#ifndef _TIMER_INTERFACE_H
#define _TIMER_INTERFACE_H


#define WGMO_BIT0 0X06
#define WGMO_BIT1 0X03

#define CS0_BIT0 0
#define CS0_BIT1 1
#define CS0_BIT2 2
#define CM0_BIT1 5
#define CM0_BIT0 4


#define TOIEO_BIT 0X00
#define OCIEO_BIT 0X01

#define NORMAL 0
#define CTC 1



#define COM1A1    7
#define COM1A0    6
#define COM1B1    5
#define COM1B0    4
#define FOC1A     3
#define FOC1B     2
#define WGM11     1
#define WGM10     0







void TMR0_INIT(u8 Copy_u8Mode);
void TMRO_voidSetCallBackOf(void (*ptr));
void TMRO_voidSetCallBackCTC(void (*ptr));
void TMRO_voidPRELOAD(u8 Copy_u8PreloadValue);
void TMRO_voidCompareValue(u8 Copy_u8PreloadValue);
void TMR_FASTPWMIni();
void TMR_voidServo();
void TMR1_voidSetOCR1A( u16 Copy_u8Value);





#endif

