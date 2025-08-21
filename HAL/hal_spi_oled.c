/*
 * oled.c
 *
 *  Created on: 2025-1-1
 *      Author: 70429
 */
#include <vxWorks.h>
#include <stdio.h>
#include "ioLib.h"
#include <inetLib.h>
#include <taskLib.h>
#include <stdlib.h>
#include <sysLib.h>
#include <errno.h>
#include <string.h>
#include "in.h"
#include <unistd.h>
#include <stdint.h>
#include <stddef.h>
#include "hal_spi_oled_front.h"
#include "hal_spi_oled.h"
#include "bsp_drv/common/fmsh_common_types.h"


u8 OLED_GRAM[144][8];

/*------- GPIO/Delay 封装 ----------*/
static inline void oled_delay_us(uint32_t us) 
{ /*硬件微秒延时*/ 
	sysUsDelay(us);
}

static inline void oled_delay_ms(uint32_t ms) 
{ /*硬件毫秒延时*/ 
	uint32_t i = 0 ;
	for(i;i<ms;i++)
	{
		sysUsDelay(1000);
	}
}

void OLED_ColorTurn(u8 i)
{
	if(i==0)
	{
		OLED_WR_Byte(0xA6,OLED_CMD);
	}
	if(i==1)
	{
		OLED_WR_Byte(0xA7,OLED_CMD);
	}
}

void OLED_DisplayTurn(u8 i)
{
	if(i==0)
	{
		OLED_WR_Byte(0xC8,OLED_CMD);
		OLED_WR_Byte(0xA1,OLED_CMD);
	}
	if(i==1)
	{
		OLED_WR_Byte(0xC0,OLED_CMD);
		OLED_WR_Byte(0xA0,OLED_CMD);
	}
}

void OLED_WR_Byte(u8 dat,u8 cmd)
{
	u8 i;
	if(cmd)
		OLED_DC_Set();
	else
		OLED_DC_Clr();
	OLED_CS_Clr();
	for(i=0;i<8;i++)
	{
		OLED_SCL_Clr();
		if(dat&0x80)
			OLED_SDA_Set();
		else
			OLED_SDA_Clr();
		OLED_SCL_Set();
		dat<<=1;
	}
	OLED_CS_Set();
	OLED_DC_Set();
}

void OLED_DisPlay_On(void)
{
	OLED_WR_Byte(0x8D,OLED_CMD);
	OLED_WR_Byte(0x14,OLED_CMD);
	OLED_WR_Byte(0xAF,OLED_CMD);
}

void OLED_DisPlay_Off(void)
{
	OLED_WR_Byte(0x8D,OLED_CMD);
	OLED_WR_Byte(0x10,OLED_CMD);
	OLED_WR_Byte(0xAE,OLED_CMD);
}


void OLED_Refresh(void)
{
	u8 i,n;
	for(i=0;i<8;i++)
	{
		OLED_WR_Byte(0xb0+i,OLED_CMD); 
		OLED_WR_Byte(0x00,OLED_CMD);   
		OLED_WR_Byte(0x10,OLED_CMD);   
		for(n=0;n<128;n++)
			OLED_WR_Byte(OLED_GRAM[n][i],OLED_DATA);
	}
}

void OLED_Clear(void)
{
	u8 i,n;
	for(i=0;i<8;i++)
	{
		for(n=0;n<128;n++)
		{
			OLED_GRAM[n][i]=0;
		}
	}
	OLED_Refresh();
}


void OLED_DrawPoint(u8 x,u8 y,u8 t)
{
	u8 i,m,n;
	i=y/8;
	m=y%8;
	n=1<<m;
	if(t){OLED_GRAM[x][i]|=n;}
	else
	{
		OLED_GRAM[x][i]=~OLED_GRAM[x][i];
		OLED_GRAM[x][i]|=n;
		OLED_GRAM[x][i]=~OLED_GRAM[x][i];
	}
}


void OLED_DrawLine(u8 x1,u8 y1,u8 x2,u8 y2,u8 mode)
{
	u16 t;
	int xerr=0,yerr=0,delta_x,delta_y,distance;
	int incx,incy,uRow,uCol;
	delta_x=x2-x1; 
	delta_y=y2-y1;
	uRow=x1;
	uCol=y1;
	if(delta_x>0)incx=1; 
	else if (delta_x==0)incx=0;
	else {incx=-1;delta_x=-delta_x;}
	if(delta_y>0)incy=1;
	else if (delta_y==0)incy=0;
	else {incy=-1;delta_y=-delta_x;}
	if(delta_x>delta_y)distance=delta_x; 
	else distance=delta_y;
	for(t=0;t<distance+1;t++)
	{
		OLED_DrawPoint(uRow,uCol,mode);
		xerr+=delta_x;
		yerr+=delta_y;
		if(xerr>distance)
		{
			xerr-=distance;
			uRow+=incx;
		}
		if(yerr>distance)
		{
			yerr-=distance;
			uCol+=incy;
		}
	}
}

void OLED_DrawCircle(u8 x,u8 y,u8 r)
{
	int a, b,num;
	a = 0;
	b = r;
	while(2 * b * b >= r * r)
	{
		OLED_DrawPoint(x + a, y - b,1);
		OLED_DrawPoint(x - a, y - b,1);
		OLED_DrawPoint(x - a, y + b,1);
		OLED_DrawPoint(x + a, y + b,1);

		OLED_DrawPoint(x + b, y + a,1);
		OLED_DrawPoint(x + b, y - a,1);
		OLED_DrawPoint(x - b, y - a,1);
		OLED_DrawPoint(x - b, y + a,1);

		a++;
		num = (a * a + b * b) - r*r;
		if(num > 0)
		{
			b--;
			a--;
		}
	}
}

void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size1,u8 mode)
{
	u8 i,m,temp,size2,chr1;
	u8 x0=x,y0=y;
	if(size1==8)size2=6;
	else size2=(size1/8+((size1%8)?1:0))*(size1/2);  
	chr1=chr-' ';  
	for(i=0;i<size2;i++)
	{
		if(size1==8)
		{temp=asc2_0806[chr1][i];} 
		else if(size1==12)
		{temp=asc2_1206[chr1][i];} 
		else if(size1==16)
		{temp=asc2_1608[chr1][i];} 
		else if(size1==24)
		{temp=asc2_2412[chr1][i];} 
		else return;
		for(m=0;m<8;m++)
		{
			if(temp&0x01)OLED_DrawPoint(x,y,mode);
			else OLED_DrawPoint(x,y,!mode);
			temp>>=1;
			y++;
		}
		x++;
		if((size1!=8)&&((x-x0)==size1/2))
		{x=x0;y0=y0+8;}
		y=y0;
	}
}


void OLED_ShowString(u8 x,u8 y,u8 *chr,u8 size1,u8 mode)
{
	while((*chr>=' ')&&(*chr<='~'))
	{
		OLED_ShowChar(x,y,*chr,size1,mode);
		if(size1==8)x+=6;
		else x+=size1/2;
		chr++;
	}
}


u32 OLED_Pow(u8 m,u8 n)
{
	u32 result=1;
	while(n--)
	{
		result*=m;
	}
	return result;
}


void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size1,u8 mode)
{
	u8 t,temp,m=0;
	if(size1==8)m=2;
	for(t=0;t<len;t++)
	{
		temp=(num/OLED_Pow(10,len-t-1))%10;
		if(temp==0)
		{
			OLED_ShowChar(x+(size1/2+m)*t,y,'0',size1,mode);
		}
		else
		{
			OLED_ShowChar(x+(size1/2+m)*t,y,temp+'0',size1,mode);
		}
	}
}


void OLED_ShowChinese(u8 x,u8 y,u8 num,u8 size1,u8 mode)
{
	u8 m,temp;
	u8 x0=x,y0=y;
	u16 i,size3=(size1/8+((size1%8)?1:0))*size1;  
	for(i=0;i<size3;i++)
	{
		if(size1==16)
		{temp=wqsz1[num][i];}
		else if(size1==24)
		{temp=wqsz2[num][i];}
		else if(size1==32)
		{temp=wqsz3[num][i];}
		else if(size1==64)
		{temp=wqsz4[num][i];}
		else return;
		for(m=0;m<8;m++)
		{
			if(temp&0x01)OLED_DrawPoint(x,y,mode);
			else OLED_DrawPoint(x,y,!mode);
			temp>>=1;
			y++;
		}
		x++;
		if((x-x0)==size1)
		{x=x0;y0=y0+8;}
		y=y0;
	}
}


void OLED_ShowChinesetip(u8 x,u8 y,u8 num,u8 size1,u8 mode)
{
	u8 m,temp;
	u8 x0=x,y0=y;
	u16 i,size3=(size1/8+((size1%8)?1:0))*size1;  
	for(i=0;i<size3;i++)
	{
		if(size1==12)
		{temp=operation_tip[num][i];}
		else return;
		for(m=0;m<8;m++)
		{
			if(temp&0x01)OLED_DrawPoint(x,y,mode);
			else OLED_DrawPoint(x,y,!mode);
			temp>>=1;
			y++;
		}
		x++;
		if((x-x0)==size1)
		{x=x0;y0=y0+8;}
		y=y0;
	}
}

void OLED_ScrollDisplay(u8 num,u8 space,u8 mode)
{
	u8 i,n,t=0,m=0,r;
	while(1)
	{
		if(m==0)
		{
			OLED_ShowChinese(128,24,t,16,mode); 
			t++;
		}
		if(t==num)
		{
			for(r=0;r<16*space;r++)      
			{
				for(i=1;i<144;i++)
				{
					for(n=0;n<8;n++)
					{
						OLED_GRAM[i-1][n]=OLED_GRAM[i][n];
					}
				}
				OLED_Refresh();
			}
			t=0;
		}
		m++;
		if(m==16){m=0;}
		for(i=1;i<144;i++)  
		{
			for(n=0;n<8;n++)
			{
				OLED_GRAM[i-1][n]=OLED_GRAM[i][n];
			}
		}
		OLED_Refresh();
	}
}

void OLED_ShowPicture(u8 x,u8 y,u8 sizex,u8 sizey,u8 BMP[],u8 mode)
{
	u16 j=0;
	u8 i,n,temp,m;
	u8 x0=x,y0=y;
	sizey=sizey/8+((sizey%8)?1:0);
	for(n=0;n<sizey;n++)
	{
		for(i=0;i<sizex;i++)
		{
			temp=BMP[j];
			j++;
			for(m=0;m<8;m++)
			{
				if(temp&0x01)OLED_DrawPoint(x,y,mode);
				else OLED_DrawPoint(x,y,!mode);
				temp>>=1;
				y++;
			}
			x++;
			if((x-x0)==sizex)
			{
				x=x0;
				y0=y0+8;
			}
			y=y0;
		}
	}
}

/*------- 1. 复位脉冲 (先 VDD 已稳, VCC 未启) ----------*/
static void oled_reset(void)
{
    OLED_RES_Clr();
    oled_delay_us(50);          // ≥3 µs (t1)
    OLED_RES_Set();
    oled_delay_us(50);          // ≥3 µs (t2)
}

/*------- 初始化寄存器 ----------*/
static const uint8_t init_seq[] = {
    0xAE,                         // Display OFF
    0xFD, 0x12,                   // Command unlock
    0xAD, 0x8B,                   // DC-DC ON  (0x8A 外部VCC, 0x8B 内部)
    0xD5, 0x80,                   // Clock div, osc  (建议0x80)
    0xA8, 0x3F,                   // MUX = 1/64
    0xD3, 0x00,                   // Display offset
    0x40,                         // Start line =0
    0xA1, 0xC8,                   // Segment remap / COM scan dir
    0xDA, 0x12,                   // COM pins (alt, disable LR remap)
    0x81, 0xBF,                   // Contrast
    0xD9, 0xF1,                   // Pre-charge (phase1=15, phase2=1)
    0xDB, 0x40,                   // VCOMH deselect @0.83×VCC
    0xA4,                         // Resume RAM display
    0xA6                          // Normal (not inverse)
};

void OLED_Init(void)
{
	size_t i;
	oled_reset();
	
    for (i = 0; i < sizeof(init_seq); ++i)
        OLED_WR_Byte(init_seq[i], OLED_CMD);
    
    oled_delay_ms(100);
    OLED_WR_Byte(0x21, OLED_CMD); OLED_WR_Byte(0, OLED_CMD); OLED_WR_Byte(127, OLED_CMD);
    OLED_WR_Byte(0x22, OLED_CMD); OLED_WR_Byte(0, OLED_CMD); OLED_WR_Byte(7,  OLED_CMD);
	OLED_Clear();
	OLED_WR_Byte(0xAF,OLED_CMD);
	LOG_INFO("OLED_Init Done ....\n");
}


void BRAM_IRQ_Set(void)
{
	PL_AXI_WriteReg(PL_AXI_BASE,0x400,1);
}


void BRAM_IRQ_Clr(void)
{
	PL_AXI_WriteReg(PL_AXI_BASE,0x400,0);
}

void BRAM_Read(void)
{
    unsigned int data = 0;
    data = PL_AXI_ReadReg(PL_AXI_BASE,0x400);
}
