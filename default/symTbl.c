/* symTbl.c - standalone symbol tables wrapper */

/* CREATED BY F:/4.VX/vx/WindRiver69/vxworks-6.9/host/resource/hutils/tcl/makeSymTbl.tcl
 *  WITH ARGS arm tmp.o symTbl.c
 *         ON Thu Aug 28 16:34:38 +0900 2025
 */

#include "vxWorks.h"
#include "symbol.h"

IMPORT int BLOCKS_PER_DATA_DIR_CACHE_GROUP;
IMPORT int BLOCKS_PER_FAT_CACHE_GROUP;
IMPORT int BRAM_IRQ_Clr ();
IMPORT int BRAM_IRQ_Set ();
IMPORT int BRAM_Read ();
IMPORT int ConfigTaskManager ();
IMPORT int ConnectionManagerTask ();
IMPORT int EVP_DecodeBlock ();
IMPORT int EVP_DecodeFinal ();
IMPORT int EVP_DecodeInit ();
IMPORT int EVP_DecodeUpdate ();
IMPORT int EVP_EncodeBlock ();
IMPORT int EVP_EncodeFinal ();
IMPORT int EVP_EncodeInit ();
IMPORT int EVP_EncodeUpdate ();
IMPORT int FDmaPs_ConfigTable;
IMPORT int FDmaPs_IRQ ();
IMPORT int FDmaPs_LookupConfig ();
IMPORT int FDmaPs_addLliItem ();
IMPORT int FDmaPs_autoCompParams ();
IMPORT int FDmaPs_checkChannelBusy ();
IMPORT int FDmaPs_checkChannelRange ();
IMPORT int FDmaPs_clearIrq ();
IMPORT int FDmaPs_destinationReady ();
IMPORT int FDmaPs_disable ();
IMPORT int FDmaPs_disableChannel ();
IMPORT int FDmaPs_disableChannelIrq ();
IMPORT int FDmaPs_enable ();
IMPORT int FDmaPs_enableChannel ();
IMPORT int FDmaPs_enableChannelIrq ();
IMPORT int FDmaPs_funcVerify ();
IMPORT int FDmaPs_getAddress ();
IMPORT int FDmaPs_getAddressInc ();
IMPORT int FDmaPs_getBlockByteCount ();
IMPORT int FDmaPs_getBlockCount ();
IMPORT int FDmaPs_getBlockTransSize ();
IMPORT int FDmaPs_getBurstTransLength ();
IMPORT int FDmaPs_getChannelConfig ();
IMPORT int FDmaPs_getChannelEnableReg ();
IMPORT int FDmaPs_getChannelFifoDepth ();
IMPORT int FDmaPs_getChannelIndex ();
IMPORT int FDmaPs_getChannelPriority ();
IMPORT int FDmaPs_getFifoMode ();
IMPORT int FDmaPs_getFlowCtlMode ();
IMPORT int FDmaPs_getFreeChannel ();
IMPORT int FDmaPs_getGatherEnable ();
IMPORT int FDmaPs_getGatherParam ();
IMPORT int FDmaPs_getHandshakingMode ();
IMPORT int FDmaPs_getHsInterface ();
IMPORT int FDmaPs_getHsPolarity ();
IMPORT int FDmaPs_getListMstSelect ();
IMPORT int FDmaPs_getListPointerAddress ();
IMPORT int FDmaPs_getLlpEnable ();
IMPORT int FDmaPs_getLockEnable ();
IMPORT int FDmaPs_getLockLevel ();
IMPORT int FDmaPs_getMaxAmbaBurstLength ();
IMPORT int FDmaPs_getMemPeriphFlowCtl ();
IMPORT int FDmaPs_getMstSelect ();
IMPORT int FDmaPs_getNumChannels ();
IMPORT int FDmaPs_getProtCtl ();
IMPORT int FDmaPs_getReload ();
IMPORT int FDmaPs_getScatterEnable ();
IMPORT int FDmaPs_getScatterParam ();
IMPORT int FDmaPs_getSoftwareRequest ();
IMPORT int FDmaPs_getStatUpdate ();
IMPORT int FDmaPs_getStatus ();
IMPORT int FDmaPs_getStatusAddress ();
IMPORT int FDmaPs_getTestMode ();
IMPORT int FDmaPs_getTransWidth ();
IMPORT int FDmaPs_getTransferType ();
IMPORT int FDmaPs_init ();
IMPORT int FDmaPs_initDev ();
IMPORT int FDmaPs_irqHandler ();
IMPORT int FDmaPs_isBlockTransDone ();
IMPORT int FDmaPs_isChannelEnabled ();
IMPORT int FDmaPs_isChannelIrqEnabled ();
IMPORT int FDmaPs_isChannelSuspended ();
IMPORT int FDmaPs_isEnabled ();
IMPORT int FDmaPs_isFifoEmpty ();
IMPORT int FDmaPs_isIrqActive ();
IMPORT int FDmaPs_isIrqMasked ();
IMPORT int FDmaPs_isRawIrqActive ();
IMPORT int FDmaPs_maskIrq ();
IMPORT int FDmaPs_nextBlockIsLast ();
IMPORT int FDmaPs_resetController ();
IMPORT int FDmaPs_resetInstance ();
IMPORT int FDmaPs_resumeChannel ();
IMPORT int FDmaPs_setAddress ();
IMPORT int FDmaPs_setAddressInc ();
IMPORT int FDmaPs_setBlockTransSize ();
IMPORT int FDmaPs_setBurstTransLength ();
IMPORT int FDmaPs_setChannelConfig ();
IMPORT int FDmaPs_setChannelPriority ();
IMPORT int FDmaPs_setChannelPriorityOrder ();
IMPORT int FDmaPs_setFifoMode ();
IMPORT int FDmaPs_setFlowCtlMode ();
IMPORT int FDmaPs_setGatherEnable ();
IMPORT int FDmaPs_setGatherParam ();
IMPORT int FDmaPs_setHandshakingMode ();
IMPORT int FDmaPs_setHsInterface ();
IMPORT int FDmaPs_setHsPolarity ();
IMPORT int FDmaPs_setListMstSelect ();
IMPORT int FDmaPs_setListPointerAddress ();
IMPORT int FDmaPs_setListener ();
IMPORT int FDmaPs_setLlpEnable ();
IMPORT int FDmaPs_setLockEnable ();
IMPORT int FDmaPs_setLockLevel ();
IMPORT int FDmaPs_setMaxAmbaBurstLength ();
IMPORT int FDmaPs_setMemPeriphFlowCtl ();
IMPORT int FDmaPs_setMstSelect ();
IMPORT int FDmaPs_setProtCtl ();
IMPORT int FDmaPs_setReload ();
IMPORT int FDmaPs_setScatterEnable ();
IMPORT int FDmaPs_setScatterParam ();
IMPORT int FDmaPs_setSingleRegion ();
IMPORT int FDmaPs_setSoftwareRequest ();
IMPORT int FDmaPs_setStatUpdate ();
IMPORT int FDmaPs_setStatus ();
IMPORT int FDmaPs_setStatusAddress ();
IMPORT int FDmaPs_setTestMode ();
IMPORT int FDmaPs_setTransWidth ();
IMPORT int FDmaPs_setTransferType ();
IMPORT int FDmaPs_sourceReady ();
IMPORT int FDmaPs_startTransfer ();
IMPORT int FDmaPs_suspendChannel ();
IMPORT int FDmaPs_unmaskIrq ();
IMPORT int FDmaPs_userIrqHandler ();
IMPORT int FSdmmcPs_CfgTbl;
IMPORT int FSdmmcPs_IRQ ();
IMPORT int FSdmmcPs_LookupConfig ();
IMPORT int FSdmmcPs_addSdDevice ();
IMPORT int FSdmmcPs_cardDataTransfer ();
IMPORT int FSdmmcPs_cardDetect ();
IMPORT int FSdmmcPs_cardIdentify ();
IMPORT int FSdmmcPs_cardInitializeVerify ();
IMPORT int FSdmmcPs_cfgInitialize ();
IMPORT int FSdmmcPs_changeBusSpeed ();
IMPORT int FSdmmcPs_checkCardState ();
IMPORT int FSdmmcPs_disableIntMask ();
IMPORT int FSdmmcPs_doTransfer ();
IMPORT int FSdmmcPs_enableDMA ();
IMPORT int FSdmmcPs_enableInt ();
IMPORT int FSdmmcPs_getBlockNumbers ();
IMPORT int FSdmmcPs_getBusSpeed ();
IMPORT int FSdmmcPs_getCardSizeKB ();
IMPORT int FSdmmcPs_getCardStatus ();
IMPORT int FSdmmcPs_getIntMask ();
IMPORT int FSdmmcPs_getMaskIntStat ();
IMPORT int FSdmmcPs_getMmcExtCsd ();
IMPORT int FSdmmcPs_getRawIntStat ();
IMPORT int FSdmmcPs_getSdSCR ();
IMPORT int FSdmmcPs_getTransferMode ();
IMPORT int FSdmmcPs_initCard ();
IMPORT int FSdmmcPs_initDev ();
IMPORT int FSdmmcPs_initDmac ();
IMPORT int FSdmmcPs_initSdmmcCtrl ();
IMPORT int FSdmmcPs_instanceReset ();
IMPORT int FSdmmcPs_intVerify ();
IMPORT int FSdmmcPs_irqHandler ();
IMPORT int FSdmmcPs_mmcEnumerate ();
IMPORT int FSdmmcPs_powerDown ();
IMPORT int FSdmmcPs_powerUp ();
IMPORT int FSdmmcPs_prepareCmd ();
IMPORT int FSdmmcPs_readFun ();
IMPORT int FSdmmcPs_readWriteData ();
IMPORT int FSdmmcPs_regInitCheck ();
IMPORT int FSdmmcPs_regRdWtCheck ();
IMPORT int FSdmmcPs_removeSdDevice ();
IMPORT int FSdmmcPs_resetCheck ();
IMPORT int FSdmmcPs_resetController ();
IMPORT int FSdmmcPs_sdControllerReset ();
IMPORT int FSdmmcPs_sdDmaReset ();
IMPORT int FSdmmcPs_sdEnumerate ();
IMPORT int FSdmmcPs_sdFifoReset ();
IMPORT int FSdmmcPs_sendCmd ();
IMPORT int FSdmmcPs_sendRwCmd ();
IMPORT int FSdmmcPs_setBlockLen ();
IMPORT int FSdmmcPs_setCardBusWidth ();
IMPORT int FSdmmcPs_setCardVoltage ();
IMPORT int FSdmmcPs_setClock ();
IMPORT int FSdmmcPs_setCtrlBuswidth ();
IMPORT int FSdmmcPs_setDmaMsize ();
IMPORT int FSdmmcPs_setIntMask ();
IMPORT int FSdmmcPs_setRXwmark ();
IMPORT int FSdmmcPs_setRawIntStat ();
IMPORT int FSdmmcPs_setTXwmark ();
IMPORT int FSdmmcPs_stopTransfer ();
IMPORT int FSdmmcPs_verify ();
IMPORT int FSdmmcPs_waitWriteDone ();
IMPORT int FSdmmcPs_writeFun ();
IMPORT int FSlcrPS_regRead ();
IMPORT int FSlcrPS_rsvRegPrint ();
IMPORT int FSlcrPS_setCanLoop ();
IMPORT int FSlcrPS_setI2cLoop ();
IMPORT int FSlcrPS_setSpiLoop ();
IMPORT int FSlcrPS_setUartLoop ();
IMPORT int FSlcrPs_ipReleaseRst ();
IMPORT int FSlcrPs_ipSetRst ();
IMPORT int FSlcrPs_lock ();
IMPORT int FSlcrPs_setBitTo0 ();
IMPORT int FSlcrPs_setBitTo1 ();
IMPORT int FSlcrPs_softRst ();
IMPORT int FSlcrPs_unlock ();
IMPORT int FileDataCmp ();
IMPORT int Gmac_RxFilt_Dis_BroadCast ();
IMPORT int Gmac_RxFilt_En_MultiCast ();
IMPORT int GpioClose ();
IMPORT int GpioCreate ();
IMPORT int GpioDevCreate ();
IMPORT int GpioDevNamePrefix;
IMPORT int GpioDrv ();
IMPORT int GpioDrvNum;
IMPORT int GpioIoCtl ();
IMPORT int GpioOpen ();
IMPORT int GpioRead ();
IMPORT int GpioRemove ();
IMPORT int GpioWrite ();
IMPORT int Hzk1;
IMPORT int Hzk2;
IMPORT int Hzk3;
IMPORT int Hzk4;
IMPORT int MD5_Final ();
IMPORT int MD5_Init ();
IMPORT int MD5_Transform ();
IMPORT int MD5_Update ();
IMPORT int MD5_version;
IMPORT int OLED_Clear ();
IMPORT int OLED_ColorTurn ();
IMPORT int OLED_DisPlay_Off ();
IMPORT int OLED_DisPlay_On ();
IMPORT int OLED_DisplayTurn ();
IMPORT int OLED_DrawCircle ();
IMPORT int OLED_DrawLine ();
IMPORT int OLED_DrawPoint ();
IMPORT int OLED_GRAM;
IMPORT int OLED_Init ();
IMPORT int OLED_Pow ();
IMPORT int OLED_Refresh ();
IMPORT int OLED_ScrollDisplay ();
IMPORT int OLED_ShowChar ();
IMPORT int OLED_ShowChinese ();
IMPORT int OLED_ShowChinesetip ();
IMPORT int OLED_ShowNum ();
IMPORT int OLED_ShowPicture ();
IMPORT int OLED_ShowString ();
IMPORT int OLED_WR_Byte ();
IMPORT int RcvBuf2;
IMPORT int RealTimeSchedulerTask ();
IMPORT int SDMMC_decodeCID ();
IMPORT int SDMMC_decodeCSD ();
IMPORT int SDMMC_getCSDInfo ();
IMPORT int SHA1_Final ();
IMPORT int SHA1_Init ();
IMPORT int SHA1_Transform ();
IMPORT int SHA1_Update ();
IMPORT int SHA1_version;
IMPORT int SHA224 ();
IMPORT int SHA224_Final ();
IMPORT int SHA224_Init ();
IMPORT int SHA224_Update ();
IMPORT int SHA256 ();
IMPORT int SHA256_Final ();
IMPORT int SHA256_Init ();
IMPORT int SHA256_Transform ();
IMPORT int SHA256_Update ();
IMPORT int SHA256_version;
IMPORT int SetNewSeedtoRandomGenerator ();
IMPORT int SndBuf2;
IMPORT int UdpSearchTask ();
IMPORT int ZBUF_GETSEG ();
IMPORT int _Jv_Balloc ();
IMPORT int _Jv_Bfree ();
IMPORT int _Jv__mcmp ();
IMPORT int _Jv__mdiff ();
IMPORT int _Jv__mprec_bigtens;
IMPORT int _Jv__mprec_tens;
IMPORT int _Jv__mprec_tinytens;
IMPORT int _Jv_b2d ();
IMPORT int _Jv_d2b ();
IMPORT int _Jv_dtoa_r ();
IMPORT int _Jv_hi0bits ();
IMPORT int _Jv_i2b ();
IMPORT int _Jv_lo0bits ();
IMPORT int _Jv_lshift ();
IMPORT int _Jv_mult ();
IMPORT int _Jv_multadd ();
IMPORT int _Jv_pow5mult ();
IMPORT int _Jv_ratio ();
IMPORT int _Jv_s2b ();
IMPORT int _Jv_ulp ();
IMPORT int _Randseed;
IMPORT int _STI__07__diab_atomic_init ();
IMPORT int __DIAB_rd_pk_db ();
IMPORT int __DIAB_rd_pk_fl ();
IMPORT int __DIAB_rd_pk_ld ();
IMPORT int __DIAB_rd_sw_db ();
IMPORT int __DIAB_rd_sw_fl ();
IMPORT int __DIAB_rd_sw_ld ();
IMPORT int __DIAB_wr_pk_db ();
IMPORT int __DIAB_wr_pk_fl ();
IMPORT int __DIAB_wr_pk_ld ();
IMPORT int __DIAB_wr_sw_db ();
IMPORT int __DIAB_wr_sw_fl ();
IMPORT int __DIAB_wr_sw_ld ();
IMPORT int __POL ();
IMPORT int ___x_diab_arm_div_o;
IMPORT int ___x_diab_comljmp_o;
IMPORT int ___x_diab_copytable_o;
IMPORT int ___x_diab_crtlibso_o;
IMPORT int ___x_diab_ctordtor_o;
IMPORT int ___x_diab_ff1_o;
IMPORT int ___x_diab_libg_o;
IMPORT int ___x_diab_rd_pk_db_o;
IMPORT int ___x_diab_rd_pk_fl_o;
IMPORT int ___x_diab_rd_pk_ld_o;
IMPORT int ___x_diab_rd_sw_db_o;
IMPORT int ___x_diab_rd_sw_fl_o;
IMPORT int ___x_diab_rd_sw_ld_o;
IMPORT int ___x_diab_sfpdadd_o;
IMPORT int ___x_diab_sfpdcmp_o;
IMPORT int ___x_diab_sfpdcmpe_o;
IMPORT int ___x_diab_sfpddiv_o;
IMPORT int ___x_diab_sfpddtof_o;
IMPORT int ___x_diab_sfpddtoi_o;
IMPORT int ___x_diab_sfpddtou_o;
IMPORT int ___x_diab_sfpdfeq_o;
IMPORT int ___x_diab_sfpdfge_o;
IMPORT int ___x_diab_sfpdfgt_o;
IMPORT int ___x_diab_sfpdfle_o;
IMPORT int ___x_diab_sfpdflt_o;
IMPORT int ___x_diab_sfpdfne_o;
IMPORT int ___x_diab_sfpditod_o;
IMPORT int ___x_diab_sfpdlltod_o;
IMPORT int ___x_diab_sfpdmul_o;
IMPORT int ___x_diab_sfpdneg_o;
IMPORT int ___x_diab_sfpdnorm_o;
IMPORT int ___x_diab_sfpdpol_o;
IMPORT int ___x_diab_sfpdsetup_o;
IMPORT int ___x_diab_sfpdutod_o;
IMPORT int ___x_diab_sfpfadd_o;
IMPORT int ___x_diab_sfpfcmp_o;
IMPORT int ___x_diab_sfpfcmpe_o;
IMPORT int ___x_diab_sfpfdiv_o;
IMPORT int ___x_diab_sfpffeq_o;
IMPORT int ___x_diab_sfpffge_o;
IMPORT int ___x_diab_sfpffgt_o;
IMPORT int ___x_diab_sfpffle_o;
IMPORT int ___x_diab_sfpfflt_o;
IMPORT int ___x_diab_sfpffne_o;
IMPORT int ___x_diab_sfpfftod_o;
IMPORT int ___x_diab_sfpfftoi_o;
IMPORT int ___x_diab_sfpfftou_o;
IMPORT int ___x_diab_sfpfitof_o;
IMPORT int ___x_diab_sfpflltof_o;
IMPORT int ___x_diab_sfpfmul_o;
IMPORT int ___x_diab_sfpfneg_o;
IMPORT int ___x_diab_sfpfnorm_o;
IMPORT int ___x_diab_sfpfsetup_o;
IMPORT int ___x_diab_sfpfulltof_o;
IMPORT int ___x_diab_sfpfutof_o;
IMPORT int ___x_diab_sfpround_o;
IMPORT int ___x_diab_sxpadd64_o;
IMPORT int ___x_diab_sxpasr64_o;
IMPORT int ___x_diab_sxpcmp64_o;
IMPORT int ___x_diab_sxpdiv64_o;
IMPORT int ___x_diab_sxplsl64_o;
IMPORT int ___x_diab_sxplsr64_o;
IMPORT int ___x_diab_sxpm6432_o;
IMPORT int ___x_diab_sxpmul64_o;
IMPORT int ___x_diab_sxprem32_o;
IMPORT int ___x_diab_sxprem64_o;
IMPORT int ___x_diab_torn_syncatomic_o;
IMPORT int ___x_diab_torn_syncmutex_o;
IMPORT int ___x_diab_torn_syncsem_o;
IMPORT int ___x_diab_wr_pk_db_o;
IMPORT int ___x_diab_wr_pk_fl_o;
IMPORT int ___x_diab_wr_pk_ld_o;
IMPORT int ___x_diab_wr_sw_db_o;
IMPORT int ___x_diab_wr_sw_fl_o;
IMPORT int ___x_diab_wr_sw_ld_o;
IMPORT int __add64 ();
IMPORT int __arm_call_via_o;
IMPORT int __asr64 ();
IMPORT int __assert ();
IMPORT int __clocale;
IMPORT int __common_intrinsicsInit ();
IMPORT int __common_long_jmp ();
IMPORT int __copy ();
IMPORT int __copy_multiple ();
IMPORT int __costate;
IMPORT int __cplusLoadObjFiles;
IMPORT int __cplusLoad_o;
IMPORT int __cplusUsr_o;
IMPORT int __cplusXtors_o;
IMPORT int __ctype;
IMPORT int __ctype_tolower;
IMPORT int __ctype_toupper;
IMPORT int __daysSinceEpoch ();
IMPORT int __diab_alloc_mutex ();
IMPORT int __diab_alloc_semaphore ();
IMPORT int __diab_atomic_enter ();
IMPORT int __diab_atomic_restore ();
IMPORT int __diab_free_mutex ();
IMPORT int __diab_free_semaphore ();
IMPORT int __diab_intrinsics_impfpInit ();
IMPORT int __diab_intrinsics_implInit ();
IMPORT int __diab_intrinsics_tornInit ();
IMPORT int __diab_lock_mutex ();
IMPORT int __diab_lock_semaphore ();
IMPORT int __diab_trylock_mutex ();
IMPORT int __diab_trylock_semaphore ();
IMPORT int __diab_unlock_mutex ();
IMPORT int __diab_unlock_semaphore ();
IMPORT int __div32 ();
IMPORT int __div64 ();
IMPORT int __dtoa ();
IMPORT int __dtof ();
IMPORT int __dtoi ();
IMPORT int __dtou ();
IMPORT int __eq64 ();
IMPORT int __errno ();
IMPORT int __exec_ctors ();
IMPORT int __exec_dtors ();
IMPORT int __exec_xtor_table;
IMPORT unsigned int __ff1 (unsigned int);
IMPORT unsigned int __ff1l (unsigned int);
IMPORT unsigned int __ff1ll (unsigned long long);
IMPORT int __fini ();
IMPORT int __fixdfdi ();
IMPORT int __fixsfdi ();
IMPORT int __fixunsdfdi ();
IMPORT int __fixunssfdi ();
IMPORT int __floatdidf ();
IMPORT int __floatdisf ();
IMPORT int __floatundidf ();
IMPORT int __floatundidf_o;
IMPORT int __ftod ();
IMPORT int __ftoi ();
IMPORT int __ftou ();
IMPORT int __ge64 ();
IMPORT int __getDstInfo ();
IMPORT int __getDstInfoSub ();
IMPORT int __getTime ();
IMPORT int __getZoneInfo ();
IMPORT int __gt64 ();
IMPORT int __ieee754_rem_pio2 ();
IMPORT unsigned int __ieee_status (unsigned int mask, unsigned int flags);
IMPORT int __includeDiabIntrinsics;
IMPORT int __init ();
IMPORT int __itod ();
IMPORT int __itof ();
IMPORT int __julday ();
IMPORT int __kernel_cos ();
IMPORT int __kernel_rem_pio2 ();
IMPORT int __kernel_sin ();
IMPORT int __kernel_tan ();
IMPORT int __le64 ();
IMPORT int __lltod ();
IMPORT int __lltof ();
IMPORT int __locale;
IMPORT int __loctime;
IMPORT int __lsl64 ();
IMPORT int __lsr64 ();
IMPORT int __lt64 ();
IMPORT int __mul64 ();
IMPORT int __mul6432 ();
IMPORT int __ne64 ();
IMPORT int __rem32 ();
IMPORT int __rem64 ();
IMPORT int __rta_longjmp;
IMPORT int __sclose ();
IMPORT int __sflags ();
IMPORT int __sflush ();
IMPORT int __sfpRoundMode;
IMPORT int __sfvwrite ();
IMPORT int __smakebuf ();
IMPORT int __sread ();
IMPORT int __srefill ();
IMPORT int __srget ();
IMPORT int __sseek ();
IMPORT int __stderr ();
IMPORT int __stdin ();
IMPORT int __stdout ();
IMPORT int __strxfrm ();
IMPORT int __sub64 ();
IMPORT int __swbuf ();
IMPORT int __swrite ();
IMPORT int __swsetup ();
IMPORT int __taskVarAdd ();
IMPORT int __taskVarDelete ();
IMPORT int __taskVarGet ();
IMPORT int __taskVarSet ();
IMPORT int __udiv32 ();
IMPORT int __udiv64 ();
IMPORT int __uge64 ();
IMPORT int __ugt64 ();
IMPORT int __ule64 ();
IMPORT int __ulltof ();
IMPORT int __ult64 ();
IMPORT int __urem32 ();
IMPORT int __urem64 ();
IMPORT int __utod ();
IMPORT int __utof ();
IMPORT int __wdbEventListIsEmpty;
IMPORT int _applLog ();
IMPORT int _archHelp_msg;
IMPORT int _archIORead16 ();
IMPORT int _archIORead32 ();
IMPORT int _archIORead8 ();
IMPORT int _archIOWrite16 ();
IMPORT int _archIOWrite32 ();
IMPORT int _archIOWrite8 ();
IMPORT int _clockRealtime;
IMPORT int _d_add ();
IMPORT int _d_cmp ();
IMPORT int _d_cmpe ();
IMPORT int _d_div ();
IMPORT int _d_dtof ();
IMPORT int _d_dtoi ();
IMPORT int _d_dtoll ();
IMPORT int _d_dtou ();
IMPORT int _d_dtoull ();
IMPORT int _d_feq ();
IMPORT int _d_fge ();
IMPORT int _d_fgt ();
IMPORT int _d_fle ();
IMPORT int _d_flt ();
IMPORT int _d_fne ();
IMPORT int _d_fnge ();
IMPORT int _d_fngt ();
IMPORT int _d_fnle ();
IMPORT int _d_fnlt ();
IMPORT int _d_itod ();
IMPORT int _d_lltod ();
IMPORT int _d_mul ();
IMPORT int _d_neg ();
IMPORT int _d_sub ();
IMPORT int _d_ulltod ();
IMPORT int _d_utod ();
IMPORT int _dbgArchInit ();
IMPORT int _dbgDsmInstRtn;
IMPORT int _dbgFuncCallCheck ();
IMPORT int _dbgInstSizeGet ();
IMPORT int _dbgRetAdrsGet ();
IMPORT int _dbgTaskPCGet ();
IMPORT int _dbgTaskPCSet ();
IMPORT int _endM2Packet_1213 ();
IMPORT int _endM2Packet_2233 ();
IMPORT int _f_add ();
IMPORT int _f_cmp ();
IMPORT int _f_cmpe ();
IMPORT int _f_div ();
IMPORT int _f_feq ();
IMPORT int _f_fge ();
IMPORT int _f_fgt ();
IMPORT int _f_fle ();
IMPORT int _f_flt ();
IMPORT int _f_fne ();
IMPORT int _f_fnge ();
IMPORT int _f_fngt ();
IMPORT int _f_fnle ();
IMPORT int _f_fnlt ();
IMPORT int _f_ftod ();
IMPORT int _f_ftoi ();
IMPORT int _f_ftoll ();
IMPORT int _f_ftou ();
IMPORT int _f_ftoull ();
IMPORT int _f_itof ();
IMPORT int _f_lltof ();
IMPORT int _f_mul ();
IMPORT int _f_neg ();
IMPORT int _f_sub ();
IMPORT int _f_ulltof ();
IMPORT int _f_utof ();
IMPORT int _fp_round ();
IMPORT int _func_CPToUtf16;
IMPORT int _func_CPToUtf8;
IMPORT int _func_IntLvlChgRtn;
IMPORT int _func_IntLvlDisableRtn;
IMPORT int _func_IntLvlEnableRtn;
IMPORT int _func_IntLvlVecAckRtn;
IMPORT int _func_IntLvlVecChkRtn;
IMPORT int _func_aimMmuLockRegionsImport;
IMPORT int _func_armIntStackSplit;
IMPORT int _func_armIrqHandler;
IMPORT int _func_armMmuCurrentGet;
IMPORT int _func_armMmuCurrentSet;
IMPORT int _func_cacheAimArch7DClearDisable;
IMPORT int _func_cacheAimArch7IClearDisable;
IMPORT int _func_cacheFuncsSet;
IMPORT int _func_classListAdd;
IMPORT int _func_classListInit;
IMPORT int _func_classListLock;
IMPORT int _func_classListRemove;
IMPORT int _func_classListTblInit;
IMPORT int _func_classListUnlock;
IMPORT int _func_consoleOut;
IMPORT int _func_coprocShow;
IMPORT int _func_coprocTaskRegsShow;
IMPORT int _func_dosChkStatPrint;
IMPORT int _func_dosDirOldShow;
IMPORT int _func_dosFsFatShow;
IMPORT int _func_dosFsFmtRtn;
IMPORT int _func_dosVDirShow;
IMPORT int _func_end2VxBusConnect;
IMPORT int _func_end8023AddressForm;
IMPORT int _func_endEtherAddressForm;
IMPORT int _func_endEtherPacketAddrGet;
IMPORT int _func_endEtherPacketDataGet;
IMPORT int _func_envGet;
IMPORT int _func_eventReceive;
IMPORT int _func_eventRsrcSend;
IMPORT int _func_eventRsrcShow;
IMPORT int _func_eventSend;
IMPORT int _func_eventTaskShow;
IMPORT int _func_eventTerminate;
IMPORT int _func_excBaseHook;
IMPORT int _func_excBreakpoint;
IMPORT int _func_excInfoShow;
IMPORT int _func_excIntHook;
IMPORT int _func_excJobAdd;
IMPORT int _func_excPanicHook;
IMPORT int _func_exit;
IMPORT int _func_fclose;
IMPORT int _func_fcntl_dup;
IMPORT int _func_fileDoesNotExist;
IMPORT int _func_fioFltFormatRtn;
IMPORT int _func_fioFltScanRtn;
IMPORT int _func_ftpLs;
IMPORT int _func_ftpTransientFatal;
IMPORT int _func_ftruncMmanHook;
IMPORT int _func_handleAlloc;
IMPORT int _func_handleFreeAll;
IMPORT int _func_intConnectRtn;
IMPORT int _func_intDisconnectRtn;
IMPORT int _func_ioGlobalStdGet;
IMPORT int _func_ioPxCreateOrOpen;
IMPORT int _func_ioTaskStdSet;
IMPORT int _func_iosOpenDrvRefCntDec;
IMPORT int _func_iosOpenDrvRefCntInc;
IMPORT int _func_iosPathFdEntryIoctl;
IMPORT int _func_iosPosixFdEntryIoctl;
IMPORT int _func_iosRtpIoTableSizeGet;
IMPORT int _func_iosRtpIoTableSizeSet;
IMPORT int _func_isrConnect;
IMPORT int _func_isrCreate;
IMPORT int _func_isrDelete;
IMPORT int _func_isrDisconnect;
IMPORT int _func_isrDispatcher;
IMPORT int _func_isrInfo;
IMPORT int _func_jobTaskWorkAdd;
IMPORT int _func_kernelModuleListIdGet;
IMPORT int _func_kernelRoundRobinHook;
IMPORT int _func_kprintf;
IMPORT int _func_kwrite;
IMPORT int _func_lf_advlock;
IMPORT int _func_loadRtpDeltaBaseAddrApply;
IMPORT int _func_loadRtpSymsPolicyOverride;
IMPORT int _func_logMsg;
IMPORT int _func_loginPrompt2;
IMPORT int _func_loginStringGet;
IMPORT int _func_loginStringSet;
IMPORT int _func_m2PollStatsIfPoll;
IMPORT int _func_memPartCacheAlloc;
IMPORT int _func_memPartCacheFree;
IMPORT int _func_memPartCacheInfoGet;
IMPORT int _func_memPartRealloc;
IMPORT int _func_memPartReallocInternal;
IMPORT int _func_memalign;
IMPORT int _func_mmuFaultAddrGet;
IMPORT int _func_mmuFaultStatusGet;
IMPORT int _func_mmuIFaultStatusGet;
IMPORT int _func_moduleIdFigure;
IMPORT int _func_moduleSegInfoGet;
IMPORT int _func_mux;
IMPORT int _func_mux_l2;
IMPORT int _func_netAttrDeReg;
IMPORT int _func_netAttrReg;
IMPORT int _func_netChDirByName;
IMPORT int _func_netDaemonIxToQId;
IMPORT int _func_netDaemonQIdToIx;
IMPORT int _func_netLsByName;
IMPORT int _func_netPoolShow;
IMPORT int _func_objCoreRelease;
IMPORT int _func_objHandleToObjId;
IMPORT int _func_objNameVerifiedSet;
IMPORT int _func_objOwnerListAdd;
IMPORT int _func_objOwnerListRemove;
IMPORT int _func_objOwnerReclaim;
IMPORT int _func_objOwnerSetBaseInternal;
IMPORT int _func_objOwnerSetInternal;
IMPORT int _func_objRtpObjEachHook;
IMPORT int _func_ownerListLock;
IMPORT int _func_ownerListUnlock;
IMPORT int _func_printErr;
IMPORT int _func_printExcPrintHook;
IMPORT int _func_proofUtf8String;
IMPORT int _func_pthread_testandset_canceltype;
IMPORT int _func_pxCpuTimerCancel;
IMPORT int _func_pxCpuTimerCreate;
IMPORT int _func_pxCpuTimerDelete;
IMPORT int _func_pxCpuTimerStart;
IMPORT int _func_qPriBMapNativeResort;
IMPORT int _func_remCurIdGet;
IMPORT int _func_remCurIdSet;
IMPORT int _func_rtpDelete;
IMPORT int _func_rtpDeleteHookAdd;
IMPORT int _func_rtpDeleteHookDelete;
IMPORT int _func_rtpDeletionDeferDisable;
IMPORT int _func_rtpDeletionDeferEnable;
IMPORT int _func_rtpExtraCmdGet;
IMPORT int _func_rtpHandleIdGet;
IMPORT int _func_rtpIdVerify;
IMPORT int _func_rtpInitCompleteHookAdd;
IMPORT int _func_rtpInitCompleteHookDelete;
IMPORT int _func_rtpPause;
IMPORT int _func_rtpPostCreateHookAdd;
IMPORT int _func_rtpPostCreateHookDelete;
IMPORT int _func_rtpPreCreateHookAdd;
IMPORT int _func_rtpPreCreateHookDelete;
IMPORT int _func_rtpSdUnmapAll;
IMPORT int _func_rtpShlCloseHook;
IMPORT int _func_rtpShlDeleteAll;
IMPORT int _func_rtpShlInfoGet;
IMPORT int _func_rtpShlOpenHook;
IMPORT int _func_rtpShlSymbolsRegister;
IMPORT int _func_rtpShlSymbolsUnregister;
IMPORT int _func_rtpShow;
IMPORT int _func_rtpSigExcKill;
IMPORT int _func_rtpSigPendDestroy;
IMPORT int _func_rtpSigPendInit;
IMPORT int _func_rtpSigPendKill;
IMPORT int _func_rtpSigaction;
IMPORT int _func_rtpSigpending;
IMPORT int _func_rtpSigprocmask;
IMPORT int _func_rtpSigqueue;
IMPORT int _func_rtpSigsuspend;
IMPORT int _func_rtpSigtimedwait;
IMPORT int _func_rtpSpawn;
IMPORT int _func_rtpSymTblIdGet;
IMPORT int _func_rtpTaskEach;
IMPORT int _func_rtpTaskKill;
IMPORT int _func_rtpTaskSigBlock;
IMPORT int _func_rtpTaskSigCheck;
IMPORT int _func_rtpTaskSigPendKill;
IMPORT int _func_rtpTaskSigqueue;
IMPORT int _func_rtpVarAdd;
IMPORT int _func_rtpVerifiedLock;
IMPORT int _func_selPtyAdd;
IMPORT int _func_selPtyDelete;
IMPORT int _func_selPtySlaveAdd;
IMPORT int _func_selPtySlaveDelete;
IMPORT int _func_selTyAdd;
IMPORT int _func_selTyDelete;
IMPORT int _func_selWakeup;
IMPORT int _func_selWakeupAll;
IMPORT int _func_selWakeupListInit;
IMPORT int _func_selWakeupListTerm;
IMPORT int _func_semExchange;
IMPORT int _func_semRTake;
IMPORT int _func_semWTake;
IMPORT int _func_shellDbgCallPrint;
IMPORT int _func_shellDbgStackTrace;
IMPORT int _func_shellExcPrint;
IMPORT int _func_sigExcKill;
IMPORT int _func_sigTimeoutRecalc;
IMPORT int _func_sigeventInit;
IMPORT int _func_sigfillset;
IMPORT int _func_signalMmanHook;
IMPORT int _func_sigprocmask;
IMPORT int _func_spy;
IMPORT int _func_spy2;
IMPORT int _func_spyClkStart;
IMPORT int _func_spyClkStop;
IMPORT int _func_spyReport;
IMPORT int _func_spyReport2;
IMPORT int _func_spyStop;
IMPORT int _func_spyTask;
IMPORT int _func_symEach;
IMPORT int _func_symEachCall;
IMPORT int _func_symFind;
IMPORT int _func_symFindSymbol;
IMPORT int _func_symNameGet;
IMPORT int _func_symRegister;
IMPORT int _func_symTblShutdown;
IMPORT int _func_symTypeGet;
IMPORT int _func_symValueGet;
IMPORT int _func_taskCreateHookAdd;
IMPORT int _func_taskDeleteHookAdd;
IMPORT int _func_taskMemCtxSwitch;
IMPORT int _func_taskStackAlloc;
IMPORT int _func_taskStackFree;
IMPORT int _func_tipStart;
IMPORT int _func_unldByModuleId;
IMPORT int _func_utf16ToCP;
IMPORT int _func_utf16ToUtf8String;
IMPORT int _func_utf16ToUtf8StringBOM;
IMPORT int _func_utf8ToCP;
IMPORT int _func_utf8ToUtf16String;
IMPORT int _func_utf8ToUtf16StringBOM;
IMPORT int _func_utflen16;
IMPORT int _func_utflen8;
IMPORT int _func_valloc;
IMPORT int _func_vfpExcHandle;
IMPORT int _func_vfpHasException;
IMPORT int _func_vfpIsEnabled;
IMPORT int _func_vfpSave;
IMPORT int _func_virtExtraMapInfoGet;
IMPORT int _func_virtSegInfoGet;
IMPORT int _func_vmBaseFuncsSet;
IMPORT int _func_vmInvPageMap;
IMPORT int _func_vmInvUnMap;
IMPORT int _func_vxMemProbeHook;
IMPORT int _func_vxbDelayCommon;
IMPORT int _func_vxbIntConnect;
IMPORT int _func_vxbIntDisable;
IMPORT int _func_vxbIntDisconnect;
IMPORT int _func_vxbIntDynaConnect;
IMPORT int _func_vxbIntDynaCtlrInputInit;
IMPORT int _func_vxbIntDynaVecAlloc;
IMPORT int _func_vxbIntDynaVecDevMultiProgram;
IMPORT int _func_vxbIntDynaVecDisable;
IMPORT int _func_vxbIntDynaVecEnable;
IMPORT int _func_vxbIntDynaVecErase;
IMPORT int _func_vxbIntDynaVecGet;
IMPORT int _func_vxbIntDynaVecOwnerFind;
IMPORT int _func_vxbIntDynaVecProgram;
IMPORT int _func_vxbIntEnable;
IMPORT int _func_vxbPciDevCfgRead;
IMPORT int _func_vxbPciDevCfgWrite;
IMPORT int _func_vxbUserHookDevInit;
IMPORT int _func_vxdbgBpDelete;
IMPORT int _func_vxdbgCtxCont;
IMPORT int _func_vxdbgCtxStop;
IMPORT int _func_vxdbgMemMove;
IMPORT int _func_vxdbgMemRead;
IMPORT int _func_vxdbgMemScan;
IMPORT int _func_vxdbgMemWrite;
IMPORT int _func_vxdbgRtpCont;
IMPORT int _func_vxdbgRtpIdVerify;
IMPORT int _func_vxdbgRtpStop;
IMPORT int _func_vxdbgTrap;
IMPORT int _func_wdbExternCoprocRegsGet;
IMPORT int _func_wdbExternCoprocRegsSet;
IMPORT int _func_wdbExternEnterHookAdd;
IMPORT int _func_wdbExternExitHookAdd;
IMPORT int _func_wdbExternNotifyHost;
IMPORT int _func_wdbExternRcvHook;
IMPORT int _func_wdbResumeSystem;
IMPORT int _func_wdbSuspendSystem;
IMPORT int _func_wdbTaskBpByIdRemove;
IMPORT int _func_wdbTaskCoprocRegsGet;
IMPORT int _func_wdbTaskCoprocRegsSet;
IMPORT int _func_wdbTrap;
IMPORT int _func_windSemRWDelete;
IMPORT int _func_windTickAnnounceHook;
IMPORT int _func_workQDbgTextDump;
IMPORT int _hostAdd ();
IMPORT int _hostDelete ();
IMPORT int _hostGetByAddr ();
IMPORT int _hostGetByName ();
IMPORT int _hostTblSearchByName2 ();
IMPORT int _ipcom_gethostbyaddr_r;
IMPORT int _ipcom_gethostbyname_r;
IMPORT int _ipdhcpc_callback_hook;
IMPORT int _linkMemReqClAlign;
IMPORT int _linkMemReqMlinkAlign;
IMPORT int _mprec_log10 ();
IMPORT int _muxProtosPerEndInc;
IMPORT int _muxProtosPerEndStart;
IMPORT int _netMemReqDefault ();
IMPORT int _netSysctl;
IMPORT int _netSysctlCli;
IMPORT int _pLinkPoolFuncTbl;
IMPORT int _pNetBufCollect;
IMPORT int _pNetDpool;
IMPORT int _pNetPoolFuncAlignTbl;
IMPORT int _pNetPoolFuncTbl;
IMPORT int _pNetSysPool;
IMPORT int _pSigQueueFreeHead;
IMPORT int _pSysL2CacheClear;
IMPORT int _pSysL2CacheDisable;
IMPORT int _pSysL2CacheEnable;
IMPORT int _pSysL2CacheFlush;
IMPORT int _pSysL2CacheInvFunc;
IMPORT int _pSysL2CachePipeFlush;
IMPORT int _panicHook;
IMPORT int _pingSockBufSize2;
IMPORT int _pingTxInterval2;
IMPORT int _pingTxLen;
IMPORT int _pingTxLen2;
IMPORT int _pingTxTmo;
IMPORT int _pingTxTmo2;
IMPORT int _procNumWasSet;
IMPORT int _setjmpSetup ();
IMPORT int _sigCtxLoad ();
IMPORT int _sigCtxRtnValSet ();
IMPORT int _sigCtxSave ();
IMPORT int _sigCtxSetup ();
IMPORT int _sigCtxStackEnd ();
IMPORT int _sigfaulttable;
IMPORT int _taskSuspend ();
IMPORT int _vdsqrt ();
IMPORT int _vxb_clkConnectRtn;
IMPORT int _vxb_clkDisableRtn;
IMPORT int _vxb_clkEnableRtn;
IMPORT int _vxb_clkRateGetRtn;
IMPORT int _vxb_clkRateSetRtn;
IMPORT int _vxb_delayRtn;
IMPORT int _vxb_msDelayRtn;
IMPORT int _vxb_timestampConnectRtn;
IMPORT int _vxb_timestampDisableRtn;
IMPORT int _vxb_timestampEnableRtn;
IMPORT int _vxb_timestampFreqRtn;
IMPORT int _vxb_timestampLockRtn;
IMPORT int _vxb_timestampPeriodRtn;
IMPORT int _vxb_timestampRtn;
IMPORT int _vxb_usDelayRtn;
IMPORT int _vxmux_pNullPoolFuncTbl;
IMPORT int _vxworks_asctime_r ();
IMPORT int _vxworks_ctime_r ();
IMPORT int _vxworks_gmtime_r ();
IMPORT int _vxworks_localtime_r ();
IMPORT int _zbufCreate_nolock ();
IMPORT int _zbufDeleteEmpty ();
IMPORT int _zbufSetSeg ();
IMPORT int _zbuf_getseg_nolock ();
IMPORT int _zbuf_getsegptr_nolock ();
IMPORT int abort ();
IMPORT int abs ();
IMPORT int absSymbols_Bounds ();
IMPORT int absSymbols_Common ();
IMPORT int accept ();
IMPORT int access ();
IMPORT int acos ();
IMPORT int adrSpaceInfoGet ();
IMPORT int adrSpaceIsOverlapped ();
IMPORT int adrSpaceLibInit ();
IMPORT int adrSpaceModel;
IMPORT int adrSpaceOptimizedSizeGet ();
IMPORT int adrSpacePageAlloc ();
IMPORT int adrSpacePageFree ();
IMPORT int adrSpacePageMap ();
IMPORT int adrSpacePageUnmap ();
IMPORT int adrSpaceRAMAddToPool ();
IMPORT int adrSpaceRAMReserve ();
IMPORT int adrSpaceRgnPreAlloc ();
IMPORT int adrSpaceVirtReserve ();
IMPORT int aimCacheInit ();
IMPORT int aimMmuBaseLibInit ();
IMPORT int alarm ();
IMPORT int allocChunkEndGuardSize;
IMPORT int altera16550Dev0Resources;
IMPORT int altera16550Dev1Resources;
IMPORT int alteraTimerDev0Resources;
IMPORT int alteraTimerDev3Resources;
IMPORT int alteraTimerDevRegistration;
IMPORT int app_main ();
IMPORT int app_realtime_print ();
IMPORT int app_register_task ();
IMPORT int app_show_count ();
IMPORT int app_start ();
IMPORT int app_start_hz ();
IMPORT int app_stop ();
IMPORT int app_unregister_task ();
IMPORT int applLoggerInit ();
IMPORT int applLoggerStop ();
IMPORT int applUtilInstInit ();
IMPORT int applUtilLogSem;
IMPORT int archPwrDown ();
IMPORT int armGIC0Resources;
IMPORT int armGetNpc ();
IMPORT int armInitExceptionModes ();
IMPORT int armInstrChangesPc ();
IMPORT int armv7GenTimerAllocate ();
IMPORT int armv7GenTimerCountGet ();
IMPORT int armv7GenTimerCountGet64 ();
IMPORT int armv7GenTimerDbgMask;
IMPORT int armv7GenTimerDevInit ();
IMPORT int armv7GenTimerDisable ();
IMPORT int armv7GenTimerDisableInternal ();
IMPORT int armv7GenTimerDrvFuncs;
IMPORT int armv7GenTimerDrvRegister ();
IMPORT int armv7GenTimerDrvRegister2 ();
IMPORT int armv7GenTimerDrvRegistration;
IMPORT int armv7GenTimerDrv_methods;
IMPORT int armv7GenTimerEnable ();
IMPORT int armv7GenTimerEnable64 ();
IMPORT int armv7GenTimerFuncGet ();
IMPORT int armv7GenTimerISRSet ();
IMPORT int armv7GenTimerInstConnect ();
IMPORT int armv7GenTimerInstInit ();
IMPORT int armv7GenTimerInstInit2 ();
IMPORT int armv7GenTimerIsr ();
IMPORT int armv7GenTimerRelease ();
IMPORT int armv7GenTimerRolloverGet ();
IMPORT int armv7GenTimerRolloverGet64 ();
IMPORT int asMemDescNumEnt;
IMPORT int asc2_0806;
IMPORT int asc2_1206;
IMPORT int asc2_1608;
IMPORT int asc2_2412;
IMPORT int asctime ();
IMPORT int asctime_r ();
IMPORT int asin ();
IMPORT int assertlist;
IMPORT int atan ();
IMPORT int atan2 ();
IMPORT int atexit ();
IMPORT int atof ();
IMPORT int atoi ();
IMPORT int atol ();
IMPORT int atomic32Add ();
IMPORT int atomic32And ();
IMPORT int atomic32Cas ();
IMPORT int atomic32Clear ();
IMPORT int atomic32Dec ();
IMPORT int atomic32Get ();
IMPORT int atomic32Inc ();
IMPORT int atomic32Nand ();
IMPORT int atomic32Or ();
IMPORT int atomic32Set ();
IMPORT int atomic32Sub ();
IMPORT int atomic32Xor ();
IMPORT int attrib ();
IMPORT int attribDisplay ();
IMPORT int attribDisplayFile ();
IMPORT int autoNegForce;
IMPORT int avlDelete ();
IMPORT int avlInsert ();
IMPORT int avlInsertInform ();
IMPORT int avlMaximumGet ();
IMPORT int avlMinimumGet ();
IMPORT int avlPredecessorGet ();
IMPORT int avlRemoveInsert ();
IMPORT int avlSearch ();
IMPORT int avlSuccessorGet ();
IMPORT int avlTreeWalk ();
IMPORT int avlUintDelete ();
IMPORT int avlUintInsert ();
IMPORT int avlUintMaximumGet ();
IMPORT int avlUintMinimumGet ();
IMPORT int avlUintPredecessorGet ();
IMPORT int avlUintSearch ();
IMPORT int avlUintSuccessorGet ();
IMPORT int avlUintTreeWalk ();
IMPORT int axi165502CInit ();
IMPORT int axi16550BaudInit ();
IMPORT int axi16550FIFOInit ();
IMPORT int axi16550Init ();
IMPORT int axi16550Recv ();
IMPORT int axi16550Send ();
IMPORT int axi16550SendNoWait ();
IMPORT int axi16550SendStartBreak ();
IMPORT int axi16550SendStopBreak ();
IMPORT int axi16550_TxReady ();
IMPORT int b ();
IMPORT int baudRateSet ();
IMPORT int bauderate_table;
IMPORT int bcmp ();
IMPORT int bcopy ();
IMPORT int bcopyBytes ();
IMPORT int bcopyLongs ();
IMPORT int bcopyNeon ();
IMPORT int bcopyWords ();
IMPORT int bd ();
IMPORT int bdall ();
IMPORT int bfill ();
IMPORT int bfillBytes ();
IMPORT int bh ();
IMPORT int bi ();
IMPORT int bind ();
IMPORT int bindresvport ();
IMPORT int bindresvportCommon ();
IMPORT int bindresvport_af ();
IMPORT int binvert ();
IMPORT int bioInit ();
IMPORT int bio_alloc ();
IMPORT int bio_done ();
IMPORT int bio_free ();
IMPORT int blkXbdDevCreate ();
IMPORT int blkXbdDevDelete ();
IMPORT int bootBpAnchorExtract ();
IMPORT int bootChange ();
IMPORT int bootLeaseExtract ();
IMPORT int bootNetmaskExtract ();
IMPORT int bootParamsErrorPrint ();
IMPORT int bootParamsPrompt ();
IMPORT int bootParamsShow ();
IMPORT int bootScanNum ();
IMPORT int bootStringToStruct ();
IMPORT int bootStringToStructAdd ();
IMPORT int bootStructToString ();
IMPORT int bsd_cvt ();
IMPORT int bsearch ();
IMPORT int bspSerialChanGet ();
IMPORT int bswap ();
IMPORT int busCtlrDevCtlr_desc;
IMPORT int busDevShow_desc;
IMPORT int bzero ();
IMPORT int c ();
IMPORT int cacheAddrAlign;
IMPORT int cacheAimArch6DClear ();
IMPORT int cacheAimArch6DFlush ();
IMPORT int cacheAimArch6DInvalidate ();
IMPORT int cacheAimArch6IClearDisable ();
IMPORT int cacheAimArch6IInvalidate ();
IMPORT int cacheAimArch6IInvalidateAll ();
IMPORT int cacheAimArch6PipeFlush ();
IMPORT int cacheAimArch7DClearAll ();
IMPORT int cacheAimArch7DDisable ();
IMPORT int cacheAimArch7DEnable ();
IMPORT int cacheAimArch7DFlushAll ();
IMPORT int cacheAimArch7DFlushPoU ();
IMPORT int cacheAimArch7DInvalidateAll ();
IMPORT int cacheAimArch7DIsOn ();
IMPORT int cacheAimArch7DProbe ();
IMPORT int cacheAimArch7DmaFree ();
IMPORT int cacheAimArch7DmaMalloc ();
IMPORT int cacheAimArch7IDisable ();
IMPORT int cacheAimArch7IEnable ();
IMPORT int cacheAimArch7IIsOn ();
IMPORT int cacheAimArch7IProbe ();
IMPORT int cacheAimArch7Identify ();
IMPORT int cacheAimArch7MmuIsOn ();
IMPORT int cacheAimArch7SizeInfoGet ();
IMPORT int cacheAimArch7TextUpdate ();
IMPORT int cacheAimCortexA15LibInit ();
IMPORT int cacheAimCortexA15PhysToVirt;
IMPORT int cacheAimCortexA15VirtToPhys;
IMPORT int cacheAimInfo;
IMPORT int cacheArch7CLIDR ();
IMPORT int cacheArchAlignSize;
IMPORT int cacheArchDClear ();
IMPORT int cacheArchDClearAll ();
IMPORT int cacheArchDFlush ();
IMPORT int cacheArchDFlushAll ();
IMPORT int cacheArchDInvalidate ();
IMPORT int cacheArchDInvalidateAll ();
IMPORT int cacheArchIInvalidate ();
IMPORT int cacheArchIInvalidateAll ();
IMPORT int cacheArchIntLock ();
IMPORT int cacheArchIntMask;
IMPORT int cacheArchL2CacheDisable ();
IMPORT int cacheArchL2CacheEnable ();
IMPORT int cacheArchL2CacheIsOn ();
IMPORT int cacheArchLocSizeGet ();
IMPORT int cacheArchLouSizeGet ();
IMPORT int cacheArchPipeFlush ();
IMPORT int cacheArchState;
IMPORT int cacheClear ();
IMPORT int cacheCortexA15DClearDisable ();
IMPORT int cacheCortexA15L2CacrGet ();
IMPORT int cacheCortexA15L2CacrSet ();
IMPORT int cacheCortexA15L2EcrGet ();
IMPORT int cacheCortexA15L2EcrSet ();
IMPORT int cacheCortexA15LibInstall ();
IMPORT int cacheCortexA8DClearDisable ();
IMPORT int cacheCortexA8L2CacrGet ();
IMPORT int cacheCortexA8L2CacrSet ();
IMPORT int cacheCortexA8L2ClearAll ();
IMPORT int cacheCortexA8L2Disable ();
IMPORT int cacheCortexA8L2Enable ();
IMPORT int cacheDataEnabled;
IMPORT int cacheDataMode;
IMPORT int cacheDisable ();
IMPORT int cacheDma32Free ();
IMPORT int cacheDma32Malloc ();
IMPORT int cacheDmaFree ();
IMPORT int cacheDmaFreeRtn;
IMPORT int cacheDmaFuncs;
IMPORT int cacheDmaMalloc ();
IMPORT int cacheDmaMallocRtn;
IMPORT int cacheDrvFlush ();
IMPORT int cacheDrvInvalidate ();
IMPORT int cacheDrvPhysToVirt ();
IMPORT int cacheDrvVirtToPhys ();
IMPORT int cacheEnable ();
IMPORT int cacheFlush ();
IMPORT int cacheForeignClear ();
IMPORT int cacheForeignFlush ();
IMPORT int cacheForeignInvalidate ();
IMPORT int cacheFuncsSet ();
IMPORT int cacheInvalidate ();
IMPORT int cacheLib;
IMPORT int cacheLibInit ();
IMPORT int cacheLineMask;
IMPORT int cacheLineSize;
IMPORT int cacheLock ();
IMPORT int cacheMmuAvailable;
IMPORT int cacheNullFuncs;
IMPORT int cachePipeFlush ();
IMPORT int cacheTextLocalUpdate ();
IMPORT int cacheTextUpdate ();
IMPORT int cacheUnlock ();
IMPORT int cacheUserFuncs;
IMPORT int calloc ();
IMPORT int catInfo;
IMPORT int cd ();
IMPORT int ceil ();
IMPORT int cfree ();
IMPORT int changeFpReg ();
IMPORT int changeLogLevel ();
IMPORT int changeReg ();
IMPORT int chdir ();
IMPORT int checkStack ();
IMPORT int checksum ();
IMPORT int chkdsk ();
IMPORT int chmod ();
IMPORT int classCreateConnect ();
IMPORT int classDestroyConnect ();
IMPORT int classIdTable;
IMPORT int classInit ();
IMPORT int classLibInit ();
IMPORT int classListLibInit ();
IMPORT int classMemPartIdSet ();
IMPORT int classShowConnect ();
IMPORT int clearerr ();
IMPORT int clk_all_show ();
IMPORT int clk_cpu_get ();
IMPORT int clk_cpu_show ();
IMPORT int clk_ddr_get ();
IMPORT int clk_ddr_show ();
IMPORT int clk_fclk0_get ();
IMPORT int clk_fclk1_get ();
IMPORT int clk_fclk2_get ();
IMPORT int clk_fclk3_get ();
IMPORT int clk_fclk_show ();
IMPORT int clk_gem0_show ();
IMPORT int clk_gem0_tx_div_get ();
IMPORT int clk_gem0_tx_get ();
IMPORT int clk_gem1_show ();
IMPORT int clk_gem1_tx_div_get ();
IMPORT int clk_gem1_tx_get ();
IMPORT int clk_gtc_get ();
IMPORT int clk_gtc_show ();
IMPORT int clk_nfc_get ();
IMPORT int clk_nfc_show ();
IMPORT int clk_pcap_get ();
IMPORT int clk_pcap_show ();
IMPORT int clk_qspi_get ();
IMPORT int clk_qspi_show ();
IMPORT int clk_sdmmc_get ();
IMPORT int clk_sdmmc_set ();
IMPORT int clk_sdmmc_show ();
IMPORT int clk_spi_get ();
IMPORT int clk_spi_show ();
IMPORT int clk_switch_sdmmc_0 ();
IMPORT int clk_switch_sdmmc_1 ();
IMPORT int clk_ttc_get ();
IMPORT int clk_ttc_show ();
IMPORT int clk_uart_get ();
IMPORT int clk_uart_show ();
IMPORT int clock ();
IMPORT int clockLibInit ();
IMPORT int clock_getres ();
IMPORT int clock_gettime ();
IMPORT int clock_gettime_wd ();
IMPORT int clock_nanosleep ();
IMPORT int clock_setres ();
IMPORT int clock_settime ();
IMPORT int close ();
IMPORT int closedir ();
IMPORT int code_table;
IMPORT int commit ();
IMPORT int completionPathComplete ();
IMPORT int completionPathListGet ();
IMPORT int completionPathShow ();
IMPORT int completionSymComplete ();
IMPORT int completionSymListGet ();
IMPORT int completionSymShow ();
IMPORT int connect ();
IMPORT int connectWithTimeout ();
IMPORT int consoleFd;
IMPORT int coprocCtxReplicate ();
IMPORT int coprocCtxStorageSizeGet ();
IMPORT int coprocDescriptorsInit ();
IMPORT int coprocDisable ();
IMPORT int coprocEnable ();
IMPORT int coprocLibInit ();
IMPORT int coprocMRegs ();
IMPORT int coprocRegListShow ();
IMPORT int coprocSave ();
IMPORT int coprocShow ();
IMPORT int coprocShowInit ();
IMPORT int coprocShowOnDebug ();
IMPORT int coprocTaskCreateHook ();
IMPORT int coprocTaskDeleteHook ();
IMPORT int coprocTaskRegsGet ();
IMPORT int coprocTaskRegsSet ();
IMPORT int coprocTaskRegsShow ();
IMPORT int coprocTaskSwapHook ();
IMPORT int coprocsDiscover ();
IMPORT int copy ();
IMPORT int copyStreams ();
IMPORT int copysign ();
IMPORT int cos ();
IMPORT int cosh ();
IMPORT int cp ();
IMPORT int cp2 ();
IMPORT int cplusCallCtors ();
IMPORT int cplusCallDtors ();
IMPORT int cplusCtors ();
IMPORT int cplusCtorsLink ();
IMPORT int cplusDemangle ();
IMPORT int cplusDemangle2 ();
IMPORT int cplusDemangle2Func;
IMPORT int cplusDemangleFunc;
IMPORT int cplusDemangleToBuffer ();
IMPORT int cplusDemangleToBufferFunc;
IMPORT int cplusDemanglerMode;
IMPORT int cplusDemanglerSet ();
IMPORT int cplusDemanglerStyle;
IMPORT int cplusDemanglerStyleInit ();
IMPORT int cplusDemanglerStyleSet ();
IMPORT int cplusDtors ();
IMPORT int cplusDtorsLink ();
IMPORT int cplusLoadCtorsCall ();
IMPORT int cplusLoadFixup ();
IMPORT int cplusMangledSymCheck ();
IMPORT int cplusMangledSymGet ();
IMPORT int cplusMatchMangled ();
IMPORT int cplusMatchMangledListGet ();
IMPORT int cplusUnloadFixup ();
IMPORT int cplusUserAsk ();
IMPORT int cplusXtorGet ();
IMPORT int cplusXtorSet ();
IMPORT int cplusXtorStrategy;
IMPORT int cpsr ();
IMPORT int creat ();
IMPORT char * creationDate;
IMPORT int cret ();
IMPORT int ctime ();
IMPORT int ctime_r ();
IMPORT int d ();
IMPORT int data_bit_table;
IMPORT int dbgBpEpCoreRtn ();
IMPORT int dbgBpListPrint ();
IMPORT int dbgCallPrint ();
IMPORT int dbgDisassemble ();
IMPORT int dbgDynPrintfCommonRtn ();
IMPORT int dbgHelp ();
IMPORT int dbgInit ();
IMPORT int dbgPrintDsp;
IMPORT int dbgPrintFpp;
IMPORT int dbgPrintSimd;
IMPORT int dbgShellCmdInit ();
IMPORT int dbgStackTrace ();
IMPORT int dbgTaskTraceCoreRtn ();
IMPORT int ddr_dRate_get ();
IMPORT int defaultDrv;
IMPORT int delay_1ms ();
IMPORT int delay_1us ();
IMPORT int delay_ms ();
IMPORT int delay_us ();
IMPORT int devAttach ();
IMPORT int devC_Load_BitStream_NonSecure ();
IMPORT int devC_Load_BitStream_NonSecure_2 ();
IMPORT int devC_Update_PL ();
IMPORT int devC_Update_PL_part ();
IMPORT int devDetach ();
IMPORT int devGetByName ();
IMPORT int devInit ();
IMPORT int devMap ();
IMPORT int devMapUnsafe ();
IMPORT int devName ();
IMPORT int devResourceGet ();
IMPORT int devResourceIntrGet ();
IMPORT int devUnmap ();
IMPORT int devUnmapUnsafe ();
IMPORT int dev_config_init ();
IMPORT int dev_config_load_defaults ();
IMPORT int dev_config_print ();
IMPORT int dev_config_save ();
IMPORT int dev_reboot ();
IMPORT int devcCtrl_Clr_PL_BitStream ();
IMPORT int devcCtrl_Clr_PcapStatus ();
IMPORT int devcCtrl_Init_Pcap ();
IMPORT int devcCtrl_Init_PcapDma ();
IMPORT int devcCtrl_Init_PcapDma_RdBack ();
IMPORT int devcCtrl_Init_Pcap_part ();
IMPORT int devcCtrl_Load_Pcap_BitStream ();
IMPORT int devcCtrl_Lock_CSU ();
IMPORT int devcCtrl_Poll_DmaDone ();
IMPORT int devcCtrl_Poll_DmaPcap_Done ();
IMPORT int devcCtrl_Poll_FpgaDone ();
IMPORT int devcCtrl_Prog_B ();
IMPORT int devcCtrl_Rd_CfgReg32 ();
IMPORT int devcCtrl_SAC_rst ();
IMPORT int devcCtrl_SetHi_CSI_B ();
IMPORT int devcCtrl_SetHi_RDWR_B ();
IMPORT int devcCtrl_SetLow_CSI_B ();
IMPORT int devcCtrl_SetLow_RDWR_B ();
IMPORT int devcCtrl_Set_DummyCnt ();
IMPORT int devcCtrl_Set_PL_DwnLdMode ();
IMPORT int devcCtrl_Set_RdClk_Edge ();
IMPORT int devcCtrl_Set_ReadFifoThrsh ();
IMPORT int devcCtrl_Set_Reg32 ();
IMPORT int devcCtrl_Set_RxDataSwap ();
IMPORT int devcCtrl_Set_Smap32_SwapCtrl ();
IMPORT int devcCtrl_Set_TxDataSwap ();
IMPORT int devcCtrl_Set_WrClk_Edge ();
IMPORT int devcCtrl_Set_WriteFifoThrsh ();
IMPORT int devcCtrl_UnLock_CSU ();
IMPORT int devcCtrl_Wr_CfgReg32 ();
IMPORT int devcCtrl_Xfer_Pcap ();
IMPORT int devcSlcr_Dis_CfgLvlShift ();
IMPORT int devcSlcr_Dis_UseLvlShift ();
IMPORT int devcSlcr_Down_CpuFreq ();
IMPORT int devcSlcr_En_CfgLvlShift ();
IMPORT int devcSlcr_En_UsrLvlShift ();
IMPORT int devcSlcr_Up_CpuFreq ();
IMPORT int devs ();
IMPORT int difftime ();
IMPORT int dirList ();
IMPORT int diskFormat ();
IMPORT int diskInit ();
IMPORT int div ();
IMPORT int div32 ();
IMPORT int div_r ();
IMPORT int dllAdd ();
IMPORT int dllCount ();
IMPORT int dllEach ();
IMPORT int dllGet ();
IMPORT int dllInit ();
IMPORT int dllInsert ();
IMPORT int dllRemove ();
IMPORT int dllTerminate ();
IMPORT int dmaCtrl_Chk_ChnBusy ();
IMPORT int dmaCtrl_Chk_ChnRange ();
IMPORT int dmaCtrl_Clr_IRQ ();
IMPORT int dmaCtrl_Dis_ChnIRQ ();
IMPORT int dmaCtrl_Dis_ChnX ();
IMPORT int dmaCtrl_Dis_Ctrl ();
IMPORT int dmaCtrl_Disable_Ctrl ();
IMPORT int dmaCtrl_En_ChnIRQ ();
IMPORT int dmaCtrl_Enable_ChnX ();
IMPORT int dmaCtrl_Enable_Ctrl ();
IMPORT int dmaCtrl_Get_BurstSize ();
IMPORT int dmaCtrl_Get_ChnCfg ();
IMPORT int dmaCtrl_Get_ChnIdx ();
IMPORT int dmaCtrl_Get_DefaultParams ();
IMPORT int dmaCtrl_Get_DefaultParams2 ();
IMPORT int dmaCtrl_Get_FreeChn ();
IMPORT int dmaCtrl_Get_HandShakMode ();
IMPORT int dmaCtrl_Get_PartParams ();
IMPORT int dmaCtrl_Get_XferPath ();
IMPORT int dmaCtrl_Get_XferType ();
IMPORT int dmaCtrl_Get_XferWidth ();
IMPORT int dmaCtrl_Init ();
IMPORT int dmaCtrl_Mask_IRQ ();
IMPORT int dmaCtrl_PreInit ();
IMPORT int dmaCtrl_Rd_CfgReg32 ();
IMPORT int dmaCtrl_Set_BlockChain_En ();
IMPORT int dmaCtrl_Set_BurstSize ();
IMPORT int dmaCtrl_Set_ChnCfg ();
IMPORT int dmaCtrl_Set_ChnPriority ();
IMPORT int dmaCtrl_Set_HandShakMode ();
IMPORT int dmaCtrl_Set_ListPtrAddr ();
IMPORT int dmaCtrl_Set_ReLoad ();
IMPORT int dmaCtrl_Set_TestMode ();
IMPORT int dmaCtrl_Set_XferPath ();
IMPORT int dmaCtrl_Set_XferType ();
IMPORT int dmaCtrl_Set_XferWidth ();
IMPORT int dmaCtrl_Start_Xfer ();
IMPORT int dmaCtrl_UnMask_IRQ ();
IMPORT int dmaCtrl_Wr_CfgReg32 ();
IMPORT int dmac_test_example ();
IMPORT int dosChkDebug;
IMPORT int dosChkDsk ();
IMPORT int dosChkLibInit ();
IMPORT int dosChkMinDate;
IMPORT int dosDirHdlrsList;
IMPORT int dosDirOldDebug;
IMPORT int dosDirOldLibInit ();
IMPORT int dosFatHdlrsList;
IMPORT int dosFsCacheCreate ();
IMPORT int dosFsCacheCreateRtn;
IMPORT int dosFsCacheDataDirDefaultSize;
IMPORT int dosFsCacheDelete ();
IMPORT int dosFsCacheDeleteRtn;
IMPORT int dosFsCacheFatDefaultSize;
IMPORT int dosFsCacheInfo ();
IMPORT int dosFsCacheLibInit ();
IMPORT int dosFsCacheMountRtn;
IMPORT int dosFsCacheShow ();
IMPORT int dosFsCacheTune ();
IMPORT int dosFsCacheUnmountRtn;
IMPORT int dosFsChkDsk ();
IMPORT int dosFsChkRtn;
IMPORT int dosFsClose ();
IMPORT int dosFsCompatNT;
IMPORT int dosFsDebug;
IMPORT int dosFsDefaultCacheSizeSet ();
IMPORT int dosFsDefaultDataDirCacheSizeGet ();
IMPORT int dosFsDefaultFatCacheSizeGet ();
IMPORT int dosFsDevCreate ();
IMPORT int dosFsDevDelete ();
IMPORT int dosFsDicard ();
IMPORT int dosFsDiskProbe ();
IMPORT int dosFsDrvNum;
IMPORT int dosFsFatInit ();
IMPORT int dosFsFdFree ();
IMPORT int dosFsFdGet ();
IMPORT int dosFsFmtLargeWriteSize;
IMPORT int dosFsFmtLibInit ();
IMPORT int dosFsHdlrInstall ();
IMPORT int dosFsIoctl ();
IMPORT int dosFsLastAccessDateEnable ();
IMPORT int dosFsLibInit ();
IMPORT int dosFsMonitorDevCreate ();
IMPORT int dosFsMsgLevel;
IMPORT int dosFsMutexOptions;
IMPORT int dosFsOpen ();
IMPORT int dosFsShow ();
IMPORT int dosFsShowInit ();
IMPORT int dosFsTCacheShow ();
IMPORT int dosFsVolDescGet ();
IMPORT int dosFsVolFormat ();
IMPORT int dosFsVolFormatFd ();
IMPORT int dosFsVolFormatWithLabel ();
IMPORT int dosFsVolIsFat12 ();
IMPORT int dosFsVolUnmount ();
IMPORT int dosFsVolumeBioBufferSize;
IMPORT int dosFsVolumeOptionsGet ();
IMPORT int dosFsVolumeOptionsSet ();
IMPORT int dosFsXbdBlkCopy ();
IMPORT int dosFsXbdBlkRead ();
IMPORT int dosFsXbdBlkWrite ();
IMPORT int dosFsXbdBytesRW ();
IMPORT int dosFsXbdIoctl ();
IMPORT int dosPathParse ();
IMPORT int dosSetVolCaseSens ();
IMPORT int dosVDirDebug;
IMPORT int dosVDirLibInit ();
IMPORT int dosVDirLibUptDotDot ();
IMPORT int dosVDirMutexOpt;
IMPORT int dosVDirReaddirPlus ();
IMPORT int dosfsDiskFormat ();
IMPORT int dosfsDiskToHost16 ();
IMPORT int dosfsDiskToHost32 ();
IMPORT int dosfsHostToDisk16 ();
IMPORT int dosfsHostToDisk32 ();
IMPORT int downCpuFreq_ARM_PLL;
IMPORT int dprintf ();
IMPORT int dprintfVerboseLvl;
IMPORT int drvTable;
IMPORT int dsmInst ();
IMPORT int dsmNbytes ();
IMPORT int dummyErrno;
IMPORT int dup ();
IMPORT int dup2 ();
IMPORT int e ();
IMPORT int edrErrorInjectStub ();
IMPORT int edrErrorPolicyHookRemove ();
IMPORT int edrFlagsGet ();
IMPORT int edrInitFatalPolicyHandler ();
IMPORT int edrInterruptFatalPolicyHandler ();
IMPORT int edrIsDebugMode ();
IMPORT int edrKernelFatalPolicyHandler ();
IMPORT int edrPolicyHandlerHookAdd ();
IMPORT int edrPolicyHandlerHookGet ();
IMPORT int edrRtpFatalPolicyHandler ();
IMPORT int edrStubInit ();
IMPORT int edrSystemDebugModeGet ();
IMPORT int edrSystemDebugModeInit ();
IMPORT int edrSystemDebugModeSet ();
IMPORT int edrSystemFatalPolicyHandler ();
IMPORT int elfArchInitHook;
IMPORT int elfArchMdlLoadHook;
IMPORT int elfArchReloc ();
IMPORT int elfArchSymProcessHook;
IMPORT int elfArchVerify ();
IMPORT int end8023AddressForm ();
IMPORT int endDevName ();
IMPORT int endDevTbl;
IMPORT int endEtherAddressForm ();
IMPORT int endEtherCrc32BeGet ();
IMPORT int endEtherCrc32LeGet ();
IMPORT int endEtherHdrInit ();
IMPORT int endEtherPacketAddrGet ();
IMPORT int endEtherPacketDataGet ();
IMPORT int endFindByName ();
IMPORT int endFirstUnitFind ();
IMPORT int endFlagsClr ();
IMPORT int endFlagsGet ();
IMPORT int endFlagsSet ();
IMPORT int endLibInit ();
IMPORT int endList;
IMPORT int endM2Free ();
IMPORT int endM2Init ();
IMPORT int endM2Ioctl ();
IMPORT int endM2Packet;
IMPORT int endMibIfInit ();
IMPORT int endMultiLstCnt ();
IMPORT int endMultiLstFirst ();
IMPORT int endMultiLstNext ();
IMPORT int endObjFlagSet ();
IMPORT int endObjInit ();
IMPORT int endObjectUnload ();
IMPORT int endPollStatsInit ();
IMPORT int endPoolClSize;
IMPORT int endPoolCreate ();
IMPORT int endPoolDestroy ();
IMPORT int endPoolJumboClSize;
IMPORT int endPoolJumboCreate ();
IMPORT int endRcvRtnCall ();
IMPORT int endTxSemGive ();
IMPORT int endTxSemTake ();
IMPORT int envGet ();
IMPORT int envLibInit ();
IMPORT int envLibSemId;
IMPORT int envPrivateCreate ();
IMPORT int envPrivateDestroy ();
IMPORT int envShow ();
IMPORT int erfCatDefSem;
IMPORT int erfCatEventQueues;
IMPORT int erfCategoriesAvailable ();
IMPORT int erfCategoryAllocate ();
IMPORT int erfCategoryQueueCreate ();
IMPORT int erfDbCatSem;
IMPORT int erfDefaultEventQueue;
IMPORT int erfEventQueueSize;
IMPORT int erfEventRaise ();
IMPORT int erfEventTaskOptions;
IMPORT int erfEventTaskPriority;
IMPORT int erfEventTaskStackSize;
IMPORT int erfHandlerDb;
IMPORT int erfHandlerRegister ();
IMPORT int erfHandlerUnregister ();
IMPORT int erfLibInit ();
IMPORT int erfLibInitialized;
IMPORT int erfMaxNumCat;
IMPORT int erfMaxNumType;
IMPORT int erfMaxNumUserCat;
IMPORT int erfMaxNumUserType;
IMPORT int erfNumUserCatDef;
IMPORT int erfNumUserTypeDef;
IMPORT int erfTypeAllocate ();
IMPORT int erfTypesAvailable ();
IMPORT int errno;
IMPORT int errnoGet ();
IMPORT int errnoOfTaskGet ();
IMPORT int errnoOfTaskSet ();
IMPORT int errnoSet ();
IMPORT int eth2_clk_gem_set ();
IMPORT int etherMultiAdd ();
IMPORT int etherMultiDel ();
IMPORT int etherMultiGet ();
IMPORT int etherbroadcastaddr;
IMPORT int eventClear ();
IMPORT int eventInit ();
IMPORT int eventLibInit ();
IMPORT int eventPointStubLibInit ();
IMPORT int eventPointSwHandle ();
IMPORT int eventPointSwStubConnect ();
IMPORT int eventReceive ();
IMPORT int eventRsrcSend ();
IMPORT int eventRsrcShow ();
IMPORT int eventSend ();
IMPORT int eventStart ();
IMPORT int eventTaskShow ();
IMPORT int eventTerminate ();
IMPORT int evtAction;
IMPORT int excEnterDataAbort ();
IMPORT int excEnterPrefetchAbort ();
IMPORT int excEnterSwi ();
IMPORT int excEnterUndef ();
IMPORT int excExcContinue ();
IMPORT int excExcHandle ();
IMPORT int excExcepHook;
IMPORT int excHookAdd ();
IMPORT int excInit ();
IMPORT int excIntConnect ();
IMPORT int excIntHandle ();
IMPORT int excJobAdd ();
IMPORT int excJobAddDefer ();
IMPORT int excOsmInit ();
IMPORT int excPtrTableOffsetSet ();
IMPORT int excShowInit ();
IMPORT int excVBARGet ();
IMPORT int excVBARSet ();
IMPORT int excVecBaseSet ();
IMPORT int excVecGet ();
IMPORT int excVecInit ();
IMPORT int excVecSet ();
IMPORT int excVecUpdate ();
IMPORT int excVmStateSet ();
IMPORT int exit ();
IMPORT int exp ();
IMPORT int expm1 ();
IMPORT int fabs ();
IMPORT int fat16ClustValueGet ();
IMPORT int fat16ClustValueSet ();
IMPORT int fat16Debug;
IMPORT int fat16VolMount ();
IMPORT int fatClugFac;
IMPORT int fchmod ();
IMPORT int fclose ();
IMPORT int fcntl ();
IMPORT int fcntl_dup ();
IMPORT int fd0;
IMPORT int fd1;
IMPORT int fd2;
IMPORT int fd3;
IMPORT int fdClass;
IMPORT int fdInvalidDrv;
IMPORT int fdatasync ();
IMPORT int fdopen ();
IMPORT int fdprintf ();
IMPORT int feof ();
IMPORT int ferror ();
IMPORT int fflush ();
IMPORT int ffs32Lsb ();
IMPORT int ffs32Msb ();
IMPORT int ffs64Lsb ();
IMPORT int ffs64Msb ();
IMPORT int ffsLsb ();
IMPORT int ffsMsb ();
IMPORT int fgetc ();
IMPORT int fgetpos ();
IMPORT int fgets ();
IMPORT int fieldSzIncludeSign;
IMPORT int file_idx_dosfs;
IMPORT int fileno ();
IMPORT int fioBaseLibInit ();
IMPORT int fioBufPrint ();
IMPORT int fioBufPut ();
IMPORT int fioFltInstall ();
IMPORT int fioFormatV ();
IMPORT int fioLibInit ();
IMPORT int fioRdString ();
IMPORT int fioRead ();
IMPORT int fioScanV ();
IMPORT int fioSnBufPut ();
IMPORT int flAddLongToFarPointer ();
IMPORT int flBufferOf ();
IMPORT int flCall ();
IMPORT int flCrc16 ();
IMPORT int flCreateMutex ();
IMPORT int flCurrentDate ();
IMPORT int flCurrentTime ();
IMPORT int flDelayLoop ();
IMPORT int flDelayMsecs ();
IMPORT int flDontNeedVcc ();
IMPORT int flDontNeedVpp ();
IMPORT int flFileSysSectorStart;
IMPORT int flFitInSocketWindow ();
IMPORT int flFormat ();
IMPORT int flFreeMutex ();
IMPORT int flGetMappingContext ();
IMPORT int flGetVolume ();
IMPORT int flIdentifyFlash ();
IMPORT int flIdentifyRegister ();
IMPORT int flInit ();
IMPORT int flInitIdentifyTable ();
IMPORT int flInitSocket ();
IMPORT int flInitSockets ();
IMPORT int flInstallTimer ();
IMPORT int flIntelIdentify ();
IMPORT int flIntelSize ();
IMPORT int flIntervalRoutine ();
IMPORT int flMap ();
IMPORT int flMediaCheck ();
IMPORT int flMount ();
IMPORT int flMsecCounter;
IMPORT int flNeedVcc ();
IMPORT int flNeedVpp ();
IMPORT int flPollSemId;
IMPORT int flPollTask ();
IMPORT int flRandByte ();
IMPORT int flRegisterComponents ();
IMPORT int flResetCardChanged ();
IMPORT int flSetPowerOnCallback ();
IMPORT int flSetWindowBusWidth ();
IMPORT int flSetWindowSize ();
IMPORT int flSetWindowSpeed ();
IMPORT int flSocketNoOf ();
IMPORT int flSocketOf ();
IMPORT int flSocketSetBusy ();
IMPORT int flSysfunInit ();
IMPORT int flTakeMutex ();
IMPORT int flWriteProtected ();
IMPORT int floatInit ();
IMPORT int floor ();
IMPORT int fmQspiResources;
IMPORT int fmSdmmcResources2_dosFS;
IMPORT int fmSdmmcResources_dosFS;
IMPORT int fmSpi0Resources;
IMPORT int fmSpi1Resources;
IMPORT int fmcp ();
IMPORT int fmod ();
IMPORT int fmprintf ();
IMPORT int fmqlDebugWrite ();
IMPORT int fmqlDebugWrite2 ();
IMPORT int fmqlMiiPhyFuncInit ();
IMPORT int fmqlMiiPhyRead;
IMPORT int fmqlMiiPhyShow;
IMPORT int fmqlMiiPhyWrite;
IMPORT int fmqlPhyRead ();
IMPORT int fmqlPhyWrite ();
IMPORT int fmqlSlcrRead ();
IMPORT int fmqlSlcrWrite ();
IMPORT int fmql_16550Pollprintf ();
IMPORT int fmshSdhcCtrl_BusWidthSetup ();
IMPORT int fmshSdhcCtrl_CardInsertSts ();
IMPORT int fmshSdhcCtrl_CardWpCheck ();
IMPORT int fmshSdhcCtrl_CmdIssue ();
IMPORT int fmshSdhcCtrl_CmdIssuePoll ();
IMPORT int fmshSdhcCtrl_CmdPrepare ();
IMPORT int fmshSdhcCtrl_DevControl ();
IMPORT int fmshSdhcCtrl_Get_BusWidth ();
IMPORT int fmshSdhcCtrl_Init ();
IMPORT int fmshSdhcCtrl_InstConnect ();
IMPORT int fmshSdhcCtrl_InstInit ();
IMPORT int fmshSdhcCtrl_InstInit2 ();
IMPORT int fmshSdhcCtrl_InterruptInfo ();
IMPORT int fmshSdhcCtrl_Isr ();
IMPORT int fmshSdhcCtrl_Monitor ();
IMPORT int fmshSdhcCtrl_PioRead ();
IMPORT int fmshSdhcCtrl_PioWrite ();
IMPORT int fmshSdhcCtrl_PollIntsts ();
IMPORT int fmshSdhcCtrl_ReadFifo ();
IMPORT int fmshSdhcCtrl_ResetFifo ();
IMPORT int fmshSdhcCtrl_SendCmd ();
IMPORT int fmshSdhcCtrl_SpecInfoGet ();
IMPORT int fmshSdhcCtrl_WriteFifo ();
IMPORT int fmshSdhcFuncs;
IMPORT int fmshSdhcPlbRegistration;
IMPORT int fmshSdhcRegister ();
IMPORT int fmshSdhc_ClkFreqSetup ();
IMPORT int fmshSdhc_CmdIssue ();
IMPORT int fmshSdhc_Get_Bitmode ();
IMPORT int fmshSdhc_VddSetup ();
IMPORT int fopen ();
IMPORT int formatFTL ();
IMPORT int fpArmModules;
IMPORT int fpTypeGet ();
IMPORT int fpathconf ();
IMPORT int fppArchInit ();
IMPORT int fppArchTaskCreateInit ();
IMPORT int fppCtxShow ();
IMPORT int fppCtxToRegs ();
IMPORT int fppProbe ();
IMPORT int fppRegListShow ();
IMPORT int fppRegsToCtx ();
IMPORT int fppRestore ();
IMPORT int fppSave ();
IMPORT int fprintf ();
IMPORT int fputc ();
IMPORT int fputs ();
IMPORT int fread ();
IMPORT int free ();
IMPORT int free_Bigints ();
IMPORT int freeifaddrs ();
IMPORT int freopen ();
IMPORT int frexp ();
IMPORT int fromUNAL ();
IMPORT int fromUNALLONG ();
IMPORT int fsEventUtilLibInit ();
IMPORT int fsMonitorInit ();
IMPORT int fsPathAddedEventRaise ();
IMPORT int fsPathAddedEventSetup ();
IMPORT int fsWaitForPath ();
IMPORT int fscanf ();
IMPORT int fseek ();
IMPORT int fsetpos ();
IMPORT int fsmGetDriver ();
IMPORT int fsmGetVolume ();
IMPORT int fsmInitialized;
IMPORT int fsmNameInstall ();
IMPORT int fsmNameMap ();
IMPORT int fsmNameUninstall ();
IMPORT int fsmProbeInstall ();
IMPORT int fsmProbeUninstall ();
IMPORT int fsmUnmountHookAdd ();
IMPORT int fsmUnmountHookDelete ();
IMPORT int fsmUnmountHookRun ();
IMPORT int fstat ();
IMPORT int fstatfs ();
IMPORT int fstatfs64 ();
IMPORT int fsync ();
IMPORT int ftell ();
IMPORT int ftpCommand ();
IMPORT int ftpCommandEnhanced ();
IMPORT int ftpDataConnGet ();
IMPORT int ftpDataConnInit ();
IMPORT int ftpDataConnInitPassiveMode ();
IMPORT int ftpHookup ();
IMPORT int ftpLibDebugOptionsSet ();
IMPORT int ftpLibInit ();
IMPORT int ftpLogin ();
IMPORT int ftpLs ();
IMPORT int ftpReplyGet ();
IMPORT int ftpReplyGetEnhanced ();
IMPORT int ftpReplyTimeout;
IMPORT int ftpTransientConfigGet ();
IMPORT int ftpTransientConfigSet ();
IMPORT int ftpTransientFatalInstall ();
IMPORT int ftpVerbose;
IMPORT int ftpXfer ();
IMPORT int ftplDebug;
IMPORT int ftplPasvModeDisable;
IMPORT int ftplTransientMaxRetryCount;
IMPORT int ftplTransientRetryInterval;
IMPORT int funcXbdBlkCacheAttach;
IMPORT int funcXbdBlkCacheDetach;
IMPORT int funcXbdBlkCacheStrategy;
IMPORT int fwrite ();
IMPORT int gDMA_BlockNum;
IMPORT int gDMA_BlockSize;
IMPORT int gDMA_XferType;
IMPORT int gSdmmc_Resp_Len_Type;
IMPORT int g_1key_pressed;
IMPORT int g_2key_pressed;
IMPORT int g_DMA_dmac;
IMPORT int g_DMA_instance;
IMPORT int g_DMA_param;
IMPORT int g_SDMMC;
IMPORT int g_SDMMC_dataParam;
IMPORT int g_SDMMC_instance;
IMPORT int g_config_conn_q;
IMPORT int g_config_mutex;
IMPORT int g_config_task_manager_tid;
IMPORT int g_conn_manager_tid;
IMPORT int g_counter1;
IMPORT int g_data_conn_q;
IMPORT int g_gpio_poll_init_flag;
IMPORT int g_irq_name_no;
IMPORT int g_pBuf8;
IMPORT int g_pBuf8_2;
IMPORT int g_pDevC;
IMPORT int g_pDma;
IMPORT int g_pGpio;
IMPORT int g_pGtc;
IMPORT int g_pQspi0;
IMPORT int g_pQspi1;
IMPORT int g_pSpi0;
IMPORT int g_pSpi1;
IMPORT int g_pUart0;
IMPORT int g_pUart1;
IMPORT int g_realtime_scheduler_tid;
IMPORT int g_sd_blk_num;
IMPORT int g_show_flag;
IMPORT int g_system_config;
IMPORT int g_test_com1;
IMPORT int g_test_qspi2;
IMPORT int g_test_sd;
IMPORT int g_test_sdmmc;
IMPORT int g_test_sdmmc0;
IMPORT int g_test_sdmmc1;
IMPORT int g_test_spi2;
IMPORT int g_test_uart1;
IMPORT int g_uart2_test;
IMPORT int g_uboot_ipAddr;
IMPORT int g_udp_search_tid;
IMPORT int g_vxInit_Qspi_ok2;
IMPORT int gcrt ();
IMPORT int gdir ();
IMPORT int genPhyDevRegistration;
IMPORT int genPhyMdio0Resources;
IMPORT int genPhyMdio1Resources;
IMPORT int genPhyRegister ();
IMPORT int getHiddenSectorsFromDPT ();
IMPORT int getOptServ ();
IMPORT int getPSMessageInfo ();
IMPORT int getSymNames ();
IMPORT int get_HARD_OSC_HZ ();
IMPORT int get_current_time ();
IMPORT int get_gtc_time ();
IMPORT int get_phyaddr_by_unit ();
IMPORT int get_sd_blk_num ();
IMPORT int get_unit_by_phyaddr ();
IMPORT int getc ();
IMPORT int getchar ();
IMPORT int getcwd ();
IMPORT int getenv ();
IMPORT int getenv_s ();
IMPORT int gethostname ();
IMPORT int getifaddrs ();
IMPORT int getlhostbyaddr ();
IMPORT int getlhostbyname ();
IMPORT int getopt ();
IMPORT int getoptInit ();
IMPORT int getopt_r ();
IMPORT int getpeername ();
IMPORT int getpid ();
IMPORT int gets ();
IMPORT int getsockname ();
IMPORT int getsockopt ();
IMPORT int gettimeofday ();
IMPORT int getw ();
IMPORT int getwd ();
IMPORT int gicCpu;
IMPORT int gicInputs;
IMPORT int gicPriority;
IMPORT int gicTrigger;
IMPORT int gic_show ();
IMPORT int gic_show2 ();
IMPORT int gic_show_all ();
IMPORT int globalNoStackFill;
IMPORT int globalRAMPgPoolId;
IMPORT int global_timer_disable ();
IMPORT int global_timer_enable ();
IMPORT int gmac0_info_show ();
IMPORT int gmac0_read ();
IMPORT int gmac0_write ();
IMPORT int gmac1_info_show ();
IMPORT int gmac1_read ();
IMPORT int gmac_reg_show ();
IMPORT int gmtime ();
IMPORT int gmtime_r ();
IMPORT int gop ();
IMPORT int gopherHookAdd ();
IMPORT int gopherWriteChar ();
IMPORT int gopherWriteScalar ();
IMPORT int gpioBank;
IMPORT int gpioCtrl_Clear_Irq ();
IMPORT int gpioCtrl_Disable_BothEdgeIrq ();
IMPORT int gpioCtrl_Disable_Debounce ();
IMPORT int gpioCtrl_Disable_Irq ();
IMPORT int gpioCtrl_Disable_Sync ();
IMPORT int gpioCtrl_Enable_BothEdgeIrq ();
IMPORT int gpioCtrl_Enable_Debounce ();
IMPORT int gpioCtrl_Enable_Irq ();
IMPORT int gpioCtrl_Enable_Sync ();
IMPORT int gpioCtrl_Get_ActiveIrq ();
IMPORT int gpioCtrl_Get_BitDirection ();
IMPORT int gpioCtrl_Get_BothEdgeIrq ();
IMPORT int gpioCtrl_Get_ExtPort ();
IMPORT int gpioCtrl_Get_IdCode ();
IMPORT int gpioCtrl_Get_Irq ();
IMPORT int gpioCtrl_Get_IrqMask ();
IMPORT int gpioCtrl_Get_IrqPolar ();
IMPORT int gpioCtrl_Get_IrqType ();
IMPORT int gpioCtrl_Get_PortBit_Chk ();
IMPORT int gpioCtrl_Get_PortDirection ();
IMPORT int gpioCtrl_Get_VerIdCode ();
IMPORT int gpioCtrl_Mask_Irq ();
IMPORT int gpioCtrl_Rd_CfgReg32 ();
IMPORT int gpioCtrl_Read_Data ();
IMPORT int gpioCtrl_Set_BitDirection ();
IMPORT int gpioCtrl_Set_IrqPolar ();
IMPORT int gpioCtrl_Set_IrqTrigger ();
IMPORT int gpioCtrl_Set_IrqType ();
IMPORT int gpioCtrl_Set_PortBit ();
IMPORT int gpioCtrl_Set_PortDirection ();
IMPORT int gpioCtrl_Wr_CfgReg32 ();
IMPORT int gpioCtrl_Write_Data ();
IMPORT int gpioCtrl_isEnable_Debounce ();
IMPORT int gpioCtrl_isEnable_Irq ();
IMPORT int gpioCtrl_isMask_Irq ();
IMPORT int gpioCtrl_isSync ();
IMPORT int gpioCtrl_unMask_Irq ();
IMPORT int gpioIsr_callbk ();
IMPORT int gpioSlcr_Mio_Init ();
IMPORT int gpio_Irq_Enable ();
IMPORT int gpio_Poll_Enable ();
IMPORT int gpio_attach_irq ();
IMPORT int gpio_get_input_val ();
IMPORT int gpio_get_key_by_pin ();
IMPORT int gpio_get_pins_by_bank ();
IMPORT int gpio_irq_init ();
IMPORT int gpio_poll_init ();
IMPORT int gpio_set_HIGH ();
IMPORT int gpio_set_LOW ();
IMPORT int gpio_set_input ();
IMPORT int gpio_set_output ();
IMPORT int gpio_set_output_val ();
IMPORT int gptAdd ();
IMPORT int gptCheckMap ();
IMPORT int gptCoreDebug;
IMPORT int gptCreate ();
IMPORT int gptCreatePartDev ();
IMPORT int gptDestroy ();
IMPORT int gptExtParse ();
IMPORT int gptMapDebug;
IMPORT int gptMapWrite ();
IMPORT int gptMbrParse ();
IMPORT int gptMigrate ();
IMPORT int gptParse ();
IMPORT int gptPartsGet ();
IMPORT int gptRead ();
IMPORT int gptRecover ();
IMPORT int gptRemove ();
IMPORT int gptShowMap ();
IMPORT int gptShowMbr ();
IMPORT int gptShowPartHdr ();
IMPORT int gptShowPartTable ();
IMPORT int grd ();
IMPORT int gtcCtrl_Disable_Counter ();
IMPORT int gtcCtrl_Enable_Counter ();
IMPORT int gtcCtrl_Get_CounterH ();
IMPORT int gtcCtrl_Get_CounterL ();
IMPORT int gtcCtrl_Halt_Counter ();
IMPORT int gtcCtrl_Rd_CfgReg32 ();
IMPORT int gtcCtrl_Wr_CfgReg32 ();
IMPORT int gtcCtrl_isStop ();
IMPORT int gtcTimerDevResources;
IMPORT int gtc_Get_Time ();
IMPORT int gtc_enable ();
IMPORT int gwr ();
IMPORT int h ();
IMPORT int handleContextGet ();
IMPORT int handleContextGetBase ();
IMPORT int handleContextSet ();
IMPORT int handleInit ();
IMPORT int handleShow ();
IMPORT int handleShowConnect ();
IMPORT int handleTerminate ();
IMPORT int handleTypeGet ();
IMPORT int handleVerify ();
IMPORT int handle_command ();
IMPORT int hardWareInterFaceBusInit ();
IMPORT int hardWareInterFaceInit ();
IMPORT int hashFuncIterScale ();
IMPORT int hashFuncModulo ();
IMPORT int hashFuncMultiply ();
IMPORT int hashKeyCmp ();
IMPORT int hashKeyStrCmp ();
IMPORT int hashLibInit ();
IMPORT int hashTblCreate ();
IMPORT int hashTblDelete ();
IMPORT int hashTblDestroy ();
IMPORT int hashTblEach ();
IMPORT int hashTblFind ();
IMPORT int hashTblInit ();
IMPORT int hashTblPut ();
IMPORT int hashTblRemove ();
IMPORT int hashTblTerminate ();
IMPORT int hcfDeviceGet ();
IMPORT int hcfDeviceList;
IMPORT int hcfDeviceNum;
IMPORT int hdprintf ();
IMPORT int help ();
IMPORT int hookAddToHead ();
IMPORT int hookAddToTail ();
IMPORT int hookDelete ();
IMPORT int hookFind ();
IMPORT int hookShow ();
IMPORT int hookTblAddToHead ();
IMPORT int hookTblAddToTail ();
IMPORT int hookTblDelete ();
IMPORT int hookTblFind ();
IMPORT int hookTblInit ();
IMPORT int hookTblShow ();
IMPORT int hookTblUpdatersUnpend ();
IMPORT int hostAdd ();
IMPORT int hostDelete ();
IMPORT int hostGetByAddr ();
IMPORT int hostGetByName ();
IMPORT int hostInitFlag;
IMPORT int hostList;
IMPORT int hostListSem;
IMPORT int hostTblInit ();
IMPORT int hostTblSearchByAddr ();
IMPORT int hostTblSearchByAddr2 ();
IMPORT int hostTblSearchByName ();
IMPORT int hostTblSearchByName2 ();
IMPORT int hostTblSetup ();
IMPORT int hostentAlloc ();
IMPORT int hostentFree ();
IMPORT int hostnameSetup ();
IMPORT int hrfsDiskFormat ();
IMPORT int hrfsFmtRtn;
IMPORT int hwMemAlloc ();
IMPORT int hwMemFree ();
IMPORT int hwMemLibInit ();
IMPORT int hwMemPool;
IMPORT int hwMemPoolCreate ();
IMPORT int i ();
IMPORT int iam ();
IMPORT int ifconfig ();
IMPORT int in_netof ();
IMPORT int index ();
IMPORT int inet_addr ();
IMPORT int inet_aton ();
IMPORT int inet_lnaof ();
IMPORT int inet_makeaddr ();
IMPORT int inet_makeaddr_b ();
IMPORT int inet_netof ();
IMPORT int inet_netof_string ();
IMPORT int inet_network ();
IMPORT int inet_ntoa ();
IMPORT int inet_ntoa_b ();
IMPORT int inet_ntop ();
IMPORT int inet_pton ();
IMPORT int initApplLogger ();
IMPORT int init_usart ();
IMPORT int instParamModify_desc;
IMPORT int intArchConnect ();
IMPORT int intArchDisconnect ();
IMPORT int intCnt;
IMPORT int intConnect ();
IMPORT int intContext ();
IMPORT int intCount ();
IMPORT int intCpuEnable ();
IMPORT int intCpuLock ();
IMPORT int intCpuMicroLock ();
IMPORT int intCpuMicroUnlock ();
IMPORT int intCpuUnlock ();
IMPORT int intCtlrChainISR ();
IMPORT int intCtlrDevID;
IMPORT int intCtlrHwConfGet ();
IMPORT int intCtlrISRAdd ();
IMPORT int intCtlrISRDisable ();
IMPORT int intCtlrISREnable ();
IMPORT int intCtlrISRRemove ();
IMPORT int intCtlrPinFind ();
IMPORT int intCtlrStrayISR ();
IMPORT int intCtlrTableArgGet ();
IMPORT int intCtlrTableCreate ();
IMPORT int intCtlrTableFlagsGet ();
IMPORT int intCtlrTableFlagsSet ();
IMPORT int intCtlrTableIsrGet ();
IMPORT int intCtlrTableUserSet ();
IMPORT int intDemuxErrorCount;
IMPORT int intDisable ();
IMPORT int intDisconnect ();
IMPORT int intEnable ();
IMPORT int intEnt ();
IMPORT int intExit ();
IMPORT int intIFLock ();
IMPORT int intIFUnlock ();
IMPORT int intIntRtnNonPreempt ();
IMPORT int intIntRtnPreempt ();
IMPORT int intLevelSet ();
IMPORT int intLibInit ();
IMPORT int intLock ();
IMPORT int intLockLevelGet ();
IMPORT int intLockLevelSet ();
IMPORT int intNestingLevel;
IMPORT int intRegsLock ();
IMPORT int intRegsUnlock ();
IMPORT int intRestrict ();
IMPORT int intUninitVecSet ();
IMPORT int intUnlock ();
IMPORT int intVBRSet ();
IMPORT int intVecBaseGet ();
IMPORT int intVecBaseSet ();
IMPORT int intVecTableWriteProtect ();
IMPORT int ioDefPath;
IMPORT int ioDefPathCat ();
IMPORT int ioDefPathGet ();
IMPORT int ioDefPathSet ();
IMPORT int ioDefPathValidate ();
IMPORT int ioFullFileNameGet ();
IMPORT int ioGlobalStdGet ();
IMPORT int ioGlobalStdSet ();
IMPORT int ioHelp ();
IMPORT int ioMaxLinkLevels;
IMPORT int ioPxCreateOrOpen ();
IMPORT int ioTaskStdGet ();
IMPORT int ioTaskStdSet ();
IMPORT int ioctl ();
IMPORT int iosClose ();
IMPORT int iosCreate ();
IMPORT int iosDelete ();
IMPORT int iosDevAdd ();
IMPORT int iosDevCheck ();
IMPORT int iosDevDelCallback ();
IMPORT int iosDevDelDrv ();
IMPORT int iosDevDelete ();
IMPORT int iosDevFind ();
IMPORT int iosDevMatch ();
IMPORT int iosDevReplace ();
IMPORT int iosDevReplaceExt ();
IMPORT int iosDevResume ();
IMPORT int iosDevShow ();
IMPORT int iosDevSuspend ();
IMPORT int iosDrvInit ();
IMPORT int iosDrvInstall ();
IMPORT int iosDrvIoctl ();
IMPORT int iosDrvIoctlMemValSet ();
IMPORT int iosDrvRemove ();
IMPORT int iosDrvShow ();
IMPORT int iosDvList;
IMPORT int iosFdDevFind ();
IMPORT int iosFdDrvValue ();
IMPORT int iosFdEntryGet ();
IMPORT int iosFdEntryIoctl ();
IMPORT int iosFdEntryPool;
IMPORT int iosFdEntryReturn ();
IMPORT int iosFdEntrySet ();
IMPORT int iosFdFree ();
IMPORT int iosFdMap ();
IMPORT int iosFdMaxFiles ();
IMPORT int iosFdNew ();
IMPORT int iosFdSet ();
IMPORT int iosFdShow ();
IMPORT int iosFdTable;
IMPORT int iosFdTableLock ();
IMPORT int iosFdTableUnlock ();
IMPORT int iosFdValue ();
IMPORT int iosInit ();
IMPORT int iosIoctl ();
IMPORT int iosIoctlInternal ();
IMPORT int iosLibInitialized;
IMPORT int iosLock ();
IMPORT int iosMaxDrivers;
IMPORT int iosMaxFiles;
IMPORT int iosNextDevGet ();
IMPORT int iosOpen ();
IMPORT int iosPathFdEntryIoctl ();
IMPORT int iosPathLibInit ();
IMPORT int iosPse52Mode;
IMPORT int iosPxLibInit ();
IMPORT int iosPxLibInitialized;
IMPORT int iosRead ();
IMPORT int iosRmvFdEntrySet ();
IMPORT int iosRmvLibInit ();
IMPORT int iosRtpDefPathGet ();
IMPORT int iosRtpDefPathSet ();
IMPORT int iosRtpDevCloseOrInvalidate ();
IMPORT int iosRtpFdEntryMap ();
IMPORT int iosRtpFdInvalid ();
IMPORT int iosRtpFdReserve ();
IMPORT int iosRtpFdReserveCntrl ();
IMPORT int iosRtpFdSetup ();
IMPORT int iosRtpFdShow ();
IMPORT int iosRtpFdTableGet ();
IMPORT int iosRtpFdTableSizeGet ();
IMPORT int iosRtpFdTblEntryGet ();
IMPORT int iosRtpFdUnmap2 ();
IMPORT int iosRtpIoTableSizeGet ();
IMPORT int iosRtpIoTableSizeSet ();
IMPORT int iosRtpLibInit ();
IMPORT int iosRtpTableSizeSet ();
IMPORT int iosShowInit ();
IMPORT int iosTaskCwdGet ();
IMPORT int iosTaskCwdSet ();
IMPORT int iosUnlock ();
IMPORT int iosWrite ();
IMPORT int ip_inaddr_any;
IMPORT int ipcomNetTask ();
IMPORT int ipcom_accept ();
IMPORT int ipcom_accept_usr ();
IMPORT int ipcom_asctime_r_vxworks ();
IMPORT int ipcom_atomic_add ();
IMPORT int ipcom_atomic_add_and_return ();
IMPORT int ipcom_atomic_dec ();
IMPORT int ipcom_atomic_get ();
IMPORT int ipcom_atomic_inc ();
IMPORT int ipcom_atomic_ptr_cas ();
IMPORT int ipcom_atomic_set ();
IMPORT int ipcom_atomic_sub ();
IMPORT int ipcom_atomic_sub_and_return ();
IMPORT int ipcom_auth_chap_login ();
IMPORT int ipcom_auth_default_hash_rtn ();
IMPORT int ipcom_auth_hash ();
IMPORT int ipcom_auth_hash_get ();
IMPORT int ipcom_auth_hash_rtn_install ();
IMPORT int ipcom_auth_login ();
IMPORT int ipcom_auth_old_and_unsecure_hash_rtn ();
IMPORT int ipcom_auth_useradd ();
IMPORT int ipcom_auth_useradd_hash ();
IMPORT int ipcom_auth_userdel ();
IMPORT int ipcom_auth_userget ();
IMPORT int ipcom_auth_userlist ();
IMPORT int ipcom_bind ();
IMPORT int ipcom_bind_usr ();
IMPORT int ipcom_block_create ();
IMPORT int ipcom_block_delete ();
IMPORT int ipcom_block_post ();
IMPORT int ipcom_block_reader_create ();
IMPORT int ipcom_block_wait ();
IMPORT int ipcom_cache_line_size ();
IMPORT int ipcom_calloc ();
IMPORT int ipcom_chdir ();
IMPORT int ipcom_clearenv ();
IMPORT int ipcom_closedir ();
IMPORT int ipcom_closelog ();
IMPORT int ipcom_cmd_cat ();
IMPORT int ipcom_cmd_cd ();
IMPORT int ipcom_cmd_cp ();
IMPORT int ipcom_cmd_date ();
IMPORT int ipcom_cmd_getenv ();
IMPORT int ipcom_cmd_if_caps_to_str ();
IMPORT int ipcom_cmd_if_flags_to_str ();
IMPORT int ipcom_cmd_key_to_str ();
IMPORT int ipcom_cmd_ls ();
IMPORT int ipcom_cmd_mkdir ();
IMPORT int ipcom_cmd_mv ();
IMPORT int ipcom_cmd_pwd ();
IMPORT int ipcom_cmd_rm ();
IMPORT int ipcom_cmd_rmdir ();
IMPORT int ipcom_cmd_setenv ();
IMPORT int ipcom_cmd_sockaddr_to_str ();
IMPORT int ipcom_cmd_str_to_key ();
IMPORT int ipcom_cmd_str_to_key2 ();
IMPORT int ipcom_cmd_time ();
IMPORT int ipcom_cmd_uuencode ();
IMPORT int ipcom_cmsg_nxthdr ();
IMPORT int ipcom_conf_max_link_hdr_size;
IMPORT int ipcom_conf_pkt_pool_buffer_alignment;
IMPORT int ipcom_conf_pkt_pool_buffer_extra_space;
IMPORT int ipcom_configure ();
IMPORT int ipcom_configure_reserved_cpus ();
IMPORT int ipcom_connect ();
IMPORT int ipcom_connect_usr ();
IMPORT int ipcom_cpu_is_online ();
IMPORT int ipcom_cpu_reserved_alloc ();
IMPORT int ipcom_cpu_reserved_free ();
IMPORT int ipcom_create ();
IMPORT int ipcom_ctime_r_vxworks ();
IMPORT int ipcom_dns;
IMPORT int ipcom_dns_init_ok;
IMPORT int ipcom_drv_eth_create ();
IMPORT int ipcom_drv_eth_exit ();
IMPORT int ipcom_drv_eth_filter_add_mcast_addr ();
IMPORT int ipcom_drv_eth_filter_exit ();
IMPORT int ipcom_drv_eth_filter_init ();
IMPORT int ipcom_drv_eth_filter_remove_mcast_addr ();
IMPORT int ipcom_drv_eth_init ();
IMPORT int ipcom_drv_eth_ip_attach ();
IMPORT int ipcom_errno_get ();
IMPORT int ipcom_errno_set ();
IMPORT int ipcom_fclose ();
IMPORT int ipcom_fdopen ();
IMPORT int ipcom_feof ();
IMPORT int ipcom_ferror ();
IMPORT int ipcom_fflush ();
IMPORT int ipcom_fileclose ();
IMPORT int ipcom_fileno ();
IMPORT int ipcom_fileopen ();
IMPORT int ipcom_fileread ();
IMPORT int ipcom_filewrite ();
IMPORT int ipcom_fopen ();
IMPORT int ipcom_forwarder_ipsec_sa_cache_size;
IMPORT int ipcom_forwarder_ipsec_single_output_queue;
IMPORT int ipcom_fread ();
IMPORT int ipcom_free ();
IMPORT int ipcom_freeaddrinfo ();
IMPORT int ipcom_freeaddrinfo2 ();
IMPORT int ipcom_freeifaddrs ();
IMPORT int ipcom_fseek ();
IMPORT int ipcom_fstat ();
IMPORT int ipcom_ftell ();
IMPORT int ipcom_fwrite ();
IMPORT int ipcom_get_cpuid ();
IMPORT int ipcom_get_ip_if_name ();
IMPORT int ipcom_get_mux_dev_name ();
IMPORT int ipcom_get_start_shell_ptr ();
IMPORT int ipcom_get_true_cpuid ();
IMPORT int ipcom_getaddrinfo ();
IMPORT int ipcom_getaddrinfo2 ();
IMPORT int ipcom_getcwd ();
IMPORT int ipcom_getenv ();
IMPORT int ipcom_getenv_as_int ();
IMPORT int ipcom_gethostbyaddr ();
IMPORT int ipcom_gethostbyaddr_r ();
IMPORT int ipcom_gethostbyaddrlocal ();
IMPORT int ipcom_gethostbyname ();
IMPORT int ipcom_gethostbyname_r ();
IMPORT int ipcom_gethostbynamelocal ();
IMPORT int ipcom_getifaddrs ();
IMPORT int ipcom_getlogmask_on ();
IMPORT int ipcom_getnameinfo ();
IMPORT int ipcom_getnameinfo2 ();
IMPORT int ipcom_getopt ();
IMPORT int ipcom_getopt_clear ();
IMPORT int ipcom_getopt_clear_r ();
IMPORT int ipcom_getopt_data;
IMPORT int ipcom_getopt_r ();
IMPORT int ipcom_getpeername ();
IMPORT int ipcom_getpeername_usr ();
IMPORT int ipcom_getpid ();
IMPORT int ipcom_getprotobyname ();
IMPORT int ipcom_getprotobynumber ();
IMPORT int ipcom_getservbyname ();
IMPORT int ipcom_getservbyport ();
IMPORT int ipcom_getsockaddrbyaddr ();
IMPORT int ipcom_getsockaddrbyaddrname ();
IMPORT int ipcom_getsockname ();
IMPORT int ipcom_getsockname_usr ();
IMPORT int ipcom_getsockopt ();
IMPORT int ipcom_getsockopt_usr ();
IMPORT int ipcom_gettimeofday ();
IMPORT int ipcom_h_errno;
IMPORT int ipcom_hash_add ();
IMPORT int ipcom_hash_delete ();
IMPORT int ipcom_hash_for_each ();
IMPORT int ipcom_hash_get ();
IMPORT int ipcom_hash_new ();
IMPORT int ipcom_hash_remove ();
IMPORT int ipcom_hash_update ();
IMPORT int ipcom_heap_sort ();
IMPORT int ipcom_if_attach ();
IMPORT int ipcom_if_attach_and_lock ();
IMPORT int ipcom_if_changelinkaddr ();
IMPORT int ipcom_if_changemtu ();
IMPORT int ipcom_if_changename ();
IMPORT int ipcom_if_detach ();
IMPORT int ipcom_if_free ();
IMPORT int ipcom_if_freenameindex ();
IMPORT int ipcom_if_indextoname ();
IMPORT int ipcom_if_malloc ();
IMPORT int ipcom_if_nameindex ();
IMPORT int ipcom_if_nametoindex ();
IMPORT int ipcom_if_nametonetif ();
IMPORT int ipcom_ima_stack_task ();
IMPORT int ipcom_in_checksum ();
IMPORT int ipcom_in_checksum_finish ();
IMPORT int ipcom_in_checksum_memcpy ();
IMPORT int ipcom_in_checksum_memcpy_asm ();
IMPORT int ipcom_in_checksum_pkt ();
IMPORT int ipcom_in_checksum_update ();
IMPORT int ipcom_in_checksum_update2_asm ();
IMPORT int ipcom_in_checksum_update_pkt ();
IMPORT int ipcom_inet_addr ();
IMPORT int ipcom_inet_aton ();
IMPORT int ipcom_inet_ntoa ();
IMPORT int ipcom_inet_ntop ();
IMPORT int ipcom_inet_pton ();
IMPORT int ipcom_init_config_vars ();
IMPORT int ipcom_initd ();
IMPORT int ipcom_interrupt_disable ();
IMPORT int ipcom_interrupt_enable ();
IMPORT int ipcom_ipc_close ();
IMPORT int ipcom_ipc_free ();
IMPORT int ipcom_ipc_install ();
IMPORT int ipcom_ipc_isopen ();
IMPORT int ipcom_ipc_malloc ();
IMPORT int ipcom_ipc_open ();
IMPORT int ipcom_ipc_receive ();
IMPORT int ipcom_ipc_send ();
IMPORT int ipcom_ipc_size ();
IMPORT int ipcom_ipc_uninstall ();
IMPORT int ipcom_ipd_datamsg ();
IMPORT int ipcom_ipd_exit ();
IMPORT int ipcom_ipd_init ();
IMPORT int ipcom_ipd_input ();
IMPORT int ipcom_ipd_input_process ();
IMPORT int ipcom_ipd_kill ();
IMPORT int ipcom_ipd_products;
IMPORT int ipcom_ipd_read ();
IMPORT int ipcom_ipd_reconfigure ();
IMPORT int ipcom_ipd_send ();
IMPORT int ipcom_ipd_sendmsg ();
IMPORT int ipcom_ipd_start ();
IMPORT int ipcom_ipproto_name ();
IMPORT int ipcom_is_pid_valid ();
IMPORT int ipcom_is_stack_task ();
IMPORT int ipcom_job_queue_init ();
IMPORT int ipcom_job_queue_pipe_schedule ();
IMPORT int ipcom_job_queue_schedule ();
IMPORT int ipcom_job_queue_schedule_singleton ();
IMPORT int ipcom_job_queue_schedule_singleton_delayed ();
IMPORT int ipcom_job_queue_singleton_delete ();
IMPORT int ipcom_job_queue_singleton_new ();
IMPORT int ipcom_key_db_file_root;
IMPORT int ipcom_list_first ();
IMPORT int ipcom_list_init ();
IMPORT int ipcom_list_insert_after ();
IMPORT int ipcom_list_insert_before ();
IMPORT int ipcom_list_insert_first ();
IMPORT int ipcom_list_insert_last ();
IMPORT int ipcom_list_last ();
IMPORT int ipcom_list_next ();
IMPORT int ipcom_list_prev ();
IMPORT int ipcom_list_remove ();
IMPORT int ipcom_list_unlink_head ();
IMPORT int ipcom_listen ();
IMPORT int ipcom_listen_usr ();
IMPORT int ipcom_lseek ();
IMPORT int ipcom_malloc ();
IMPORT int ipcom_mask_to_prefixlen ();
IMPORT int ipcom_mb ();
IMPORT int ipcom_mcmd_ifconfig ();
IMPORT int ipcom_mcmd_route ();
IMPORT int ipcom_memory_pool_new ();
IMPORT int ipcom_microtime ();
IMPORT int ipcom_millisleep ();
IMPORT int ipcom_mipc_addr2offset ();
IMPORT int ipcom_mipc_offset2addr ();
IMPORT int ipcom_mkdir ();
IMPORT int ipcom_mutex_create ();
IMPORT int ipcom_mutex_delete ();
IMPORT int ipcom_mutex_lock ();
IMPORT int ipcom_mutex_unlock ();
IMPORT int ipcom_null_pool_create;
IMPORT int ipcom_num_configured_cpus ();
IMPORT int ipcom_num_online_cpus ();
IMPORT int ipcom_observer_notify ();
IMPORT int ipcom_once ();
IMPORT int ipcom_once_mutex;
IMPORT int ipcom_opendir ();
IMPORT int ipcom_openlog ();
IMPORT int ipcom_parse_argstr ();
IMPORT int ipcom_pipe_attr_init ();
IMPORT int ipcom_pipe_free ();
IMPORT int ipcom_pipe_generic_create ();
IMPORT int ipcom_pipe_job_queue_create ();
IMPORT int ipcom_pipe_lockless_create ();
IMPORT int ipcom_pipe_new ();
IMPORT int ipcom_pipe_register_type ();
IMPORT int ipcom_pipe_tv_zero;
IMPORT int ipcom_pkt_alloc_info ();
IMPORT int ipcom_pkt_copy_info ();
IMPORT int ipcom_pkt_create ();
IMPORT int ipcom_pkt_create_info ();
IMPORT int ipcom_pkt_free ();
IMPORT int ipcom_pkt_get_info ();
IMPORT int ipcom_pkt_get_info_and_size ();
IMPORT int ipcom_pkt_get_info_safe ();
IMPORT int ipcom_pkt_hdrspace ();
IMPORT int ipcom_pkt_input ();
IMPORT int ipcom_pkt_input_queue ();
IMPORT int ipcom_pkt_make_linear ();
IMPORT int ipcom_pkt_malloc ();
IMPORT int ipcom_pkt_output_done ();
IMPORT int ipcom_pkt_set_info ();
IMPORT int ipcom_pkt_sg_get_data ();
IMPORT int ipcom_pkt_trim_head ();
IMPORT int ipcom_pkt_trim_tail ();
IMPORT int ipcom_pktbuf_free ();
IMPORT int ipcom_port;
IMPORT int ipcom_port_pkt_hdr_extra_size;
IMPORT int ipcom_pqueue_delete ();
IMPORT int ipcom_pqueue_for_each ();
IMPORT int ipcom_pqueue_get ();
IMPORT int ipcom_pqueue_get_next ();
IMPORT int ipcom_pqueue_insert ();
IMPORT int ipcom_pqueue_new ();
IMPORT int ipcom_pqueue_nop_store_index ();
IMPORT int ipcom_pqueue_remove ();
IMPORT int ipcom_pqueue_remove_next ();
IMPORT int ipcom_pqueue_size ();
IMPORT int ipcom_preempt_disable ();
IMPORT int ipcom_preempt_enable ();
IMPORT int ipcom_priority_map;
IMPORT int ipcom_proc_acreate ();
IMPORT int ipcom_proc_attr_init ();
IMPORT int ipcom_proc_cpu_affinity_clr ();
IMPORT int ipcom_proc_cpu_affinity_get ();
IMPORT int ipcom_proc_cpu_affinity_set ();
IMPORT int ipcom_proc_cpu_affinity_set_all ();
IMPORT int ipcom_proc_create ();
IMPORT int ipcom_proc_exit ();
IMPORT int ipcom_proc_find ();
IMPORT int ipcom_proc_free ();
IMPORT int ipcom_proc_getprio ();
IMPORT int ipcom_proc_init ();
IMPORT int ipcom_proc_malloc ();
IMPORT int ipcom_proc_self ();
IMPORT int ipcom_proc_setprio ();
IMPORT int ipcom_proc_vr_get ();
IMPORT int ipcom_proc_vr_set ();
IMPORT int ipcom_proc_yield ();
IMPORT int ipcom_rand ();
IMPORT int ipcom_random ();
IMPORT int ipcom_random_init ();
IMPORT int ipcom_random_seed_state ();
IMPORT int ipcom_readdir ();
IMPORT int ipcom_realloc ();
IMPORT int ipcom_recv ();
IMPORT int ipcom_recv_usr ();
IMPORT int ipcom_recvfrom ();
IMPORT int ipcom_recvfrom_usr ();
IMPORT int ipcom_recvmsg ();
IMPORT int ipcom_recvmsg_usr ();
IMPORT int ipcom_register_dev_name_mapping ();
IMPORT int ipcom_rename ();
IMPORT int ipcom_rewind ();
IMPORT int ipcom_rmb ();
IMPORT int ipcom_rmdir ();
IMPORT int ipcom_route_add ();
IMPORT int ipcom_route_first_entry ();
IMPORT int ipcom_route_free_table ();
IMPORT int ipcom_route_init_subtree_mask ();
IMPORT int ipcom_route_key_cmp ();
IMPORT int ipcom_route_lookup ();
IMPORT int ipcom_route_new_table ();
IMPORT int ipcom_route_next_entry ();
IMPORT int ipcom_route_remove ();
IMPORT int ipcom_route_walk_tree ();
IMPORT int ipcom_route_walk_tree_backwards ();
IMPORT int ipcom_rtp_tcb_index_get_fd ();
IMPORT int ipcom_run_cmd ();
IMPORT int ipcom_sem_create ();
IMPORT int ipcom_sem_delete ();
IMPORT int ipcom_sem_flush ();
IMPORT int ipcom_sem_getvalue ();
IMPORT int ipcom_sem_interrupt_flush ();
IMPORT int ipcom_sem_interrupt_post ();
IMPORT int ipcom_sem_post ();
IMPORT int ipcom_sem_wait ();
IMPORT int ipcom_send ();
IMPORT int ipcom_send_usr ();
IMPORT int ipcom_sendmsg ();
IMPORT int ipcom_sendmsg_usr ();
IMPORT int ipcom_sendto ();
IMPORT int ipcom_sendto_usr ();
IMPORT int ipcom_set_add ();
IMPORT int ipcom_set_clone ();
IMPORT int ipcom_set_contains ();
IMPORT int ipcom_set_delete ();
IMPORT int ipcom_set_equal ();
IMPORT int ipcom_set_for_each ();
IMPORT int ipcom_set_intersection ();
IMPORT int ipcom_set_new ();
IMPORT int ipcom_set_remove ();
IMPORT int ipcom_set_remove_all ();
IMPORT int ipcom_set_start_shell_ptr ();
IMPORT int ipcom_set_subtract ();
IMPORT int ipcom_set_union ();
IMPORT int ipcom_setenv ();
IMPORT int ipcom_setenv_as_int ();
IMPORT int ipcom_setlogfile ();
IMPORT int ipcom_setlogmask_on ();
IMPORT int ipcom_setlogudp ();
IMPORT int ipcom_setsockopt ();
IMPORT int ipcom_setsockopt_usr ();
IMPORT int ipcom_settimeofday ();
IMPORT int ipcom_shell_add_cmd ();
IMPORT int ipcom_shell_cmd_head;
IMPORT int ipcom_shell_ctx_add ();
IMPORT int ipcom_shell_ctx_add_int ();
IMPORT int ipcom_shell_ctx_add_local_addr ();
IMPORT int ipcom_shell_ctx_add_peer_addr ();
IMPORT int ipcom_shell_ctx_add_user ();
IMPORT int ipcom_shell_ctx_free ();
IMPORT int ipcom_shell_ctx_get ();
IMPORT int ipcom_shell_ctx_get_clt_addr ();
IMPORT int ipcom_shell_ctx_get_int ();
IMPORT int ipcom_shell_ctx_get_peer_addr ();
IMPORT int ipcom_shell_ctx_get_user ();
IMPORT int ipcom_shell_ctx_new ();
IMPORT int ipcom_shell_find_cmd ();
IMPORT int ipcom_shell_find_cmd_hook;
IMPORT int ipcom_shell_fread ();
IMPORT int ipcom_shell_fwrite ();
IMPORT int ipcom_shell_remove_cmd ();
IMPORT int ipcom_shutdown ();
IMPORT int ipcom_shutdown_usr ();
IMPORT int ipcom_slab_add ();
IMPORT int ipcom_slab_alloc_from ();
IMPORT int ipcom_slab_alloc_try ();
IMPORT int ipcom_slab_free ();
IMPORT int ipcom_slab_get_objects_per_slab ();
IMPORT int ipcom_slab_memory_pool_list;
IMPORT int ipcom_slab_new ();
IMPORT int ipcom_slab_once;
IMPORT int ipcom_sleep ();
IMPORT int ipcom_sockaddr_to_prefixlen ();
IMPORT int ipcom_socket ();
IMPORT int ipcom_socket_usr ();
IMPORT int ipcom_socketclose ();
IMPORT int ipcom_socketclose_usr ();
IMPORT int ipcom_socketioctl ();
IMPORT int ipcom_socketioctl_usr ();
IMPORT int ipcom_socketread ();
IMPORT int ipcom_socketread_usr ();
IMPORT int ipcom_socketselect ();
IMPORT int ipcom_socketselect_usr ();
IMPORT int ipcom_socketwrite ();
IMPORT int ipcom_socketwrite_usr ();
IMPORT int ipcom_socketwritev ();
IMPORT int ipcom_socketwritev_usr ();
IMPORT int ipcom_spinlock_create ();
IMPORT int ipcom_spinlock_delete ();
IMPORT int ipcom_spinlock_lock ();
IMPORT int ipcom_spinlock_unlock ();
IMPORT int ipcom_srand ();
IMPORT int ipcom_srandom ();
IMPORT int ipcom_stackd_init ();
IMPORT int ipcom_start ();
IMPORT int ipcom_start_shell ();
IMPORT int ipcom_start_shell_native ();
IMPORT int ipcom_start_shell_ptr;
IMPORT int ipcom_stat ();
IMPORT int ipcom_stderr ();
IMPORT int ipcom_stdin ();
IMPORT int ipcom_stdio_set_echo ();
IMPORT int ipcom_stdout ();
IMPORT int ipcom_str_in_list ();
IMPORT int ipcom_strcasecmp ();
IMPORT int ipcom_strerror ();
IMPORT int ipcom_strerror_r ();
IMPORT int ipcom_strncasecmp ();
IMPORT int ipcom_sys_free;
IMPORT int ipcom_sys_malloc;
IMPORT int ipcom_sysctl ();
IMPORT int ipcom_syslog ();
IMPORT int ipcom_syslog_facility_names;
IMPORT int ipcom_syslog_printf ();
IMPORT int ipcom_syslog_priority_names;
IMPORT int ipcom_syslogd_init ();
IMPORT int ipcom_sysvar_add_observer ();
IMPORT int ipcom_sysvar_ext_setv ();
IMPORT int ipcom_sysvar_for_each ();
IMPORT int ipcom_sysvar_get ();
IMPORT int ipcom_sysvar_get0 ();
IMPORT int ipcom_sysvar_get_as_int ();
IMPORT int ipcom_sysvar_get_as_int0 ();
IMPORT int ipcom_sysvar_get_as_int_vr ();
IMPORT int ipcom_sysvar_get_descriptive_int0 ();
IMPORT int ipcom_sysvar_get_descriptive_int_vr ();
IMPORT int ipcom_sysvar_getvr ();
IMPORT int ipcom_sysvar_remove_observer ();
IMPORT int ipcom_sysvar_set ();
IMPORT int ipcom_sysvar_set0 ();
IMPORT int ipcom_sysvar_set_tree ();
IMPORT int ipcom_sysvar_setv ();
IMPORT int ipcom_sysvar_setvr ();
IMPORT int ipcom_sysvar_unset ();
IMPORT int ipcom_telnetd ();
IMPORT int ipcom_telnetspawn ();
IMPORT int ipcom_tmo2_cancel ();
IMPORT int ipcom_tmo2_delete ();
IMPORT int ipcom_tmo2_get ();
IMPORT int ipcom_tmo2_new ();
IMPORT int ipcom_tmo2_request ();
IMPORT int ipcom_tmo2_request_timeval ();
IMPORT int ipcom_tmo2_reset ();
IMPORT int ipcom_tmo2_select ();
IMPORT int ipcom_tmo_cancel ();
IMPORT int ipcom_tmo_get ();
IMPORT int ipcom_tmo_request ();
IMPORT int ipcom_tmo_reset ();
IMPORT int ipcom_unlink ();
IMPORT int ipcom_unsetenv ();
IMPORT int ipcom_usr_create ();
IMPORT int ipcom_version;
IMPORT int ipcom_vsyslog ();
IMPORT int ipcom_vxshell_add_cmd ();
IMPORT int ipcom_vxshell_add_cmd_hook;
IMPORT int ipcom_vxworks_boot_devname ();
IMPORT int ipcom_vxworks_loginStringGet ();
IMPORT int ipcom_vxworks_pkt_pool_hdr_ctor ();
IMPORT int ipcom_vxworks_proc_free ();
IMPORT int ipcom_vxworks_rtp_del_hook_add ();
IMPORT int ipcom_vxworks_task_del_hook ();
IMPORT int ipcom_windnet_socketwritev ();
IMPORT int ipcom_windnet_socklib_init ();
IMPORT int ipcom_windnet_socklib_sock_size ();
IMPORT int ipcom_windnet_socklib_socket_free ();
IMPORT int ipcom_windnet_socklib_socket_init ();
IMPORT int ipcom_wmb ();
IMPORT int ipcom_wv_event_2 ();
IMPORT int ipcom_wv_marker_1 ();
IMPORT int ipcom_wv_marker_2 ();
IMPORT int ipmcp_is_enabled;
IMPORT int ipmcrypto_MD5_Final ();
IMPORT int ipmcrypto_MD5_Init ();
IMPORT int ipmcrypto_MD5_Update ();
IMPORT int ipmcrypto_SHA1_Final ();
IMPORT int ipmcrypto_SHA1_Init ();
IMPORT int ipmcrypto_SHA1_Update ();
IMPORT int ipmcrypto_md5_calculate ();
IMPORT int ipnet;
IMPORT int ipnet_arp_ioctl ();
IMPORT int ipnet_arp_request ();
IMPORT int ipnet_bit_array_clr ();
IMPORT int ipnet_bit_array_test_and_set ();
IMPORT int ipnet_bool_map;
IMPORT int ipnet_cmd_if_type_to_str ();
IMPORT int ipnet_cmd_ifconfig_common ();
IMPORT int ipnet_cmd_ifconfig_hook;
IMPORT int ipnet_cmd_init_addrs ();
IMPORT int ipnet_cmd_msec_since ();
IMPORT int ipnet_cmd_neigh_for_each ();
IMPORT int ipnet_cmd_neigh_for_each_optmask ();
IMPORT int ipnet_cmd_ping ();
IMPORT int ipnet_cmd_ping_stoppable ();
IMPORT int ipnet_cmd_qc_hook;
IMPORT int ipnet_cmd_route_hook;
IMPORT int ipnet_cmd_rt_flags_to_str ();
IMPORT int ipnet_cmd_rt_flags_to_str_short ();
IMPORT int ipnet_conf_boot_cmd;
IMPORT int ipnet_conf_cache_bufsiz;
IMPORT int ipnet_conf_inq_max;
IMPORT int ipnet_conf_interfaces;
IMPORT int ipnet_conf_ip4_min_mtu;
IMPORT int ipnet_conf_ip6_min_mtu;
IMPORT int ipnet_conf_link_layer;
IMPORT int ipnet_conf_max_dgram_frag_list_len;
IMPORT int ipnet_conf_max_reassembly_list_len;
IMPORT int ipnet_conf_max_sockets;
IMPORT int ipnet_conf_memory_limit;
IMPORT int ipnet_conf_reassembly_timeout;
IMPORT int ipnet_conf_update ();
IMPORT int ipnet_configd_start ();
IMPORT int ipnet_configure ();
IMPORT int ipnet_create ();
IMPORT int ipnet_create_reassembled_packet ();
IMPORT int ipnet_ctrl ();
IMPORT int ipnet_ctrl_sig ();
IMPORT int ipnet_do_close ();
IMPORT int ipnet_dst_cache;
IMPORT int ipnet_dst_cache_blackhole ();
IMPORT int ipnet_dst_cache_blackhole_flow_spec ();
IMPORT int ipnet_dst_cache_flush ();
IMPORT int ipnet_dst_cache_flush_where_neigh_is ();
IMPORT int ipnet_dst_cache_foreach ();
IMPORT int ipnet_dst_cache_init ();
IMPORT int ipnet_dst_cache_new ();
IMPORT int ipnet_dst_cache_number_limit;
IMPORT int ipnet_dst_cache_select_best_rt ();
IMPORT int ipnet_dst_cache_set_path_mtu ();
IMPORT int ipnet_dst_cache_set_rx_handler ();
IMPORT int ipnet_dst_cache_set_tx_handler ();
IMPORT int ipnet_eth_add_hdr ();
IMPORT int ipnet_eth_addr_broadcast;
IMPORT int ipnet_eth_addr_broadcast_storage;
IMPORT int ipnet_eth_if_init ();
IMPORT int ipnet_eth_update_mib2_lastchange ();
IMPORT int ipnet_flags;
IMPORT int ipnet_flow_spec_domain ();
IMPORT int ipnet_flow_spec_from_info ();
IMPORT int ipnet_flow_spec_from_sock ();
IMPORT int ipnet_frag_release_peer_info ();
IMPORT int ipnet_frag_set_peer_info ();
IMPORT int ipnet_frag_to_peer_info ();
IMPORT int ipnet_fragment_packet ();
IMPORT int ipnet_get_sock ();
IMPORT int ipnet_has_priv ();
IMPORT int ipnet_icmp4_param_init ();
IMPORT int ipnet_icmp4_send ();
IMPORT int ipnet_icmp4_send_host_unreachable ();
IMPORT int ipnet_icmp4_send_port_unreachable ();
IMPORT int ipnet_if_can_detach ();
IMPORT int ipnet_if_clean ();
IMPORT int ipnet_if_clean_ppp_peer ();
IMPORT int ipnet_if_clean_snd_queue ();
IMPORT int ipnet_if_detach ();
IMPORT int ipnet_if_drv_ioctl ();
IMPORT int ipnet_if_drv_output ();
IMPORT int ipnet_if_free ();
IMPORT int ipnet_if_get_index_array ();
IMPORT int ipnet_if_indextonetif ();
IMPORT int ipnet_if_init ();
IMPORT int ipnet_if_init_ppp_peer ();
IMPORT int ipnet_if_link_ioctl ();
IMPORT int ipnet_if_nametonetif ();
IMPORT int ipnet_if_output ();
IMPORT int ipnet_if_set_ipv4_ppp_peer ();
IMPORT int ipnet_if_to_sockaddr_dl ();
IMPORT int ipnet_if_update_mib2_ifLastChange ();
IMPORT int ipnet_ifconfig_if_change_state ();
IMPORT int ipnet_igmpv3_report_change ();
IMPORT int ipnet_increase_hdr_space ();
IMPORT int ipnet_ioctl_move_if_rt_to_vr ();
IMPORT int ipnet_ip4_acd_conflict ();
IMPORT int ipnet_ip4_add_addr ();
IMPORT int ipnet_ip4_add_addr2 ();
IMPORT int ipnet_ip4_add_route_table ();
IMPORT int ipnet_ip4_addr_to_sockaddr ();
IMPORT int ipnet_ip4_change_addr_mask ();
IMPORT int ipnet_ip4_configure_route_table ();
IMPORT int ipnet_ip4_dst_cache_get ();
IMPORT int ipnet_ip4_dst_cache_rx_ctor ();
IMPORT int ipnet_ip4_dst_unreachable ();
IMPORT int ipnet_ip4_dst_unreachable_filter ();
IMPORT int ipnet_ip4_flow_spec_from_info ();
IMPORT int ipnet_ip4_flow_spec_from_pkt ();
IMPORT int ipnet_ip4_fragment_timeout_peer ();
IMPORT int ipnet_ip4_get_addr_entry ();
IMPORT int ipnet_ip4_get_addr_type ();
IMPORT int ipnet_ip4_get_addr_type2 ();
IMPORT int ipnet_ip4_get_mss ();
IMPORT int ipnet_ip4_get_src_addr ();
IMPORT int ipnet_ip4_init ();
IMPORT int ipnet_ip4_input ();
IMPORT int ipnet_ip4_insert_addr_cache ();
IMPORT int ipnet_ip4_is_part_of_same_pkt ();
IMPORT int ipnet_ip4_kioevent ();
IMPORT int ipnet_ip4_netif_get_subbrd ();
IMPORT int ipnet_ip4_pkt_with_iphdr_rawsock_tx ();
IMPORT int ipnet_ip4_pkt_with_iphdr_tx ();
IMPORT int ipnet_ip4_reg_transport_layer ();
IMPORT int ipnet_ip4_remove_addr ();
IMPORT int ipnet_ip4_remove_addr_cache ();
IMPORT int ipnet_ip4_rfc1256_mode_update ();
IMPORT int ipnet_ip4_rx ();
IMPORT int ipnet_ip4_sendto ();
IMPORT int ipnet_ip4_transport_rx ();
IMPORT int ipnet_ip4_tx ();
IMPORT int ipnet_is_loopback ();
IMPORT int ipnet_is_sock_exceptional ();
IMPORT int ipnet_is_sock_readable ();
IMPORT int ipnet_is_sock_writable ();
IMPORT int ipnet_is_stack_task ();
IMPORT int ipnet_kioevent ();
IMPORT int ipnet_loop_pkt_tx ();
IMPORT int ipnet_loopback_attach ();
IMPORT int ipnet_loopback_get_netif ();
IMPORT int ipnet_loopback_if_init ();
IMPORT int ipnet_mcast_build_if_filter ();
IMPORT int ipnet_mcast_build_source_change_report ();
IMPORT int ipnet_mcast_clear ();
IMPORT int ipnet_mcast_free ();
IMPORT int ipnet_mcast_init ();
IMPORT int ipnet_mcast_report_finish ();
IMPORT int ipnet_mcast_schedule_membership_report ();
IMPORT int ipnet_mcast_time_to_msec ();
IMPORT int ipnet_msec_now ();
IMPORT int ipnet_neigh_dad ();
IMPORT int ipnet_neigh_flush ();
IMPORT int ipnet_neigh_flush_all ();
IMPORT int ipnet_neigh_foreach ();
IMPORT int ipnet_neigh_get ();
IMPORT int ipnet_neigh_init ();
IMPORT int ipnet_neigh_init_addr_observer ();
IMPORT int ipnet_neigh_invalidate ();
IMPORT int ipnet_neigh_is_probing ();
IMPORT int ipnet_neigh_netif_discard ();
IMPORT int ipnet_neigh_probe ();
IMPORT int ipnet_neigh_release ();
IMPORT int ipnet_neigh_set_blackhole ();
IMPORT int ipnet_neigh_set_external ();
IMPORT int ipnet_neigh_set_gateway ();
IMPORT int ipnet_neigh_set_lifetime ();
IMPORT int ipnet_neigh_set_lladdr ();
IMPORT int ipnet_neigh_set_local ();
IMPORT int ipnet_neigh_set_perm ();
IMPORT int ipnet_neigh_set_publ ();
IMPORT int ipnet_neigh_set_report ();
IMPORT int ipnet_neigh_set_silent ();
IMPORT int ipnet_neigh_set_state ();
IMPORT int ipnet_netif_change_flags ();
IMPORT int ipnet_netif_is_ifproxy ();
IMPORT int ipnet_netif_neigh_create ();
IMPORT int ipnet_next_ephemeral_port ();
IMPORT int ipnet_noeth_if_init ();
IMPORT int ipnet_packet_getsockopt ();
IMPORT int ipnet_packet_input ();
IMPORT int ipnet_packet_setsockopt ();
IMPORT int ipnet_pcap_ioctl ();
IMPORT int ipnet_peer_info_addref ();
IMPORT int ipnet_peer_info_get ();
IMPORT int ipnet_peer_info_init ();
IMPORT int ipnet_peer_info_release ();
IMPORT int ipnet_peer_info_timeout_cancel ();
IMPORT int ipnet_peer_info_timeout_schedule ();
IMPORT int ipnet_ping_stat_init ();
IMPORT int ipnet_ping_stat_receive ();
IMPORT int ipnet_ping_stat_report ();
IMPORT int ipnet_ping_stat_transmit ();
IMPORT int ipnet_pipe_create ();
IMPORT int ipnet_pkt_clone ();
IMPORT int ipnet_pkt_get_maxlen ();
IMPORT int ipnet_pkt_input ();
IMPORT int ipnet_pkt_pool_drain ();
IMPORT int ipnet_pkt_pool_hdr_count_hint ();
IMPORT int ipnet_pkt_pool_hdr_ctor_func;
IMPORT int ipnet_pkt_pool_init ();
IMPORT int ipnet_pkt_pool_slab_desc;
IMPORT int ipnet_pkt_queue_delete ();
IMPORT int ipnet_pkt_queue_fifo_template ();
IMPORT int ipnet_pkt_queue_init ();
IMPORT int ipnet_pkt_queue_new ();
IMPORT int ipnet_pmtu_foreach ();
IMPORT int ipnet_pmtu_get ();
IMPORT int ipnet_pmtu_init ();
IMPORT int ipnet_pmtu_limit;
IMPORT int ipnet_pmtu_live_time;
IMPORT int ipnet_pmtu_proc ();
IMPORT int ipnet_ppp_if_init ();
IMPORT int ipnet_queue_received_packet ();
IMPORT int ipnet_raw_input ();
IMPORT int ipnet_reassembly ();
IMPORT int ipnet_register_if_attach_handler ();
IMPORT int ipnet_release_sock ();
IMPORT int ipnet_resume_stack ();
IMPORT int ipnet_route_add ();
IMPORT int ipnet_route_add_table ();
IMPORT int ipnet_route_apply_mask ();
IMPORT int ipnet_route_cache_invalidate ();
IMPORT int ipnet_route_create_mask ();
IMPORT int ipnet_route_delete ();
IMPORT int ipnet_route_delete2 ();
IMPORT int ipnet_route_delete_name ();
IMPORT int ipnet_route_delete_table ();
IMPORT int ipnet_route_delete_vr ();
IMPORT int ipnet_route_first_entry ();
IMPORT int ipnet_route_for_each_data_init ();
IMPORT int ipnet_route_get_name ();
IMPORT int ipnet_route_get_rtab ();
IMPORT int ipnet_route_get_table_ids ();
IMPORT int ipnet_route_has_changed ();
IMPORT int ipnet_route_has_expired ();
IMPORT int ipnet_route_ip4_is_mcast_or_bcast ();
IMPORT int ipnet_route_is_virtual_router_valid ();
IMPORT int ipnet_route_key_cmp ();
IMPORT int ipnet_route_key_to_sockaddr ();
IMPORT int ipnet_route_lock ();
IMPORT int ipnet_route_lookup ();
IMPORT int ipnet_route_lookup_ecmp ();
IMPORT int ipnet_route_next_entry ();
IMPORT int ipnet_route_notify_func ();
IMPORT int ipnet_route_policy_get_rule_chain ();
IMPORT int ipnet_route_policy_ioctl ();
IMPORT int ipnet_route_raw_lookup ();
IMPORT int ipnet_route_raw_lookup2 ();
IMPORT int ipnet_route_remove_all ();
IMPORT int ipnet_route_remove_all_cb_for_each_entry ();
IMPORT int ipnet_route_remove_dynamic_rt_with_gw ();
IMPORT int ipnet_route_rotate_gateways ();
IMPORT int ipnet_route_set_lifetime ();
IMPORT int ipnet_route_set_name ();
IMPORT int ipnet_route_set_rtab ();
IMPORT int ipnet_route_sockaddr_to_key ();
IMPORT int ipnet_route_unlock ();
IMPORT int ipnet_route_vr_and_table_from_name ();
IMPORT int ipnet_route_walk_tree ();
IMPORT int ipnet_routesock_addr_add ();
IMPORT int ipnet_routesock_addr_conflict ();
IMPORT int ipnet_routesock_addr_delete ();
IMPORT int ipnet_routesock_if_announce ();
IMPORT int ipnet_routesock_if_change ();
IMPORT int ipnet_routesock_neigh_resolve ();
IMPORT int ipnet_routesock_rt_add ();
IMPORT int ipnet_routesock_rt_change ();
IMPORT int ipnet_routesock_rt_delete ();
IMPORT int ipnet_routesock_rt_miss ();
IMPORT int ipnet_routesock_rt_redirect ();
IMPORT int ipnet_sec_now ();
IMPORT int ipnet_sig_free ();
IMPORT int ipnet_sock_alloc_private_data ();
IMPORT int ipnet_sock_bind ();
IMPORT int ipnet_sock_bind_addr_removed ();
IMPORT int ipnet_sock_bind_to_port ();
IMPORT int ipnet_sock_change_addr_entry ();
IMPORT int ipnet_sock_data_avail ();
IMPORT int ipnet_sock_drop_all_multicast_memberships ();
IMPORT int ipnet_sock_free ();
IMPORT int ipnet_sock_get ();
IMPORT int ipnet_sock_get_bound_port_size ();
IMPORT int ipnet_sock_get_ops_handle ();
IMPORT int ipnet_sock_get_route ();
IMPORT int ipnet_sock_has_waiting_writers ();
IMPORT int ipnet_sock_init ();
IMPORT int ipnet_sock_ip4_get_mcast_data ();
IMPORT int ipnet_sock_ip4_get_ops ();
IMPORT int ipnet_sock_ip4_lookup ();
IMPORT int ipnet_sock_ip4_mcast_delete_data ();
IMPORT int ipnet_sock_ip4_register ();
IMPORT int ipnet_sock_join_router_alert_chain ();
IMPORT int ipnet_sock_leave_router_alert_chain ();
IMPORT int ipnet_sock_next ();
IMPORT int ipnet_sock_ops;
IMPORT int ipnet_sock_packet_lookup ();
IMPORT int ipnet_sock_packet_register ();
IMPORT int ipnet_sock_pkt_drain ();
IMPORT int ipnet_sock_register_ops ();
IMPORT int ipnet_sock_route_register ();
IMPORT int ipnet_sock_router_alert_pkt ();
IMPORT int ipnet_sock_set_reachable ();
IMPORT int ipnet_sock_set_unreachable ();
IMPORT int ipnet_sock_tcp_register ();
IMPORT int ipnet_sock_tcp_zombie_send_pkt_free ();
IMPORT int ipnet_sock_udp_register ();
IMPORT int ipnet_sock_unbind ();
IMPORT int ipnet_sock_unconnect ();
IMPORT int ipnet_sock_update_reuse ();
IMPORT int ipnet_sockopt_ip4_addr_to_netif ();
IMPORT int ipnet_softirq_init ();
IMPORT int ipnet_softirq_schedule ();
IMPORT int ipnet_start ();
IMPORT int ipnet_stats_tcp_established ();
IMPORT int ipnet_suspend_stack ();
IMPORT int ipnet_sys_accept ();
IMPORT int ipnet_sys_bind ();
IMPORT int ipnet_sys_checktcp ();
IMPORT int ipnet_sys_connect ();
IMPORT int ipnet_sys_get_ancillary_data ();
IMPORT int ipnet_sys_getname ();
IMPORT int ipnet_sys_getsockopt ();
IMPORT int ipnet_sys_if_attach ();
IMPORT int ipnet_sys_if_changelinkaddr ();
IMPORT int ipnet_sys_if_changemtu ();
IMPORT int ipnet_sys_if_changename ();
IMPORT int ipnet_sys_if_detach ();
IMPORT int ipnet_sys_if_free ();
IMPORT int ipnet_sys_if_indexname ();
IMPORT int ipnet_sys_if_malloc ();
IMPORT int ipnet_sys_if_nametonetif ();
IMPORT int ipnet_sys_listen ();
IMPORT int ipnet_sys_poll ();
IMPORT int ipnet_sys_poll_async ();
IMPORT int ipnet_sys_savesignal ();
IMPORT int ipnet_sys_sendmsg ();
IMPORT int ipnet_sys_setsockopt ();
IMPORT int ipnet_sys_shutdown ();
IMPORT int ipnet_sys_socket ();
IMPORT int ipnet_sys_socketclose ();
IMPORT int ipnet_sys_socketioctl ();
IMPORT int ipnet_sys_sysctl ();
IMPORT int ipnet_sysctl_create_ifinfo ();
IMPORT int ipnet_sysctl_if_add_addrs_one ();
IMPORT int ipnet_sysvar_get_as_int_vr ();
IMPORT int ipnet_sysvar_netif_get_as_int ();
IMPORT int ipnet_sysvar_netif_get_as_int_ex ();
IMPORT int ipnet_timeout_cancel ();
IMPORT int ipnet_timeout_msec_until ();
IMPORT int ipnet_timeout_schedule ();
IMPORT int ipnet_timeval_to_msec ();
IMPORT int ipnet_try_free_mem ();
IMPORT int ipnet_usr_sock_get_ops ();
IMPORT int ipnet_usr_sock_get_pipe ();
IMPORT int ipnet_usr_sock_get_response_pipe ();
IMPORT int ipnet_usr_sock_get_route_cache_id ();
IMPORT int ipnet_usr_sock_init ();
IMPORT int ipnet_usr_sock_init_sig ();
IMPORT int ipnet_usr_sock_recvmsg ();
IMPORT int ipnet_usr_sock_wait_until_writable ();
IMPORT int ipnet_version ();
IMPORT int ipstack_ifconfig_print_info ();
IMPORT int iptcp;
IMPORT int iptcp_accept ();
IMPORT int iptcp_ao_rtnetlink_init ();
IMPORT int iptcp_change_state_global ();
IMPORT int iptcp_close ();
IMPORT int iptcp_conf_default_backlog;
IMPORT int iptcp_configure ();
IMPORT int iptcp_connect ();
IMPORT int iptcp_create ();
IMPORT int iptcp_drop_connection ();
IMPORT int iptcp_get_rto ();
IMPORT int iptcp_get_state ();
IMPORT int iptcp_getsockopt ();
IMPORT int iptcp_icmp4_report ();
IMPORT int iptcp_ioctl ();
IMPORT int iptcp_listen ();
IMPORT int iptcp_pkt_drain ();
IMPORT int iptcp_send ();
IMPORT int iptcp_send_reset ();
IMPORT int iptcp_setsockopt ();
IMPORT int iptcp_shutdown ();
IMPORT int iptcp_sock_free ();
IMPORT int iptcp_sock_init ();
IMPORT int iptcp_start ();
IMPORT int iptcp_tx_list;
IMPORT int iptcp_usr_recv ();
IMPORT int iptcp_version ();
IMPORT int iptcp_window_update ();
IMPORT int iptelnets_configure ();
IMPORT int iptelnets_start ();
IMPORT int iptelnets_version ();
IMPORT int isalnum ();
IMPORT int isalpha ();
IMPORT int isatty ();
IMPORT int iscntrl ();
IMPORT int isdigit ();
IMPORT int isgraph ();
IMPORT int islower ();
IMPORT int isprint ();
IMPORT int ispunct ();
IMPORT int isrDeferJobAdd ();
IMPORT int isrDeferLibInit ();
IMPORT int isrDeferQueueGet ();
IMPORT int isrIdCurrent;
IMPORT int isrJobPool;
IMPORT int isrRerouteNotify ();
IMPORT int isr_dispatcher ();
IMPORT int isspace ();
IMPORT int isupper ();
IMPORT int isxdigit ();
IMPORT int jobAdd ();
IMPORT int jobQueueCreate ();
IMPORT int jobQueueInit ();
IMPORT int jobQueueLibInit ();
IMPORT int jobQueuePost ();
IMPORT int jobQueuePriorityMask ();
IMPORT int jobQueueProcess ();
IMPORT int jobQueueProcessFunc;
IMPORT int jobQueueStdJobsAlloc ();
IMPORT int jobQueueStdPoolInit ();
IMPORT int jobQueueStdPost ();
IMPORT int jobQueueTask ();
IMPORT int jobTaskLibInit ();
IMPORT int jobTaskWorkAdd ();
IMPORT int kernelBaseInit ();
IMPORT int kernelCpuEnable ();
IMPORT int kernelId;
IMPORT int kernelIdGet ();
IMPORT int kernelInit ();
IMPORT int kernelIsCpuIdle ();
IMPORT int kernelIsIdle;
IMPORT int kernelIsSystemIdle ();
IMPORT int kernelModuleListId;
IMPORT int kernelObjClassId;
IMPORT int kernelRgnPoolId;
IMPORT int kernelRoundRobinInstall ();
IMPORT int kernelState;
IMPORT int kernelTimeSlice ();
IMPORT int kernelTimeSliceGet ();
IMPORT int kernelVersion ();
IMPORT int kernelVirtPgPoolId;
IMPORT int kill ();
IMPORT int kprintf ();
IMPORT int l ();
IMPORT int labs ();
IMPORT int ld ();
IMPORT int ldCommonMatchAll;
IMPORT int ldexp ();
IMPORT int ldiv ();
IMPORT int ldiv_r ();
IMPORT int le_uuid_dec ();
IMPORT int le_uuid_enc ();
IMPORT int ledBeep ();
IMPORT int ledBwdFind ();
IMPORT int ledCDelete ();
IMPORT int ledChange ();
IMPORT int ledClose ();
IMPORT int ledComplete ();
IMPORT int ledCompletionSet ();
IMPORT int ledControl ();
IMPORT int ledDfltComplete ();
IMPORT int ledFwdFind ();
IMPORT int ledHistCurrentNumGet ();
IMPORT int ledHistFind ();
IMPORT int ledHistNextGet ();
IMPORT int ledHistNumGet ();
IMPORT int ledHistPrevGet ();
IMPORT int ledHistResize ();
IMPORT int ledHistoryAdd ();
IMPORT int ledHistoryClone ();
IMPORT int ledHistoryCreate ();
IMPORT int ledHistoryFree ();
IMPORT int ledHistoryLineAllocate ();
IMPORT int ledHistorySet ();
IMPORT int ledInactivityDelaySet ();
IMPORT int ledLibInit ();
IMPORT int ledModeDefaultNameGet ();
IMPORT int ledModeNameGet ();
IMPORT int ledModeRegister ();
IMPORT int ledModeSet ();
IMPORT int ledNWrite ();
IMPORT int ledOpen ();
IMPORT int ledPreempt ();
IMPORT int ledPreemptSet ();
IMPORT int ledRead ();
IMPORT int ledRead2 ();
IMPORT int ledRedraw ();
IMPORT int ledReplace ();
IMPORT int ledSearch ();
IMPORT int link ();
IMPORT int linkBufPoolInit ();
IMPORT int linkDataSyms;
IMPORT int linkSyms;
IMPORT int linkedCtorsInitialized;
IMPORT int listen ();
IMPORT int lkAddr ();
IMPORT int lkAddrInternal ();
IMPORT int lkup ();
IMPORT int ll ();
IMPORT int llr ();
IMPORT int loadCommonSymbolProcess ();
IMPORT int loadDefinedSymbolProcess ();
IMPORT int loadElfFileHeaderReadAndCheck ();
IMPORT int loadElfInit ();
IMPORT int loadElfProgramHeaderTableReadAndCheck ();
IMPORT int loadElfRelEntryRead ();
IMPORT int loadElfRelUEntryRead ();
IMPORT int loadElfRelaEntryRead ();
IMPORT int loadElfSectionHeaderCheck ();
IMPORT int loadElfSectionHeaderReadAndCheck ();
IMPORT int loadElfSymbolEntryRead ();
IMPORT int loadExecUsrFunc ();
IMPORT int loadExecUsrInit ();
IMPORT int loadFileSectionsChecksum ();
IMPORT int loadLibInit ();
IMPORT int loadModule ();
IMPORT int loadModuleAt ();
IMPORT int loadModuleEx ();
IMPORT int loadModuleInfoFromFd ();
IMPORT int loadModuleInfoFromFilenameOpen ();
IMPORT int loadModuleInfoInit ();
IMPORT int loadModuleInfoRelease ();
IMPORT int loadModuleSeek ();
IMPORT int loadModuleStringRead ();
IMPORT int loadModuleTagsCheck ();
IMPORT int loadModuleValueRead ();
IMPORT int loadSectionsInstall ();
IMPORT int loadSegInfoDescAllocate ();
IMPORT int loadSegInfoDescFree ();
IMPORT int loadSegmentsAllocate ();
IMPORT int loadShareTgtMemAlign ();
IMPORT int loadShareTgtMemFree ();
IMPORT int loadShareTgtMemSet ();
IMPORT int loadSysSymTblLoad ();
IMPORT int loadUndefinedSymbolProcess ();
IMPORT int loaderCacheBufferSize;
IMPORT int localToGlobalOffset;
IMPORT int localeconv ();
IMPORT int localtime ();
IMPORT int localtime_r ();
IMPORT int log ();
IMPORT int log10 ();
IMPORT int logDecorationChange ();
IMPORT int logFd;
IMPORT int logFdAdd ();
IMPORT int logFdDelete ();
IMPORT int logFdFromRlogin;
IMPORT int logFdSem;
IMPORT int logFdSet ();
IMPORT int logInit ();
IMPORT int logLevelChange ();
IMPORT int logMsg ();
IMPORT int logShow ();
IMPORT int logTask ();
IMPORT int logTaskId;
IMPORT int logTaskOptions;
IMPORT int logTaskPriority;
IMPORT int logTaskStackSize;
IMPORT int log_get_level ();
IMPORT int log_init ();
IMPORT int log_printf ();
IMPORT int log_set_level ();
IMPORT int loggerInfoShow ();
IMPORT int loginHostname;
IMPORT int loginPassword;
IMPORT int loginUsername;
IMPORT int logout ();
IMPORT int longjmp ();
IMPORT int ls ();
IMPORT int lseek ();
IMPORT int lsr ();
IMPORT int lstAdd ();
IMPORT int lstConcat ();
IMPORT int lstCount ();
IMPORT int lstDelete ();
IMPORT int lstExtract ();
IMPORT int lstFind ();
IMPORT int lstFirst ();
IMPORT int lstFree ();
IMPORT int lstFree2 ();
IMPORT int lstGet ();
IMPORT int lstInit ();
IMPORT int lstInsert ();
IMPORT int lstLast ();
IMPORT int lstLibInit ();
IMPORT int lstNStep ();
IMPORT int lstNext ();
IMPORT int lstNth ();
IMPORT int lstPrevious ();
IMPORT int m ();
IMPORT int m2If64BitCounters;
IMPORT int mRegs ();
IMPORT int m_prepend ();
IMPORT int malloc ();
IMPORT int map_add ();
IMPORT int map_alloc ();
IMPORT int map_del ();
IMPORT int map_find ();
IMPORT int map_first ();
IMPORT int map_free ();
IMPORT int map_init ();
IMPORT int map_last ();
IMPORT int map_remove ();
IMPORT int map_show ();
IMPORT int map_uninit ();
IMPORT int mask_copy ();
IMPORT int mask_generate ();
IMPORT int mask_poll ();
IMPORT int mask_read ();
IMPORT int mask_write ();
IMPORT int mathSoftInit ();
IMPORT int max_hdr;
IMPORT int max_linkhdr;
IMPORT int max_protohdr;
IMPORT int mblen ();
IMPORT int mbstowcs ();
IMPORT int mbtowc ();
IMPORT int md ();
IMPORT int md5_block_data_order ();
IMPORT int md5_block_host_order ();
IMPORT int mdlSymSyncLibInit ();
IMPORT int mdlSymSyncModAdd ();
IMPORT int mdlSymSyncModInfoGet ();
IMPORT int mdlSymSyncModuleRemove ();
IMPORT int mdlSymSyncStop ();
IMPORT int mdlSymSyncSymListAdd ();
IMPORT int mdlSymSyncSymListGet ();
IMPORT int memAddToPool ();
IMPORT int memBlockSizeGet ();
IMPORT int memDefaultAlignment;
IMPORT int memFindMax ();
IMPORT int memInfoGet ();
IMPORT int memInfoInit ();
IMPORT int memInit ();
IMPORT int memMsgBlockError;
IMPORT int memMsgBlockTooBig;
IMPORT int memOptionsGet ();
IMPORT int memOptionsSet ();
IMPORT int memPartAddToPool ();
IMPORT int memPartAlignedAlloc ();
IMPORT int memPartAlloc ();
IMPORT int memPartAllocErrorRtn;
IMPORT int memPartAllocN ();
IMPORT int memPartBlockErrorRtn;
IMPORT int memPartBlockIsValid ();
IMPORT int memPartBlockValidate ();
IMPORT int memPartClassId;
IMPORT int memPartCreate ();
IMPORT int memPartCreateHookSet ();
IMPORT int memPartDelete ();
IMPORT int memPartDeleteFree ();
IMPORT int memPartEdrErrorInject ();
IMPORT int memPartFindMax ();
IMPORT int memPartFree ();
IMPORT int memPartFreeListWalk ();
IMPORT int memPartFreeN ();
IMPORT int memPartHooksInstall ();
IMPORT int memPartInfoGet ();
IMPORT int memPartInit ();
IMPORT int memPartInsertFree ();
IMPORT int memPartLibInit ();
IMPORT int memPartOptionsDefault;
IMPORT int memPartOptionsGet ();
IMPORT int memPartOptionsSet ();
IMPORT int memPartRealloc ();
IMPORT int memPartReallocInternal ();
IMPORT int memPartShow ();
IMPORT int memPartVerifiedLock ();
IMPORT int memPoolEndAdrs;
IMPORT int memShow ();
IMPORT int memShowInit ();
IMPORT int memSysPartId;
IMPORT int memSysPartition;
IMPORT int memalign ();
IMPORT int memchr ();
IMPORT int memcmp ();
IMPORT int memcpy ();
IMPORT int memmove ();
IMPORT int memoryDump ();
IMPORT int memoryModify ();
IMPORT int memset ();
IMPORT int mib2ErrorAdd ();
IMPORT int mib2Init ();
IMPORT int miiBusCreate ();
IMPORT int miiBusDelete ();
IMPORT int miiBusGet ();
IMPORT int miiBusIdleErrorCheck ();
IMPORT int miiBusListAdd ();
IMPORT int miiBusListDel ();
IMPORT int miiBusLpiModeGet ();
IMPORT int miiBusMediaAdd ();
IMPORT int miiBusMediaDefaultSet ();
IMPORT int miiBusMediaDel ();
IMPORT int miiBusMediaListGet ();
IMPORT int miiBusMediaUpdate ();
IMPORT int miiBusModeGet ();
IMPORT int miiBusModeSet ();
IMPORT int miiBusRead ();
IMPORT int miiBusRegister ();
IMPORT int miiBusWrite ();
IMPORT int miiLpiModeGet_desc;
IMPORT int miiMediaUpdate_desc;
IMPORT int miiModeGet_desc;
IMPORT int miiModeSet_desc;
IMPORT int miiRead_desc;
IMPORT int miiWrite_desc;
IMPORT int mkdir ();
IMPORT int mktime ();
IMPORT int mm ();
IMPORT int mmcCmdReadExtCsd ();
IMPORT int mmcCmdSeEraseGrpEnd ();
IMPORT int mmcCmdSeEraseGrpStart ();
IMPORT int mmcCmdSetBlockNum ();
IMPORT int mmcCmdSetEraseGrp ();
IMPORT int mmcHrfsInclude;
IMPORT int mmcSendHpi ();
IMPORT int mmcSwitch ();
IMPORT int mmuArchCopySize;
IMPORT int mmuArchLibAttrs;
IMPORT int mmuArchLibFuncs;
IMPORT int mmuArchPteFlags;
IMPORT int mmuArchTtbrFlags;
IMPORT int mmuArchTtbrGet ();
IMPORT int mmuCacheStateTransTbl;
IMPORT int mmuContextTbl;
IMPORT int mmuCortexA8ADisable ();
IMPORT int mmuCortexA8AEnable ();
IMPORT int mmuCortexA8AcrGet ();
IMPORT int mmuCortexA8AcrSet ();
IMPORT int mmuCortexA8BufCopy ();
IMPORT int mmuCortexA8DTcmrGet ();
IMPORT int mmuCortexA8DTcmrSet ();
IMPORT int mmuCortexA8DacrSet ();
IMPORT int mmuCortexA8ITcmrGet ();
IMPORT int mmuCortexA8ITcmrSet ();
IMPORT int mmuCortexA8LibInstall ();
IMPORT int mmuCortexA8SecondLevelMiniHeap_Max;
IMPORT int mmuCortexA8TLBIDFlushAll ();
IMPORT int mmuCortexA8TLBIDFlushEntry ();
IMPORT int mmuCortexA8TtbrGet ();
IMPORT int mmuCortexA8TtbrGetAll ();
IMPORT int mmuCortexA8TtbrSet ();
IMPORT int mmuCortexA8TtbrSetAll ();
IMPORT int mmuCortexA8WordSet ();
IMPORT int mmuCortexA8WordSetMultiple ();
IMPORT int mmuCrGet;
IMPORT int mmuFarGet ();
IMPORT int mmuFsrGet ();
IMPORT int mmuHardCrGet ();
IMPORT int mmuIFsrGet ();
IMPORT int mmuInvalidState;
IMPORT int mmuLibFuncs;
IMPORT int mmuMaskTransTbl;
IMPORT int mmuModifyCr;
IMPORT int mmuModifyHardCr ();
IMPORT int mmuPhysToVirt ();
IMPORT int mmuProtStateTransTbl;
IMPORT int mmuReadId ();
IMPORT int mmuValidStateTransTbl;
IMPORT int mmuVirtToPhys ();
IMPORT int modf ();
IMPORT int modlist;
IMPORT int moduleCheck ();
IMPORT int moduleCommonSymEach ();
IMPORT int moduleCreate ();
IMPORT int moduleCreateHookAdd ();
IMPORT int moduleCreateHookDelete ();
IMPORT int moduleDelete ();
IMPORT int moduleDescDestroy ();
IMPORT int moduleEach ();
IMPORT int moduleFindByGroup ();
IMPORT int moduleFindByName ();
IMPORT int moduleFindByNameAndPath ();
IMPORT int moduleFirstSectionGet ();
IMPORT int moduleFlagsGet ();
IMPORT int moduleFlagsSet ();
IMPORT int moduleHookLibInit ();
IMPORT int moduleIdFigure ();
IMPORT int moduleIdListGet ();
IMPORT int moduleIdVerify ();
IMPORT int moduleInfoGet ();
IMPORT int moduleInit ();
IMPORT int moduleIsLastModuleMatched ();
IMPORT int moduleLibInit ();
IMPORT int moduleLoadHookAdd ();
IMPORT int moduleLoadHookDelete ();
IMPORT int moduleLoadHooksCall ();
IMPORT int moduleNameGet ();
IMPORT int moduleNextSectionGet ();
IMPORT int moduleSectionChecksumSet ();
IMPORT int moduleSectionDescFree ();
IMPORT int moduleSectionDescGet ();
IMPORT int moduleSectionRegister ();
IMPORT int moduleSectionsCksumCompare ();
IMPORT int moduleSectionsFileChecksumSet ();
IMPORT int moduleSegAdd ();
IMPORT int moduleSegEach ();
IMPORT int moduleSegFirst ();
IMPORT int moduleSegGet ();
IMPORT int moduleSegInfoGet ();
IMPORT int moduleSegNext ();
IMPORT int moduleShellCmdInit ();
IMPORT int moduleShow ();
IMPORT int moduleShowInit ();
IMPORT int moduleUndefSymAdd ();
IMPORT int moduleUndefSymEach ();
IMPORT int moduleUnloadHookAdd ();
IMPORT int moduleUnloadHookDelete ();
IMPORT int moduleUnloadHooksCall ();
IMPORT int mountFTL ();
IMPORT int mountValidateSet ();
IMPORT int msgQClassId;
IMPORT int msgQCreate ();
IMPORT int msgQCreateLibInit ();
IMPORT int msgQDelete ();
IMPORT int msgQDestroy ();
IMPORT int msgQEvStart ();
IMPORT int msgQEvStop ();
IMPORT int msgQInfoGet ();
IMPORT int msgQInit ();
IMPORT int msgQInitialize ();
IMPORT int msgQLibInit ();
IMPORT int msgQLibInstalled;
IMPORT int msgQNumMsgs ();
IMPORT int msgQReceive ();
IMPORT int msgQSend ();
IMPORT int msgQSmNumMsgsRtn;
IMPORT int msgQSmReceiveRtn;
IMPORT int msgQSmSendRtn;
IMPORT int msgQTerminate ();
IMPORT int msgQWritable ();
IMPORT int mtdIdentifyTable;
IMPORT int mtdTable;
IMPORT int mutexOptionsHostLib;
IMPORT int mutexOptionsIosLib;
IMPORT int mutexOptionsLogLib;
IMPORT int mutexOptionsNetDrv;
IMPORT int mutexOptionsSelectLib;
IMPORT int mutexOptionsSymLib;
IMPORT int mutexOptionsTyLib;
IMPORT int mux2Bind ();
IMPORT int mux2LibInit ();
IMPORT int mux2OverEndInit ();
IMPORT int mux2OverEndOutputFilterChainDrops;
IMPORT int mux2PollReceive ();
IMPORT int mux2PollSend ();
IMPORT int mux2Send ();
IMPORT int muxAddressForm ();
IMPORT int muxBind ();
IMPORT int muxBindCommon ();
IMPORT int muxBindStyles;
IMPORT int muxCommonInit ();
IMPORT int muxDebug;
IMPORT int muxDevAcquire ();
IMPORT int muxDevConnect_desc;
IMPORT int muxDevExists ();
IMPORT int muxDevLoad ();
IMPORT int muxDevRelease ();
IMPORT int muxDevStart ();
IMPORT int muxDevStop ();
IMPORT int muxDevStopAll ();
IMPORT int muxDevUnload ();
IMPORT int muxDevUnloadAsync ();
IMPORT int muxEndJobQDo ();
IMPORT int muxEndJobQDoJob ();
IMPORT int muxEndListGet ();
IMPORT int muxEndQnumGet ();
IMPORT int muxEndRxJobQueue ();
IMPORT int muxEndStyles;
IMPORT int muxError ();
IMPORT int muxErrorPost ();
IMPORT int muxErrorSkip ();
IMPORT int muxIfTypeGet ();
IMPORT int muxInstallDevStopRebootHook;
IMPORT int muxIoctl ();
IMPORT int muxIpcomPktFreeMblk ();
IMPORT int muxIpcomPktToMblkTx ();
IMPORT int muxL2PortDetachRtn;
IMPORT int muxLibInit ();
IMPORT int muxLinkDownNotify ();
IMPORT int muxLinkHeaderCreate ();
IMPORT int muxLinkUpNotify ();
IMPORT int muxLock;
IMPORT int muxMCastAddrAdd ();
IMPORT int muxMCastAddrDel ();
IMPORT int muxMCastAddrGet ();
IMPORT int muxMblkToIpcomPktMallocDrops;
IMPORT int muxMblkToIpcomPktTx ();
IMPORT int muxMblkToIpcomPktTxChainDrops;
IMPORT int muxPacketAddrGet ();
IMPORT int muxPacketDataGet ();
IMPORT int muxPollReceive ();
IMPORT int muxPollSend ();
IMPORT int muxProtoInfoGet ();
IMPORT int muxProtoListGet ();
IMPORT int muxReceive ();
IMPORT int muxRestoreIpcomPktFromMblkTx ();
IMPORT int muxSend ();
IMPORT int muxShow ();
IMPORT int muxTkBind ();
IMPORT int muxTkCookieGet ();
IMPORT int muxTkDrvCheck ();
IMPORT int muxTkLibInit ();
IMPORT int muxTkOverEndInit ();
IMPORT int muxTkPollReceive ();
IMPORT int muxTkPollSend ();
IMPORT int muxTkSend ();
IMPORT int muxTxRestart ();
IMPORT int muxUnbind ();
IMPORT int mv ();
IMPORT int nae_log ();
IMPORT int namelessPrefix;
IMPORT int nanosleep ();
IMPORT int needCheckRAM;
IMPORT int netAttachFlag;
IMPORT int netBufClOffset;
IMPORT int netBufLibInit ();
IMPORT int netBufLibInitialize ();
IMPORT int netBufLock;
IMPORT int netBufPoolInit ();
IMPORT int netClBlkFree ();
IMPORT int netClBlkGet ();
IMPORT int netClBlkJoin ();
IMPORT int netClFree ();
IMPORT int netClPoolIdGet ();
IMPORT int netClusterGet ();
IMPORT int netDaemonQ ();
IMPORT int netDaemonQnum ();
IMPORT int netDaemonsCount ();
IMPORT int netDaemonsStart ();
IMPORT int netDevBootFlag;
IMPORT int netDevCreate ();
IMPORT int netDevCreate2 ();
IMPORT int netDevCreateEx ();
IMPORT int netDrv ();
IMPORT int netDrvDebugLevelSet ();
IMPORT int netDrvFileDoesNotExist ();
IMPORT int netDrvFileDoesNotExistInstall ();
IMPORT int netErrnoSet ();
IMPORT int netHelp ();
IMPORT int netJobAdd ();
IMPORT int netJobNum;
IMPORT int netJobQueueId;
IMPORT int netLibInitialize ();
IMPORT int netLsByName ();
IMPORT int netMblkChainDup ();
IMPORT int netMblkClChainFree ();
IMPORT int netMblkClFree ();
IMPORT int netMblkClGet ();
IMPORT int netMblkClJoin ();
IMPORT int netMblkDup ();
IMPORT int netMblkFree ();
IMPORT int netMblkFromBufCopy ();
IMPORT int netMblkGet ();
IMPORT int netMblkOffsetToBufCopy ();
IMPORT int netMblkToBufCopy ();
IMPORT int netPoolCreate ();
IMPORT int netPoolCreateValidate ();
IMPORT int netPoolDelete ();
IMPORT int netPoolIdGet ();
IMPORT int netPoolIdGetWork ();
IMPORT int netPoolInit ();
IMPORT int netPoolInitWrapper ();
IMPORT int netPoolKheapInit ();
IMPORT int netPoolNameGet ();
IMPORT int netPoolRelPri;
IMPORT int netPoolRelease ();
IMPORT int netTaskId;
IMPORT int netTaskNamePrefix;
IMPORT int netTaskOptions;
IMPORT int netTaskPriority;
IMPORT int netTaskStackSize;
IMPORT int netTupleFree ();
IMPORT int netTupleGet ();
IMPORT int netVersionString;
IMPORT int netmask;
IMPORT int noDev ();
IMPORT int noOfDrives;
IMPORT int noOfMTDs;
IMPORT int noOfTLs;
IMPORT int ns16550SioRegister ();
IMPORT int ns16550TestChannels ();
IMPORT int ns16550vxbChanSetup ();
IMPORT int ns16550vxbDebugLevel;
IMPORT int ns16550vxbDumpOutputChars ();
IMPORT int ns16550vxbPollEcho ();
IMPORT int ns16550vxbReadInputChars ();
IMPORT int ns16550vxbSioShow ();
IMPORT int ns16550vxbTestOutput ();
IMPORT int numLogFds;
IMPORT int objAlloc ();
IMPORT int objAllocExtra ();
IMPORT int objArchLibInit ();
IMPORT int objClassIdGet ();
IMPORT int objClassTypeGet ();
IMPORT int objContextGet ();
IMPORT int objContextSet ();
IMPORT int objCoreInit ();
IMPORT int objCoreInvalidate ();
IMPORT int objCoreReclaim ();
IMPORT int objCoreTerminate ();
IMPORT int objCoreUnlink ();
IMPORT int objEach ();
IMPORT int objFree ();
IMPORT int objGenericVerify ();
IMPORT int objInfo ();
IMPORT int objInfoInit ();
IMPORT int objLibInit ();
IMPORT int objMemAlloc ();
IMPORT int objMemFree ();
IMPORT int objNameGet ();
IMPORT int objNameLenGet ();
IMPORT int objNamePtrGet ();
IMPORT int objNamePtrSet ();
IMPORT int objNameSet ();
IMPORT int objNameToId ();
IMPORT int objOwnerGet ();
IMPORT int objOwnerLibInstalled;
IMPORT int objOwnerSet ();
IMPORT int objOwnerSetBase ();
IMPORT int objRoutineNameGet ();
IMPORT int objShow ();
IMPORT int objVerify ();
IMPORT int objVerifyError ();
IMPORT int objVerifyMagicRead ();
IMPORT int objVerifyTypeRead ();
IMPORT int objectShow ();
IMPORT int onAssert__ ();
IMPORT int open ();
IMPORT int opendir ();
IMPORT int operation_tip;
IMPORT int oprintf ();
IMPORT int optarg;
IMPORT int opterr;
IMPORT int optind;
IMPORT int optopt;
IMPORT int optreset;
IMPORT int osmGuardPageSize;
IMPORT int pAddrString;
IMPORT int pAsInitParams;
IMPORT int pAsMemDesc;
IMPORT int pBusHead;
IMPORT int pBusListHead;
IMPORT int pChanStructShow ();
IMPORT int pClkCookie;
IMPORT int pClkTimer;
IMPORT int pCoprocDescList;
IMPORT int pDbgClnt;
IMPORT int pDevName;
IMPORT int pDriverListHead;
IMPORT int pEndPktDev;
IMPORT int pHead;
IMPORT int pIosDevCloseRtn;
IMPORT int pIosFdEntrySetRtn;
IMPORT int pIosFdInvalidRtn;
IMPORT int pIosRemovableDevDrv;
IMPORT int pIosSuspendedDevDrv;
IMPORT int pJobPool;
IMPORT int pLoadRoutine;
IMPORT int pLoaderHooksCall;
IMPORT int pM2TrapRtn;
IMPORT int pM2TrapRtnArg;
IMPORT int pMibRtn;
IMPORT int pNetPoolHead;
IMPORT int pNullFd;
IMPORT int pPlbBus;
IMPORT int pPlbDev;
IMPORT int pPlbDevControl;
IMPORT int pRebootHookTbl;
IMPORT int pRootMemStart;
IMPORT int pRtpDbgCmdSvc;
IMPORT int pSockIoctlMemVal;
IMPORT int pSysClkName;
IMPORT int pSysPhysMemDescCortexA8Ext;
IMPORT int pSysPlbMethods;
IMPORT int pTaskLastDspTcb;
IMPORT int pTaskLastFpTcb;
IMPORT int pTgtName;
IMPORT int pTimestampCookie;
IMPORT int pTimestampTimer;
IMPORT int pTimestampTimerName;
IMPORT int pUnixIoctlMemVal;
IMPORT int pUnloaderHooksCall;
IMPORT int pVxbDelayCookie;
IMPORT int pVxbDelayTimer;
IMPORT int pVxbSpinLockGive;
IMPORT int pVxbSpinLockTake;
IMPORT int pWdbClnt;
IMPORT int pWdbCommIf;
IMPORT int pWdbCtxBpIf;
IMPORT int pWdbExternSystemRegs;
IMPORT int pWdbMemRegions;
IMPORT int pWdbRtIf;
IMPORT int pWdbXport;
IMPORT int pWvNetEvtMap;
IMPORT int panic ();
IMPORT int panicSuspend;
IMPORT int partitionExist;
IMPORT int pathBuild ();
IMPORT int pathCat ();
IMPORT int pathCondense ();
IMPORT int pathLastName ();
IMPORT int pathLastNamePtr ();
IMPORT int pathParse ();
IMPORT int pathSplit ();
IMPORT int pathconf ();
IMPORT int pause ();
IMPORT int pc ();
IMPORT int period ();
IMPORT int periodHost ();
IMPORT int periodRun ();
IMPORT int perror ();
IMPORT int pgPoolAddToPool ();
IMPORT int pgPoolAlignedAlloc ();
IMPORT int pgPoolAllocAt ();
IMPORT int pgPoolAvailAlloc ();
IMPORT int pgPoolCreate ();
IMPORT int pgPoolDelete ();
IMPORT int pgPoolFree ();
IMPORT int pgPoolInfoGet ();
IMPORT int pgPoolInit ();
IMPORT int pgPoolLibInit ();
IMPORT int pgPoolNextFreeGet ();
IMPORT int pgPoolPhysAddToPool ();
IMPORT int pgPoolPhysAlignedAlloc ();
IMPORT int pgPoolPhysAlloc ();
IMPORT int pgPoolPhysAllocAt ();
IMPORT int pgPoolPhysAvailAlloc ();
IMPORT int pgPoolPhysFree ();
IMPORT int pgPoolPhysLibInit ();
IMPORT int pgPoolPhysNextFreeGet ();
IMPORT int pgPoolPhysRangeEach ();
IMPORT int pgPoolPhysRangeIsAllocated ();
IMPORT int pgPoolPhysRangeIsFree ();
IMPORT int pgPoolPhysRangeVerify ();
IMPORT int pgPoolPhysRemoveFromPool ();
IMPORT int pgPoolRangeStateCheck ();
IMPORT int pgPoolRangeVerify ();
IMPORT int pgPoolRemoveFromPool ();
IMPORT int pgPoolVirtAddToPool ();
IMPORT int pgPoolVirtAlignedAlloc ();
IMPORT int pgPoolVirtAlloc ();
IMPORT int pgPoolVirtAllocAt ();
IMPORT int pgPoolVirtAvailAlloc ();
IMPORT int pgPoolVirtFree ();
IMPORT int pgPoolVirtLibInit ();
IMPORT int pgPoolVirtNextFreeGet ();
IMPORT int pgPoolVirtRangeEach ();
IMPORT int pgPoolVirtRangeIsAllocated ();
IMPORT int pgPoolVirtRangeIsFree ();
IMPORT int pgPoolVirtRangeVerify ();
IMPORT int pgPoolVirtRemoveFromPool ();
IMPORT int phy1116R_MiiRead ();
IMPORT int phy1116R_MiiWrite ();
IMPORT int phy8511_MiiRead ();
IMPORT int phy8511_MiiWrite ();
IMPORT int phy_read ();
IMPORT int phy_read2 ();
IMPORT int phy_read_all ();
IMPORT int phy_write ();
IMPORT int ping ();
IMPORT int ping2 ();
IMPORT int pingLibInit2 ();
IMPORT int pipeDevCreate ();
IMPORT int pipeDevDelete ();
IMPORT int pipeDrv ();
IMPORT int pipeMsgQOptions;
IMPORT int pl_bitstream_parse ();
IMPORT int plbInit1 ();
IMPORT int plbIntrGet ();
IMPORT int plbIntrSet ();
IMPORT int plbRegister ();
IMPORT int pmtuShow ();
IMPORT int poolBlockAdd ();
IMPORT int poolCreate ();
IMPORT int poolDelete ();
IMPORT int poolFindItem ();
IMPORT int poolFreeCount ();
IMPORT int poolIdListGet ();
IMPORT int poolIncrementGet ();
IMPORT int poolIncrementSet ();
IMPORT int poolInitialize ();
IMPORT int poolItemGet ();
IMPORT int poolItemReturn ();
IMPORT int poolLibInit ();
IMPORT int poolListGbl;
IMPORT int poolTotalCount ();
IMPORT int poolUnusedBlocksFree ();
IMPORT int posixSignalMode;
IMPORT int pow ();
IMPORT int ppGlobalEnviron;
IMPORT int print64 ();
IMPORT int print64Fine ();
IMPORT int print64Mult ();
IMPORT int print64Row ();
IMPORT int printErr ();
IMPORT int printErrno ();
IMPORT int printExc ();
IMPORT int printLogo ();
IMPORT int printf ();
IMPORT int prints ();
IMPORT int priv_targetName;
IMPORT int ps_clock_init_data;
IMPORT int ps_config ();
IMPORT int ps_ddr_init_data;
IMPORT int ps_debug ();
IMPORT int ps_debug_init_data;
IMPORT int ps_init ();
IMPORT int ps_init_2 ();
IMPORT int ps_mio_init_data;
IMPORT int ps_mio_init_data_nfc;
IMPORT int ps_peripherals_init_data;
IMPORT int ps_peripherals_init_data_nfc;
IMPORT int ps_pll_init_data;
IMPORT int ps_post_config ();
IMPORT int ps_post_config_init_data;
IMPORT int ps_post_init_data;
IMPORT int psrShow ();
IMPORT int ptyDevCreate ();
IMPORT int ptyDevRemove ();
IMPORT int ptyDrv ();
IMPORT int putc ();
IMPORT int putchar ();
IMPORT int putenv ();
IMPORT int puts ();
IMPORT int putw ();
IMPORT int pwd ();
IMPORT int qFifoClass;
IMPORT int qFifoClassId;
IMPORT int qFifoEach ();
IMPORT int qFifoGet ();
IMPORT int qFifoInfo ();
IMPORT int qFifoInit ();
IMPORT int qFifoNext ();
IMPORT int qFifoPut ();
IMPORT int qFifoRemove ();
IMPORT int qFifoResort ();
IMPORT int qFifoRestore ();
IMPORT int qPriBMapClassId;
IMPORT int qPriBMapEach ();
IMPORT int qPriBMapGet ();
IMPORT int qPriBMapInfo ();
IMPORT int qPriBMapInit ();
IMPORT int qPriBMapKey ();
IMPORT int qPriBMapNext ();
IMPORT int qPriBMapPut ();
IMPORT int qPriBMapRemove ();
IMPORT int qPriBMapResort ();
IMPORT int qPriBMapRestore ();
IMPORT int qPriBMapSet ();
IMPORT int qPriDeltaAdvance ();
IMPORT int qPriDeltaClassId;
IMPORT int qPriDeltaEach ();
IMPORT int qPriDeltaGet ();
IMPORT int qPriDeltaGetExpired ();
IMPORT int qPriDeltaInfo ();
IMPORT int qPriDeltaInit ();
IMPORT int qPriDeltaKey ();
IMPORT int qPriDeltaNext ();
IMPORT int qPriDeltaPut ();
IMPORT int qPriDeltaRemove ();
IMPORT int qPriDeltaResort ();
IMPORT int qPriListClassId;
IMPORT int qPriListEach ();
IMPORT int qPriListFromTailClassId;
IMPORT int qPriListGet ();
IMPORT int qPriListInfo ();
IMPORT int qPriListInit ();
IMPORT int qPriListKey ();
IMPORT int qPriListNext ();
IMPORT int qPriListPut ();
IMPORT int qPriListPutFromTail ();
IMPORT int qPriListRemove ();
IMPORT int qPriListResort ();
IMPORT int qTradPriBMapClassId;
IMPORT int qTradPriBMapSetCompatible ();
IMPORT int qTradPriListClassId;
IMPORT int qTradPriListSetCompatible ();
IMPORT int qsort ();
IMPORT int qspiCtrl_Clr_RcvFifo ();
IMPORT int qspiCtrl_CmdExecute ();
IMPORT int qspiCtrl_FastRcv_Setup ();
IMPORT int qspiCtrl_FastSnd_Setup ();
IMPORT int qspiCtrl_Rd_CfgReg ();
IMPORT int qspiCtrl_Rd_Fifo ();
IMPORT int qspiCtrl_Reset ();
IMPORT int qspiCtrl_SetFlashMode ();
IMPORT int qspiCtrl_Set_3B_AddrMode ();
IMPORT int qspiCtrl_Set_4B_AddrMode ();
IMPORT int qspiCtrl_Set_BaudRate ();
IMPORT int qspiCtrl_Set_BytesMode ();
IMPORT int qspiCtrl_Set_CaptureDelay ();
IMPORT int qspiCtrl_Wait_BusIdle ();
IMPORT int qspiCtrl_Wait_ExeOk ();
IMPORT int qspiCtrl_Wr_CfgReg ();
IMPORT int qspiCtrl_Wr_Fifo ();
IMPORT int qspiCtrl_params_init ();
IMPORT int qspiFlashInit1 ();
IMPORT int qspiFlashInit2 ();
IMPORT int qspiFlash_Clr_FlagStatus ();
IMPORT int qspiFlash_Enter_4BAddr ();
IMPORT int qspiFlash_Erase_Chip ();
IMPORT int qspiFlash_Erase_Sect ();
IMPORT int qspiFlash_Exit_4BAddr ();
IMPORT int qspiFlash_Get_FlagStatus ();
IMPORT int qspiFlash_Get_QuadMode ();
IMPORT int qspiFlash_Get_Reg16 ();
IMPORT int qspiFlash_Get_Reg8 ();
IMPORT int qspiFlash_Get_RegStatus1 ();
IMPORT int qspiFlash_Get_Segment ();
IMPORT int qspiFlash_Offset_LogtoPhy ();
IMPORT int qspiFlash_PageIdx_LogtoPhy ();
IMPORT int qspiFlash_ParseInfo_2 ();
IMPORT int qspiFlash_RcvBytes_Direct ();
IMPORT int qspiFlash_RcvBytes_Direct_tffs ();
IMPORT int qspiFlash_RcvBytes_Indirect ();
IMPORT int qspiFlash_RcvBytes_Indirect_tffs ();
IMPORT int qspiFlash_ReadBytes_Direct0 ();
IMPORT int qspiFlash_ReadBytes_Direct0_tffs ();
IMPORT int qspiFlash_ReadBytes_InDirect0 ();
IMPORT int qspiFlash_ReadBytes_InDirect0_tffs ();
IMPORT int qspiFlash_ReadId ();
IMPORT int qspiFlash_ReadId_2 ();
IMPORT int qspiFlash_ReadId_3 ();
IMPORT int qspiFlash_Read_Page ();
IMPORT int qspiFlash_Read_Sect ();
IMPORT int qspiFlash_Reset_Flash ();
IMPORT int qspiFlash_Rx_Data ();
IMPORT int qspiFlash_SectIdx_LogtoPhy ();
IMPORT int qspiFlash_SectIdx_LogtoPhy_Only ();
IMPORT int qspiFlash_Set_QuadMode ();
IMPORT int qspiFlash_Set_Reg16 ();
IMPORT int qspiFlash_Set_Reg8 ();
IMPORT int qspiFlash_Set_Seg_0_16M ();
IMPORT int qspiFlash_Set_Seg_16_32M ();
IMPORT int qspiFlash_Set_Seg_32_48M ();
IMPORT int qspiFlash_Set_Seg_48_64M ();
IMPORT int qspiFlash_Set_Segment ();
IMPORT int qspiFlash_SndBytes_Direct ();
IMPORT int qspiFlash_SndBytes_Direct_2 ();
IMPORT int qspiFlash_SndBytes_Direct_tffs ();
IMPORT int qspiFlash_SndBytes_Indirect ();
IMPORT int qspiFlash_SndBytes_Indirect_tffs ();
IMPORT int qspiFlash_Tx_Data ();
IMPORT int qspiFlash_UnLock_Flash_Ctrl0 ();
IMPORT int qspiFlash_Unlock_Flash ();
IMPORT int qspiFlash_WREN_Cmd ();
IMPORT int qspiFlash_Wait_FSR_Ok ();
IMPORT int qspiFlash_Wait_FlashReady ();
IMPORT int qspiFlash_Wait_WIP_Ok ();
IMPORT int qspiFlash_WriteBytes_Direct0 ();
IMPORT int qspiFlash_WriteBytes_Direct0_tffs ();
IMPORT int qspiFlash_WriteBytes_InDirect0 ();
IMPORT int qspiFlash_WriteBytes_InDirect0_tffs ();
IMPORT int qspiFlash_Write_Page ();
IMPORT int qspiFlash_Write_Sect ();
IMPORT int qspi_erase_ipaddr ();
IMPORT int qspi_get_ipaddr ();
IMPORT int r0 ();
IMPORT int r1 ();
IMPORT int r10 ();
IMPORT int r11 ();
IMPORT int r12 ();
IMPORT int r13 ();
IMPORT int r14 ();
IMPORT int r2 ();
IMPORT int r3 ();
IMPORT int r4 ();
IMPORT int r5 ();
IMPORT int r6 ();
IMPORT int r7 ();
IMPORT int r8 ();
IMPORT int r9 ();
IMPORT int raise ();
IMPORT int rand ();
IMPORT int rawFsBioBufferSize;
IMPORT int rawFsDevInit ();
IMPORT int rawFsDrvNum;
IMPORT int rawFsFdListMutexOptions;
IMPORT int rawFsFdMutexOptions;
IMPORT int rawFsInit ();
IMPORT int rawFsVolMutexOptions;
IMPORT int rawFsVolUnmount ();
IMPORT int rcmd ();
IMPORT int rcmd_af ();
IMPORT int read ();
IMPORT int read32 ();
IMPORT int read32p ();
IMPORT int read_all_flag;
IMPORT int readdir ();
IMPORT int readdir_r ();
IMPORT int readv ();
IMPORT int readyQBMap;
IMPORT int readyQHead;
IMPORT int realloc ();
IMPORT int reboot ();
IMPORT int reboot2 ();
IMPORT int reboot3 ();
IMPORT int reboot4 ();
IMPORT int rebootHookAdd ();
IMPORT int rebootHookDelete ();
IMPORT int rebootHookTbl;
IMPORT int rebootHookTblSize;
IMPORT int recv ();
IMPORT int recvfrom ();
IMPORT int recvmsg ();
IMPORT int regprint ();
IMPORT int reld ();
IMPORT int remCurIdGet ();
IMPORT int remCurIdSet ();
IMPORT int remLastResvPort;
IMPORT int remLibInit ();
IMPORT int remNumConnRetrials;
IMPORT int remPasswd;
IMPORT int remStdErrSetupTimeout;
IMPORT int remUser;
IMPORT int remove ();
IMPORT int rename ();
IMPORT int repeat ();
IMPORT int repeatHost ();
IMPORT int repeatRun ();
IMPORT int reschedule ();
IMPORT int restartTaskName;
IMPORT int restartTaskOptions;
IMPORT int restartTaskPriority;
IMPORT int restartTaskStackSize;
IMPORT int retran_noprs;
IMPORT int retran_notmr;
IMPORT int rewind ();
IMPORT int rewinddir ();
IMPORT int rindex ();
IMPORT int ring_buffer_dequeue ();
IMPORT int ring_buffer_dequeue_arr ();
IMPORT int ring_buffer_init ();
IMPORT int ring_buffer_peek ();
IMPORT int ring_buffer_queue ();
IMPORT int ring_buffer_queue_arr ();
IMPORT int rm ();
IMPORT int rmdir ();
IMPORT int rngBufGet ();
IMPORT int rngBufPut ();
IMPORT int rngCreate ();
IMPORT int rngDelete ();
IMPORT int rngFlush ();
IMPORT int rngFreeBytes ();
IMPORT int rngIsEmpty ();
IMPORT int rngIsFull ();
IMPORT int rngMoveAhead ();
IMPORT int rngNBytes ();
IMPORT int rngPutAhead ();
IMPORT int rootMemNBytes;
IMPORT int rootTaskId;
IMPORT int roundRobinHookInstalled;
IMPORT int roundRobinOn;
IMPORT int roundRobinSlice;
IMPORT int rresvport ();
IMPORT int rresvportCommon ();
IMPORT int rresvport_af ();
IMPORT int rtpCodeSize;
IMPORT int rtpCodeStart;
IMPORT int rtpDeleteMsg;
IMPORT int rtpSigDeleteMsg;
IMPORT int rtpSigStopMsg;
IMPORT int rtpStopMsg;
IMPORT char * runtimeName;
IMPORT char * runtimeVersion;
IMPORT char * runtimeVersionFull;
IMPORT int s ();
IMPORT int scalbn ();
IMPORT int scanCharSet ();
IMPORT int scanField ();
IMPORT int scanf ();
IMPORT int sdACmdClrCardDetect ();
IMPORT int sdACmdSendOpCond ();
IMPORT int sdACmdSendScr ();
IMPORT int sdACmdSendSsr ();
IMPORT int sdACmdSetBusWidth ();
IMPORT int sdACmdSwitchFunc ();
IMPORT int sdBusAnnounceDevices ();
IMPORT int sdBusCtlrInterruptInfo_desc;
IMPORT int sdCmdAllSendCid ();
IMPORT int sdCmdAppCmd ();
IMPORT int sdCmdDeselectCard ();
IMPORT int sdCmdGoIdleState ();
IMPORT int sdCmdGoInactiveState ();
IMPORT int sdCmdIssue ();
IMPORT int sdCmdReadBlock ();
IMPORT int sdCmdReadMultipleBlock ();
IMPORT int sdCmdReadSingleBlock ();
IMPORT int sdCmdSelectCard ();
IMPORT int sdCmdSendCid ();
IMPORT int sdCmdSendCsd ();
IMPORT int sdCmdSendIfCond ();
IMPORT int sdCmdSendRelativeAddr ();
IMPORT int sdCmdSendStatus ();
IMPORT int sdCmdSetBlockLen ();
IMPORT int sdCmdSetDsr ();
IMPORT int sdCmdStopTransmission ();
IMPORT int sdCmdSwitchVoltage ();
IMPORT int sdCmdWriteBlock ();
IMPORT int sdCmdWriteMultipleBlock ();
IMPORT int sdCmdWriteSingleBlock ();
IMPORT int sdMmcCmdSendOpCond ();
IMPORT int sdMmcCmdSetRelativeAddr ();
IMPORT int sdRegister ();
IMPORT int sdhcDbgMask;
IMPORT int sdioCmdIoRwDirect ();
IMPORT int sdioCmdIoRwExtend ();
IMPORT int sdioCmdIoSendOpCond ();
IMPORT int sdmmc_get_baseAddr ();
IMPORT int sdmmc_res_len;
IMPORT int sectorChecksum ();
IMPORT int sectorChecksumWrite ();
IMPORT int selNodeAdd ();
IMPORT int selNodeDelete ();
IMPORT int selTaskDeleteHookAdd ();
IMPORT int selWakeup ();
IMPORT int selWakeupAll ();
IMPORT int selWakeupListInit ();
IMPORT int selWakeupListLen ();
IMPORT int selWakeupListTerm ();
IMPORT int selWakeupType ();
IMPORT int select ();
IMPORT int selectInit ();
IMPORT int semBCreate ();
IMPORT int semBGive ();
IMPORT int semBGiveDefer ();
IMPORT int semBGiveNoLock ();
IMPORT int semBGiveScalable ();
IMPORT int semBInit ();
IMPORT int semBInitialize ();
IMPORT int semBTake ();
IMPORT int semBTakeNoLock ();
IMPORT int semBTakeScalable ();
IMPORT int semCCreate ();
IMPORT int semCGive ();
IMPORT int semCGiveDefer ();
IMPORT int semCInit ();
IMPORT int semCInitialize ();
IMPORT int semCTake ();
IMPORT int semClass;
IMPORT int semClassId;
IMPORT int semCreateTbl;
IMPORT int semDelete ();
IMPORT int semDeleteLibInit ();
IMPORT int semDestroy ();
IMPORT int semEvIsFreeTbl;
IMPORT int semEvStart ();
IMPORT int semEvStop ();
IMPORT int semFlush ();
IMPORT int semFlushDefer ();
IMPORT int semFlushDeferTbl;
IMPORT int semFlushTbl;
IMPORT int semGive ();
IMPORT int semGiveDefer ();
IMPORT int semGiveDeferTbl;
IMPORT int semGiveNoLockTbl;
IMPORT int semGiveTbl;
IMPORT int semInfo ();
IMPORT int semInfoGet ();
IMPORT int semIntRestrict ();
IMPORT int semInvalid ();
IMPORT int semLibInit ();
IMPORT int semLocalIdVerify ();
IMPORT int semMCreate ();
IMPORT int semMGive ();
IMPORT int semMGiveForce ();
IMPORT int semMGiveKernWork ();
IMPORT int semMGiveNoLock ();
IMPORT int semMGiveScalable ();
IMPORT int semMInit ();
IMPORT int semMInitialize ();
IMPORT int semMPendQPut ();
IMPORT int semMTake ();
IMPORT int semMTakeByProxy ();
IMPORT int semMTakeNoLock ();
IMPORT int semMTakeScalable ();
IMPORT int semQFlush ();
IMPORT int semQFlushDefer ();
IMPORT int semQInit ();
IMPORT int semRTake ();
IMPORT int semRWCreate ();
IMPORT int semRWGive ();
IMPORT int semRWGiveForce ();
IMPORT int semRWInitialize ();
IMPORT int semRWLibMaxReaders;
IMPORT int semShow ();
IMPORT int semShowInit ();
IMPORT int semSync_mmc;
IMPORT int semTake ();
IMPORT int semTakeNoLockTbl;
IMPORT int semTakeTbl;
IMPORT int semTerminate ();
IMPORT int semWTake ();
IMPORT int send ();
IMPORT int send_full;
IMPORT int send_xon_xoff_char ();
IMPORT int sendmsg ();
IMPORT int sendto ();
IMPORT int setAlt ();
IMPORT int setFpt ();
IMPORT int setbuf ();
IMPORT int setbuffer ();
IMPORT int sethostname ();
IMPORT int setjmp ();
IMPORT int setlinebuf ();
IMPORT int setlocale ();
IMPORT int setsockopt ();
IMPORT int settimeofday ();
IMPORT int setvbuf ();
IMPORT int sfpDoubleNormalize ();
IMPORT int sfpDoubleNormalize2 ();
IMPORT int sfpDoubleSetup ();
IMPORT int sfpFloatNormalize ();
IMPORT int sfpFloatSetup ();
IMPORT int shConfig ();
IMPORT int sha1_block_data_order ();
IMPORT int sha1_block_host_order ();
IMPORT int sha256_block_data_order ();
IMPORT int sha256_block_host_order ();
IMPORT int shellAbort ();
IMPORT int shellAbortHandledByShell ();
IMPORT int shellActivate ();
IMPORT int shellBackgroundInit ();
IMPORT int shellBackgroundRead ();
IMPORT int shellCmdAdd ();
IMPORT int shellCmdAliasAdd ();
IMPORT int shellCmdAliasArrayAdd ();
IMPORT int shellCmdAliasDelete ();
IMPORT int shellCmdAliasShow ();
IMPORT int shellCmdArrayAdd ();
IMPORT int shellCmdCheck ();
IMPORT int shellCmdExec ();
IMPORT int shellCmdInfoArgsStore ();
IMPORT int shellCmdInfoCmdLineStore ();
IMPORT int shellCmdInfoFinalNameStore ();
IMPORT int shellCmdInfoGet ();
IMPORT int shellCmdInfoInitialNameStore ();
IMPORT int shellCmdInit ();
IMPORT int shellCmdMatchingAliasListGet ();
IMPORT int shellCmdMatchingCmdListGet ();
IMPORT int shellCmdMemRegister ();
IMPORT int shellCmdMemUnregister ();
IMPORT int shellCmdPreParseAdd ();
IMPORT int shellCmdPreParsedGet ();
IMPORT int shellCmdStatementExec ();
IMPORT int shellCmdStatementSplit ();
IMPORT int shellCmdSymTabIdGet ();
IMPORT int shellCmdTaskIdConvert ();
IMPORT int shellCmdTopicAdd ();
IMPORT int shellCompatibleCheck ();
IMPORT int shellCompatibleSet ();
IMPORT int shellCompletionPathnameGet ();
IMPORT int shellConfigDefaultGet ();
IMPORT int shellConfigDefaultSet ();
IMPORT int shellConfigDefaultValueGet ();
IMPORT int shellConfigDefaultValueSet ();
IMPORT int shellConfigDefaultValueUnset ();
IMPORT int shellConfigGet ();
IMPORT int shellConfigLibInit ();
IMPORT int shellConfigSet ();
IMPORT int shellConfigValueGet ();
IMPORT int shellConfigValueSet ();
IMPORT int shellConfigValueUnset ();
IMPORT int shellConsoleInit ();
IMPORT int shellConsoleTaskId;
IMPORT int shellContextFinalize ();
IMPORT int shellContextInit ();
IMPORT int shellContextListLock ();
IMPORT int shellContextListUnlock ();
IMPORT int shellDataAdd ();
IMPORT int shellDataAllRemove ();
IMPORT int shellDataFirst ();
IMPORT int shellDataFromNameAdd ();
IMPORT int shellDataFromNameGet ();
IMPORT int shellDataGet ();
IMPORT int shellDataNext ();
IMPORT int shellDataRemove ();
IMPORT int shellErrnoGet ();
IMPORT int shellErrnoSet ();
IMPORT int shellExec ();
IMPORT int shellExitWrapper ();
IMPORT int shellFirst ();
IMPORT int shellFromNameGet ();
IMPORT int shellFromTaskGet ();
IMPORT int shellFromTaskParentContextGet ();
IMPORT int shellGenericCreate ();
IMPORT int shellGenericInit ();
IMPORT int shellHistory ();
IMPORT int shellIOStdGet ();
IMPORT int shellIOStdSet ();
IMPORT int shellIdVerify ();
IMPORT int shellInOutBgndClose ();
IMPORT int shellInOutBgndGet ();
IMPORT int shellInOutBgndIoClose ();
IMPORT int shellInOutBgndOpen ();
IMPORT int shellInOutBgndRegister ();
IMPORT int shellInOutBlockingBlock ();
IMPORT int shellInOutBlockingBlockedDataGet ();
IMPORT int shellInOutBlockingClose ();
IMPORT int shellInOutBlockingDataSet ();
IMPORT int shellInOutBlockingGet ();
IMPORT int shellInOutBlockingOnDataClose ();
IMPORT int shellInOutBlockingOpen ();
IMPORT int shellInOutBlockingUnblock ();
IMPORT int shellInOutInitialGet ();
IMPORT int shellInOutInputHookAdd ();
IMPORT int shellInOutInputHookDelete ();
IMPORT int shellInOutInputHookSet ();
IMPORT int shellInOutInputHookUnset ();
IMPORT int shellInOutInputUniqueCheck ();
IMPORT int shellInOutMasterPtyGet ();
IMPORT int shellInOutRedirectClose ();
IMPORT int shellInOutRedirectOpen ();
IMPORT int shellInOutRedirectRestore ();
IMPORT int shellInOutRedirectScript ();
IMPORT int shellInOutRedirectSet ();
IMPORT int shellInOutSet ();
IMPORT int shellInOutSlavePtyGet ();
IMPORT int shellInOutUse ();
IMPORT int shellInternalArgStackAllocate ();
IMPORT int shellInternalArgumentEval ();
IMPORT int shellInternalDataSymbolGet ();
IMPORT int shellInternalDecValueDisplay ();
IMPORT int shellInternalFuncDoubleArgAdd ();
IMPORT int shellInternalFuncFloatArgAdd ();
IMPORT int shellInternalFuncLLongArgAdd ();
IMPORT int shellInternalFuncLongArgAdd ();
IMPORT int shellInternalFunctionCall ();
IMPORT int shellInternalHexValueDisplay ();
IMPORT int shellInternalKernelSymbolCreate ();
IMPORT int shellInternalOptFree ();
IMPORT int shellInternalOptGet ();
IMPORT int shellInternalStrSpaceTokenize ();
IMPORT int shellInternalStrToChar ();
IMPORT int shellInternalStrToFloat ();
IMPORT int shellInternalStrToInt ();
IMPORT int shellInternalStrToInt2 ();
IMPORT int shellInternalStrToInt32 ();
IMPORT int shellInternalStrToLong ();
IMPORT int shellInternalStrTokenize ();
IMPORT int shellInternalStrUnquote ();
IMPORT int shellInternalSymTblFromRtpGet ();
IMPORT int shellInternalSymTblFromTaskGet ();
IMPORT int shellInternalSymbolDisplay ();
IMPORT int shellInternalSymbolGet ();
IMPORT int shellInternalSymbolsResolve ();
IMPORT int shellInternalTaskNameMatch ();
IMPORT int shellInternalTextSymbolGet ();
IMPORT int shellInternalValueDisplay ();
IMPORT int shellInterpByNameFind ();
IMPORT int shellInterpCInit ();
IMPORT int shellInterpC_create_buffer ();
IMPORT int shellInterpC_delete_buffer ();
IMPORT int shellInterpC_flush_buffer ();
IMPORT int shellInterpC_init_buffer ();
IMPORT int shellInterpC_load_buffer_state ();
IMPORT int shellInterpC_scan_buffer ();
IMPORT int shellInterpC_scan_bytes ();
IMPORT int shellInterpC_scan_string ();
IMPORT int shellInterpC_switch_to_buffer ();
IMPORT int shellInterpCin;
IMPORT int shellInterpCleng;
IMPORT int shellInterpClex ();
IMPORT int shellInterpCmdInit ();
IMPORT int shellInterpCmdLibInit ();
IMPORT int shellInterpCout;
IMPORT int shellInterpCparse ();
IMPORT int shellInterpCrestart ();
IMPORT int shellInterpCtext;
IMPORT int shellInterpCtxCreate ();
IMPORT int shellInterpCtxGet ();
IMPORT int shellInterpDefaultNameGet ();
IMPORT int shellInterpDelete ();
IMPORT int shellInterpEvaluate ();
IMPORT int shellInterpLibInit ();
IMPORT int shellInterpNameGet ();
IMPORT int shellInterpPromptDftSet ();
IMPORT int shellInterpPromptGet ();
IMPORT int shellInterpPromptSet ();
IMPORT int shellInterpRegister ();
IMPORT int shellInterpRestart ();
IMPORT int shellInterpSet ();
IMPORT int shellInterpSwitch ();
IMPORT int shellLibInit ();
IMPORT int shellLineLenGet ();
IMPORT int shellLock ();
IMPORT int shellLoginInstall ();
IMPORT int shellLogout ();
IMPORT int shellLogout2 ();
IMPORT int shellLogoutInstall ();
IMPORT int shellMaxSessionsSet ();
IMPORT int shellMemAllRegFree ();
IMPORT int shellMemCalloc ();
IMPORT int shellMemFree ();
IMPORT int shellMemLibInit ();
IMPORT int shellMemMalloc ();
IMPORT int shellMemRealloc ();
IMPORT int shellMemRegAllFree ();
IMPORT int shellMemRegFree ();
IMPORT int shellMemRegMalloc ();
IMPORT int shellMemRegister ();
IMPORT int shellMemStrdup ();
IMPORT int shellMemStringAdd ();
IMPORT int shellMemStringFree ();
IMPORT int shellMemStringIsAllocated ();
IMPORT int shellMemStringShow ();
IMPORT int shellMemUnregister ();
IMPORT int shellNext ();
IMPORT int shellOutputLock ();
IMPORT int shellOutputUnlock ();
IMPORT int shellParserControl ();
IMPORT int shellPrint ();
IMPORT int shellPrintErr ();
IMPORT int shellPromptFmtDftSet ();
IMPORT int shellPromptFmtSet ();
IMPORT int shellPromptFmtStrAdd ();
IMPORT int shellPromptLibInit ();
IMPORT int shellPromptPrint ();
IMPORT int shellPromptSet ();
IMPORT int shellRemoteConfigStr;
IMPORT int shellResourceReleaseHookAdd ();
IMPORT int shellRestart ();
IMPORT int shellScriptAbort ();
IMPORT int shellScriptNoAbort ();
IMPORT int shellTask ();
IMPORT int shellTaskDefaultBaseNameGet ();
IMPORT int shellTaskDefaultBaseNameSet ();
IMPORT int shellTaskDefaultOptionsGet ();
IMPORT int shellTaskDefaultOptionsSet ();
IMPORT int shellTaskDefaultPriorityGet ();
IMPORT int shellTaskDefaultPrioritySet ();
IMPORT int shellTaskDefaultStackSizeGet ();
IMPORT int shellTaskDefaultStackSizeSet ();
IMPORT int shellTaskGet ();
IMPORT int shellTaskIdDefault ();
IMPORT int shellTerminate ();
IMPORT int shellWorkingMemCtxAttach ();
IMPORT int shellWorkingMemCtxAttachedShow ();
IMPORT int shellWorkingMemCtxCurrentGet ();
IMPORT int shellWorkingMemCtxCurrentSet ();
IMPORT int shellWorkingMemCtxDetach ();
IMPORT int shellWorkingMemCtxDuplicate ();
IMPORT int shellWorkingMemCtxGet ();
IMPORT int shellWorkingMemCtxIdConvert ();
IMPORT int shellWorkingMemCtxLastGet ();
IMPORT int shellWorkingMemCtxRtnSet ();
IMPORT int show ();
IMPORT int showLoggerInfo ();
IMPORT int shutdown ();
IMPORT int sigEvtRtn;
IMPORT int sigInit ();
IMPORT int sigPendDestroy ();
IMPORT int sigPendInit ();
IMPORT int sigPendKill ();
IMPORT int sigaction ();
IMPORT int sigaddset ();
IMPORT int sigblock ();
IMPORT int sigdelset ();
IMPORT int sigemptyset ();
IMPORT int sigeventCreate ();
IMPORT int sigeventDelete ();
IMPORT int sigeventInit ();
IMPORT int sigeventLibInit ();
IMPORT int sigeventNotify ();
IMPORT int sigeventSigOverrunGet ();
IMPORT int sigfillset ();
IMPORT int sigismember ();
IMPORT int signal ();
IMPORT int sigpending ();
IMPORT int sigprocmask ();
IMPORT int sigqueue ();
IMPORT int sigqueueInit ();
IMPORT int sigreturn ();
IMPORT int sigsetjmp ();
IMPORT int sigsetmask ();
IMPORT int sigsuspend ();
IMPORT int sigtimedwait ();
IMPORT int sigvec ();
IMPORT int sigwait ();
IMPORT int sigwaitinfo ();
IMPORT int sin ();
IMPORT int sinh ();
IMPORT int sioChanConnect_desc;
IMPORT int sioChanGet_desc;
IMPORT int sioEnable_desc;
IMPORT int sioIntEnable_desc;
IMPORT int sioNextChannelNumberAssign ();
IMPORT int sizeNodesAlloc ();
IMPORT int slcrRegs_Config ();
IMPORT int slcr_DisableCAN ();
IMPORT int slcr_EnableCAN ();
IMPORT int slcr_ResetCAN ();
IMPORT int slcr_gem_reset ();
IMPORT int slcr_read ();
IMPORT int slcr_show ();
IMPORT int slcr_write ();
IMPORT int sleep ();
IMPORT int sllCount ();
IMPORT SL_NODE *sllEach ();
IMPORT SL_NODE *sllGet ();
IMPORT int sllInit ();
IMPORT SL_NODE *sllPrevious ();
IMPORT void sllPutAtHead ();
IMPORT void sllPutAtTail ();
IMPORT void sllRemove ();
IMPORT int sllTerminate ();
IMPORT int smObjPoolMinusOne;
IMPORT int smObjTaskDeleteFailRtn;
IMPORT int smObjTcbFreeFailRtn;
IMPORT int smObjTcbFreeRtn;
IMPORT int snprintf ();
IMPORT int so ();
IMPORT int sockInfo ();
IMPORT int sockLibAdd ();
IMPORT int sockLibInit ();
IMPORT int sockLibMap;
IMPORT int sockShow ();
IMPORT int socket ();
IMPORT int socketDevHdr;
IMPORT int socket_send_to_middle ();
IMPORT int sp ();
IMPORT int spTaskOptions;
IMPORT int spTaskPriority;
IMPORT int spTaskStackSize;
IMPORT int spiCtrl_DisIRQ ();
IMPORT int spiCtrl_Disable ();
IMPORT int spiCtrl_Enable ();
IMPORT int spiCtrl_IP_Loop ();
IMPORT int spiCtrl_Init_Master ();
IMPORT int spiCtrl_Init_Slave ();
IMPORT int spiCtrl_RcvFifo_Poll ();
IMPORT int spiCtrl_Rd_CfgReg32 ();
IMPORT int spiCtrl_Reset ();
IMPORT int spiCtrl_SLCR_Loop ();
IMPORT int spiCtrl_Set_Baud_Mst ();
IMPORT int spiCtrl_Set_DMARxLvl ();
IMPORT int spiCtrl_Set_DMATxLvl ();
IMPORT int spiCtrl_Set_FrmLen ();
IMPORT int spiCtrl_Set_LoopBack ();
IMPORT int spiCtrl_Set_Master ();
IMPORT int spiCtrl_Set_PeerSlave ();
IMPORT int spiCtrl_Set_RcvFrmNum ();
IMPORT int spiCtrl_Set_RxFifoFullLvl ();
IMPORT int spiCtrl_Set_SckMode ();
IMPORT int spiCtrl_Set_Slave ();
IMPORT int spiCtrl_Set_TxFiFoEmptyLvl ();
IMPORT int spiCtrl_Set_XfrMode ();
IMPORT int spiCtrl_Set_enSlvTxd ();
IMPORT int spiCtrl_SndFifo_Poll ();
IMPORT int spiCtrl_Wr_CfgReg32 ();
IMPORT int spiCtrl_X_Loop ();
IMPORT int spiSlcr_Set_SpiClk ();
IMPORT int spiSlcr_Set_SpiLoop ();
IMPORT int spinLockIsrGive ();
IMPORT int spinLockIsrInit ();
IMPORT int spinLockIsrTake ();
IMPORT int spinLockRestrict ();
IMPORT int spinLockTaskGive ();
IMPORT int spinLockTaskInit ();
IMPORT int spinLockTaskTake ();
IMPORT int sprintf ();
IMPORT int spy ();
IMPORT int spyClkStart ();
IMPORT int spyClkStop ();
IMPORT int spyHelp ();
IMPORT int spyReport ();
IMPORT int spyStop ();
IMPORT int spyTask ();
IMPORT int sqrt ();
IMPORT int srand ();
IMPORT int sscanf ();
IMPORT int stat ();
IMPORT int statSymTbl;
IMPORT int state_work;
IMPORT int statfs ();
IMPORT int statfs64 ();
IMPORT int stdioFp ();
IMPORT int stdioFpCreate ();
IMPORT int stdioFpDestroy ();
IMPORT int stdioInit ();
IMPORT int stopApplLogger ();
IMPORT int strFree ();
IMPORT int strcasecmp ();
IMPORT int strcat ();
IMPORT int strchr ();
IMPORT int strcmp ();
IMPORT int strcoll ();
IMPORT int strcpy ();
IMPORT int strcspn ();
IMPORT int strdup ();
IMPORT int strerror ();
IMPORT int strerrorIf ();
IMPORT int strerror_r ();
IMPORT int strftime ();
IMPORT int strlcpy ();
IMPORT int strlen ();
IMPORT int strncasecmp ();
IMPORT int strncat ();
IMPORT int strncmp ();
IMPORT int strncpy ();
IMPORT int strpbrk ();
IMPORT int strrchr ();
IMPORT int strspn ();
IMPORT int strstr ();
IMPORT int strtod ();
IMPORT int strtok ();
IMPORT int strtok_r ();
IMPORT int strtol ();
IMPORT int strtoul ();
IMPORT int strxfrm ();
IMPORT int substrcmp ();
IMPORT int swab ();
IMPORT int swap_hex32_2 ();
IMPORT int symAdd ();
IMPORT int symByCNameFind ();
IMPORT int symByValueAndTypeFind ();
IMPORT int symByValueFind ();
IMPORT int symEach ();
IMPORT int symEachCall ();
IMPORT int symFind ();
IMPORT int symFindByName ();
IMPORT int symFindByNameAndType ();
IMPORT int symFindByValue ();
IMPORT int symFindByValueAndType ();
IMPORT int symFindSymbol ();
IMPORT int symFree ();
IMPORT int symGroupDefault;
IMPORT int symLibInit ();
IMPORT int symListGet ();
IMPORT int symLkupPgSz;
IMPORT int symNameGet ();
IMPORT int symRegister ();
IMPORT int symRemove ();
IMPORT int symShellCmdInit ();
IMPORT int symShow ();
IMPORT int symShowInit ();
IMPORT int symTblAdd ();
IMPORT int symTblCreate ();
IMPORT int symTblDelete ();
IMPORT int symTblRemove ();
IMPORT int symTblShutdown ();
IMPORT int symTblSymSetRemove ();
IMPORT int symTypeGet ();
IMPORT int symTypeToStringConvert ();
IMPORT int symValueGet ();
IMPORT int syncLoadRtn;
IMPORT int syncSymAddRtn;
IMPORT int syncSymRemoveRtn;
IMPORT int syncUnldRtn;
IMPORT int sysAdaEnable;
IMPORT int sysAxiReadLong ();
IMPORT int sysAxiWriteLong ();
IMPORT int sysBootFile;
IMPORT int sysBootHost;
IMPORT int sysBootLine;
IMPORT int sysBootParams;
IMPORT int sysBspDevFilter_desc;
IMPORT int sysBspRev ();
IMPORT int sysBus;
IMPORT int sysCacheLibInit;
IMPORT int sysClkConnect ();
IMPORT int sysClkDevUnitNo;
IMPORT int sysClkDisable ();
IMPORT int sysClkEnable ();
IMPORT int sysClkFreqGet ();
IMPORT int sysClkHandleGet ();
IMPORT int sysClkInit ();
IMPORT int sysClkRateGet ();
IMPORT int sysClkRateSet ();
IMPORT int sysClkTimerNo;
IMPORT int sysCplusEnable;
IMPORT int sysCpu;
IMPORT int sysCpuAvailableGet ();
IMPORT int sysDebugModeGet ();
IMPORT int sysDebugModeInit ();
IMPORT int sysDebugModeSet ();
IMPORT int sysDebugModeSetHookAdd ();
IMPORT int sysDebugModeSetHookDelete ();
IMPORT int sysDelay ();
IMPORT int sysExcMsg;
IMPORT int sysFlags;
IMPORT int sysGpioAlloc ();
IMPORT int sysGpioBankShow ();
IMPORT int sysGpioCheckValid ();
IMPORT int sysGpioFree ();
IMPORT int sysGpioGetValue ();
IMPORT int sysGpioInit ();
IMPORT int sysGpioIntConnect ();
IMPORT int sysGpioIntDisable ();
IMPORT int sysGpioIntDisconnect ();
IMPORT int sysGpioIntEnable ();
IMPORT int sysGpioIntTestIrq ();
IMPORT int sysGpioIntTestStart ();
IMPORT int sysGpioIntTestStop ();
IMPORT int sysGpioIsValid ();
IMPORT int sysGpioIsr ();
IMPORT int sysGpioLedTest ();
IMPORT int sysGpioSelectInput ();
IMPORT int sysGpioSelectOutput ();
IMPORT int sysGpioSetIrqTrigger ();
IMPORT int sysGpioSetValue ();
IMPORT int sysGpioShow ();
IMPORT int sysGpioSysIrqConnect ();
IMPORT int sysGpioSysIrqDisconnect ();
IMPORT int sysHwInit ();
IMPORT int sysHwInit0 ();
IMPORT int sysHwInit2 ();
IMPORT int sysInByte ();
IMPORT int sysInLong ();
IMPORT int sysInWord ();
IMPORT int sysInit ();
IMPORT int sysInstParamTable;
IMPORT int sysIntLvlChgRtn;
IMPORT int sysIntLvlDisableRtn;
IMPORT int sysIntLvlEnableRtn;
IMPORT int sysIntLvlVecAckRtn;
IMPORT int sysIntLvlVecChkRtn;
IMPORT int sysL2CacheEnabled;
IMPORT int sysMacIndex2Dev ();
IMPORT int sysMacIndex2Unit ();
IMPORT int sysMacOffsetGet ();
IMPORT int sysMemTop ();
IMPORT int sysMmuLibInit;
IMPORT int sysModel ();
IMPORT int sysMsDelay ();
IMPORT int sysMshcClkFreqSetup ();
IMPORT int sysMshcClkFreqSetup_2 ();
IMPORT int sysMshcClkFreq_Get ();
IMPORT int sysMtdIdentify ();
IMPORT int sysNetDevName;
IMPORT int sysNetMacAddrGet ();
IMPORT int sysNetMacAddrSet ();
IMPORT int sysNetMacNVRamAddrGet ();
IMPORT int sysNvRamGet ();
IMPORT int sysNvRamSet ();
IMPORT int sysOutByte ();
IMPORT int sysOutLong ();
IMPORT int sysOutWord ();
IMPORT int sysPhysMemDesc;
IMPORT int sysPhysMemDescCortexA8ExtNumEnt;
IMPORT int sysPhysMemDescNumEnt;
IMPORT int sysPhysMemTop ();
IMPORT int sysProcNum;
IMPORT int sysProcNumGet ();
IMPORT int sysProcNumSet ();
IMPORT int sysSdmmcSetup_2 ();
IMPORT int sysSdmmcSetup_25M ();
IMPORT int sysSdmmcSetup_50M ();
IMPORT int sysSdmmcSetup_5M ();
IMPORT int sysSdmmcSetup_byRate ();
IMPORT int sysSdmmcSetup_byRate_2 ();
IMPORT int sysSerialChanConnect ();
IMPORT int sysSerialChanGet ();
IMPORT int sysSerialConnectAll ();
IMPORT int sysStart ();
IMPORT int sysStartType;
IMPORT int sysSymPhysMemBottom;
IMPORT int sysSymPhysMemSize;
IMPORT int sysSymTbl;
IMPORT int sysTextProtect;
IMPORT int sysTffsFormat ();
IMPORT int sysTffsProgressCb ();
IMPORT int sysTimestamp ();
IMPORT int sysTimestampConnect ();
IMPORT int sysTimestampDisable ();
IMPORT int sysTimestampEnable ();
IMPORT int sysTimestampFreq ();
IMPORT int sysTimestampHandleGet ();
IMPORT int sysTimestampLock ();
IMPORT int sysTimestampPeriod ();
IMPORT int sysToMonitor ();
IMPORT int sysUsDelay ();
IMPORT int sysVmContext;
IMPORT int system ();
IMPORT int systemSecurityIsEnabled;
IMPORT int tExcTaskExcStk;
IMPORT int tExcTaskStk;
IMPORT int tExcTaskTcb;
IMPORT int tagCheckEvaluateAsserts ();
IMPORT int tagCheckModuleAdd ();
IMPORT int tagCheckModuleDel ();
IMPORT int tagCheckStatementAdd ();
IMPORT int taglist;
IMPORT int tan ();
IMPORT int tanh ();
IMPORT int taskActivate ();
IMPORT int taskArgsGet ();
IMPORT int taskArgsSet ();
IMPORT int taskBpHook;
IMPORT int taskBpHookSet ();
IMPORT int taskClassId;
IMPORT int taskClientCont ();
IMPORT int taskClientStopForce ();
IMPORT int taskCont ();
IMPORT int taskContHookAdd ();
IMPORT int taskContHookDelete ();
IMPORT int taskContTable;
IMPORT int taskCpuAffinityGet ();
IMPORT int taskCpuAffinitySet ();
IMPORT int taskCpuLock ();
IMPORT int taskCpuUnlock ();
IMPORT int taskCpuUnlockNoResched ();
IMPORT int taskCreat ();
IMPORT int taskCreate ();
IMPORT int taskCreateHookAdd ();
IMPORT int taskCreateHookDelete ();
IMPORT int taskCreateHookInit ();
IMPORT int taskCreateHookShow ();
IMPORT int taskCreateHooks;
IMPORT int taskCreateHooksArrayA;
IMPORT int taskCreateHooksArrayB;
IMPORT int taskCreateLibInit ();
IMPORT int taskCreateWithGuard ();
IMPORT int taskDelay ();
IMPORT int taskDelete ();
IMPORT int taskDeleteForce ();
IMPORT int taskDeleteHookAdd ();
IMPORT int taskDeleteHookDelete ();
IMPORT int taskDeleteHookShow ();
IMPORT int taskDeleteHooks;
IMPORT int taskDeleteHooksArrayA;
IMPORT int taskDeleteHooksArrayB;
IMPORT int taskDestroy ();
IMPORT int taskEach ();
IMPORT int taskExit ();
IMPORT int taskHookShowInit ();
IMPORT int taskIdCurrent;
IMPORT int taskIdDefault ();
IMPORT int taskIdFigure ();
IMPORT int taskIdListGet ();
IMPORT int taskIdListSort ();
IMPORT int taskIdSelf ();
IMPORT int taskIdVerify ();
IMPORT int taskInfoGet ();
IMPORT int taskInit ();
IMPORT int taskInitExcStk ();
IMPORT int taskInitialize ();
IMPORT int taskIsDelayed ();
IMPORT int taskIsPended ();
IMPORT int taskIsReady ();
IMPORT int taskIsStopped ();
IMPORT int taskIsSuspended ();
IMPORT int taskKerExcStackSize;
IMPORT int taskKerExcStkOverflowSize;
IMPORT int taskKerExecStkOverflowSize;
IMPORT int taskKerExecStkUnderflowSize;
IMPORT int taskLibInit ();
IMPORT int taskLock ();
IMPORT int taskName ();
IMPORT int taskNameToId ();
IMPORT int taskOptionsGet ();
IMPORT int taskOptionsSet ();
IMPORT int taskOptionsString ();
IMPORT int taskPriNormalGet ();
IMPORT int taskPriorityGet ();
IMPORT int taskPrioritySet ();
IMPORT int taskRegName;
IMPORT int taskRegsGet ();
IMPORT int taskRegsInit ();
IMPORT int taskRegsModify ();
IMPORT int taskRegsSet ();
IMPORT int taskRegsShow ();
IMPORT int taskRegsShowOutput ();
IMPORT int taskReservedFieldGet ();
IMPORT int taskReservedFieldSet ();
IMPORT int taskReservedNumAllot ();
IMPORT int taskReset ();
IMPORT int taskRestart ();
IMPORT int taskResume ();
IMPORT int taskRtnValueSet ();
IMPORT int taskSafe ();
IMPORT int taskSchedInfoGet ();
IMPORT int taskShellCmdInit ();
IMPORT int taskShow ();
IMPORT int taskShowInit ();
IMPORT int taskSpareFieldGet ();
IMPORT int taskSpareFieldSet ();
IMPORT int taskSpareNumAllot ();
IMPORT int taskSpawn ();
IMPORT int taskStackAllot ();
IMPORT int taskStackSizeGet ();
IMPORT int taskStatusString ();
IMPORT int taskStop ();
IMPORT int taskStopForce ();
IMPORT int taskStopHookAdd ();
IMPORT int taskStopHookDelete ();
IMPORT int taskStopMsg;
IMPORT int taskStopTable;
IMPORT int taskSuspend ();
IMPORT int taskSwapHookAdd ();
IMPORT int taskSwapHookAttach ();
IMPORT int taskSwapHookDelete ();
IMPORT int taskSwapHookDetach ();
IMPORT int taskSwapHookShow ();
IMPORT int taskSwapReference;
IMPORT int taskSwapTable;
IMPORT int taskSwitchHookAdd ();
IMPORT int taskSwitchHookDelete ();
IMPORT int taskSwitchHookShow ();
IMPORT int taskSwitchTable;
IMPORT int taskTcb ();
IMPORT int taskTerminate ();
IMPORT int taskUndelay ();
IMPORT int taskUnlock ();
IMPORT int taskUnsafe ();
IMPORT int taskUnsafeInternal ();
IMPORT int taskUsrExcStackSize;
IMPORT int taskUsrExcStkOverflowSize;
IMPORT int taskUsrExecStkOverflowSize;
IMPORT int taskUsrExecStkUnderflowSize;
IMPORT int taskVarAdd ();
IMPORT int taskVarDelete ();
IMPORT int taskVarGet ();
IMPORT int taskVarInfo ();
IMPORT int taskVarInit ();
IMPORT int taskVarSet ();
IMPORT int taskWait ();
IMPORT int taskWaitShow ();
IMPORT int taskWaitShowCoreRtn ();
IMPORT int task_com1_rcv ();
IMPORT int tcbReserveBitmap;
IMPORT int tcbSpareBitmap;
IMPORT int tcp_tmr_string;
IMPORT int td ();
IMPORT int test_100us_timer ();
IMPORT int test_com1_rcv ();
IMPORT int test_com1_snd ();
IMPORT int test_dma_1 ();
IMPORT int test_dma_2 ();
IMPORT int test_dmac_init ();
IMPORT int test_erase_all_chip ();
IMPORT int test_get_seg ();
IMPORT int test_gpio_button ();
IMPORT int test_gpio_button_poll ();
IMPORT int test_gpio_led ();
IMPORT int test_gpio_read ();
IMPORT int test_gtc ();
IMPORT int test_gtc_delay ();
IMPORT int test_mmc_rd_file ();
IMPORT int test_mmc_speed_dosfs ();
IMPORT int test_mmc_w_r_sects_bare1 ();
IMPORT int test_mmc_w_r_sects_bare1_2 ();
IMPORT int test_mmc_wr_file ();
IMPORT int test_phy_reset ();
IMPORT int test_qspi_erase_sect ();
IMPORT int test_qspi_rd_file ();
IMPORT int test_qspi_rd_sect ();
IMPORT int test_qspi_rd_uboot_env ();
IMPORT int test_qspi_wr_file ();
IMPORT int test_qspi_wr_sect ();
IMPORT int test_qspiflash_rd_id ();
IMPORT int test_qspiflash_rd_ids ();
IMPORT int test_rd_ctrl_regs ();
IMPORT int test_rd_quadmode ();
IMPORT int test_rd_sector ();
IMPORT int test_rd_sector0 ();
IMPORT int test_rd_sector1 ();
IMPORT int test_readintMMC ();
IMPORT int test_sd_speed_dosfs ();
IMPORT int test_sdmmc_init ();
IMPORT int test_sdmmc_speed_dosfs_2 ();
IMPORT int test_set_3b_addrmode ();
IMPORT int test_set_4b_addrmode ();
IMPORT int test_set_seg ();
IMPORT int test_spi_loop1 ();
IMPORT int test_spi_loop2 ();
IMPORT int test_spi_loop3 ();
IMPORT int test_ttc ();
IMPORT int test_uart1_put ();
IMPORT int test_uart1_snd ();
IMPORT int test_uart2_put ();
IMPORT int test_usdelay ();
IMPORT int test_wr_sector ();
IMPORT int test_wr_sector0 ();
IMPORT int test_wr_sector1 ();
IMPORT int testvx_open_bootbin ();
IMPORT int testvx_qspi_all_chip ();
IMPORT int testvx_qspi_erase_sect2 ();
IMPORT int testvx_qspi_rd_sect2 ();
IMPORT int testvx_qspi_rdwr_sects ();
IMPORT int testvx_qspi_wr_sect2 ();
IMPORT int testvx_update_bit2 ();
IMPORT int testvx_update_bit3 ();
IMPORT int testvx_update_bit4 ();
IMPORT int testvx_update_bit_part ();
IMPORT int tffsDevCreate ();
IMPORT int tffsDevFormat ();
IMPORT int tffsDevOptionsSet ();
IMPORT int tffsDevRawSpeedShow ();
IMPORT int tffsDevStatShow ();
IMPORT int tffsDiskChangeAnnounce ();
IMPORT int tffsDrv ();
IMPORT int tffsDrvOptionsSet ();
IMPORT int tffsRawio ();
IMPORT int tffsShow ();
IMPORT int tffsShowAll ();
IMPORT int tffsVolStatInit ();
IMPORT int tffsVolStatShow ();
IMPORT int tffsWrtLock ();
IMPORT int tffsWrtUnlock ();
IMPORT int tffs_qspiFlashPageWrite ();
IMPORT int tffs_qspiFlashRead ();
IMPORT int tffs_qspiFlashSectorErase ();
IMPORT int tffs_qspiFlashSectorErase_Idx ();
IMPORT int tffscmpWords ();
IMPORT int ti ();
IMPORT int tick64Get ();
IMPORT int tick64Set ();
IMPORT int tickAnnounce ();
IMPORT int tickAnnounceHookAdd ();
IMPORT int tickGet ();
IMPORT int tickQHead;
IMPORT int tickSet ();
IMPORT int time ();
IMPORT int timerClass;
IMPORT int timerClassId;
IMPORT int timerLibInit ();
IMPORT int timerLibLog;
IMPORT int timerWdHandler ();
IMPORT int timer_cancel ();
IMPORT int timer_connect ();
IMPORT int timer_create ();
IMPORT int timer_delete ();
IMPORT int timer_destroy ();
IMPORT int timer_getoverrun ();
IMPORT int timer_gettime ();
IMPORT int timer_modify ();
IMPORT int timer_settime ();
IMPORT int timestampDevUnitNo;
IMPORT int timestampTimerNo;
IMPORT int timex ();
IMPORT int timexClear ();
IMPORT int timexFunc ();
IMPORT int timexHelp ();
IMPORT int timexInit ();
IMPORT int timexN ();
IMPORT int timexPost ();
IMPORT int timexPre ();
IMPORT int timexShow ();
IMPORT int tip ();
IMPORT int tipConfigString;
IMPORT int tipEscapeChar;
IMPORT int tipLibInit ();
IMPORT int tipShellCmdInit ();
IMPORT int tipStart ();
IMPORT int tlTable;
IMPORT int tmpfile ();
IMPORT int tmpnam ();
IMPORT int toUNAL ();
IMPORT int toUNALLONG ();
IMPORT int tolower ();
IMPORT int toupper ();
IMPORT int tr ();
IMPORT int trcDefaultArgs;
IMPORT int trcLibFuncs;
IMPORT int trcScanDepth;
IMPORT int trcStack ();
IMPORT int trcStackCtxTrace ();
IMPORT int trcStackEx ();
IMPORT int trcStackTrace ();
IMPORT int ts ();
IMPORT int tt ();
IMPORT int ttc_init_timer ();
IMPORT int ttc_stop_timer ();
IMPORT int ttyDevCreate ();
IMPORT int ttyDrv ();
IMPORT int ttyTester ();
IMPORT int tw ();
IMPORT int tyAbortFuncGet ();
IMPORT int tyAbortFuncSet ();
IMPORT int tyAbortGet ();
IMPORT int tyAbortSet ();
IMPORT int tyBackspaceChar;
IMPORT int tyBackspaceSet ();
IMPORT int tyDeleteLineChar;
IMPORT int tyDeleteLineSet ();
IMPORT int tyDevInit ();
IMPORT int tyDevRemove ();
IMPORT int tyDevTerminate ();
IMPORT int tyEOFGet ();
IMPORT int tyEOFSet ();
IMPORT int tyEofChar;
IMPORT int tyIRd ();
IMPORT int tyITx ();
IMPORT int tyIoctl ();
IMPORT int tyLibInit ();
IMPORT int tyMonitorTrapSet ();
IMPORT int tyRead ();
IMPORT int tyWrite ();
IMPORT int tyXoffHookSet ();
IMPORT int uNum;
IMPORT int uartBase;
IMPORT int uartBase2;
IMPORT int uartCtrl_Disable_Afc ();
IMPORT int uartCtrl_Disable_Fifos ();
IMPORT int uartCtrl_Disable_Irq ();
IMPORT int uartCtrl_Disable_Loopback ();
IMPORT int uartCtrl_Disable_Ptime ();
IMPORT int uartCtrl_Enable_Afc ();
IMPORT int uartCtrl_Enable_Fifos ();
IMPORT int uartCtrl_Enable_Irq ();
IMPORT int uartCtrl_Enable_Loopback ();
IMPORT int uartCtrl_Enable_Ptime ();
IMPORT int uartCtrl_Get_ActiveIrq ();
IMPORT int uartCtrl_Get_Break ();
IMPORT int uartCtrl_Get_ClockDivisor ();
IMPORT int uartCtrl_Get_DataBits ();
IMPORT int uartCtrl_Get_FifoDepth ();
IMPORT int uartCtrl_Get_IrqMask ();
IMPORT int uartCtrl_Get_LineControl ();
IMPORT int uartCtrl_Get_LineStatus ();
IMPORT int uartCtrl_Get_ModemLine ();
IMPORT int uartCtrl_Get_ModemStatus ();
IMPORT int uartCtrl_Get_Parity ();
IMPORT int uartCtrl_Get_RxFifoLevel ();
IMPORT int uartCtrl_Get_RxTrigger ();
IMPORT int uartCtrl_Get_Scratchpad ();
IMPORT int uartCtrl_Get_StopBits ();
IMPORT int uartCtrl_Get_TxFifoLevel ();
IMPORT int uartCtrl_Get_TxTrigger ();
IMPORT int uartCtrl_Is_AfcEnabled ();
IMPORT int uartCtrl_Is_Busy ();
IMPORT int uartCtrl_Is_FifosEnabled ();
IMPORT int uartCtrl_Is_IrqEnabled ();
IMPORT int uartCtrl_Is_LoopbackEnabled ();
IMPORT int uartCtrl_Is_PtimeEnabled ();
IMPORT int uartCtrl_Is_RxFifoEmpty ();
IMPORT int uartCtrl_Is_RxFifoFull ();
IMPORT int uartCtrl_Is_TxFifoEmpty ();
IMPORT int uartCtrl_Is_TxFifoFull ();
IMPORT int uartCtrl_Rd_CfgReg32 ();
IMPORT int uartCtrl_Reset ();
IMPORT int uartCtrl_Rst_RxFifo ();
IMPORT int uartCtrl_Rst_TxFifo ();
IMPORT int uartCtrl_Rx_Poll ();
IMPORT int uartCtrl_SLCR_Loop ();
IMPORT int uartCtrl_Set_BaudRate ();
IMPORT int uartCtrl_Set_Break ();
IMPORT int uartCtrl_Set_ClockDivisor ();
IMPORT int uartCtrl_Set_DataBits ();
IMPORT int uartCtrl_Set_LineControl ();
IMPORT int uartCtrl_Set_ModemLine ();
IMPORT int uartCtrl_Set_Parity ();
IMPORT int uartCtrl_Set_RxTrigger ();
IMPORT int uartCtrl_Set_Scratchpad ();
IMPORT int uartCtrl_Set_Stick ();
IMPORT int uartCtrl_Set_StopBits ();
IMPORT int uartCtrl_Set_TxTrigger ();
IMPORT int uartCtrl_Tx_Poll ();
IMPORT int uartCtrl_Wr_CfgReg32 ();
IMPORT int uartCtrl_autoCompParams ();
IMPORT int uartCtrl_burstRead ();
IMPORT int uartCtrl_burstWrite ();
IMPORT int uartCtrl_clearModemLine ();
IMPORT int uartCtrl_read ();
IMPORT int uartCtrl_write ();
IMPORT int uartSetdelay ();
IMPORT int uartSlcr_Enable_UartClk ();
IMPORT int udpCommIfInit ();
IMPORT int udpRcv ();
IMPORT int ungetc ();
IMPORT int unld ();
IMPORT int unldByGroup ();
IMPORT int unldByModuleId ();
IMPORT int unldByNameAndPath ();
IMPORT int unldExecUsrTerm ();
IMPORT int unldLibInit ();
IMPORT int unlink ();
IMPORT int unloadShellCmdInit ();
IMPORT int unmount ();
IMPORT int upCpuFreq_ARM_PLL;
IMPORT int usart_close ();
IMPORT int usart_report_queue ();
IMPORT int usart_set_baudrate ();
IMPORT int usart_set_line_control ();
IMPORT int usart_set_start_break ();
IMPORT int usart_set_stop_break ();
IMPORT int usart_set_tx_fifo ();
IMPORT int usart_set_xoff ();
IMPORT int usart_set_xon ();
IMPORT int usart_set_xon_xoff ();
IMPORT int userAxiCfgRead ();
IMPORT int userAxiCfgWrite ();
IMPORT int userCallback ();
IMPORT int userListener ();
IMPORT int userRgnPoolId;
IMPORT int user_task_increment_counter ();
IMPORT int user_task_print_message ();
IMPORT int usrAppInit ();
IMPORT int usrBanner ();
IMPORT int usrBootHwInit ();
IMPORT int usrBootLineCrack ();
IMPORT int usrBootLineGet ();
IMPORT int usrBootLineInit ();
IMPORT int usrBootLineParse ();
IMPORT int usrBreakpointInit ();
IMPORT int usrBreakpointSet ();
IMPORT int usrCacheEnable ();
IMPORT int usrClock ();
IMPORT int usrDosfsInit ();
IMPORT int usrFsShellCmdInit ();
IMPORT int usrFtpInit ();
IMPORT int usrInit ();
IMPORT int usrIosCoreInit ();
IMPORT int usrIosExtraInit ();
IMPORT int usrIsrDeferInit ();
IMPORT int usrKernelCoreInit ();
IMPORT int usrKernelCreateInit ();
IMPORT int usrKernelExtraInit ();
IMPORT int usrKernelInit ();
IMPORT int usrLibInit ();
IMPORT int usrLoaderInit ();
IMPORT int usrMmuInit ();
IMPORT int usrModuleLoad ();
IMPORT int usrMuxConfigInit ();
IMPORT int usrNetApplUtilInit ();
IMPORT int usrNetBoot ();
IMPORT int usrNetDaemonInit ();
IMPORT int usrNetDevNameGet ();
IMPORT int usrNetEndLibInit ();
IMPORT int usrNetHostInit ();
IMPORT int usrNetIfconfigInit ();
IMPORT int usrNetRemoteCreate ();
IMPORT int usrNetRemoteInit ();
IMPORT int usrNetUtilsInit ();
IMPORT int usrNetmaskGet ();
IMPORT int usrNetworkInit ();
IMPORT int usrRoot ();
IMPORT int usrRtpAppInit ();
IMPORT int usrSerialInit ();
IMPORT int usrShell ();
IMPORT int usrShellCmdInit ();
IMPORT int usrShellInit ();
IMPORT int usrShowInit ();
IMPORT int usrStandaloneInit ();
IMPORT int usrStat;
IMPORT int usrSymLibInit ();
IMPORT int usrSymTblInit ();
IMPORT int usrSysHwInit2 ();
IMPORT int usrSysSymTblInit ();
IMPORT int usrTffsConfig ();
IMPORT int usrTffsLnConfig ();
IMPORT int usrTipInit ();
IMPORT int usrToolsInit ();
IMPORT int usrVxbTimerSysInit ();
IMPORT int usrVxdbgInit ();
IMPORT int usrWdbBanner ();
IMPORT int usrWdbBp ();
IMPORT int usrWdbGopherInit ();
IMPORT int usrWdbInit ();
IMPORT int usrWdbInitDone ();
IMPORT int usrWdbTaskModeInit ();
IMPORT int uswab ();
IMPORT int utime ();
IMPORT int uuidGen ();
IMPORT int uuidStr ();
IMPORT int uuid_compare ();
IMPORT int uuid_create ();
IMPORT int uuid_create_nil ();
IMPORT int uuid_dec_be ();
IMPORT int uuid_dec_le ();
IMPORT int uuid_enc_be ();
IMPORT int uuid_enc_le ();
IMPORT int uuid_equal ();
IMPORT int uuid_from_string ();
IMPORT int uuid_hash ();
IMPORT int uuid_is_nil ();
IMPORT int uuid_node ();
IMPORT int uuid_time ();
IMPORT int uuid_to_string ();
IMPORT int valloc ();
IMPORT int version ();
IMPORT int vfdprintf ();
IMPORT int vfpArchInit ();
IMPORT int vfpArchTaskCreateInit ();
IMPORT int vfpCtlRegName;
IMPORT int vfpCtxCreate ();
IMPORT int vfpCtxDelete ();
IMPORT int vfpCtxShow ();
IMPORT int vfpCtxToRegs ();
IMPORT int vfpDisable ();
IMPORT int vfpDoubleRegName;
IMPORT int vfpEnable ();
IMPORT int vfpExcHandle ();
IMPORT int vfpFpScrGet ();
IMPORT int vfpFpScrSet ();
IMPORT int vfpFpSidGet ();
IMPORT int vfpHasException ();
IMPORT int vfpIsEnabled ();
IMPORT int vfpProbe ();
IMPORT int vfpProbeSup ();
IMPORT int vfpProbeTrap ();
IMPORT int vfpRegListShow ();
IMPORT int vfpRegsToCtx ();
IMPORT int vfpRestore ();
IMPORT int vfpSave ();
IMPORT int vfpSingleRegName;
IMPORT int vfpTaskRegsCFmt;
IMPORT int vfpTaskRegsDFmt;
IMPORT int vfpTaskRegsSFmt;
IMPORT int vfprintf ();
IMPORT int vfpscrInitValue;
IMPORT int viLedLibInit ();
IMPORT int vmAttrToArchConvert ();
IMPORT int vmAttrToIndepConvert ();
IMPORT int vmBaseLibInit ();
IMPORT int vmBasePageSizeGet ();
IMPORT int vmBaseStateSet ();
IMPORT int vmBufferWrite ();
IMPORT int vmContextClassId;
IMPORT int vmContextSwitch ();
IMPORT int vmContigBlockEach ();
IMPORT int vmCtxCreate ();
IMPORT int vmCtxDelete ();
IMPORT int vmCtxDestroy ();
IMPORT int vmCtxInit ();
IMPORT int vmCtxMask ();
IMPORT int vmCtxTerminate ();
IMPORT int vmCtxUnion ();
IMPORT int vmCtxUnionInit ();
IMPORT int vmCurrentGet ();
IMPORT int vmCurrentSet ();
IMPORT int vmGlobalMapInit ();
IMPORT int vmInfoGet ();
IMPORT int vmKernelContextIdGet ();
IMPORT int vmLibInfo;
IMPORT int vmLibInit ();
IMPORT int vmMap ();
IMPORT int vmMaxPhysBitsGet ();
IMPORT int vmOptimizedSizeGet ();
IMPORT int vmPageBlockSizeGet ();
IMPORT int vmPageLock ();
IMPORT int vmPageMap ();
IMPORT int vmPageOptimize ();
IMPORT int vmPageSizeGet ();
IMPORT int vmPageUnlock ();
IMPORT int vmPageUnmap ();
IMPORT int vmPgMap ();
IMPORT int vmPgUnMap ();
IMPORT int vmPhysTranslate ();
IMPORT int vmPteSizeGet ();
IMPORT int vmStateGet ();
IMPORT int vmStateSet ();
IMPORT int vmTextProtect ();
IMPORT int vmTranslate ();
IMPORT int voprintf ();
IMPORT int vprintf ();
IMPORT int vsnprintf ();
IMPORT int vsprintf ();
IMPORT int vxAbsTicks;
IMPORT int vxAtomic32Add ();
IMPORT int vxAtomic32And ();
IMPORT int vxAtomic32Cas ();
IMPORT int vxAtomic32Clear ();
IMPORT int vxAtomic32Dec ();
IMPORT int vxAtomic32Get ();
IMPORT int vxAtomic32Inc ();
IMPORT int vxAtomic32Nand ();
IMPORT int vxAtomic32Or ();
IMPORT int vxAtomic32Set ();
IMPORT int vxAtomic32Sub ();
IMPORT int vxAtomic32Xor ();
IMPORT int vxAtomicAdd ();
IMPORT int vxAtomicAnd ();
IMPORT int vxAtomicCas ();
IMPORT int vxAtomicClear ();
IMPORT int vxAtomicDec ();
IMPORT int vxAtomicGet ();
IMPORT int vxAtomicInc ();
IMPORT int vxAtomicNand ();
IMPORT int vxAtomicOr ();
IMPORT int vxAtomicSet ();
IMPORT int vxAtomicSub ();
IMPORT int vxAtomicXor ();
IMPORT int vxBaseCpuPhysIndex;
IMPORT int vxCas ();
IMPORT int vxCpsrGet ();
IMPORT int vxCpuConfigured;
IMPORT int vxCpuConfiguredGet ();
IMPORT int vxCpuEnabled;
IMPORT int vxCpuEnabledGet ();
IMPORT int vxCpuIdGet ();
IMPORT int vxCpuIdToPhysIndex ();
IMPORT int vxCpuIndexGet ();
IMPORT int vxCpuLibInit ();
IMPORT int vxCpuPhysIndexGet ();
IMPORT int vxCpuPhysIndexToId ();
IMPORT int vxCpuReserve ();
IMPORT int vxCpuReservedGet ();
IMPORT int vxCpuSetReserved;
IMPORT int vxCpuSetReservedAvail;
IMPORT int vxCpuUnreserve ();
IMPORT int vxEventPendQ;
IMPORT int vxGic_Get_IrqFlag ();
IMPORT int vxInit_Devc ();
IMPORT int vxInit_Dma ();
IMPORT int vxInit_Dma_1 ();
IMPORT int vxInit_Dma_2 ();
IMPORT int vxInit_Gpio ();
IMPORT int vxInit_Gtc ();
IMPORT int vxInit_Qspi ();
IMPORT int vxInit_Spi ();
IMPORT int vxInit_Uart ();
IMPORT int vxIntStackBase;
IMPORT int vxIntStackEnd;
IMPORT int vxIntStackOverflowSize;
IMPORT int vxIntStackUnderflowSize;
IMPORT int vxIrqIntStackBase;
IMPORT int vxIrqIntStackEnd;
IMPORT int vxMemArchProbe ();
IMPORT int vxMemArchProbeInit ();
IMPORT int vxMemProbe ();
IMPORT int vxMemProbeByteRead ();
IMPORT int vxMemProbeByteWrite ();
IMPORT int vxMemProbeErrorRtn ();
IMPORT int vxMemProbeInit ();
IMPORT int vxMemProbeLongRead ();
IMPORT int vxMemProbeLongWrite ();
IMPORT int vxMemProbeSup ();
IMPORT int vxMemProbeSupEnd ();
IMPORT int vxMemProbeWordRead ();
IMPORT int vxMemProbeWordWrite ();
IMPORT int vxSvcIntStackBase;
IMPORT int vxSvcIntStackEnd;
IMPORT int vxTas ();
IMPORT int vxTaskEntry ();
IMPORT int vxTaskEntryFatalInject ();
IMPORT char * vxWorksVersion;
IMPORT const unsigned int vxWorksVersionMaint;
IMPORT const unsigned int vxWorksVersionMajor;
IMPORT const unsigned int vxWorksVersionMinor;
IMPORT int vxWorksVersionSvcPk;
IMPORT int vx_FGicPs_Disable ();
IMPORT int vx_FGicPs_Enable ();
IMPORT int vx_FGicPs_Get_PrioTrigType ();
IMPORT int vx_FGicPs_Set_PrioTrigType ();
IMPORT int vx_FGicPs_SoftwareIntr ();
IMPORT int vxbAltSocGen5DwEndRegister ();
IMPORT int vxbAltSocGen5DwEndRegister2 ();
IMPORT int vxbAltSocGen5TimerRegister ();
IMPORT int vxbArmGenIntCtlrRegister ();
IMPORT int vxbArmGicLvlChg ();
IMPORT int vxbArmGicLvlVecAck ();
IMPORT int vxbArmGicLvlVecChk ();
IMPORT int vxbBusAnnounce ();
IMPORT int vxbBusListLock;
IMPORT int vxbBusTypeRegister ();
IMPORT int vxbBusTypeString ();
IMPORT int vxbBusTypeUnregister ();
IMPORT int vxbDelay ();
IMPORT int vxbDelayLibInit ();
IMPORT int vxbDelayTimerFreeRunning;
IMPORT int vxbDevConnect ();
IMPORT int vxbDevConnectInternal ();
IMPORT int vxbDevInit ();
IMPORT int vxbDevInitInternal ();
IMPORT int vxbDevIntCapabCheck_desc;
IMPORT int vxbDevIterate ();
IMPORT int vxbDevMethodGet ();
IMPORT int vxbDevMethodRun ();
IMPORT int vxbDevParent ();
IMPORT int vxbDevPath ();
IMPORT int vxbDevRegMap_desc;
IMPORT int vxbDevRegister ();
IMPORT int vxbDevRemovalAnnounce ();
IMPORT int vxbDevStructAlloc ();
IMPORT int vxbDevStructFree ();
IMPORT int vxbDevStructListLock;
IMPORT int vxbDeviceAnnounce ();
IMPORT int vxbDeviceDriverRelease ();
IMPORT int vxbDeviceMethodRun ();
IMPORT int vxbDmaChanAlloc ();
IMPORT int vxbDmaChanFree ();
IMPORT int vxbDmaLibInit ();
IMPORT int vxbDmaResDedicatedGet_desc;
IMPORT int vxbDmaResourceGet_desc;
IMPORT int vxbDmaResourceRelease_desc;
IMPORT int vxbDriverUnregister ();
IMPORT int vxbDrvRescan ();
IMPORT int vxbDrvUnlink_desc;
IMPORT int vxbDrvVerCheck ();
IMPORT int vxbDwEmacDev0Resources;
IMPORT int vxbDwEmacDev1Resources;
IMPORT int vxbFmshSdhcCtrl_methods;
IMPORT int vxbGlobalListsLock;
IMPORT int vxbInit ();
IMPORT int vxbInstByNameFind ();
IMPORT int vxbInstParamByIndexGet ();
IMPORT int vxbInstParamByNameGet ();
IMPORT int vxbInstParamSet ();
IMPORT int vxbInstUnitGet ();
IMPORT int vxbInstUnitSet ();
IMPORT int vxbInstUsrOptionGet ();
IMPORT int vxbIntAcknowledge ();
IMPORT int vxbIntAlloc ();
IMPORT int vxbIntConnect ();
IMPORT int vxbIntCtlrAck_desc;
IMPORT int vxbIntCtlrAlloc_desc;
IMPORT int vxbIntCtlrConnect_desc;
IMPORT int vxbIntCtlrDisable_desc;
IMPORT int vxbIntCtlrDisconnect_desc;
IMPORT int vxbIntCtlrEnable_desc;
IMPORT int vxbIntCtlrFree_desc;
IMPORT int vxbIntDisable ();
IMPORT int vxbIntDisconnect ();
IMPORT int vxbIntEnable ();
IMPORT int vxbIntFree ();
IMPORT int vxbIntVectorGet ();
IMPORT int vxbLegacyIntInit ();
IMPORT int vxbLibError ();
IMPORT int vxbLibInit ();
IMPORT int vxbLockDelete ();
IMPORT int vxbLockGive ();
IMPORT int vxbLockInit ();
IMPORT int vxbLockTake ();
IMPORT int vxbMmcStorageRegister ();
IMPORT int vxbMsDelay ();
IMPORT int vxbNextUnitGet ();
IMPORT int vxbRead16 ();
IMPORT int vxbRead32 ();
IMPORT int vxbRead8 ();
IMPORT int vxbRegMap ();
IMPORT int vxbRegUnmap ();
IMPORT int vxbResourceFind ();
IMPORT int vxbSdSpecInfoGet_desc;
IMPORT int vxbSdStorageRegister ();
IMPORT int vxbSdioInt ();
IMPORT int vxbSdioIntConnect ();
IMPORT int vxbSdioIntLibInit ();
IMPORT int vxbSdioReadCis ();
IMPORT int vxbSdioSetFunc ();
IMPORT int vxbSerialChanGet ();
IMPORT int vxbSubDevAction ();
IMPORT int vxbSwap16 ();
IMPORT int vxbSwap32 ();
IMPORT int vxbSysClkConnect ();
IMPORT int vxbSysClkDisable ();
IMPORT int vxbSysClkEnable ();
IMPORT int vxbSysClkLibInit ();
IMPORT int vxbSysClkRateGet ();
IMPORT int vxbSysClkRateSet ();
IMPORT int vxbTimerAlloc ();
IMPORT int vxbTimerFeaturesGet ();
IMPORT int vxbTimerFuncGet_desc;
IMPORT int vxbTimerNumberGet_desc;
IMPORT int vxbTimerRelease ();
IMPORT int vxbTimestamp ();
IMPORT int vxbTimestampConnect ();
IMPORT int vxbTimestampDisable ();
IMPORT int vxbTimestampEnable ();
IMPORT int vxbTimestampFreq ();
IMPORT int vxbTimestampLibInit ();
IMPORT int vxbTimestampLock ();
IMPORT int vxbTimestampPeriod ();
IMPORT int vxbUsDelay ();
IMPORT int vxbWrite16 ();
IMPORT int vxbWrite32 ();
IMPORT int vxbWrite8 ();
IMPORT int vxcoreip_shellFromTaskGet_ptr;
IMPORT int vxcoreip_shellTaskGet_ptr;
IMPORT int vxdbgAttach ();
IMPORT int vxdbgBpAdd ();
IMPORT int vxdbgBpAddrCheck ();
IMPORT int vxdbgBpAllDisable ();
IMPORT int vxdbgBpDelete ();
IMPORT int vxdbgBpFind ();
IMPORT int vxdbgBpList;
IMPORT int vxdbgBpMsgDrop ();
IMPORT int vxdbgBpMsgGet ();
IMPORT int vxdbgBpMsgPost ();
IMPORT int vxdbgBpMsgQCreate ();
IMPORT int vxdbgBpMsgQHdlrIsRunning ();
IMPORT int vxdbgBpTraceAbort ();
IMPORT int vxdbgBpUserKeyGet ();
IMPORT int vxdbgBpUserKeySet ();
IMPORT int vxdbgClntRegister ();
IMPORT int vxdbgClntUnregister ();
IMPORT int vxdbgCont ();
IMPORT int vxdbgDetach ();
IMPORT int vxdbgDisableReason;
IMPORT int vxdbgEnable ();
IMPORT int vxdbgEventCancel ();
IMPORT int vxdbgEventIdAlloc ();
IMPORT int vxdbgEventIdFree ();
IMPORT int vxdbgEventInject ();
IMPORT int vxdbgEventLibInit ();
IMPORT int vxdbgEventRunCtrlStateChangeInject ();
IMPORT int vxdbgExcLibInit ();
IMPORT int vxdbgHookAdd ();
IMPORT int vxdbgHookInvoke ();
IMPORT int vxdbgHooksInit ();
IMPORT int vxdbgHwBpAdd ();
IMPORT int vxdbgHwBpTypeValidate ();
IMPORT int vxdbgInstrCmp ();
IMPORT int vxdbgInternalEventInject ();
IMPORT int vxdbgIsAttached ();
IMPORT int vxdbgIsBpAddr ();
IMPORT int vxdbgIsEnabled ();
IMPORT int vxdbgLibInit ();
IMPORT int vxdbgLockUnbreakable;
IMPORT int vxdbgMemAccess ();
IMPORT int vxdbgMemCtxSwitch ();
IMPORT int vxdbgMemMove ();
IMPORT int vxdbgMemProbe ();
IMPORT int vxdbgMemRead ();
IMPORT int vxdbgMemScan ();
IMPORT int vxdbgMemWrite ();
IMPORT int vxdbgModuleLibInit ();
IMPORT int vxdbgRunCtrlHookInvoke ();
IMPORT int vxdbgRunCtrlLibInit ();
IMPORT int vxdbgRunCtrlStateChangeNotify ();
IMPORT int vxdbgSafeUnbreakable;
IMPORT int vxdbgStep ();
IMPORT int vxdbgStop ();
IMPORT int vxdbgTaskBpToInstall ();
IMPORT int vxdbgTaskCont ();
IMPORT int vxdbgTaskHookInit ();
IMPORT int vxdbgTaskLibInit ();
IMPORT int vxdbgTaskStep ();
IMPORT int vxdbgTaskStop ();
IMPORT int vxdbgUnbreakableOld;
IMPORT int vxfs_ramdisk_init_hook;
IMPORT int vxmux_mux_mblk_init ();
IMPORT int vxmux_null_buf_init ();
IMPORT int vxmux_null_pool;
IMPORT int w ();
IMPORT int wcstombs ();
IMPORT int wctomb ();
IMPORT int wdCancel ();
IMPORT int wdClassId;
IMPORT int wdCreate ();
IMPORT int wdCreateLibInit ();
IMPORT int wdDelete ();
IMPORT int wdDestroy ();
IMPORT int wdInit ();
IMPORT int wdInitialize ();
IMPORT int wdLibInit ();
IMPORT int wdStart ();
IMPORT int wdTerminate ();
IMPORT int wdTick ();
IMPORT int wdbAvailModes;
IMPORT int wdbAvailOptions;
IMPORT int wdbBpAddHookAdd ();
IMPORT int wdbBpSyncLibInit ();
IMPORT int wdbBpSysEnterHook;
IMPORT int wdbBpSysExitHook;
IMPORT int wdbCksum ();
IMPORT int wdbCmdLoop ();
IMPORT int wdbCnctModePost ();
IMPORT int wdbCommDevInit ();
IMPORT int wdbCommIfEnable ();
IMPORT int wdbCommMtu;
IMPORT int wdbCommMtuGet ();
IMPORT int wdbConfig ();
IMPORT int wdbConnectHookAdd ();
IMPORT int wdbConnectLibInit ();
IMPORT int wdbCtxCreateNotify ();
IMPORT int wdbCtxDeleteNotify ();
IMPORT int wdbCtxEvtLibInit ();
IMPORT int wdbCtxExitEventGet ();
IMPORT int wdbCtxExitLibInit ();
IMPORT int wdbCtxExitNotifyHook ();
IMPORT int wdbCtxLibInit ();
IMPORT int wdbCtxStartEventGet ();
IMPORT int wdbCtxStartLibInit ();
IMPORT int wdbDbgAddrCheck ();
IMPORT int wdbDbgArchInit ();
IMPORT int wdbDbgGetNpc ();
IMPORT int wdbDbgSysCallCheck ();
IMPORT int wdbDbgTraceModeClear ();
IMPORT int wdbDbgTraceModeSet ();
IMPORT int wdbDbgTrap ();
IMPORT int wdbDirectCallLibInit ();
IMPORT int wdbE ();
IMPORT int wdbEndDebug;
IMPORT int wdbEndDeviceAddress;
IMPORT int wdbEndPktDevInit ();
IMPORT int wdbEventDeq ();
IMPORT int wdbEventLibInit ();
IMPORT int wdbEventNodeInit ();
IMPORT int wdbEventPost ();
IMPORT int wdbEvtptClassConnect ();
IMPORT int wdbEvtptLibInit ();
IMPORT int wdbExcLibInit ();
IMPORT int wdbExternCoprocRegLibInit ();
IMPORT int wdbExternEnterHookAdd ();
IMPORT int wdbExternExitHookAdd ();
IMPORT int wdbExternInit ();
IMPORT int wdbExternLibInit ();
IMPORT int wdbExternRegLibInit ();
IMPORT int wdbFuncCallLibInit ();
IMPORT int wdbGopherLibInit ();
IMPORT int wdbInfoGet ();
IMPORT int wdbInstallCommIf ();
IMPORT int wdbInstallRtIf ();
IMPORT int wdbIoctl ();
IMPORT int wdbIsAlwaysEnabled;
IMPORT int wdbIsInitialized;
IMPORT int wdbIsNowExternal ();
IMPORT int wdbIsReady;
IMPORT int wdbMbufAlloc ();
IMPORT int wdbMbufFree ();
IMPORT int wdbMbufInit ();
IMPORT int wdbMdlSymSyncLibInit ();
IMPORT int wdbMemCoreLibInit ();
IMPORT int wdbMemLibInit ();
IMPORT int wdbMode;
IMPORT int wdbModeSet ();
IMPORT int wdbModeSetHookAdd ();
IMPORT int wdbNotifyHost ();
IMPORT int wdbNumMemRegions;
IMPORT int wdbOneShot;
IMPORT int wdbPort;
IMPORT int wdbRegsLibInit ();
IMPORT int wdbRpcGetArgs ();
IMPORT int wdbRpcNotifyConnect ();
IMPORT int wdbRpcNotifyHost ();
IMPORT int wdbRpcRcv ();
IMPORT int wdbRpcReply ();
IMPORT int wdbRpcReplyErr ();
IMPORT int wdbRpcResendReply ();
IMPORT int wdbRpcXportInit ();
IMPORT int wdbRtIf;
IMPORT int wdbRtLibInit ();
IMPORT int wdbRtMemInit ();
IMPORT int wdbRunsExternal ();
IMPORT int wdbRunsTasking ();
IMPORT int wdbSharedBuffer;
IMPORT int wdbSharedBufferSize;
IMPORT int wdbSp ();
IMPORT int wdbSvcAdd ();
IMPORT int wdbSvcDispatch ();
IMPORT int wdbSvcHookAdd ();
IMPORT int wdbSvcLibInit ();
IMPORT int wdbSysBpDisableAll ();
IMPORT int wdbSysBpEnableAll ();
IMPORT int wdbSysBpLibInit ();
IMPORT int wdbSysModeInit ();
IMPORT int wdbSystemSuspend ();
IMPORT int wdbTargetIsConnected ();
IMPORT int wdbTaskBpAdd ();
IMPORT int wdbTaskBpLibInit ();
IMPORT int wdbTaskCont ();
IMPORT int wdbTaskCoprocRegLibInit ();
IMPORT int wdbTaskCreateHookAdd ();
IMPORT int wdbTaskDeleteHookAdd ();
IMPORT int wdbTaskExtraModules;
IMPORT int wdbTaskHookInit ();
IMPORT int wdbTaskModeInit ();
IMPORT int wdbTaskRegLibInit ();
IMPORT int wdbTaskRestartHook;
IMPORT int wdbTaskStep ();
IMPORT int wdbTaskStop ();
IMPORT int wdbTgtInfoLibInit ();
IMPORT int wdbToolName;
IMPORT int wdbUserEvtLibInit ();
IMPORT int wdbUserEvtPost ();
IMPORT int wdbVioChannelRegister ();
IMPORT int wdbVioChannelUnregister ();
IMPORT int wdbVioDrv ();
IMPORT int wdbVioLibInit ();
IMPORT int wdbXdrCreate ();
IMPORT int wdbXdrGetVal ();
IMPORT int wdbXdrGetpos ();
IMPORT int wdbXdrInline ();
IMPORT int wdbXdrPutVal ();
IMPORT int wdbXdrPutbytes ();
IMPORT int wdbXdrSetpos ();
IMPORT int whoami ();
IMPORT int windClientCont ();
IMPORT int windClientStop ();
IMPORT int windCont ();
IMPORT int windDelay ();
IMPORT int windDelete ();
IMPORT int windExit ();
IMPORT int windIntStackSet ();
IMPORT int windLoadContext ();
IMPORT int windNullReturn ();
IMPORT int windPendQFlush ();
IMPORT int windPendQGet ();
IMPORT int windPendQPut ();
IMPORT int windPendQRemove ();
IMPORT int windPendQTerminate ();
IMPORT int windPriNormalSet ();
IMPORT int windPrioritySet ();
IMPORT int windReadyQPut ();
IMPORT int windReadyQRemove ();
IMPORT int windResume ();
IMPORT int windSemDelete ();
IMPORT int windSemRWDelete ();
IMPORT int windStop ();
IMPORT int windStopClear ();
IMPORT int windSuspend ();
IMPORT int windTickAnnounce ();
IMPORT int windTickAnnounceN ();
IMPORT int windTickWaitGet ();
IMPORT int windUndelay ();
IMPORT int windWdCancel ();
IMPORT int windWdStart ();
IMPORT int workQAdd0 ();
IMPORT int workQAdd1 ();
IMPORT int workQAdd2 ();
IMPORT int workQDoWork ();
IMPORT int workQInit ();
IMPORT int workQIsEmpty;
IMPORT int workQIsPanicked;
IMPORT int workQIx;
IMPORT int workQPanic ();
IMPORT int workQPanicHook;
IMPORT int workQWorkInProgress;
IMPORT int wqsz1;
IMPORT int wqsz2;
IMPORT int wqsz3;
IMPORT int wqsz4;
IMPORT int write ();
IMPORT int write32 ();
IMPORT int write32p ();
IMPORT int writev ();
IMPORT int xattrib ();
IMPORT int xbdAddGptPartition ();
IMPORT int xbdAttach ();
IMPORT int xbdAttachExt ();
IMPORT int xbdAttachSchecdPolicyById ();
IMPORT int xbdAttachSchecdPolicyByName ();
IMPORT int xbdBioSchedAvlDelete ();
IMPORT int xbdBioSchedAvlInsert ();
IMPORT int xbdBioSchedAvlMinGet ();
IMPORT int xbdBioSchedAvlNodeShow ();
IMPORT int xbdBioSchedAvlPredecessorGet ();
IMPORT int xbdBioSchedAvlSearch ();
IMPORT int xbdBioSchedAvlShow ();
IMPORT int xbdBioSchedAvlSuccessorGet ();
IMPORT int xbdBioSchedDeadlineAttach ();
IMPORT int xbdBioSchedDeadlineAvlCompare ();
IMPORT int xbdBioSchedDeadlineBioEnq ();
IMPORT int xbdBioSchedDeadlineDetach ();
IMPORT int xbdBioSchedDeadlineDispatch ();
IMPORT int xbdBioSchedDeadlineFini ();
IMPORT int xbdBioSchedDeadlineInit ();
IMPORT int xbdBioSchedDeadlinePolicy;
IMPORT int xbdBioSchedDeadlineReqDeq ();
IMPORT int xbdBioSchedDeadlineReqDone ();
IMPORT int xbdBioSchedDeadlineReqEnq ();
IMPORT int xbdBioSchedDeadlineReqGet ();
IMPORT int xbdBioSchedDeadlineReqMerged ();
IMPORT int xbdBioSchedDeadlineReqNext ();
IMPORT int xbdBioSchedDeadlineReqPrev ();
IMPORT int xbdBioSchedDeadlineReqPut ();
IMPORT int xbdBioSchedDeadlineShow ();
IMPORT int xbdBioSchedExit ();
IMPORT int xbdBioSchedFindBackMerge ();
IMPORT int xbdBioSchedFindBackMergeByHash ();
IMPORT int xbdBioSchedFindFrontMerge ();
IMPORT int xbdBioSchedFindFrontMergeByHash ();
IMPORT int xbdBioSchedFlush ();
IMPORT int xbdBioSchedGetAvlNode ();
IMPORT int xbdBioSchedHashNodeShow ();
IMPORT int xbdBioSchedInit ();
IMPORT int xbdBioSchedMaxActiveReqsSet ();
IMPORT int xbdBioSchedMaxBiosPerReqSet ();
IMPORT int xbdBioSchedMaxBlksPerBioSet ();
IMPORT int xbdBioSchedMaxBlksPerReqSet ();
IMPORT int xbdBioSchedMergeAdd ();
IMPORT int xbdBioSchedMergeBio ();
IMPORT int xbdBioSchedMergeRemove ();
IMPORT int xbdBioSchedPolicyAdd ();
IMPORT int xbdBioSchedPolicyAttach ();
IMPORT int xbdBioSchedPolicyDettach ();
IMPORT int xbdBioSchedPolicyNoop;
IMPORT int xbdBioSchedPolicyNoopAttach ();
IMPORT int xbdBioSchedPolicyNoopBioEnQ ();
IMPORT int xbdBioSchedPolicyNoopDetach ();
IMPORT int xbdBioSchedPolicyNoopDispatch ();
IMPORT int xbdBioSchedPolicyNoopFini ();
IMPORT int xbdBioSchedPolicyNoopInit ();
IMPORT int xbdBioSchedPolicyNoopReqDeQ ();
IMPORT int xbdBioSchedPolicyNoopReqDone ();
IMPORT int xbdBioSchedPolicyNoopReqEnQ ();
IMPORT int xbdBioSchedPolicyNoopReqGet ();
IMPORT int xbdBioSchedPolicyNoopReqPut ();
IMPORT int xbdBioSchedPolicyNoopShow ();
IMPORT int xbdBioSchedPolicyRemove ();
IMPORT int xbdBioSchedPolicySSD;
IMPORT int xbdBioSchedPolicySSDAttach ();
IMPORT int xbdBioSchedPolicySSDAvlCompare ();
IMPORT int xbdBioSchedPolicySSDDetach ();
IMPORT int xbdBioSchedPolicySSDDispatch ();
IMPORT int xbdBioSchedPolicySSDFini ();
IMPORT int xbdBioSchedPolicySSDInit ();
IMPORT int xbdBioSchedPolicySSDReqDeQ ();
IMPORT int xbdBioSchedPolicySSDReqDone ();
IMPORT int xbdBioSchedPolicySSDReqEnQ ();
IMPORT int xbdBioSchedPolicySSDReqGet ();
IMPORT int xbdBioSchedPolicySSDReqMerged ();
IMPORT int xbdBioSchedPolicySSDReqNext ();
IMPORT int xbdBioSchedPolicySSDReqPrev ();
IMPORT int xbdBioSchedPolicySSDReqPut ();
IMPORT int xbdBioSchedPolicySSDShow ();
IMPORT int xbdBioSchedPutAvlNode ();
IMPORT int xbdBioSchedReqDeq ();
IMPORT int xbdBioSchedReqEnq ();
IMPORT int xbdBioSchedReqGet ();
IMPORT int xbdBioSchedReqMergeable ();
IMPORT int xbdBioSchedReqMerged ();
IMPORT int xbdBioSchedReqPut ();
IMPORT int xbdBioSchedShow ();
IMPORT int xbdBioSchedStrategy ();
IMPORT int xbdBlkDevCreate ();
IMPORT int xbdBlkDevCreateSync ();
IMPORT int xbdBlkDevDelete ();
IMPORT int xbdBlkDevLibInit ();
IMPORT int xbdBlkDevServTskPri;
IMPORT int xbdBlockSize ();
IMPORT int xbdCacheInfoSet ();
IMPORT int xbdCreateGptPartition ();
IMPORT int xbdDetach ();
IMPORT int xbdDetachSchecdPolicyById ();
IMPORT int xbdDetachSchecdPolicyByName ();
IMPORT int xbdDump ();
IMPORT int xbdEventCategory;
IMPORT int xbdEventInstantiated;
IMPORT int xbdEventMediaChanged;
IMPORT int xbdEventPrimaryInsert;
IMPORT int xbdEventRemove;
IMPORT int xbdEventSecondaryInsert;
IMPORT int xbdEventSoftInsert;
IMPORT int xbdFindPolicyById ();
IMPORT int xbdFindPolicyByName ();
IMPORT int xbdGetBioSched ();
IMPORT int xbdGetNextBioGeneric ();
IMPORT int xbdGptPartAdd ();
IMPORT int xbdGptPartDevCreate ();
IMPORT int xbdGptPartFin ();
IMPORT int xbdGptPartStart ();
IMPORT int xbdGptPartVecAdd ();
IMPORT int xbdInit ();
IMPORT int xbdIoctl ();
IMPORT int xbdMapGet ();
IMPORT int xbdNBlocks ();
IMPORT int xbdPartitionDevCreate ();
IMPORT int xbdReqSchedComplete ();
IMPORT int xbdRequestBackMergeHash ();
IMPORT int xbdRequestCacheCreate ();
IMPORT int xbdRequestCacheDestroy ();
IMPORT int xbdRequestCacheLibFini ();
IMPORT int xbdRequestCacheLibInit ();
IMPORT int xbdRequestFrontMergeHash ();
IMPORT int xbdRequestHashKeyCmp ();
IMPORT int xbdRoot ();
IMPORT int xbdSchedDebug;
IMPORT int xbdSchedSSDDebug;
IMPORT int xbdSetBioSched ();
IMPORT int xbdSize ();
IMPORT int xbdSrvTaskGeneric ();
IMPORT int xbdStrategy ();
IMPORT int xbdStrategyGeneric ();
IMPORT int xbdSwitchSchecdPolicyById ();
IMPORT int xbdSwitchSchecdPolicyByName ();
IMPORT int xcopy ();
IMPORT int xdelete ();
IMPORT int xdrCksum ();
IMPORT int xdr_ARRAY ();
IMPORT int xdr_BOOL ();
IMPORT int xdr_CHECKSUM ();
IMPORT int xdr_ENUM ();
IMPORT int xdr_REFERENCE ();
IMPORT int xdr_TGT_ADDR_T ();
IMPORT int xdr_TGT_LONG_T ();
IMPORT int xdr_UINT32 ();
IMPORT int xdr_VOID ();
IMPORT int xdr_WDB_AGENT_INFO ();
IMPORT int xdr_WDB_CALL_RETURN_INFO ();
IMPORT int xdr_WDB_CONNECT_INFO ();
IMPORT int xdr_WDB_CONNECT_PARAMS ();
IMPORT int xdr_WDB_CORE ();
IMPORT int xdr_WDB_CTX ();
IMPORT int xdr_WDB_CTX_CREATE_DESC ();
IMPORT int xdr_WDB_CTX_KILL_DESC ();
IMPORT int xdr_WDB_CTX_STEP_DESC ();
IMPORT int xdr_WDB_DIRECT_CALL_RET ();
IMPORT int xdr_WDB_EVTPT_ADD_DESC ();
IMPORT int xdr_WDB_EVTPT_DEL_DESC ();
IMPORT int xdr_WDB_EVT_DATA ();
IMPORT int xdr_WDB_EVT_INFO ();
IMPORT int xdr_WDB_MEM_REGION ();
IMPORT int xdr_WDB_MEM_SCAN_DESC ();
IMPORT int xdr_WDB_MEM_XFER ();
IMPORT int xdr_WDB_MOD_INFO ();
IMPORT int xdr_WDB_OPQ_DATA_T ();
IMPORT int xdr_WDB_PARAM_WRAPPER ();
IMPORT int xdr_WDB_REG_READ_DESC ();
IMPORT int xdr_WDB_REG_WRITE_DESC ();
IMPORT int xdr_WDB_REPLY_WRAPPER ();
IMPORT int xdr_WDB_RT_INFO ();
IMPORT int xdr_WDB_SECT_INFO ();
IMPORT int xdr_WDB_SEG_INFO ();
IMPORT int xdr_WDB_STRING_ARRAY ();
IMPORT int xdr_WDB_STRING_T ();
IMPORT int xdr_WDB_SYM_ID ();
IMPORT int xdr_WDB_SYM_ID_LIST ();
IMPORT int xdr_WDB_SYM_INFO ();
IMPORT int xdr_WDB_SYM_LIST ();
IMPORT int xdr_WDB_SYM_MOD_DESC ();
IMPORT int xdr_WDB_TGT_INFO ();
IMPORT int xdr_WDB_TGT_INFO_2 ();
IMPORT int xh;
IMPORT int xpFuncs;
IMPORT int yzgm;
IMPORT int zbufCreate ();
IMPORT int zbufCut ();
IMPORT int zbufDelete ();
IMPORT int zbufDup ();
IMPORT int zbufExtractCopy ();
IMPORT int zbufInsert ();
IMPORT int zbufInsertBuf ();
IMPORT int zbufInsertBuf64 ();
IMPORT int zbufInsertCopy ();
IMPORT int zbufLength ();
IMPORT int zbufLibInit ();
IMPORT int zbufSegData ();
IMPORT int zbufSegFind ();
IMPORT int zbufSegLength ();
IMPORT int zbufSegNext ();
IMPORT int zbufSegPrev ();
IMPORT int zbufSockBufSend ();
IMPORT int zbufSockBufSend64 ();
IMPORT int zbufSockBufSendto ();
IMPORT int zbufSockBufSendto64 ();
IMPORT int zbufSockLibInit ();
IMPORT int zbufSockRecv ();
IMPORT int zbufSockRecvfrom ();
IMPORT int zbufSockSend ();
IMPORT int zbufSockSendto ();
IMPORT int zbufSplit ();
IMPORT int zbuf_free ();

SYMBOL standTbl [6737] =
    {
        {{NULL}, "BLOCKS_PER_DATA_DIR_CACHE_GROUP", (char*) &BLOCKS_PER_DATA_DIR_CACHE_GROUP, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "BLOCKS_PER_FAT_CACHE_GROUP", (char*) &BLOCKS_PER_FAT_CACHE_GROUP, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "BRAM_IRQ_Clr", (char*) BRAM_IRQ_Clr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "BRAM_IRQ_Set", (char*) BRAM_IRQ_Set, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "BRAM_Read", (char*) BRAM_Read, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ConfigTaskManager", (char*) ConfigTaskManager, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ConnectionManagerTask", (char*) ConnectionManagerTask, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "EVP_DecodeBlock", (char*) EVP_DecodeBlock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "EVP_DecodeFinal", (char*) EVP_DecodeFinal, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "EVP_DecodeInit", (char*) EVP_DecodeInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "EVP_DecodeUpdate", (char*) EVP_DecodeUpdate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "EVP_EncodeBlock", (char*) EVP_EncodeBlock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "EVP_EncodeFinal", (char*) EVP_EncodeFinal, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "EVP_EncodeInit", (char*) EVP_EncodeInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "EVP_EncodeUpdate", (char*) EVP_EncodeUpdate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_ConfigTable", (char*) &FDmaPs_ConfigTable, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "FDmaPs_IRQ", (char*) FDmaPs_IRQ, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_LookupConfig", (char*) FDmaPs_LookupConfig, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_addLliItem", (char*) FDmaPs_addLliItem, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_autoCompParams", (char*) FDmaPs_autoCompParams, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_checkChannelBusy", (char*) FDmaPs_checkChannelBusy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_checkChannelRange", (char*) FDmaPs_checkChannelRange, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_clearIrq", (char*) FDmaPs_clearIrq, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_destinationReady", (char*) FDmaPs_destinationReady, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_disable", (char*) FDmaPs_disable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_disableChannel", (char*) FDmaPs_disableChannel, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_disableChannelIrq", (char*) FDmaPs_disableChannelIrq, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_enable", (char*) FDmaPs_enable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_enableChannel", (char*) FDmaPs_enableChannel, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_enableChannelIrq", (char*) FDmaPs_enableChannelIrq, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_funcVerify", (char*) FDmaPs_funcVerify, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getAddress", (char*) FDmaPs_getAddress, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getAddressInc", (char*) FDmaPs_getAddressInc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getBlockByteCount", (char*) FDmaPs_getBlockByteCount, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getBlockCount", (char*) FDmaPs_getBlockCount, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getBlockTransSize", (char*) FDmaPs_getBlockTransSize, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getBurstTransLength", (char*) FDmaPs_getBurstTransLength, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getChannelConfig", (char*) FDmaPs_getChannelConfig, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getChannelEnableReg", (char*) FDmaPs_getChannelEnableReg, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getChannelFifoDepth", (char*) FDmaPs_getChannelFifoDepth, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getChannelIndex", (char*) FDmaPs_getChannelIndex, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getChannelPriority", (char*) FDmaPs_getChannelPriority, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getFifoMode", (char*) FDmaPs_getFifoMode, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getFlowCtlMode", (char*) FDmaPs_getFlowCtlMode, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getFreeChannel", (char*) FDmaPs_getFreeChannel, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getGatherEnable", (char*) FDmaPs_getGatherEnable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getGatherParam", (char*) FDmaPs_getGatherParam, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getHandshakingMode", (char*) FDmaPs_getHandshakingMode, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getHsInterface", (char*) FDmaPs_getHsInterface, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getHsPolarity", (char*) FDmaPs_getHsPolarity, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getListMstSelect", (char*) FDmaPs_getListMstSelect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getListPointerAddress", (char*) FDmaPs_getListPointerAddress, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getLlpEnable", (char*) FDmaPs_getLlpEnable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getLockEnable", (char*) FDmaPs_getLockEnable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getLockLevel", (char*) FDmaPs_getLockLevel, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getMaxAmbaBurstLength", (char*) FDmaPs_getMaxAmbaBurstLength, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getMemPeriphFlowCtl", (char*) FDmaPs_getMemPeriphFlowCtl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getMstSelect", (char*) FDmaPs_getMstSelect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getNumChannels", (char*) FDmaPs_getNumChannels, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getProtCtl", (char*) FDmaPs_getProtCtl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getReload", (char*) FDmaPs_getReload, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getScatterEnable", (char*) FDmaPs_getScatterEnable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getScatterParam", (char*) FDmaPs_getScatterParam, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getSoftwareRequest", (char*) FDmaPs_getSoftwareRequest, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getStatUpdate", (char*) FDmaPs_getStatUpdate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getStatus", (char*) FDmaPs_getStatus, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getStatusAddress", (char*) FDmaPs_getStatusAddress, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getTestMode", (char*) FDmaPs_getTestMode, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getTransWidth", (char*) FDmaPs_getTransWidth, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_getTransferType", (char*) FDmaPs_getTransferType, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_init", (char*) FDmaPs_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_initDev", (char*) FDmaPs_initDev, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_irqHandler", (char*) FDmaPs_irqHandler, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_isBlockTransDone", (char*) FDmaPs_isBlockTransDone, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_isChannelEnabled", (char*) FDmaPs_isChannelEnabled, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_isChannelIrqEnabled", (char*) FDmaPs_isChannelIrqEnabled, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_isChannelSuspended", (char*) FDmaPs_isChannelSuspended, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_isEnabled", (char*) FDmaPs_isEnabled, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_isFifoEmpty", (char*) FDmaPs_isFifoEmpty, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_isIrqActive", (char*) FDmaPs_isIrqActive, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_isIrqMasked", (char*) FDmaPs_isIrqMasked, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_isRawIrqActive", (char*) FDmaPs_isRawIrqActive, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_maskIrq", (char*) FDmaPs_maskIrq, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_nextBlockIsLast", (char*) FDmaPs_nextBlockIsLast, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_resetController", (char*) FDmaPs_resetController, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_resetInstance", (char*) FDmaPs_resetInstance, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_resumeChannel", (char*) FDmaPs_resumeChannel, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setAddress", (char*) FDmaPs_setAddress, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setAddressInc", (char*) FDmaPs_setAddressInc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setBlockTransSize", (char*) FDmaPs_setBlockTransSize, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setBurstTransLength", (char*) FDmaPs_setBurstTransLength, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setChannelConfig", (char*) FDmaPs_setChannelConfig, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setChannelPriority", (char*) FDmaPs_setChannelPriority, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setChannelPriorityOrder", (char*) FDmaPs_setChannelPriorityOrder, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setFifoMode", (char*) FDmaPs_setFifoMode, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setFlowCtlMode", (char*) FDmaPs_setFlowCtlMode, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setGatherEnable", (char*) FDmaPs_setGatherEnable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setGatherParam", (char*) FDmaPs_setGatherParam, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setHandshakingMode", (char*) FDmaPs_setHandshakingMode, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setHsInterface", (char*) FDmaPs_setHsInterface, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setHsPolarity", (char*) FDmaPs_setHsPolarity, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setListMstSelect", (char*) FDmaPs_setListMstSelect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setListPointerAddress", (char*) FDmaPs_setListPointerAddress, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setListener", (char*) FDmaPs_setListener, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setLlpEnable", (char*) FDmaPs_setLlpEnable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setLockEnable", (char*) FDmaPs_setLockEnable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setLockLevel", (char*) FDmaPs_setLockLevel, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setMaxAmbaBurstLength", (char*) FDmaPs_setMaxAmbaBurstLength, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setMemPeriphFlowCtl", (char*) FDmaPs_setMemPeriphFlowCtl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setMstSelect", (char*) FDmaPs_setMstSelect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setProtCtl", (char*) FDmaPs_setProtCtl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setReload", (char*) FDmaPs_setReload, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setScatterEnable", (char*) FDmaPs_setScatterEnable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setScatterParam", (char*) FDmaPs_setScatterParam, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setSingleRegion", (char*) FDmaPs_setSingleRegion, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setSoftwareRequest", (char*) FDmaPs_setSoftwareRequest, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setStatUpdate", (char*) FDmaPs_setStatUpdate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setStatus", (char*) FDmaPs_setStatus, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setStatusAddress", (char*) FDmaPs_setStatusAddress, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setTestMode", (char*) FDmaPs_setTestMode, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setTransWidth", (char*) FDmaPs_setTransWidth, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_setTransferType", (char*) FDmaPs_setTransferType, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_sourceReady", (char*) FDmaPs_sourceReady, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_startTransfer", (char*) FDmaPs_startTransfer, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_suspendChannel", (char*) FDmaPs_suspendChannel, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_unmaskIrq", (char*) FDmaPs_unmaskIrq, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FDmaPs_userIrqHandler", (char*) FDmaPs_userIrqHandler, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_CfgTbl", (char*) &FSdmmcPs_CfgTbl, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "FSdmmcPs_IRQ", (char*) FSdmmcPs_IRQ, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_LookupConfig", (char*) FSdmmcPs_LookupConfig, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_addSdDevice", (char*) FSdmmcPs_addSdDevice, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_cardDataTransfer", (char*) FSdmmcPs_cardDataTransfer, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_cardDetect", (char*) FSdmmcPs_cardDetect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_cardIdentify", (char*) FSdmmcPs_cardIdentify, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_cardInitializeVerify", (char*) FSdmmcPs_cardInitializeVerify, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_cfgInitialize", (char*) FSdmmcPs_cfgInitialize, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_changeBusSpeed", (char*) FSdmmcPs_changeBusSpeed, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_checkCardState", (char*) FSdmmcPs_checkCardState, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_disableIntMask", (char*) FSdmmcPs_disableIntMask, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_doTransfer", (char*) FSdmmcPs_doTransfer, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_enableDMA", (char*) FSdmmcPs_enableDMA, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_enableInt", (char*) FSdmmcPs_enableInt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_getBlockNumbers", (char*) FSdmmcPs_getBlockNumbers, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_getBusSpeed", (char*) FSdmmcPs_getBusSpeed, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_getCardSizeKB", (char*) FSdmmcPs_getCardSizeKB, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_getCardStatus", (char*) FSdmmcPs_getCardStatus, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_getIntMask", (char*) FSdmmcPs_getIntMask, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_getMaskIntStat", (char*) FSdmmcPs_getMaskIntStat, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_getMmcExtCsd", (char*) FSdmmcPs_getMmcExtCsd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_getRawIntStat", (char*) FSdmmcPs_getRawIntStat, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_getSdSCR", (char*) FSdmmcPs_getSdSCR, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_getTransferMode", (char*) FSdmmcPs_getTransferMode, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_initCard", (char*) FSdmmcPs_initCard, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_initDev", (char*) FSdmmcPs_initDev, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_initDmac", (char*) FSdmmcPs_initDmac, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_initSdmmcCtrl", (char*) FSdmmcPs_initSdmmcCtrl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_instanceReset", (char*) FSdmmcPs_instanceReset, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_intVerify", (char*) FSdmmcPs_intVerify, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_irqHandler", (char*) FSdmmcPs_irqHandler, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_mmcEnumerate", (char*) FSdmmcPs_mmcEnumerate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_powerDown", (char*) FSdmmcPs_powerDown, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_powerUp", (char*) FSdmmcPs_powerUp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_prepareCmd", (char*) FSdmmcPs_prepareCmd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_readFun", (char*) FSdmmcPs_readFun, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_readWriteData", (char*) FSdmmcPs_readWriteData, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_regInitCheck", (char*) FSdmmcPs_regInitCheck, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_regRdWtCheck", (char*) FSdmmcPs_regRdWtCheck, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_removeSdDevice", (char*) FSdmmcPs_removeSdDevice, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_resetCheck", (char*) FSdmmcPs_resetCheck, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_resetController", (char*) FSdmmcPs_resetController, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_sdControllerReset", (char*) FSdmmcPs_sdControllerReset, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_sdDmaReset", (char*) FSdmmcPs_sdDmaReset, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_sdEnumerate", (char*) FSdmmcPs_sdEnumerate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_sdFifoReset", (char*) FSdmmcPs_sdFifoReset, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_sendCmd", (char*) FSdmmcPs_sendCmd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_sendRwCmd", (char*) FSdmmcPs_sendRwCmd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_setBlockLen", (char*) FSdmmcPs_setBlockLen, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_setCardBusWidth", (char*) FSdmmcPs_setCardBusWidth, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_setCardVoltage", (char*) FSdmmcPs_setCardVoltage, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_setClock", (char*) FSdmmcPs_setClock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_setCtrlBuswidth", (char*) FSdmmcPs_setCtrlBuswidth, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_setDmaMsize", (char*) FSdmmcPs_setDmaMsize, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_setIntMask", (char*) FSdmmcPs_setIntMask, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_setRXwmark", (char*) FSdmmcPs_setRXwmark, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_setRawIntStat", (char*) FSdmmcPs_setRawIntStat, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_setTXwmark", (char*) FSdmmcPs_setTXwmark, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_stopTransfer", (char*) FSdmmcPs_stopTransfer, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_verify", (char*) FSdmmcPs_verify, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_waitWriteDone", (char*) FSdmmcPs_waitWriteDone, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSdmmcPs_writeFun", (char*) FSdmmcPs_writeFun, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSlcrPS_regRead", (char*) FSlcrPS_regRead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSlcrPS_rsvRegPrint", (char*) FSlcrPS_rsvRegPrint, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSlcrPS_setCanLoop", (char*) FSlcrPS_setCanLoop, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSlcrPS_setI2cLoop", (char*) FSlcrPS_setI2cLoop, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSlcrPS_setSpiLoop", (char*) FSlcrPS_setSpiLoop, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSlcrPS_setUartLoop", (char*) FSlcrPS_setUartLoop, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSlcrPs_ipReleaseRst", (char*) FSlcrPs_ipReleaseRst, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSlcrPs_ipSetRst", (char*) FSlcrPs_ipSetRst, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSlcrPs_lock", (char*) FSlcrPs_lock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSlcrPs_setBitTo0", (char*) FSlcrPs_setBitTo0, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSlcrPs_setBitTo1", (char*) FSlcrPs_setBitTo1, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSlcrPs_softRst", (char*) FSlcrPs_softRst, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FSlcrPs_unlock", (char*) FSlcrPs_unlock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "FileDataCmp", (char*) FileDataCmp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "Gmac_RxFilt_Dis_BroadCast", (char*) Gmac_RxFilt_Dis_BroadCast, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "Gmac_RxFilt_En_MultiCast", (char*) Gmac_RxFilt_En_MultiCast, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "GpioClose", (char*) GpioClose, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "GpioCreate", (char*) GpioCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "GpioDevCreate", (char*) GpioDevCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "GpioDevNamePrefix", (char*) &GpioDevNamePrefix, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "GpioDrv", (char*) GpioDrv, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "GpioDrvNum", (char*) &GpioDrvNum, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "GpioIoCtl", (char*) GpioIoCtl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "GpioOpen", (char*) GpioOpen, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "GpioRead", (char*) GpioRead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "GpioRemove", (char*) GpioRemove, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "GpioWrite", (char*) GpioWrite, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "Hzk1", (char*) &Hzk1, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "Hzk2", (char*) &Hzk2, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "Hzk3", (char*) &Hzk3, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "Hzk4", (char*) &Hzk4, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "MD5_Final", (char*) MD5_Final, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "MD5_Init", (char*) MD5_Init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "MD5_Transform", (char*) MD5_Transform, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "MD5_Update", (char*) MD5_Update, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "MD5_version", (char*) &MD5_version, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "OLED_Clear", (char*) OLED_Clear, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "OLED_ColorTurn", (char*) OLED_ColorTurn, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "OLED_DisPlay_Off", (char*) OLED_DisPlay_Off, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "OLED_DisPlay_On", (char*) OLED_DisPlay_On, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "OLED_DisplayTurn", (char*) OLED_DisplayTurn, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "OLED_DrawCircle", (char*) OLED_DrawCircle, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "OLED_DrawLine", (char*) OLED_DrawLine, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "OLED_DrawPoint", (char*) OLED_DrawPoint, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "OLED_GRAM", (char*) &OLED_GRAM, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "OLED_Init", (char*) OLED_Init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "OLED_Pow", (char*) OLED_Pow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "OLED_Refresh", (char*) OLED_Refresh, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "OLED_ScrollDisplay", (char*) OLED_ScrollDisplay, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "OLED_ShowChar", (char*) OLED_ShowChar, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "OLED_ShowChinese", (char*) OLED_ShowChinese, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "OLED_ShowChinesetip", (char*) OLED_ShowChinesetip, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "OLED_ShowNum", (char*) OLED_ShowNum, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "OLED_ShowPicture", (char*) OLED_ShowPicture, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "OLED_ShowString", (char*) OLED_ShowString, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "OLED_WR_Byte", (char*) OLED_WR_Byte, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "RcvBuf2", (char*) &RcvBuf2, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "RealTimeSchedulerTask", (char*) RealTimeSchedulerTask, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "SDMMC_decodeCID", (char*) SDMMC_decodeCID, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "SDMMC_decodeCSD", (char*) SDMMC_decodeCSD, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "SDMMC_getCSDInfo", (char*) SDMMC_getCSDInfo, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "SHA1_Final", (char*) SHA1_Final, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "SHA1_Init", (char*) SHA1_Init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "SHA1_Transform", (char*) SHA1_Transform, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "SHA1_Update", (char*) SHA1_Update, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "SHA1_version", (char*) &SHA1_version, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "SHA224", (char*) SHA224, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "SHA224_Final", (char*) SHA224_Final, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "SHA224_Init", (char*) SHA224_Init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "SHA224_Update", (char*) SHA224_Update, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "SHA256", (char*) SHA256, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "SHA256_Final", (char*) SHA256_Final, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "SHA256_Init", (char*) SHA256_Init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "SHA256_Transform", (char*) SHA256_Transform, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "SHA256_Update", (char*) SHA256_Update, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "SHA256_version", (char*) &SHA256_version, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "SetNewSeedtoRandomGenerator", (char*) SetNewSeedtoRandomGenerator, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "SndBuf2", (char*) &SndBuf2, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "UdpSearchTask", (char*) UdpSearchTask, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ZBUF_GETSEG", (char*) ZBUF_GETSEG, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_Jv_Balloc", (char*) _Jv_Balloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_Jv_Bfree", (char*) _Jv_Bfree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_Jv__mcmp", (char*) _Jv__mcmp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_Jv__mdiff", (char*) _Jv__mdiff, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_Jv__mprec_bigtens", (char*) &_Jv__mprec_bigtens, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_Jv__mprec_tens", (char*) &_Jv__mprec_tens, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_Jv__mprec_tinytens", (char*) &_Jv__mprec_tinytens, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_Jv_b2d", (char*) _Jv_b2d, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_Jv_d2b", (char*) _Jv_d2b, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_Jv_dtoa_r", (char*) _Jv_dtoa_r, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_Jv_hi0bits", (char*) _Jv_hi0bits, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_Jv_i2b", (char*) _Jv_i2b, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_Jv_lo0bits", (char*) _Jv_lo0bits, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_Jv_lshift", (char*) _Jv_lshift, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_Jv_mult", (char*) _Jv_mult, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_Jv_multadd", (char*) _Jv_multadd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_Jv_pow5mult", (char*) _Jv_pow5mult, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_Jv_ratio", (char*) _Jv_ratio, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_Jv_s2b", (char*) _Jv_s2b, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_Jv_ulp", (char*) _Jv_ulp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_Randseed", (char*) &_Randseed, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_STI__07__diab_atomic_init", (char*) _STI__07__diab_atomic_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__DIAB_rd_pk_db", (char*) __DIAB_rd_pk_db, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__DIAB_rd_pk_fl", (char*) __DIAB_rd_pk_fl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__DIAB_rd_pk_ld", (char*) __DIAB_rd_pk_ld, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__DIAB_rd_sw_db", (char*) __DIAB_rd_sw_db, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__DIAB_rd_sw_fl", (char*) __DIAB_rd_sw_fl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__DIAB_rd_sw_ld", (char*) __DIAB_rd_sw_ld, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__DIAB_wr_pk_db", (char*) __DIAB_wr_pk_db, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__DIAB_wr_pk_fl", (char*) __DIAB_wr_pk_fl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__DIAB_wr_pk_ld", (char*) __DIAB_wr_pk_ld, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__DIAB_wr_sw_db", (char*) __DIAB_wr_sw_db, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__DIAB_wr_sw_fl", (char*) __DIAB_wr_sw_fl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__DIAB_wr_sw_ld", (char*) __DIAB_wr_sw_ld, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__POL", (char*) __POL, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "___x_diab_arm_div_o", (char*) &___x_diab_arm_div_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_comljmp_o", (char*) &___x_diab_comljmp_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_copytable_o", (char*) &___x_diab_copytable_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_crtlibso_o", (char*) &___x_diab_crtlibso_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_ctordtor_o", (char*) &___x_diab_ctordtor_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_ff1_o", (char*) &___x_diab_ff1_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_libg_o", (char*) &___x_diab_libg_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_rd_pk_db_o", (char*) &___x_diab_rd_pk_db_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_rd_pk_fl_o", (char*) &___x_diab_rd_pk_fl_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_rd_pk_ld_o", (char*) &___x_diab_rd_pk_ld_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_rd_sw_db_o", (char*) &___x_diab_rd_sw_db_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_rd_sw_fl_o", (char*) &___x_diab_rd_sw_fl_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_rd_sw_ld_o", (char*) &___x_diab_rd_sw_ld_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpdadd_o", (char*) &___x_diab_sfpdadd_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpdcmp_o", (char*) &___x_diab_sfpdcmp_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpdcmpe_o", (char*) &___x_diab_sfpdcmpe_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpddiv_o", (char*) &___x_diab_sfpddiv_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpddtof_o", (char*) &___x_diab_sfpddtof_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpddtoi_o", (char*) &___x_diab_sfpddtoi_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpddtou_o", (char*) &___x_diab_sfpddtou_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpdfeq_o", (char*) &___x_diab_sfpdfeq_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpdfge_o", (char*) &___x_diab_sfpdfge_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpdfgt_o", (char*) &___x_diab_sfpdfgt_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpdfle_o", (char*) &___x_diab_sfpdfle_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpdflt_o", (char*) &___x_diab_sfpdflt_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpdfne_o", (char*) &___x_diab_sfpdfne_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpditod_o", (char*) &___x_diab_sfpditod_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpdlltod_o", (char*) &___x_diab_sfpdlltod_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpdmul_o", (char*) &___x_diab_sfpdmul_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpdneg_o", (char*) &___x_diab_sfpdneg_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpdnorm_o", (char*) &___x_diab_sfpdnorm_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpdpol_o", (char*) &___x_diab_sfpdpol_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpdsetup_o", (char*) &___x_diab_sfpdsetup_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpdutod_o", (char*) &___x_diab_sfpdutod_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpfadd_o", (char*) &___x_diab_sfpfadd_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpfcmp_o", (char*) &___x_diab_sfpfcmp_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpfcmpe_o", (char*) &___x_diab_sfpfcmpe_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpfdiv_o", (char*) &___x_diab_sfpfdiv_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpffeq_o", (char*) &___x_diab_sfpffeq_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpffge_o", (char*) &___x_diab_sfpffge_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpffgt_o", (char*) &___x_diab_sfpffgt_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpffle_o", (char*) &___x_diab_sfpffle_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpfflt_o", (char*) &___x_diab_sfpfflt_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpffne_o", (char*) &___x_diab_sfpffne_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpfftod_o", (char*) &___x_diab_sfpfftod_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpfftoi_o", (char*) &___x_diab_sfpfftoi_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpfftou_o", (char*) &___x_diab_sfpfftou_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpfitof_o", (char*) &___x_diab_sfpfitof_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpflltof_o", (char*) &___x_diab_sfpflltof_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpfmul_o", (char*) &___x_diab_sfpfmul_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpfneg_o", (char*) &___x_diab_sfpfneg_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpfnorm_o", (char*) &___x_diab_sfpfnorm_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpfsetup_o", (char*) &___x_diab_sfpfsetup_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpfulltof_o", (char*) &___x_diab_sfpfulltof_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpfutof_o", (char*) &___x_diab_sfpfutof_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sfpround_o", (char*) &___x_diab_sfpround_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sxpadd64_o", (char*) &___x_diab_sxpadd64_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sxpasr64_o", (char*) &___x_diab_sxpasr64_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sxpcmp64_o", (char*) &___x_diab_sxpcmp64_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sxpdiv64_o", (char*) &___x_diab_sxpdiv64_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sxplsl64_o", (char*) &___x_diab_sxplsl64_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sxplsr64_o", (char*) &___x_diab_sxplsr64_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sxpm6432_o", (char*) &___x_diab_sxpm6432_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sxpmul64_o", (char*) &___x_diab_sxpmul64_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sxprem32_o", (char*) &___x_diab_sxprem32_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_sxprem64_o", (char*) &___x_diab_sxprem64_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_torn_syncatomic_o", (char*) &___x_diab_torn_syncatomic_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_torn_syncmutex_o", (char*) &___x_diab_torn_syncmutex_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_torn_syncsem_o", (char*) &___x_diab_torn_syncsem_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_wr_pk_db_o", (char*) &___x_diab_wr_pk_db_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_wr_pk_fl_o", (char*) &___x_diab_wr_pk_fl_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_wr_pk_ld_o", (char*) &___x_diab_wr_pk_ld_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_wr_sw_db_o", (char*) &___x_diab_wr_sw_db_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_wr_sw_fl_o", (char*) &___x_diab_wr_sw_fl_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "___x_diab_wr_sw_ld_o", (char*) &___x_diab_wr_sw_ld_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "__add64", (char*) __add64, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__arm_call_via_o", (char*) &__arm_call_via_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "__asr64", (char*) __asr64, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__assert", (char*) __assert, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__clocale", (char*) &__clocale, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "__common_intrinsicsInit", (char*) __common_intrinsicsInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__common_long_jmp", (char*) __common_long_jmp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__copy", (char*) __copy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__copy_multiple", (char*) __copy_multiple, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__costate", (char*) &__costate, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "__cplusLoadObjFiles", (char*) &__cplusLoadObjFiles, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "__cplusLoad_o", (char*) &__cplusLoad_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "__cplusUsr_o", (char*) &__cplusUsr_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "__cplusXtors_o", (char*) &__cplusXtors_o, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "__ctype", (char*) &__ctype, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "__ctype_tolower", (char*) &__ctype_tolower, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "__ctype_toupper", (char*) &__ctype_toupper, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "__daysSinceEpoch", (char*) __daysSinceEpoch, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__diab_alloc_mutex", (char*) __diab_alloc_mutex, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__diab_alloc_semaphore", (char*) __diab_alloc_semaphore, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__diab_atomic_enter", (char*) __diab_atomic_enter, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__diab_atomic_restore", (char*) __diab_atomic_restore, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__diab_free_mutex", (char*) __diab_free_mutex, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__diab_free_semaphore", (char*) __diab_free_semaphore, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__diab_intrinsics_impfpInit", (char*) __diab_intrinsics_impfpInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__diab_intrinsics_implInit", (char*) __diab_intrinsics_implInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__diab_intrinsics_tornInit", (char*) __diab_intrinsics_tornInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__diab_lock_mutex", (char*) __diab_lock_mutex, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__diab_lock_semaphore", (char*) __diab_lock_semaphore, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__diab_trylock_mutex", (char*) __diab_trylock_mutex, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__diab_trylock_semaphore", (char*) __diab_trylock_semaphore, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__diab_unlock_mutex", (char*) __diab_unlock_mutex, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__diab_unlock_semaphore", (char*) __diab_unlock_semaphore, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__div32", (char*) __div32, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__div64", (char*) __div64, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__dtoa", (char*) __dtoa, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__dtof", (char*) __dtof, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__dtoi", (char*) __dtoi, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__dtou", (char*) __dtou, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__eq64", (char*) __eq64, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__errno", (char*) __errno, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__exec_ctors", (char*) __exec_ctors, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__exec_dtors", (char*) __exec_dtors, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__exec_xtor_table", (char*) &__exec_xtor_table, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "__ff1", (char*) __ff1, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__ff1l", (char*) __ff1l, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__ff1ll", (char*) __ff1ll, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__fini", (char*) __fini, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__fixdfdi", (char*) __fixdfdi, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__fixsfdi", (char*) __fixsfdi, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__fixunsdfdi", (char*) __fixunsdfdi, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__fixunssfdi", (char*) __fixunssfdi, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__floatdidf", (char*) __floatdidf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__floatdisf", (char*) __floatdisf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__floatundidf", (char*) __floatundidf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__floatundidf_o", (char*) &__floatundidf_o, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "__ftod", (char*) __ftod, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__ftoi", (char*) __ftoi, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__ftou", (char*) __ftou, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__ge64", (char*) __ge64, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__getDstInfo", (char*) __getDstInfo, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__getDstInfoSub", (char*) __getDstInfoSub, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__getTime", (char*) __getTime, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__getZoneInfo", (char*) __getZoneInfo, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__gt64", (char*) __gt64, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__ieee754_rem_pio2", (char*) __ieee754_rem_pio2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__ieee_status", (char*) __ieee_status, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__includeDiabIntrinsics", (char*) &__includeDiabIntrinsics, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "__init", (char*) __init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__itod", (char*) __itod, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__itof", (char*) __itof, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__julday", (char*) __julday, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__kernel_cos", (char*) __kernel_cos, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__kernel_rem_pio2", (char*) __kernel_rem_pio2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__kernel_sin", (char*) __kernel_sin, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__kernel_tan", (char*) __kernel_tan, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__le64", (char*) __le64, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__lltod", (char*) __lltod, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__lltof", (char*) __lltof, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__locale", (char*) &__locale, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "__loctime", (char*) &__loctime, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "__lsl64", (char*) __lsl64, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__lsr64", (char*) __lsr64, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__lt64", (char*) __lt64, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__mul64", (char*) __mul64, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__mul6432", (char*) __mul6432, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__ne64", (char*) __ne64, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__rem32", (char*) __rem32, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__rem64", (char*) __rem64, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__rta_longjmp", (char*) &__rta_longjmp, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "__sclose", (char*) __sclose, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__sflags", (char*) __sflags, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__sflush", (char*) __sflush, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__sfpRoundMode", (char*) &__sfpRoundMode, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "__sfvwrite", (char*) __sfvwrite, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__smakebuf", (char*) __smakebuf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__sread", (char*) __sread, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__srefill", (char*) __srefill, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__srget", (char*) __srget, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__sseek", (char*) __sseek, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__stderr", (char*) __stderr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__stdin", (char*) __stdin, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__stdout", (char*) __stdout, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__strxfrm", (char*) __strxfrm, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__sub64", (char*) __sub64, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__swbuf", (char*) __swbuf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__swrite", (char*) __swrite, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__swsetup", (char*) __swsetup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__taskVarAdd", (char*) __taskVarAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__taskVarDelete", (char*) __taskVarDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__taskVarGet", (char*) __taskVarGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__taskVarSet", (char*) __taskVarSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__udiv32", (char*) __udiv32, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__udiv64", (char*) __udiv64, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__uge64", (char*) __uge64, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__ugt64", (char*) __ugt64, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__ule64", (char*) __ule64, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__ulltof", (char*) __ulltof, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__ult64", (char*) __ult64, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__urem32", (char*) __urem32, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__urem64", (char*) __urem64, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__utod", (char*) __utod, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__utof", (char*) __utof, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "__wdbEventListIsEmpty", (char*) &__wdbEventListIsEmpty, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_applLog", (char*) _applLog, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_archHelp_msg", (char*) &_archHelp_msg, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_archIORead16", (char*) _archIORead16, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_archIORead32", (char*) _archIORead32, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_archIORead8", (char*) _archIORead8, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_archIOWrite16", (char*) _archIOWrite16, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_archIOWrite32", (char*) _archIOWrite32, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_archIOWrite8", (char*) _archIOWrite8, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_clockRealtime", (char*) &_clockRealtime, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_d_add", (char*) _d_add, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_d_cmp", (char*) _d_cmp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_d_cmpe", (char*) _d_cmpe, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_d_div", (char*) _d_div, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_d_dtof", (char*) _d_dtof, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_d_dtoi", (char*) _d_dtoi, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_d_dtoll", (char*) _d_dtoll, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_d_dtou", (char*) _d_dtou, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_d_dtoull", (char*) _d_dtoull, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_d_feq", (char*) _d_feq, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_d_fge", (char*) _d_fge, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_d_fgt", (char*) _d_fgt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_d_fle", (char*) _d_fle, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_d_flt", (char*) _d_flt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_d_fne", (char*) _d_fne, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_d_fnge", (char*) _d_fnge, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_d_fngt", (char*) _d_fngt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_d_fnle", (char*) _d_fnle, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_d_fnlt", (char*) _d_fnlt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_d_itod", (char*) _d_itod, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_d_lltod", (char*) _d_lltod, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_d_mul", (char*) _d_mul, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_d_neg", (char*) _d_neg, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_d_sub", (char*) _d_sub, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_d_ulltod", (char*) _d_ulltod, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_d_utod", (char*) _d_utod, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_dbgArchInit", (char*) _dbgArchInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_dbgDsmInstRtn", (char*) &_dbgDsmInstRtn, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_dbgFuncCallCheck", (char*) _dbgFuncCallCheck, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_dbgInstSizeGet", (char*) _dbgInstSizeGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_dbgRetAdrsGet", (char*) _dbgRetAdrsGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_dbgTaskPCGet", (char*) _dbgTaskPCGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_dbgTaskPCSet", (char*) _dbgTaskPCSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_endM2Packet_1213", (char*) _endM2Packet_1213, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_endM2Packet_2233", (char*) _endM2Packet_2233, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_f_add", (char*) _f_add, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_f_cmp", (char*) _f_cmp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_f_cmpe", (char*) _f_cmpe, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_f_div", (char*) _f_div, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_f_feq", (char*) _f_feq, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_f_fge", (char*) _f_fge, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_f_fgt", (char*) _f_fgt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_f_fle", (char*) _f_fle, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_f_flt", (char*) _f_flt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_f_fne", (char*) _f_fne, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_f_fnge", (char*) _f_fnge, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_f_fngt", (char*) _f_fngt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_f_fnle", (char*) _f_fnle, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_f_fnlt", (char*) _f_fnlt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_f_ftod", (char*) _f_ftod, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_f_ftoi", (char*) _f_ftoi, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_f_ftoll", (char*) _f_ftoll, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_f_ftou", (char*) _f_ftou, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_f_ftoull", (char*) _f_ftoull, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_f_itof", (char*) _f_itof, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_f_lltof", (char*) _f_lltof, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_f_mul", (char*) _f_mul, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_f_neg", (char*) _f_neg, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_f_sub", (char*) _f_sub, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_f_ulltof", (char*) _f_ulltof, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_f_utof", (char*) _f_utof, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_fp_round", (char*) _fp_round, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_func_CPToUtf16", (char*) &_func_CPToUtf16, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_CPToUtf8", (char*) &_func_CPToUtf8, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_IntLvlChgRtn", (char*) &_func_IntLvlChgRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_IntLvlDisableRtn", (char*) &_func_IntLvlDisableRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_IntLvlEnableRtn", (char*) &_func_IntLvlEnableRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_IntLvlVecAckRtn", (char*) &_func_IntLvlVecAckRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_IntLvlVecChkRtn", (char*) &_func_IntLvlVecChkRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_aimMmuLockRegionsImport", (char*) &_func_aimMmuLockRegionsImport, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_armIntStackSplit", (char*) &_func_armIntStackSplit, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_armIrqHandler", (char*) &_func_armIrqHandler, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_armMmuCurrentGet", (char*) &_func_armMmuCurrentGet, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_armMmuCurrentSet", (char*) &_func_armMmuCurrentSet, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_cacheAimArch7DClearDisable", (char*) &_func_cacheAimArch7DClearDisable, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_cacheAimArch7IClearDisable", (char*) &_func_cacheAimArch7IClearDisable, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_cacheFuncsSet", (char*) &_func_cacheFuncsSet, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_classListAdd", (char*) &_func_classListAdd, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_classListInit", (char*) &_func_classListInit, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_classListLock", (char*) &_func_classListLock, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_classListRemove", (char*) &_func_classListRemove, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_classListTblInit", (char*) &_func_classListTblInit, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_classListUnlock", (char*) &_func_classListUnlock, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_consoleOut", (char*) &_func_consoleOut, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_coprocShow", (char*) &_func_coprocShow, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_coprocTaskRegsShow", (char*) &_func_coprocTaskRegsShow, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_dosChkStatPrint", (char*) &_func_dosChkStatPrint, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_dosDirOldShow", (char*) &_func_dosDirOldShow, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_dosFsFatShow", (char*) &_func_dosFsFatShow, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_dosFsFmtRtn", (char*) &_func_dosFsFmtRtn, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_dosVDirShow", (char*) &_func_dosVDirShow, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_end2VxBusConnect", (char*) &_func_end2VxBusConnect, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_end8023AddressForm", (char*) &_func_end8023AddressForm, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_endEtherAddressForm", (char*) &_func_endEtherAddressForm, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_endEtherPacketAddrGet", (char*) &_func_endEtherPacketAddrGet, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_endEtherPacketDataGet", (char*) &_func_endEtherPacketDataGet, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_envGet", (char*) &_func_envGet, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_eventReceive", (char*) &_func_eventReceive, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_eventRsrcSend", (char*) &_func_eventRsrcSend, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_eventRsrcShow", (char*) &_func_eventRsrcShow, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_eventSend", (char*) &_func_eventSend, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_eventTaskShow", (char*) &_func_eventTaskShow, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_eventTerminate", (char*) &_func_eventTerminate, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_excBaseHook", (char*) &_func_excBaseHook, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_excBreakpoint", (char*) &_func_excBreakpoint, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_excInfoShow", (char*) &_func_excInfoShow, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_excIntHook", (char*) &_func_excIntHook, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_excJobAdd", (char*) &_func_excJobAdd, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_excPanicHook", (char*) &_func_excPanicHook, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_exit", (char*) &_func_exit, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_fclose", (char*) &_func_fclose, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_fcntl_dup", (char*) &_func_fcntl_dup, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_fileDoesNotExist", (char*) &_func_fileDoesNotExist, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_fioFltFormatRtn", (char*) &_func_fioFltFormatRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_fioFltScanRtn", (char*) &_func_fioFltScanRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_ftpLs", (char*) &_func_ftpLs, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_ftpTransientFatal", (char*) &_func_ftpTransientFatal, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_ftruncMmanHook", (char*) &_func_ftruncMmanHook, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_handleAlloc", (char*) &_func_handleAlloc, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_handleFreeAll", (char*) &_func_handleFreeAll, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_intConnectRtn", (char*) &_func_intConnectRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_intDisconnectRtn", (char*) &_func_intDisconnectRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_ioGlobalStdGet", (char*) &_func_ioGlobalStdGet, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_ioPxCreateOrOpen", (char*) &_func_ioPxCreateOrOpen, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_ioTaskStdSet", (char*) &_func_ioTaskStdSet, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_iosOpenDrvRefCntDec", (char*) &_func_iosOpenDrvRefCntDec, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_iosOpenDrvRefCntInc", (char*) &_func_iosOpenDrvRefCntInc, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_iosPathFdEntryIoctl", (char*) &_func_iosPathFdEntryIoctl, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_iosPosixFdEntryIoctl", (char*) &_func_iosPosixFdEntryIoctl, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_iosRtpIoTableSizeGet", (char*) &_func_iosRtpIoTableSizeGet, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_iosRtpIoTableSizeSet", (char*) &_func_iosRtpIoTableSizeSet, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_isrConnect", (char*) &_func_isrConnect, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_isrCreate", (char*) &_func_isrCreate, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_isrDelete", (char*) &_func_isrDelete, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_isrDisconnect", (char*) &_func_isrDisconnect, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_isrDispatcher", (char*) &_func_isrDispatcher, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_isrInfo", (char*) &_func_isrInfo, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_jobTaskWorkAdd", (char*) &_func_jobTaskWorkAdd, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_kernelModuleListIdGet", (char*) &_func_kernelModuleListIdGet, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_kernelRoundRobinHook", (char*) &_func_kernelRoundRobinHook, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_kprintf", (char*) &_func_kprintf, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_kwrite", (char*) &_func_kwrite, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_lf_advlock", (char*) &_func_lf_advlock, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_loadRtpDeltaBaseAddrApply", (char*) &_func_loadRtpDeltaBaseAddrApply, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_loadRtpSymsPolicyOverride", (char*) &_func_loadRtpSymsPolicyOverride, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_logMsg", (char*) &_func_logMsg, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_loginPrompt2", (char*) &_func_loginPrompt2, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_loginStringGet", (char*) &_func_loginStringGet, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_loginStringSet", (char*) &_func_loginStringSet, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_m2PollStatsIfPoll", (char*) &_func_m2PollStatsIfPoll, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_memPartCacheAlloc", (char*) &_func_memPartCacheAlloc, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_memPartCacheFree", (char*) &_func_memPartCacheFree, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_memPartCacheInfoGet", (char*) &_func_memPartCacheInfoGet, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_memPartRealloc", (char*) &_func_memPartRealloc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_memPartReallocInternal", (char*) &_func_memPartReallocInternal, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_memalign", (char*) &_func_memalign, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_mmuFaultAddrGet", (char*) &_func_mmuFaultAddrGet, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_mmuFaultStatusGet", (char*) &_func_mmuFaultStatusGet, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_mmuIFaultStatusGet", (char*) &_func_mmuIFaultStatusGet, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_moduleIdFigure", (char*) &_func_moduleIdFigure, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_moduleSegInfoGet", (char*) &_func_moduleSegInfoGet, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_mux", (char*) &_func_mux, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_mux_l2", (char*) &_func_mux_l2, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_netAttrDeReg", (char*) &_func_netAttrDeReg, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_netAttrReg", (char*) &_func_netAttrReg, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_netChDirByName", (char*) &_func_netChDirByName, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_netDaemonIxToQId", (char*) &_func_netDaemonIxToQId, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_netDaemonQIdToIx", (char*) &_func_netDaemonQIdToIx, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_netLsByName", (char*) &_func_netLsByName, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_netPoolShow", (char*) &_func_netPoolShow, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_objCoreRelease", (char*) &_func_objCoreRelease, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_objHandleToObjId", (char*) &_func_objHandleToObjId, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_objNameVerifiedSet", (char*) &_func_objNameVerifiedSet, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_objOwnerListAdd", (char*) &_func_objOwnerListAdd, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_objOwnerListRemove", (char*) &_func_objOwnerListRemove, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_objOwnerReclaim", (char*) &_func_objOwnerReclaim, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_objOwnerSetBaseInternal", (char*) &_func_objOwnerSetBaseInternal, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_objOwnerSetInternal", (char*) &_func_objOwnerSetInternal, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_objRtpObjEachHook", (char*) &_func_objRtpObjEachHook, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_ownerListLock", (char*) &_func_ownerListLock, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_ownerListUnlock", (char*) &_func_ownerListUnlock, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_printErr", (char*) &_func_printErr, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_printExcPrintHook", (char*) &_func_printExcPrintHook, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_proofUtf8String", (char*) &_func_proofUtf8String, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_pthread_testandset_canceltype", (char*) &_func_pthread_testandset_canceltype, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_pxCpuTimerCancel", (char*) &_func_pxCpuTimerCancel, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_pxCpuTimerCreate", (char*) &_func_pxCpuTimerCreate, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_pxCpuTimerDelete", (char*) &_func_pxCpuTimerDelete, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_pxCpuTimerStart", (char*) &_func_pxCpuTimerStart, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_qPriBMapNativeResort", (char*) &_func_qPriBMapNativeResort, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_remCurIdGet", (char*) &_func_remCurIdGet, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_remCurIdSet", (char*) &_func_remCurIdSet, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpDelete", (char*) &_func_rtpDelete, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpDeleteHookAdd", (char*) &_func_rtpDeleteHookAdd, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpDeleteHookDelete", (char*) &_func_rtpDeleteHookDelete, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpDeletionDeferDisable", (char*) &_func_rtpDeletionDeferDisable, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpDeletionDeferEnable", (char*) &_func_rtpDeletionDeferEnable, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpExtraCmdGet", (char*) &_func_rtpExtraCmdGet, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_rtpHandleIdGet", (char*) &_func_rtpHandleIdGet, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpIdVerify", (char*) &_func_rtpIdVerify, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpInitCompleteHookAdd", (char*) &_func_rtpInitCompleteHookAdd, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpInitCompleteHookDelete", (char*) &_func_rtpInitCompleteHookDelete, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpPause", (char*) &_func_rtpPause, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpPostCreateHookAdd", (char*) &_func_rtpPostCreateHookAdd, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpPostCreateHookDelete", (char*) &_func_rtpPostCreateHookDelete, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpPreCreateHookAdd", (char*) &_func_rtpPreCreateHookAdd, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpPreCreateHookDelete", (char*) &_func_rtpPreCreateHookDelete, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpSdUnmapAll", (char*) &_func_rtpSdUnmapAll, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpShlCloseHook", (char*) &_func_rtpShlCloseHook, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpShlDeleteAll", (char*) &_func_rtpShlDeleteAll, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpShlInfoGet", (char*) &_func_rtpShlInfoGet, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpShlOpenHook", (char*) &_func_rtpShlOpenHook, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpShlSymbolsRegister", (char*) &_func_rtpShlSymbolsRegister, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpShlSymbolsUnregister", (char*) &_func_rtpShlSymbolsUnregister, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpShow", (char*) &_func_rtpShow, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpSigExcKill", (char*) &_func_rtpSigExcKill, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpSigPendDestroy", (char*) &_func_rtpSigPendDestroy, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpSigPendInit", (char*) &_func_rtpSigPendInit, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpSigPendKill", (char*) &_func_rtpSigPendKill, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpSigaction", (char*) &_func_rtpSigaction, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpSigpending", (char*) &_func_rtpSigpending, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpSigprocmask", (char*) &_func_rtpSigprocmask, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpSigqueue", (char*) &_func_rtpSigqueue, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpSigsuspend", (char*) &_func_rtpSigsuspend, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpSigtimedwait", (char*) &_func_rtpSigtimedwait, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpSpawn", (char*) &_func_rtpSpawn, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpSymTblIdGet", (char*) &_func_rtpSymTblIdGet, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_rtpTaskEach", (char*) &_func_rtpTaskEach, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpTaskKill", (char*) &_func_rtpTaskKill, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpTaskSigBlock", (char*) &_func_rtpTaskSigBlock, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpTaskSigCheck", (char*) &_func_rtpTaskSigCheck, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpTaskSigPendKill", (char*) &_func_rtpTaskSigPendKill, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpTaskSigqueue", (char*) &_func_rtpTaskSigqueue, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpVarAdd", (char*) &_func_rtpVarAdd, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_rtpVerifiedLock", (char*) &_func_rtpVerifiedLock, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_selPtyAdd", (char*) &_func_selPtyAdd, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_selPtyDelete", (char*) &_func_selPtyDelete, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_selPtySlaveAdd", (char*) &_func_selPtySlaveAdd, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_selPtySlaveDelete", (char*) &_func_selPtySlaveDelete, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_selTyAdd", (char*) &_func_selTyAdd, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_selTyDelete", (char*) &_func_selTyDelete, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_selWakeup", (char*) &_func_selWakeup, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_selWakeupAll", (char*) &_func_selWakeupAll, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_selWakeupListInit", (char*) &_func_selWakeupListInit, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_selWakeupListTerm", (char*) &_func_selWakeupListTerm, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_semExchange", (char*) &_func_semExchange, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_semRTake", (char*) &_func_semRTake, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_semWTake", (char*) &_func_semWTake, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_shellDbgCallPrint", (char*) &_func_shellDbgCallPrint, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_shellDbgStackTrace", (char*) &_func_shellDbgStackTrace, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_shellExcPrint", (char*) &_func_shellExcPrint, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_sigExcKill", (char*) &_func_sigExcKill, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_sigTimeoutRecalc", (char*) &_func_sigTimeoutRecalc, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_sigeventInit", (char*) &_func_sigeventInit, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_sigfillset", (char*) &_func_sigfillset, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_signalMmanHook", (char*) &_func_signalMmanHook, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_sigprocmask", (char*) &_func_sigprocmask, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_spy", (char*) &_func_spy, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_spy2", (char*) &_func_spy2, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_spyClkStart", (char*) &_func_spyClkStart, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_spyClkStop", (char*) &_func_spyClkStop, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_spyReport", (char*) &_func_spyReport, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_spyReport2", (char*) &_func_spyReport2, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_spyStop", (char*) &_func_spyStop, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_spyTask", (char*) &_func_spyTask, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_symEach", (char*) &_func_symEach, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_symEachCall", (char*) &_func_symEachCall, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_symFind", (char*) &_func_symFind, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_symFindSymbol", (char*) &_func_symFindSymbol, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_symNameGet", (char*) &_func_symNameGet, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_symRegister", (char*) &_func_symRegister, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_symTblShutdown", (char*) &_func_symTblShutdown, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_symTypeGet", (char*) &_func_symTypeGet, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_symValueGet", (char*) &_func_symValueGet, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_taskCreateHookAdd", (char*) &_func_taskCreateHookAdd, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_taskDeleteHookAdd", (char*) &_func_taskDeleteHookAdd, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_taskMemCtxSwitch", (char*) &_func_taskMemCtxSwitch, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_taskStackAlloc", (char*) &_func_taskStackAlloc, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_taskStackFree", (char*) &_func_taskStackFree, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_tipStart", (char*) &_func_tipStart, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_unldByModuleId", (char*) &_func_unldByModuleId, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_utf16ToCP", (char*) &_func_utf16ToCP, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_utf16ToUtf8String", (char*) &_func_utf16ToUtf8String, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_utf16ToUtf8StringBOM", (char*) &_func_utf16ToUtf8StringBOM, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_utf8ToCP", (char*) &_func_utf8ToCP, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_utf8ToUtf16String", (char*) &_func_utf8ToUtf16String, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_utf8ToUtf16StringBOM", (char*) &_func_utf8ToUtf16StringBOM, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_utflen16", (char*) &_func_utflen16, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_utflen8", (char*) &_func_utflen8, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_valloc", (char*) &_func_valloc, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_vfpExcHandle", (char*) &_func_vfpExcHandle, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_vfpHasException", (char*) &_func_vfpHasException, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_vfpIsEnabled", (char*) &_func_vfpIsEnabled, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_vfpSave", (char*) &_func_vfpSave, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_virtExtraMapInfoGet", (char*) &_func_virtExtraMapInfoGet, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_virtSegInfoGet", (char*) &_func_virtSegInfoGet, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_vmBaseFuncsSet", (char*) &_func_vmBaseFuncsSet, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_vmInvPageMap", (char*) &_func_vmInvPageMap, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_vmInvUnMap", (char*) &_func_vmInvUnMap, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_vxMemProbeHook", (char*) &_func_vxMemProbeHook, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_vxbDelayCommon", (char*) &_func_vxbDelayCommon, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_vxbIntConnect", (char*) &_func_vxbIntConnect, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_vxbIntDisable", (char*) &_func_vxbIntDisable, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_vxbIntDisconnect", (char*) &_func_vxbIntDisconnect, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_vxbIntDynaConnect", (char*) &_func_vxbIntDynaConnect, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_vxbIntDynaCtlrInputInit", (char*) &_func_vxbIntDynaCtlrInputInit, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_vxbIntDynaVecAlloc", (char*) &_func_vxbIntDynaVecAlloc, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_vxbIntDynaVecDevMultiProgram", (char*) &_func_vxbIntDynaVecDevMultiProgram, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_vxbIntDynaVecDisable", (char*) &_func_vxbIntDynaVecDisable, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_vxbIntDynaVecEnable", (char*) &_func_vxbIntDynaVecEnable, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_vxbIntDynaVecErase", (char*) &_func_vxbIntDynaVecErase, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_vxbIntDynaVecGet", (char*) &_func_vxbIntDynaVecGet, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_vxbIntDynaVecOwnerFind", (char*) &_func_vxbIntDynaVecOwnerFind, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_vxbIntDynaVecProgram", (char*) &_func_vxbIntDynaVecProgram, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_vxbIntEnable", (char*) &_func_vxbIntEnable, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_vxbPciDevCfgRead", (char*) &_func_vxbPciDevCfgRead, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_vxbPciDevCfgWrite", (char*) &_func_vxbPciDevCfgWrite, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_vxbUserHookDevInit", (char*) &_func_vxbUserHookDevInit, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_vxdbgBpDelete", (char*) &_func_vxdbgBpDelete, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_vxdbgCtxCont", (char*) &_func_vxdbgCtxCont, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_vxdbgCtxStop", (char*) &_func_vxdbgCtxStop, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_vxdbgMemMove", (char*) &_func_vxdbgMemMove, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_vxdbgMemRead", (char*) &_func_vxdbgMemRead, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_vxdbgMemScan", (char*) &_func_vxdbgMemScan, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_vxdbgMemWrite", (char*) &_func_vxdbgMemWrite, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_vxdbgRtpCont", (char*) &_func_vxdbgRtpCont, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_vxdbgRtpIdVerify", (char*) &_func_vxdbgRtpIdVerify, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_vxdbgRtpStop", (char*) &_func_vxdbgRtpStop, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_vxdbgTrap", (char*) &_func_vxdbgTrap, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_wdbExternCoprocRegsGet", (char*) &_func_wdbExternCoprocRegsGet, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_wdbExternCoprocRegsSet", (char*) &_func_wdbExternCoprocRegsSet, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_wdbExternEnterHookAdd", (char*) &_func_wdbExternEnterHookAdd, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_wdbExternExitHookAdd", (char*) &_func_wdbExternExitHookAdd, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_wdbExternNotifyHost", (char*) &_func_wdbExternNotifyHost, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_wdbExternRcvHook", (char*) &_func_wdbExternRcvHook, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_wdbResumeSystem", (char*) &_func_wdbResumeSystem, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_wdbSuspendSystem", (char*) &_func_wdbSuspendSystem, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_wdbTaskBpByIdRemove", (char*) &_func_wdbTaskBpByIdRemove, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_wdbTaskCoprocRegsGet", (char*) &_func_wdbTaskCoprocRegsGet, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_wdbTaskCoprocRegsSet", (char*) &_func_wdbTaskCoprocRegsSet, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_wdbTrap", (char*) &_func_wdbTrap, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_windSemRWDelete", (char*) &_func_windSemRWDelete, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_func_windTickAnnounceHook", (char*) &_func_windTickAnnounceHook, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_func_workQDbgTextDump", (char*) &_func_workQDbgTextDump, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_hostAdd", (char*) _hostAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_hostDelete", (char*) _hostDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_hostGetByAddr", (char*) _hostGetByAddr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_hostGetByName", (char*) _hostGetByName, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_hostTblSearchByName2", (char*) _hostTblSearchByName2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_ipcom_gethostbyaddr_r", (char*) &_ipcom_gethostbyaddr_r, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_ipcom_gethostbyname_r", (char*) &_ipcom_gethostbyname_r, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_ipdhcpc_callback_hook", (char*) &_ipdhcpc_callback_hook, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_linkMemReqClAlign", (char*) &_linkMemReqClAlign, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_linkMemReqMlinkAlign", (char*) &_linkMemReqMlinkAlign, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_mprec_log10", (char*) _mprec_log10, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_muxProtosPerEndInc", (char*) &_muxProtosPerEndInc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_muxProtosPerEndStart", (char*) &_muxProtosPerEndStart, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_netMemReqDefault", (char*) _netMemReqDefault, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_netSysctl", (char*) &_netSysctl, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_netSysctlCli", (char*) &_netSysctlCli, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_pLinkPoolFuncTbl", (char*) &_pLinkPoolFuncTbl, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_pNetBufCollect", (char*) &_pNetBufCollect, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_pNetDpool", (char*) &_pNetDpool, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_pNetPoolFuncAlignTbl", (char*) &_pNetPoolFuncAlignTbl, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_pNetPoolFuncTbl", (char*) &_pNetPoolFuncTbl, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_pNetSysPool", (char*) &_pNetSysPool, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_pSigQueueFreeHead", (char*) &_pSigQueueFreeHead, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "_pSysL2CacheClear", (char*) &_pSysL2CacheClear, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_pSysL2CacheDisable", (char*) &_pSysL2CacheDisable, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_pSysL2CacheEnable", (char*) &_pSysL2CacheEnable, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_pSysL2CacheFlush", (char*) &_pSysL2CacheFlush, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_pSysL2CacheInvFunc", (char*) &_pSysL2CacheInvFunc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_pSysL2CachePipeFlush", (char*) &_pSysL2CachePipeFlush, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_panicHook", (char*) &_panicHook, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_pingSockBufSize2", (char*) &_pingSockBufSize2, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_pingTxInterval2", (char*) &_pingTxInterval2, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_pingTxLen", (char*) &_pingTxLen, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_pingTxLen2", (char*) &_pingTxLen2, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_pingTxTmo", (char*) &_pingTxTmo, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_pingTxTmo2", (char*) &_pingTxTmo2, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_procNumWasSet", (char*) &_procNumWasSet, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_setjmpSetup", (char*) _setjmpSetup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_sigCtxLoad", (char*) _sigCtxLoad, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_sigCtxRtnValSet", (char*) _sigCtxRtnValSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_sigCtxSave", (char*) _sigCtxSave, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_sigCtxSetup", (char*) _sigCtxSetup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_sigCtxStackEnd", (char*) _sigCtxStackEnd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_sigfaulttable", (char*) &_sigfaulttable, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_taskSuspend", (char*) _taskSuspend, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_vdsqrt", (char*) _vdsqrt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_vx_offset_COMMON_SYM_pSymbol", (char*) 0x00000004, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_COPROC_DESC_ctxAlign", (char*) 0x00000008, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_COPROC_DESC_ctxSize", (char*) 0x00000004, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_COPROC_DESC_mask", (char*) 0x00000048, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_COPROC_DESC_next", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_COPROC_DESC_pCtxGetRtn", (char*) 0x00000024, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_COPROC_DESC_pLastEntry", (char*) 0x00000044, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_COPROC_TBL_ENTRY_pCtx", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_COPROC_TBL_ENTRY_pDescriptor", (char*) 0x00000004, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_COPROC_TBL_ENTRY_pTask", (char*) 0x00000008, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_COPROC_TBL_ENTRY_size", (char*) 0x0000000c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_DEV_HDR_drvNum", (char*) 0x0000001c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_DEV_HDR_name", (char*) 0x00000008, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_DL_LIST_head", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_DL_NODE_next", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_DRV_ENTRY_de_close", (char*) 0x0000000c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_DRV_ENTRY_de_create", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_DRV_ENTRY_de_delete", (char*) 0x00000004, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_DRV_ENTRY_de_inuse", (char*) 0x00000020, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_DRV_ENTRY_de_ioctl", (char*) 0x00000018, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_DRV_ENTRY_de_open", (char*) 0x00000008, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_DRV_ENTRY_de_read", (char*) 0x00000010, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_DRV_ENTRY_de_write", (char*) 0x00000014, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_ESFARM_cpsr", (char*) 0x00000004, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_ESFARM_pc", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_ESFARM_vecAddr", (char*) 0x0000000c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_FD_ENTRY_pDevHdr", (char*) 0x00000044, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_FD_ENTRY_refCnt", (char*) 0x00000050, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_FD_ENTRY_value", (char*) 0x00000048, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_HANDLE_attributes", (char*) 0x00000008, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_HANDLE_context", (char*) 0x0000000c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_HANDLE_contextType", (char*) 0x0000000b, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_HANDLE_magic", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_HANDLE_objSize", (char*) 0x00000010, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_HANDLE_safeCnt", (char*) 0x00000004, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_HANDLE_type", (char*) 0x0000000a, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_HASH_TBL_elements", (char*) 0x00000020, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_HASH_TBL_pHashTbl", (char*) 0x00000018, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_HOOK_TBL_hookTableA", (char*) 0x0000008c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_HOOK_TBL_maxEntries", (char*) 0x00000070, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_JOB_arg1", (char*) 0x00000004, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_JOB_arg2", (char*) 0x00000008, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_JOB_function", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_JOB_isrTag", (char*) 0x0000000c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_KERNEL_RTP_CMN_pWdbInfo", (char*) 0x00000010, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_KERNEL_RTP_CMN_pgMgrId", (char*) 0x00000004, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_KERNEL_RTP_CMN_sharedDataList", (char*) 0x00000008, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_KERNEL_RTP_CMN_vmContextId", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_MEM_PART_STATS_maxBlockSizeFree", (char*) 0x00000008, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_MEM_PART_STATS_maxBytesAlloc", (char*) 0x00000014, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_MEM_PART_STATS_numBlocksAlloc", (char*) 0x00000010, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_MEM_PART_STATS_numBlocksFree", (char*) 0x00000004, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_MEM_PART_STATS_numBytesAlloc", (char*) 0x0000000c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_MEM_PART_STATS_numBytesFree", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_MEM_SECTION_HDR_size", (char*) 0x00000004, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_MODLIST_DESC_moduleList", (char*) 0x00000010, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_MODULE_commTotalSize", (char*) 0x00000540, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_MODULE_commonSymList", (char*) 0x00000554, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_MODULE_ctors", (char*) 0x00000538, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_MODULE_dtors", (char*) 0x0000053c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_MODULE_flags", (char*) 0x0000051c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_MODULE_format", (char*) 0x00000530, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_MODULE_group", (char*) 0x00000534, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_MODULE_nameWithPath", (char*) 0x00000018, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_MODULE_sectionList", (char*) 0x00000520, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_MODULE_segmentList", (char*) 0x00000528, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_MODULE_swapNeeded", (char*) 0x00000544, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_MODULE_undefSymCount", (char*) 0x00000548, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_MODULE_undefSymList", (char*) 0x0000054c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_MSG_NODE_message", (char*) 0x0000000c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_MSG_NODE_msgLength", (char*) 0x00000004, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_MSG_Q_HEAD_count", (char*) 0x00000008, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_MSG_Q_HEAD_list", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_MSG_Q_HEAD_pendQ", (char*) 0x0000000c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_MSG_Q_events", (char*) 0x0000008c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_MSG_Q_freeQ", (char*) 0x00000060, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_MSG_Q_maxMsgLength", (char*) 0x00000080, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_MSG_Q_maxMsgs", (char*) 0x0000007c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_MSG_Q_msgQ", (char*) 0x00000044, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_MSG_Q_options", (char*) 0x000000a8, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_MSG_Q_recvTimeouts", (char*) 0x00000088, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_MSG_Q_sendTimeouts", (char*) 0x00000084, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_OBJ_CLASS_createRtn", (char*) 0x0000001c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_OBJ_CLASS_destroyRtn", (char*) 0x00000020, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_OBJ_CLASS_handle", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_OBJ_CLASS_objClassType", (char*) 0x00000010, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_OBJ_CLASS_objMemAllocRtn", (char*) 0x00000028, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_OBJ_CLASS_objMemFreeRtn", (char*) 0x0000002c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_OBJ_CLASS_objPartId", (char*) 0x00000030, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_OBJ_CLASS_objPrivList", (char*) 0x00000034, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_OBJ_CLASS_objPubList", (char*) 0x0000003c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_OBJ_CLASS_objSize", (char*) 0x00000018, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_OBJ_CLASS_options", (char*) 0x00000014, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_OBJ_CLASS_pClassSem", (char*) 0x00000044, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_OBJ_CLASS_showRtn", (char*) 0x00000024, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_PAGE_MGR_OBJ_mmapList", (char*) 0x00000010, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_PAGE_MGR_OBJ_options", (char*) 0x00000018, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_PAGE_MGR_OBJ_physPgPoolId", (char*) 0x00000004, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_PAGE_MGR_OBJ_virtPgPoolId", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_PAGE_MGR_OBJ_vmContextId", (char*) 0x0000000c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_PARTITION_avlSize", (char*) 0x00000044, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_PARTITION_cumBlocksAllocated", (char*) 0x000000fc, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_PARTITION_cumWordsAllocated", (char*) 0x00000104, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_PARTITION_curBlocksAllocated", (char*) 0x000000f4, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_PARTITION_curBlocksAllocatedInternal", (char*) 0x00000110, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_PARTITION_curBlocksFreed", (char*) 0x000000ec, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_PARTITION_curWordsAllocated", (char*) 0x000000f8, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_PARTITION_curWordsAllocatedInternal", (char*) 0x00000114, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_PARTITION_curWordsFreed", (char*) 0x000000f0, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_PARTITION_freeSizeNodeNb", (char*) 0x00000050, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_PARTITION_maxWordsAllocated", (char*) 0x0000010c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_PARTITION_options", (char*) 0x000000cc, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_PARTITION_sectionHdrLst", (char*) 0x000000d0, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_PARTITION_sem", (char*) 0x00000058, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_PARTITION_totalWords", (char*) 0x000000c8, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_POSIX_MSG_Q_ATTR_mq_curmsgs", (char*) 0x0000000c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_POSIX_MSG_Q_ATTR_mq_flags", (char*) 0x00000008, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_POSIX_MSG_Q_ATTR_mq_maxmsg", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_POSIX_MSG_Q_ATTR_mq_msgsize", (char*) 0x00000004, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_POSIX_MSG_Q_DES_f_data", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_POSIX_MSG_Q_DES_f_flag", (char*) 0x00000004, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_POSIX_MSG_Q_msgq_attr", (char*) 0x00000114, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_POSIX_MSG_Q_msgq_cond_data", (char*) 0x00000054, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_POSIX_MSG_Q_msgq_cond_read", (char*) 0x00000044, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_PSEMAPHORE_objCore", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_PSEMAPHORE_pSelf", (char*) 0x00000048, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_PSEMAPHORE_wSemId", (char*) 0x00000044, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_Q_FIFO_G_HEAD_pFifoQ", (char*) 0x00000008, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_RBUFF_BUFF_TYPE_dataEnd", (char*) 0x0000000c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_RBUFF_BUFF_TYPE_dataLen", (char*) 0x00000010, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_RBUFF_BUFF_TYPE_dataStart", (char*) 0x00000008, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_RBUFF_BUFF_TYPE_next", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_RBUFF_BUFF_TYPE_prev", (char*) 0x00000018, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_RBUFF_BUFF_TYPE_spaceAvail", (char*) 0x00000004, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_RBUFF_BUFF_TYPE_uncommitedRead", (char*) 0x00000014, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_RBUFF_INFO_TYPE_buffSize", (char*) 0x00000008, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_RBUFF_INFO_TYPE_bytesPeak", (char*) 0x00000040, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_RBUFF_INFO_TYPE_bytesRead", (char*) 0x0000003c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_RBUFF_INFO_TYPE_bytesWritten", (char*) 0x00000038, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_RBUFF_INFO_TYPE_currBuffs", (char*) 0x0000000c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_RBUFF_INFO_TYPE_dataContent", (char*) 0x00000024, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_RBUFF_INFO_TYPE_emptyBuffs", (char*) 0x00000020, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_RBUFF_INFO_TYPE_maxBuffs", (char*) 0x00000018, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_RBUFF_INFO_TYPE_maxBuffsActual", (char*) 0x0000001c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_RBUFF_INFO_TYPE_minBuffs", (char*) 0x00000014, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_RBUFF_INFO_TYPE_options", (char*) 0x00000004, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_RBUFF_INFO_TYPE_readsSinceReset", (char*) 0x0000002c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_RBUFF_INFO_TYPE_srcPart", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_RBUFF_INFO_TYPE_threshold", (char*) 0x00000010, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_RBUFF_INFO_TYPE_timesExtended", (char*) 0x00000030, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_RBUFF_INFO_TYPE_timesXThreshold", (char*) 0x00000034, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_RBUFF_INFO_TYPE_writesSinceReset", (char*) 0x00000028, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_RBUFF_TYPE_buffDesc", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_RBUFF_TYPE_buffRead", (char*) 0x000000b0, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_RBUFF_TYPE_buffWrite", (char*) 0x000000b4, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_RBUFF_TYPE_dataRead", (char*) 0x000000b8, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_RBUFF_TYPE_dataWrite", (char*) 0x000000bc, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_RBUFF_TYPE_info", (char*) 0x000000cc, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_REG_SET_pc", (char*) 0x0000003c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_REG_SET_size", (char*) 0x00000048, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_REG_SET_sp", (char*) 0x00000034, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_RTP_SIG_CTX_ctx_regset", (char*) 0x00000034, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SECTION_DESC_address", (char*) 0x0000001c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SECTION_DESC_checksum", (char*) 0x00000030, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SECTION_DESC_flags", (char*) 0x00000028, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SECTION_DESC_name", (char*) 0x00000018, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SECTION_DESC_sectionNode", (char*) 0x00000010, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SECTION_DESC_size", (char*) 0x00000020, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SECTION_DESC_type", (char*) 0x00000024, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SEGMENT_address", (char*) 0x00000008, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SEGMENT_flags", (char*) 0x00000014, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SEGMENT_segmentNode", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SEGMENT_size", (char*) 0x0000000c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SEGMENT_type", (char*) 0x00000010, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SEMAPHORE_count", (char*) 0x0000005c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SEMAPHORE_events", (char*) 0x00000060, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SEMAPHORE_events_options", (char*) 0x00000068, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SEMAPHORE_events_registered", (char*) 0x00000064, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SEMAPHORE_options", (char*) 0x00000045, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SEMAPHORE_priInheritFlag", (char*) 0x00000048, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SEMAPHORE_qHead", (char*) 0x0000004c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SEMAPHORE_recurse", (char*) 0x00000046, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SEMAPHORE_semType", (char*) 0x00000044, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SL_LIST_head", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SL_LIST_size", (char*) 0x00000008, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SL_NODE_next", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_BLOCK_HDR_nWords", (char*) 0x00000004, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_FREE_BLOCK_node", (char*) 0x00000010, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_MSG_NODE_message", (char*) 0x0000000c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_MSG_NODE_msgLength", (char*) 0x00000008, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_MSG_Q_freeQ", (char*) 0x00000048, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_MSG_Q_freeQSem", (char*) 0x0000002c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_MSG_Q_maxMsgLength", (char*) 0x00000058, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_MSG_Q_maxMsgs", (char*) 0x00000054, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_MSG_Q_msgQ", (char*) 0x00000024, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_MSG_Q_msgQSem", (char*) 0x00000008, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_MSG_Q_options", (char*) 0x00000050, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_MSG_Q_recvTimeouts", (char*) 0x00000060, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_MSG_Q_sendTimeouts", (char*) 0x0000005c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_OBJ_MEM_HDR_curNumMsgQ", (char*) 0x000001d0, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_OBJ_MEM_HDR_curNumName", (char*) 0x000001dc, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_OBJ_MEM_HDR_curNumPart", (char*) 0x000001d8, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_OBJ_MEM_HDR_curNumSemB", (char*) 0x000001c8, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_OBJ_MEM_HDR_curNumSemC", (char*) 0x000001cc, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_OBJ_MEM_HDR_curNumTask", (char*) 0x000001d4, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_OBJ_MEM_HDR_maxMemParts", (char*) 0x000001c0, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_OBJ_MEM_HDR_maxMsgQueues", (char*) 0x000001b8, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_OBJ_MEM_HDR_maxNames", (char*) 0x000001c4, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_OBJ_MEM_HDR_maxSems", (char*) 0x000001b4, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_OBJ_MEM_HDR_maxTasks", (char*) 0x000001bc, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_OBJ_MEM_HDR_nameDtb", (char*) 0x00000184, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_OBJ_MEM_HDR_objCpuTbl", (char*) 0x000001b0, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_OBJ_MEM_HDR_smMsgQPart", (char*) 0x000000b8, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_OBJ_MEM_HDR_smNamePart", (char*) 0x00000074, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_OBJ_MEM_HDR_smPartPart", (char*) 0x000000fc, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_OBJ_MEM_HDR_smSemPart", (char*) 0x00000030, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_OBJ_MEM_HDR_smSysPart", (char*) 0x00000140, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_OBJ_MEM_HDR_smTcbPart", (char*) 0x0000000c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_OBJ_TCB_localTcb", (char*) 0x00000008, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_OBJ_TCB_ownerCpu", (char*) 0x0000000c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_OBJ_objType", (char*) 0x00000004, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_PARTITION_cumBlocksAllocated", (char*) 0x0000003c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_PARTITION_cumWordsAllocated", (char*) 0x00000040, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_PARTITION_curBlocksAllocated", (char*) 0x00000034, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_PARTITION_curWordsAllocated", (char*) 0x00000038, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_PARTITION_freeList", (char*) 0x00000008, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_PARTITION_totalWords", (char*) 0x00000028, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_SEMAPHORE_count", (char*) 0x00000014, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_SEMAPHORE_flag", (char*) 0x00000014, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_SEMAPHORE_lock", (char*) 0x00000008, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_SEMAPHORE_objType", (char*) 0x00000004, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_SEMAPHORE_smPendQ", (char*) 0x0000000c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SM_SEMAPHORE_verify", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SYMBOL_group", (char*) 0x00000010, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SYMBOL_name", (char*) 0x00000004, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SYMBOL_symRef", (char*) 0x0000000c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SYMBOL_type", (char*) 0x00000012, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SYMBOL_value", (char*) 0x00000008, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SYMTAB_nameHashId", (char*) 0x00000010, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SYSCALL_ENTRY_STATE_args", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SYSCALL_ENTRY_STATE_pUStack", (char*) 0x0000002c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SYSCALL_ENTRY_STATE_pc", (char*) 0x00000028, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SYSCALL_ENTRY_STATE_retAddrReg", (char*) 0x00000030, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SYSCALL_ENTRY_STATE_scn", (char*) 0x00000020, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_SYSCALL_ENTRY_STATE_size", (char*) 0x00000034, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_TRIGGER_actionArg", (char*) 0x00000078, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_TRIGGER_actionDef", (char*) 0x0000007c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_TRIGGER_actionFunc", (char*) 0x00000074, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_TRIGGER_actionType", (char*) 0x00000070, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_TRIGGER_chain", (char*) 0x00000058, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_TRIGGER_condEx1", (char*) 0x00000064, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_TRIGGER_condEx2", (char*) 0x0000006c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_TRIGGER_condOp", (char*) 0x00000068, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_TRIGGER_condType", (char*) 0x00000060, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_TRIGGER_conditional", (char*) 0x0000005c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_TRIGGER_contextId", (char*) 0x00000050, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_TRIGGER_contextType", (char*) 0x0000004c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_TRIGGER_disable", (char*) 0x00000048, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_TRIGGER_eventId", (char*) 0x00000044, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_TRIGGER_hitCnt", (char*) 0x00000080, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_TRIGGER_initialState", (char*) 0x00000084, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_TRIGGER_objCore", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_TRIGGER_objId", (char*) 0x00000054, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_TRIGGER_pDataCollector", (char*) 0x00000088, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_TRIGGER_status", (char*) 0x00000046, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_UNCOMPCB_dropped", (char*) 0x00000022, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_UNCOMPCB_hiwatermark", (char*) 0x00000020, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_UNCOMPCB_node", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_UNCOMPCB_pLastExp", (char*) 0x00000018, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_UNCOMPCB_pLastReg", (char*) 0x00000014, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_UNCOMPCB_pPeerSocket", (char*) 0x0000000c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_UNCOMPCB_pRecvPacket", (char*) 0x0000001c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_UNCOMPCB_pSelfSocket", (char*) 0x00000008, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_UNCOMPCB_selfName", (char*) 0x00000012, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_UNCOMPCB_selfState", (char*) 0x00000010, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_UNDEF_SYM_name", (char*) 0x00000004, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_VFP_CONTEXT_fpexc", (char*) 0x00000008, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_VFP_CONTEXT_fpinst", (char*) 0x0000000c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_VFP_CONTEXT_fpinst2", (char*) 0x00000010, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_VFP_CONTEXT_fpscr", (char*) 0x00000004, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_VFP_CONTEXT_fpsid", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_VFP_CONTEXT_mfvfr0", (char*) 0x00000014, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_VFP_CONTEXT_mfvfr1", (char*) 0x00000018, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_VFP_CONTEXT_vfp_gpr", (char*) 0x00000020, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_VM_CONTEXT_mmuTransTbl", (char*) 0x00000044, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_VM_LIB_INFO_pVmCtxSwitchRtn", (char*) 0x00000034, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_VX_coproc1Task", (char*) 0x01000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_VX_coproc2Task", (char*) 0x02000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_VX_coproc3Task", (char*) 0x04000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_VX_coproc4Task", (char*) 0x08000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_VX_coproc5Task", (char*) 0x10000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_VX_coproc6Task", (char*) 0x20000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_VX_coproc7Task", (char*) 0x40000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_VX_coproc8Task", (char*) 0x80000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_VX_fpTask", (char*) 0x01000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WDOG_deferStartCnt", (char*) 0x0000005e, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WDOG_status", (char*) 0x0000005c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WDOG_timeout", (char*) 0x0000004c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WDOG_wdParameter", (char*) 0x00000058, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WDOG_wdRoutine", (char*) 0x00000054, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_ISR_arg", (char*) 0x0000005c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_ISR_count", (char*) 0x00000048, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_ISR_cpuTime", (char*) 0x00000050, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_ISR_handlerRtn", (char*) 0x00000058, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_ISR_isrTag", (char*) 0x00000044, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_ISR_objCore", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_ISR_options", (char*) 0x00000060, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_ISR_serviceCount", (char*) 0x0000004c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_OBJ_accessCnt", (char*) 0x00000042, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_OBJ_classNode", (char*) 0x00000020, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_OBJ_handle", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_OBJ_name", (char*) 0x00000030, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_OBJ_objHandleList", (char*) 0x00000038, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_OBJ_ownerId", (char*) 0x00000028, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_OBJ_ownerList", (char*) 0x00000010, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_OBJ_ownerNode", (char*) 0x00000018, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_OBJ_ownerRtpId", (char*) 0x0000002c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_OBJ_pObjClass", (char*) 0x00000034, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_OBJ_refCnt", (char*) 0x00000040, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_RTP_binaryInfo", (char*) 0x00000084, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_RTP_cpuTimeInfo", (char*) 0x00000b5c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_RTP_defPath", (char*) 0x000000d4, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_RTP_defPathLen", (char*) 0x000000d8, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_RTP_entrAddr", (char*) 0x00000078, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_RTP_fdTable", (char*) 0x000000cc, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_RTP_fdTableSize", (char*) 0x000000d0, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_RTP_initTaskId", (char*) 0x0000007c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_RTP_kernelRtpCmn", (char*) 0x00000044, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_RTP_lockTaskId", (char*) 0x00000b48, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_RTP_options", (char*) 0x00000074, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_RTP_pArgv", (char*) 0x00000068, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_RTP_pEnv", (char*) 0x0000006c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_RTP_pPathName", (char*) 0x00000064, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_RTP_pSchedInfo", (char*) 0x00000b6c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_RTP_pSigQFreeHead", (char*) 0x00000714, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_RTP_parentRtpId", (char*) 0x00000728, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_RTP_rtpNode", (char*) 0x00000058, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_RTP_semId", (char*) 0x00000060, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_RTP_sigReturnRtn", (char*) 0x000000e0, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_RTP_signalInfo", (char*) 0x000000e4, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_RTP_sigwaitQ", (char*) 0x00000718, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_RTP_status", (char*) 0x00000070, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_RTP_symTabId", (char*) 0x00000080, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_RTP_taskCnt", (char*) 0x000000b4, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_RTP_taskExitRtn", (char*) 0x000000dc, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_SD_attr", (char*) 0x000000bc, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_SD_clientCount", (char*) 0x000000d0, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_SD_objCore", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_SD_options", (char*) 0x000000b8, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_SD_physAdrs", (char*) 0x000000c4, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_SD_sem", (char*) 0x00000048, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_SD_size", (char*) 0x000000c0, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_SD_virtAdrs", (char*) 0x000000cc, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_SOCKET_so_fd", (char*) 0x00000044, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_SOCKET_so_linger", (char*) 0x00000008, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_SOCKET_so_options", (char*) 0x00000006, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_SOCKET_so_pcb", (char*) 0x0000000c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_SOCKET_so_qlen", (char*) 0x00000030, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_SOCKET_so_qlimit", (char*) 0x00000034, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_SOCKET_so_state", (char*) 0x0000000a, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_SOCKET_so_type", (char*) 0x00000004, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_cpuTimeInfo", (char*) 0x00000168, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_entry", (char*) 0x000000c4, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_errorStatus", (char*) 0x000000d4, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_events", (char*) 0x00000110, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_excCnt", (char*) 0x00000070, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_excInfo", (char*) 0x000001bc, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_fpStatus", (char*) 0x000001cc, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_lockCnt", (char*) 0x00000080, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_objCore", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_options", (char*) 0x000000a0, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_pCoprocTbl", (char*) 0x000000f4, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_pDbgInfo", (char*) 0x00000138, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_pEdrInfo", (char*) 0x000000d0, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_pExcRegSet", (char*) 0x00000130, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_pExcStackBase", (char*) 0x00000064, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_pExcStackEnd", (char*) 0x00000068, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_pExcStackStart", (char*) 0x0000006c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_pPendQ", (char*) 0x000000a8, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_pPriMutex", (char*) 0x00000090, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_pPwrMgmtPState", (char*) 0x00000178, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_pSchedInfo", (char*) 0x0000017c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_pStackBase", (char*) 0x000000c8, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_pStackEnd", (char*) 0x000000cc, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_pTlsDesc", (char*) 0x00000228, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_pUTcb", (char*) 0x0000009c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_priDrop", (char*) 0x0000008c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_priInheritCnt", (char*) 0x00000088, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_priMutexCnt", (char*) 0x00000084, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_priNormal", (char*) 0x0000007c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_priority", (char*) 0x00000078, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_qNode", (char*) 0x00000054, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_regs", (char*) 0x000001d8, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_rtpId", (char*) 0x00000098, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_safeCnt", (char*) 0x000000b0, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_safetyQHead", (char*) 0x000000b4, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_status", (char*) 0x00000074, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_swapInMask", (char*) 0x000000ac, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_swapOutMask", (char*) 0x000000ae, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_taskTicks", (char*) 0x000000e4, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_timeout", (char*) 0x0000004c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WIND_TCB_windSmpInfo", (char*) 0x00000184, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WORK_Q_IX_bitmask", (char*) 0x00000004, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WORK_Q_IX_read", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WORK_Q_IX_write", (char*) 0x00000008, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WV_HASH_NODE_eventSize", (char*) 0x00000004, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WV_HASH_NODE_key", (char*) 0x00000008, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WV_HASH_NODE_next", (char*) 0x0000000c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WV_HASH_NODE_pEvent", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WV_HASH_TBL_size", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WV_HASH_TBL_tbl", (char*) 0x00000004, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WV_LOG_LIST_hdr_magic", (char*) 0x00000010, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WV_LOG_LIST_hdr_memPart", (char*) 0x00000008, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WV_LOG_LIST_hdr_numLogs", (char*) 0x0000000c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WV_LOG_LIST_hdr_wvLogListHead", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WV_LOG_configEventSize", (char*) 0x00000010, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WV_LOG_memPart", (char*) 0x00000004, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WV_LOG_node", (char*) 0x00000000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WV_LOG_pConfigEvent", (char*) 0x0000000c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WV_LOG_pEvtBuffer", (char*) 0x00000008, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_WV_LOG_pHashTbl", (char*) 0x00000014, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_hiddenModule", (char*) 0x00000010, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_loadAllSymbols", (char*) 0x0000000c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_loadCommonHeap", (char*) 0x00000800, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_loadCommonMatchAll", (char*) 0x00000400, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_loadCommonMatchNone", (char*) 0x00000100, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_loadCommonMatchUser", (char*) 0x00000200, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_loadCplusXtorAuto", (char*) 0x00001000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_loadCplusXtorManual", (char*) 0x00002000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_loadForce", (char*) 0x00000080, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_loadFullyLinked", (char*) 0x00000020, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_loadGlobalSymbols", (char*) 0x00000008, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_loadLocalSymbols", (char*) 0x00000004, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_loadNoDownload", (char*) 0x00000040, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_loadNoSymbols", (char*) 0x00000002, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_loadWeakMatchAll", (char*) 0x00020000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_loadWeakMatchNone", (char*) 0x00010000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_sizeof_FD_ENTRY", (char*) 0x00000060, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_sizeof_MSG_NODE", (char*) 0x0000000c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_sizeof_MSG_Q", (char*) 0x000000b0, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_sizeof_SEMAPHORE", (char*) 0x00000070, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_sizeof_SEM_RW_EXT", (char*) 0x00000018, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_sizeof_SEM_RW_LIST_ENTRY", (char*) 0x0000000c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_sizeof_WDOG", (char*) 0x00000060, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_sizeof_WIND_OBJ", (char*) 0x00000044, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_syscallEntryBaseOffset", (char*) 0x0000000c, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_unloadCplusXtorAuto", (char*) 0x00000020, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_unloadCplusXtorManual", (char*) 0x00000040, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_unloadForce", (char*) 0x00000002, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vx_offset_vfpNumSgpr", (char*) 0x00000020, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "_vxb_clkConnectRtn", (char*) &_vxb_clkConnectRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_vxb_clkDisableRtn", (char*) &_vxb_clkDisableRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_vxb_clkEnableRtn", (char*) &_vxb_clkEnableRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_vxb_clkRateGetRtn", (char*) &_vxb_clkRateGetRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_vxb_clkRateSetRtn", (char*) &_vxb_clkRateSetRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_vxb_delayRtn", (char*) &_vxb_delayRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_vxb_msDelayRtn", (char*) &_vxb_msDelayRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_vxb_timestampConnectRtn", (char*) &_vxb_timestampConnectRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_vxb_timestampDisableRtn", (char*) &_vxb_timestampDisableRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_vxb_timestampEnableRtn", (char*) &_vxb_timestampEnableRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_vxb_timestampFreqRtn", (char*) &_vxb_timestampFreqRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_vxb_timestampLockRtn", (char*) &_vxb_timestampLockRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_vxb_timestampPeriodRtn", (char*) &_vxb_timestampPeriodRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_vxb_timestampRtn", (char*) &_vxb_timestampRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_vxb_usDelayRtn", (char*) &_vxb_usDelayRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_vxmux_pNullPoolFuncTbl", (char*) &_vxmux_pNullPoolFuncTbl, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "_vxworks_asctime_r", (char*) _vxworks_asctime_r, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_vxworks_ctime_r", (char*) _vxworks_ctime_r, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_vxworks_gmtime_r", (char*) _vxworks_gmtime_r, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_vxworks_localtime_r", (char*) _vxworks_localtime_r, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_zbufCreate_nolock", (char*) _zbufCreate_nolock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_zbufDeleteEmpty", (char*) _zbufDeleteEmpty, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_zbufSetSeg", (char*) _zbufSetSeg, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_zbuf_getseg_nolock", (char*) _zbuf_getseg_nolock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "_zbuf_getsegptr_nolock", (char*) _zbuf_getsegptr_nolock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "abort", (char*) abort, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "abs", (char*) abs, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "absSymbols_Bounds", (char*) absSymbols_Bounds, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "absSymbols_Common", (char*) absSymbols_Common, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "accept", (char*) accept, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "access", (char*) access, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "acos", (char*) acos, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "adrSpaceInfoGet", (char*) adrSpaceInfoGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "adrSpaceIsOverlapped", (char*) adrSpaceIsOverlapped, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "adrSpaceLibInit", (char*) adrSpaceLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "adrSpaceModel", (char*) &adrSpaceModel, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "adrSpaceOptimizedSizeGet", (char*) adrSpaceOptimizedSizeGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "adrSpacePageAlloc", (char*) adrSpacePageAlloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "adrSpacePageFree", (char*) adrSpacePageFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "adrSpacePageMap", (char*) adrSpacePageMap, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "adrSpacePageUnmap", (char*) adrSpacePageUnmap, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "adrSpaceRAMAddToPool", (char*) adrSpaceRAMAddToPool, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "adrSpaceRAMReserve", (char*) adrSpaceRAMReserve, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "adrSpaceRgnPreAlloc", (char*) adrSpaceRgnPreAlloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "adrSpaceVirtReserve", (char*) adrSpaceVirtReserve, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "aimCacheInit", (char*) aimCacheInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "aimMmuBaseLibInit", (char*) aimMmuBaseLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "alarm", (char*) alarm, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "allocChunkEndGuardSize", (char*) &allocChunkEndGuardSize, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "altera16550Dev0Resources", (char*) &altera16550Dev0Resources, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "altera16550Dev1Resources", (char*) &altera16550Dev1Resources, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "alteraTimerDev0Resources", (char*) &alteraTimerDev0Resources, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "alteraTimerDev3Resources", (char*) &alteraTimerDev3Resources, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "alteraTimerDevRegistration", (char*) &alteraTimerDevRegistration, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "app_main", (char*) app_main, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "app_realtime_print", (char*) app_realtime_print, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "app_register_task", (char*) app_register_task, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "app_show_count", (char*) app_show_count, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "app_start", (char*) app_start, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "app_start_hz", (char*) app_start_hz, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "app_stop", (char*) app_stop, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "app_unregister_task", (char*) app_unregister_task, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "applLoggerInit", (char*) applLoggerInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "applLoggerStop", (char*) applLoggerStop, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "applUtilInstInit", (char*) applUtilInstInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "applUtilLogSem", (char*) &applUtilLogSem, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "archPwrDown", (char*) archPwrDown, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "armGIC0Resources", (char*) &armGIC0Resources, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "armGetNpc", (char*) armGetNpc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "armInitExceptionModes", (char*) armInitExceptionModes, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "armInstrChangesPc", (char*) armInstrChangesPc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "armv7GenTimerAllocate", (char*) armv7GenTimerAllocate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "armv7GenTimerCountGet", (char*) armv7GenTimerCountGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "armv7GenTimerCountGet64", (char*) armv7GenTimerCountGet64, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "armv7GenTimerDbgMask", (char*) &armv7GenTimerDbgMask, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "armv7GenTimerDevInit", (char*) armv7GenTimerDevInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "armv7GenTimerDisable", (char*) armv7GenTimerDisable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "armv7GenTimerDisableInternal", (char*) armv7GenTimerDisableInternal, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "armv7GenTimerDrvFuncs", (char*) &armv7GenTimerDrvFuncs, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "armv7GenTimerDrvRegister", (char*) armv7GenTimerDrvRegister, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "armv7GenTimerDrvRegister2", (char*) armv7GenTimerDrvRegister2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "armv7GenTimerDrvRegistration", (char*) &armv7GenTimerDrvRegistration, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "armv7GenTimerDrv_methods", (char*) &armv7GenTimerDrv_methods, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "armv7GenTimerEnable", (char*) armv7GenTimerEnable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "armv7GenTimerEnable64", (char*) armv7GenTimerEnable64, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "armv7GenTimerFuncGet", (char*) armv7GenTimerFuncGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "armv7GenTimerISRSet", (char*) armv7GenTimerISRSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "armv7GenTimerInstConnect", (char*) armv7GenTimerInstConnect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "armv7GenTimerInstInit", (char*) armv7GenTimerInstInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "armv7GenTimerInstInit2", (char*) armv7GenTimerInstInit2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "armv7GenTimerIsr", (char*) armv7GenTimerIsr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "armv7GenTimerRelease", (char*) armv7GenTimerRelease, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "armv7GenTimerRolloverGet", (char*) armv7GenTimerRolloverGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "armv7GenTimerRolloverGet64", (char*) armv7GenTimerRolloverGet64, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "asMemDescNumEnt", (char*) &asMemDescNumEnt, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "asc2_0806", (char*) &asc2_0806, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "asc2_1206", (char*) &asc2_1206, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "asc2_1608", (char*) &asc2_1608, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "asc2_2412", (char*) &asc2_2412, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "asctime", (char*) asctime, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "asctime_r", (char*) asctime_r, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "asin", (char*) asin, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "assertlist", (char*) &assertlist, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "atan", (char*) atan, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "atan2", (char*) atan2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "atexit", (char*) atexit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "atof", (char*) atof, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "atoi", (char*) atoi, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "atol", (char*) atol, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "atomic32Add", (char*) atomic32Add, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "atomic32And", (char*) atomic32And, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "atomic32Cas", (char*) atomic32Cas, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "atomic32Clear", (char*) atomic32Clear, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "atomic32Dec", (char*) atomic32Dec, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "atomic32Get", (char*) atomic32Get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "atomic32Inc", (char*) atomic32Inc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "atomic32Nand", (char*) atomic32Nand, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "atomic32Or", (char*) atomic32Or, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "atomic32Set", (char*) atomic32Set, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "atomic32Sub", (char*) atomic32Sub, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "atomic32Xor", (char*) atomic32Xor, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "attrib", (char*) attrib, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "attribDisplay", (char*) attribDisplay, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "attribDisplayFile", (char*) attribDisplayFile, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "autoNegForce", (char*) &autoNegForce, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "avlDelete", (char*) avlDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "avlInsert", (char*) avlInsert, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "avlInsertInform", (char*) avlInsertInform, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "avlMaximumGet", (char*) avlMaximumGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "avlMinimumGet", (char*) avlMinimumGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "avlPredecessorGet", (char*) avlPredecessorGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "avlRemoveInsert", (char*) avlRemoveInsert, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "avlSearch", (char*) avlSearch, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "avlSuccessorGet", (char*) avlSuccessorGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "avlTreeWalk", (char*) avlTreeWalk, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "avlUintDelete", (char*) avlUintDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "avlUintInsert", (char*) avlUintInsert, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "avlUintMaximumGet", (char*) avlUintMaximumGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "avlUintMinimumGet", (char*) avlUintMinimumGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "avlUintPredecessorGet", (char*) avlUintPredecessorGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "avlUintSearch", (char*) avlUintSearch, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "avlUintSuccessorGet", (char*) avlUintSuccessorGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "avlUintTreeWalk", (char*) avlUintTreeWalk, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "axi165502CInit", (char*) axi165502CInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "axi16550BaudInit", (char*) axi16550BaudInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "axi16550FIFOInit", (char*) axi16550FIFOInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "axi16550Init", (char*) axi16550Init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "axi16550Recv", (char*) axi16550Recv, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "axi16550Send", (char*) axi16550Send, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "axi16550SendNoWait", (char*) axi16550SendNoWait, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "axi16550SendStartBreak", (char*) axi16550SendStartBreak, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "axi16550SendStopBreak", (char*) axi16550SendStopBreak, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "axi16550_TxReady", (char*) axi16550_TxReady, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "b", (char*) b, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "baudRateSet", (char*) baudRateSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bauderate_table", (char*) &bauderate_table, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "bcmp", (char*) bcmp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bcopy", (char*) bcopy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bcopyBytes", (char*) bcopyBytes, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bcopyLongs", (char*) bcopyLongs, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bcopyNeon", (char*) bcopyNeon, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bcopyWords", (char*) bcopyWords, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bd", (char*) bd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bdall", (char*) bdall, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bfill", (char*) bfill, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bfillBytes", (char*) bfillBytes, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bh", (char*) bh, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bi", (char*) bi, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bind", (char*) bind, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bindresvport", (char*) bindresvport, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bindresvportCommon", (char*) bindresvportCommon, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bindresvport_af", (char*) bindresvport_af, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "binvert", (char*) binvert, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bioInit", (char*) bioInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bio_alloc", (char*) bio_alloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bio_done", (char*) bio_done, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bio_free", (char*) bio_free, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "blkXbdDevCreate", (char*) blkXbdDevCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "blkXbdDevDelete", (char*) blkXbdDevDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bootBpAnchorExtract", (char*) bootBpAnchorExtract, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bootChange", (char*) bootChange, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bootLeaseExtract", (char*) bootLeaseExtract, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bootNetmaskExtract", (char*) bootNetmaskExtract, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bootParamsErrorPrint", (char*) bootParamsErrorPrint, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bootParamsPrompt", (char*) bootParamsPrompt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bootParamsShow", (char*) bootParamsShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bootScanNum", (char*) bootScanNum, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bootStringToStruct", (char*) bootStringToStruct, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bootStringToStructAdd", (char*) bootStringToStructAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bootStructToString", (char*) bootStructToString, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bsd_cvt", (char*) bsd_cvt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bsearch", (char*) bsearch, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bspSerialChanGet", (char*) bspSerialChanGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "bswap", (char*) bswap, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "busCtlrDevCtlr_desc", (char*) &busCtlrDevCtlr_desc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "busDevShow_desc", (char*) &busDevShow_desc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "bzero", (char*) bzero, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "c", (char*) c, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheAddrAlign", (char*) &cacheAddrAlign, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "cacheAimArch6DClear", (char*) cacheAimArch6DClear, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheAimArch6DFlush", (char*) cacheAimArch6DFlush, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheAimArch6DInvalidate", (char*) cacheAimArch6DInvalidate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheAimArch6IClearDisable", (char*) cacheAimArch6IClearDisable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheAimArch6IInvalidate", (char*) cacheAimArch6IInvalidate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheAimArch6IInvalidateAll", (char*) cacheAimArch6IInvalidateAll, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheAimArch6PipeFlush", (char*) cacheAimArch6PipeFlush, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheAimArch7DClearAll", (char*) cacheAimArch7DClearAll, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheAimArch7DDisable", (char*) cacheAimArch7DDisable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheAimArch7DEnable", (char*) cacheAimArch7DEnable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheAimArch7DFlushAll", (char*) cacheAimArch7DFlushAll, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheAimArch7DFlushPoU", (char*) cacheAimArch7DFlushPoU, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheAimArch7DInvalidateAll", (char*) cacheAimArch7DInvalidateAll, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheAimArch7DIsOn", (char*) cacheAimArch7DIsOn, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheAimArch7DProbe", (char*) cacheAimArch7DProbe, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheAimArch7DmaFree", (char*) cacheAimArch7DmaFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheAimArch7DmaMalloc", (char*) cacheAimArch7DmaMalloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheAimArch7IDisable", (char*) cacheAimArch7IDisable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheAimArch7IEnable", (char*) cacheAimArch7IEnable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheAimArch7IIsOn", (char*) cacheAimArch7IIsOn, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheAimArch7IProbe", (char*) cacheAimArch7IProbe, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheAimArch7Identify", (char*) cacheAimArch7Identify, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheAimArch7MmuIsOn", (char*) cacheAimArch7MmuIsOn, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheAimArch7SizeInfoGet", (char*) cacheAimArch7SizeInfoGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheAimArch7TextUpdate", (char*) cacheAimArch7TextUpdate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheAimCortexA15LibInit", (char*) cacheAimCortexA15LibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheAimCortexA15PhysToVirt", (char*) &cacheAimCortexA15PhysToVirt, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "cacheAimCortexA15VirtToPhys", (char*) &cacheAimCortexA15VirtToPhys, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "cacheAimInfo", (char*) &cacheAimInfo, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "cacheArch7CLIDR", (char*) cacheArch7CLIDR, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheArchAlignSize", (char*) &cacheArchAlignSize, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "cacheArchDClear", (char*) cacheArchDClear, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheArchDClearAll", (char*) cacheArchDClearAll, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheArchDFlush", (char*) cacheArchDFlush, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheArchDFlushAll", (char*) cacheArchDFlushAll, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheArchDInvalidate", (char*) cacheArchDInvalidate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheArchDInvalidateAll", (char*) cacheArchDInvalidateAll, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheArchIInvalidate", (char*) cacheArchIInvalidate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheArchIInvalidateAll", (char*) cacheArchIInvalidateAll, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheArchIntLock", (char*) cacheArchIntLock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheArchIntMask", (char*) &cacheArchIntMask, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "cacheArchL2CacheDisable", (char*) cacheArchL2CacheDisable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheArchL2CacheEnable", (char*) cacheArchL2CacheEnable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheArchL2CacheIsOn", (char*) cacheArchL2CacheIsOn, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheArchLocSizeGet", (char*) cacheArchLocSizeGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheArchLouSizeGet", (char*) cacheArchLouSizeGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheArchPipeFlush", (char*) cacheArchPipeFlush, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheArchState", (char*) &cacheArchState, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "cacheClear", (char*) cacheClear, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheCortexA15DClearDisable", (char*) cacheCortexA15DClearDisable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheCortexA15L2CacrGet", (char*) cacheCortexA15L2CacrGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheCortexA15L2CacrSet", (char*) cacheCortexA15L2CacrSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheCortexA15L2EcrGet", (char*) cacheCortexA15L2EcrGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheCortexA15L2EcrSet", (char*) cacheCortexA15L2EcrSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheCortexA15LibInstall", (char*) cacheCortexA15LibInstall, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheCortexA8DClearDisable", (char*) cacheCortexA8DClearDisable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheCortexA8L2CacrGet", (char*) cacheCortexA8L2CacrGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheCortexA8L2CacrSet", (char*) cacheCortexA8L2CacrSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheCortexA8L2ClearAll", (char*) cacheCortexA8L2ClearAll, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheCortexA8L2Disable", (char*) cacheCortexA8L2Disable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheCortexA8L2Enable", (char*) cacheCortexA8L2Enable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheDataEnabled", (char*) &cacheDataEnabled, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "cacheDataMode", (char*) &cacheDataMode, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "cacheDisable", (char*) cacheDisable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheDma32Free", (char*) cacheDma32Free, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheDma32Malloc", (char*) cacheDma32Malloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheDmaFree", (char*) cacheDmaFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheDmaFreeRtn", (char*) &cacheDmaFreeRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "cacheDmaFuncs", (char*) &cacheDmaFuncs, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "cacheDmaMalloc", (char*) cacheDmaMalloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheDmaMallocRtn", (char*) &cacheDmaMallocRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "cacheDrvFlush", (char*) cacheDrvFlush, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheDrvInvalidate", (char*) cacheDrvInvalidate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheDrvPhysToVirt", (char*) cacheDrvPhysToVirt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheDrvVirtToPhys", (char*) cacheDrvVirtToPhys, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheEnable", (char*) cacheEnable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheFlush", (char*) cacheFlush, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheForeignClear", (char*) cacheForeignClear, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheForeignFlush", (char*) cacheForeignFlush, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheForeignInvalidate", (char*) cacheForeignInvalidate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheFuncsSet", (char*) cacheFuncsSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheInvalidate", (char*) cacheInvalidate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheLib", (char*) &cacheLib, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "cacheLibInit", (char*) cacheLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheLineMask", (char*) &cacheLineMask, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "cacheLineSize", (char*) &cacheLineSize, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "cacheLock", (char*) cacheLock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheMmuAvailable", (char*) &cacheMmuAvailable, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "cacheNullFuncs", (char*) &cacheNullFuncs, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "cachePipeFlush", (char*) cachePipeFlush, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheTextLocalUpdate", (char*) cacheTextLocalUpdate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheTextUpdate", (char*) cacheTextUpdate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheUnlock", (char*) cacheUnlock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cacheUserFuncs", (char*) &cacheUserFuncs, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "calloc", (char*) calloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "catInfo", (char*) &catInfo, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "cd", (char*) cd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ceil", (char*) ceil, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cfree", (char*) cfree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "changeFpReg", (char*) changeFpReg, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "changeLogLevel", (char*) changeLogLevel, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "changeReg", (char*) changeReg, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "chdir", (char*) chdir, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "checkStack", (char*) checkStack, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "checksum", (char*) checksum, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "chkdsk", (char*) chkdsk, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "chmod", (char*) chmod, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "classCreateConnect", (char*) classCreateConnect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "classDestroyConnect", (char*) classDestroyConnect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "classIdTable", (char*) &classIdTable, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "classInit", (char*) classInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "classLibInit", (char*) classLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "classListLibInit", (char*) classListLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "classMemPartIdSet", (char*) classMemPartIdSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "classShowConnect", (char*) classShowConnect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clearerr", (char*) clearerr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_all_show", (char*) clk_all_show, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_cpu_get", (char*) clk_cpu_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_cpu_show", (char*) clk_cpu_show, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_ddr_get", (char*) clk_ddr_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_ddr_show", (char*) clk_ddr_show, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_fclk0_get", (char*) clk_fclk0_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_fclk1_get", (char*) clk_fclk1_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_fclk2_get", (char*) clk_fclk2_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_fclk3_get", (char*) clk_fclk3_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_fclk_show", (char*) clk_fclk_show, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_gem0_show", (char*) clk_gem0_show, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_gem0_tx_div_get", (char*) clk_gem0_tx_div_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_gem0_tx_get", (char*) clk_gem0_tx_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_gem1_show", (char*) clk_gem1_show, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_gem1_tx_div_get", (char*) clk_gem1_tx_div_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_gem1_tx_get", (char*) clk_gem1_tx_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_gtc_get", (char*) clk_gtc_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_gtc_show", (char*) clk_gtc_show, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_nfc_get", (char*) clk_nfc_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_nfc_show", (char*) clk_nfc_show, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_pcap_get", (char*) clk_pcap_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_pcap_show", (char*) clk_pcap_show, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_qspi_get", (char*) clk_qspi_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_qspi_show", (char*) clk_qspi_show, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_sdmmc_get", (char*) clk_sdmmc_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_sdmmc_set", (char*) clk_sdmmc_set, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_sdmmc_show", (char*) clk_sdmmc_show, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_spi_get", (char*) clk_spi_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_spi_show", (char*) clk_spi_show, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_switch_sdmmc_0", (char*) clk_switch_sdmmc_0, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_switch_sdmmc_1", (char*) clk_switch_sdmmc_1, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_ttc_get", (char*) clk_ttc_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_ttc_show", (char*) clk_ttc_show, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_uart_get", (char*) clk_uart_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clk_uart_show", (char*) clk_uart_show, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clock", (char*) clock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clockLibInit", (char*) clockLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clock_getres", (char*) clock_getres, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clock_gettime", (char*) clock_gettime, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clock_gettime_wd", (char*) clock_gettime_wd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clock_nanosleep", (char*) clock_nanosleep, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clock_setres", (char*) clock_setres, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "clock_settime", (char*) clock_settime, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "close", (char*) close, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "closedir", (char*) closedir, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "code_table", (char*) &code_table, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "commit", (char*) commit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "completionPathComplete", (char*) completionPathComplete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "completionPathListGet", (char*) completionPathListGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "completionPathShow", (char*) completionPathShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "completionSymComplete", (char*) completionSymComplete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "completionSymListGet", (char*) completionSymListGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "completionSymShow", (char*) completionSymShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "connect", (char*) connect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "connectWithTimeout", (char*) connectWithTimeout, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "consoleFd", (char*) &consoleFd, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "coprocCtxReplicate", (char*) coprocCtxReplicate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "coprocCtxStorageSizeGet", (char*) coprocCtxStorageSizeGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "coprocDescriptorsInit", (char*) coprocDescriptorsInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "coprocDisable", (char*) coprocDisable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "coprocEnable", (char*) coprocEnable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "coprocLibInit", (char*) coprocLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "coprocMRegs", (char*) coprocMRegs, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "coprocRegListShow", (char*) coprocRegListShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "coprocSave", (char*) coprocSave, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "coprocShow", (char*) coprocShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "coprocShowInit", (char*) coprocShowInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "coprocShowOnDebug", (char*) coprocShowOnDebug, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "coprocTaskCreateHook", (char*) coprocTaskCreateHook, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "coprocTaskDeleteHook", (char*) coprocTaskDeleteHook, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "coprocTaskRegsGet", (char*) coprocTaskRegsGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "coprocTaskRegsSet", (char*) coprocTaskRegsSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "coprocTaskRegsShow", (char*) coprocTaskRegsShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "coprocTaskSwapHook", (char*) coprocTaskSwapHook, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "coprocsDiscover", (char*) coprocsDiscover, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "copy", (char*) copy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "copyStreams", (char*) copyStreams, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "copysign", (char*) copysign, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cos", (char*) cos, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cosh", (char*) cosh, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cp", (char*) cp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cp2", (char*) cp2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cplusCallCtors", (char*) cplusCallCtors, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cplusCallDtors", (char*) cplusCallDtors, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cplusCtors", (char*) cplusCtors, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cplusCtorsLink", (char*) cplusCtorsLink, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cplusDemangle", (char*) cplusDemangle, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cplusDemangle2", (char*) cplusDemangle2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cplusDemangle2Func", (char*) &cplusDemangle2Func, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "cplusDemangleFunc", (char*) &cplusDemangleFunc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "cplusDemangleToBuffer", (char*) cplusDemangleToBuffer, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cplusDemangleToBufferFunc", (char*) &cplusDemangleToBufferFunc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "cplusDemanglerMode", (char*) &cplusDemanglerMode, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "cplusDemanglerSet", (char*) cplusDemanglerSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cplusDemanglerStyle", (char*) &cplusDemanglerStyle, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "cplusDemanglerStyleInit", (char*) cplusDemanglerStyleInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cplusDemanglerStyleSet", (char*) cplusDemanglerStyleSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cplusDtors", (char*) cplusDtors, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cplusDtorsLink", (char*) cplusDtorsLink, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cplusLoadCtorsCall", (char*) cplusLoadCtorsCall, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cplusLoadFixup", (char*) cplusLoadFixup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cplusMangledSymCheck", (char*) cplusMangledSymCheck, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cplusMangledSymGet", (char*) cplusMangledSymGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cplusMatchMangled", (char*) cplusMatchMangled, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cplusMatchMangledListGet", (char*) cplusMatchMangledListGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cplusUnloadFixup", (char*) cplusUnloadFixup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cplusUserAsk", (char*) cplusUserAsk, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cplusXtorGet", (char*) cplusXtorGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cplusXtorSet", (char*) cplusXtorSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "cplusXtorStrategy", (char*) &cplusXtorStrategy, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "cpsr", (char*) cpsr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "creat", (char*) creat, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "creationDate", (char*) &creationDate, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "cret", (char*) cret, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ctime", (char*) ctime, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ctime_r", (char*) ctime_r, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "d", (char*) d, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "data_bit_table", (char*) &data_bit_table, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "dbgBpEpCoreRtn", (char*) dbgBpEpCoreRtn, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dbgBpListPrint", (char*) dbgBpListPrint, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dbgCallPrint", (char*) dbgCallPrint, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dbgDisassemble", (char*) dbgDisassemble, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dbgDynPrintfCommonRtn", (char*) dbgDynPrintfCommonRtn, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dbgHelp", (char*) dbgHelp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dbgInit", (char*) dbgInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dbgPrintDsp", (char*) &dbgPrintDsp, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "dbgPrintFpp", (char*) &dbgPrintFpp, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "dbgPrintSimd", (char*) &dbgPrintSimd, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "dbgShellCmdInit", (char*) dbgShellCmdInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dbgStackTrace", (char*) dbgStackTrace, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dbgTaskTraceCoreRtn", (char*) dbgTaskTraceCoreRtn, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ddr_dRate_get", (char*) ddr_dRate_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "defaultDrv", (char*) &defaultDrv, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "delay_1ms", (char*) delay_1ms, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "delay_1us", (char*) delay_1us, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "delay_ms", (char*) delay_ms, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "delay_us", (char*) delay_us, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devAttach", (char*) devAttach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devC_Load_BitStream_NonSecure", (char*) devC_Load_BitStream_NonSecure, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devC_Load_BitStream_NonSecure_2", (char*) devC_Load_BitStream_NonSecure_2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devC_Update_PL", (char*) devC_Update_PL, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devC_Update_PL_part", (char*) devC_Update_PL_part, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devDetach", (char*) devDetach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devGetByName", (char*) devGetByName, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devInit", (char*) devInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devMap", (char*) devMap, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devMapUnsafe", (char*) devMapUnsafe, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devName", (char*) devName, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devResourceGet", (char*) devResourceGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devResourceIntrGet", (char*) devResourceIntrGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devUnmap", (char*) devUnmap, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devUnmapUnsafe", (char*) devUnmapUnsafe, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dev_config_init", (char*) dev_config_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dev_config_load_defaults", (char*) dev_config_load_defaults, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dev_config_print", (char*) dev_config_print, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dev_config_save", (char*) dev_config_save, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dev_reboot", (char*) dev_reboot, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcCtrl_Clr_PL_BitStream", (char*) devcCtrl_Clr_PL_BitStream, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcCtrl_Clr_PcapStatus", (char*) devcCtrl_Clr_PcapStatus, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcCtrl_Init_Pcap", (char*) devcCtrl_Init_Pcap, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcCtrl_Init_PcapDma", (char*) devcCtrl_Init_PcapDma, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcCtrl_Init_PcapDma_RdBack", (char*) devcCtrl_Init_PcapDma_RdBack, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcCtrl_Init_Pcap_part", (char*) devcCtrl_Init_Pcap_part, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcCtrl_Load_Pcap_BitStream", (char*) devcCtrl_Load_Pcap_BitStream, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcCtrl_Lock_CSU", (char*) devcCtrl_Lock_CSU, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcCtrl_Poll_DmaDone", (char*) devcCtrl_Poll_DmaDone, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcCtrl_Poll_DmaPcap_Done", (char*) devcCtrl_Poll_DmaPcap_Done, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcCtrl_Poll_FpgaDone", (char*) devcCtrl_Poll_FpgaDone, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcCtrl_Prog_B", (char*) devcCtrl_Prog_B, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcCtrl_Rd_CfgReg32", (char*) devcCtrl_Rd_CfgReg32, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcCtrl_SAC_rst", (char*) devcCtrl_SAC_rst, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcCtrl_SetHi_CSI_B", (char*) devcCtrl_SetHi_CSI_B, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcCtrl_SetHi_RDWR_B", (char*) devcCtrl_SetHi_RDWR_B, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcCtrl_SetLow_CSI_B", (char*) devcCtrl_SetLow_CSI_B, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcCtrl_SetLow_RDWR_B", (char*) devcCtrl_SetLow_RDWR_B, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcCtrl_Set_DummyCnt", (char*) devcCtrl_Set_DummyCnt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcCtrl_Set_PL_DwnLdMode", (char*) devcCtrl_Set_PL_DwnLdMode, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcCtrl_Set_RdClk_Edge", (char*) devcCtrl_Set_RdClk_Edge, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcCtrl_Set_ReadFifoThrsh", (char*) devcCtrl_Set_ReadFifoThrsh, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcCtrl_Set_Reg32", (char*) devcCtrl_Set_Reg32, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcCtrl_Set_RxDataSwap", (char*) devcCtrl_Set_RxDataSwap, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcCtrl_Set_Smap32_SwapCtrl", (char*) devcCtrl_Set_Smap32_SwapCtrl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcCtrl_Set_TxDataSwap", (char*) devcCtrl_Set_TxDataSwap, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcCtrl_Set_WrClk_Edge", (char*) devcCtrl_Set_WrClk_Edge, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcCtrl_Set_WriteFifoThrsh", (char*) devcCtrl_Set_WriteFifoThrsh, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcCtrl_UnLock_CSU", (char*) devcCtrl_UnLock_CSU, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcCtrl_Wr_CfgReg32", (char*) devcCtrl_Wr_CfgReg32, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcCtrl_Xfer_Pcap", (char*) devcCtrl_Xfer_Pcap, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcSlcr_Dis_CfgLvlShift", (char*) devcSlcr_Dis_CfgLvlShift, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcSlcr_Dis_UseLvlShift", (char*) devcSlcr_Dis_UseLvlShift, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcSlcr_Down_CpuFreq", (char*) devcSlcr_Down_CpuFreq, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcSlcr_En_CfgLvlShift", (char*) devcSlcr_En_CfgLvlShift, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcSlcr_En_UsrLvlShift", (char*) devcSlcr_En_UsrLvlShift, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devcSlcr_Up_CpuFreq", (char*) devcSlcr_Up_CpuFreq, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "devs", (char*) devs, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "difftime", (char*) difftime, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dirList", (char*) dirList, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "diskFormat", (char*) diskFormat, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "diskInit", (char*) diskInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "div", (char*) div, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "div32", (char*) div32, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "div_r", (char*) div_r, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dllAdd", (char*) dllAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dllCount", (char*) dllCount, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dllEach", (char*) dllEach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dllGet", (char*) dllGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dllInit", (char*) dllInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dllInsert", (char*) dllInsert, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dllRemove", (char*) dllRemove, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dllTerminate", (char*) dllTerminate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Chk_ChnBusy", (char*) dmaCtrl_Chk_ChnBusy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Chk_ChnRange", (char*) dmaCtrl_Chk_ChnRange, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Clr_IRQ", (char*) dmaCtrl_Clr_IRQ, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Dis_ChnIRQ", (char*) dmaCtrl_Dis_ChnIRQ, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Dis_ChnX", (char*) dmaCtrl_Dis_ChnX, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Dis_Ctrl", (char*) dmaCtrl_Dis_Ctrl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Disable_Ctrl", (char*) dmaCtrl_Disable_Ctrl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_En_ChnIRQ", (char*) dmaCtrl_En_ChnIRQ, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Enable_ChnX", (char*) dmaCtrl_Enable_ChnX, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Enable_Ctrl", (char*) dmaCtrl_Enable_Ctrl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Get_BurstSize", (char*) dmaCtrl_Get_BurstSize, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Get_ChnCfg", (char*) dmaCtrl_Get_ChnCfg, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Get_ChnIdx", (char*) dmaCtrl_Get_ChnIdx, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Get_DefaultParams", (char*) dmaCtrl_Get_DefaultParams, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Get_DefaultParams2", (char*) dmaCtrl_Get_DefaultParams2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Get_FreeChn", (char*) dmaCtrl_Get_FreeChn, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Get_HandShakMode", (char*) dmaCtrl_Get_HandShakMode, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Get_PartParams", (char*) dmaCtrl_Get_PartParams, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Get_XferPath", (char*) dmaCtrl_Get_XferPath, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Get_XferType", (char*) dmaCtrl_Get_XferType, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Get_XferWidth", (char*) dmaCtrl_Get_XferWidth, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Init", (char*) dmaCtrl_Init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Mask_IRQ", (char*) dmaCtrl_Mask_IRQ, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_PreInit", (char*) dmaCtrl_PreInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Rd_CfgReg32", (char*) dmaCtrl_Rd_CfgReg32, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Set_BlockChain_En", (char*) dmaCtrl_Set_BlockChain_En, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Set_BurstSize", (char*) dmaCtrl_Set_BurstSize, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Set_ChnCfg", (char*) dmaCtrl_Set_ChnCfg, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Set_ChnPriority", (char*) dmaCtrl_Set_ChnPriority, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Set_HandShakMode", (char*) dmaCtrl_Set_HandShakMode, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Set_ListPtrAddr", (char*) dmaCtrl_Set_ListPtrAddr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Set_ReLoad", (char*) dmaCtrl_Set_ReLoad, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Set_TestMode", (char*) dmaCtrl_Set_TestMode, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Set_XferPath", (char*) dmaCtrl_Set_XferPath, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Set_XferType", (char*) dmaCtrl_Set_XferType, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Set_XferWidth", (char*) dmaCtrl_Set_XferWidth, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Start_Xfer", (char*) dmaCtrl_Start_Xfer, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_UnMask_IRQ", (char*) dmaCtrl_UnMask_IRQ, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmaCtrl_Wr_CfgReg32", (char*) dmaCtrl_Wr_CfgReg32, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dmac_test_example", (char*) dmac_test_example, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosChkDebug", (char*) &dosChkDebug, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "dosChkDsk", (char*) dosChkDsk, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosChkLibInit", (char*) dosChkLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosChkMinDate", (char*) &dosChkMinDate, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "dosDirHdlrsList", (char*) &dosDirHdlrsList, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "dosDirOldDebug", (char*) &dosDirOldDebug, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "dosDirOldLibInit", (char*) dosDirOldLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFatHdlrsList", (char*) &dosFatHdlrsList, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "dosFsCacheCreate", (char*) dosFsCacheCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsCacheCreateRtn", (char*) &dosFsCacheCreateRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "dosFsCacheDataDirDefaultSize", (char*) &dosFsCacheDataDirDefaultSize, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "dosFsCacheDelete", (char*) dosFsCacheDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsCacheDeleteRtn", (char*) &dosFsCacheDeleteRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "dosFsCacheFatDefaultSize", (char*) &dosFsCacheFatDefaultSize, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "dosFsCacheInfo", (char*) dosFsCacheInfo, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsCacheLibInit", (char*) dosFsCacheLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsCacheMountRtn", (char*) &dosFsCacheMountRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "dosFsCacheShow", (char*) dosFsCacheShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsCacheTune", (char*) dosFsCacheTune, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsCacheUnmountRtn", (char*) &dosFsCacheUnmountRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "dosFsChkDsk", (char*) dosFsChkDsk, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsChkRtn", (char*) &dosFsChkRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "dosFsClose", (char*) dosFsClose, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsCompatNT", (char*) &dosFsCompatNT, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "dosFsDebug", (char*) &dosFsDebug, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "dosFsDefaultCacheSizeSet", (char*) dosFsDefaultCacheSizeSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsDefaultDataDirCacheSizeGet", (char*) dosFsDefaultDataDirCacheSizeGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsDefaultFatCacheSizeGet", (char*) dosFsDefaultFatCacheSizeGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsDevCreate", (char*) dosFsDevCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsDevDelete", (char*) dosFsDevDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsDicard", (char*) dosFsDicard, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsDiskProbe", (char*) dosFsDiskProbe, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsDrvNum", (char*) &dosFsDrvNum, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "dosFsFatInit", (char*) dosFsFatInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsFdFree", (char*) dosFsFdFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsFdGet", (char*) dosFsFdGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsFmtLargeWriteSize", (char*) &dosFsFmtLargeWriteSize, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "dosFsFmtLibInit", (char*) dosFsFmtLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsHdlrInstall", (char*) dosFsHdlrInstall, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsIoctl", (char*) dosFsIoctl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsLastAccessDateEnable", (char*) dosFsLastAccessDateEnable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsLibInit", (char*) dosFsLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsMonitorDevCreate", (char*) dosFsMonitorDevCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsMsgLevel", (char*) &dosFsMsgLevel, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "dosFsMutexOptions", (char*) &dosFsMutexOptions, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "dosFsOpen", (char*) dosFsOpen, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsShow", (char*) dosFsShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsShowInit", (char*) dosFsShowInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsTCacheShow", (char*) dosFsTCacheShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsVolDescGet", (char*) dosFsVolDescGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsVolFormat", (char*) dosFsVolFormat, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsVolFormatFd", (char*) dosFsVolFormatFd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsVolFormatWithLabel", (char*) dosFsVolFormatWithLabel, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsVolIsFat12", (char*) dosFsVolIsFat12, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsVolUnmount", (char*) dosFsVolUnmount, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsVolumeBioBufferSize", (char*) &dosFsVolumeBioBufferSize, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "dosFsVolumeOptionsGet", (char*) dosFsVolumeOptionsGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsVolumeOptionsSet", (char*) dosFsVolumeOptionsSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsXbdBlkCopy", (char*) dosFsXbdBlkCopy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsXbdBlkRead", (char*) dosFsXbdBlkRead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsXbdBlkWrite", (char*) dosFsXbdBlkWrite, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsXbdBytesRW", (char*) dosFsXbdBytesRW, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosFsXbdIoctl", (char*) dosFsXbdIoctl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosPathParse", (char*) dosPathParse, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosSetVolCaseSens", (char*) dosSetVolCaseSens, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosVDirDebug", (char*) &dosVDirDebug, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "dosVDirLibInit", (char*) dosVDirLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosVDirLibUptDotDot", (char*) dosVDirLibUptDotDot, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosVDirMutexOpt", (char*) &dosVDirMutexOpt, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "dosVDirReaddirPlus", (char*) dosVDirReaddirPlus, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosfsDiskFormat", (char*) dosfsDiskFormat, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosfsDiskToHost16", (char*) dosfsDiskToHost16, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosfsDiskToHost32", (char*) dosfsDiskToHost32, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosfsHostToDisk16", (char*) dosfsHostToDisk16, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dosfsHostToDisk32", (char*) dosfsHostToDisk32, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "downCpuFreq_ARM_PLL", (char*) &downCpuFreq_ARM_PLL, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "dprintf", (char*) dprintf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dprintfVerboseLvl", (char*) &dprintfVerboseLvl, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "drvTable", (char*) &drvTable, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "dsmInst", (char*) dsmInst, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dsmNbytes", (char*) dsmNbytes, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dummyErrno", (char*) &dummyErrno, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "dup", (char*) dup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "dup2", (char*) dup2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "e", (char*) e, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "edrErrorInjectStub", (char*) edrErrorInjectStub, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "edrErrorPolicyHookRemove", (char*) edrErrorPolicyHookRemove, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "edrFlagsGet", (char*) edrFlagsGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "edrInitFatalPolicyHandler", (char*) edrInitFatalPolicyHandler, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "edrInterruptFatalPolicyHandler", (char*) edrInterruptFatalPolicyHandler, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "edrIsDebugMode", (char*) edrIsDebugMode, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "edrKernelFatalPolicyHandler", (char*) edrKernelFatalPolicyHandler, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "edrPolicyHandlerHookAdd", (char*) edrPolicyHandlerHookAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "edrPolicyHandlerHookGet", (char*) edrPolicyHandlerHookGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "edrRtpFatalPolicyHandler", (char*) edrRtpFatalPolicyHandler, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "edrStubInit", (char*) edrStubInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "edrSystemDebugModeGet", (char*) edrSystemDebugModeGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "edrSystemDebugModeInit", (char*) edrSystemDebugModeInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "edrSystemDebugModeSet", (char*) edrSystemDebugModeSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "edrSystemFatalPolicyHandler", (char*) edrSystemFatalPolicyHandler, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "elfArchInitHook", (char*) &elfArchInitHook, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "elfArchMdlLoadHook", (char*) &elfArchMdlLoadHook, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "elfArchReloc", (char*) elfArchReloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "elfArchSymProcessHook", (char*) &elfArchSymProcessHook, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "elfArchVerify", (char*) elfArchVerify, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "end8023AddressForm", (char*) end8023AddressForm, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "endDevName", (char*) endDevName, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "endDevTbl", (char*) &endDevTbl, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "endEtherAddressForm", (char*) endEtherAddressForm, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "endEtherCrc32BeGet", (char*) endEtherCrc32BeGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "endEtherCrc32LeGet", (char*) endEtherCrc32LeGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "endEtherHdrInit", (char*) endEtherHdrInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "endEtherPacketAddrGet", (char*) endEtherPacketAddrGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "endEtherPacketDataGet", (char*) endEtherPacketDataGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "endFindByName", (char*) endFindByName, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "endFirstUnitFind", (char*) endFirstUnitFind, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "endFlagsClr", (char*) endFlagsClr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "endFlagsGet", (char*) endFlagsGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "endFlagsSet", (char*) endFlagsSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "endLibInit", (char*) endLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "endList", (char*) &endList, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "endM2Free", (char*) endM2Free, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "endM2Init", (char*) endM2Init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "endM2Ioctl", (char*) endM2Ioctl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "endM2Packet", (char*) &endM2Packet, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "endMibIfInit", (char*) endMibIfInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "endMultiLstCnt", (char*) endMultiLstCnt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "endMultiLstFirst", (char*) endMultiLstFirst, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "endMultiLstNext", (char*) endMultiLstNext, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "endObjFlagSet", (char*) endObjFlagSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "endObjInit", (char*) endObjInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "endObjectUnload", (char*) endObjectUnload, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "endPollStatsInit", (char*) endPollStatsInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "endPoolClSize", (char*) &endPoolClSize, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "endPoolCreate", (char*) endPoolCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "endPoolDestroy", (char*) endPoolDestroy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "endPoolJumboClSize", (char*) &endPoolJumboClSize, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "endPoolJumboCreate", (char*) endPoolJumboCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "endRcvRtnCall", (char*) endRcvRtnCall, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "endTxSemGive", (char*) endTxSemGive, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "endTxSemTake", (char*) endTxSemTake, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "envGet", (char*) envGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "envLibInit", (char*) envLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "envLibSemId", (char*) &envLibSemId, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "envPrivateCreate", (char*) envPrivateCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "envPrivateDestroy", (char*) envPrivateDestroy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "envShow", (char*) envShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "erfCatDefSem", (char*) &erfCatDefSem, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "erfCatEventQueues", (char*) &erfCatEventQueues, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "erfCategoriesAvailable", (char*) erfCategoriesAvailable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "erfCategoryAllocate", (char*) erfCategoryAllocate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "erfCategoryQueueCreate", (char*) erfCategoryQueueCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "erfDbCatSem", (char*) &erfDbCatSem, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "erfDefaultEventQueue", (char*) &erfDefaultEventQueue, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "erfEventQueueSize", (char*) &erfEventQueueSize, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "erfEventRaise", (char*) erfEventRaise, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "erfEventTaskOptions", (char*) &erfEventTaskOptions, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "erfEventTaskPriority", (char*) &erfEventTaskPriority, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "erfEventTaskStackSize", (char*) &erfEventTaskStackSize, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "erfHandlerDb", (char*) &erfHandlerDb, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "erfHandlerRegister", (char*) erfHandlerRegister, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "erfHandlerUnregister", (char*) erfHandlerUnregister, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "erfLibInit", (char*) erfLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "erfLibInitialized", (char*) &erfLibInitialized, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "erfMaxNumCat", (char*) &erfMaxNumCat, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "erfMaxNumType", (char*) &erfMaxNumType, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "erfMaxNumUserCat", (char*) &erfMaxNumUserCat, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "erfMaxNumUserType", (char*) &erfMaxNumUserType, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "erfNumUserCatDef", (char*) &erfNumUserCatDef, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "erfNumUserTypeDef", (char*) &erfNumUserTypeDef, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "erfTypeAllocate", (char*) erfTypeAllocate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "erfTypesAvailable", (char*) erfTypesAvailable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "errno", (char*) &errno, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "errnoGet", (char*) errnoGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "errnoOfTaskGet", (char*) errnoOfTaskGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "errnoOfTaskSet", (char*) errnoOfTaskSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "errnoSet", (char*) errnoSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "eth2_clk_gem_set", (char*) eth2_clk_gem_set, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "etherMultiAdd", (char*) etherMultiAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "etherMultiDel", (char*) etherMultiDel, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "etherMultiGet", (char*) etherMultiGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "etherbroadcastaddr", (char*) &etherbroadcastaddr, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "eventClear", (char*) eventClear, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "eventInit", (char*) eventInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "eventLibInit", (char*) eventLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "eventPointStubLibInit", (char*) eventPointStubLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "eventPointSwHandle", (char*) eventPointSwHandle, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "eventPointSwStubConnect", (char*) eventPointSwStubConnect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "eventReceive", (char*) eventReceive, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "eventRsrcSend", (char*) eventRsrcSend, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "eventRsrcShow", (char*) eventRsrcShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "eventSend", (char*) eventSend, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "eventStart", (char*) eventStart, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "eventTaskShow", (char*) eventTaskShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "eventTerminate", (char*) eventTerminate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "evtAction", (char*) &evtAction, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "excEnterDataAbort", (char*) excEnterDataAbort, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "excEnterPrefetchAbort", (char*) excEnterPrefetchAbort, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "excEnterSwi", (char*) excEnterSwi, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "excEnterUndef", (char*) excEnterUndef, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "excExcContinue", (char*) excExcContinue, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "excExcHandle", (char*) excExcHandle, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "excExcepHook", (char*) &excExcepHook, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "excHookAdd", (char*) excHookAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "excInit", (char*) excInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "excIntConnect", (char*) excIntConnect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "excIntHandle", (char*) excIntHandle, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "excJobAdd", (char*) excJobAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "excJobAddDefer", (char*) excJobAddDefer, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "excOsmInit", (char*) excOsmInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "excPtrTableOffsetSet", (char*) excPtrTableOffsetSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "excShowInit", (char*) excShowInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "excVBARGet", (char*) excVBARGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "excVBARSet", (char*) excVBARSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "excVecBaseSet", (char*) excVecBaseSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "excVecGet", (char*) excVecGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "excVecInit", (char*) excVecInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "excVecSet", (char*) excVecSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "excVecUpdate", (char*) excVecUpdate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "excVmStateSet", (char*) excVmStateSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "exit", (char*) exit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "exp", (char*) exp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "expm1", (char*) expm1, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fabs", (char*) fabs, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fat16ClustValueGet", (char*) fat16ClustValueGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fat16ClustValueSet", (char*) fat16ClustValueSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fat16Debug", (char*) &fat16Debug, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "fat16VolMount", (char*) fat16VolMount, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fatClugFac", (char*) &fatClugFac, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "fchmod", (char*) fchmod, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fclose", (char*) fclose, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fcntl", (char*) fcntl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fcntl_dup", (char*) fcntl_dup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fd0", (char*) &fd0, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "fd1", (char*) &fd1, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "fd2", (char*) &fd2, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "fd3", (char*) &fd3, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "fdClass", (char*) &fdClass, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "fdInvalidDrv", (char*) &fdInvalidDrv, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "fdatasync", (char*) fdatasync, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fdopen", (char*) fdopen, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fdprintf", (char*) fdprintf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "feof", (char*) feof, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ferror", (char*) ferror, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fflush", (char*) fflush, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ffs32Lsb", (char*) ffs32Lsb, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ffs32Msb", (char*) ffs32Msb, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ffs64Lsb", (char*) ffs64Lsb, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ffs64Msb", (char*) ffs64Msb, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ffsLsb", (char*) ffsLsb, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ffsMsb", (char*) ffsMsb, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fgetc", (char*) fgetc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fgetpos", (char*) fgetpos, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fgets", (char*) fgets, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fieldSzIncludeSign", (char*) &fieldSzIncludeSign, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "file_idx_dosfs", (char*) &file_idx_dosfs, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "fileno", (char*) fileno, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fioBaseLibInit", (char*) fioBaseLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fioBufPrint", (char*) fioBufPrint, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fioBufPut", (char*) fioBufPut, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fioFltInstall", (char*) fioFltInstall, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fioFormatV", (char*) fioFormatV, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fioLibInit", (char*) fioLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fioRdString", (char*) fioRdString, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fioRead", (char*) fioRead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fioScanV", (char*) fioScanV, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fioSnBufPut", (char*) fioSnBufPut, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flAddLongToFarPointer", (char*) flAddLongToFarPointer, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flBufferOf", (char*) flBufferOf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flCall", (char*) flCall, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flCrc16", (char*) flCrc16, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flCreateMutex", (char*) flCreateMutex, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flCurrentDate", (char*) flCurrentDate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flCurrentTime", (char*) flCurrentTime, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flDelayLoop", (char*) flDelayLoop, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flDelayMsecs", (char*) flDelayMsecs, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flDontNeedVcc", (char*) flDontNeedVcc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flDontNeedVpp", (char*) flDontNeedVpp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flFileSysSectorStart", (char*) &flFileSysSectorStart, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "flFitInSocketWindow", (char*) flFitInSocketWindow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flFormat", (char*) flFormat, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flFreeMutex", (char*) flFreeMutex, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flGetMappingContext", (char*) flGetMappingContext, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flGetVolume", (char*) flGetVolume, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flIdentifyFlash", (char*) flIdentifyFlash, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flIdentifyRegister", (char*) flIdentifyRegister, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flInit", (char*) flInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flInitIdentifyTable", (char*) flInitIdentifyTable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flInitSocket", (char*) flInitSocket, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flInitSockets", (char*) flInitSockets, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flInstallTimer", (char*) flInstallTimer, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flIntelIdentify", (char*) flIntelIdentify, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flIntelSize", (char*) flIntelSize, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flIntervalRoutine", (char*) flIntervalRoutine, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flMap", (char*) flMap, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flMediaCheck", (char*) flMediaCheck, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flMount", (char*) flMount, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flMsecCounter", (char*) &flMsecCounter, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "flNeedVcc", (char*) flNeedVcc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flNeedVpp", (char*) flNeedVpp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flPollSemId", (char*) &flPollSemId, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "flPollTask", (char*) flPollTask, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flRandByte", (char*) flRandByte, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flRegisterComponents", (char*) flRegisterComponents, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flResetCardChanged", (char*) flResetCardChanged, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flSetPowerOnCallback", (char*) flSetPowerOnCallback, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flSetWindowBusWidth", (char*) flSetWindowBusWidth, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flSetWindowSize", (char*) flSetWindowSize, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flSetWindowSpeed", (char*) flSetWindowSpeed, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flSocketNoOf", (char*) flSocketNoOf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flSocketOf", (char*) flSocketOf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flSocketSetBusy", (char*) flSocketSetBusy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flSysfunInit", (char*) flSysfunInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flTakeMutex", (char*) flTakeMutex, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "flWriteProtected", (char*) flWriteProtected, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "floatInit", (char*) floatInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "floor", (char*) floor, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmQspiResources", (char*) &fmQspiResources, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "fmSdmmcResources2_dosFS", (char*) &fmSdmmcResources2_dosFS, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "fmSdmmcResources_dosFS", (char*) &fmSdmmcResources_dosFS, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "fmSpi0Resources", (char*) &fmSpi0Resources, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "fmSpi1Resources", (char*) &fmSpi1Resources, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "fmcp", (char*) fmcp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmod", (char*) fmod, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmprintf", (char*) fmprintf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmqlDebugWrite", (char*) fmqlDebugWrite, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmqlDebugWrite2", (char*) fmqlDebugWrite2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmqlMiiPhyFuncInit", (char*) fmqlMiiPhyFuncInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmqlMiiPhyRead", (char*) &fmqlMiiPhyRead, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "fmqlMiiPhyShow", (char*) &fmqlMiiPhyShow, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "fmqlMiiPhyWrite", (char*) &fmqlMiiPhyWrite, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "fmqlPhyRead", (char*) fmqlPhyRead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmqlPhyWrite", (char*) fmqlPhyWrite, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmqlSlcrRead", (char*) fmqlSlcrRead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmqlSlcrWrite", (char*) fmqlSlcrWrite, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmql_16550Pollprintf", (char*) fmql_16550Pollprintf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmshSdhcCtrl_BusWidthSetup", (char*) fmshSdhcCtrl_BusWidthSetup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmshSdhcCtrl_CardInsertSts", (char*) fmshSdhcCtrl_CardInsertSts, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmshSdhcCtrl_CardWpCheck", (char*) fmshSdhcCtrl_CardWpCheck, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmshSdhcCtrl_CmdIssue", (char*) fmshSdhcCtrl_CmdIssue, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmshSdhcCtrl_CmdIssuePoll", (char*) fmshSdhcCtrl_CmdIssuePoll, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmshSdhcCtrl_CmdPrepare", (char*) fmshSdhcCtrl_CmdPrepare, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmshSdhcCtrl_DevControl", (char*) fmshSdhcCtrl_DevControl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmshSdhcCtrl_Get_BusWidth", (char*) fmshSdhcCtrl_Get_BusWidth, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmshSdhcCtrl_Init", (char*) fmshSdhcCtrl_Init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmshSdhcCtrl_InstConnect", (char*) fmshSdhcCtrl_InstConnect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmshSdhcCtrl_InstInit", (char*) fmshSdhcCtrl_InstInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmshSdhcCtrl_InstInit2", (char*) fmshSdhcCtrl_InstInit2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmshSdhcCtrl_InterruptInfo", (char*) fmshSdhcCtrl_InterruptInfo, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmshSdhcCtrl_Isr", (char*) fmshSdhcCtrl_Isr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmshSdhcCtrl_Monitor", (char*) fmshSdhcCtrl_Monitor, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmshSdhcCtrl_PioRead", (char*) fmshSdhcCtrl_PioRead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmshSdhcCtrl_PioWrite", (char*) fmshSdhcCtrl_PioWrite, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmshSdhcCtrl_PollIntsts", (char*) fmshSdhcCtrl_PollIntsts, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmshSdhcCtrl_ReadFifo", (char*) fmshSdhcCtrl_ReadFifo, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmshSdhcCtrl_ResetFifo", (char*) fmshSdhcCtrl_ResetFifo, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmshSdhcCtrl_SendCmd", (char*) fmshSdhcCtrl_SendCmd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmshSdhcCtrl_SpecInfoGet", (char*) fmshSdhcCtrl_SpecInfoGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmshSdhcCtrl_WriteFifo", (char*) fmshSdhcCtrl_WriteFifo, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmshSdhcFuncs", (char*) &fmshSdhcFuncs, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "fmshSdhcPlbRegistration", (char*) &fmshSdhcPlbRegistration, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "fmshSdhcRegister", (char*) fmshSdhcRegister, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmshSdhc_ClkFreqSetup", (char*) fmshSdhc_ClkFreqSetup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmshSdhc_CmdIssue", (char*) fmshSdhc_CmdIssue, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmshSdhc_Get_Bitmode", (char*) fmshSdhc_Get_Bitmode, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fmshSdhc_VddSetup", (char*) fmshSdhc_VddSetup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fopen", (char*) fopen, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "formatFTL", (char*) formatFTL, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fpArmModules", (char*) &fpArmModules, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "fpTypeGet", (char*) fpTypeGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fpathconf", (char*) fpathconf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fppArchInit", (char*) fppArchInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fppArchTaskCreateInit", (char*) fppArchTaskCreateInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fppCtxShow", (char*) fppCtxShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fppCtxToRegs", (char*) fppCtxToRegs, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fppProbe", (char*) fppProbe, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fppRegListShow", (char*) fppRegListShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fppRegsToCtx", (char*) fppRegsToCtx, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fppRestore", (char*) fppRestore, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fppSave", (char*) fppSave, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fprintf", (char*) fprintf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fputc", (char*) fputc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fputs", (char*) fputs, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fread", (char*) fread, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "free", (char*) free, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "free_Bigints", (char*) free_Bigints, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "freeifaddrs", (char*) freeifaddrs, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "freopen", (char*) freopen, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "frexp", (char*) frexp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fromUNAL", (char*) fromUNAL, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fromUNALLONG", (char*) fromUNALLONG, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fsEventUtilLibInit", (char*) fsEventUtilLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fsMonitorInit", (char*) fsMonitorInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fsPathAddedEventRaise", (char*) fsPathAddedEventRaise, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fsPathAddedEventSetup", (char*) fsPathAddedEventSetup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fsWaitForPath", (char*) fsWaitForPath, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fscanf", (char*) fscanf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fseek", (char*) fseek, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fsetpos", (char*) fsetpos, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fsmGetDriver", (char*) fsmGetDriver, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fsmGetVolume", (char*) fsmGetVolume, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fsmInitialized", (char*) &fsmInitialized, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "fsmNameInstall", (char*) fsmNameInstall, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fsmNameMap", (char*) fsmNameMap, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fsmNameUninstall", (char*) fsmNameUninstall, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fsmProbeInstall", (char*) fsmProbeInstall, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fsmProbeUninstall", (char*) fsmProbeUninstall, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fsmUnmountHookAdd", (char*) fsmUnmountHookAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fsmUnmountHookDelete", (char*) fsmUnmountHookDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fsmUnmountHookRun", (char*) fsmUnmountHookRun, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fstat", (char*) fstat, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fstatfs", (char*) fstatfs, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fstatfs64", (char*) fstatfs64, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "fsync", (char*) fsync, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ftell", (char*) ftell, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ftpCommand", (char*) ftpCommand, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ftpCommandEnhanced", (char*) ftpCommandEnhanced, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ftpDataConnGet", (char*) ftpDataConnGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ftpDataConnInit", (char*) ftpDataConnInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ftpDataConnInitPassiveMode", (char*) ftpDataConnInitPassiveMode, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ftpHookup", (char*) ftpHookup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ftpLibDebugOptionsSet", (char*) ftpLibDebugOptionsSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ftpLibInit", (char*) ftpLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ftpLogin", (char*) ftpLogin, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ftpLs", (char*) ftpLs, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ftpReplyGet", (char*) ftpReplyGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ftpReplyGetEnhanced", (char*) ftpReplyGetEnhanced, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ftpReplyTimeout", (char*) &ftpReplyTimeout, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ftpTransientConfigGet", (char*) ftpTransientConfigGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ftpTransientConfigSet", (char*) ftpTransientConfigSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ftpTransientFatalInstall", (char*) ftpTransientFatalInstall, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ftpVerbose", (char*) &ftpVerbose, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ftpXfer", (char*) ftpXfer, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ftplDebug", (char*) &ftplDebug, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ftplPasvModeDisable", (char*) &ftplPasvModeDisable, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ftplTransientMaxRetryCount", (char*) &ftplTransientMaxRetryCount, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ftplTransientRetryInterval", (char*) &ftplTransientRetryInterval, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "funcXbdBlkCacheAttach", (char*) &funcXbdBlkCacheAttach, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "funcXbdBlkCacheDetach", (char*) &funcXbdBlkCacheDetach, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "funcXbdBlkCacheStrategy", (char*) &funcXbdBlkCacheStrategy, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "fwrite", (char*) fwrite, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gDMA_BlockNum", (char*) &gDMA_BlockNum, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "gDMA_BlockSize", (char*) &gDMA_BlockSize, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "gDMA_XferType", (char*) &gDMA_XferType, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "gSdmmc_Resp_Len_Type", (char*) &gSdmmc_Resp_Len_Type, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "g_1key_pressed", (char*) &g_1key_pressed, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "g_2key_pressed", (char*) &g_2key_pressed, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "g_DMA_dmac", (char*) &g_DMA_dmac, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "g_DMA_instance", (char*) &g_DMA_instance, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "g_DMA_param", (char*) &g_DMA_param, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "g_SDMMC", (char*) &g_SDMMC, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "g_SDMMC_dataParam", (char*) &g_SDMMC_dataParam, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "g_SDMMC_instance", (char*) &g_SDMMC_instance, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "g_config_conn_q", (char*) &g_config_conn_q, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "g_config_mutex", (char*) &g_config_mutex, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "g_config_task_manager_tid", (char*) &g_config_task_manager_tid, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "g_conn_manager_tid", (char*) &g_conn_manager_tid, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "g_counter1", (char*) &g_counter1, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "g_data_conn_q", (char*) &g_data_conn_q, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "g_gpio_poll_init_flag", (char*) &g_gpio_poll_init_flag, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "g_irq_name_no", (char*) &g_irq_name_no, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "g_pBuf8", (char*) &g_pBuf8, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "g_pBuf8_2", (char*) &g_pBuf8_2, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "g_pDevC", (char*) &g_pDevC, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "g_pDma", (char*) &g_pDma, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "g_pGpio", (char*) &g_pGpio, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "g_pGtc", (char*) &g_pGtc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "g_pQspi0", (char*) &g_pQspi0, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "g_pQspi1", (char*) &g_pQspi1, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "g_pSpi0", (char*) &g_pSpi0, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "g_pSpi1", (char*) &g_pSpi1, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "g_pUart0", (char*) &g_pUart0, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "g_pUart1", (char*) &g_pUart1, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "g_realtime_scheduler_tid", (char*) &g_realtime_scheduler_tid, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "g_sd_blk_num", (char*) &g_sd_blk_num, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "g_show_flag", (char*) &g_show_flag, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "g_system_config", (char*) &g_system_config, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "g_test_com1", (char*) &g_test_com1, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "g_test_qspi2", (char*) &g_test_qspi2, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "g_test_sd", (char*) &g_test_sd, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "g_test_sdmmc", (char*) &g_test_sdmmc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "g_test_sdmmc0", (char*) &g_test_sdmmc0, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "g_test_sdmmc1", (char*) &g_test_sdmmc1, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "g_test_spi2", (char*) &g_test_spi2, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "g_test_uart1", (char*) &g_test_uart1, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "g_uart2_test", (char*) &g_uart2_test, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "g_uboot_ipAddr", (char*) &g_uboot_ipAddr, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "g_udp_search_tid", (char*) &g_udp_search_tid, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "g_vxInit_Qspi_ok2", (char*) &g_vxInit_Qspi_ok2, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "gcrt", (char*) gcrt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gdir", (char*) gdir, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "genPhyDevRegistration", (char*) &genPhyDevRegistration, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "genPhyMdio0Resources", (char*) &genPhyMdio0Resources, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "genPhyMdio1Resources", (char*) &genPhyMdio1Resources, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "genPhyRegister", (char*) genPhyRegister, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "getHiddenSectorsFromDPT", (char*) getHiddenSectorsFromDPT, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "getOptServ", (char*) getOptServ, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "getPSMessageInfo", (char*) getPSMessageInfo, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "getSymNames", (char*) getSymNames, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "get_HARD_OSC_HZ", (char*) get_HARD_OSC_HZ, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "get_current_time", (char*) get_current_time, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "get_gtc_time", (char*) get_gtc_time, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "get_phyaddr_by_unit", (char*) get_phyaddr_by_unit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "get_sd_blk_num", (char*) get_sd_blk_num, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "get_unit_by_phyaddr", (char*) get_unit_by_phyaddr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "getc", (char*) getc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "getchar", (char*) getchar, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "getcwd", (char*) getcwd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "getenv", (char*) getenv, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "getenv_s", (char*) getenv_s, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gethostname", (char*) gethostname, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "getifaddrs", (char*) getifaddrs, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "getlhostbyaddr", (char*) getlhostbyaddr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "getlhostbyname", (char*) getlhostbyname, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "getopt", (char*) getopt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "getoptInit", (char*) getoptInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "getopt_r", (char*) getopt_r, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "getpeername", (char*) getpeername, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "getpid", (char*) getpid, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gets", (char*) gets, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "getsockname", (char*) getsockname, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "getsockopt", (char*) getsockopt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gettimeofday", (char*) gettimeofday, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "getw", (char*) getw, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "getwd", (char*) getwd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gicCpu", (char*) &gicCpu, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "gicInputs", (char*) &gicInputs, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "gicPriority", (char*) &gicPriority, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "gicTrigger", (char*) &gicTrigger, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "gic_show", (char*) gic_show, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gic_show2", (char*) gic_show2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gic_show_all", (char*) gic_show_all, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "globalNoStackFill", (char*) &globalNoStackFill, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "globalRAMPgPoolId", (char*) &globalRAMPgPoolId, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "global_timer_disable", (char*) global_timer_disable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "global_timer_enable", (char*) global_timer_enable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gmac0_info_show", (char*) gmac0_info_show, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gmac0_read", (char*) gmac0_read, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gmac0_write", (char*) gmac0_write, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gmac1_info_show", (char*) gmac1_info_show, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gmac1_read", (char*) gmac1_read, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gmac_reg_show", (char*) gmac_reg_show, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gmtime", (char*) gmtime, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gmtime_r", (char*) gmtime_r, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gop", (char*) gop, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gopherHookAdd", (char*) gopherHookAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gopherWriteChar", (char*) gopherWriteChar, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gopherWriteScalar", (char*) gopherWriteScalar, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioBank", (char*) &gpioBank, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "gpioCtrl_Clear_Irq", (char*) gpioCtrl_Clear_Irq, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_Disable_BothEdgeIrq", (char*) gpioCtrl_Disable_BothEdgeIrq, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_Disable_Debounce", (char*) gpioCtrl_Disable_Debounce, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_Disable_Irq", (char*) gpioCtrl_Disable_Irq, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_Disable_Sync", (char*) gpioCtrl_Disable_Sync, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_Enable_BothEdgeIrq", (char*) gpioCtrl_Enable_BothEdgeIrq, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_Enable_Debounce", (char*) gpioCtrl_Enable_Debounce, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_Enable_Irq", (char*) gpioCtrl_Enable_Irq, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_Enable_Sync", (char*) gpioCtrl_Enable_Sync, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_Get_ActiveIrq", (char*) gpioCtrl_Get_ActiveIrq, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_Get_BitDirection", (char*) gpioCtrl_Get_BitDirection, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_Get_BothEdgeIrq", (char*) gpioCtrl_Get_BothEdgeIrq, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_Get_ExtPort", (char*) gpioCtrl_Get_ExtPort, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_Get_IdCode", (char*) gpioCtrl_Get_IdCode, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_Get_Irq", (char*) gpioCtrl_Get_Irq, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_Get_IrqMask", (char*) gpioCtrl_Get_IrqMask, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_Get_IrqPolar", (char*) gpioCtrl_Get_IrqPolar, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_Get_IrqType", (char*) gpioCtrl_Get_IrqType, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_Get_PortBit_Chk", (char*) gpioCtrl_Get_PortBit_Chk, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_Get_PortDirection", (char*) gpioCtrl_Get_PortDirection, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_Get_VerIdCode", (char*) gpioCtrl_Get_VerIdCode, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_Mask_Irq", (char*) gpioCtrl_Mask_Irq, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_Rd_CfgReg32", (char*) gpioCtrl_Rd_CfgReg32, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_Read_Data", (char*) gpioCtrl_Read_Data, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_Set_BitDirection", (char*) gpioCtrl_Set_BitDirection, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_Set_IrqPolar", (char*) gpioCtrl_Set_IrqPolar, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_Set_IrqTrigger", (char*) gpioCtrl_Set_IrqTrigger, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_Set_IrqType", (char*) gpioCtrl_Set_IrqType, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_Set_PortBit", (char*) gpioCtrl_Set_PortBit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_Set_PortDirection", (char*) gpioCtrl_Set_PortDirection, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_Wr_CfgReg32", (char*) gpioCtrl_Wr_CfgReg32, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_Write_Data", (char*) gpioCtrl_Write_Data, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_isEnable_Debounce", (char*) gpioCtrl_isEnable_Debounce, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_isEnable_Irq", (char*) gpioCtrl_isEnable_Irq, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_isMask_Irq", (char*) gpioCtrl_isMask_Irq, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_isSync", (char*) gpioCtrl_isSync, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioCtrl_unMask_Irq", (char*) gpioCtrl_unMask_Irq, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioIsr_callbk", (char*) gpioIsr_callbk, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpioSlcr_Mio_Init", (char*) gpioSlcr_Mio_Init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpio_Irq_Enable", (char*) gpio_Irq_Enable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpio_Poll_Enable", (char*) gpio_Poll_Enable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpio_attach_irq", (char*) gpio_attach_irq, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpio_get_input_val", (char*) gpio_get_input_val, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpio_get_key_by_pin", (char*) gpio_get_key_by_pin, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpio_get_pins_by_bank", (char*) gpio_get_pins_by_bank, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpio_irq_init", (char*) gpio_irq_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpio_poll_init", (char*) gpio_poll_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpio_set_HIGH", (char*) gpio_set_HIGH, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpio_set_LOW", (char*) gpio_set_LOW, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpio_set_input", (char*) gpio_set_input, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpio_set_output", (char*) gpio_set_output, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gpio_set_output_val", (char*) gpio_set_output_val, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gptAdd", (char*) gptAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gptCheckMap", (char*) gptCheckMap, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gptCoreDebug", (char*) &gptCoreDebug, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "gptCreate", (char*) gptCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gptCreatePartDev", (char*) gptCreatePartDev, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gptDestroy", (char*) gptDestroy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gptExtParse", (char*) gptExtParse, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gptMapDebug", (char*) &gptMapDebug, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "gptMapWrite", (char*) gptMapWrite, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gptMbrParse", (char*) gptMbrParse, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gptMigrate", (char*) gptMigrate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gptParse", (char*) gptParse, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gptPartsGet", (char*) gptPartsGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gptRead", (char*) gptRead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gptRecover", (char*) gptRecover, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gptRemove", (char*) gptRemove, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gptShowMap", (char*) gptShowMap, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gptShowMbr", (char*) gptShowMbr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gptShowPartHdr", (char*) gptShowPartHdr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gptShowPartTable", (char*) gptShowPartTable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "grd", (char*) grd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gtcCtrl_Disable_Counter", (char*) gtcCtrl_Disable_Counter, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gtcCtrl_Enable_Counter", (char*) gtcCtrl_Enable_Counter, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gtcCtrl_Get_CounterH", (char*) gtcCtrl_Get_CounterH, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gtcCtrl_Get_CounterL", (char*) gtcCtrl_Get_CounterL, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gtcCtrl_Halt_Counter", (char*) gtcCtrl_Halt_Counter, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gtcCtrl_Rd_CfgReg32", (char*) gtcCtrl_Rd_CfgReg32, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gtcCtrl_Wr_CfgReg32", (char*) gtcCtrl_Wr_CfgReg32, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gtcCtrl_isStop", (char*) gtcCtrl_isStop, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gtcTimerDevResources", (char*) &gtcTimerDevResources, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "gtc_Get_Time", (char*) gtc_Get_Time, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gtc_enable", (char*) gtc_enable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "gwr", (char*) gwr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "h", (char*) h, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "handleContextGet", (char*) handleContextGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "handleContextGetBase", (char*) handleContextGetBase, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "handleContextSet", (char*) handleContextSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "handleInit", (char*) handleInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "handleShow", (char*) handleShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "handleShowConnect", (char*) handleShowConnect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "handleTerminate", (char*) handleTerminate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "handleTypeGet", (char*) handleTypeGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "handleVerify", (char*) handleVerify, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "handle_command", (char*) handle_command, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hardWareInterFaceBusInit", (char*) hardWareInterFaceBusInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hardWareInterFaceInit", (char*) hardWareInterFaceInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hashFuncIterScale", (char*) hashFuncIterScale, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hashFuncModulo", (char*) hashFuncModulo, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hashFuncMultiply", (char*) hashFuncMultiply, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hashKeyCmp", (char*) hashKeyCmp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hashKeyStrCmp", (char*) hashKeyStrCmp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hashLibInit", (char*) hashLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hashTblCreate", (char*) hashTblCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hashTblDelete", (char*) hashTblDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hashTblDestroy", (char*) hashTblDestroy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hashTblEach", (char*) hashTblEach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hashTblFind", (char*) hashTblFind, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hashTblInit", (char*) hashTblInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hashTblPut", (char*) hashTblPut, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hashTblRemove", (char*) hashTblRemove, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hashTblTerminate", (char*) hashTblTerminate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hcfDeviceGet", (char*) hcfDeviceGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hcfDeviceList", (char*) &hcfDeviceList, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "hcfDeviceNum", (char*) &hcfDeviceNum, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "hdprintf", (char*) hdprintf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "help", (char*) help, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hookAddToHead", (char*) hookAddToHead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hookAddToTail", (char*) hookAddToTail, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hookDelete", (char*) hookDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hookFind", (char*) hookFind, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hookShow", (char*) hookShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hookTblAddToHead", (char*) hookTblAddToHead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hookTblAddToTail", (char*) hookTblAddToTail, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hookTblDelete", (char*) hookTblDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hookTblFind", (char*) hookTblFind, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hookTblInit", (char*) hookTblInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hookTblShow", (char*) hookTblShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hookTblUpdatersUnpend", (char*) hookTblUpdatersUnpend, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hostAdd", (char*) hostAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hostDelete", (char*) hostDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hostGetByAddr", (char*) hostGetByAddr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hostGetByName", (char*) hostGetByName, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hostInitFlag", (char*) &hostInitFlag, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "hostList", (char*) &hostList, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "hostListSem", (char*) &hostListSem, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "hostTblInit", (char*) hostTblInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hostTblSearchByAddr", (char*) hostTblSearchByAddr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hostTblSearchByAddr2", (char*) hostTblSearchByAddr2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hostTblSearchByName", (char*) hostTblSearchByName, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hostTblSearchByName2", (char*) hostTblSearchByName2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hostTblSetup", (char*) hostTblSetup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hostentAlloc", (char*) hostentAlloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hostentFree", (char*) hostentFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hostnameSetup", (char*) hostnameSetup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hrfsDiskFormat", (char*) hrfsDiskFormat, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hrfsFmtRtn", (char*) &hrfsFmtRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "hwMemAlloc", (char*) hwMemAlloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hwMemFree", (char*) hwMemFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hwMemLibInit", (char*) hwMemLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "hwMemPool", (char*) &hwMemPool, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "hwMemPoolCreate", (char*) hwMemPoolCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "i", (char*) i, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iam", (char*) iam, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ifconfig", (char*) ifconfig, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "in_netof", (char*) in_netof, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "index", (char*) index, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "inet_addr", (char*) inet_addr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "inet_aton", (char*) inet_aton, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "inet_lnaof", (char*) inet_lnaof, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "inet_makeaddr", (char*) inet_makeaddr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "inet_makeaddr_b", (char*) inet_makeaddr_b, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "inet_netof", (char*) inet_netof, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "inet_netof_string", (char*) inet_netof_string, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "inet_network", (char*) inet_network, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "inet_ntoa", (char*) inet_ntoa, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "inet_ntoa_b", (char*) inet_ntoa_b, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "inet_ntop", (char*) inet_ntop, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "inet_pton", (char*) inet_pton, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "initApplLogger", (char*) initApplLogger, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "init_usart", (char*) init_usart, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "instParamModify_desc", (char*) &instParamModify_desc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "intArchConnect", (char*) intArchConnect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intArchDisconnect", (char*) intArchDisconnect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intCnt", (char*) &intCnt, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "intConnect", (char*) intConnect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intContext", (char*) intContext, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intCount", (char*) intCount, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intCpuEnable", (char*) intCpuEnable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intCpuLock", (char*) intCpuLock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intCpuMicroLock", (char*) intCpuMicroLock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intCpuMicroUnlock", (char*) intCpuMicroUnlock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intCpuUnlock", (char*) intCpuUnlock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intCtlrChainISR", (char*) intCtlrChainISR, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intCtlrDevID", (char*) &intCtlrDevID, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "intCtlrHwConfGet", (char*) intCtlrHwConfGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intCtlrISRAdd", (char*) intCtlrISRAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intCtlrISRDisable", (char*) intCtlrISRDisable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intCtlrISREnable", (char*) intCtlrISREnable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intCtlrISRRemove", (char*) intCtlrISRRemove, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intCtlrPinFind", (char*) intCtlrPinFind, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intCtlrStrayISR", (char*) intCtlrStrayISR, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intCtlrTableArgGet", (char*) intCtlrTableArgGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intCtlrTableCreate", (char*) intCtlrTableCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intCtlrTableFlagsGet", (char*) intCtlrTableFlagsGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intCtlrTableFlagsSet", (char*) intCtlrTableFlagsSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intCtlrTableIsrGet", (char*) intCtlrTableIsrGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intCtlrTableUserSet", (char*) intCtlrTableUserSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intDemuxErrorCount", (char*) &intDemuxErrorCount, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "intDisable", (char*) intDisable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intDisconnect", (char*) intDisconnect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intEnable", (char*) intEnable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intEnt", (char*) intEnt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intExit", (char*) intExit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intIFLock", (char*) intIFLock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intIFUnlock", (char*) intIFUnlock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intIntRtnNonPreempt", (char*) intIntRtnNonPreempt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intIntRtnPreempt", (char*) intIntRtnPreempt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intLevelSet", (char*) intLevelSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intLibInit", (char*) intLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intLock", (char*) intLock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intLockLevelGet", (char*) intLockLevelGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intLockLevelSet", (char*) intLockLevelSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intNestingLevel", (char*) &intNestingLevel, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "intRegsLock", (char*) intRegsLock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intRegsUnlock", (char*) intRegsUnlock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intRestrict", (char*) intRestrict, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intUninitVecSet", (char*) intUninitVecSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intUnlock", (char*) intUnlock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intVBRSet", (char*) intVBRSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intVecBaseGet", (char*) intVecBaseGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intVecBaseSet", (char*) intVecBaseSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "intVecTableWriteProtect", (char*) intVecTableWriteProtect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ioDefPath", (char*) &ioDefPath, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "ioDefPathCat", (char*) ioDefPathCat, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ioDefPathGet", (char*) ioDefPathGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ioDefPathSet", (char*) ioDefPathSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ioDefPathValidate", (char*) ioDefPathValidate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ioFullFileNameGet", (char*) ioFullFileNameGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ioGlobalStdGet", (char*) ioGlobalStdGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ioGlobalStdSet", (char*) ioGlobalStdSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ioHelp", (char*) ioHelp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ioMaxLinkLevels", (char*) &ioMaxLinkLevels, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ioPxCreateOrOpen", (char*) ioPxCreateOrOpen, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ioTaskStdGet", (char*) ioTaskStdGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ioTaskStdSet", (char*) ioTaskStdSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ioctl", (char*) ioctl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosClose", (char*) iosClose, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosCreate", (char*) iosCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosDelete", (char*) iosDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosDevAdd", (char*) iosDevAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosDevCheck", (char*) iosDevCheck, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosDevDelCallback", (char*) iosDevDelCallback, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosDevDelDrv", (char*) iosDevDelDrv, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosDevDelete", (char*) iosDevDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosDevFind", (char*) iosDevFind, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosDevMatch", (char*) iosDevMatch, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosDevReplace", (char*) iosDevReplace, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosDevReplaceExt", (char*) iosDevReplaceExt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosDevResume", (char*) iosDevResume, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosDevShow", (char*) iosDevShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosDevSuspend", (char*) iosDevSuspend, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosDrvInit", (char*) iosDrvInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosDrvInstall", (char*) iosDrvInstall, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosDrvIoctl", (char*) iosDrvIoctl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosDrvIoctlMemValSet", (char*) iosDrvIoctlMemValSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosDrvRemove", (char*) iosDrvRemove, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosDrvShow", (char*) iosDrvShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosDvList", (char*) &iosDvList, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "iosFdDevFind", (char*) iosFdDevFind, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosFdDrvValue", (char*) iosFdDrvValue, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosFdEntryGet", (char*) iosFdEntryGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosFdEntryIoctl", (char*) iosFdEntryIoctl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosFdEntryPool", (char*) &iosFdEntryPool, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "iosFdEntryReturn", (char*) iosFdEntryReturn, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosFdEntrySet", (char*) iosFdEntrySet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosFdFree", (char*) iosFdFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosFdMap", (char*) iosFdMap, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosFdMaxFiles", (char*) iosFdMaxFiles, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosFdNew", (char*) iosFdNew, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosFdSet", (char*) iosFdSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosFdShow", (char*) iosFdShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosFdTable", (char*) &iosFdTable, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "iosFdTableLock", (char*) iosFdTableLock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosFdTableUnlock", (char*) iosFdTableUnlock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosFdValue", (char*) iosFdValue, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosInit", (char*) iosInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosIoctl", (char*) iosIoctl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosIoctlInternal", (char*) iosIoctlInternal, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosLibInitialized", (char*) &iosLibInitialized, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "iosLock", (char*) iosLock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosMaxDrivers", (char*) &iosMaxDrivers, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "iosMaxFiles", (char*) &iosMaxFiles, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "iosNextDevGet", (char*) iosNextDevGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosOpen", (char*) iosOpen, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosPathFdEntryIoctl", (char*) iosPathFdEntryIoctl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosPathLibInit", (char*) iosPathLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosPse52Mode", (char*) &iosPse52Mode, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "iosPxLibInit", (char*) iosPxLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosPxLibInitialized", (char*) &iosPxLibInitialized, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "iosRead", (char*) iosRead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosRmvFdEntrySet", (char*) iosRmvFdEntrySet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosRmvLibInit", (char*) iosRmvLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosRtpDefPathGet", (char*) iosRtpDefPathGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosRtpDefPathSet", (char*) iosRtpDefPathSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosRtpDevCloseOrInvalidate", (char*) iosRtpDevCloseOrInvalidate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosRtpFdEntryMap", (char*) iosRtpFdEntryMap, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosRtpFdInvalid", (char*) iosRtpFdInvalid, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosRtpFdReserve", (char*) iosRtpFdReserve, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosRtpFdReserveCntrl", (char*) iosRtpFdReserveCntrl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosRtpFdSetup", (char*) iosRtpFdSetup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosRtpFdShow", (char*) iosRtpFdShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosRtpFdTableGet", (char*) iosRtpFdTableGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosRtpFdTableSizeGet", (char*) iosRtpFdTableSizeGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosRtpFdTblEntryGet", (char*) iosRtpFdTblEntryGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosRtpFdUnmap2", (char*) iosRtpFdUnmap2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosRtpIoTableSizeGet", (char*) iosRtpIoTableSizeGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosRtpIoTableSizeSet", (char*) iosRtpIoTableSizeSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosRtpLibInit", (char*) iosRtpLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosRtpTableSizeSet", (char*) iosRtpTableSizeSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosShowInit", (char*) iosShowInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosTaskCwdGet", (char*) iosTaskCwdGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosTaskCwdSet", (char*) iosTaskCwdSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosUnlock", (char*) iosUnlock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iosWrite", (char*) iosWrite, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ip_inaddr_any", (char*) &ip_inaddr_any, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipcomNetTask", (char*) ipcomNetTask, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_accept", (char*) ipcom_accept, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_accept_usr", (char*) ipcom_accept_usr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_asctime_r_vxworks", (char*) ipcom_asctime_r_vxworks, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_atomic_add", (char*) ipcom_atomic_add, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_atomic_add_and_return", (char*) ipcom_atomic_add_and_return, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_atomic_dec", (char*) ipcom_atomic_dec, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_atomic_get", (char*) ipcom_atomic_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_atomic_inc", (char*) ipcom_atomic_inc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_atomic_ptr_cas", (char*) ipcom_atomic_ptr_cas, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_atomic_set", (char*) ipcom_atomic_set, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_atomic_sub", (char*) ipcom_atomic_sub, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_atomic_sub_and_return", (char*) ipcom_atomic_sub_and_return, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_auth_chap_login", (char*) ipcom_auth_chap_login, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_auth_default_hash_rtn", (char*) ipcom_auth_default_hash_rtn, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_auth_hash", (char*) ipcom_auth_hash, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_auth_hash_get", (char*) ipcom_auth_hash_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_auth_hash_rtn_install", (char*) ipcom_auth_hash_rtn_install, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_auth_login", (char*) ipcom_auth_login, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_auth_old_and_unsecure_hash_rtn", (char*) ipcom_auth_old_and_unsecure_hash_rtn, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_auth_useradd", (char*) ipcom_auth_useradd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_auth_useradd_hash", (char*) ipcom_auth_useradd_hash, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_auth_userdel", (char*) ipcom_auth_userdel, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_auth_userget", (char*) ipcom_auth_userget, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_auth_userlist", (char*) ipcom_auth_userlist, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_bind", (char*) ipcom_bind, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_bind_usr", (char*) ipcom_bind_usr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_block_create", (char*) ipcom_block_create, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_block_delete", (char*) ipcom_block_delete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_block_post", (char*) ipcom_block_post, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_block_reader_create", (char*) ipcom_block_reader_create, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_block_wait", (char*) ipcom_block_wait, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_cache_line_size", (char*) ipcom_cache_line_size, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_calloc", (char*) ipcom_calloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_chdir", (char*) ipcom_chdir, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_clearenv", (char*) ipcom_clearenv, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_closedir", (char*) ipcom_closedir, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_closelog", (char*) ipcom_closelog, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_cmd_cat", (char*) ipcom_cmd_cat, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_cmd_cd", (char*) ipcom_cmd_cd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_cmd_cp", (char*) ipcom_cmd_cp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_cmd_date", (char*) ipcom_cmd_date, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_cmd_getenv", (char*) ipcom_cmd_getenv, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_cmd_if_caps_to_str", (char*) ipcom_cmd_if_caps_to_str, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_cmd_if_flags_to_str", (char*) ipcom_cmd_if_flags_to_str, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_cmd_key_to_str", (char*) ipcom_cmd_key_to_str, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_cmd_ls", (char*) ipcom_cmd_ls, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_cmd_mkdir", (char*) ipcom_cmd_mkdir, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_cmd_mv", (char*) ipcom_cmd_mv, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_cmd_pwd", (char*) ipcom_cmd_pwd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_cmd_rm", (char*) ipcom_cmd_rm, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_cmd_rmdir", (char*) ipcom_cmd_rmdir, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_cmd_setenv", (char*) ipcom_cmd_setenv, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_cmd_sockaddr_to_str", (char*) ipcom_cmd_sockaddr_to_str, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_cmd_str_to_key", (char*) ipcom_cmd_str_to_key, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_cmd_str_to_key2", (char*) ipcom_cmd_str_to_key2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_cmd_time", (char*) ipcom_cmd_time, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_cmd_uuencode", (char*) ipcom_cmd_uuencode, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_cmsg_nxthdr", (char*) ipcom_cmsg_nxthdr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_conf_max_link_hdr_size", (char*) &ipcom_conf_max_link_hdr_size, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "ipcom_conf_pkt_pool_buffer_alignment", (char*) &ipcom_conf_pkt_pool_buffer_alignment, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipcom_conf_pkt_pool_buffer_extra_space", (char*) &ipcom_conf_pkt_pool_buffer_extra_space, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipcom_configure", (char*) ipcom_configure, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_configure_reserved_cpus", (char*) ipcom_configure_reserved_cpus, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_connect", (char*) ipcom_connect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_connect_usr", (char*) ipcom_connect_usr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_cpu_is_online", (char*) ipcom_cpu_is_online, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_cpu_reserved_alloc", (char*) ipcom_cpu_reserved_alloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_cpu_reserved_free", (char*) ipcom_cpu_reserved_free, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_create", (char*) ipcom_create, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_ctime_r_vxworks", (char*) ipcom_ctime_r_vxworks, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_dns", (char*) &ipcom_dns, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "ipcom_dns_init_ok", (char*) &ipcom_dns_init_ok, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipcom_drv_eth_create", (char*) ipcom_drv_eth_create, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_drv_eth_exit", (char*) ipcom_drv_eth_exit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_drv_eth_filter_add_mcast_addr", (char*) ipcom_drv_eth_filter_add_mcast_addr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_drv_eth_filter_exit", (char*) ipcom_drv_eth_filter_exit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_drv_eth_filter_init", (char*) ipcom_drv_eth_filter_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_drv_eth_filter_remove_mcast_addr", (char*) ipcom_drv_eth_filter_remove_mcast_addr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_drv_eth_init", (char*) ipcom_drv_eth_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_drv_eth_ip_attach", (char*) ipcom_drv_eth_ip_attach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_errno_get", (char*) ipcom_errno_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_errno_set", (char*) ipcom_errno_set, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_fclose", (char*) ipcom_fclose, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_fdopen", (char*) ipcom_fdopen, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_feof", (char*) ipcom_feof, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_ferror", (char*) ipcom_ferror, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_fflush", (char*) ipcom_fflush, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_fileclose", (char*) ipcom_fileclose, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_fileno", (char*) ipcom_fileno, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_fileopen", (char*) ipcom_fileopen, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_fileread", (char*) ipcom_fileread, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_filewrite", (char*) ipcom_filewrite, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_fopen", (char*) ipcom_fopen, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_forwarder_ipsec_sa_cache_size", (char*) &ipcom_forwarder_ipsec_sa_cache_size, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipcom_forwarder_ipsec_single_output_queue", (char*) &ipcom_forwarder_ipsec_single_output_queue, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipcom_fread", (char*) ipcom_fread, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_free", (char*) ipcom_free, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_freeaddrinfo", (char*) ipcom_freeaddrinfo, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_freeaddrinfo2", (char*) ipcom_freeaddrinfo2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_freeifaddrs", (char*) ipcom_freeifaddrs, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_fseek", (char*) ipcom_fseek, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_fstat", (char*) ipcom_fstat, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_ftell", (char*) ipcom_ftell, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_fwrite", (char*) ipcom_fwrite, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_get_cpuid", (char*) ipcom_get_cpuid, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_get_ip_if_name", (char*) ipcom_get_ip_if_name, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_get_mux_dev_name", (char*) ipcom_get_mux_dev_name, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_get_start_shell_ptr", (char*) ipcom_get_start_shell_ptr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_get_true_cpuid", (char*) ipcom_get_true_cpuid, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_getaddrinfo", (char*) ipcom_getaddrinfo, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_getaddrinfo2", (char*) ipcom_getaddrinfo2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_getcwd", (char*) ipcom_getcwd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_getenv", (char*) ipcom_getenv, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_getenv_as_int", (char*) ipcom_getenv_as_int, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_gethostbyaddr", (char*) ipcom_gethostbyaddr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_gethostbyaddr_r", (char*) ipcom_gethostbyaddr_r, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_gethostbyaddrlocal", (char*) ipcom_gethostbyaddrlocal, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_gethostbyname", (char*) ipcom_gethostbyname, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_gethostbyname_r", (char*) ipcom_gethostbyname_r, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_gethostbynamelocal", (char*) ipcom_gethostbynamelocal, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_getifaddrs", (char*) ipcom_getifaddrs, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_getlogmask_on", (char*) ipcom_getlogmask_on, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_getnameinfo", (char*) ipcom_getnameinfo, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_getnameinfo2", (char*) ipcom_getnameinfo2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_getopt", (char*) ipcom_getopt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_getopt_clear", (char*) ipcom_getopt_clear, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_getopt_clear_r", (char*) ipcom_getopt_clear_r, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_getopt_data", (char*) &ipcom_getopt_data, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "ipcom_getopt_r", (char*) ipcom_getopt_r, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_getpeername", (char*) ipcom_getpeername, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_getpeername_usr", (char*) ipcom_getpeername_usr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_getpid", (char*) ipcom_getpid, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_getprotobyname", (char*) ipcom_getprotobyname, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_getprotobynumber", (char*) ipcom_getprotobynumber, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_getservbyname", (char*) ipcom_getservbyname, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_getservbyport", (char*) ipcom_getservbyport, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_getsockaddrbyaddr", (char*) ipcom_getsockaddrbyaddr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_getsockaddrbyaddrname", (char*) ipcom_getsockaddrbyaddrname, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_getsockname", (char*) ipcom_getsockname, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_getsockname_usr", (char*) ipcom_getsockname_usr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_getsockopt", (char*) ipcom_getsockopt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_getsockopt_usr", (char*) ipcom_getsockopt_usr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_gettimeofday", (char*) ipcom_gettimeofday, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_h_errno", (char*) &ipcom_h_errno, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "ipcom_hash_add", (char*) ipcom_hash_add, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_hash_delete", (char*) ipcom_hash_delete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_hash_for_each", (char*) ipcom_hash_for_each, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_hash_get", (char*) ipcom_hash_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_hash_new", (char*) ipcom_hash_new, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_hash_remove", (char*) ipcom_hash_remove, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_hash_update", (char*) ipcom_hash_update, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_heap_sort", (char*) ipcom_heap_sort, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_if_attach", (char*) ipcom_if_attach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_if_attach_and_lock", (char*) ipcom_if_attach_and_lock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_if_changelinkaddr", (char*) ipcom_if_changelinkaddr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_if_changemtu", (char*) ipcom_if_changemtu, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_if_changename", (char*) ipcom_if_changename, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_if_detach", (char*) ipcom_if_detach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_if_free", (char*) ipcom_if_free, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_if_freenameindex", (char*) ipcom_if_freenameindex, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_if_indextoname", (char*) ipcom_if_indextoname, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_if_malloc", (char*) ipcom_if_malloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_if_nameindex", (char*) ipcom_if_nameindex, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_if_nametoindex", (char*) ipcom_if_nametoindex, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_if_nametonetif", (char*) ipcom_if_nametonetif, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_ima_stack_task", (char*) ipcom_ima_stack_task, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_in_checksum", (char*) ipcom_in_checksum, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_in_checksum_finish", (char*) ipcom_in_checksum_finish, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_in_checksum_memcpy", (char*) ipcom_in_checksum_memcpy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_in_checksum_memcpy_asm", (char*) ipcom_in_checksum_memcpy_asm, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_in_checksum_pkt", (char*) ipcom_in_checksum_pkt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_in_checksum_update", (char*) ipcom_in_checksum_update, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_in_checksum_update2_asm", (char*) ipcom_in_checksum_update2_asm, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_in_checksum_update_pkt", (char*) ipcom_in_checksum_update_pkt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_inet_addr", (char*) ipcom_inet_addr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_inet_aton", (char*) ipcom_inet_aton, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_inet_ntoa", (char*) ipcom_inet_ntoa, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_inet_ntop", (char*) ipcom_inet_ntop, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_inet_pton", (char*) ipcom_inet_pton, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_init_config_vars", (char*) ipcom_init_config_vars, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_initd", (char*) ipcom_initd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_interrupt_disable", (char*) ipcom_interrupt_disable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_interrupt_enable", (char*) ipcom_interrupt_enable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_ipc_close", (char*) ipcom_ipc_close, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_ipc_free", (char*) ipcom_ipc_free, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_ipc_install", (char*) ipcom_ipc_install, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_ipc_isopen", (char*) ipcom_ipc_isopen, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_ipc_malloc", (char*) ipcom_ipc_malloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_ipc_open", (char*) ipcom_ipc_open, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_ipc_receive", (char*) ipcom_ipc_receive, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_ipc_send", (char*) ipcom_ipc_send, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_ipc_size", (char*) ipcom_ipc_size, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_ipc_uninstall", (char*) ipcom_ipc_uninstall, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_ipd_datamsg", (char*) ipcom_ipd_datamsg, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_ipd_exit", (char*) ipcom_ipd_exit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_ipd_init", (char*) ipcom_ipd_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_ipd_input", (char*) ipcom_ipd_input, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_ipd_input_process", (char*) ipcom_ipd_input_process, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_ipd_kill", (char*) ipcom_ipd_kill, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_ipd_products", (char*) &ipcom_ipd_products, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipcom_ipd_read", (char*) ipcom_ipd_read, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_ipd_reconfigure", (char*) ipcom_ipd_reconfigure, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_ipd_send", (char*) ipcom_ipd_send, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_ipd_sendmsg", (char*) ipcom_ipd_sendmsg, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_ipd_start", (char*) ipcom_ipd_start, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_ipproto_name", (char*) ipcom_ipproto_name, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_is_pid_valid", (char*) ipcom_is_pid_valid, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_is_stack_task", (char*) ipcom_is_stack_task, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_job_queue_init", (char*) ipcom_job_queue_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_job_queue_pipe_schedule", (char*) ipcom_job_queue_pipe_schedule, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_job_queue_schedule", (char*) ipcom_job_queue_schedule, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_job_queue_schedule_singleton", (char*) ipcom_job_queue_schedule_singleton, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_job_queue_schedule_singleton_delayed", (char*) ipcom_job_queue_schedule_singleton_delayed, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_job_queue_singleton_delete", (char*) ipcom_job_queue_singleton_delete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_job_queue_singleton_new", (char*) ipcom_job_queue_singleton_new, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_key_db_file_root", (char*) &ipcom_key_db_file_root, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipcom_list_first", (char*) ipcom_list_first, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_list_init", (char*) ipcom_list_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_list_insert_after", (char*) ipcom_list_insert_after, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_list_insert_before", (char*) ipcom_list_insert_before, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_list_insert_first", (char*) ipcom_list_insert_first, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_list_insert_last", (char*) ipcom_list_insert_last, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_list_last", (char*) ipcom_list_last, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_list_next", (char*) ipcom_list_next, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_list_prev", (char*) ipcom_list_prev, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_list_remove", (char*) ipcom_list_remove, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_list_unlink_head", (char*) ipcom_list_unlink_head, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_listen", (char*) ipcom_listen, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_listen_usr", (char*) ipcom_listen_usr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_lseek", (char*) ipcom_lseek, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_malloc", (char*) ipcom_malloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_mask_to_prefixlen", (char*) ipcom_mask_to_prefixlen, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_mb", (char*) ipcom_mb, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_mcmd_ifconfig", (char*) ipcom_mcmd_ifconfig, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_mcmd_route", (char*) ipcom_mcmd_route, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_memory_pool_new", (char*) ipcom_memory_pool_new, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_microtime", (char*) ipcom_microtime, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_millisleep", (char*) ipcom_millisleep, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_mipc_addr2offset", (char*) ipcom_mipc_addr2offset, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_mipc_offset2addr", (char*) ipcom_mipc_offset2addr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_mkdir", (char*) ipcom_mkdir, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_mutex_create", (char*) ipcom_mutex_create, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_mutex_delete", (char*) ipcom_mutex_delete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_mutex_lock", (char*) ipcom_mutex_lock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_mutex_unlock", (char*) ipcom_mutex_unlock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_null_pool_create", (char*) &ipcom_null_pool_create, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipcom_num_configured_cpus", (char*) ipcom_num_configured_cpus, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_num_online_cpus", (char*) ipcom_num_online_cpus, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_observer_notify", (char*) ipcom_observer_notify, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_once", (char*) ipcom_once, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_once_mutex", (char*) &ipcom_once_mutex, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "ipcom_opendir", (char*) ipcom_opendir, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_openlog", (char*) ipcom_openlog, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_parse_argstr", (char*) ipcom_parse_argstr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pipe_attr_init", (char*) ipcom_pipe_attr_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pipe_free", (char*) ipcom_pipe_free, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pipe_generic_create", (char*) ipcom_pipe_generic_create, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pipe_job_queue_create", (char*) ipcom_pipe_job_queue_create, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pipe_lockless_create", (char*) ipcom_pipe_lockless_create, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pipe_new", (char*) ipcom_pipe_new, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pipe_register_type", (char*) ipcom_pipe_register_type, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pipe_tv_zero", (char*) &ipcom_pipe_tv_zero, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipcom_pkt_alloc_info", (char*) ipcom_pkt_alloc_info, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pkt_copy_info", (char*) ipcom_pkt_copy_info, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pkt_create", (char*) ipcom_pkt_create, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pkt_create_info", (char*) ipcom_pkt_create_info, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pkt_free", (char*) ipcom_pkt_free, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pkt_get_info", (char*) ipcom_pkt_get_info, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pkt_get_info_and_size", (char*) ipcom_pkt_get_info_and_size, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pkt_get_info_safe", (char*) ipcom_pkt_get_info_safe, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pkt_hdrspace", (char*) ipcom_pkt_hdrspace, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pkt_input", (char*) ipcom_pkt_input, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pkt_input_queue", (char*) ipcom_pkt_input_queue, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pkt_make_linear", (char*) ipcom_pkt_make_linear, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pkt_malloc", (char*) ipcom_pkt_malloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pkt_output_done", (char*) ipcom_pkt_output_done, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pkt_set_info", (char*) ipcom_pkt_set_info, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pkt_sg_get_data", (char*) ipcom_pkt_sg_get_data, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pkt_trim_head", (char*) ipcom_pkt_trim_head, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pkt_trim_tail", (char*) ipcom_pkt_trim_tail, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pktbuf_free", (char*) ipcom_pktbuf_free, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_port", (char*) &ipcom_port, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipcom_port_pkt_hdr_extra_size", (char*) &ipcom_port_pkt_hdr_extra_size, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipcom_pqueue_delete", (char*) ipcom_pqueue_delete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pqueue_for_each", (char*) ipcom_pqueue_for_each, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pqueue_get", (char*) ipcom_pqueue_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pqueue_get_next", (char*) ipcom_pqueue_get_next, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pqueue_insert", (char*) ipcom_pqueue_insert, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pqueue_new", (char*) ipcom_pqueue_new, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pqueue_nop_store_index", (char*) ipcom_pqueue_nop_store_index, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pqueue_remove", (char*) ipcom_pqueue_remove, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pqueue_remove_next", (char*) ipcom_pqueue_remove_next, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_pqueue_size", (char*) ipcom_pqueue_size, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_preempt_disable", (char*) ipcom_preempt_disable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_preempt_enable", (char*) ipcom_preempt_enable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_priority_map", (char*) &ipcom_priority_map, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipcom_proc_acreate", (char*) ipcom_proc_acreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_proc_attr_init", (char*) ipcom_proc_attr_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_proc_cpu_affinity_clr", (char*) ipcom_proc_cpu_affinity_clr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_proc_cpu_affinity_get", (char*) ipcom_proc_cpu_affinity_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_proc_cpu_affinity_set", (char*) ipcom_proc_cpu_affinity_set, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_proc_cpu_affinity_set_all", (char*) ipcom_proc_cpu_affinity_set_all, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_proc_create", (char*) ipcom_proc_create, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_proc_exit", (char*) ipcom_proc_exit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_proc_find", (char*) ipcom_proc_find, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_proc_free", (char*) ipcom_proc_free, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_proc_getprio", (char*) ipcom_proc_getprio, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_proc_init", (char*) ipcom_proc_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_proc_malloc", (char*) ipcom_proc_malloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_proc_self", (char*) ipcom_proc_self, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_proc_setprio", (char*) ipcom_proc_setprio, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_proc_vr_get", (char*) ipcom_proc_vr_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_proc_vr_set", (char*) ipcom_proc_vr_set, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_proc_yield", (char*) ipcom_proc_yield, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_rand", (char*) ipcom_rand, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_random", (char*) ipcom_random, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_random_init", (char*) ipcom_random_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_random_seed_state", (char*) ipcom_random_seed_state, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_readdir", (char*) ipcom_readdir, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_realloc", (char*) ipcom_realloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_recv", (char*) ipcom_recv, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_recv_usr", (char*) ipcom_recv_usr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_recvfrom", (char*) ipcom_recvfrom, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_recvfrom_usr", (char*) ipcom_recvfrom_usr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_recvmsg", (char*) ipcom_recvmsg, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_recvmsg_usr", (char*) ipcom_recvmsg_usr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_register_dev_name_mapping", (char*) ipcom_register_dev_name_mapping, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_rename", (char*) ipcom_rename, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_rewind", (char*) ipcom_rewind, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_rmb", (char*) ipcom_rmb, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_rmdir", (char*) ipcom_rmdir, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_route_add", (char*) ipcom_route_add, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_route_first_entry", (char*) ipcom_route_first_entry, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_route_free_table", (char*) ipcom_route_free_table, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_route_init_subtree_mask", (char*) ipcom_route_init_subtree_mask, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_route_key_cmp", (char*) ipcom_route_key_cmp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_route_lookup", (char*) ipcom_route_lookup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_route_new_table", (char*) ipcom_route_new_table, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_route_next_entry", (char*) ipcom_route_next_entry, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_route_remove", (char*) ipcom_route_remove, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_route_walk_tree", (char*) ipcom_route_walk_tree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_route_walk_tree_backwards", (char*) ipcom_route_walk_tree_backwards, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_rtp_tcb_index_get_fd", (char*) ipcom_rtp_tcb_index_get_fd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_run_cmd", (char*) ipcom_run_cmd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_sem_create", (char*) ipcom_sem_create, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_sem_delete", (char*) ipcom_sem_delete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_sem_flush", (char*) ipcom_sem_flush, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_sem_getvalue", (char*) ipcom_sem_getvalue, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_sem_interrupt_flush", (char*) ipcom_sem_interrupt_flush, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_sem_interrupt_post", (char*) ipcom_sem_interrupt_post, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_sem_post", (char*) ipcom_sem_post, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_sem_wait", (char*) ipcom_sem_wait, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_send", (char*) ipcom_send, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_send_usr", (char*) ipcom_send_usr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_sendmsg", (char*) ipcom_sendmsg, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_sendmsg_usr", (char*) ipcom_sendmsg_usr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_sendto", (char*) ipcom_sendto, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_sendto_usr", (char*) ipcom_sendto_usr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_set_add", (char*) ipcom_set_add, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_set_clone", (char*) ipcom_set_clone, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_set_contains", (char*) ipcom_set_contains, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_set_delete", (char*) ipcom_set_delete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_set_equal", (char*) ipcom_set_equal, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_set_for_each", (char*) ipcom_set_for_each, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_set_intersection", (char*) ipcom_set_intersection, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_set_new", (char*) ipcom_set_new, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_set_remove", (char*) ipcom_set_remove, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_set_remove_all", (char*) ipcom_set_remove_all, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_set_start_shell_ptr", (char*) ipcom_set_start_shell_ptr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_set_subtract", (char*) ipcom_set_subtract, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_set_union", (char*) ipcom_set_union, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_setenv", (char*) ipcom_setenv, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_setenv_as_int", (char*) ipcom_setenv_as_int, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_setlogfile", (char*) ipcom_setlogfile, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_setlogmask_on", (char*) ipcom_setlogmask_on, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_setlogudp", (char*) ipcom_setlogudp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_setsockopt", (char*) ipcom_setsockopt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_setsockopt_usr", (char*) ipcom_setsockopt_usr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_settimeofday", (char*) ipcom_settimeofday, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_shell_add_cmd", (char*) ipcom_shell_add_cmd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_shell_cmd_head", (char*) &ipcom_shell_cmd_head, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "ipcom_shell_ctx_add", (char*) ipcom_shell_ctx_add, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_shell_ctx_add_int", (char*) ipcom_shell_ctx_add_int, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_shell_ctx_add_local_addr", (char*) ipcom_shell_ctx_add_local_addr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_shell_ctx_add_peer_addr", (char*) ipcom_shell_ctx_add_peer_addr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_shell_ctx_add_user", (char*) ipcom_shell_ctx_add_user, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_shell_ctx_free", (char*) ipcom_shell_ctx_free, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_shell_ctx_get", (char*) ipcom_shell_ctx_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_shell_ctx_get_clt_addr", (char*) ipcom_shell_ctx_get_clt_addr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_shell_ctx_get_int", (char*) ipcom_shell_ctx_get_int, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_shell_ctx_get_peer_addr", (char*) ipcom_shell_ctx_get_peer_addr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_shell_ctx_get_user", (char*) ipcom_shell_ctx_get_user, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_shell_ctx_new", (char*) ipcom_shell_ctx_new, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_shell_find_cmd", (char*) ipcom_shell_find_cmd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_shell_find_cmd_hook", (char*) &ipcom_shell_find_cmd_hook, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipcom_shell_fread", (char*) ipcom_shell_fread, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_shell_fwrite", (char*) ipcom_shell_fwrite, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_shell_remove_cmd", (char*) ipcom_shell_remove_cmd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_shutdown", (char*) ipcom_shutdown, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_shutdown_usr", (char*) ipcom_shutdown_usr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_slab_add", (char*) ipcom_slab_add, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_slab_alloc_from", (char*) ipcom_slab_alloc_from, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_slab_alloc_try", (char*) ipcom_slab_alloc_try, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_slab_free", (char*) ipcom_slab_free, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_slab_get_objects_per_slab", (char*) ipcom_slab_get_objects_per_slab, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_slab_memory_pool_list", (char*) &ipcom_slab_memory_pool_list, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "ipcom_slab_new", (char*) ipcom_slab_new, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_slab_once", (char*) &ipcom_slab_once, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipcom_sleep", (char*) ipcom_sleep, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_sockaddr_to_prefixlen", (char*) ipcom_sockaddr_to_prefixlen, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_socket", (char*) ipcom_socket, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_socket_usr", (char*) ipcom_socket_usr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_socketclose", (char*) ipcom_socketclose, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_socketclose_usr", (char*) ipcom_socketclose_usr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_socketioctl", (char*) ipcom_socketioctl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_socketioctl_usr", (char*) ipcom_socketioctl_usr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_socketread", (char*) ipcom_socketread, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_socketread_usr", (char*) ipcom_socketread_usr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_socketselect", (char*) ipcom_socketselect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_socketselect_usr", (char*) ipcom_socketselect_usr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_socketwrite", (char*) ipcom_socketwrite, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_socketwrite_usr", (char*) ipcom_socketwrite_usr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_socketwritev", (char*) ipcom_socketwritev, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_socketwritev_usr", (char*) ipcom_socketwritev_usr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_spinlock_create", (char*) ipcom_spinlock_create, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_spinlock_delete", (char*) ipcom_spinlock_delete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_spinlock_lock", (char*) ipcom_spinlock_lock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_spinlock_unlock", (char*) ipcom_spinlock_unlock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_srand", (char*) ipcom_srand, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_srandom", (char*) ipcom_srandom, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_stackd_init", (char*) ipcom_stackd_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_start", (char*) ipcom_start, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_start_shell", (char*) ipcom_start_shell, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_start_shell_native", (char*) ipcom_start_shell_native, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_start_shell_ptr", (char*) &ipcom_start_shell_ptr, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipcom_stat", (char*) ipcom_stat, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_stderr", (char*) ipcom_stderr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_stdin", (char*) ipcom_stdin, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_stdio_set_echo", (char*) ipcom_stdio_set_echo, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_stdout", (char*) ipcom_stdout, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_str_in_list", (char*) ipcom_str_in_list, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_strcasecmp", (char*) ipcom_strcasecmp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_strerror", (char*) ipcom_strerror, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_strerror_r", (char*) ipcom_strerror_r, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_strncasecmp", (char*) ipcom_strncasecmp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_sys_free", (char*) &ipcom_sys_free, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipcom_sys_malloc", (char*) &ipcom_sys_malloc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipcom_sysctl", (char*) ipcom_sysctl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_syslog", (char*) ipcom_syslog, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_syslog_facility_names", (char*) &ipcom_syslog_facility_names, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipcom_syslog_printf", (char*) ipcom_syslog_printf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_syslog_priority_names", (char*) &ipcom_syslog_priority_names, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipcom_syslogd_init", (char*) ipcom_syslogd_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_sysvar_add_observer", (char*) ipcom_sysvar_add_observer, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_sysvar_ext_setv", (char*) ipcom_sysvar_ext_setv, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_sysvar_for_each", (char*) ipcom_sysvar_for_each, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_sysvar_get", (char*) ipcom_sysvar_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_sysvar_get0", (char*) ipcom_sysvar_get0, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_sysvar_get_as_int", (char*) ipcom_sysvar_get_as_int, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_sysvar_get_as_int0", (char*) ipcom_sysvar_get_as_int0, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_sysvar_get_as_int_vr", (char*) ipcom_sysvar_get_as_int_vr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_sysvar_get_descriptive_int0", (char*) ipcom_sysvar_get_descriptive_int0, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_sysvar_get_descriptive_int_vr", (char*) ipcom_sysvar_get_descriptive_int_vr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_sysvar_getvr", (char*) ipcom_sysvar_getvr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_sysvar_remove_observer", (char*) ipcom_sysvar_remove_observer, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_sysvar_set", (char*) ipcom_sysvar_set, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_sysvar_set0", (char*) ipcom_sysvar_set0, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_sysvar_set_tree", (char*) ipcom_sysvar_set_tree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_sysvar_setv", (char*) ipcom_sysvar_setv, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_sysvar_setvr", (char*) ipcom_sysvar_setvr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_sysvar_unset", (char*) ipcom_sysvar_unset, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_telnetd", (char*) ipcom_telnetd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_telnetspawn", (char*) ipcom_telnetspawn, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_tmo2_cancel", (char*) ipcom_tmo2_cancel, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_tmo2_delete", (char*) ipcom_tmo2_delete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_tmo2_get", (char*) ipcom_tmo2_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_tmo2_new", (char*) ipcom_tmo2_new, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_tmo2_request", (char*) ipcom_tmo2_request, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_tmo2_request_timeval", (char*) ipcom_tmo2_request_timeval, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_tmo2_reset", (char*) ipcom_tmo2_reset, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_tmo2_select", (char*) ipcom_tmo2_select, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_tmo_cancel", (char*) ipcom_tmo_cancel, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_tmo_get", (char*) ipcom_tmo_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_tmo_request", (char*) ipcom_tmo_request, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_tmo_reset", (char*) ipcom_tmo_reset, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_unlink", (char*) ipcom_unlink, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_unsetenv", (char*) ipcom_unsetenv, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_usr_create", (char*) ipcom_usr_create, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_version", (char*) &ipcom_version, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipcom_vsyslog", (char*) ipcom_vsyslog, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_vxshell_add_cmd", (char*) ipcom_vxshell_add_cmd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_vxshell_add_cmd_hook", (char*) &ipcom_vxshell_add_cmd_hook, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipcom_vxworks_boot_devname", (char*) ipcom_vxworks_boot_devname, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_vxworks_loginStringGet", (char*) ipcom_vxworks_loginStringGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_vxworks_pkt_pool_hdr_ctor", (char*) ipcom_vxworks_pkt_pool_hdr_ctor, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_vxworks_proc_free", (char*) ipcom_vxworks_proc_free, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_vxworks_rtp_del_hook_add", (char*) ipcom_vxworks_rtp_del_hook_add, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_vxworks_task_del_hook", (char*) ipcom_vxworks_task_del_hook, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_windnet_socketwritev", (char*) ipcom_windnet_socketwritev, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_windnet_socklib_init", (char*) ipcom_windnet_socklib_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_windnet_socklib_sock_size", (char*) ipcom_windnet_socklib_sock_size, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_windnet_socklib_socket_free", (char*) ipcom_windnet_socklib_socket_free, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_windnet_socklib_socket_init", (char*) ipcom_windnet_socklib_socket_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_wmb", (char*) ipcom_wmb, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_wv_event_2", (char*) ipcom_wv_event_2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_wv_marker_1", (char*) ipcom_wv_marker_1, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipcom_wv_marker_2", (char*) ipcom_wv_marker_2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipmcp_is_enabled", (char*) &ipmcp_is_enabled, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipmcrypto_MD5_Final", (char*) ipmcrypto_MD5_Final, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipmcrypto_MD5_Init", (char*) ipmcrypto_MD5_Init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipmcrypto_MD5_Update", (char*) ipmcrypto_MD5_Update, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipmcrypto_SHA1_Final", (char*) ipmcrypto_SHA1_Final, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipmcrypto_SHA1_Init", (char*) ipmcrypto_SHA1_Init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipmcrypto_SHA1_Update", (char*) ipmcrypto_SHA1_Update, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipmcrypto_md5_calculate", (char*) ipmcrypto_md5_calculate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet", (char*) &ipnet, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipnet_arp_ioctl", (char*) ipnet_arp_ioctl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_arp_request", (char*) ipnet_arp_request, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_bit_array_clr", (char*) ipnet_bit_array_clr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_bit_array_test_and_set", (char*) ipnet_bit_array_test_and_set, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_bool_map", (char*) &ipnet_bool_map, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipnet_cmd_if_type_to_str", (char*) ipnet_cmd_if_type_to_str, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_cmd_ifconfig_common", (char*) ipnet_cmd_ifconfig_common, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_cmd_ifconfig_hook", (char*) &ipnet_cmd_ifconfig_hook, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipnet_cmd_init_addrs", (char*) ipnet_cmd_init_addrs, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_cmd_msec_since", (char*) ipnet_cmd_msec_since, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_cmd_neigh_for_each", (char*) ipnet_cmd_neigh_for_each, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_cmd_neigh_for_each_optmask", (char*) ipnet_cmd_neigh_for_each_optmask, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_cmd_ping", (char*) ipnet_cmd_ping, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_cmd_ping_stoppable", (char*) ipnet_cmd_ping_stoppable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_cmd_qc_hook", (char*) &ipnet_cmd_qc_hook, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipnet_cmd_route_hook", (char*) &ipnet_cmd_route_hook, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipnet_cmd_rt_flags_to_str", (char*) ipnet_cmd_rt_flags_to_str, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_cmd_rt_flags_to_str_short", (char*) ipnet_cmd_rt_flags_to_str_short, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_conf_boot_cmd", (char*) &ipnet_conf_boot_cmd, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipnet_conf_cache_bufsiz", (char*) &ipnet_conf_cache_bufsiz, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipnet_conf_inq_max", (char*) &ipnet_conf_inq_max, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipnet_conf_interfaces", (char*) &ipnet_conf_interfaces, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipnet_conf_ip4_min_mtu", (char*) &ipnet_conf_ip4_min_mtu, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipnet_conf_ip6_min_mtu", (char*) &ipnet_conf_ip6_min_mtu, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipnet_conf_link_layer", (char*) &ipnet_conf_link_layer, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipnet_conf_max_dgram_frag_list_len", (char*) &ipnet_conf_max_dgram_frag_list_len, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipnet_conf_max_reassembly_list_len", (char*) &ipnet_conf_max_reassembly_list_len, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipnet_conf_max_sockets", (char*) &ipnet_conf_max_sockets, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipnet_conf_memory_limit", (char*) &ipnet_conf_memory_limit, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipnet_conf_reassembly_timeout", (char*) &ipnet_conf_reassembly_timeout, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipnet_conf_update", (char*) ipnet_conf_update, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_configd_start", (char*) ipnet_configd_start, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_configure", (char*) ipnet_configure, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_create", (char*) ipnet_create, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_create_reassembled_packet", (char*) ipnet_create_reassembled_packet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ctrl", (char*) ipnet_ctrl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ctrl_sig", (char*) ipnet_ctrl_sig, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_do_close", (char*) ipnet_do_close, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_dst_cache", (char*) &ipnet_dst_cache, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "ipnet_dst_cache_blackhole", (char*) ipnet_dst_cache_blackhole, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_dst_cache_blackhole_flow_spec", (char*) ipnet_dst_cache_blackhole_flow_spec, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_dst_cache_flush", (char*) ipnet_dst_cache_flush, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_dst_cache_flush_where_neigh_is", (char*) ipnet_dst_cache_flush_where_neigh_is, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_dst_cache_foreach", (char*) ipnet_dst_cache_foreach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_dst_cache_init", (char*) ipnet_dst_cache_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_dst_cache_new", (char*) ipnet_dst_cache_new, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_dst_cache_number_limit", (char*) &ipnet_dst_cache_number_limit, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipnet_dst_cache_select_best_rt", (char*) ipnet_dst_cache_select_best_rt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_dst_cache_set_path_mtu", (char*) ipnet_dst_cache_set_path_mtu, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_dst_cache_set_rx_handler", (char*) ipnet_dst_cache_set_rx_handler, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_dst_cache_set_tx_handler", (char*) ipnet_dst_cache_set_tx_handler, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_eth_add_hdr", (char*) ipnet_eth_add_hdr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_eth_addr_broadcast", (char*) &ipnet_eth_addr_broadcast, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipnet_eth_addr_broadcast_storage", (char*) &ipnet_eth_addr_broadcast_storage, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipnet_eth_if_init", (char*) ipnet_eth_if_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_eth_update_mib2_lastchange", (char*) ipnet_eth_update_mib2_lastchange, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_flags", (char*) &ipnet_flags, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipnet_flow_spec_domain", (char*) ipnet_flow_spec_domain, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_flow_spec_from_info", (char*) ipnet_flow_spec_from_info, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_flow_spec_from_sock", (char*) ipnet_flow_spec_from_sock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_frag_release_peer_info", (char*) ipnet_frag_release_peer_info, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_frag_set_peer_info", (char*) ipnet_frag_set_peer_info, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_frag_to_peer_info", (char*) ipnet_frag_to_peer_info, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_fragment_packet", (char*) ipnet_fragment_packet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_get_sock", (char*) ipnet_get_sock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_has_priv", (char*) ipnet_has_priv, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_icmp4_param_init", (char*) ipnet_icmp4_param_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_icmp4_send", (char*) ipnet_icmp4_send, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_icmp4_send_host_unreachable", (char*) ipnet_icmp4_send_host_unreachable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_icmp4_send_port_unreachable", (char*) ipnet_icmp4_send_port_unreachable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_if_can_detach", (char*) ipnet_if_can_detach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_if_clean", (char*) ipnet_if_clean, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_if_clean_ppp_peer", (char*) ipnet_if_clean_ppp_peer, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_if_clean_snd_queue", (char*) ipnet_if_clean_snd_queue, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_if_detach", (char*) ipnet_if_detach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_if_drv_ioctl", (char*) ipnet_if_drv_ioctl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_if_drv_output", (char*) ipnet_if_drv_output, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_if_free", (char*) ipnet_if_free, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_if_get_index_array", (char*) ipnet_if_get_index_array, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_if_indextonetif", (char*) ipnet_if_indextonetif, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_if_init", (char*) ipnet_if_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_if_init_ppp_peer", (char*) ipnet_if_init_ppp_peer, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_if_link_ioctl", (char*) ipnet_if_link_ioctl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_if_nametonetif", (char*) ipnet_if_nametonetif, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_if_output", (char*) ipnet_if_output, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_if_set_ipv4_ppp_peer", (char*) ipnet_if_set_ipv4_ppp_peer, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_if_to_sockaddr_dl", (char*) ipnet_if_to_sockaddr_dl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_if_update_mib2_ifLastChange", (char*) ipnet_if_update_mib2_ifLastChange, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ifconfig_if_change_state", (char*) ipnet_ifconfig_if_change_state, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_igmpv3_report_change", (char*) ipnet_igmpv3_report_change, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_increase_hdr_space", (char*) ipnet_increase_hdr_space, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ioctl_move_if_rt_to_vr", (char*) ipnet_ioctl_move_if_rt_to_vr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_acd_conflict", (char*) ipnet_ip4_acd_conflict, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_add_addr", (char*) ipnet_ip4_add_addr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_add_addr2", (char*) ipnet_ip4_add_addr2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_add_route_table", (char*) ipnet_ip4_add_route_table, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_addr_to_sockaddr", (char*) ipnet_ip4_addr_to_sockaddr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_change_addr_mask", (char*) ipnet_ip4_change_addr_mask, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_configure_route_table", (char*) ipnet_ip4_configure_route_table, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_dst_cache_get", (char*) ipnet_ip4_dst_cache_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_dst_cache_rx_ctor", (char*) ipnet_ip4_dst_cache_rx_ctor, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_dst_unreachable", (char*) ipnet_ip4_dst_unreachable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_dst_unreachable_filter", (char*) ipnet_ip4_dst_unreachable_filter, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_flow_spec_from_info", (char*) ipnet_ip4_flow_spec_from_info, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_flow_spec_from_pkt", (char*) ipnet_ip4_flow_spec_from_pkt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_fragment_timeout_peer", (char*) ipnet_ip4_fragment_timeout_peer, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_get_addr_entry", (char*) ipnet_ip4_get_addr_entry, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_get_addr_type", (char*) ipnet_ip4_get_addr_type, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_get_addr_type2", (char*) ipnet_ip4_get_addr_type2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_get_mss", (char*) ipnet_ip4_get_mss, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_get_src_addr", (char*) ipnet_ip4_get_src_addr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_init", (char*) ipnet_ip4_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_input", (char*) ipnet_ip4_input, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_insert_addr_cache", (char*) ipnet_ip4_insert_addr_cache, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_is_part_of_same_pkt", (char*) ipnet_ip4_is_part_of_same_pkt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_kioevent", (char*) ipnet_ip4_kioevent, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_netif_get_subbrd", (char*) ipnet_ip4_netif_get_subbrd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_pkt_with_iphdr_rawsock_tx", (char*) ipnet_ip4_pkt_with_iphdr_rawsock_tx, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_pkt_with_iphdr_tx", (char*) ipnet_ip4_pkt_with_iphdr_tx, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_reg_transport_layer", (char*) ipnet_ip4_reg_transport_layer, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_remove_addr", (char*) ipnet_ip4_remove_addr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_remove_addr_cache", (char*) ipnet_ip4_remove_addr_cache, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_rfc1256_mode_update", (char*) ipnet_ip4_rfc1256_mode_update, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_rx", (char*) ipnet_ip4_rx, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_sendto", (char*) ipnet_ip4_sendto, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_transport_rx", (char*) ipnet_ip4_transport_rx, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ip4_tx", (char*) ipnet_ip4_tx, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_is_loopback", (char*) ipnet_is_loopback, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_is_sock_exceptional", (char*) ipnet_is_sock_exceptional, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_is_sock_readable", (char*) ipnet_is_sock_readable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_is_sock_writable", (char*) ipnet_is_sock_writable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_is_stack_task", (char*) ipnet_is_stack_task, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_kioevent", (char*) ipnet_kioevent, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_loop_pkt_tx", (char*) ipnet_loop_pkt_tx, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_loopback_attach", (char*) ipnet_loopback_attach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_loopback_get_netif", (char*) ipnet_loopback_get_netif, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_loopback_if_init", (char*) ipnet_loopback_if_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_mcast_build_if_filter", (char*) ipnet_mcast_build_if_filter, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_mcast_build_source_change_report", (char*) ipnet_mcast_build_source_change_report, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_mcast_clear", (char*) ipnet_mcast_clear, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_mcast_free", (char*) ipnet_mcast_free, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_mcast_init", (char*) ipnet_mcast_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_mcast_report_finish", (char*) ipnet_mcast_report_finish, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_mcast_schedule_membership_report", (char*) ipnet_mcast_schedule_membership_report, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_mcast_time_to_msec", (char*) ipnet_mcast_time_to_msec, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_msec_now", (char*) ipnet_msec_now, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_neigh_dad", (char*) ipnet_neigh_dad, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_neigh_flush", (char*) ipnet_neigh_flush, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_neigh_flush_all", (char*) ipnet_neigh_flush_all, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_neigh_foreach", (char*) ipnet_neigh_foreach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_neigh_get", (char*) ipnet_neigh_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_neigh_init", (char*) ipnet_neigh_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_neigh_init_addr_observer", (char*) ipnet_neigh_init_addr_observer, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_neigh_invalidate", (char*) ipnet_neigh_invalidate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_neigh_is_probing", (char*) ipnet_neigh_is_probing, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_neigh_netif_discard", (char*) ipnet_neigh_netif_discard, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_neigh_probe", (char*) ipnet_neigh_probe, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_neigh_release", (char*) ipnet_neigh_release, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_neigh_set_blackhole", (char*) ipnet_neigh_set_blackhole, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_neigh_set_external", (char*) ipnet_neigh_set_external, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_neigh_set_gateway", (char*) ipnet_neigh_set_gateway, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_neigh_set_lifetime", (char*) ipnet_neigh_set_lifetime, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_neigh_set_lladdr", (char*) ipnet_neigh_set_lladdr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_neigh_set_local", (char*) ipnet_neigh_set_local, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_neigh_set_perm", (char*) ipnet_neigh_set_perm, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_neigh_set_publ", (char*) ipnet_neigh_set_publ, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_neigh_set_report", (char*) ipnet_neigh_set_report, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_neigh_set_silent", (char*) ipnet_neigh_set_silent, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_neigh_set_state", (char*) ipnet_neigh_set_state, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_netif_change_flags", (char*) ipnet_netif_change_flags, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_netif_is_ifproxy", (char*) ipnet_netif_is_ifproxy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_netif_neigh_create", (char*) ipnet_netif_neigh_create, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_next_ephemeral_port", (char*) ipnet_next_ephemeral_port, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_noeth_if_init", (char*) ipnet_noeth_if_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_packet_getsockopt", (char*) ipnet_packet_getsockopt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_packet_input", (char*) ipnet_packet_input, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_packet_setsockopt", (char*) ipnet_packet_setsockopt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_pcap_ioctl", (char*) ipnet_pcap_ioctl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_peer_info_addref", (char*) ipnet_peer_info_addref, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_peer_info_get", (char*) ipnet_peer_info_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_peer_info_init", (char*) ipnet_peer_info_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_peer_info_release", (char*) ipnet_peer_info_release, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_peer_info_timeout_cancel", (char*) ipnet_peer_info_timeout_cancel, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_peer_info_timeout_schedule", (char*) ipnet_peer_info_timeout_schedule, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ping_stat_init", (char*) ipnet_ping_stat_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ping_stat_receive", (char*) ipnet_ping_stat_receive, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ping_stat_report", (char*) ipnet_ping_stat_report, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ping_stat_transmit", (char*) ipnet_ping_stat_transmit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_pipe_create", (char*) ipnet_pipe_create, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_pkt_clone", (char*) ipnet_pkt_clone, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_pkt_get_maxlen", (char*) ipnet_pkt_get_maxlen, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_pkt_input", (char*) ipnet_pkt_input, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_pkt_pool_drain", (char*) ipnet_pkt_pool_drain, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_pkt_pool_hdr_count_hint", (char*) ipnet_pkt_pool_hdr_count_hint, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_pkt_pool_hdr_ctor_func", (char*) &ipnet_pkt_pool_hdr_ctor_func, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipnet_pkt_pool_init", (char*) ipnet_pkt_pool_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_pkt_pool_slab_desc", (char*) &ipnet_pkt_pool_slab_desc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipnet_pkt_queue_delete", (char*) ipnet_pkt_queue_delete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_pkt_queue_fifo_template", (char*) ipnet_pkt_queue_fifo_template, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_pkt_queue_init", (char*) ipnet_pkt_queue_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_pkt_queue_new", (char*) ipnet_pkt_queue_new, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_pmtu_foreach", (char*) ipnet_pmtu_foreach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_pmtu_get", (char*) ipnet_pmtu_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_pmtu_init", (char*) ipnet_pmtu_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_pmtu_limit", (char*) &ipnet_pmtu_limit, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipnet_pmtu_live_time", (char*) &ipnet_pmtu_live_time, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipnet_pmtu_proc", (char*) ipnet_pmtu_proc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_ppp_if_init", (char*) ipnet_ppp_if_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_queue_received_packet", (char*) ipnet_queue_received_packet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_raw_input", (char*) ipnet_raw_input, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_reassembly", (char*) ipnet_reassembly, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_register_if_attach_handler", (char*) ipnet_register_if_attach_handler, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_release_sock", (char*) ipnet_release_sock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_resume_stack", (char*) ipnet_resume_stack, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_add", (char*) ipnet_route_add, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_add_table", (char*) ipnet_route_add_table, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_apply_mask", (char*) ipnet_route_apply_mask, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_cache_invalidate", (char*) ipnet_route_cache_invalidate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_create_mask", (char*) ipnet_route_create_mask, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_delete", (char*) ipnet_route_delete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_delete2", (char*) ipnet_route_delete2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_delete_name", (char*) ipnet_route_delete_name, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_delete_table", (char*) ipnet_route_delete_table, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_delete_vr", (char*) ipnet_route_delete_vr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_first_entry", (char*) ipnet_route_first_entry, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_for_each_data_init", (char*) ipnet_route_for_each_data_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_get_name", (char*) ipnet_route_get_name, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_get_rtab", (char*) ipnet_route_get_rtab, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_get_table_ids", (char*) ipnet_route_get_table_ids, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_has_changed", (char*) ipnet_route_has_changed, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_has_expired", (char*) ipnet_route_has_expired, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_ip4_is_mcast_or_bcast", (char*) ipnet_route_ip4_is_mcast_or_bcast, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_is_virtual_router_valid", (char*) ipnet_route_is_virtual_router_valid, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_key_cmp", (char*) ipnet_route_key_cmp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_key_to_sockaddr", (char*) ipnet_route_key_to_sockaddr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_lock", (char*) ipnet_route_lock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_lookup", (char*) ipnet_route_lookup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_lookup_ecmp", (char*) ipnet_route_lookup_ecmp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_next_entry", (char*) ipnet_route_next_entry, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_notify_func", (char*) ipnet_route_notify_func, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_policy_get_rule_chain", (char*) ipnet_route_policy_get_rule_chain, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_policy_ioctl", (char*) ipnet_route_policy_ioctl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_raw_lookup", (char*) ipnet_route_raw_lookup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_raw_lookup2", (char*) ipnet_route_raw_lookup2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_remove_all", (char*) ipnet_route_remove_all, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_remove_all_cb_for_each_entry", (char*) ipnet_route_remove_all_cb_for_each_entry, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_remove_dynamic_rt_with_gw", (char*) ipnet_route_remove_dynamic_rt_with_gw, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_rotate_gateways", (char*) ipnet_route_rotate_gateways, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_set_lifetime", (char*) ipnet_route_set_lifetime, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_set_name", (char*) ipnet_route_set_name, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_set_rtab", (char*) ipnet_route_set_rtab, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_sockaddr_to_key", (char*) ipnet_route_sockaddr_to_key, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_unlock", (char*) ipnet_route_unlock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_vr_and_table_from_name", (char*) ipnet_route_vr_and_table_from_name, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_route_walk_tree", (char*) ipnet_route_walk_tree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_routesock_addr_add", (char*) ipnet_routesock_addr_add, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_routesock_addr_conflict", (char*) ipnet_routesock_addr_conflict, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_routesock_addr_delete", (char*) ipnet_routesock_addr_delete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_routesock_if_announce", (char*) ipnet_routesock_if_announce, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_routesock_if_change", (char*) ipnet_routesock_if_change, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_routesock_neigh_resolve", (char*) ipnet_routesock_neigh_resolve, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_routesock_rt_add", (char*) ipnet_routesock_rt_add, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_routesock_rt_change", (char*) ipnet_routesock_rt_change, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_routesock_rt_delete", (char*) ipnet_routesock_rt_delete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_routesock_rt_miss", (char*) ipnet_routesock_rt_miss, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_routesock_rt_redirect", (char*) ipnet_routesock_rt_redirect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sec_now", (char*) ipnet_sec_now, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sig_free", (char*) ipnet_sig_free, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_alloc_private_data", (char*) ipnet_sock_alloc_private_data, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_bind", (char*) ipnet_sock_bind, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_bind_addr_removed", (char*) ipnet_sock_bind_addr_removed, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_bind_to_port", (char*) ipnet_sock_bind_to_port, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_change_addr_entry", (char*) ipnet_sock_change_addr_entry, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_data_avail", (char*) ipnet_sock_data_avail, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_drop_all_multicast_memberships", (char*) ipnet_sock_drop_all_multicast_memberships, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_free", (char*) ipnet_sock_free, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_get", (char*) ipnet_sock_get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_get_bound_port_size", (char*) ipnet_sock_get_bound_port_size, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_get_ops_handle", (char*) ipnet_sock_get_ops_handle, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_get_route", (char*) ipnet_sock_get_route, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_has_waiting_writers", (char*) ipnet_sock_has_waiting_writers, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_init", (char*) ipnet_sock_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_ip4_get_mcast_data", (char*) ipnet_sock_ip4_get_mcast_data, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_ip4_get_ops", (char*) ipnet_sock_ip4_get_ops, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_ip4_lookup", (char*) ipnet_sock_ip4_lookup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_ip4_mcast_delete_data", (char*) ipnet_sock_ip4_mcast_delete_data, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_ip4_register", (char*) ipnet_sock_ip4_register, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_join_router_alert_chain", (char*) ipnet_sock_join_router_alert_chain, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_leave_router_alert_chain", (char*) ipnet_sock_leave_router_alert_chain, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_next", (char*) ipnet_sock_next, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_ops", (char*) &ipnet_sock_ops, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ipnet_sock_packet_lookup", (char*) ipnet_sock_packet_lookup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_packet_register", (char*) ipnet_sock_packet_register, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_pkt_drain", (char*) ipnet_sock_pkt_drain, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_register_ops", (char*) ipnet_sock_register_ops, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_route_register", (char*) ipnet_sock_route_register, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_router_alert_pkt", (char*) ipnet_sock_router_alert_pkt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_set_reachable", (char*) ipnet_sock_set_reachable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_set_unreachable", (char*) ipnet_sock_set_unreachable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_tcp_register", (char*) ipnet_sock_tcp_register, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_tcp_zombie_send_pkt_free", (char*) ipnet_sock_tcp_zombie_send_pkt_free, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_udp_register", (char*) ipnet_sock_udp_register, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_unbind", (char*) ipnet_sock_unbind, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_unconnect", (char*) ipnet_sock_unconnect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sock_update_reuse", (char*) ipnet_sock_update_reuse, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sockopt_ip4_addr_to_netif", (char*) ipnet_sockopt_ip4_addr_to_netif, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_softirq_init", (char*) ipnet_softirq_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_softirq_schedule", (char*) ipnet_softirq_schedule, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_start", (char*) ipnet_start, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_stats_tcp_established", (char*) ipnet_stats_tcp_established, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_suspend_stack", (char*) ipnet_suspend_stack, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sys_accept", (char*) ipnet_sys_accept, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sys_bind", (char*) ipnet_sys_bind, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sys_checktcp", (char*) ipnet_sys_checktcp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sys_connect", (char*) ipnet_sys_connect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sys_get_ancillary_data", (char*) ipnet_sys_get_ancillary_data, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sys_getname", (char*) ipnet_sys_getname, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sys_getsockopt", (char*) ipnet_sys_getsockopt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sys_if_attach", (char*) ipnet_sys_if_attach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sys_if_changelinkaddr", (char*) ipnet_sys_if_changelinkaddr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sys_if_changemtu", (char*) ipnet_sys_if_changemtu, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sys_if_changename", (char*) ipnet_sys_if_changename, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sys_if_detach", (char*) ipnet_sys_if_detach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sys_if_free", (char*) ipnet_sys_if_free, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sys_if_indexname", (char*) ipnet_sys_if_indexname, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sys_if_malloc", (char*) ipnet_sys_if_malloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sys_if_nametonetif", (char*) ipnet_sys_if_nametonetif, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sys_listen", (char*) ipnet_sys_listen, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sys_poll", (char*) ipnet_sys_poll, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sys_poll_async", (char*) ipnet_sys_poll_async, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sys_savesignal", (char*) ipnet_sys_savesignal, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sys_sendmsg", (char*) ipnet_sys_sendmsg, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sys_setsockopt", (char*) ipnet_sys_setsockopt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sys_shutdown", (char*) ipnet_sys_shutdown, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sys_socket", (char*) ipnet_sys_socket, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sys_socketclose", (char*) ipnet_sys_socketclose, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sys_socketioctl", (char*) ipnet_sys_socketioctl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sys_sysctl", (char*) ipnet_sys_sysctl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sysctl_create_ifinfo", (char*) ipnet_sysctl_create_ifinfo, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sysctl_if_add_addrs_one", (char*) ipnet_sysctl_if_add_addrs_one, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sysvar_get_as_int_vr", (char*) ipnet_sysvar_get_as_int_vr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sysvar_netif_get_as_int", (char*) ipnet_sysvar_netif_get_as_int, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_sysvar_netif_get_as_int_ex", (char*) ipnet_sysvar_netif_get_as_int_ex, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_timeout_cancel", (char*) ipnet_timeout_cancel, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_timeout_msec_until", (char*) ipnet_timeout_msec_until, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_timeout_schedule", (char*) ipnet_timeout_schedule, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_timeval_to_msec", (char*) ipnet_timeval_to_msec, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_try_free_mem", (char*) ipnet_try_free_mem, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_usr_sock_get_ops", (char*) ipnet_usr_sock_get_ops, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_usr_sock_get_pipe", (char*) ipnet_usr_sock_get_pipe, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_usr_sock_get_response_pipe", (char*) ipnet_usr_sock_get_response_pipe, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_usr_sock_get_route_cache_id", (char*) ipnet_usr_sock_get_route_cache_id, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_usr_sock_init", (char*) ipnet_usr_sock_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_usr_sock_init_sig", (char*) ipnet_usr_sock_init_sig, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_usr_sock_recvmsg", (char*) ipnet_usr_sock_recvmsg, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_usr_sock_wait_until_writable", (char*) ipnet_usr_sock_wait_until_writable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipnet_version", (char*) ipnet_version, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ipstack_ifconfig_print_info", (char*) ipstack_ifconfig_print_info, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iptcp", (char*) &iptcp, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "iptcp_accept", (char*) iptcp_accept, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iptcp_ao_rtnetlink_init", (char*) iptcp_ao_rtnetlink_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iptcp_change_state_global", (char*) iptcp_change_state_global, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iptcp_close", (char*) iptcp_close, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iptcp_conf_default_backlog", (char*) &iptcp_conf_default_backlog, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "iptcp_configure", (char*) iptcp_configure, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iptcp_connect", (char*) iptcp_connect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iptcp_create", (char*) iptcp_create, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iptcp_drop_connection", (char*) iptcp_drop_connection, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iptcp_get_rto", (char*) iptcp_get_rto, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iptcp_get_state", (char*) iptcp_get_state, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iptcp_getsockopt", (char*) iptcp_getsockopt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iptcp_icmp4_report", (char*) iptcp_icmp4_report, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iptcp_ioctl", (char*) iptcp_ioctl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iptcp_listen", (char*) iptcp_listen, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iptcp_pkt_drain", (char*) iptcp_pkt_drain, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iptcp_send", (char*) iptcp_send, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iptcp_send_reset", (char*) iptcp_send_reset, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iptcp_setsockopt", (char*) iptcp_setsockopt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iptcp_shutdown", (char*) iptcp_shutdown, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iptcp_sock_free", (char*) iptcp_sock_free, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iptcp_sock_init", (char*) iptcp_sock_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iptcp_start", (char*) iptcp_start, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iptcp_tx_list", (char*) &iptcp_tx_list, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "iptcp_usr_recv", (char*) iptcp_usr_recv, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iptcp_version", (char*) iptcp_version, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iptcp_window_update", (char*) iptcp_window_update, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iptelnets_configure", (char*) iptelnets_configure, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iptelnets_start", (char*) iptelnets_start, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iptelnets_version", (char*) iptelnets_version, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "isalnum", (char*) isalnum, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "isalpha", (char*) isalpha, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "isatty", (char*) isatty, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "iscntrl", (char*) iscntrl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "isdigit", (char*) isdigit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "isgraph", (char*) isgraph, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "islower", (char*) islower, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "isprint", (char*) isprint, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ispunct", (char*) ispunct, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "isrDeferJobAdd", (char*) isrDeferJobAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "isrDeferLibInit", (char*) isrDeferLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "isrDeferQueueGet", (char*) isrDeferQueueGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "isrIdCurrent", (char*) &isrIdCurrent, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "isrJobPool", (char*) &isrJobPool, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "isrRerouteNotify", (char*) isrRerouteNotify, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "isr_dispatcher", (char*) isr_dispatcher, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "isspace", (char*) isspace, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "isupper", (char*) isupper, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "isxdigit", (char*) isxdigit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "jobAdd", (char*) jobAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "jobQueueCreate", (char*) jobQueueCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "jobQueueInit", (char*) jobQueueInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "jobQueueLibInit", (char*) jobQueueLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "jobQueuePost", (char*) jobQueuePost, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "jobQueuePriorityMask", (char*) jobQueuePriorityMask, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "jobQueueProcess", (char*) jobQueueProcess, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "jobQueueProcessFunc", (char*) &jobQueueProcessFunc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "jobQueueStdJobsAlloc", (char*) jobQueueStdJobsAlloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "jobQueueStdPoolInit", (char*) jobQueueStdPoolInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "jobQueueStdPost", (char*) jobQueueStdPost, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "jobQueueTask", (char*) jobQueueTask, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "jobTaskLibInit", (char*) jobTaskLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "jobTaskWorkAdd", (char*) jobTaskWorkAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "kernelBaseInit", (char*) kernelBaseInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "kernelCpuEnable", (char*) kernelCpuEnable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "kernelId", (char*) &kernelId, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "kernelIdGet", (char*) kernelIdGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "kernelInit", (char*) kernelInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "kernelIsCpuIdle", (char*) kernelIsCpuIdle, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "kernelIsIdle", (char*) &kernelIsIdle, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "kernelIsSystemIdle", (char*) kernelIsSystemIdle, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "kernelModuleListId", (char*) &kernelModuleListId, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "kernelObjClassId", (char*) &kernelObjClassId, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "kernelRgnPoolId", (char*) &kernelRgnPoolId, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "kernelRoundRobinInstall", (char*) kernelRoundRobinInstall, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "kernelState", (char*) &kernelState, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "kernelTimeSlice", (char*) kernelTimeSlice, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "kernelTimeSliceGet", (char*) kernelTimeSliceGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "kernelVersion", (char*) kernelVersion, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "kernelVirtPgPoolId", (char*) &kernelVirtPgPoolId, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "kill", (char*) kill, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "kprintf", (char*) kprintf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "l", (char*) l, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "labs", (char*) labs, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ld", (char*) ld, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ldCommonMatchAll", (char*) &ldCommonMatchAll, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ldexp", (char*) ldexp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ldiv", (char*) ldiv, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ldiv_r", (char*) ldiv_r, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "le_uuid_dec", (char*) le_uuid_dec, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "le_uuid_enc", (char*) le_uuid_enc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledBeep", (char*) ledBeep, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledBwdFind", (char*) ledBwdFind, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledCDelete", (char*) ledCDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledChange", (char*) ledChange, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledClose", (char*) ledClose, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledComplete", (char*) ledComplete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledCompletionSet", (char*) ledCompletionSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledControl", (char*) ledControl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledDfltComplete", (char*) ledDfltComplete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledFwdFind", (char*) ledFwdFind, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledHistCurrentNumGet", (char*) ledHistCurrentNumGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledHistFind", (char*) ledHistFind, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledHistNextGet", (char*) ledHistNextGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledHistNumGet", (char*) ledHistNumGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledHistPrevGet", (char*) ledHistPrevGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledHistResize", (char*) ledHistResize, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledHistoryAdd", (char*) ledHistoryAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledHistoryClone", (char*) ledHistoryClone, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledHistoryCreate", (char*) ledHistoryCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledHistoryFree", (char*) ledHistoryFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledHistoryLineAllocate", (char*) ledHistoryLineAllocate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledHistorySet", (char*) ledHistorySet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledInactivityDelaySet", (char*) ledInactivityDelaySet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledLibInit", (char*) ledLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledModeDefaultNameGet", (char*) ledModeDefaultNameGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledModeNameGet", (char*) ledModeNameGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledModeRegister", (char*) ledModeRegister, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledModeSet", (char*) ledModeSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledNWrite", (char*) ledNWrite, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledOpen", (char*) ledOpen, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledPreempt", (char*) ledPreempt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledPreemptSet", (char*) ledPreemptSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledRead", (char*) ledRead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledRead2", (char*) ledRead2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledRedraw", (char*) ledRedraw, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledReplace", (char*) ledReplace, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ledSearch", (char*) ledSearch, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "link", (char*) link, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "linkBufPoolInit", (char*) linkBufPoolInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "linkDataSyms", (char*) &linkDataSyms, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "linkSyms", (char*) &linkSyms, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "linkedCtorsInitialized", (char*) &linkedCtorsInitialized, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "listen", (char*) listen, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "lkAddr", (char*) lkAddr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "lkAddrInternal", (char*) lkAddrInternal, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "lkup", (char*) lkup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ll", (char*) ll, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "llr", (char*) llr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadCommonSymbolProcess", (char*) loadCommonSymbolProcess, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadDefinedSymbolProcess", (char*) loadDefinedSymbolProcess, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadElfFileHeaderReadAndCheck", (char*) loadElfFileHeaderReadAndCheck, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadElfInit", (char*) loadElfInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadElfProgramHeaderTableReadAndCheck", (char*) loadElfProgramHeaderTableReadAndCheck, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadElfRelEntryRead", (char*) loadElfRelEntryRead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadElfRelUEntryRead", (char*) loadElfRelUEntryRead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadElfRelaEntryRead", (char*) loadElfRelaEntryRead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadElfSectionHeaderCheck", (char*) loadElfSectionHeaderCheck, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadElfSectionHeaderReadAndCheck", (char*) loadElfSectionHeaderReadAndCheck, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadElfSymbolEntryRead", (char*) loadElfSymbolEntryRead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadExecUsrFunc", (char*) loadExecUsrFunc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadExecUsrInit", (char*) loadExecUsrInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadFileSectionsChecksum", (char*) loadFileSectionsChecksum, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadLibInit", (char*) loadLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadModule", (char*) loadModule, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadModuleAt", (char*) loadModuleAt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadModuleEx", (char*) loadModuleEx, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadModuleInfoFromFd", (char*) loadModuleInfoFromFd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadModuleInfoFromFilenameOpen", (char*) loadModuleInfoFromFilenameOpen, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadModuleInfoInit", (char*) loadModuleInfoInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadModuleInfoRelease", (char*) loadModuleInfoRelease, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadModuleSeek", (char*) loadModuleSeek, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadModuleStringRead", (char*) loadModuleStringRead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadModuleTagsCheck", (char*) loadModuleTagsCheck, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadModuleValueRead", (char*) loadModuleValueRead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadSectionsInstall", (char*) loadSectionsInstall, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadSegInfoDescAllocate", (char*) loadSegInfoDescAllocate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadSegInfoDescFree", (char*) loadSegInfoDescFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadSegmentsAllocate", (char*) loadSegmentsAllocate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadShareTgtMemAlign", (char*) loadShareTgtMemAlign, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadShareTgtMemFree", (char*) loadShareTgtMemFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadShareTgtMemSet", (char*) loadShareTgtMemSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadSysSymTblLoad", (char*) loadSysSymTblLoad, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loadUndefinedSymbolProcess", (char*) loadUndefinedSymbolProcess, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loaderCacheBufferSize", (char*) &loaderCacheBufferSize, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "localToGlobalOffset", (char*) &localToGlobalOffset, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "localeconv", (char*) localeconv, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "localtime", (char*) localtime, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "localtime_r", (char*) localtime_r, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "log", (char*) log, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "log10", (char*) log10, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "logDecorationChange", (char*) logDecorationChange, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "logFd", (char*) &logFd, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "logFdAdd", (char*) logFdAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "logFdDelete", (char*) logFdDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "logFdFromRlogin", (char*) &logFdFromRlogin, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "logFdSem", (char*) &logFdSem, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "logFdSet", (char*) logFdSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "logInit", (char*) logInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "logLevelChange", (char*) logLevelChange, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "logMsg", (char*) logMsg, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "logShow", (char*) logShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "logTask", (char*) logTask, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "logTaskId", (char*) &logTaskId, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "logTaskOptions", (char*) &logTaskOptions, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "logTaskPriority", (char*) &logTaskPriority, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "logTaskStackSize", (char*) &logTaskStackSize, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "log_get_level", (char*) log_get_level, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "log_init", (char*) log_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "log_printf", (char*) log_printf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "log_set_level", (char*) log_set_level, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loggerInfoShow", (char*) loggerInfoShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "loginHostname", (char*) &loginHostname, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "loginPassword", (char*) &loginPassword, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "loginUsername", (char*) &loginUsername, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "logout", (char*) logout, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "longjmp", (char*) longjmp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ls", (char*) ls, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "lseek", (char*) lseek, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "lsr", (char*) lsr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "lstAdd", (char*) lstAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "lstConcat", (char*) lstConcat, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "lstCount", (char*) lstCount, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "lstDelete", (char*) lstDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "lstExtract", (char*) lstExtract, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "lstFind", (char*) lstFind, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "lstFirst", (char*) lstFirst, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "lstFree", (char*) lstFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "lstFree2", (char*) lstFree2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "lstGet", (char*) lstGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "lstInit", (char*) lstInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "lstInsert", (char*) lstInsert, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "lstLast", (char*) lstLast, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "lstLibInit", (char*) lstLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "lstNStep", (char*) lstNStep, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "lstNext", (char*) lstNext, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "lstNth", (char*) lstNth, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "lstPrevious", (char*) lstPrevious, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "m", (char*) m, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "m2If64BitCounters", (char*) &m2If64BitCounters, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "mRegs", (char*) mRegs, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "m_prepend", (char*) m_prepend, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "malloc", (char*) malloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "map_add", (char*) map_add, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "map_alloc", (char*) map_alloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "map_del", (char*) map_del, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "map_find", (char*) map_find, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "map_first", (char*) map_first, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "map_free", (char*) map_free, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "map_init", (char*) map_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "map_last", (char*) map_last, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "map_remove", (char*) map_remove, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "map_show", (char*) map_show, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "map_uninit", (char*) map_uninit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mask_copy", (char*) mask_copy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mask_generate", (char*) mask_generate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mask_poll", (char*) mask_poll, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mask_read", (char*) mask_read, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mask_write", (char*) mask_write, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mathSoftInit", (char*) mathSoftInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "max_hdr", (char*) &max_hdr, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "max_linkhdr", (char*) &max_linkhdr, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "max_protohdr", (char*) &max_protohdr, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "mblen", (char*) mblen, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mbstowcs", (char*) mbstowcs, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mbtowc", (char*) mbtowc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "md", (char*) md, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "md5_block_data_order", (char*) md5_block_data_order, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "md5_block_host_order", (char*) md5_block_host_order, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mdlSymSyncLibInit", (char*) mdlSymSyncLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mdlSymSyncModAdd", (char*) mdlSymSyncModAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mdlSymSyncModInfoGet", (char*) mdlSymSyncModInfoGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mdlSymSyncModuleRemove", (char*) mdlSymSyncModuleRemove, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mdlSymSyncStop", (char*) mdlSymSyncStop, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mdlSymSyncSymListAdd", (char*) mdlSymSyncSymListAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mdlSymSyncSymListGet", (char*) mdlSymSyncSymListGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memAddToPool", (char*) memAddToPool, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memBlockSizeGet", (char*) memBlockSizeGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memDefaultAlignment", (char*) &memDefaultAlignment, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "memFindMax", (char*) memFindMax, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memInfoGet", (char*) memInfoGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memInfoInit", (char*) memInfoInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memInit", (char*) memInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memMsgBlockError", (char*) &memMsgBlockError, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "memMsgBlockTooBig", (char*) &memMsgBlockTooBig, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "memOptionsGet", (char*) memOptionsGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memOptionsSet", (char*) memOptionsSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memPartAddToPool", (char*) memPartAddToPool, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memPartAlignedAlloc", (char*) memPartAlignedAlloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memPartAlloc", (char*) memPartAlloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memPartAllocErrorRtn", (char*) &memPartAllocErrorRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "memPartAllocN", (char*) memPartAllocN, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memPartBlockErrorRtn", (char*) &memPartBlockErrorRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "memPartBlockIsValid", (char*) memPartBlockIsValid, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memPartBlockValidate", (char*) memPartBlockValidate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memPartClassId", (char*) &memPartClassId, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "memPartCreate", (char*) memPartCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memPartCreateHookSet", (char*) memPartCreateHookSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memPartDelete", (char*) memPartDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memPartDeleteFree", (char*) memPartDeleteFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memPartEdrErrorInject", (char*) memPartEdrErrorInject, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memPartFindMax", (char*) memPartFindMax, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memPartFree", (char*) memPartFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memPartFreeListWalk", (char*) memPartFreeListWalk, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memPartFreeN", (char*) memPartFreeN, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memPartHooksInstall", (char*) memPartHooksInstall, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memPartInfoGet", (char*) memPartInfoGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memPartInit", (char*) memPartInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memPartInsertFree", (char*) memPartInsertFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memPartLibInit", (char*) memPartLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memPartOptionsDefault", (char*) &memPartOptionsDefault, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "memPartOptionsGet", (char*) memPartOptionsGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memPartOptionsSet", (char*) memPartOptionsSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memPartRealloc", (char*) memPartRealloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memPartReallocInternal", (char*) memPartReallocInternal, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memPartShow", (char*) memPartShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memPartVerifiedLock", (char*) memPartVerifiedLock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memPoolEndAdrs", (char*) &memPoolEndAdrs, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "memShow", (char*) memShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memShowInit", (char*) memShowInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memSysPartId", (char*) &memSysPartId, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "memSysPartition", (char*) &memSysPartition, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "memalign", (char*) memalign, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memchr", (char*) memchr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memcmp", (char*) memcmp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memcpy", (char*) memcpy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memmove", (char*) memmove, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memoryDump", (char*) memoryDump, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memoryModify", (char*) memoryModify, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "memset", (char*) memset, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mib2ErrorAdd", (char*) mib2ErrorAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mib2Init", (char*) mib2Init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "miiBusCreate", (char*) miiBusCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "miiBusDelete", (char*) miiBusDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "miiBusGet", (char*) miiBusGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "miiBusIdleErrorCheck", (char*) miiBusIdleErrorCheck, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "miiBusListAdd", (char*) miiBusListAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "miiBusListDel", (char*) miiBusListDel, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "miiBusLpiModeGet", (char*) miiBusLpiModeGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "miiBusMediaAdd", (char*) miiBusMediaAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "miiBusMediaDefaultSet", (char*) miiBusMediaDefaultSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "miiBusMediaDel", (char*) miiBusMediaDel, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "miiBusMediaListGet", (char*) miiBusMediaListGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "miiBusMediaUpdate", (char*) miiBusMediaUpdate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "miiBusModeGet", (char*) miiBusModeGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "miiBusModeSet", (char*) miiBusModeSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "miiBusRead", (char*) miiBusRead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "miiBusRegister", (char*) miiBusRegister, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "miiBusWrite", (char*) miiBusWrite, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "miiLpiModeGet_desc", (char*) &miiLpiModeGet_desc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "miiMediaUpdate_desc", (char*) &miiMediaUpdate_desc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "miiModeGet_desc", (char*) &miiModeGet_desc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "miiModeSet_desc", (char*) &miiModeSet_desc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "miiRead_desc", (char*) &miiRead_desc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "miiWrite_desc", (char*) &miiWrite_desc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "mkdir", (char*) mkdir, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mktime", (char*) mktime, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mm", (char*) mm, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmcCmdReadExtCsd", (char*) mmcCmdReadExtCsd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmcCmdSeEraseGrpEnd", (char*) mmcCmdSeEraseGrpEnd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmcCmdSeEraseGrpStart", (char*) mmcCmdSeEraseGrpStart, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmcCmdSetBlockNum", (char*) mmcCmdSetBlockNum, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmcCmdSetEraseGrp", (char*) mmcCmdSetEraseGrp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmcHrfsInclude", (char*) &mmcHrfsInclude, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "mmcSendHpi", (char*) mmcSendHpi, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmcSwitch", (char*) mmcSwitch, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmuArchCopySize", (char*) &mmuArchCopySize, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "mmuArchLibAttrs", (char*) &mmuArchLibAttrs, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "mmuArchLibFuncs", (char*) &mmuArchLibFuncs, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "mmuArchPteFlags", (char*) &mmuArchPteFlags, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "mmuArchTtbrFlags", (char*) &mmuArchTtbrFlags, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "mmuArchTtbrGet", (char*) mmuArchTtbrGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmuCacheStateTransTbl", (char*) &mmuCacheStateTransTbl, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "mmuContextTbl", (char*) &mmuContextTbl, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "mmuCortexA8ADisable", (char*) mmuCortexA8ADisable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmuCortexA8AEnable", (char*) mmuCortexA8AEnable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmuCortexA8AcrGet", (char*) mmuCortexA8AcrGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmuCortexA8AcrSet", (char*) mmuCortexA8AcrSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmuCortexA8BufCopy", (char*) mmuCortexA8BufCopy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmuCortexA8DTcmrGet", (char*) mmuCortexA8DTcmrGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmuCortexA8DTcmrSet", (char*) mmuCortexA8DTcmrSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmuCortexA8DacrSet", (char*) mmuCortexA8DacrSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmuCortexA8ITcmrGet", (char*) mmuCortexA8ITcmrGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmuCortexA8ITcmrSet", (char*) mmuCortexA8ITcmrSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmuCortexA8LibInstall", (char*) mmuCortexA8LibInstall, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmuCortexA8SecondLevelMiniHeap_Max", (char*) &mmuCortexA8SecondLevelMiniHeap_Max, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "mmuCortexA8TLBIDFlushAll", (char*) mmuCortexA8TLBIDFlushAll, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmuCortexA8TLBIDFlushEntry", (char*) mmuCortexA8TLBIDFlushEntry, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmuCortexA8TtbrGet", (char*) mmuCortexA8TtbrGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmuCortexA8TtbrGetAll", (char*) mmuCortexA8TtbrGetAll, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmuCortexA8TtbrSet", (char*) mmuCortexA8TtbrSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmuCortexA8TtbrSetAll", (char*) mmuCortexA8TtbrSetAll, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmuCortexA8WordSet", (char*) mmuCortexA8WordSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmuCortexA8WordSetMultiple", (char*) mmuCortexA8WordSetMultiple, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmuCrGet", (char*) &mmuCrGet, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "mmuFarGet", (char*) mmuFarGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmuFsrGet", (char*) mmuFsrGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmuHardCrGet", (char*) mmuHardCrGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmuIFsrGet", (char*) mmuIFsrGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmuInvalidState", (char*) &mmuInvalidState, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "mmuLibFuncs", (char*) &mmuLibFuncs, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "mmuMaskTransTbl", (char*) &mmuMaskTransTbl, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "mmuModifyCr", (char*) &mmuModifyCr, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "mmuModifyHardCr", (char*) mmuModifyHardCr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmuPhysToVirt", (char*) mmuPhysToVirt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmuProtStateTransTbl", (char*) &mmuProtStateTransTbl, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "mmuReadId", (char*) mmuReadId, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mmuValidStateTransTbl", (char*) &mmuValidStateTransTbl, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "mmuVirtToPhys", (char*) mmuVirtToPhys, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "modf", (char*) modf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "modlist", (char*) &modlist, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "moduleCheck", (char*) moduleCheck, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleCommonSymEach", (char*) moduleCommonSymEach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleCreate", (char*) moduleCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleCreateHookAdd", (char*) moduleCreateHookAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleCreateHookDelete", (char*) moduleCreateHookDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleDelete", (char*) moduleDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleDescDestroy", (char*) moduleDescDestroy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleEach", (char*) moduleEach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleFindByGroup", (char*) moduleFindByGroup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleFindByName", (char*) moduleFindByName, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleFindByNameAndPath", (char*) moduleFindByNameAndPath, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleFirstSectionGet", (char*) moduleFirstSectionGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleFlagsGet", (char*) moduleFlagsGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleFlagsSet", (char*) moduleFlagsSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleHookLibInit", (char*) moduleHookLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleIdFigure", (char*) moduleIdFigure, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleIdListGet", (char*) moduleIdListGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleIdVerify", (char*) moduleIdVerify, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleInfoGet", (char*) moduleInfoGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleInit", (char*) moduleInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleIsLastModuleMatched", (char*) moduleIsLastModuleMatched, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleLibInit", (char*) moduleLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleLoadHookAdd", (char*) moduleLoadHookAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleLoadHookDelete", (char*) moduleLoadHookDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleLoadHooksCall", (char*) moduleLoadHooksCall, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleNameGet", (char*) moduleNameGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleNextSectionGet", (char*) moduleNextSectionGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleSectionChecksumSet", (char*) moduleSectionChecksumSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleSectionDescFree", (char*) moduleSectionDescFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleSectionDescGet", (char*) moduleSectionDescGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleSectionRegister", (char*) moduleSectionRegister, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleSectionsCksumCompare", (char*) moduleSectionsCksumCompare, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleSectionsFileChecksumSet", (char*) moduleSectionsFileChecksumSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleSegAdd", (char*) moduleSegAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleSegEach", (char*) moduleSegEach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleSegFirst", (char*) moduleSegFirst, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleSegGet", (char*) moduleSegGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleSegInfoGet", (char*) moduleSegInfoGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleSegNext", (char*) moduleSegNext, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleShellCmdInit", (char*) moduleShellCmdInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleShow", (char*) moduleShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleShowInit", (char*) moduleShowInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleUndefSymAdd", (char*) moduleUndefSymAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleUndefSymEach", (char*) moduleUndefSymEach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleUnloadHookAdd", (char*) moduleUnloadHookAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleUnloadHookDelete", (char*) moduleUnloadHookDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "moduleUnloadHooksCall", (char*) moduleUnloadHooksCall, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mountFTL", (char*) mountFTL, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mountValidateSet", (char*) mountValidateSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "msgQClassId", (char*) &msgQClassId, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "msgQCreate", (char*) msgQCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "msgQCreateLibInit", (char*) msgQCreateLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "msgQDelete", (char*) msgQDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "msgQDestroy", (char*) msgQDestroy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "msgQEvStart", (char*) msgQEvStart, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "msgQEvStop", (char*) msgQEvStop, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "msgQInfoGet", (char*) msgQInfoGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "msgQInit", (char*) msgQInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "msgQInitialize", (char*) msgQInitialize, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "msgQLibInit", (char*) msgQLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "msgQLibInstalled", (char*) &msgQLibInstalled, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "msgQNumMsgs", (char*) msgQNumMsgs, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "msgQReceive", (char*) msgQReceive, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "msgQSend", (char*) msgQSend, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "msgQSmNumMsgsRtn", (char*) &msgQSmNumMsgsRtn, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "msgQSmReceiveRtn", (char*) &msgQSmReceiveRtn, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "msgQSmSendRtn", (char*) &msgQSmSendRtn, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "msgQTerminate", (char*) msgQTerminate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "msgQWritable", (char*) msgQWritable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mtdIdentifyTable", (char*) &mtdIdentifyTable, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "mtdTable", (char*) &mtdTable, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "mutexOptionsHostLib", (char*) &mutexOptionsHostLib, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "mutexOptionsIosLib", (char*) &mutexOptionsIosLib, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "mutexOptionsLogLib", (char*) &mutexOptionsLogLib, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "mutexOptionsNetDrv", (char*) &mutexOptionsNetDrv, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "mutexOptionsSelectLib", (char*) &mutexOptionsSelectLib, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "mutexOptionsSymLib", (char*) &mutexOptionsSymLib, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "mutexOptionsTyLib", (char*) &mutexOptionsTyLib, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "mux2Bind", (char*) mux2Bind, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mux2LibInit", (char*) mux2LibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mux2OverEndInit", (char*) mux2OverEndInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mux2OverEndOutputFilterChainDrops", (char*) &mux2OverEndOutputFilterChainDrops, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "mux2PollReceive", (char*) mux2PollReceive, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mux2PollSend", (char*) mux2PollSend, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mux2Send", (char*) mux2Send, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxAddressForm", (char*) muxAddressForm, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxBind", (char*) muxBind, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxBindCommon", (char*) muxBindCommon, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxBindStyles", (char*) &muxBindStyles, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "muxCommonInit", (char*) muxCommonInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxDebug", (char*) &muxDebug, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "muxDevAcquire", (char*) muxDevAcquire, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxDevConnect_desc", (char*) &muxDevConnect_desc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "muxDevExists", (char*) muxDevExists, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxDevLoad", (char*) muxDevLoad, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxDevRelease", (char*) muxDevRelease, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxDevStart", (char*) muxDevStart, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxDevStop", (char*) muxDevStop, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxDevStopAll", (char*) muxDevStopAll, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxDevUnload", (char*) muxDevUnload, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxDevUnloadAsync", (char*) muxDevUnloadAsync, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxEndJobQDo", (char*) muxEndJobQDo, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxEndJobQDoJob", (char*) muxEndJobQDoJob, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxEndListGet", (char*) muxEndListGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxEndQnumGet", (char*) muxEndQnumGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxEndRxJobQueue", (char*) muxEndRxJobQueue, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxEndStyles", (char*) &muxEndStyles, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "muxError", (char*) muxError, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxErrorPost", (char*) muxErrorPost, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxErrorSkip", (char*) muxErrorSkip, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxIfTypeGet", (char*) muxIfTypeGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxInstallDevStopRebootHook", (char*) &muxInstallDevStopRebootHook, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "muxIoctl", (char*) muxIoctl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxIpcomPktFreeMblk", (char*) muxIpcomPktFreeMblk, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxIpcomPktToMblkTx", (char*) muxIpcomPktToMblkTx, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxL2PortDetachRtn", (char*) &muxL2PortDetachRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "muxLibInit", (char*) muxLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxLinkDownNotify", (char*) muxLinkDownNotify, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxLinkHeaderCreate", (char*) muxLinkHeaderCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxLinkUpNotify", (char*) muxLinkUpNotify, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxLock", (char*) &muxLock, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "muxMCastAddrAdd", (char*) muxMCastAddrAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxMCastAddrDel", (char*) muxMCastAddrDel, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxMCastAddrGet", (char*) muxMCastAddrGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxMblkToIpcomPktMallocDrops", (char*) &muxMblkToIpcomPktMallocDrops, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "muxMblkToIpcomPktTx", (char*) muxMblkToIpcomPktTx, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxMblkToIpcomPktTxChainDrops", (char*) &muxMblkToIpcomPktTxChainDrops, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "muxPacketAddrGet", (char*) muxPacketAddrGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxPacketDataGet", (char*) muxPacketDataGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxPollReceive", (char*) muxPollReceive, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxPollSend", (char*) muxPollSend, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxProtoInfoGet", (char*) muxProtoInfoGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxProtoListGet", (char*) muxProtoListGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxReceive", (char*) muxReceive, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxRestoreIpcomPktFromMblkTx", (char*) muxRestoreIpcomPktFromMblkTx, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxSend", (char*) muxSend, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxShow", (char*) muxShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxTkBind", (char*) muxTkBind, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxTkCookieGet", (char*) muxTkCookieGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxTkDrvCheck", (char*) muxTkDrvCheck, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxTkLibInit", (char*) muxTkLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxTkOverEndInit", (char*) muxTkOverEndInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxTkPollReceive", (char*) muxTkPollReceive, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxTkPollSend", (char*) muxTkPollSend, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxTkSend", (char*) muxTkSend, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxTxRestart", (char*) muxTxRestart, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "muxUnbind", (char*) muxUnbind, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "mv", (char*) mv, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "nae_log", (char*) nae_log, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "namelessPrefix", (char*) &namelessPrefix, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "nanosleep", (char*) nanosleep, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "needCheckRAM", (char*) &needCheckRAM, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "netAttachFlag", (char*) &netAttachFlag, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "netBufClOffset", (char*) &netBufClOffset, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "netBufLibInit", (char*) netBufLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netBufLibInitialize", (char*) netBufLibInitialize, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netBufLock", (char*) &netBufLock, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "netBufPoolInit", (char*) netBufPoolInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netClBlkFree", (char*) netClBlkFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netClBlkGet", (char*) netClBlkGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netClBlkJoin", (char*) netClBlkJoin, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netClFree", (char*) netClFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netClPoolIdGet", (char*) netClPoolIdGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netClusterGet", (char*) netClusterGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netDaemonQ", (char*) netDaemonQ, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netDaemonQnum", (char*) netDaemonQnum, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netDaemonsCount", (char*) netDaemonsCount, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netDaemonsStart", (char*) netDaemonsStart, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netDevBootFlag", (char*) &netDevBootFlag, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "netDevCreate", (char*) netDevCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netDevCreate2", (char*) netDevCreate2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netDevCreateEx", (char*) netDevCreateEx, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netDrv", (char*) netDrv, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netDrvDebugLevelSet", (char*) netDrvDebugLevelSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netDrvFileDoesNotExist", (char*) netDrvFileDoesNotExist, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netDrvFileDoesNotExistInstall", (char*) netDrvFileDoesNotExistInstall, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netErrnoSet", (char*) netErrnoSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netHelp", (char*) netHelp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netJobAdd", (char*) netJobAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netJobNum", (char*) &netJobNum, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "netJobQueueId", (char*) &netJobQueueId, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "netLibInitialize", (char*) netLibInitialize, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netLsByName", (char*) netLsByName, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netMblkChainDup", (char*) netMblkChainDup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netMblkClChainFree", (char*) netMblkClChainFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netMblkClFree", (char*) netMblkClFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netMblkClGet", (char*) netMblkClGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netMblkClJoin", (char*) netMblkClJoin, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netMblkDup", (char*) netMblkDup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netMblkFree", (char*) netMblkFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netMblkFromBufCopy", (char*) netMblkFromBufCopy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netMblkGet", (char*) netMblkGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netMblkOffsetToBufCopy", (char*) netMblkOffsetToBufCopy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netMblkToBufCopy", (char*) netMblkToBufCopy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netPoolCreate", (char*) netPoolCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netPoolCreateValidate", (char*) netPoolCreateValidate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netPoolDelete", (char*) netPoolDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netPoolIdGet", (char*) netPoolIdGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netPoolIdGetWork", (char*) netPoolIdGetWork, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netPoolInit", (char*) netPoolInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netPoolInitWrapper", (char*) netPoolInitWrapper, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netPoolKheapInit", (char*) netPoolKheapInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netPoolNameGet", (char*) netPoolNameGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netPoolRelPri", (char*) &netPoolRelPri, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "netPoolRelease", (char*) netPoolRelease, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netTaskId", (char*) &netTaskId, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "netTaskNamePrefix", (char*) &netTaskNamePrefix, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "netTaskOptions", (char*) &netTaskOptions, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "netTaskPriority", (char*) &netTaskPriority, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "netTaskStackSize", (char*) &netTaskStackSize, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "netTupleFree", (char*) netTupleFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netTupleGet", (char*) netTupleGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "netVersionString", (char*) &netVersionString, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "netmask", (char*) &netmask, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "noDev", (char*) noDev, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "noOfDrives", (char*) &noOfDrives, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "noOfMTDs", (char*) &noOfMTDs, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "noOfTLs", (char*) &noOfTLs, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ns16550SioRegister", (char*) ns16550SioRegister, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ns16550TestChannels", (char*) ns16550TestChannels, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ns16550vxbChanSetup", (char*) ns16550vxbChanSetup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ns16550vxbDebugLevel", (char*) &ns16550vxbDebugLevel, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ns16550vxbDumpOutputChars", (char*) ns16550vxbDumpOutputChars, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ns16550vxbPollEcho", (char*) ns16550vxbPollEcho, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ns16550vxbReadInputChars", (char*) ns16550vxbReadInputChars, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ns16550vxbSioShow", (char*) ns16550vxbSioShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ns16550vxbTestOutput", (char*) ns16550vxbTestOutput, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "numLogFds", (char*) &numLogFds, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "objAlloc", (char*) objAlloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objAllocExtra", (char*) objAllocExtra, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objArchLibInit", (char*) objArchLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objClassIdGet", (char*) objClassIdGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objClassTypeGet", (char*) objClassTypeGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objContextGet", (char*) objContextGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objContextSet", (char*) objContextSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objCoreInit", (char*) objCoreInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objCoreInvalidate", (char*) objCoreInvalidate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objCoreReclaim", (char*) objCoreReclaim, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objCoreTerminate", (char*) objCoreTerminate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objCoreUnlink", (char*) objCoreUnlink, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objEach", (char*) objEach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objFree", (char*) objFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objGenericVerify", (char*) objGenericVerify, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objInfo", (char*) objInfo, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objInfoInit", (char*) objInfoInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objLibInit", (char*) objLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objMemAlloc", (char*) objMemAlloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objMemFree", (char*) objMemFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objNameGet", (char*) objNameGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objNameLenGet", (char*) objNameLenGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objNamePtrGet", (char*) objNamePtrGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objNamePtrSet", (char*) objNamePtrSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objNameSet", (char*) objNameSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objNameToId", (char*) objNameToId, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objOwnerGet", (char*) objOwnerGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objOwnerLibInstalled", (char*) &objOwnerLibInstalled, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "objOwnerSet", (char*) objOwnerSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objOwnerSetBase", (char*) objOwnerSetBase, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objRoutineNameGet", (char*) objRoutineNameGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objShow", (char*) objShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objVerify", (char*) objVerify, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objVerifyError", (char*) objVerifyError, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objVerifyMagicRead", (char*) objVerifyMagicRead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objVerifyTypeRead", (char*) objVerifyTypeRead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "objectShow", (char*) objectShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "onAssert__", (char*) onAssert__, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "open", (char*) open, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "opendir", (char*) opendir, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "operation_tip", (char*) &operation_tip, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "oprintf", (char*) oprintf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "optarg", (char*) &optarg, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "opterr", (char*) &opterr, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "optind", (char*) &optind, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "optopt", (char*) &optopt, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "optreset", (char*) &optreset, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "osmGuardPageSize", (char*) &osmGuardPageSize, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pAddrString", (char*) &pAddrString, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "pAsInitParams", (char*) &pAsInitParams, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "pAsMemDesc", (char*) &pAsMemDesc, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "pBusHead", (char*) &pBusHead, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pBusListHead", (char*) &pBusListHead, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pChanStructShow", (char*) pChanStructShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pClkCookie", (char*) &pClkCookie, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pClkTimer", (char*) &pClkTimer, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pCoprocDescList", (char*) &pCoprocDescList, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pDbgClnt", (char*) &pDbgClnt, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pDevName", (char*) &pDevName, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "pDriverListHead", (char*) &pDriverListHead, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pEndPktDev", (char*) &pEndPktDev, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "pHead", (char*) &pHead, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pIosDevCloseRtn", (char*) &pIosDevCloseRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pIosFdEntrySetRtn", (char*) &pIosFdEntrySetRtn, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "pIosFdInvalidRtn", (char*) &pIosFdInvalidRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pIosRemovableDevDrv", (char*) &pIosRemovableDevDrv, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "pIosSuspendedDevDrv", (char*) &pIosSuspendedDevDrv, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "pJobPool", (char*) &pJobPool, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "pLoadRoutine", (char*) &pLoadRoutine, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pLoaderHooksCall", (char*) &pLoaderHooksCall, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "pM2TrapRtn", (char*) &pM2TrapRtn, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "pM2TrapRtnArg", (char*) &pM2TrapRtnArg, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "pMibRtn", (char*) &pMibRtn, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "pNetPoolHead", (char*) &pNetPoolHead, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pNullFd", (char*) &pNullFd, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "pPlbBus", (char*) &pPlbBus, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pPlbDev", (char*) &pPlbDev, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pPlbDevControl", (char*) &pPlbDevControl, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pRebootHookTbl", (char*) &pRebootHookTbl, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "pRootMemStart", (char*) &pRootMemStart, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "pRtpDbgCmdSvc", (char*) &pRtpDbgCmdSvc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pSockIoctlMemVal", (char*) &pSockIoctlMemVal, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pSysClkName", (char*) &pSysClkName, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pSysPhysMemDescCortexA8Ext", (char*) &pSysPhysMemDescCortexA8Ext, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pSysPlbMethods", (char*) &pSysPlbMethods, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pTaskLastDspTcb", (char*) &pTaskLastDspTcb, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pTaskLastFpTcb", (char*) &pTaskLastFpTcb, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pTgtName", (char*) &pTgtName, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "pTimestampCookie", (char*) &pTimestampCookie, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pTimestampTimer", (char*) &pTimestampTimer, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pTimestampTimerName", (char*) &pTimestampTimerName, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pUnixIoctlMemVal", (char*) &pUnixIoctlMemVal, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pUnloaderHooksCall", (char*) &pUnloaderHooksCall, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "pVxbDelayCookie", (char*) &pVxbDelayCookie, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pVxbDelayTimer", (char*) &pVxbDelayTimer, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pVxbSpinLockGive", (char*) &pVxbSpinLockGive, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pVxbSpinLockTake", (char*) &pVxbSpinLockTake, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pWdbClnt", (char*) &pWdbClnt, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pWdbCommIf", (char*) &pWdbCommIf, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "pWdbCtxBpIf", (char*) &pWdbCtxBpIf, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "pWdbExternSystemRegs", (char*) &pWdbExternSystemRegs, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pWdbMemRegions", (char*) &pWdbMemRegions, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pWdbRtIf", (char*) &pWdbRtIf, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "pWdbXport", (char*) &pWdbXport, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "pWvNetEvtMap", (char*) &pWvNetEvtMap, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "panic", (char*) panic, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "panicSuspend", (char*) &panicSuspend, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "partitionExist", (char*) &partitionExist, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pathBuild", (char*) pathBuild, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pathCat", (char*) pathCat, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pathCondense", (char*) pathCondense, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pathLastName", (char*) pathLastName, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pathLastNamePtr", (char*) pathLastNamePtr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pathParse", (char*) pathParse, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pathSplit", (char*) pathSplit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pathconf", (char*) pathconf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pause", (char*) pause, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pc", (char*) pc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "period", (char*) period, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "periodHost", (char*) periodHost, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "periodRun", (char*) periodRun, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "perror", (char*) perror, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolAddToPool", (char*) pgPoolAddToPool, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolAlignedAlloc", (char*) pgPoolAlignedAlloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolAllocAt", (char*) pgPoolAllocAt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolAvailAlloc", (char*) pgPoolAvailAlloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolCreate", (char*) pgPoolCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolDelete", (char*) pgPoolDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolFree", (char*) pgPoolFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolInfoGet", (char*) pgPoolInfoGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolInit", (char*) pgPoolInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolLibInit", (char*) pgPoolLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolNextFreeGet", (char*) pgPoolNextFreeGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolPhysAddToPool", (char*) pgPoolPhysAddToPool, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolPhysAlignedAlloc", (char*) pgPoolPhysAlignedAlloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolPhysAlloc", (char*) pgPoolPhysAlloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolPhysAllocAt", (char*) pgPoolPhysAllocAt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolPhysAvailAlloc", (char*) pgPoolPhysAvailAlloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolPhysFree", (char*) pgPoolPhysFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolPhysLibInit", (char*) pgPoolPhysLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolPhysNextFreeGet", (char*) pgPoolPhysNextFreeGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolPhysRangeEach", (char*) pgPoolPhysRangeEach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolPhysRangeIsAllocated", (char*) pgPoolPhysRangeIsAllocated, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolPhysRangeIsFree", (char*) pgPoolPhysRangeIsFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolPhysRangeVerify", (char*) pgPoolPhysRangeVerify, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolPhysRemoveFromPool", (char*) pgPoolPhysRemoveFromPool, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolRangeStateCheck", (char*) pgPoolRangeStateCheck, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolRangeVerify", (char*) pgPoolRangeVerify, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolRemoveFromPool", (char*) pgPoolRemoveFromPool, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolVirtAddToPool", (char*) pgPoolVirtAddToPool, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolVirtAlignedAlloc", (char*) pgPoolVirtAlignedAlloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolVirtAlloc", (char*) pgPoolVirtAlloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolVirtAllocAt", (char*) pgPoolVirtAllocAt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolVirtAvailAlloc", (char*) pgPoolVirtAvailAlloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolVirtFree", (char*) pgPoolVirtFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolVirtLibInit", (char*) pgPoolVirtLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolVirtNextFreeGet", (char*) pgPoolVirtNextFreeGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolVirtRangeEach", (char*) pgPoolVirtRangeEach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolVirtRangeIsAllocated", (char*) pgPoolVirtRangeIsAllocated, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolVirtRangeIsFree", (char*) pgPoolVirtRangeIsFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolVirtRangeVerify", (char*) pgPoolVirtRangeVerify, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pgPoolVirtRemoveFromPool", (char*) pgPoolVirtRemoveFromPool, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "phy1116R_MiiRead", (char*) phy1116R_MiiRead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "phy1116R_MiiWrite", (char*) phy1116R_MiiWrite, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "phy8511_MiiRead", (char*) phy8511_MiiRead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "phy8511_MiiWrite", (char*) phy8511_MiiWrite, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "phy_read", (char*) phy_read, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "phy_read2", (char*) phy_read2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "phy_read_all", (char*) phy_read_all, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "phy_write", (char*) phy_write, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ping", (char*) ping, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ping2", (char*) ping2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pingLibInit2", (char*) pingLibInit2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pipeDevCreate", (char*) pipeDevCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pipeDevDelete", (char*) pipeDevDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pipeDrv", (char*) pipeDrv, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pipeMsgQOptions", (char*) &pipeMsgQOptions, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "pl_bitstream_parse", (char*) pl_bitstream_parse, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "plbInit1", (char*) plbInit1, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "plbIntrGet", (char*) plbIntrGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "plbIntrSet", (char*) plbIntrSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "plbRegister", (char*) plbRegister, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pmtuShow", (char*) pmtuShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "poolBlockAdd", (char*) poolBlockAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "poolCreate", (char*) poolCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "poolDelete", (char*) poolDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "poolFindItem", (char*) poolFindItem, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "poolFreeCount", (char*) poolFreeCount, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "poolIdListGet", (char*) poolIdListGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "poolIncrementGet", (char*) poolIncrementGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "poolIncrementSet", (char*) poolIncrementSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "poolInitialize", (char*) poolInitialize, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "poolItemGet", (char*) poolItemGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "poolItemReturn", (char*) poolItemReturn, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "poolLibInit", (char*) poolLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "poolListGbl", (char*) &poolListGbl, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "poolTotalCount", (char*) poolTotalCount, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "poolUnusedBlocksFree", (char*) poolUnusedBlocksFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "posixSignalMode", (char*) &posixSignalMode, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "pow", (char*) pow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ppGlobalEnviron", (char*) &ppGlobalEnviron, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "print64", (char*) print64, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "print64Fine", (char*) print64Fine, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "print64Mult", (char*) print64Mult, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "print64Row", (char*) print64Row, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "printErr", (char*) printErr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "printErrno", (char*) printErrno, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "printExc", (char*) printExc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "printLogo", (char*) printLogo, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "printf", (char*) printf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "prints", (char*) prints, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "priv_targetName", (char*) &priv_targetName, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "ps_clock_init_data", (char*) &ps_clock_init_data, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ps_config", (char*) ps_config, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ps_ddr_init_data", (char*) &ps_ddr_init_data, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ps_debug", (char*) ps_debug, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ps_debug_init_data", (char*) &ps_debug_init_data, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ps_init", (char*) ps_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ps_init_2", (char*) ps_init_2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ps_mio_init_data", (char*) &ps_mio_init_data, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ps_mio_init_data_nfc", (char*) &ps_mio_init_data_nfc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ps_peripherals_init_data", (char*) &ps_peripherals_init_data, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ps_peripherals_init_data_nfc", (char*) &ps_peripherals_init_data_nfc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ps_pll_init_data", (char*) &ps_pll_init_data, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ps_post_config", (char*) ps_post_config, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ps_post_config_init_data", (char*) &ps_post_config_init_data, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "ps_post_init_data", (char*) &ps_post_init_data, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "psrShow", (char*) psrShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ptyDevCreate", (char*) ptyDevCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ptyDevRemove", (char*) ptyDevRemove, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ptyDrv", (char*) ptyDrv, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "putc", (char*) putc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "putchar", (char*) putchar, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "putenv", (char*) putenv, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "puts", (char*) puts, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "putw", (char*) putw, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "pwd", (char*) pwd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qFifoClass", (char*) &qFifoClass, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "qFifoClassId", (char*) &qFifoClassId, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "qFifoEach", (char*) qFifoEach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qFifoGet", (char*) qFifoGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qFifoInfo", (char*) qFifoInfo, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qFifoInit", (char*) qFifoInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qFifoNext", (char*) qFifoNext, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qFifoPut", (char*) qFifoPut, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qFifoRemove", (char*) qFifoRemove, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qFifoResort", (char*) qFifoResort, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qFifoRestore", (char*) qFifoRestore, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qPriBMapClassId", (char*) &qPriBMapClassId, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "qPriBMapEach", (char*) qPriBMapEach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qPriBMapGet", (char*) qPriBMapGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qPriBMapInfo", (char*) qPriBMapInfo, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qPriBMapInit", (char*) qPriBMapInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qPriBMapKey", (char*) qPriBMapKey, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qPriBMapNext", (char*) qPriBMapNext, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qPriBMapPut", (char*) qPriBMapPut, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qPriBMapRemove", (char*) qPriBMapRemove, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qPriBMapResort", (char*) qPriBMapResort, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qPriBMapRestore", (char*) qPriBMapRestore, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qPriBMapSet", (char*) qPriBMapSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qPriDeltaAdvance", (char*) qPriDeltaAdvance, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qPriDeltaClassId", (char*) &qPriDeltaClassId, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "qPriDeltaEach", (char*) qPriDeltaEach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qPriDeltaGet", (char*) qPriDeltaGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qPriDeltaGetExpired", (char*) qPriDeltaGetExpired, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qPriDeltaInfo", (char*) qPriDeltaInfo, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qPriDeltaInit", (char*) qPriDeltaInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qPriDeltaKey", (char*) qPriDeltaKey, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qPriDeltaNext", (char*) qPriDeltaNext, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qPriDeltaPut", (char*) qPriDeltaPut, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qPriDeltaRemove", (char*) qPriDeltaRemove, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qPriDeltaResort", (char*) qPriDeltaResort, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qPriListClassId", (char*) &qPriListClassId, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "qPriListEach", (char*) qPriListEach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qPriListFromTailClassId", (char*) &qPriListFromTailClassId, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "qPriListGet", (char*) qPriListGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qPriListInfo", (char*) qPriListInfo, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qPriListInit", (char*) qPriListInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qPriListKey", (char*) qPriListKey, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qPriListNext", (char*) qPriListNext, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qPriListPut", (char*) qPriListPut, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qPriListPutFromTail", (char*) qPriListPutFromTail, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qPriListRemove", (char*) qPriListRemove, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qPriListResort", (char*) qPriListResort, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qTradPriBMapClassId", (char*) &qTradPriBMapClassId, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "qTradPriBMapSetCompatible", (char*) qTradPriBMapSetCompatible, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qTradPriListClassId", (char*) &qTradPriListClassId, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "qTradPriListSetCompatible", (char*) qTradPriListSetCompatible, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qsort", (char*) qsort, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiCtrl_Clr_RcvFifo", (char*) qspiCtrl_Clr_RcvFifo, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiCtrl_CmdExecute", (char*) qspiCtrl_CmdExecute, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiCtrl_FastRcv_Setup", (char*) qspiCtrl_FastRcv_Setup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiCtrl_FastSnd_Setup", (char*) qspiCtrl_FastSnd_Setup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiCtrl_Rd_CfgReg", (char*) qspiCtrl_Rd_CfgReg, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiCtrl_Rd_Fifo", (char*) qspiCtrl_Rd_Fifo, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiCtrl_Reset", (char*) qspiCtrl_Reset, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiCtrl_SetFlashMode", (char*) qspiCtrl_SetFlashMode, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiCtrl_Set_3B_AddrMode", (char*) qspiCtrl_Set_3B_AddrMode, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiCtrl_Set_4B_AddrMode", (char*) qspiCtrl_Set_4B_AddrMode, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiCtrl_Set_BaudRate", (char*) qspiCtrl_Set_BaudRate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiCtrl_Set_BytesMode", (char*) qspiCtrl_Set_BytesMode, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiCtrl_Set_CaptureDelay", (char*) qspiCtrl_Set_CaptureDelay, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiCtrl_Wait_BusIdle", (char*) qspiCtrl_Wait_BusIdle, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiCtrl_Wait_ExeOk", (char*) qspiCtrl_Wait_ExeOk, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiCtrl_Wr_CfgReg", (char*) qspiCtrl_Wr_CfgReg, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiCtrl_Wr_Fifo", (char*) qspiCtrl_Wr_Fifo, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiCtrl_params_init", (char*) qspiCtrl_params_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlashInit1", (char*) qspiFlashInit1, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlashInit2", (char*) qspiFlashInit2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_Clr_FlagStatus", (char*) qspiFlash_Clr_FlagStatus, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_Enter_4BAddr", (char*) qspiFlash_Enter_4BAddr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_Erase_Chip", (char*) qspiFlash_Erase_Chip, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_Erase_Sect", (char*) qspiFlash_Erase_Sect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_Exit_4BAddr", (char*) qspiFlash_Exit_4BAddr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_Get_FlagStatus", (char*) qspiFlash_Get_FlagStatus, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_Get_QuadMode", (char*) qspiFlash_Get_QuadMode, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_Get_Reg16", (char*) qspiFlash_Get_Reg16, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_Get_Reg8", (char*) qspiFlash_Get_Reg8, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_Get_RegStatus1", (char*) qspiFlash_Get_RegStatus1, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_Get_Segment", (char*) qspiFlash_Get_Segment, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_Offset_LogtoPhy", (char*) qspiFlash_Offset_LogtoPhy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_PageIdx_LogtoPhy", (char*) qspiFlash_PageIdx_LogtoPhy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_ParseInfo_2", (char*) qspiFlash_ParseInfo_2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_RcvBytes_Direct", (char*) qspiFlash_RcvBytes_Direct, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_RcvBytes_Direct_tffs", (char*) qspiFlash_RcvBytes_Direct_tffs, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_RcvBytes_Indirect", (char*) qspiFlash_RcvBytes_Indirect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_RcvBytes_Indirect_tffs", (char*) qspiFlash_RcvBytes_Indirect_tffs, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_ReadBytes_Direct0", (char*) qspiFlash_ReadBytes_Direct0, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_ReadBytes_Direct0_tffs", (char*) qspiFlash_ReadBytes_Direct0_tffs, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_ReadBytes_InDirect0", (char*) qspiFlash_ReadBytes_InDirect0, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_ReadBytes_InDirect0_tffs", (char*) qspiFlash_ReadBytes_InDirect0_tffs, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_ReadId", (char*) qspiFlash_ReadId, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_ReadId_2", (char*) qspiFlash_ReadId_2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_ReadId_3", (char*) qspiFlash_ReadId_3, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_Read_Page", (char*) qspiFlash_Read_Page, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_Read_Sect", (char*) qspiFlash_Read_Sect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_Reset_Flash", (char*) qspiFlash_Reset_Flash, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_Rx_Data", (char*) qspiFlash_Rx_Data, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_SectIdx_LogtoPhy", (char*) qspiFlash_SectIdx_LogtoPhy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_SectIdx_LogtoPhy_Only", (char*) qspiFlash_SectIdx_LogtoPhy_Only, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_Set_QuadMode", (char*) qspiFlash_Set_QuadMode, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_Set_Reg16", (char*) qspiFlash_Set_Reg16, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_Set_Reg8", (char*) qspiFlash_Set_Reg8, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_Set_Seg_0_16M", (char*) qspiFlash_Set_Seg_0_16M, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_Set_Seg_16_32M", (char*) qspiFlash_Set_Seg_16_32M, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_Set_Seg_32_48M", (char*) qspiFlash_Set_Seg_32_48M, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_Set_Seg_48_64M", (char*) qspiFlash_Set_Seg_48_64M, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_Set_Segment", (char*) qspiFlash_Set_Segment, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_SndBytes_Direct", (char*) qspiFlash_SndBytes_Direct, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_SndBytes_Direct_2", (char*) qspiFlash_SndBytes_Direct_2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_SndBytes_Direct_tffs", (char*) qspiFlash_SndBytes_Direct_tffs, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_SndBytes_Indirect", (char*) qspiFlash_SndBytes_Indirect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_SndBytes_Indirect_tffs", (char*) qspiFlash_SndBytes_Indirect_tffs, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_Tx_Data", (char*) qspiFlash_Tx_Data, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_UnLock_Flash_Ctrl0", (char*) qspiFlash_UnLock_Flash_Ctrl0, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_Unlock_Flash", (char*) qspiFlash_Unlock_Flash, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_WREN_Cmd", (char*) qspiFlash_WREN_Cmd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_Wait_FSR_Ok", (char*) qspiFlash_Wait_FSR_Ok, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_Wait_FlashReady", (char*) qspiFlash_Wait_FlashReady, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_Wait_WIP_Ok", (char*) qspiFlash_Wait_WIP_Ok, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_WriteBytes_Direct0", (char*) qspiFlash_WriteBytes_Direct0, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_WriteBytes_Direct0_tffs", (char*) qspiFlash_WriteBytes_Direct0_tffs, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_WriteBytes_InDirect0", (char*) qspiFlash_WriteBytes_InDirect0, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_WriteBytes_InDirect0_tffs", (char*) qspiFlash_WriteBytes_InDirect0_tffs, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_Write_Page", (char*) qspiFlash_Write_Page, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspiFlash_Write_Sect", (char*) qspiFlash_Write_Sect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspi_erase_ipaddr", (char*) qspi_erase_ipaddr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "qspi_get_ipaddr", (char*) qspi_get_ipaddr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "r0", (char*) r0, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "r1", (char*) r1, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "r10", (char*) r10, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "r11", (char*) r11, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "r12", (char*) r12, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "r13", (char*) r13, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "r14", (char*) r14, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "r2", (char*) r2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "r3", (char*) r3, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "r4", (char*) r4, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "r5", (char*) r5, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "r6", (char*) r6, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "r7", (char*) r7, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "r8", (char*) r8, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "r9", (char*) r9, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "raise", (char*) raise, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "rand", (char*) rand, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "rawFsBioBufferSize", (char*) &rawFsBioBufferSize, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "rawFsDevInit", (char*) rawFsDevInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "rawFsDrvNum", (char*) &rawFsDrvNum, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "rawFsFdListMutexOptions", (char*) &rawFsFdListMutexOptions, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "rawFsFdMutexOptions", (char*) &rawFsFdMutexOptions, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "rawFsInit", (char*) rawFsInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "rawFsVolMutexOptions", (char*) &rawFsVolMutexOptions, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "rawFsVolUnmount", (char*) rawFsVolUnmount, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "rcmd", (char*) rcmd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "rcmd_af", (char*) rcmd_af, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "read", (char*) read, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "read32", (char*) read32, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "read32p", (char*) read32p, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "read_all_flag", (char*) &read_all_flag, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "readdir", (char*) readdir, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "readdir_r", (char*) readdir_r, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "readv", (char*) readv, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "readyQBMap", (char*) &readyQBMap, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "readyQHead", (char*) &readyQHead, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "realloc", (char*) realloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "reboot", (char*) reboot, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "reboot2", (char*) reboot2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "reboot3", (char*) reboot3, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "reboot4", (char*) reboot4, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "rebootHookAdd", (char*) rebootHookAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "rebootHookDelete", (char*) rebootHookDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "rebootHookTbl", (char*) &rebootHookTbl, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "rebootHookTblSize", (char*) &rebootHookTblSize, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "recv", (char*) recv, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "recvfrom", (char*) recvfrom, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "recvmsg", (char*) recvmsg, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "regprint", (char*) regprint, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "reld", (char*) reld, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "remCurIdGet", (char*) remCurIdGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "remCurIdSet", (char*) remCurIdSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "remLastResvPort", (char*) &remLastResvPort, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "remLibInit", (char*) remLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "remNumConnRetrials", (char*) &remNumConnRetrials, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "remPasswd", (char*) &remPasswd, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "remStdErrSetupTimeout", (char*) &remStdErrSetupTimeout, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "remUser", (char*) &remUser, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "remove", (char*) remove, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "rename", (char*) rename, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "repeat", (char*) repeat, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "repeatHost", (char*) repeatHost, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "repeatRun", (char*) repeatRun, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "reschedule", (char*) reschedule, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "restartTaskName", (char*) &restartTaskName, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "restartTaskOptions", (char*) &restartTaskOptions, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "restartTaskPriority", (char*) &restartTaskPriority, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "restartTaskStackSize", (char*) &restartTaskStackSize, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "retran_noprs", (char*) &retran_noprs, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "retran_notmr", (char*) &retran_notmr, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "rewind", (char*) rewind, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "rewinddir", (char*) rewinddir, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "rindex", (char*) rindex, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ring_buffer_dequeue", (char*) ring_buffer_dequeue, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ring_buffer_dequeue_arr", (char*) ring_buffer_dequeue_arr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ring_buffer_init", (char*) ring_buffer_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ring_buffer_peek", (char*) ring_buffer_peek, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ring_buffer_queue", (char*) ring_buffer_queue, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ring_buffer_queue_arr", (char*) ring_buffer_queue_arr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "rm", (char*) rm, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "rmdir", (char*) rmdir, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "rngBufGet", (char*) rngBufGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "rngBufPut", (char*) rngBufPut, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "rngCreate", (char*) rngCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "rngDelete", (char*) rngDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "rngFlush", (char*) rngFlush, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "rngFreeBytes", (char*) rngFreeBytes, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "rngIsEmpty", (char*) rngIsEmpty, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "rngIsFull", (char*) rngIsFull, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "rngMoveAhead", (char*) rngMoveAhead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "rngNBytes", (char*) rngNBytes, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "rngPutAhead", (char*) rngPutAhead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "rootMemNBytes", (char*) &rootMemNBytes, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "rootTaskId", (char*) &rootTaskId, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "roundRobinHookInstalled", (char*) &roundRobinHookInstalled, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "roundRobinOn", (char*) &roundRobinOn, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "roundRobinSlice", (char*) &roundRobinSlice, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "rresvport", (char*) rresvport, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "rresvportCommon", (char*) rresvportCommon, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "rresvport_af", (char*) rresvport_af, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "rtpCodeSize", (char*) &rtpCodeSize, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "rtpCodeStart", (char*) &rtpCodeStart, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "rtpDeleteMsg", (char*) &rtpDeleteMsg, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "rtpSigDeleteMsg", (char*) &rtpSigDeleteMsg, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "rtpSigStopMsg", (char*) &rtpSigStopMsg, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "rtpStopMsg", (char*) &rtpStopMsg, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "runtimeName", (char*) &runtimeName, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "runtimeVersion", (char*) &runtimeVersion, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "runtimeVersionFull", (char*) &runtimeVersionFull, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "s", (char*) s, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "scalbn", (char*) scalbn, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "scanCharSet", (char*) scanCharSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "scanField", (char*) scanField, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "scanf", (char*) scanf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdACmdClrCardDetect", (char*) sdACmdClrCardDetect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdACmdSendOpCond", (char*) sdACmdSendOpCond, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdACmdSendScr", (char*) sdACmdSendScr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdACmdSendSsr", (char*) sdACmdSendSsr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdACmdSetBusWidth", (char*) sdACmdSetBusWidth, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdACmdSwitchFunc", (char*) sdACmdSwitchFunc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdBusAnnounceDevices", (char*) sdBusAnnounceDevices, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdBusCtlrInterruptInfo_desc", (char*) &sdBusCtlrInterruptInfo_desc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "sdCmdAllSendCid", (char*) sdCmdAllSendCid, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdCmdAppCmd", (char*) sdCmdAppCmd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdCmdDeselectCard", (char*) sdCmdDeselectCard, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdCmdGoIdleState", (char*) sdCmdGoIdleState, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdCmdGoInactiveState", (char*) sdCmdGoInactiveState, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdCmdIssue", (char*) sdCmdIssue, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdCmdReadBlock", (char*) sdCmdReadBlock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdCmdReadMultipleBlock", (char*) sdCmdReadMultipleBlock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdCmdReadSingleBlock", (char*) sdCmdReadSingleBlock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdCmdSelectCard", (char*) sdCmdSelectCard, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdCmdSendCid", (char*) sdCmdSendCid, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdCmdSendCsd", (char*) sdCmdSendCsd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdCmdSendIfCond", (char*) sdCmdSendIfCond, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdCmdSendRelativeAddr", (char*) sdCmdSendRelativeAddr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdCmdSendStatus", (char*) sdCmdSendStatus, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdCmdSetBlockLen", (char*) sdCmdSetBlockLen, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdCmdSetDsr", (char*) sdCmdSetDsr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdCmdStopTransmission", (char*) sdCmdStopTransmission, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdCmdSwitchVoltage", (char*) sdCmdSwitchVoltage, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdCmdWriteBlock", (char*) sdCmdWriteBlock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdCmdWriteMultipleBlock", (char*) sdCmdWriteMultipleBlock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdCmdWriteSingleBlock", (char*) sdCmdWriteSingleBlock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdMmcCmdSendOpCond", (char*) sdMmcCmdSendOpCond, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdMmcCmdSetRelativeAddr", (char*) sdMmcCmdSetRelativeAddr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdRegister", (char*) sdRegister, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdhcDbgMask", (char*) &sdhcDbgMask, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "sdioCmdIoRwDirect", (char*) sdioCmdIoRwDirect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdioCmdIoRwExtend", (char*) sdioCmdIoRwExtend, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdioCmdIoSendOpCond", (char*) sdioCmdIoSendOpCond, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdmmc_get_baseAddr", (char*) sdmmc_get_baseAddr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sdmmc_res_len", (char*) &sdmmc_res_len, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "sectorChecksum", (char*) sectorChecksum, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sectorChecksumWrite", (char*) sectorChecksumWrite, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "selNodeAdd", (char*) selNodeAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "selNodeDelete", (char*) selNodeDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "selTaskDeleteHookAdd", (char*) selTaskDeleteHookAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "selWakeup", (char*) selWakeup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "selWakeupAll", (char*) selWakeupAll, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "selWakeupListInit", (char*) selWakeupListInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "selWakeupListLen", (char*) selWakeupListLen, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "selWakeupListTerm", (char*) selWakeupListTerm, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "selWakeupType", (char*) selWakeupType, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "select", (char*) select, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "selectInit", (char*) selectInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semBCreate", (char*) semBCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semBGive", (char*) semBGive, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semBGiveDefer", (char*) semBGiveDefer, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semBGiveNoLock", (char*) semBGiveNoLock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semBGiveScalable", (char*) semBGiveScalable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semBInit", (char*) semBInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semBInitialize", (char*) semBInitialize, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semBTake", (char*) semBTake, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semBTakeNoLock", (char*) semBTakeNoLock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semBTakeScalable", (char*) semBTakeScalable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semCCreate", (char*) semCCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semCGive", (char*) semCGive, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semCGiveDefer", (char*) semCGiveDefer, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semCInit", (char*) semCInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semCInitialize", (char*) semCInitialize, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semCTake", (char*) semCTake, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semClass", (char*) &semClass, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "semClassId", (char*) &semClassId, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "semCreateTbl", (char*) &semCreateTbl, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "semDelete", (char*) semDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semDeleteLibInit", (char*) semDeleteLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semDestroy", (char*) semDestroy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semEvIsFreeTbl", (char*) &semEvIsFreeTbl, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "semEvStart", (char*) semEvStart, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semEvStop", (char*) semEvStop, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semFlush", (char*) semFlush, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semFlushDefer", (char*) semFlushDefer, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semFlushDeferTbl", (char*) &semFlushDeferTbl, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "semFlushTbl", (char*) &semFlushTbl, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "semGive", (char*) semGive, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semGiveDefer", (char*) semGiveDefer, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semGiveDeferTbl", (char*) &semGiveDeferTbl, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "semGiveNoLockTbl", (char*) &semGiveNoLockTbl, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "semGiveTbl", (char*) &semGiveTbl, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "semInfo", (char*) semInfo, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semInfoGet", (char*) semInfoGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semIntRestrict", (char*) semIntRestrict, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semInvalid", (char*) semInvalid, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semLibInit", (char*) semLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semLocalIdVerify", (char*) semLocalIdVerify, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semMCreate", (char*) semMCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semMGive", (char*) semMGive, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semMGiveForce", (char*) semMGiveForce, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semMGiveKernWork", (char*) semMGiveKernWork, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semMGiveNoLock", (char*) semMGiveNoLock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semMGiveScalable", (char*) semMGiveScalable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semMInit", (char*) semMInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semMInitialize", (char*) semMInitialize, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semMPendQPut", (char*) semMPendQPut, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semMTake", (char*) semMTake, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semMTakeByProxy", (char*) semMTakeByProxy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semMTakeNoLock", (char*) semMTakeNoLock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semMTakeScalable", (char*) semMTakeScalable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semQFlush", (char*) semQFlush, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semQFlushDefer", (char*) semQFlushDefer, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semQInit", (char*) semQInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semRTake", (char*) semRTake, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semRWCreate", (char*) semRWCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semRWGive", (char*) semRWGive, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semRWGiveForce", (char*) semRWGiveForce, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semRWInitialize", (char*) semRWInitialize, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semRWLibMaxReaders", (char*) &semRWLibMaxReaders, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "semShow", (char*) semShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semShowInit", (char*) semShowInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semSync_mmc", (char*) &semSync_mmc, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "semTake", (char*) semTake, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semTakeNoLockTbl", (char*) &semTakeNoLockTbl, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "semTakeTbl", (char*) &semTakeTbl, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "semTerminate", (char*) semTerminate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "semWTake", (char*) semWTake, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "send", (char*) send, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "send_full", (char*) &send_full, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "send_xon_xoff_char", (char*) send_xon_xoff_char, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sendmsg", (char*) sendmsg, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sendto", (char*) sendto, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "setAlt", (char*) setAlt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "setFpt", (char*) setFpt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "setbuf", (char*) setbuf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "setbuffer", (char*) setbuffer, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sethostname", (char*) sethostname, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "setjmp", (char*) setjmp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "setlinebuf", (char*) setlinebuf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "setlocale", (char*) setlocale, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "setsockopt", (char*) setsockopt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "settimeofday", (char*) settimeofday, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "setvbuf", (char*) setvbuf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sfpDoubleNormalize", (char*) sfpDoubleNormalize, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sfpDoubleNormalize2", (char*) sfpDoubleNormalize2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sfpDoubleSetup", (char*) sfpDoubleSetup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sfpFloatNormalize", (char*) sfpFloatNormalize, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sfpFloatSetup", (char*) sfpFloatSetup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shConfig", (char*) shConfig, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sha1_block_data_order", (char*) sha1_block_data_order, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sha1_block_host_order", (char*) sha1_block_host_order, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sha256_block_data_order", (char*) sha256_block_data_order, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sha256_block_host_order", (char*) sha256_block_host_order, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellAbort", (char*) shellAbort, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellAbortHandledByShell", (char*) shellAbortHandledByShell, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellActivate", (char*) shellActivate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellBackgroundInit", (char*) shellBackgroundInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellBackgroundRead", (char*) shellBackgroundRead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellCmdAdd", (char*) shellCmdAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellCmdAliasAdd", (char*) shellCmdAliasAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellCmdAliasArrayAdd", (char*) shellCmdAliasArrayAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellCmdAliasDelete", (char*) shellCmdAliasDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellCmdAliasShow", (char*) shellCmdAliasShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellCmdArrayAdd", (char*) shellCmdArrayAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellCmdCheck", (char*) shellCmdCheck, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellCmdExec", (char*) shellCmdExec, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellCmdInfoArgsStore", (char*) shellCmdInfoArgsStore, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellCmdInfoCmdLineStore", (char*) shellCmdInfoCmdLineStore, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellCmdInfoFinalNameStore", (char*) shellCmdInfoFinalNameStore, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellCmdInfoGet", (char*) shellCmdInfoGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellCmdInfoInitialNameStore", (char*) shellCmdInfoInitialNameStore, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellCmdInit", (char*) shellCmdInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellCmdMatchingAliasListGet", (char*) shellCmdMatchingAliasListGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellCmdMatchingCmdListGet", (char*) shellCmdMatchingCmdListGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellCmdMemRegister", (char*) shellCmdMemRegister, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellCmdMemUnregister", (char*) shellCmdMemUnregister, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellCmdPreParseAdd", (char*) shellCmdPreParseAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellCmdPreParsedGet", (char*) shellCmdPreParsedGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellCmdStatementExec", (char*) shellCmdStatementExec, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellCmdStatementSplit", (char*) shellCmdStatementSplit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellCmdSymTabIdGet", (char*) shellCmdSymTabIdGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellCmdTaskIdConvert", (char*) shellCmdTaskIdConvert, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellCmdTopicAdd", (char*) shellCmdTopicAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellCompatibleCheck", (char*) shellCompatibleCheck, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellCompatibleSet", (char*) shellCompatibleSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellCompletionPathnameGet", (char*) shellCompletionPathnameGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellConfigDefaultGet", (char*) shellConfigDefaultGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellConfigDefaultSet", (char*) shellConfigDefaultSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellConfigDefaultValueGet", (char*) shellConfigDefaultValueGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellConfigDefaultValueSet", (char*) shellConfigDefaultValueSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellConfigDefaultValueUnset", (char*) shellConfigDefaultValueUnset, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellConfigGet", (char*) shellConfigGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellConfigLibInit", (char*) shellConfigLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellConfigSet", (char*) shellConfigSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellConfigValueGet", (char*) shellConfigValueGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellConfigValueSet", (char*) shellConfigValueSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellConfigValueUnset", (char*) shellConfigValueUnset, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellConsoleInit", (char*) shellConsoleInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellConsoleTaskId", (char*) &shellConsoleTaskId, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "shellContextFinalize", (char*) shellContextFinalize, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellContextInit", (char*) shellContextInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellContextListLock", (char*) shellContextListLock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellContextListUnlock", (char*) shellContextListUnlock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellDataAdd", (char*) shellDataAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellDataAllRemove", (char*) shellDataAllRemove, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellDataFirst", (char*) shellDataFirst, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellDataFromNameAdd", (char*) shellDataFromNameAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellDataFromNameGet", (char*) shellDataFromNameGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellDataGet", (char*) shellDataGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellDataNext", (char*) shellDataNext, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellDataRemove", (char*) shellDataRemove, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellErrnoGet", (char*) shellErrnoGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellErrnoSet", (char*) shellErrnoSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellExec", (char*) shellExec, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellExitWrapper", (char*) shellExitWrapper, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellFirst", (char*) shellFirst, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellFromNameGet", (char*) shellFromNameGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellFromTaskGet", (char*) shellFromTaskGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellFromTaskParentContextGet", (char*) shellFromTaskParentContextGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellGenericCreate", (char*) shellGenericCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellGenericInit", (char*) shellGenericInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellHistory", (char*) shellHistory, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellIOStdGet", (char*) shellIOStdGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellIOStdSet", (char*) shellIOStdSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellIdVerify", (char*) shellIdVerify, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInOutBgndClose", (char*) shellInOutBgndClose, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInOutBgndGet", (char*) shellInOutBgndGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInOutBgndIoClose", (char*) shellInOutBgndIoClose, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInOutBgndOpen", (char*) shellInOutBgndOpen, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInOutBgndRegister", (char*) shellInOutBgndRegister, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInOutBlockingBlock", (char*) shellInOutBlockingBlock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInOutBlockingBlockedDataGet", (char*) shellInOutBlockingBlockedDataGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInOutBlockingClose", (char*) shellInOutBlockingClose, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInOutBlockingDataSet", (char*) shellInOutBlockingDataSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInOutBlockingGet", (char*) shellInOutBlockingGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInOutBlockingOnDataClose", (char*) shellInOutBlockingOnDataClose, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInOutBlockingOpen", (char*) shellInOutBlockingOpen, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInOutBlockingUnblock", (char*) shellInOutBlockingUnblock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInOutInitialGet", (char*) shellInOutInitialGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInOutInputHookAdd", (char*) shellInOutInputHookAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInOutInputHookDelete", (char*) shellInOutInputHookDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInOutInputHookSet", (char*) shellInOutInputHookSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInOutInputHookUnset", (char*) shellInOutInputHookUnset, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInOutInputUniqueCheck", (char*) shellInOutInputUniqueCheck, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInOutMasterPtyGet", (char*) shellInOutMasterPtyGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInOutRedirectClose", (char*) shellInOutRedirectClose, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInOutRedirectOpen", (char*) shellInOutRedirectOpen, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInOutRedirectRestore", (char*) shellInOutRedirectRestore, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInOutRedirectScript", (char*) shellInOutRedirectScript, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInOutRedirectSet", (char*) shellInOutRedirectSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInOutSet", (char*) shellInOutSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInOutSlavePtyGet", (char*) shellInOutSlavePtyGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInOutUse", (char*) shellInOutUse, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInternalArgStackAllocate", (char*) shellInternalArgStackAllocate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInternalArgumentEval", (char*) shellInternalArgumentEval, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInternalDataSymbolGet", (char*) shellInternalDataSymbolGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInternalDecValueDisplay", (char*) shellInternalDecValueDisplay, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInternalFuncDoubleArgAdd", (char*) shellInternalFuncDoubleArgAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInternalFuncFloatArgAdd", (char*) shellInternalFuncFloatArgAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInternalFuncLLongArgAdd", (char*) shellInternalFuncLLongArgAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInternalFuncLongArgAdd", (char*) shellInternalFuncLongArgAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInternalFunctionCall", (char*) shellInternalFunctionCall, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInternalHexValueDisplay", (char*) shellInternalHexValueDisplay, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInternalKernelSymbolCreate", (char*) shellInternalKernelSymbolCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInternalOptFree", (char*) shellInternalOptFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInternalOptGet", (char*) shellInternalOptGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInternalStrSpaceTokenize", (char*) shellInternalStrSpaceTokenize, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInternalStrToChar", (char*) shellInternalStrToChar, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInternalStrToFloat", (char*) shellInternalStrToFloat, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInternalStrToInt", (char*) shellInternalStrToInt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInternalStrToInt2", (char*) shellInternalStrToInt2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInternalStrToInt32", (char*) shellInternalStrToInt32, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInternalStrToLong", (char*) shellInternalStrToLong, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInternalStrTokenize", (char*) shellInternalStrTokenize, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInternalStrUnquote", (char*) shellInternalStrUnquote, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInternalSymTblFromRtpGet", (char*) shellInternalSymTblFromRtpGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInternalSymTblFromTaskGet", (char*) shellInternalSymTblFromTaskGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInternalSymbolDisplay", (char*) shellInternalSymbolDisplay, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInternalSymbolGet", (char*) shellInternalSymbolGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInternalSymbolsResolve", (char*) shellInternalSymbolsResolve, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInternalTaskNameMatch", (char*) shellInternalTaskNameMatch, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInternalTextSymbolGet", (char*) shellInternalTextSymbolGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInternalValueDisplay", (char*) shellInternalValueDisplay, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInterpByNameFind", (char*) shellInterpByNameFind, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInterpCInit", (char*) shellInterpCInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInterpC_create_buffer", (char*) shellInterpC_create_buffer, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInterpC_delete_buffer", (char*) shellInterpC_delete_buffer, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInterpC_flush_buffer", (char*) shellInterpC_flush_buffer, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInterpC_init_buffer", (char*) shellInterpC_init_buffer, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInterpC_load_buffer_state", (char*) shellInterpC_load_buffer_state, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInterpC_scan_buffer", (char*) shellInterpC_scan_buffer, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInterpC_scan_bytes", (char*) shellInterpC_scan_bytes, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInterpC_scan_string", (char*) shellInterpC_scan_string, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInterpC_switch_to_buffer", (char*) shellInterpC_switch_to_buffer, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInterpCin", (char*) &shellInterpCin, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "shellInterpCleng", (char*) &shellInterpCleng, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "shellInterpClex", (char*) shellInterpClex, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInterpCmdInit", (char*) shellInterpCmdInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInterpCmdLibInit", (char*) shellInterpCmdLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInterpCout", (char*) &shellInterpCout, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "shellInterpCparse", (char*) shellInterpCparse, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInterpCrestart", (char*) shellInterpCrestart, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInterpCtext", (char*) &shellInterpCtext, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "shellInterpCtxCreate", (char*) shellInterpCtxCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInterpCtxGet", (char*) shellInterpCtxGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInterpDefaultNameGet", (char*) shellInterpDefaultNameGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInterpDelete", (char*) shellInterpDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInterpEvaluate", (char*) shellInterpEvaluate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInterpLibInit", (char*) shellInterpLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInterpNameGet", (char*) shellInterpNameGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInterpPromptDftSet", (char*) shellInterpPromptDftSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInterpPromptGet", (char*) shellInterpPromptGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInterpPromptSet", (char*) shellInterpPromptSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInterpRegister", (char*) shellInterpRegister, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInterpRestart", (char*) shellInterpRestart, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInterpSet", (char*) shellInterpSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellInterpSwitch", (char*) shellInterpSwitch, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellLibInit", (char*) shellLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellLineLenGet", (char*) shellLineLenGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellLock", (char*) shellLock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellLoginInstall", (char*) shellLoginInstall, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellLogout", (char*) shellLogout, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellLogout2", (char*) shellLogout2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellLogoutInstall", (char*) shellLogoutInstall, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellMaxSessionsSet", (char*) shellMaxSessionsSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellMemAllRegFree", (char*) shellMemAllRegFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellMemCalloc", (char*) shellMemCalloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellMemFree", (char*) shellMemFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellMemLibInit", (char*) shellMemLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellMemMalloc", (char*) shellMemMalloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellMemRealloc", (char*) shellMemRealloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellMemRegAllFree", (char*) shellMemRegAllFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellMemRegFree", (char*) shellMemRegFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellMemRegMalloc", (char*) shellMemRegMalloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellMemRegister", (char*) shellMemRegister, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellMemStrdup", (char*) shellMemStrdup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellMemStringAdd", (char*) shellMemStringAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellMemStringFree", (char*) shellMemStringFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellMemStringIsAllocated", (char*) shellMemStringIsAllocated, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellMemStringShow", (char*) shellMemStringShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellMemUnregister", (char*) shellMemUnregister, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellNext", (char*) shellNext, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellOutputLock", (char*) shellOutputLock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellOutputUnlock", (char*) shellOutputUnlock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellParserControl", (char*) shellParserControl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellPrint", (char*) shellPrint, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellPrintErr", (char*) shellPrintErr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellPromptFmtDftSet", (char*) shellPromptFmtDftSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellPromptFmtSet", (char*) shellPromptFmtSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellPromptFmtStrAdd", (char*) shellPromptFmtStrAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellPromptLibInit", (char*) shellPromptLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellPromptPrint", (char*) shellPromptPrint, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellPromptSet", (char*) shellPromptSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellRemoteConfigStr", (char*) &shellRemoteConfigStr, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "shellResourceReleaseHookAdd", (char*) shellResourceReleaseHookAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellRestart", (char*) shellRestart, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellScriptAbort", (char*) shellScriptAbort, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellScriptNoAbort", (char*) shellScriptNoAbort, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellTask", (char*) shellTask, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellTaskDefaultBaseNameGet", (char*) shellTaskDefaultBaseNameGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellTaskDefaultBaseNameSet", (char*) shellTaskDefaultBaseNameSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellTaskDefaultOptionsGet", (char*) shellTaskDefaultOptionsGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellTaskDefaultOptionsSet", (char*) shellTaskDefaultOptionsSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellTaskDefaultPriorityGet", (char*) shellTaskDefaultPriorityGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellTaskDefaultPrioritySet", (char*) shellTaskDefaultPrioritySet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellTaskDefaultStackSizeGet", (char*) shellTaskDefaultStackSizeGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellTaskDefaultStackSizeSet", (char*) shellTaskDefaultStackSizeSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellTaskGet", (char*) shellTaskGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellTaskIdDefault", (char*) shellTaskIdDefault, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellTerminate", (char*) shellTerminate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellWorkingMemCtxAttach", (char*) shellWorkingMemCtxAttach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellWorkingMemCtxAttachedShow", (char*) shellWorkingMemCtxAttachedShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellWorkingMemCtxCurrentGet", (char*) shellWorkingMemCtxCurrentGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellWorkingMemCtxCurrentSet", (char*) shellWorkingMemCtxCurrentSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellWorkingMemCtxDetach", (char*) shellWorkingMemCtxDetach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellWorkingMemCtxDuplicate", (char*) shellWorkingMemCtxDuplicate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellWorkingMemCtxGet", (char*) shellWorkingMemCtxGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellWorkingMemCtxIdConvert", (char*) shellWorkingMemCtxIdConvert, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellWorkingMemCtxLastGet", (char*) shellWorkingMemCtxLastGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shellWorkingMemCtxRtnSet", (char*) shellWorkingMemCtxRtnSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "show", (char*) show, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "showLoggerInfo", (char*) showLoggerInfo, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "shutdown", (char*) shutdown, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sigEvtRtn", (char*) &sigEvtRtn, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "sigInit", (char*) sigInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sigPendDestroy", (char*) sigPendDestroy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sigPendInit", (char*) sigPendInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sigPendKill", (char*) sigPendKill, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sigaction", (char*) sigaction, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sigaddset", (char*) sigaddset, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sigblock", (char*) sigblock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sigdelset", (char*) sigdelset, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sigemptyset", (char*) sigemptyset, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sigeventCreate", (char*) sigeventCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sigeventDelete", (char*) sigeventDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sigeventInit", (char*) sigeventInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sigeventLibInit", (char*) sigeventLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sigeventNotify", (char*) sigeventNotify, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sigeventSigOverrunGet", (char*) sigeventSigOverrunGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sigfillset", (char*) sigfillset, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sigismember", (char*) sigismember, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "signal", (char*) signal, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sigpending", (char*) sigpending, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sigprocmask", (char*) sigprocmask, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sigqueue", (char*) sigqueue, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sigqueueInit", (char*) sigqueueInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sigreturn", (char*) sigreturn, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sigsetjmp", (char*) sigsetjmp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sigsetmask", (char*) sigsetmask, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sigsuspend", (char*) sigsuspend, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sigtimedwait", (char*) sigtimedwait, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sigvec", (char*) sigvec, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sigwait", (char*) sigwait, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sigwaitinfo", (char*) sigwaitinfo, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sin", (char*) sin, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sinh", (char*) sinh, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sioChanConnect_desc", (char*) &sioChanConnect_desc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "sioChanGet_desc", (char*) &sioChanGet_desc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "sioEnable_desc", (char*) &sioEnable_desc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "sioIntEnable_desc", (char*) &sioIntEnable_desc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "sioNextChannelNumberAssign", (char*) sioNextChannelNumberAssign, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sizeNodesAlloc", (char*) sizeNodesAlloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "slcrRegs_Config", (char*) slcrRegs_Config, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "slcr_DisableCAN", (char*) slcr_DisableCAN, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "slcr_EnableCAN", (char*) slcr_EnableCAN, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "slcr_ResetCAN", (char*) slcr_ResetCAN, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "slcr_gem_reset", (char*) slcr_gem_reset, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "slcr_read", (char*) slcr_read, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "slcr_show", (char*) slcr_show, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "slcr_write", (char*) slcr_write, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sleep", (char*) sleep, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sllCount", (char*) sllCount, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sllEach", (char*) sllEach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sllGet", (char*) sllGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sllInit", (char*) sllInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sllPrevious", (char*) sllPrevious, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sllPutAtHead", (char*) sllPutAtHead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sllPutAtTail", (char*) sllPutAtTail, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sllRemove", (char*) sllRemove, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sllTerminate", (char*) sllTerminate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "smObjPoolMinusOne", (char*) &smObjPoolMinusOne, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "smObjTaskDeleteFailRtn", (char*) &smObjTaskDeleteFailRtn, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "smObjTcbFreeFailRtn", (char*) &smObjTcbFreeFailRtn, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "smObjTcbFreeRtn", (char*) &smObjTcbFreeRtn, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "snprintf", (char*) snprintf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "so", (char*) so, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sockInfo", (char*) sockInfo, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sockLibAdd", (char*) sockLibAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sockLibInit", (char*) sockLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sockLibMap", (char*) &sockLibMap, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "sockShow", (char*) sockShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "socket", (char*) socket, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "socketDevHdr", (char*) &socketDevHdr, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "socket_send_to_middle", (char*) socket_send_to_middle, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sp", (char*) sp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spTaskOptions", (char*) &spTaskOptions, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "spTaskPriority", (char*) &spTaskPriority, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "spTaskStackSize", (char*) &spTaskStackSize, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "spiCtrl_DisIRQ", (char*) spiCtrl_DisIRQ, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spiCtrl_Disable", (char*) spiCtrl_Disable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spiCtrl_Enable", (char*) spiCtrl_Enable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spiCtrl_IP_Loop", (char*) spiCtrl_IP_Loop, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spiCtrl_Init_Master", (char*) spiCtrl_Init_Master, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spiCtrl_Init_Slave", (char*) spiCtrl_Init_Slave, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spiCtrl_RcvFifo_Poll", (char*) spiCtrl_RcvFifo_Poll, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spiCtrl_Rd_CfgReg32", (char*) spiCtrl_Rd_CfgReg32, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spiCtrl_Reset", (char*) spiCtrl_Reset, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spiCtrl_SLCR_Loop", (char*) spiCtrl_SLCR_Loop, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spiCtrl_Set_Baud_Mst", (char*) spiCtrl_Set_Baud_Mst, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spiCtrl_Set_DMARxLvl", (char*) spiCtrl_Set_DMARxLvl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spiCtrl_Set_DMATxLvl", (char*) spiCtrl_Set_DMATxLvl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spiCtrl_Set_FrmLen", (char*) spiCtrl_Set_FrmLen, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spiCtrl_Set_LoopBack", (char*) spiCtrl_Set_LoopBack, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spiCtrl_Set_Master", (char*) spiCtrl_Set_Master, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spiCtrl_Set_PeerSlave", (char*) spiCtrl_Set_PeerSlave, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spiCtrl_Set_RcvFrmNum", (char*) spiCtrl_Set_RcvFrmNum, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spiCtrl_Set_RxFifoFullLvl", (char*) spiCtrl_Set_RxFifoFullLvl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spiCtrl_Set_SckMode", (char*) spiCtrl_Set_SckMode, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spiCtrl_Set_Slave", (char*) spiCtrl_Set_Slave, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spiCtrl_Set_TxFiFoEmptyLvl", (char*) spiCtrl_Set_TxFiFoEmptyLvl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spiCtrl_Set_XfrMode", (char*) spiCtrl_Set_XfrMode, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spiCtrl_Set_enSlvTxd", (char*) spiCtrl_Set_enSlvTxd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spiCtrl_SndFifo_Poll", (char*) spiCtrl_SndFifo_Poll, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spiCtrl_Wr_CfgReg32", (char*) spiCtrl_Wr_CfgReg32, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spiCtrl_X_Loop", (char*) spiCtrl_X_Loop, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spiSlcr_Set_SpiClk", (char*) spiSlcr_Set_SpiClk, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spiSlcr_Set_SpiLoop", (char*) spiSlcr_Set_SpiLoop, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spinLockIsrGive", (char*) spinLockIsrGive, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spinLockIsrInit", (char*) spinLockIsrInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spinLockIsrTake", (char*) spinLockIsrTake, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spinLockRestrict", (char*) spinLockRestrict, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spinLockTaskGive", (char*) spinLockTaskGive, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spinLockTaskInit", (char*) spinLockTaskInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spinLockTaskTake", (char*) spinLockTaskTake, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sprintf", (char*) sprintf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spy", (char*) spy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spyClkStart", (char*) spyClkStart, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spyClkStop", (char*) spyClkStop, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spyHelp", (char*) spyHelp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spyReport", (char*) spyReport, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spyStop", (char*) spyStop, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "spyTask", (char*) spyTask, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sqrt", (char*) sqrt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "srand", (char*) srand, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sscanf", (char*) sscanf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "stat", (char*) stat, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "statSymTbl", (char*) &statSymTbl, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "state_work", (char*) &state_work, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "statfs", (char*) statfs, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "statfs64", (char*) statfs64, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "stdioFp", (char*) stdioFp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "stdioFpCreate", (char*) stdioFpCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "stdioFpDestroy", (char*) stdioFpDestroy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "stdioInit", (char*) stdioInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "stopApplLogger", (char*) stopApplLogger, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "strFree", (char*) strFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "strcasecmp", (char*) strcasecmp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "strcat", (char*) strcat, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "strchr", (char*) strchr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "strcmp", (char*) strcmp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "strcoll", (char*) strcoll, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "strcpy", (char*) strcpy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "strcspn", (char*) strcspn, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "strdup", (char*) strdup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "strerror", (char*) strerror, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "strerrorIf", (char*) strerrorIf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "strerror_r", (char*) strerror_r, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "strftime", (char*) strftime, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "strlcpy", (char*) strlcpy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "strlen", (char*) strlen, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "strncasecmp", (char*) strncasecmp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "strncat", (char*) strncat, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "strncmp", (char*) strncmp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "strncpy", (char*) strncpy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "strpbrk", (char*) strpbrk, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "strrchr", (char*) strrchr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "strspn", (char*) strspn, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "strstr", (char*) strstr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "strtod", (char*) strtod, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "strtok", (char*) strtok, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "strtok_r", (char*) strtok_r, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "strtol", (char*) strtol, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "strtoul", (char*) strtoul, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "strxfrm", (char*) strxfrm, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "substrcmp", (char*) substrcmp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "swab", (char*) swab, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "swap_hex32_2", (char*) swap_hex32_2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "symAdd", (char*) symAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "symByCNameFind", (char*) symByCNameFind, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "symByValueAndTypeFind", (char*) symByValueAndTypeFind, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "symByValueFind", (char*) symByValueFind, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "symEach", (char*) symEach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "symEachCall", (char*) symEachCall, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "symFind", (char*) symFind, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "symFindByName", (char*) symFindByName, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "symFindByNameAndType", (char*) symFindByNameAndType, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "symFindByValue", (char*) symFindByValue, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "symFindByValueAndType", (char*) symFindByValueAndType, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "symFindSymbol", (char*) symFindSymbol, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "symFree", (char*) symFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "symGroupDefault", (char*) &symGroupDefault, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "symLibInit", (char*) symLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "symListGet", (char*) symListGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "symLkupPgSz", (char*) &symLkupPgSz, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "symNameGet", (char*) symNameGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "symRegister", (char*) symRegister, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "symRemove", (char*) symRemove, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "symShellCmdInit", (char*) symShellCmdInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "symShow", (char*) symShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "symShowInit", (char*) symShowInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "symTblAdd", (char*) symTblAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "symTblCreate", (char*) symTblCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "symTblDelete", (char*) symTblDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "symTblRemove", (char*) symTblRemove, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "symTblShutdown", (char*) symTblShutdown, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "symTblSymSetRemove", (char*) symTblSymSetRemove, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "symTypeGet", (char*) symTypeGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "symTypeToStringConvert", (char*) symTypeToStringConvert, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "symValueGet", (char*) symValueGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "syncLoadRtn", (char*) &syncLoadRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "syncSymAddRtn", (char*) &syncSymAddRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "syncSymRemoveRtn", (char*) &syncSymRemoveRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "syncUnldRtn", (char*) &syncUnldRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "sysAbsSymPhysMemBottom", (char*) 0x00100000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "sysAbsSymPhysMemSize", (char*) 0x0ff00000, 0, 0, SYM_GLOBAL | SYM_ABS},
        {{NULL}, "sysAdaEnable", (char*) &sysAdaEnable, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "sysAxiReadLong", (char*) sysAxiReadLong, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysAxiWriteLong", (char*) sysAxiWriteLong, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysBootFile", (char*) &sysBootFile, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "sysBootHost", (char*) &sysBootHost, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "sysBootLine", (char*) &sysBootLine, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "sysBootParams", (char*) &sysBootParams, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "sysBspDevFilter_desc", (char*) &sysBspDevFilter_desc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "sysBspRev", (char*) sysBspRev, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysBus", (char*) &sysBus, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "sysCacheLibInit", (char*) &sysCacheLibInit, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "sysClkConnect", (char*) sysClkConnect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysClkDevUnitNo", (char*) &sysClkDevUnitNo, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "sysClkDisable", (char*) sysClkDisable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysClkEnable", (char*) sysClkEnable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysClkFreqGet", (char*) sysClkFreqGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysClkHandleGet", (char*) sysClkHandleGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysClkInit", (char*) sysClkInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysClkRateGet", (char*) sysClkRateGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysClkRateSet", (char*) sysClkRateSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysClkTimerNo", (char*) &sysClkTimerNo, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "sysCplusEnable", (char*) &sysCplusEnable, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "sysCpu", (char*) &sysCpu, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "sysCpuAvailableGet", (char*) sysCpuAvailableGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysDebugModeGet", (char*) sysDebugModeGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysDebugModeInit", (char*) sysDebugModeInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysDebugModeSet", (char*) sysDebugModeSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysDebugModeSetHookAdd", (char*) sysDebugModeSetHookAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysDebugModeSetHookDelete", (char*) sysDebugModeSetHookDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysDelay", (char*) sysDelay, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysExcMsg", (char*) &sysExcMsg, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "sysFlags", (char*) &sysFlags, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "sysGpioAlloc", (char*) sysGpioAlloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysGpioBankShow", (char*) sysGpioBankShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysGpioCheckValid", (char*) sysGpioCheckValid, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysGpioFree", (char*) sysGpioFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysGpioGetValue", (char*) sysGpioGetValue, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysGpioInit", (char*) sysGpioInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysGpioIntConnect", (char*) sysGpioIntConnect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysGpioIntDisable", (char*) sysGpioIntDisable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysGpioIntDisconnect", (char*) sysGpioIntDisconnect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysGpioIntEnable", (char*) sysGpioIntEnable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysGpioIntTestIrq", (char*) sysGpioIntTestIrq, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysGpioIntTestStart", (char*) sysGpioIntTestStart, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysGpioIntTestStop", (char*) sysGpioIntTestStop, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysGpioIsValid", (char*) sysGpioIsValid, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysGpioIsr", (char*) sysGpioIsr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysGpioLedTest", (char*) sysGpioLedTest, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysGpioSelectInput", (char*) sysGpioSelectInput, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysGpioSelectOutput", (char*) sysGpioSelectOutput, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysGpioSetIrqTrigger", (char*) sysGpioSetIrqTrigger, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysGpioSetValue", (char*) sysGpioSetValue, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysGpioShow", (char*) sysGpioShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysGpioSysIrqConnect", (char*) sysGpioSysIrqConnect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysGpioSysIrqDisconnect", (char*) sysGpioSysIrqDisconnect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysHwInit", (char*) sysHwInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysHwInit0", (char*) sysHwInit0, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysHwInit2", (char*) sysHwInit2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysInByte", (char*) sysInByte, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysInLong", (char*) sysInLong, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysInWord", (char*) sysInWord, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysInit", (char*) sysInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysInstParamTable", (char*) &sysInstParamTable, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "sysIntLvlChgRtn", (char*) &sysIntLvlChgRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "sysIntLvlDisableRtn", (char*) &sysIntLvlDisableRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "sysIntLvlEnableRtn", (char*) &sysIntLvlEnableRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "sysIntLvlVecAckRtn", (char*) &sysIntLvlVecAckRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "sysIntLvlVecChkRtn", (char*) &sysIntLvlVecChkRtn, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "sysL2CacheEnabled", (char*) &sysL2CacheEnabled, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "sysMacIndex2Dev", (char*) sysMacIndex2Dev, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysMacIndex2Unit", (char*) sysMacIndex2Unit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysMacOffsetGet", (char*) sysMacOffsetGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysMemTop", (char*) sysMemTop, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysMmuLibInit", (char*) &sysMmuLibInit, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "sysModel", (char*) sysModel, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysMsDelay", (char*) sysMsDelay, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysMshcClkFreqSetup", (char*) sysMshcClkFreqSetup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysMshcClkFreqSetup_2", (char*) sysMshcClkFreqSetup_2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysMshcClkFreq_Get", (char*) sysMshcClkFreq_Get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysMtdIdentify", (char*) sysMtdIdentify, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysNetDevName", (char*) &sysNetDevName, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "sysNetMacAddrGet", (char*) sysNetMacAddrGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysNetMacAddrSet", (char*) sysNetMacAddrSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysNetMacNVRamAddrGet", (char*) sysNetMacNVRamAddrGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysNvRamGet", (char*) sysNvRamGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysNvRamSet", (char*) sysNvRamSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysOutByte", (char*) sysOutByte, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysOutLong", (char*) sysOutLong, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysOutWord", (char*) sysOutWord, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysPhysMemDesc", (char*) &sysPhysMemDesc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "sysPhysMemDescCortexA8ExtNumEnt", (char*) &sysPhysMemDescCortexA8ExtNumEnt, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "sysPhysMemDescNumEnt", (char*) &sysPhysMemDescNumEnt, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "sysPhysMemTop", (char*) sysPhysMemTop, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysProcNum", (char*) &sysProcNum, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "sysProcNumGet", (char*) sysProcNumGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysProcNumSet", (char*) sysProcNumSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysSdmmcSetup_2", (char*) sysSdmmcSetup_2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysSdmmcSetup_25M", (char*) sysSdmmcSetup_25M, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysSdmmcSetup_50M", (char*) sysSdmmcSetup_50M, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysSdmmcSetup_5M", (char*) sysSdmmcSetup_5M, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysSdmmcSetup_byRate", (char*) sysSdmmcSetup_byRate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysSdmmcSetup_byRate_2", (char*) sysSdmmcSetup_byRate_2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysSerialChanConnect", (char*) sysSerialChanConnect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysSerialChanGet", (char*) sysSerialChanGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysSerialConnectAll", (char*) sysSerialConnectAll, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysStart", (char*) sysStart, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysStartType", (char*) &sysStartType, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "sysSymPhysMemBottom", (char*) &sysSymPhysMemBottom, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "sysSymPhysMemSize", (char*) &sysSymPhysMemSize, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "sysSymTbl", (char*) &sysSymTbl, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "sysTextProtect", (char*) &sysTextProtect, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "sysTffsFormat", (char*) sysTffsFormat, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysTffsProgressCb", (char*) sysTffsProgressCb, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysTimestamp", (char*) sysTimestamp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysTimestampConnect", (char*) sysTimestampConnect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysTimestampDisable", (char*) sysTimestampDisable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysTimestampEnable", (char*) sysTimestampEnable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysTimestampFreq", (char*) sysTimestampFreq, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysTimestampHandleGet", (char*) sysTimestampHandleGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysTimestampLock", (char*) sysTimestampLock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysTimestampPeriod", (char*) sysTimestampPeriod, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysToMonitor", (char*) sysToMonitor, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysUsDelay", (char*) sysUsDelay, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "sysVmContext", (char*) &sysVmContext, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "system", (char*) system, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "systemSecurityIsEnabled", (char*) &systemSecurityIsEnabled, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "tExcTaskExcStk", (char*) &tExcTaskExcStk, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "tExcTaskStk", (char*) &tExcTaskStk, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "tExcTaskTcb", (char*) &tExcTaskTcb, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "tagCheckEvaluateAsserts", (char*) tagCheckEvaluateAsserts, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tagCheckModuleAdd", (char*) tagCheckModuleAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tagCheckModuleDel", (char*) tagCheckModuleDel, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tagCheckStatementAdd", (char*) tagCheckStatementAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taglist", (char*) &taglist, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "tan", (char*) tan, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tanh", (char*) tanh, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskActivate", (char*) taskActivate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskArgsGet", (char*) taskArgsGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskArgsSet", (char*) taskArgsSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskBpHook", (char*) &taskBpHook, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "taskBpHookSet", (char*) taskBpHookSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskClassId", (char*) &taskClassId, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "taskClientCont", (char*) taskClientCont, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskClientStopForce", (char*) taskClientStopForce, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskCont", (char*) taskCont, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskContHookAdd", (char*) taskContHookAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskContHookDelete", (char*) taskContHookDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskContTable", (char*) &taskContTable, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "taskCpuAffinityGet", (char*) taskCpuAffinityGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskCpuAffinitySet", (char*) taskCpuAffinitySet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskCpuLock", (char*) taskCpuLock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskCpuUnlock", (char*) taskCpuUnlock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskCpuUnlockNoResched", (char*) taskCpuUnlockNoResched, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskCreat", (char*) taskCreat, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskCreate", (char*) taskCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskCreateHookAdd", (char*) taskCreateHookAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskCreateHookDelete", (char*) taskCreateHookDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskCreateHookInit", (char*) taskCreateHookInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskCreateHookShow", (char*) taskCreateHookShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskCreateHooks", (char*) &taskCreateHooks, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "taskCreateHooksArrayA", (char*) &taskCreateHooksArrayA, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "taskCreateHooksArrayB", (char*) &taskCreateHooksArrayB, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "taskCreateLibInit", (char*) taskCreateLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskCreateWithGuard", (char*) taskCreateWithGuard, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskDelay", (char*) taskDelay, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskDelete", (char*) taskDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskDeleteForce", (char*) taskDeleteForce, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskDeleteHookAdd", (char*) taskDeleteHookAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskDeleteHookDelete", (char*) taskDeleteHookDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskDeleteHookShow", (char*) taskDeleteHookShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskDeleteHooks", (char*) &taskDeleteHooks, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "taskDeleteHooksArrayA", (char*) &taskDeleteHooksArrayA, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "taskDeleteHooksArrayB", (char*) &taskDeleteHooksArrayB, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "taskDestroy", (char*) taskDestroy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskEach", (char*) taskEach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskExit", (char*) taskExit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskHookShowInit", (char*) taskHookShowInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskIdCurrent", (char*) &taskIdCurrent, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "taskIdDefault", (char*) taskIdDefault, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskIdFigure", (char*) taskIdFigure, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskIdListGet", (char*) taskIdListGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskIdListSort", (char*) taskIdListSort, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskIdSelf", (char*) taskIdSelf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskIdVerify", (char*) taskIdVerify, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskInfoGet", (char*) taskInfoGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskInit", (char*) taskInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskInitExcStk", (char*) taskInitExcStk, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskInitialize", (char*) taskInitialize, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskIsDelayed", (char*) taskIsDelayed, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskIsPended", (char*) taskIsPended, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskIsReady", (char*) taskIsReady, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskIsStopped", (char*) taskIsStopped, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskIsSuspended", (char*) taskIsSuspended, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskKerExcStackSize", (char*) &taskKerExcStackSize, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "taskKerExcStkOverflowSize", (char*) &taskKerExcStkOverflowSize, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "taskKerExecStkOverflowSize", (char*) &taskKerExecStkOverflowSize, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "taskKerExecStkUnderflowSize", (char*) &taskKerExecStkUnderflowSize, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "taskLibInit", (char*) taskLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskLock", (char*) taskLock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskName", (char*) taskName, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskNameToId", (char*) taskNameToId, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskOptionsGet", (char*) taskOptionsGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskOptionsSet", (char*) taskOptionsSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskOptionsString", (char*) taskOptionsString, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskPriNormalGet", (char*) taskPriNormalGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskPriorityGet", (char*) taskPriorityGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskPrioritySet", (char*) taskPrioritySet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskRegName", (char*) &taskRegName, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "taskRegsGet", (char*) taskRegsGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskRegsInit", (char*) taskRegsInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskRegsModify", (char*) taskRegsModify, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskRegsSet", (char*) taskRegsSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskRegsShow", (char*) taskRegsShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskRegsShowOutput", (char*) taskRegsShowOutput, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskReservedFieldGet", (char*) taskReservedFieldGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskReservedFieldSet", (char*) taskReservedFieldSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskReservedNumAllot", (char*) taskReservedNumAllot, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskReset", (char*) taskReset, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskRestart", (char*) taskRestart, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskResume", (char*) taskResume, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskRtnValueSet", (char*) taskRtnValueSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskSafe", (char*) taskSafe, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskSchedInfoGet", (char*) taskSchedInfoGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskShellCmdInit", (char*) taskShellCmdInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskShow", (char*) taskShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskShowInit", (char*) taskShowInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskSpareFieldGet", (char*) taskSpareFieldGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskSpareFieldSet", (char*) taskSpareFieldSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskSpareNumAllot", (char*) taskSpareNumAllot, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskSpawn", (char*) taskSpawn, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskStackAllot", (char*) taskStackAllot, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskStackSizeGet", (char*) taskStackSizeGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskStatusString", (char*) taskStatusString, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskStop", (char*) taskStop, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskStopForce", (char*) taskStopForce, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskStopHookAdd", (char*) taskStopHookAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskStopHookDelete", (char*) taskStopHookDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskStopMsg", (char*) &taskStopMsg, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "taskStopTable", (char*) &taskStopTable, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "taskSuspend", (char*) taskSuspend, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskSwapHookAdd", (char*) taskSwapHookAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskSwapHookAttach", (char*) taskSwapHookAttach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskSwapHookDelete", (char*) taskSwapHookDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskSwapHookDetach", (char*) taskSwapHookDetach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskSwapHookShow", (char*) taskSwapHookShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskSwapReference", (char*) &taskSwapReference, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "taskSwapTable", (char*) &taskSwapTable, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "taskSwitchHookAdd", (char*) taskSwitchHookAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskSwitchHookDelete", (char*) taskSwitchHookDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskSwitchHookShow", (char*) taskSwitchHookShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskSwitchTable", (char*) &taskSwitchTable, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "taskTcb", (char*) taskTcb, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskTerminate", (char*) taskTerminate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskUndelay", (char*) taskUndelay, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskUnlock", (char*) taskUnlock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskUnsafe", (char*) taskUnsafe, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskUnsafeInternal", (char*) taskUnsafeInternal, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskUsrExcStackSize", (char*) &taskUsrExcStackSize, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "taskUsrExcStkOverflowSize", (char*) &taskUsrExcStkOverflowSize, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "taskUsrExecStkOverflowSize", (char*) &taskUsrExecStkOverflowSize, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "taskUsrExecStkUnderflowSize", (char*) &taskUsrExecStkUnderflowSize, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "taskVarAdd", (char*) taskVarAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskVarDelete", (char*) taskVarDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskVarGet", (char*) taskVarGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskVarInfo", (char*) taskVarInfo, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskVarInit", (char*) taskVarInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskVarSet", (char*) taskVarSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskWait", (char*) taskWait, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskWaitShow", (char*) taskWaitShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "taskWaitShowCoreRtn", (char*) taskWaitShowCoreRtn, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "task_com1_rcv", (char*) task_com1_rcv, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tcbReserveBitmap", (char*) &tcbReserveBitmap, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "tcbSpareBitmap", (char*) &tcbSpareBitmap, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "tcp_tmr_string", (char*) &tcp_tmr_string, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "td", (char*) td, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_100us_timer", (char*) test_100us_timer, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_com1_rcv", (char*) test_com1_rcv, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_com1_snd", (char*) test_com1_snd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_dma_1", (char*) test_dma_1, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_dma_2", (char*) test_dma_2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_dmac_init", (char*) test_dmac_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_erase_all_chip", (char*) test_erase_all_chip, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_get_seg", (char*) test_get_seg, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_gpio_button", (char*) test_gpio_button, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_gpio_button_poll", (char*) test_gpio_button_poll, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_gpio_led", (char*) test_gpio_led, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_gpio_read", (char*) test_gpio_read, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_gtc", (char*) test_gtc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_gtc_delay", (char*) test_gtc_delay, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_mmc_rd_file", (char*) test_mmc_rd_file, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_mmc_speed_dosfs", (char*) test_mmc_speed_dosfs, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_mmc_w_r_sects_bare1", (char*) test_mmc_w_r_sects_bare1, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_mmc_w_r_sects_bare1_2", (char*) test_mmc_w_r_sects_bare1_2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_mmc_wr_file", (char*) test_mmc_wr_file, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_phy_reset", (char*) test_phy_reset, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_qspi_erase_sect", (char*) test_qspi_erase_sect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_qspi_rd_file", (char*) test_qspi_rd_file, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_qspi_rd_sect", (char*) test_qspi_rd_sect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_qspi_rd_uboot_env", (char*) test_qspi_rd_uboot_env, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_qspi_wr_file", (char*) test_qspi_wr_file, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_qspi_wr_sect", (char*) test_qspi_wr_sect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_qspiflash_rd_id", (char*) test_qspiflash_rd_id, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_qspiflash_rd_ids", (char*) test_qspiflash_rd_ids, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_rd_ctrl_regs", (char*) test_rd_ctrl_regs, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_rd_quadmode", (char*) test_rd_quadmode, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_rd_sector", (char*) test_rd_sector, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_rd_sector0", (char*) test_rd_sector0, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_rd_sector1", (char*) test_rd_sector1, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_readintMMC", (char*) test_readintMMC, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_sd_speed_dosfs", (char*) test_sd_speed_dosfs, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_sdmmc_init", (char*) test_sdmmc_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_sdmmc_speed_dosfs_2", (char*) test_sdmmc_speed_dosfs_2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_set_3b_addrmode", (char*) test_set_3b_addrmode, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_set_4b_addrmode", (char*) test_set_4b_addrmode, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_set_seg", (char*) test_set_seg, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_spi_loop1", (char*) test_spi_loop1, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_spi_loop2", (char*) test_spi_loop2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_spi_loop3", (char*) test_spi_loop3, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_ttc", (char*) test_ttc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_uart1_put", (char*) test_uart1_put, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_uart1_snd", (char*) test_uart1_snd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_uart2_put", (char*) test_uart2_put, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_usdelay", (char*) test_usdelay, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_wr_sector", (char*) test_wr_sector, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_wr_sector0", (char*) test_wr_sector0, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "test_wr_sector1", (char*) test_wr_sector1, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "testvx_open_bootbin", (char*) testvx_open_bootbin, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "testvx_qspi_all_chip", (char*) testvx_qspi_all_chip, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "testvx_qspi_erase_sect2", (char*) testvx_qspi_erase_sect2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "testvx_qspi_rd_sect2", (char*) testvx_qspi_rd_sect2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "testvx_qspi_rdwr_sects", (char*) testvx_qspi_rdwr_sects, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "testvx_qspi_wr_sect2", (char*) testvx_qspi_wr_sect2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "testvx_update_bit2", (char*) testvx_update_bit2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "testvx_update_bit3", (char*) testvx_update_bit3, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "testvx_update_bit4", (char*) testvx_update_bit4, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "testvx_update_bit_part", (char*) testvx_update_bit_part, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tffsDevCreate", (char*) tffsDevCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tffsDevFormat", (char*) tffsDevFormat, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tffsDevOptionsSet", (char*) tffsDevOptionsSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tffsDevRawSpeedShow", (char*) tffsDevRawSpeedShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tffsDevStatShow", (char*) tffsDevStatShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tffsDiskChangeAnnounce", (char*) tffsDiskChangeAnnounce, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tffsDrv", (char*) tffsDrv, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tffsDrvOptionsSet", (char*) tffsDrvOptionsSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tffsRawio", (char*) tffsRawio, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tffsShow", (char*) tffsShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tffsShowAll", (char*) tffsShowAll, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tffsVolStatInit", (char*) tffsVolStatInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tffsVolStatShow", (char*) tffsVolStatShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tffsWrtLock", (char*) tffsWrtLock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tffsWrtUnlock", (char*) tffsWrtUnlock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tffs_qspiFlashPageWrite", (char*) tffs_qspiFlashPageWrite, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tffs_qspiFlashRead", (char*) tffs_qspiFlashRead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tffs_qspiFlashSectorErase", (char*) tffs_qspiFlashSectorErase, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tffs_qspiFlashSectorErase_Idx", (char*) tffs_qspiFlashSectorErase_Idx, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tffscmpWords", (char*) tffscmpWords, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ti", (char*) ti, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tick64Get", (char*) tick64Get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tick64Set", (char*) tick64Set, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tickAnnounce", (char*) tickAnnounce, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tickAnnounceHookAdd", (char*) tickAnnounceHookAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tickGet", (char*) tickGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tickQHead", (char*) &tickQHead, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "tickSet", (char*) tickSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "time", (char*) time, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "timerClass", (char*) &timerClass, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "timerClassId", (char*) &timerClassId, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "timerLibInit", (char*) timerLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "timerLibLog", (char*) &timerLibLog, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "timerWdHandler", (char*) timerWdHandler, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "timer_cancel", (char*) timer_cancel, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "timer_connect", (char*) timer_connect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "timer_create", (char*) timer_create, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "timer_delete", (char*) timer_delete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "timer_destroy", (char*) timer_destroy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "timer_getoverrun", (char*) timer_getoverrun, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "timer_gettime", (char*) timer_gettime, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "timer_modify", (char*) timer_modify, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "timer_settime", (char*) timer_settime, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "timestampDevUnitNo", (char*) &timestampDevUnitNo, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "timestampTimerNo", (char*) &timestampTimerNo, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "timex", (char*) timex, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "timexClear", (char*) timexClear, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "timexFunc", (char*) timexFunc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "timexHelp", (char*) timexHelp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "timexInit", (char*) timexInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "timexN", (char*) timexN, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "timexPost", (char*) timexPost, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "timexPre", (char*) timexPre, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "timexShow", (char*) timexShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tip", (char*) tip, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tipConfigString", (char*) &tipConfigString, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "tipEscapeChar", (char*) &tipEscapeChar, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "tipLibInit", (char*) tipLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tipShellCmdInit", (char*) tipShellCmdInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tipStart", (char*) tipStart, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tlTable", (char*) &tlTable, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "tmpfile", (char*) tmpfile, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tmpnam", (char*) tmpnam, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "toUNAL", (char*) toUNAL, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "toUNALLONG", (char*) toUNALLONG, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tolower", (char*) tolower, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "toupper", (char*) toupper, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tr", (char*) tr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "trcDefaultArgs", (char*) &trcDefaultArgs, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "trcLibFuncs", (char*) &trcLibFuncs, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "trcScanDepth", (char*) &trcScanDepth, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "trcStack", (char*) trcStack, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "trcStackCtxTrace", (char*) trcStackCtxTrace, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "trcStackEx", (char*) trcStackEx, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "trcStackTrace", (char*) trcStackTrace, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ts", (char*) ts, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tt", (char*) tt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ttc_init_timer", (char*) ttc_init_timer, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ttc_stop_timer", (char*) ttc_stop_timer, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ttyDevCreate", (char*) ttyDevCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ttyDrv", (char*) ttyDrv, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ttyTester", (char*) ttyTester, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tw", (char*) tw, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tyAbortFuncGet", (char*) tyAbortFuncGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tyAbortFuncSet", (char*) tyAbortFuncSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tyAbortGet", (char*) tyAbortGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tyAbortSet", (char*) tyAbortSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tyBackspaceChar", (char*) &tyBackspaceChar, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "tyBackspaceSet", (char*) tyBackspaceSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tyDeleteLineChar", (char*) &tyDeleteLineChar, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "tyDeleteLineSet", (char*) tyDeleteLineSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tyDevInit", (char*) tyDevInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tyDevRemove", (char*) tyDevRemove, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tyDevTerminate", (char*) tyDevTerminate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tyEOFGet", (char*) tyEOFGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tyEOFSet", (char*) tyEOFSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tyEofChar", (char*) &tyEofChar, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "tyIRd", (char*) tyIRd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tyITx", (char*) tyITx, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tyIoctl", (char*) tyIoctl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tyLibInit", (char*) tyLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tyMonitorTrapSet", (char*) tyMonitorTrapSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tyRead", (char*) tyRead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tyWrite", (char*) tyWrite, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "tyXoffHookSet", (char*) tyXoffHookSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uNum", (char*) &uNum, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "uartBase", (char*) &uartBase, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "uartBase2", (char*) &uartBase2, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "uartCtrl_Disable_Afc", (char*) uartCtrl_Disable_Afc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Disable_Fifos", (char*) uartCtrl_Disable_Fifos, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Disable_Irq", (char*) uartCtrl_Disable_Irq, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Disable_Loopback", (char*) uartCtrl_Disable_Loopback, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Disable_Ptime", (char*) uartCtrl_Disable_Ptime, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Enable_Afc", (char*) uartCtrl_Enable_Afc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Enable_Fifos", (char*) uartCtrl_Enable_Fifos, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Enable_Irq", (char*) uartCtrl_Enable_Irq, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Enable_Loopback", (char*) uartCtrl_Enable_Loopback, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Enable_Ptime", (char*) uartCtrl_Enable_Ptime, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Get_ActiveIrq", (char*) uartCtrl_Get_ActiveIrq, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Get_Break", (char*) uartCtrl_Get_Break, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Get_ClockDivisor", (char*) uartCtrl_Get_ClockDivisor, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Get_DataBits", (char*) uartCtrl_Get_DataBits, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Get_FifoDepth", (char*) uartCtrl_Get_FifoDepth, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Get_IrqMask", (char*) uartCtrl_Get_IrqMask, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Get_LineControl", (char*) uartCtrl_Get_LineControl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Get_LineStatus", (char*) uartCtrl_Get_LineStatus, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Get_ModemLine", (char*) uartCtrl_Get_ModemLine, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Get_ModemStatus", (char*) uartCtrl_Get_ModemStatus, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Get_Parity", (char*) uartCtrl_Get_Parity, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Get_RxFifoLevel", (char*) uartCtrl_Get_RxFifoLevel, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Get_RxTrigger", (char*) uartCtrl_Get_RxTrigger, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Get_Scratchpad", (char*) uartCtrl_Get_Scratchpad, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Get_StopBits", (char*) uartCtrl_Get_StopBits, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Get_TxFifoLevel", (char*) uartCtrl_Get_TxFifoLevel, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Get_TxTrigger", (char*) uartCtrl_Get_TxTrigger, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Is_AfcEnabled", (char*) uartCtrl_Is_AfcEnabled, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Is_Busy", (char*) uartCtrl_Is_Busy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Is_FifosEnabled", (char*) uartCtrl_Is_FifosEnabled, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Is_IrqEnabled", (char*) uartCtrl_Is_IrqEnabled, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Is_LoopbackEnabled", (char*) uartCtrl_Is_LoopbackEnabled, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Is_PtimeEnabled", (char*) uartCtrl_Is_PtimeEnabled, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Is_RxFifoEmpty", (char*) uartCtrl_Is_RxFifoEmpty, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Is_RxFifoFull", (char*) uartCtrl_Is_RxFifoFull, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Is_TxFifoEmpty", (char*) uartCtrl_Is_TxFifoEmpty, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Is_TxFifoFull", (char*) uartCtrl_Is_TxFifoFull, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Rd_CfgReg32", (char*) uartCtrl_Rd_CfgReg32, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Reset", (char*) uartCtrl_Reset, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Rst_RxFifo", (char*) uartCtrl_Rst_RxFifo, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Rst_TxFifo", (char*) uartCtrl_Rst_TxFifo, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Rx_Poll", (char*) uartCtrl_Rx_Poll, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_SLCR_Loop", (char*) uartCtrl_SLCR_Loop, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Set_BaudRate", (char*) uartCtrl_Set_BaudRate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Set_Break", (char*) uartCtrl_Set_Break, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Set_ClockDivisor", (char*) uartCtrl_Set_ClockDivisor, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Set_DataBits", (char*) uartCtrl_Set_DataBits, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Set_LineControl", (char*) uartCtrl_Set_LineControl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Set_ModemLine", (char*) uartCtrl_Set_ModemLine, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Set_Parity", (char*) uartCtrl_Set_Parity, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Set_RxTrigger", (char*) uartCtrl_Set_RxTrigger, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Set_Scratchpad", (char*) uartCtrl_Set_Scratchpad, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Set_Stick", (char*) uartCtrl_Set_Stick, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Set_StopBits", (char*) uartCtrl_Set_StopBits, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Set_TxTrigger", (char*) uartCtrl_Set_TxTrigger, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Tx_Poll", (char*) uartCtrl_Tx_Poll, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_Wr_CfgReg32", (char*) uartCtrl_Wr_CfgReg32, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_autoCompParams", (char*) uartCtrl_autoCompParams, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_burstRead", (char*) uartCtrl_burstRead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_burstWrite", (char*) uartCtrl_burstWrite, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_clearModemLine", (char*) uartCtrl_clearModemLine, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_read", (char*) uartCtrl_read, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartCtrl_write", (char*) uartCtrl_write, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartSetdelay", (char*) uartSetdelay, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uartSlcr_Enable_UartClk", (char*) uartSlcr_Enable_UartClk, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "udpCommIfInit", (char*) udpCommIfInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "udpRcv", (char*) udpRcv, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "ungetc", (char*) ungetc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "unld", (char*) unld, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "unldByGroup", (char*) unldByGroup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "unldByModuleId", (char*) unldByModuleId, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "unldByNameAndPath", (char*) unldByNameAndPath, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "unldExecUsrTerm", (char*) unldExecUsrTerm, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "unldLibInit", (char*) unldLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "unlink", (char*) unlink, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "unloadShellCmdInit", (char*) unloadShellCmdInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "unmount", (char*) unmount, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "upCpuFreq_ARM_PLL", (char*) &upCpuFreq_ARM_PLL, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "usart_close", (char*) usart_close, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usart_report_queue", (char*) usart_report_queue, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usart_set_baudrate", (char*) usart_set_baudrate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usart_set_line_control", (char*) usart_set_line_control, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usart_set_start_break", (char*) usart_set_start_break, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usart_set_stop_break", (char*) usart_set_stop_break, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usart_set_tx_fifo", (char*) usart_set_tx_fifo, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usart_set_xoff", (char*) usart_set_xoff, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usart_set_xon", (char*) usart_set_xon, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usart_set_xon_xoff", (char*) usart_set_xon_xoff, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "userAxiCfgRead", (char*) userAxiCfgRead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "userAxiCfgWrite", (char*) userAxiCfgWrite, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "userCallback", (char*) userCallback, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "userListener", (char*) userListener, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "userRgnPoolId", (char*) &userRgnPoolId, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "user_task_increment_counter", (char*) user_task_increment_counter, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "user_task_print_message", (char*) user_task_print_message, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrAppInit", (char*) usrAppInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrBanner", (char*) usrBanner, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrBootHwInit", (char*) usrBootHwInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrBootLineCrack", (char*) usrBootLineCrack, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrBootLineGet", (char*) usrBootLineGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrBootLineInit", (char*) usrBootLineInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrBootLineParse", (char*) usrBootLineParse, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrBreakpointInit", (char*) usrBreakpointInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrBreakpointSet", (char*) usrBreakpointSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrCacheEnable", (char*) usrCacheEnable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrClock", (char*) usrClock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrDosfsInit", (char*) usrDosfsInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrFsShellCmdInit", (char*) usrFsShellCmdInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrFtpInit", (char*) usrFtpInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrInit", (char*) usrInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrIosCoreInit", (char*) usrIosCoreInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrIosExtraInit", (char*) usrIosExtraInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrIsrDeferInit", (char*) usrIsrDeferInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrKernelCoreInit", (char*) usrKernelCoreInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrKernelCreateInit", (char*) usrKernelCreateInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrKernelExtraInit", (char*) usrKernelExtraInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrKernelInit", (char*) usrKernelInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrLibInit", (char*) usrLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrLoaderInit", (char*) usrLoaderInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrMmuInit", (char*) usrMmuInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrModuleLoad", (char*) usrModuleLoad, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrMuxConfigInit", (char*) usrMuxConfigInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrNetApplUtilInit", (char*) usrNetApplUtilInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrNetBoot", (char*) usrNetBoot, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrNetDaemonInit", (char*) usrNetDaemonInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrNetDevNameGet", (char*) usrNetDevNameGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrNetEndLibInit", (char*) usrNetEndLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrNetHostInit", (char*) usrNetHostInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrNetIfconfigInit", (char*) usrNetIfconfigInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrNetRemoteCreate", (char*) usrNetRemoteCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrNetRemoteInit", (char*) usrNetRemoteInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrNetUtilsInit", (char*) usrNetUtilsInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrNetmaskGet", (char*) usrNetmaskGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrNetworkInit", (char*) usrNetworkInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrRoot", (char*) usrRoot, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrRtpAppInit", (char*) usrRtpAppInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrSerialInit", (char*) usrSerialInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrShell", (char*) usrShell, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrShellCmdInit", (char*) usrShellCmdInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrShellInit", (char*) usrShellInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrShowInit", (char*) usrShowInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrStandaloneInit", (char*) usrStandaloneInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrStat", (char*) &usrStat, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "usrSymLibInit", (char*) usrSymLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrSymTblInit", (char*) usrSymTblInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrSysHwInit2", (char*) usrSysHwInit2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrSysSymTblInit", (char*) usrSysSymTblInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrTffsConfig", (char*) usrTffsConfig, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrTffsLnConfig", (char*) usrTffsLnConfig, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrTipInit", (char*) usrTipInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrToolsInit", (char*) usrToolsInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrVxbTimerSysInit", (char*) usrVxbTimerSysInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrVxdbgInit", (char*) usrVxdbgInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrWdbBanner", (char*) usrWdbBanner, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrWdbBp", (char*) usrWdbBp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrWdbGopherInit", (char*) usrWdbGopherInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrWdbInit", (char*) usrWdbInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrWdbInitDone", (char*) usrWdbInitDone, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "usrWdbTaskModeInit", (char*) usrWdbTaskModeInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uswab", (char*) uswab, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "utime", (char*) utime, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uuidGen", (char*) uuidGen, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uuidStr", (char*) uuidStr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uuid_compare", (char*) uuid_compare, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uuid_create", (char*) uuid_create, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uuid_create_nil", (char*) uuid_create_nil, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uuid_dec_be", (char*) uuid_dec_be, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uuid_dec_le", (char*) uuid_dec_le, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uuid_enc_be", (char*) uuid_enc_be, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uuid_enc_le", (char*) uuid_enc_le, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uuid_equal", (char*) uuid_equal, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uuid_from_string", (char*) uuid_from_string, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uuid_hash", (char*) uuid_hash, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uuid_is_nil", (char*) uuid_is_nil, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uuid_node", (char*) uuid_node, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uuid_time", (char*) uuid_time, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "uuid_to_string", (char*) uuid_to_string, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "valloc", (char*) valloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "version", (char*) version, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vfdprintf", (char*) vfdprintf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vfpArchInit", (char*) vfpArchInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vfpArchTaskCreateInit", (char*) vfpArchTaskCreateInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vfpCtlRegName", (char*) &vfpCtlRegName, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vfpCtxCreate", (char*) vfpCtxCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vfpCtxDelete", (char*) vfpCtxDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vfpCtxShow", (char*) vfpCtxShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vfpCtxToRegs", (char*) vfpCtxToRegs, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vfpDisable", (char*) vfpDisable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vfpDoubleRegName", (char*) &vfpDoubleRegName, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vfpEnable", (char*) vfpEnable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vfpExcHandle", (char*) vfpExcHandle, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vfpFpScrGet", (char*) vfpFpScrGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vfpFpScrSet", (char*) vfpFpScrSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vfpFpSidGet", (char*) vfpFpSidGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vfpHasException", (char*) vfpHasException, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vfpIsEnabled", (char*) vfpIsEnabled, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vfpProbe", (char*) vfpProbe, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vfpProbeSup", (char*) vfpProbeSup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vfpProbeTrap", (char*) vfpProbeTrap, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vfpRegListShow", (char*) vfpRegListShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vfpRegsToCtx", (char*) vfpRegsToCtx, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vfpRestore", (char*) vfpRestore, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vfpSave", (char*) vfpSave, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vfpSingleRegName", (char*) &vfpSingleRegName, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vfpTaskRegsCFmt", (char*) &vfpTaskRegsCFmt, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vfpTaskRegsDFmt", (char*) &vfpTaskRegsDFmt, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vfpTaskRegsSFmt", (char*) &vfpTaskRegsSFmt, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vfprintf", (char*) vfprintf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vfpscrInitValue", (char*) &vfpscrInitValue, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "viLedLibInit", (char*) viLedLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmAttrToArchConvert", (char*) vmAttrToArchConvert, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmAttrToIndepConvert", (char*) vmAttrToIndepConvert, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmBaseLibInit", (char*) vmBaseLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmBasePageSizeGet", (char*) vmBasePageSizeGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmBaseStateSet", (char*) vmBaseStateSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmBufferWrite", (char*) vmBufferWrite, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmContextClassId", (char*) &vmContextClassId, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vmContextSwitch", (char*) vmContextSwitch, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmContigBlockEach", (char*) vmContigBlockEach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmCtxCreate", (char*) vmCtxCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmCtxDelete", (char*) vmCtxDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmCtxDestroy", (char*) vmCtxDestroy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmCtxInit", (char*) vmCtxInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmCtxMask", (char*) vmCtxMask, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmCtxTerminate", (char*) vmCtxTerminate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmCtxUnion", (char*) vmCtxUnion, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmCtxUnionInit", (char*) vmCtxUnionInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmCurrentGet", (char*) vmCurrentGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmCurrentSet", (char*) vmCurrentSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmGlobalMapInit", (char*) vmGlobalMapInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmInfoGet", (char*) vmInfoGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmKernelContextIdGet", (char*) vmKernelContextIdGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmLibInfo", (char*) &vmLibInfo, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vmLibInit", (char*) vmLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmMap", (char*) vmMap, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmMaxPhysBitsGet", (char*) vmMaxPhysBitsGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmOptimizedSizeGet", (char*) vmOptimizedSizeGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmPageBlockSizeGet", (char*) vmPageBlockSizeGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmPageLock", (char*) vmPageLock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmPageMap", (char*) vmPageMap, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmPageOptimize", (char*) vmPageOptimize, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmPageSizeGet", (char*) vmPageSizeGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmPageUnlock", (char*) vmPageUnlock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmPageUnmap", (char*) vmPageUnmap, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmPgMap", (char*) vmPgMap, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmPgUnMap", (char*) vmPgUnMap, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmPhysTranslate", (char*) vmPhysTranslate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmPteSizeGet", (char*) vmPteSizeGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmStateGet", (char*) vmStateGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmStateSet", (char*) vmStateSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmTextProtect", (char*) vmTextProtect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vmTranslate", (char*) vmTranslate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "voprintf", (char*) voprintf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vprintf", (char*) vprintf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vsnprintf", (char*) vsnprintf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vsprintf", (char*) vsprintf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxAbsTicks", (char*) &vxAbsTicks, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "vxAtomic32Add", (char*) vxAtomic32Add, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxAtomic32And", (char*) vxAtomic32And, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxAtomic32Cas", (char*) vxAtomic32Cas, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxAtomic32Clear", (char*) vxAtomic32Clear, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxAtomic32Dec", (char*) vxAtomic32Dec, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxAtomic32Get", (char*) vxAtomic32Get, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxAtomic32Inc", (char*) vxAtomic32Inc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxAtomic32Nand", (char*) vxAtomic32Nand, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxAtomic32Or", (char*) vxAtomic32Or, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxAtomic32Set", (char*) vxAtomic32Set, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxAtomic32Sub", (char*) vxAtomic32Sub, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxAtomic32Xor", (char*) vxAtomic32Xor, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxAtomicAdd", (char*) vxAtomicAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxAtomicAnd", (char*) vxAtomicAnd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxAtomicCas", (char*) vxAtomicCas, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxAtomicClear", (char*) vxAtomicClear, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxAtomicDec", (char*) vxAtomicDec, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxAtomicGet", (char*) vxAtomicGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxAtomicInc", (char*) vxAtomicInc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxAtomicNand", (char*) vxAtomicNand, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxAtomicOr", (char*) vxAtomicOr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxAtomicSet", (char*) vxAtomicSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxAtomicSub", (char*) vxAtomicSub, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxAtomicXor", (char*) vxAtomicXor, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxBaseCpuPhysIndex", (char*) &vxBaseCpuPhysIndex, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxCas", (char*) vxCas, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxCpsrGet", (char*) vxCpsrGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxCpuConfigured", (char*) &vxCpuConfigured, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxCpuConfiguredGet", (char*) vxCpuConfiguredGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxCpuEnabled", (char*) &vxCpuEnabled, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxCpuEnabledGet", (char*) vxCpuEnabledGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxCpuIdGet", (char*) vxCpuIdGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxCpuIdToPhysIndex", (char*) vxCpuIdToPhysIndex, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxCpuIndexGet", (char*) vxCpuIndexGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxCpuLibInit", (char*) vxCpuLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxCpuPhysIndexGet", (char*) vxCpuPhysIndexGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxCpuPhysIndexToId", (char*) vxCpuPhysIndexToId, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxCpuReserve", (char*) vxCpuReserve, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxCpuReservedGet", (char*) vxCpuReservedGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxCpuSetReserved", (char*) &vxCpuSetReserved, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxCpuSetReservedAvail", (char*) &vxCpuSetReservedAvail, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "vxCpuUnreserve", (char*) vxCpuUnreserve, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxEventPendQ", (char*) &vxEventPendQ, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxGic_Get_IrqFlag", (char*) vxGic_Get_IrqFlag, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxInit_Devc", (char*) vxInit_Devc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxInit_Dma", (char*) vxInit_Dma, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxInit_Dma_1", (char*) vxInit_Dma_1, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxInit_Dma_2", (char*) vxInit_Dma_2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxInit_Gpio", (char*) vxInit_Gpio, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxInit_Gtc", (char*) vxInit_Gtc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxInit_Qspi", (char*) vxInit_Qspi, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxInit_Spi", (char*) vxInit_Spi, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxInit_Uart", (char*) vxInit_Uart, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxIntStackBase", (char*) &vxIntStackBase, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "vxIntStackEnd", (char*) &vxIntStackEnd, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "vxIntStackOverflowSize", (char*) &vxIntStackOverflowSize, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxIntStackUnderflowSize", (char*) &vxIntStackUnderflowSize, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxIrqIntStackBase", (char*) &vxIrqIntStackBase, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "vxIrqIntStackEnd", (char*) &vxIrqIntStackEnd, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "vxMemArchProbe", (char*) vxMemArchProbe, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxMemArchProbeInit", (char*) vxMemArchProbeInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxMemProbe", (char*) vxMemProbe, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxMemProbeByteRead", (char*) vxMemProbeByteRead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxMemProbeByteWrite", (char*) vxMemProbeByteWrite, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxMemProbeErrorRtn", (char*) vxMemProbeErrorRtn, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxMemProbeInit", (char*) vxMemProbeInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxMemProbeLongRead", (char*) vxMemProbeLongRead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxMemProbeLongWrite", (char*) vxMemProbeLongWrite, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxMemProbeSup", (char*) vxMemProbeSup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxMemProbeSupEnd", (char*) vxMemProbeSupEnd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxMemProbeWordRead", (char*) vxMemProbeWordRead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxMemProbeWordWrite", (char*) vxMemProbeWordWrite, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxSvcIntStackBase", (char*) &vxSvcIntStackBase, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "vxSvcIntStackEnd", (char*) &vxSvcIntStackEnd, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "vxTas", (char*) vxTas, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxTaskEntry", (char*) vxTaskEntry, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxTaskEntryFatalInject", (char*) vxTaskEntryFatalInject, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxWorksVersion", (char*) &vxWorksVersion, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxWorksVersionMaint", (char*) &vxWorksVersionMaint, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxWorksVersionMajor", (char*) &vxWorksVersionMajor, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxWorksVersionMinor", (char*) &vxWorksVersionMinor, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxWorksVersionSvcPk", (char*) &vxWorksVersionSvcPk, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vx_FGicPs_Disable", (char*) vx_FGicPs_Disable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vx_FGicPs_Enable", (char*) vx_FGicPs_Enable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vx_FGicPs_Get_PrioTrigType", (char*) vx_FGicPs_Get_PrioTrigType, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vx_FGicPs_Set_PrioTrigType", (char*) vx_FGicPs_Set_PrioTrigType, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vx_FGicPs_SoftwareIntr", (char*) vx_FGicPs_SoftwareIntr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbAltSocGen5DwEndRegister", (char*) vxbAltSocGen5DwEndRegister, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbAltSocGen5DwEndRegister2", (char*) vxbAltSocGen5DwEndRegister2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbAltSocGen5TimerRegister", (char*) vxbAltSocGen5TimerRegister, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbArmGenIntCtlrRegister", (char*) vxbArmGenIntCtlrRegister, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbArmGicLvlChg", (char*) vxbArmGicLvlChg, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbArmGicLvlVecAck", (char*) vxbArmGicLvlVecAck, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbArmGicLvlVecChk", (char*) vxbArmGicLvlVecChk, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbBusAnnounce", (char*) vxbBusAnnounce, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbBusListLock", (char*) &vxbBusListLock, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxbBusTypeRegister", (char*) vxbBusTypeRegister, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbBusTypeString", (char*) vxbBusTypeString, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbBusTypeUnregister", (char*) vxbBusTypeUnregister, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbDelay", (char*) vxbDelay, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbDelayLibInit", (char*) vxbDelayLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbDelayTimerFreeRunning", (char*) &vxbDelayTimerFreeRunning, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxbDevConnect", (char*) vxbDevConnect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbDevConnectInternal", (char*) vxbDevConnectInternal, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbDevInit", (char*) vxbDevInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbDevInitInternal", (char*) vxbDevInitInternal, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbDevIntCapabCheck_desc", (char*) &vxbDevIntCapabCheck_desc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxbDevIterate", (char*) vxbDevIterate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbDevMethodGet", (char*) vxbDevMethodGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbDevMethodRun", (char*) vxbDevMethodRun, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbDevParent", (char*) vxbDevParent, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbDevPath", (char*) vxbDevPath, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbDevRegMap_desc", (char*) &vxbDevRegMap_desc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxbDevRegister", (char*) vxbDevRegister, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbDevRemovalAnnounce", (char*) vxbDevRemovalAnnounce, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbDevStructAlloc", (char*) vxbDevStructAlloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbDevStructFree", (char*) vxbDevStructFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbDevStructListLock", (char*) &vxbDevStructListLock, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxbDeviceAnnounce", (char*) vxbDeviceAnnounce, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbDeviceDriverRelease", (char*) vxbDeviceDriverRelease, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbDeviceMethodRun", (char*) vxbDeviceMethodRun, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbDmaChanAlloc", (char*) vxbDmaChanAlloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbDmaChanFree", (char*) vxbDmaChanFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbDmaLibInit", (char*) vxbDmaLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbDmaResDedicatedGet_desc", (char*) &vxbDmaResDedicatedGet_desc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxbDmaResourceGet_desc", (char*) &vxbDmaResourceGet_desc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxbDmaResourceRelease_desc", (char*) &vxbDmaResourceRelease_desc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxbDriverUnregister", (char*) vxbDriverUnregister, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbDrvRescan", (char*) vxbDrvRescan, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbDrvUnlink_desc", (char*) &vxbDrvUnlink_desc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxbDrvVerCheck", (char*) vxbDrvVerCheck, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbDwEmacDev0Resources", (char*) &vxbDwEmacDev0Resources, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxbDwEmacDev1Resources", (char*) &vxbDwEmacDev1Resources, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxbFmshSdhcCtrl_methods", (char*) &vxbFmshSdhcCtrl_methods, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxbGlobalListsLock", (char*) &vxbGlobalListsLock, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxbInit", (char*) vxbInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbInstByNameFind", (char*) vxbInstByNameFind, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbInstParamByIndexGet", (char*) vxbInstParamByIndexGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbInstParamByNameGet", (char*) vxbInstParamByNameGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbInstParamSet", (char*) vxbInstParamSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbInstUnitGet", (char*) vxbInstUnitGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbInstUnitSet", (char*) vxbInstUnitSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbInstUsrOptionGet", (char*) vxbInstUsrOptionGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbIntAcknowledge", (char*) vxbIntAcknowledge, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbIntAlloc", (char*) vxbIntAlloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbIntConnect", (char*) vxbIntConnect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbIntCtlrAck_desc", (char*) &vxbIntCtlrAck_desc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxbIntCtlrAlloc_desc", (char*) &vxbIntCtlrAlloc_desc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxbIntCtlrConnect_desc", (char*) &vxbIntCtlrConnect_desc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxbIntCtlrDisable_desc", (char*) &vxbIntCtlrDisable_desc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxbIntCtlrDisconnect_desc", (char*) &vxbIntCtlrDisconnect_desc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxbIntCtlrEnable_desc", (char*) &vxbIntCtlrEnable_desc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxbIntCtlrFree_desc", (char*) &vxbIntCtlrFree_desc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxbIntDisable", (char*) vxbIntDisable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbIntDisconnect", (char*) vxbIntDisconnect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbIntEnable", (char*) vxbIntEnable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbIntFree", (char*) vxbIntFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbIntVectorGet", (char*) vxbIntVectorGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbLegacyIntInit", (char*) vxbLegacyIntInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbLibError", (char*) vxbLibError, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbLibInit", (char*) vxbLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbLockDelete", (char*) vxbLockDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbLockGive", (char*) vxbLockGive, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbLockInit", (char*) vxbLockInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbLockTake", (char*) vxbLockTake, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbMmcStorageRegister", (char*) vxbMmcStorageRegister, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbMsDelay", (char*) vxbMsDelay, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbNextUnitGet", (char*) vxbNextUnitGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbRead16", (char*) vxbRead16, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbRead32", (char*) vxbRead32, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbRead8", (char*) vxbRead8, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbRegMap", (char*) vxbRegMap, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbRegUnmap", (char*) vxbRegUnmap, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbResourceFind", (char*) vxbResourceFind, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbSdSpecInfoGet_desc", (char*) &vxbSdSpecInfoGet_desc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxbSdStorageRegister", (char*) vxbSdStorageRegister, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbSdioInt", (char*) vxbSdioInt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbSdioIntConnect", (char*) vxbSdioIntConnect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbSdioIntLibInit", (char*) vxbSdioIntLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbSdioReadCis", (char*) vxbSdioReadCis, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbSdioSetFunc", (char*) vxbSdioSetFunc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbSerialChanGet", (char*) vxbSerialChanGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbSubDevAction", (char*) vxbSubDevAction, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbSwap16", (char*) vxbSwap16, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbSwap32", (char*) vxbSwap32, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbSysClkConnect", (char*) vxbSysClkConnect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbSysClkDisable", (char*) vxbSysClkDisable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbSysClkEnable", (char*) vxbSysClkEnable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbSysClkLibInit", (char*) vxbSysClkLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbSysClkRateGet", (char*) vxbSysClkRateGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbSysClkRateSet", (char*) vxbSysClkRateSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbTimerAlloc", (char*) vxbTimerAlloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbTimerFeaturesGet", (char*) vxbTimerFeaturesGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbTimerFuncGet_desc", (char*) &vxbTimerFuncGet_desc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxbTimerNumberGet_desc", (char*) &vxbTimerNumberGet_desc, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxbTimerRelease", (char*) vxbTimerRelease, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbTimestamp", (char*) vxbTimestamp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbTimestampConnect", (char*) vxbTimestampConnect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbTimestampDisable", (char*) vxbTimestampDisable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbTimestampEnable", (char*) vxbTimestampEnable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbTimestampFreq", (char*) vxbTimestampFreq, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbTimestampLibInit", (char*) vxbTimestampLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbTimestampLock", (char*) vxbTimestampLock, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbTimestampPeriod", (char*) vxbTimestampPeriod, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbUsDelay", (char*) vxbUsDelay, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbWrite16", (char*) vxbWrite16, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbWrite32", (char*) vxbWrite32, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxbWrite8", (char*) vxbWrite8, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxcoreip_shellFromTaskGet_ptr", (char*) &vxcoreip_shellFromTaskGet_ptr, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxcoreip_shellTaskGet_ptr", (char*) &vxcoreip_shellTaskGet_ptr, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxdbgAttach", (char*) vxdbgAttach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgBpAdd", (char*) vxdbgBpAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgBpAddrCheck", (char*) vxdbgBpAddrCheck, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgBpAllDisable", (char*) vxdbgBpAllDisable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgBpDelete", (char*) vxdbgBpDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgBpFind", (char*) vxdbgBpFind, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgBpList", (char*) &vxdbgBpList, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "vxdbgBpMsgDrop", (char*) vxdbgBpMsgDrop, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgBpMsgGet", (char*) vxdbgBpMsgGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgBpMsgPost", (char*) vxdbgBpMsgPost, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgBpMsgQCreate", (char*) vxdbgBpMsgQCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgBpMsgQHdlrIsRunning", (char*) vxdbgBpMsgQHdlrIsRunning, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgBpTraceAbort", (char*) vxdbgBpTraceAbort, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgBpUserKeyGet", (char*) vxdbgBpUserKeyGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgBpUserKeySet", (char*) vxdbgBpUserKeySet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgClntRegister", (char*) vxdbgClntRegister, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgClntUnregister", (char*) vxdbgClntUnregister, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgCont", (char*) vxdbgCont, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgDetach", (char*) vxdbgDetach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgDisableReason", (char*) &vxdbgDisableReason, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "vxdbgEnable", (char*) vxdbgEnable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgEventCancel", (char*) vxdbgEventCancel, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgEventIdAlloc", (char*) vxdbgEventIdAlloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgEventIdFree", (char*) vxdbgEventIdFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgEventInject", (char*) vxdbgEventInject, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgEventLibInit", (char*) vxdbgEventLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgEventRunCtrlStateChangeInject", (char*) vxdbgEventRunCtrlStateChangeInject, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgExcLibInit", (char*) vxdbgExcLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgHookAdd", (char*) vxdbgHookAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgHookInvoke", (char*) vxdbgHookInvoke, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgHooksInit", (char*) vxdbgHooksInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgHwBpAdd", (char*) vxdbgHwBpAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgHwBpTypeValidate", (char*) vxdbgHwBpTypeValidate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgInstrCmp", (char*) vxdbgInstrCmp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgInternalEventInject", (char*) vxdbgInternalEventInject, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgIsAttached", (char*) vxdbgIsAttached, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgIsBpAddr", (char*) vxdbgIsBpAddr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgIsEnabled", (char*) vxdbgIsEnabled, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgLibInit", (char*) vxdbgLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgLockUnbreakable", (char*) &vxdbgLockUnbreakable, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "vxdbgMemAccess", (char*) vxdbgMemAccess, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgMemCtxSwitch", (char*) vxdbgMemCtxSwitch, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgMemMove", (char*) vxdbgMemMove, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgMemProbe", (char*) vxdbgMemProbe, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgMemRead", (char*) vxdbgMemRead, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgMemScan", (char*) vxdbgMemScan, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgMemWrite", (char*) vxdbgMemWrite, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgModuleLibInit", (char*) vxdbgModuleLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgRunCtrlHookInvoke", (char*) vxdbgRunCtrlHookInvoke, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgRunCtrlLibInit", (char*) vxdbgRunCtrlLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgRunCtrlStateChangeNotify", (char*) vxdbgRunCtrlStateChangeNotify, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgSafeUnbreakable", (char*) &vxdbgSafeUnbreakable, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "vxdbgStep", (char*) vxdbgStep, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgStop", (char*) vxdbgStop, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgTaskBpToInstall", (char*) vxdbgTaskBpToInstall, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgTaskCont", (char*) vxdbgTaskCont, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgTaskHookInit", (char*) vxdbgTaskHookInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgTaskLibInit", (char*) vxdbgTaskLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgTaskStep", (char*) vxdbgTaskStep, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgTaskStop", (char*) vxdbgTaskStop, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxdbgUnbreakableOld", (char*) &vxdbgUnbreakableOld, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "vxfs_ramdisk_init_hook", (char*) &vxfs_ramdisk_init_hook, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "vxmux_mux_mblk_init", (char*) vxmux_mux_mblk_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxmux_null_buf_init", (char*) vxmux_null_buf_init, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "vxmux_null_pool", (char*) &vxmux_null_pool, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "w", (char*) w, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wcstombs", (char*) wcstombs, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wctomb", (char*) wctomb, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdCancel", (char*) wdCancel, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdClassId", (char*) &wdClassId, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "wdCreate", (char*) wdCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdCreateLibInit", (char*) wdCreateLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdDelete", (char*) wdDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdDestroy", (char*) wdDestroy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdInit", (char*) wdInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdInitialize", (char*) wdInitialize, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdLibInit", (char*) wdLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdStart", (char*) wdStart, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdTerminate", (char*) wdTerminate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdTick", (char*) wdTick, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbAvailModes", (char*) &wdbAvailModes, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "wdbAvailOptions", (char*) &wdbAvailOptions, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "wdbBpAddHookAdd", (char*) wdbBpAddHookAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbBpSyncLibInit", (char*) wdbBpSyncLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbBpSysEnterHook", (char*) &wdbBpSysEnterHook, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "wdbBpSysExitHook", (char*) &wdbBpSysExitHook, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "wdbCksum", (char*) wdbCksum, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbCmdLoop", (char*) wdbCmdLoop, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbCnctModePost", (char*) wdbCnctModePost, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbCommDevInit", (char*) wdbCommDevInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbCommIfEnable", (char*) wdbCommIfEnable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbCommMtu", (char*) &wdbCommMtu, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "wdbCommMtuGet", (char*) wdbCommMtuGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbConfig", (char*) wdbConfig, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbConnectHookAdd", (char*) wdbConnectHookAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbConnectLibInit", (char*) wdbConnectLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbCtxCreateNotify", (char*) wdbCtxCreateNotify, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbCtxDeleteNotify", (char*) wdbCtxDeleteNotify, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbCtxEvtLibInit", (char*) wdbCtxEvtLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbCtxExitEventGet", (char*) wdbCtxExitEventGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbCtxExitLibInit", (char*) wdbCtxExitLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbCtxExitNotifyHook", (char*) wdbCtxExitNotifyHook, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbCtxLibInit", (char*) wdbCtxLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbCtxStartEventGet", (char*) wdbCtxStartEventGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbCtxStartLibInit", (char*) wdbCtxStartLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbDbgAddrCheck", (char*) wdbDbgAddrCheck, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbDbgArchInit", (char*) wdbDbgArchInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbDbgGetNpc", (char*) wdbDbgGetNpc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbDbgSysCallCheck", (char*) wdbDbgSysCallCheck, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbDbgTraceModeClear", (char*) wdbDbgTraceModeClear, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbDbgTraceModeSet", (char*) wdbDbgTraceModeSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbDbgTrap", (char*) wdbDbgTrap, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbDirectCallLibInit", (char*) wdbDirectCallLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbE", (char*) wdbE, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbEndDebug", (char*) &wdbEndDebug, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "wdbEndDeviceAddress", (char*) &wdbEndDeviceAddress, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "wdbEndPktDevInit", (char*) wdbEndPktDevInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbEventDeq", (char*) wdbEventDeq, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbEventLibInit", (char*) wdbEventLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbEventNodeInit", (char*) wdbEventNodeInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbEventPost", (char*) wdbEventPost, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbEvtptClassConnect", (char*) wdbEvtptClassConnect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbEvtptLibInit", (char*) wdbEvtptLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbExcLibInit", (char*) wdbExcLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbExternCoprocRegLibInit", (char*) wdbExternCoprocRegLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbExternEnterHookAdd", (char*) wdbExternEnterHookAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbExternExitHookAdd", (char*) wdbExternExitHookAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbExternInit", (char*) wdbExternInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbExternLibInit", (char*) wdbExternLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbExternRegLibInit", (char*) wdbExternRegLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbFuncCallLibInit", (char*) wdbFuncCallLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbGopherLibInit", (char*) wdbGopherLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbInfoGet", (char*) wdbInfoGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbInstallCommIf", (char*) wdbInstallCommIf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbInstallRtIf", (char*) wdbInstallRtIf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbIoctl", (char*) wdbIoctl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbIsAlwaysEnabled", (char*) &wdbIsAlwaysEnabled, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "wdbIsInitialized", (char*) &wdbIsInitialized, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "wdbIsNowExternal", (char*) wdbIsNowExternal, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbIsReady", (char*) &wdbIsReady, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "wdbMbufAlloc", (char*) wdbMbufAlloc, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbMbufFree", (char*) wdbMbufFree, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbMbufInit", (char*) wdbMbufInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbMdlSymSyncLibInit", (char*) wdbMdlSymSyncLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbMemCoreLibInit", (char*) wdbMemCoreLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbMemLibInit", (char*) wdbMemLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbMode", (char*) &wdbMode, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "wdbModeSet", (char*) wdbModeSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbModeSetHookAdd", (char*) wdbModeSetHookAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbNotifyHost", (char*) wdbNotifyHost, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbNumMemRegions", (char*) &wdbNumMemRegions, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "wdbOneShot", (char*) &wdbOneShot, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "wdbPort", (char*) &wdbPort, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "wdbRegsLibInit", (char*) wdbRegsLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbRpcGetArgs", (char*) wdbRpcGetArgs, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbRpcNotifyConnect", (char*) wdbRpcNotifyConnect, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbRpcNotifyHost", (char*) wdbRpcNotifyHost, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbRpcRcv", (char*) wdbRpcRcv, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbRpcReply", (char*) wdbRpcReply, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbRpcReplyErr", (char*) wdbRpcReplyErr, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbRpcResendReply", (char*) wdbRpcResendReply, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbRpcXportInit", (char*) wdbRpcXportInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbRtIf", (char*) &wdbRtIf, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "wdbRtLibInit", (char*) wdbRtLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbRtMemInit", (char*) wdbRtMemInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbRunsExternal", (char*) wdbRunsExternal, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbRunsTasking", (char*) wdbRunsTasking, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbSharedBuffer", (char*) &wdbSharedBuffer, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "wdbSharedBufferSize", (char*) &wdbSharedBufferSize, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "wdbSp", (char*) wdbSp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbSvcAdd", (char*) wdbSvcAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbSvcDispatch", (char*) wdbSvcDispatch, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbSvcHookAdd", (char*) wdbSvcHookAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbSvcLibInit", (char*) wdbSvcLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbSysBpDisableAll", (char*) wdbSysBpDisableAll, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbSysBpEnableAll", (char*) wdbSysBpEnableAll, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbSysBpLibInit", (char*) wdbSysBpLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbSysModeInit", (char*) wdbSysModeInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbSystemSuspend", (char*) wdbSystemSuspend, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbTargetIsConnected", (char*) wdbTargetIsConnected, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbTaskBpAdd", (char*) wdbTaskBpAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbTaskBpLibInit", (char*) wdbTaskBpLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbTaskCont", (char*) wdbTaskCont, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbTaskCoprocRegLibInit", (char*) wdbTaskCoprocRegLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbTaskCreateHookAdd", (char*) wdbTaskCreateHookAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbTaskDeleteHookAdd", (char*) wdbTaskDeleteHookAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbTaskExtraModules", (char*) &wdbTaskExtraModules, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "wdbTaskHookInit", (char*) wdbTaskHookInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbTaskModeInit", (char*) wdbTaskModeInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbTaskRegLibInit", (char*) wdbTaskRegLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbTaskRestartHook", (char*) &wdbTaskRestartHook, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "wdbTaskStep", (char*) wdbTaskStep, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbTaskStop", (char*) wdbTaskStop, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbTgtInfoLibInit", (char*) wdbTgtInfoLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbToolName", (char*) &wdbToolName, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "wdbUserEvtLibInit", (char*) wdbUserEvtLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbUserEvtPost", (char*) wdbUserEvtPost, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbVioChannelRegister", (char*) wdbVioChannelRegister, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbVioChannelUnregister", (char*) wdbVioChannelUnregister, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbVioDrv", (char*) wdbVioDrv, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbVioLibInit", (char*) wdbVioLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbXdrCreate", (char*) wdbXdrCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbXdrGetVal", (char*) wdbXdrGetVal, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbXdrGetpos", (char*) wdbXdrGetpos, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbXdrInline", (char*) wdbXdrInline, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbXdrPutVal", (char*) wdbXdrPutVal, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbXdrPutbytes", (char*) wdbXdrPutbytes, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "wdbXdrSetpos", (char*) wdbXdrSetpos, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "whoami", (char*) whoami, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "windClientCont", (char*) windClientCont, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "windClientStop", (char*) windClientStop, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "windCont", (char*) windCont, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "windDelay", (char*) windDelay, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "windDelete", (char*) windDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "windExit", (char*) windExit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "windIntStackSet", (char*) windIntStackSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "windLoadContext", (char*) windLoadContext, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "windNullReturn", (char*) windNullReturn, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "windPendQFlush", (char*) windPendQFlush, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "windPendQGet", (char*) windPendQGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "windPendQPut", (char*) windPendQPut, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "windPendQRemove", (char*) windPendQRemove, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "windPendQTerminate", (char*) windPendQTerminate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "windPriNormalSet", (char*) windPriNormalSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "windPrioritySet", (char*) windPrioritySet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "windReadyQPut", (char*) windReadyQPut, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "windReadyQRemove", (char*) windReadyQRemove, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "windResume", (char*) windResume, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "windSemDelete", (char*) windSemDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "windSemRWDelete", (char*) windSemRWDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "windStop", (char*) windStop, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "windStopClear", (char*) windStopClear, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "windSuspend", (char*) windSuspend, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "windTickAnnounce", (char*) windTickAnnounce, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "windTickAnnounceN", (char*) windTickAnnounceN, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "windTickWaitGet", (char*) windTickWaitGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "windUndelay", (char*) windUndelay, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "windWdCancel", (char*) windWdCancel, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "windWdStart", (char*) windWdStart, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "workQAdd0", (char*) workQAdd0, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "workQAdd1", (char*) workQAdd1, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "workQAdd2", (char*) workQAdd2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "workQDoWork", (char*) workQDoWork, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "workQInit", (char*) workQInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "workQIsEmpty", (char*) &workQIsEmpty, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "workQIsPanicked", (char*) &workQIsPanicked, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "workQIx", (char*) &workQIx, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "workQPanic", (char*) workQPanic, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "workQPanicHook", (char*) &workQPanicHook, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "workQWorkInProgress", (char*) &workQWorkInProgress, 0, 0,  SYM_GLOBAL | SYM_BSS},
        {{NULL}, "wqsz1", (char*) &wqsz1, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "wqsz2", (char*) &wqsz2, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "wqsz3", (char*) &wqsz3, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "wqsz4", (char*) &wqsz4, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "write", (char*) write, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "write32", (char*) write32, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "write32p", (char*) write32p, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "writev", (char*) writev, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xattrib", (char*) xattrib, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdAddGptPartition", (char*) xbdAddGptPartition, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdAttach", (char*) xbdAttach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdAttachExt", (char*) xbdAttachExt, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdAttachSchecdPolicyById", (char*) xbdAttachSchecdPolicyById, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdAttachSchecdPolicyByName", (char*) xbdAttachSchecdPolicyByName, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedAvlDelete", (char*) xbdBioSchedAvlDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedAvlInsert", (char*) xbdBioSchedAvlInsert, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedAvlMinGet", (char*) xbdBioSchedAvlMinGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedAvlNodeShow", (char*) xbdBioSchedAvlNodeShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedAvlPredecessorGet", (char*) xbdBioSchedAvlPredecessorGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedAvlSearch", (char*) xbdBioSchedAvlSearch, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedAvlShow", (char*) xbdBioSchedAvlShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedAvlSuccessorGet", (char*) xbdBioSchedAvlSuccessorGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedDeadlineAttach", (char*) xbdBioSchedDeadlineAttach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedDeadlineAvlCompare", (char*) xbdBioSchedDeadlineAvlCompare, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedDeadlineBioEnq", (char*) xbdBioSchedDeadlineBioEnq, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedDeadlineDetach", (char*) xbdBioSchedDeadlineDetach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedDeadlineDispatch", (char*) xbdBioSchedDeadlineDispatch, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedDeadlineFini", (char*) xbdBioSchedDeadlineFini, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedDeadlineInit", (char*) xbdBioSchedDeadlineInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedDeadlinePolicy", (char*) &xbdBioSchedDeadlinePolicy, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "xbdBioSchedDeadlineReqDeq", (char*) xbdBioSchedDeadlineReqDeq, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedDeadlineReqDone", (char*) xbdBioSchedDeadlineReqDone, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedDeadlineReqEnq", (char*) xbdBioSchedDeadlineReqEnq, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedDeadlineReqGet", (char*) xbdBioSchedDeadlineReqGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedDeadlineReqMerged", (char*) xbdBioSchedDeadlineReqMerged, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedDeadlineReqNext", (char*) xbdBioSchedDeadlineReqNext, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedDeadlineReqPrev", (char*) xbdBioSchedDeadlineReqPrev, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedDeadlineReqPut", (char*) xbdBioSchedDeadlineReqPut, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedDeadlineShow", (char*) xbdBioSchedDeadlineShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedExit", (char*) xbdBioSchedExit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedFindBackMerge", (char*) xbdBioSchedFindBackMerge, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedFindBackMergeByHash", (char*) xbdBioSchedFindBackMergeByHash, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedFindFrontMerge", (char*) xbdBioSchedFindFrontMerge, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedFindFrontMergeByHash", (char*) xbdBioSchedFindFrontMergeByHash, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedFlush", (char*) xbdBioSchedFlush, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedGetAvlNode", (char*) xbdBioSchedGetAvlNode, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedHashNodeShow", (char*) xbdBioSchedHashNodeShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedInit", (char*) xbdBioSchedInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedMaxActiveReqsSet", (char*) xbdBioSchedMaxActiveReqsSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedMaxBiosPerReqSet", (char*) xbdBioSchedMaxBiosPerReqSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedMaxBlksPerBioSet", (char*) xbdBioSchedMaxBlksPerBioSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedMaxBlksPerReqSet", (char*) xbdBioSchedMaxBlksPerReqSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedMergeAdd", (char*) xbdBioSchedMergeAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedMergeBio", (char*) xbdBioSchedMergeBio, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedMergeRemove", (char*) xbdBioSchedMergeRemove, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedPolicyAdd", (char*) xbdBioSchedPolicyAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedPolicyAttach", (char*) xbdBioSchedPolicyAttach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedPolicyDettach", (char*) xbdBioSchedPolicyDettach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedPolicyNoop", (char*) &xbdBioSchedPolicyNoop, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "xbdBioSchedPolicyNoopAttach", (char*) xbdBioSchedPolicyNoopAttach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedPolicyNoopBioEnQ", (char*) xbdBioSchedPolicyNoopBioEnQ, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedPolicyNoopDetach", (char*) xbdBioSchedPolicyNoopDetach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedPolicyNoopDispatch", (char*) xbdBioSchedPolicyNoopDispatch, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedPolicyNoopFini", (char*) xbdBioSchedPolicyNoopFini, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedPolicyNoopInit", (char*) xbdBioSchedPolicyNoopInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedPolicyNoopReqDeQ", (char*) xbdBioSchedPolicyNoopReqDeQ, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedPolicyNoopReqDone", (char*) xbdBioSchedPolicyNoopReqDone, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedPolicyNoopReqEnQ", (char*) xbdBioSchedPolicyNoopReqEnQ, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedPolicyNoopReqGet", (char*) xbdBioSchedPolicyNoopReqGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedPolicyNoopReqPut", (char*) xbdBioSchedPolicyNoopReqPut, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedPolicyNoopShow", (char*) xbdBioSchedPolicyNoopShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedPolicyRemove", (char*) xbdBioSchedPolicyRemove, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedPolicySSD", (char*) &xbdBioSchedPolicySSD, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "xbdBioSchedPolicySSDAttach", (char*) xbdBioSchedPolicySSDAttach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedPolicySSDAvlCompare", (char*) xbdBioSchedPolicySSDAvlCompare, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedPolicySSDDetach", (char*) xbdBioSchedPolicySSDDetach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedPolicySSDDispatch", (char*) xbdBioSchedPolicySSDDispatch, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedPolicySSDFini", (char*) xbdBioSchedPolicySSDFini, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedPolicySSDInit", (char*) xbdBioSchedPolicySSDInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedPolicySSDReqDeQ", (char*) xbdBioSchedPolicySSDReqDeQ, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedPolicySSDReqDone", (char*) xbdBioSchedPolicySSDReqDone, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedPolicySSDReqEnQ", (char*) xbdBioSchedPolicySSDReqEnQ, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedPolicySSDReqGet", (char*) xbdBioSchedPolicySSDReqGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedPolicySSDReqMerged", (char*) xbdBioSchedPolicySSDReqMerged, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedPolicySSDReqNext", (char*) xbdBioSchedPolicySSDReqNext, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedPolicySSDReqPrev", (char*) xbdBioSchedPolicySSDReqPrev, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedPolicySSDReqPut", (char*) xbdBioSchedPolicySSDReqPut, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedPolicySSDShow", (char*) xbdBioSchedPolicySSDShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedPutAvlNode", (char*) xbdBioSchedPutAvlNode, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedReqDeq", (char*) xbdBioSchedReqDeq, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedReqEnq", (char*) xbdBioSchedReqEnq, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedReqGet", (char*) xbdBioSchedReqGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedReqMergeable", (char*) xbdBioSchedReqMergeable, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedReqMerged", (char*) xbdBioSchedReqMerged, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedReqPut", (char*) xbdBioSchedReqPut, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedShow", (char*) xbdBioSchedShow, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBioSchedStrategy", (char*) xbdBioSchedStrategy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBlkDevCreate", (char*) xbdBlkDevCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBlkDevCreateSync", (char*) xbdBlkDevCreateSync, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBlkDevDelete", (char*) xbdBlkDevDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBlkDevLibInit", (char*) xbdBlkDevLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdBlkDevServTskPri", (char*) &xbdBlkDevServTskPri, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "xbdBlockSize", (char*) xbdBlockSize, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdCacheInfoSet", (char*) xbdCacheInfoSet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdCreateGptPartition", (char*) xbdCreateGptPartition, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdDetach", (char*) xbdDetach, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdDetachSchecdPolicyById", (char*) xbdDetachSchecdPolicyById, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdDetachSchecdPolicyByName", (char*) xbdDetachSchecdPolicyByName, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdDump", (char*) xbdDump, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdEventCategory", (char*) &xbdEventCategory, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "xbdEventInstantiated", (char*) &xbdEventInstantiated, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "xbdEventMediaChanged", (char*) &xbdEventMediaChanged, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "xbdEventPrimaryInsert", (char*) &xbdEventPrimaryInsert, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "xbdEventRemove", (char*) &xbdEventRemove, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "xbdEventSecondaryInsert", (char*) &xbdEventSecondaryInsert, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "xbdEventSoftInsert", (char*) &xbdEventSoftInsert, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "xbdFindPolicyById", (char*) xbdFindPolicyById, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdFindPolicyByName", (char*) xbdFindPolicyByName, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdGetBioSched", (char*) xbdGetBioSched, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdGetNextBioGeneric", (char*) xbdGetNextBioGeneric, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdGptPartAdd", (char*) xbdGptPartAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdGptPartDevCreate", (char*) xbdGptPartDevCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdGptPartFin", (char*) xbdGptPartFin, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdGptPartStart", (char*) xbdGptPartStart, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdGptPartVecAdd", (char*) xbdGptPartVecAdd, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdInit", (char*) xbdInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdIoctl", (char*) xbdIoctl, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdMapGet", (char*) xbdMapGet, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdNBlocks", (char*) xbdNBlocks, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdPartitionDevCreate", (char*) xbdPartitionDevCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdReqSchedComplete", (char*) xbdReqSchedComplete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdRequestBackMergeHash", (char*) xbdRequestBackMergeHash, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdRequestCacheCreate", (char*) xbdRequestCacheCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdRequestCacheDestroy", (char*) xbdRequestCacheDestroy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdRequestCacheLibFini", (char*) xbdRequestCacheLibFini, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdRequestCacheLibInit", (char*) xbdRequestCacheLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdRequestFrontMergeHash", (char*) xbdRequestFrontMergeHash, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdRequestHashKeyCmp", (char*) xbdRequestHashKeyCmp, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdRoot", (char*) xbdRoot, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdSchedDebug", (char*) &xbdSchedDebug, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "xbdSchedSSDDebug", (char*) &xbdSchedSSDDebug, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "xbdSetBioSched", (char*) xbdSetBioSched, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdSize", (char*) xbdSize, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdSrvTaskGeneric", (char*) xbdSrvTaskGeneric, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdStrategy", (char*) xbdStrategy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdStrategyGeneric", (char*) xbdStrategyGeneric, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdSwitchSchecdPolicyById", (char*) xbdSwitchSchecdPolicyById, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xbdSwitchSchecdPolicyByName", (char*) xbdSwitchSchecdPolicyByName, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xcopy", (char*) xcopy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdelete", (char*) xdelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdrCksum", (char*) xdrCksum, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_ARRAY", (char*) xdr_ARRAY, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_BOOL", (char*) xdr_BOOL, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_CHECKSUM", (char*) xdr_CHECKSUM, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_ENUM", (char*) xdr_ENUM, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_REFERENCE", (char*) xdr_REFERENCE, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_TGT_ADDR_T", (char*) xdr_TGT_ADDR_T, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_TGT_LONG_T", (char*) xdr_TGT_LONG_T, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_UINT32", (char*) xdr_UINT32, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_VOID", (char*) xdr_VOID, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_AGENT_INFO", (char*) xdr_WDB_AGENT_INFO, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_CALL_RETURN_INFO", (char*) xdr_WDB_CALL_RETURN_INFO, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_CONNECT_INFO", (char*) xdr_WDB_CONNECT_INFO, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_CONNECT_PARAMS", (char*) xdr_WDB_CONNECT_PARAMS, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_CORE", (char*) xdr_WDB_CORE, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_CTX", (char*) xdr_WDB_CTX, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_CTX_CREATE_DESC", (char*) xdr_WDB_CTX_CREATE_DESC, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_CTX_KILL_DESC", (char*) xdr_WDB_CTX_KILL_DESC, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_CTX_STEP_DESC", (char*) xdr_WDB_CTX_STEP_DESC, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_DIRECT_CALL_RET", (char*) xdr_WDB_DIRECT_CALL_RET, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_EVTPT_ADD_DESC", (char*) xdr_WDB_EVTPT_ADD_DESC, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_EVTPT_DEL_DESC", (char*) xdr_WDB_EVTPT_DEL_DESC, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_EVT_DATA", (char*) xdr_WDB_EVT_DATA, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_EVT_INFO", (char*) xdr_WDB_EVT_INFO, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_MEM_REGION", (char*) xdr_WDB_MEM_REGION, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_MEM_SCAN_DESC", (char*) xdr_WDB_MEM_SCAN_DESC, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_MEM_XFER", (char*) xdr_WDB_MEM_XFER, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_MOD_INFO", (char*) xdr_WDB_MOD_INFO, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_OPQ_DATA_T", (char*) xdr_WDB_OPQ_DATA_T, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_PARAM_WRAPPER", (char*) xdr_WDB_PARAM_WRAPPER, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_REG_READ_DESC", (char*) xdr_WDB_REG_READ_DESC, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_REG_WRITE_DESC", (char*) xdr_WDB_REG_WRITE_DESC, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_REPLY_WRAPPER", (char*) xdr_WDB_REPLY_WRAPPER, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_RT_INFO", (char*) xdr_WDB_RT_INFO, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_SECT_INFO", (char*) xdr_WDB_SECT_INFO, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_SEG_INFO", (char*) xdr_WDB_SEG_INFO, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_STRING_ARRAY", (char*) xdr_WDB_STRING_ARRAY, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_STRING_T", (char*) xdr_WDB_STRING_T, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_SYM_ID", (char*) xdr_WDB_SYM_ID, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_SYM_ID_LIST", (char*) xdr_WDB_SYM_ID_LIST, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_SYM_INFO", (char*) xdr_WDB_SYM_INFO, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_SYM_LIST", (char*) xdr_WDB_SYM_LIST, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_SYM_MOD_DESC", (char*) xdr_WDB_SYM_MOD_DESC, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_TGT_INFO", (char*) xdr_WDB_TGT_INFO, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xdr_WDB_TGT_INFO_2", (char*) xdr_WDB_TGT_INFO_2, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "xh", (char*) &xh, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "xpFuncs", (char*) &xpFuncs, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "yzgm", (char*) &yzgm, 0, 0,  SYM_GLOBAL | SYM_DATA},
        {{NULL}, "zbufCreate", (char*) zbufCreate, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "zbufCut", (char*) zbufCut, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "zbufDelete", (char*) zbufDelete, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "zbufDup", (char*) zbufDup, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "zbufExtractCopy", (char*) zbufExtractCopy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "zbufInsert", (char*) zbufInsert, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "zbufInsertBuf", (char*) zbufInsertBuf, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "zbufInsertBuf64", (char*) zbufInsertBuf64, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "zbufInsertCopy", (char*) zbufInsertCopy, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "zbufLength", (char*) zbufLength, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "zbufLibInit", (char*) zbufLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "zbufSegData", (char*) zbufSegData, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "zbufSegFind", (char*) zbufSegFind, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "zbufSegLength", (char*) zbufSegLength, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "zbufSegNext", (char*) zbufSegNext, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "zbufSegPrev", (char*) zbufSegPrev, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "zbufSockBufSend", (char*) zbufSockBufSend, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "zbufSockBufSend64", (char*) zbufSockBufSend64, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "zbufSockBufSendto", (char*) zbufSockBufSendto, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "zbufSockBufSendto64", (char*) zbufSockBufSendto64, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "zbufSockLibInit", (char*) zbufSockLibInit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "zbufSockRecv", (char*) zbufSockRecv, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "zbufSockRecvfrom", (char*) zbufSockRecvfrom, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "zbufSockSend", (char*) zbufSockSend, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "zbufSockSendto", (char*) zbufSockSendto, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "zbufSplit", (char*) zbufSplit, 0, 0,  SYM_GLOBAL | SYM_TEXT},
        {{NULL}, "zbuf_free", (char*) zbuf_free, 0, 0,  SYM_GLOBAL | SYM_TEXT},
    };


ULONG standTblSize = 6737;
