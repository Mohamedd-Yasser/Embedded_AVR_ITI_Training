#ifndef _KYP_INTERFACE_H
#define _KYP_INTERFACE_H



#define All_HIGH 0xFF
#define FourOUT_FourIN 0x0F



u8 KYP_GetPressedKey(void);
void KYP_Init(void);
void KYP_CALC(void);

#endif

