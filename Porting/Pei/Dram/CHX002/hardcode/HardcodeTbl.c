


#include "hardcode.h"


UINT16 VREF_Overlap_Tbl[] = {0XBF,0XF1};
UINT16 VREF_Coarse_Tbl[] = {0XBF,0XF1} ;


RXTXTIMING Rx_TNI_Value_Tbl[] = {
    {CHA_RXTXHARDCODE, TNI_RXTXHARDCODE, 0, 0x0525, 0x0527, 0x052C, 0x0531, 0x0507, 0x050E, 0x0510, 0x051C, 0x0100 ,1},
    {CHA_RXTXHARDCODE, TNI_RXTXHARDCODE, 1, 0x0520, 0x0520, 0x0520, 0x0520, 0x0520, 0x0520, 0x0520, 0x0520, 0x0100 ,1},
    {CHA_RXTXHARDCODE, TNI_RXTXHARDCODE, 2, 0x0520, 0x0520, 0x0520, 0x0520, 0x0520, 0x0520, 0x0520, 0x0520, 0x0100 ,1},
    {CHA_RXTXHARDCODE, TNI_RXTXHARDCODE, 3, 0x0520, 0x0520, 0x0520, 0x0520, 0x0520, 0x0520, 0x0520, 0x0520, 0x0100 ,1},
    {CHB_RXTXHARDCODE, TNI_RXTXHARDCODE, 0, 0x053A, 0x053F, 0x053F, 0x0507, 0x0519, 0x051F, 0x0628, 0x062A, 0x0100 ,1},
    {CHB_RXTXHARDCODE, TNI_RXTXHARDCODE, 1, 0x0520, 0x0520, 0x0520, 0x0520, 0x0520, 0x0520, 0x0620, 0x0620, 0x0100 ,1},
    {CHB_RXTXHARDCODE, TNI_RXTXHARDCODE, 2, 0x0520, 0x0520, 0x0520, 0x0520, 0x0520, 0x0520, 0x0620, 0x0620, 0x0100 ,1},
    {CHB_RXTXHARDCODE, TNI_RXTXHARDCODE, 3, 0x0520, 0x0520, 0x0520, 0x0520, 0x0520, 0x0520, 0x0620, 0x0620, 0x0100 ,1},
  };
UINT32 Rx_TNI_Value_Tbl_Items = sizeof(Rx_TNI_Value_Tbl) / sizeof(RXTXTIMING);


RXVREFTIMING Rx_RxVref_Value_Tbl[] = {
    {CHA_RXTXHARDCODE, 0, 0x45, 0x44, 0x42, 0x4B, 0x46, 0x46, 0x40, 0x44 ,1},
    {CHA_RXTXHARDCODE, 1, 0x46, 0x41, 0x48, 0x43, 0x45, 0x44, 0x47, 0x43 ,1},
    {CHA_RXTXHARDCODE, 2, 0x48, 0x4E, 0x41, 0x4A, 0x4A, 0x46, 0x47, 0x47 ,1},
    {CHA_RXTXHARDCODE, 3, 0x42, 0x46, 0x42, 0x43, 0x48, 0x41, 0x49, 0x43 ,1},
    {CHA_RXTXHARDCODE, 4, 0x40, 0x43, 0x43, 0x49, 0x48, 0x40, 0x44, 0x42 ,1},
    {CHA_RXTXHARDCODE, 5, 0x4A, 0x47, 0x44, 0x45, 0x49, 0x47, 0x46, 0x49 ,1},
    {CHA_RXTXHARDCODE, 6, 0x48, 0x47, 0x48, 0x44, 0x45, 0x44, 0x48, 0x47 ,1},
    {CHA_RXTXHARDCODE, 7, 0x47, 0x4C, 0x47, 0x43, 0x4B, 0x48, 0x48, 0x4E ,1},
    {CHB_RXTXHARDCODE, 0, 0x47, 0x43, 0x47, 0x47, 0x45, 0x49, 0x4A, 0x43 ,1},
    {CHB_RXTXHARDCODE, 1, 0x4D, 0x46, 0x44, 0x44, 0x49, 0x42, 0x45, 0x42 ,1},
    {CHB_RXTXHARDCODE, 2, 0x4A, 0x4C, 0x49, 0x46, 0x47, 0x4A, 0x4D, 0x45 ,1},
    {CHB_RXTXHARDCODE, 3, 0x4A, 0x48, 0x46, 0x42, 0x4A, 0x46, 0x43, 0x49 ,1},
    {CHB_RXTXHARDCODE, 4, 0x46, 0x42, 0x45, 0x45, 0x49, 0x44, 0x43, 0x41 ,1},
    {CHB_RXTXHARDCODE, 5, 0x45, 0x49, 0x45, 0x43, 0x46, 0x40, 0x4A, 0x4A ,1},
    {CHB_RXTXHARDCODE, 6, 0x48, 0x49, 0x46, 0x4D, 0x49, 0x46, 0x4B, 0x4F ,1},
    {CHB_RXTXHARDCODE, 7, 0x4B, 0x47, 0x44, 0x46, 0x48, 0x48, 0x4A, 0x49 ,1},
  };
UINT32 Rx_RxVref_Value_Tbl_Items = sizeof(Rx_RxVref_Value_Tbl) / sizeof(RXVREFTIMING);


RXDQSITIMING Rx_DQSI_Value_Tbl[] = {

    {CHA_RXTXHARDCODE, 0, 0, 0x001A, 0x0018, 0x001A, 0x001A, 0x001A, 0x001A, 0x001A, 0x001A, 1, 1},
    {CHA_RXTXHARDCODE, 0, 0, 0x0018, 0x0018, 0x0017, 0x0018, 0x0018, 0x0019, 0x0018, 0x0018, 0, 1},
    {CHA_RXTXHARDCODE, 0, 1, 0x0019, 0x001A, 0x001A, 0x001B, 0x001A, 0x0019, 0x001B, 0x001A, 1, 1},
    {CHA_RXTXHARDCODE, 0, 1, 0x0016, 0x0017, 0x0016, 0x0017, 0x0017, 0x0016, 0x0017, 0x0016, 0, 1},
    {CHA_RXTXHARDCODE, 0, 2, 0x0019, 0x001A, 0x001B, 0x001A, 0x001A, 0x001A, 0x001A, 0x001A, 1, 1},
    {CHA_RXTXHARDCODE, 0, 2, 0x0017, 0x0017, 0x0017, 0x0016, 0x0017, 0x0017, 0x0017, 0x0017, 0, 1},
    {CHA_RXTXHARDCODE, 0, 3, 0x0019, 0x0018, 0x001A, 0x001A, 0x0019, 0x0019, 0x001A, 0x001A, 1, 1},
    {CHA_RXTXHARDCODE, 0, 3, 0x0017, 0x0017, 0x0017, 0x0016, 0x0017, 0x0017, 0x0017, 0x0016, 0, 1},
    {CHA_RXTXHARDCODE, 0, 4, 0x0018, 0x0018, 0x001A, 0x001A, 0x001A, 0x001A, 0x0019, 0x001A, 1, 1},
    {CHA_RXTXHARDCODE, 0, 4, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0016, 0, 1},
    {CHA_RXTXHARDCODE, 0, 5, 0x0018, 0x0018, 0x001A, 0x0019, 0x001A, 0x0018, 0x0019, 0x0018, 1, 1},
    {CHA_RXTXHARDCODE, 0, 5, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0, 1},
    {CHA_RXTXHARDCODE, 0, 6, 0x0017, 0x0018, 0x0019, 0x0018, 0x0018, 0x0017, 0x0016, 0x0018, 1, 1},
    {CHA_RXTXHARDCODE, 0, 6, 0x0017, 0x0018, 0x0018, 0x0017, 0x0018, 0x0017, 0x0016, 0x0018, 0, 1},
    {CHA_RXTXHARDCODE, 0, 7, 0x0017, 0x0017, 0x0017, 0x0018, 0x0017, 0x0017, 0x0018, 0x0019, 1, 1},
    {CHA_RXTXHARDCODE, 0, 7, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x001A, 0, 1},
    {CHA_RXTXHARDCODE, 0, 8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHA_RXTXHARDCODE, 0, 8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},

    {CHA_RXTXHARDCODE, 1, 0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHA_RXTXHARDCODE, 1, 0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHA_RXTXHARDCODE, 1, 1, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHA_RXTXHARDCODE, 1, 1, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHA_RXTXHARDCODE, 1, 2, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHA_RXTXHARDCODE, 1, 2, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHA_RXTXHARDCODE, 1, 3, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHA_RXTXHARDCODE, 1, 3, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHA_RXTXHARDCODE, 1, 4, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHA_RXTXHARDCODE, 1, 4, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHA_RXTXHARDCODE, 1, 5, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHA_RXTXHARDCODE, 1, 5, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHA_RXTXHARDCODE, 1, 6, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHA_RXTXHARDCODE, 1, 6, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHA_RXTXHARDCODE, 1, 7, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHA_RXTXHARDCODE, 1, 7, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHA_RXTXHARDCODE, 1, 8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHA_RXTXHARDCODE, 1, 8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},

    {CHA_RXTXHARDCODE, 2, 0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHA_RXTXHARDCODE, 2, 0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHA_RXTXHARDCODE, 2, 1, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHA_RXTXHARDCODE, 2, 1, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHA_RXTXHARDCODE, 2, 2, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHA_RXTXHARDCODE, 2, 2, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHA_RXTXHARDCODE, 2, 3, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHA_RXTXHARDCODE, 2, 3, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHA_RXTXHARDCODE, 2, 4, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHA_RXTXHARDCODE, 2, 4, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHA_RXTXHARDCODE, 2, 5, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHA_RXTXHARDCODE, 2, 5, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHA_RXTXHARDCODE, 2, 6, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHA_RXTXHARDCODE, 2, 6, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHA_RXTXHARDCODE, 2, 7, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHA_RXTXHARDCODE, 2, 7, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHA_RXTXHARDCODE, 2, 8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHA_RXTXHARDCODE, 2, 8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},

    {CHA_RXTXHARDCODE, 3, 0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHA_RXTXHARDCODE, 3, 0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHA_RXTXHARDCODE, 3, 1, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHA_RXTXHARDCODE, 3, 1, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHA_RXTXHARDCODE, 3, 2, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHA_RXTXHARDCODE, 3, 2, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHA_RXTXHARDCODE, 3, 3, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHA_RXTXHARDCODE, 3, 3, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHA_RXTXHARDCODE, 3, 4, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHA_RXTXHARDCODE, 3, 4, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHA_RXTXHARDCODE, 3, 5, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHA_RXTXHARDCODE, 3, 5, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHA_RXTXHARDCODE, 3, 6, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHA_RXTXHARDCODE, 3, 6, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHA_RXTXHARDCODE, 3, 7, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHA_RXTXHARDCODE, 3, 7, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHA_RXTXHARDCODE, 3, 8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHA_RXTXHARDCODE, 3, 8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},

    {CHB_RXTXHARDCODE, 0, 0, 0x0017, 0x0018, 0x0018, 0x0019, 0x0018, 0x0019, 0x0018, 0x0019, 1, 1},
    {CHB_RXTXHARDCODE, 0, 0, 0x0017, 0x0018, 0x0017, 0x0018, 0x0018, 0x0018, 0x0017, 0x0017, 0, 1},
    {CHB_RXTXHARDCODE, 0, 1, 0x0018, 0x0018, 0x0019, 0x001A, 0x0019, 0x0018, 0x001A, 0x0019, 1, 1},
    {CHB_RXTXHARDCODE, 0, 1, 0x0018, 0x0018, 0x0018, 0x0019, 0x0019, 0x0018, 0x0018, 0x0018, 0, 1},
    {CHB_RXTXHARDCODE, 0, 2, 0x0018, 0x0019, 0x0019, 0x001A, 0x0017, 0x0018, 0x0017, 0x0018, 1, 1},
    {CHB_RXTXHARDCODE, 0, 2, 0x0019, 0x0019, 0x0019, 0x0018, 0x0019, 0x001A, 0x001A, 0x0018, 0, 1},
    {CHB_RXTXHARDCODE, 0, 3, 0x0017, 0x0018, 0x001B, 0x001A, 0x0018, 0x001A, 0x001A, 0x001A, 1, 1},
    {CHB_RXTXHARDCODE, 0, 3, 0x001A, 0x001B, 0x001B, 0x001B, 0x001B, 0x001A, 0x001B, 0x001A, 0, 1},
    {CHB_RXTXHARDCODE, 0, 4, 0x0018, 0x0017, 0x0017, 0x0017, 0x0016, 0x0017, 0x0016, 0x0017, 1, 1},
    {CHB_RXTXHARDCODE, 0, 4, 0x0017, 0x0017, 0x0019, 0x0017, 0x0016, 0x0018, 0x0016, 0x0017, 0, 1},
    {CHB_RXTXHARDCODE, 0, 5, 0x0018, 0x0017, 0x0018, 0x001A, 0x0018, 0x0016, 0x0018, 0x0018, 1, 1},
    {CHB_RXTXHARDCODE, 0, 5, 0x0018, 0x0018, 0x001A, 0x0017, 0x0019, 0x0017, 0x0017, 0x0017, 0, 1},
    {CHB_RXTXHARDCODE, 0, 6, 0x0019, 0x001A, 0x001A, 0x0018, 0x0018, 0x0018, 0x0018, 0x001A, 1, 1},
    {CHB_RXTXHARDCODE, 0, 6, 0x0018, 0x0019, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x0019, 0, 1},
    {CHB_RXTXHARDCODE, 0, 7, 0x0019, 0x0018, 0x0019, 0x0019, 0x0019, 0x0018, 0x0019, 0x001D, 1, 1},
    {CHB_RXTXHARDCODE, 0, 7, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0018, 0, 1},
    {CHB_RXTXHARDCODE, 0, 8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHB_RXTXHARDCODE, 0, 8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},

    {CHB_RXTXHARDCODE, 1, 0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHB_RXTXHARDCODE, 1, 0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHB_RXTXHARDCODE, 1, 1, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHB_RXTXHARDCODE, 1, 1, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHB_RXTXHARDCODE, 1, 2, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHB_RXTXHARDCODE, 1, 2, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHB_RXTXHARDCODE, 1, 3, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHB_RXTXHARDCODE, 1, 3, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHB_RXTXHARDCODE, 1, 4, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHB_RXTXHARDCODE, 1, 4, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHB_RXTXHARDCODE, 1, 5, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHB_RXTXHARDCODE, 1, 5, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHB_RXTXHARDCODE, 1, 6, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHB_RXTXHARDCODE, 1, 6, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHB_RXTXHARDCODE, 1, 7, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHB_RXTXHARDCODE, 1, 7, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHB_RXTXHARDCODE, 1, 8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHB_RXTXHARDCODE, 1, 8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},

    {CHB_RXTXHARDCODE, 2, 0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHB_RXTXHARDCODE, 2, 0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHB_RXTXHARDCODE, 2, 1, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHB_RXTXHARDCODE, 2, 1, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHB_RXTXHARDCODE, 2, 2, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHB_RXTXHARDCODE, 2, 2, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHB_RXTXHARDCODE, 2, 3, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHB_RXTXHARDCODE, 2, 3, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHB_RXTXHARDCODE, 2, 4, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHB_RXTXHARDCODE, 2, 4, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHB_RXTXHARDCODE, 2, 5, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHB_RXTXHARDCODE, 2, 5, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHB_RXTXHARDCODE, 2, 6, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHB_RXTXHARDCODE, 2, 6, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHB_RXTXHARDCODE, 2, 7, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHB_RXTXHARDCODE, 2, 7, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHB_RXTXHARDCODE, 2, 8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHB_RXTXHARDCODE, 2, 8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},

    {CHB_RXTXHARDCODE, 3, 0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHB_RXTXHARDCODE, 3, 0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHB_RXTXHARDCODE, 3, 1, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHB_RXTXHARDCODE, 3, 1, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHB_RXTXHARDCODE, 3, 2, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHB_RXTXHARDCODE, 3, 2, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHB_RXTXHARDCODE, 3, 3, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHB_RXTXHARDCODE, 3, 3, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHB_RXTXHARDCODE, 3, 4, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHB_RXTXHARDCODE, 3, 4, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHB_RXTXHARDCODE, 3, 5, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHB_RXTXHARDCODE, 3, 5, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHB_RXTXHARDCODE, 3, 6, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHB_RXTXHARDCODE, 3, 6, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHB_RXTXHARDCODE, 3, 7, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHB_RXTXHARDCODE, 3, 7, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
    {CHB_RXTXHARDCODE, 3, 8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 1, 1},
    {CHB_RXTXHARDCODE, 3, 8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0, 1},
  };
UINT32 Rx_DQSI_Value_Tbl_Items = sizeof(Rx_DQSI_Value_Tbl) / sizeof(RXDQSITIMING);


RXTXTIMING TX_Value_Tbl[] = {
    {CHA_RXTXHARDCODE, DQO_RXTXHARDCODE, 0, 0x0307, 0x0310, 0x031D, 0x0325, 0x033D, 0x033F, 0x0405, 0x0406, 0x0100 ,1},
    {CHB_RXTXHARDCODE, DQO_RXTXHARDCODE, 0, 0x030B, 0x0315, 0x031B, 0x0323, 0x033F, 0x033F, 0x0402, 0x0407, 0x0100 ,1},
    {CHA_RXTXHARDCODE, DQSO_RXTXHARDCODE, 0, 0x0336, 0x033E, 0x030A, 0x0312, 0x032A, 0x032C, 0x0432, 0x0434, 0x0700 ,1},
    {CHB_RXTXHARDCODE, DQSO_RXTXHARDCODE, 0, 0x0336, 0x0302, 0x030A, 0x0312, 0x032C, 0x032E, 0x0432, 0x0436, 0x0700 ,1},
    {CHA_RXTXHARDCODE, TXVREF_RXTXHARDCODE, 0, 0x0021, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 ,1},
    {CHA_RXTXHARDCODE, TXVREF_RXTXHARDCODE, 1, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 ,1},
    {CHA_RXTXHARDCODE, TXVREF_RXTXHARDCODE, 2, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 ,1},
    {CHA_RXTXHARDCODE, TXVREF_RXTXHARDCODE, 3, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 ,1},
    {CHB_RXTXHARDCODE, TXVREF_RXTXHARDCODE, 0, 0x0021, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 ,1},
    {CHB_RXTXHARDCODE, TXVREF_RXTXHARDCODE, 1, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 ,1},
    {CHB_RXTXHARDCODE, TXVREF_RXTXHARDCODE, 2, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 ,1},
    {CHB_RXTXHARDCODE, TXVREF_RXTXHARDCODE, 3, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 ,1},
  };
UINT32 TX_Value_Tbl_Items = sizeof(TX_Value_Tbl) / sizeof(RXTXTIMING);


