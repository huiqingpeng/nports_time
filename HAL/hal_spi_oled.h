/*
 * oled.h
 *
 *  Created on: 2025
 *      Author: 70429
 */

 #ifndef SRC_OLED_H_
 #define SRC_OLED_H_
 
#include "hal_com.h"


#define PL_AXI_WriteReg(BaseAddress, RegOffset, Data) \
		sysAxiWriteLong((BaseAddress) + (RegOffset), (uint32_t)(Data))

#define PL_AXI_ReadReg(BaseAddress, RegOffset) \
		sysAxiReadLong((BaseAddress) + (RegOffset))

#define PL_AXI_BASE  0x40000000 

 /*-----------------OLED----------------*/
 #define OLED_SCL_Clr() PL_AXI_WriteReg(PL_AXI_BASE,0x00,0)//SCL
 #define OLED_SCL_Set() PL_AXI_WriteReg(PL_AXI_BASE,0x00,1)
 
 #define OLED_SDA_Clr() PL_AXI_WriteReg(PL_AXI_BASE,0x04,0)//SDA
 #define OLED_SDA_Set() PL_AXI_WriteReg(PL_AXI_BASE,0x04,1)
 
 #define OLED_RES_Clr() PL_AXI_WriteReg(PL_AXI_BASE,0x08,0)//RES
 #define OLED_RES_Set() PL_AXI_WriteReg(PL_AXI_BASE,0x08,1)
 
 #define OLED_DC_Clr()  PL_AXI_WriteReg(PL_AXI_BASE,0x0C,0)//DC
 #define OLED_DC_Set()  PL_AXI_WriteReg(PL_AXI_BASE,0x0C,1)
 
 #define OLED_CS_Clr()  PL_AXI_WriteReg(PL_AXI_BASE,0x10,0)//CS
 #define OLED_CS_Set()  PL_AXI_WriteReg(PL_AXI_BASE,0x10,1)
 
 
 #define OLED_CMD  0	
 #define OLED_DATA 1	
 
 
 void OLED_ClearPoint(uint8_t x,uint8_t y);
 void OLED_ColorTurn(uint8_t i);
 void OLED_DisplayTurn(uint8_t i);
 void OLED_WR_Byte(uint8_t dat,uint8_t mode);
 void OLED_DisPlay_On(void);
 void OLED_DisPlay_Off(void);
 void OLED_Refresh(void);
 void OLED_Clear(void);
 void OLED_DrawPoint(uint8_t x,uint8_t y,uint8_t t);
 void OLED_DrawLine(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,uint8_t mode);
 void OLED_DrawCircle(uint8_t x,uint8_t y,uint8_t r);
 void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t size1,uint8_t mode);
 void OLED_ShowChar6x8(uint8_t x,uint8_t y,uint8_t chr,uint8_t mode);
 void OLED_ShowString(uint8_t x,uint8_t y,uint8_t *chr,uint8_t size1,uint8_t mode);
 void OLED_ShowNum(uint8_t x,uint8_t y,uint32_t num,uint8_t len,uint8_t size1,uint8_t mode);
 void OLED_ShowChinese(uint8_t x,uint8_t y,uint8_t num,uint8_t size1,uint8_t mode);
 void OLED_ScrollDisplay(uint8_t num,uint8_t space,uint8_t mode);
 void OLED_ShowPicture(uint8_t x,uint8_t y,uint8_t sizex,uint8_t sizey,uint8_t BMP[],uint8_t mode);
 void OLED_Init(void);
 
 #endif /* SRC_OLED_H_ */
 
