#ifndef SST_INTERFACE_H
#define SST_INTERFACE_H

extern kal_bool SST_Get_ChipRID(kal_char *pUid, kal_int32 buf_len);

#if defined(MT6580)
typedef enum{
	AP_SBC_EN = 1,
	C_CTRL0,
	C_CTRL1,
	C_DAT0,
	C_DAT1,
	C_DAT2,
	C_DAT3,
	C_DAT4,
	C_DAT5,
}EFUSE_DATA_TYPE;
#else
typedef enum{
	AP_SBC_EN = 0,
	C_CTRL0 = 0,
	C_CTRL1 = 0, 
	C_DAT0 = 0,
	C_DAT1 = 0,
	C_DAT2 = 0,
	C_DAT3 = 0,
	C_DAT4 = 0,
	C_DAT5 = 0,
}EFUSE_DATA_TYPE;
#endif

#endif
