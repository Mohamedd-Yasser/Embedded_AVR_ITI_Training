
#include "STD-TYPES.h"
#include "BIT_MATH.h"
#include "DIO_PRIVATE.h"
#include "DIO_Interface.h"
#include "TIMER_INTERFACE.h"
#include "TIMER_CONFIG.h"
#include "EXTINT_Interface.h"
#include "EXTINT_Private.h"


void (*TMR_GPFun0)(void)='\0';
void (*TMR_GPFun1)(void)='\0';



void TMR0_INIT(u8 Copy_u8Mode)
{


	switch (Copy_u8Mode)
	{
	case NORMAL:
		SET_BIT (TIMSK,TOIEO_BIT);
		CLR_BIT (TCCRO,WGMO_BIT0);
		CLR_BIT (TCCRO,WGMO_BIT1);
		break;
	case CTC:
		CLR_BIT(TCCRO,WGMO_BIT0);
		SET_BIT(TCCRO,WGMO_BIT1);

		SET_BIT(TIMSK,OCIEO_BIT);
		CLR_BIT(TCCRO,4);
		CLR_BIT(TCCRO,5);

	}

	CLR_BIT (TCCRO,CS0_BIT0);
	CLR_BIT (TCCRO,CS0_BIT1);
	SET_BIT (TCCRO,CS0_BIT2);





	//DIO_voidSetPortValue(TCCRO,0b00000010);


}

void TMRO_voidPRELOAD(u8 Copy_u8PreloadValue)
{

	TCNTO=Copy_u8PreloadValue;
}

void TMRO_voidCompareValue(u8 Copy_u8PreloadValue)
{
	OCRO=Copy_u8PreloadValue;
}

void TMRO_voidSetCallBackOf(void (*ptr))
{
	TMR_GPFun0=ptr;

}
void __vector_11()__attribute__((signal));
void __vector_11()
{
	if (TMR_GPFun0 != '\0')
	{
		TMR_GPFun0();
	}


}

void TMRO_voidSetCallBackCTC(void (*ptr))
{
	TMR_GPFun1=ptr;
}


void __vector_10()__attribute__((signal));
void __vector_10()
{
	if (TMR_GPFun1 != '\0')
	{
		TMR_GPFun1();
	}


}
void TMR_FASTPWMIni()
{
	SET_BIT (TCCRO,WGMO_BIT0);
	SET_BIT (TCCRO,WGMO_BIT1);
	CLR_BIT (TCCRO,CM0_BIT0);
	SET_BIT (TCCRO,CM0_BIT1);
	CLR_BIT (TCCRO,CS0_BIT0);
	CLR_BIT (TCCRO,CS0_BIT1);
	SET_BIT (TCCRO,CS0_BIT2);
	OCRO=250;

}

void TMR_voidServo()
{

	SET_BIT(TCCR1A,COM1A1);
	CLR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1B1);
	CLR_BIT(TCCR1A,COM1B0);

	CLR_BIT (TCCR1A,WGM10);
	SET_BIT (TCCR1A,WGM11);
	SET_BIT(TCCR1B,PIN3_ID);
	SET_BIT(TCCR1B,PIN4_ID);


	CLR_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);

	ICR1=20000;



	}

void TMR1_voidSetOCR1A( u16 Copy_u8Value)

{

	OCR1A=Copy_u8Value;

	}

void Servo_voidGetAngle(u8 Copy_u8Angle)
{
	u32 timer;
	f32 slope;
	TMR_voidServo();
	slope=50.0/9;
	timer=slope*Copy_u8Angle+999;
	TMR1_voidSetOCR1A(timer);
}


