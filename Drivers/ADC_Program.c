#include "STD-TYPES.h"
#include "BIT_MATH.h"
#include"DIO_Private.h"
#include"DIO_Interface.h"
//#include"DCMOTOR_Interface.h"
#include"EXTINT_Private.h"
#include "ADC_Private.h"
#include"ADC_Interface.h"
#include"ADC_Congif.h"




void ADC_voidInit()
{
	//AVCC with external capacitor at AREF pin
	SET_BIT(ADMUX,6);
	SET_BIT(ADMUX,7);
	
	//Right Adjust
	CLR_BIT(ADMUX,5);
	
	// To choose ADC0 (select channel)
	CLR_BIT(ADMUX,0);
	CLR_BIT(ADMUX,1);
	CLR_BIT(ADMUX,2);
	CLR_BIT(ADMUX,3);
	CLR_BIT(ADMUX,4);
	
	//Single Conversion
	SET_BIT(ADCSRA,6);
	
	//Prescaler 
	CLR_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
	
	//Enable ADC
	SET_BIT(ADCSRA,7);
	
	//ADLAR=0
	CLR_BIT(ADMUX,5);
	
}


u16 ADC_u16GetResult()
{
	return ADC ;
	
	
}

void ADC_voidSingleRead()
{
	//Single Conversion
	SET_BIT(ADCSRA,6);
}

void ADC_voidSelectChannel(u8 Copy_u8ChannelNUM)
{
	switch(Copy_u8ChannelNUM)
	{
	case ADC0 :
		CLR_BIT(ADMUX,0);
		CLR_BIT(ADMUX,1);
		CLR_BIT(ADMUX,2);
		CLR_BIT(ADMUX,3);
		CLR_BIT(ADMUX,4);
		break ;
	case ADC1 :
		SET_BIT(ADMUX,0);
		CLR_BIT(ADMUX,1);
		CLR_BIT(ADMUX,2);
		CLR_BIT(ADMUX,3);
		CLR_BIT(ADMUX,4);
		break ;
	case ADC2 :
		CLR_BIT(ADMUX,0);
		SET_BIT(ADMUX,1);
		CLR_BIT(ADMUX,2);
		CLR_BIT(ADMUX,3);
		CLR_BIT(ADMUX,4);
		break ;
	case ADC3 :
		SET_BIT(ADMUX,0);
		SET_BIT(ADMUX,1);
		CLR_BIT(ADMUX,2);
		CLR_BIT(ADMUX,3);
		CLR_BIT(ADMUX,4);
		break ;
	case ADC4 :
		CLR_BIT(ADMUX,0);
		CLR_BIT(ADMUX,1);
		SET_BIT(ADMUX,2);
		CLR_BIT(ADMUX,3);
		CLR_BIT(ADMUX,4);
		break ;
	case ADC5 :
		SET_BIT(ADMUX,0);
		CLR_BIT(ADMUX,1);
		SET_BIT(ADMUX,2);
		CLR_BIT(ADMUX,3);
		CLR_BIT(ADMUX,4);
		break ;
	case ADC6 :
		CLR_BIT(ADMUX,0);
		SET_BIT(ADMUX,1);
		SET_BIT(ADMUX,2);
		CLR_BIT(ADMUX,3);
		CLR_BIT(ADMUX,4);
		break ;
	case ADC7 :
		SET_BIT(ADMUX,0);
		SET_BIT(ADMUX,1);
		SET_BIT(ADMUX,2);
		CLR_BIT(ADMUX,3);
		CLR_BIT(ADMUX,4);
		break ;


    }


}


void ADC_voidSelectPreScaler(u8 Copy_u8ClkDiv)
{
	switch(Copy_u8ClkDiv)
	{


	case(Div2) :

		CLR_BIT(ADCSRA,0);
	CLR_BIT(ADCSRA,1);
	CLR_BIT(ADCSRA,2);
	break ;

	case(Div4) :

		CLR_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	CLR_BIT(ADCSRA,2);
	break ;

	case(Div8) :

		SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	CLR_BIT(ADCSRA,2);
	break ;

	case(Div16) :

		CLR_BIT(ADCSRA,0);
	CLR_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
	break ;

	case(Div32) :

		SET_BIT(ADCSRA,0);
	CLR_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
	break ;

	case(Div64) :

		CLR_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
	break ;

	case(Div128) :

		SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
	break ;

	}





}
