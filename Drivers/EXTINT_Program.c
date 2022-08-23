#include "STD-TYPES.h"
#include "BIT_MATH.h"
#include"DIO_Private.h"
#include"DIO_Interface.h"
//#include"DCMOTOR_Interface.h"
#include"EXTINT_Private.h"



void EXTINT_voidIntIialize(u8 Copy_u8IntNum)
{
	SET_BIT(S_REG,PIN7_ID);                                   // Enable Intereput

	switch(Copy_u8IntNum)
	{
	case (0):
			DIO_voidSetPinDirection(PORTD_ID,PIN2_ID,PIN_INPUT_ID);   // Enable GIE
	DIO_voidSetPinValue(PORTD_ID,PIN2_ID,PIN_HIGH_ID);
	SET_BIT(GICR_REG ,PIN6_ID);
	break ;

	case(1):
			DIO_voidSetPinDirection(PORTD_ID,PIN3_ID,PIN_INPUT_ID);   // Enable GIE
	DIO_voidSetPinValue(PORTD_ID,PIN3_ID,PIN_HIGH_ID);
	SET_BIT(GICR_REG ,PIN7_ID);
	break;

	case(2):
			DIO_voidSetPinDirection(PORTB_ID,PIN2_ID,PIN_INPUT_ID);   // Enable GIE
	DIO_voidSetPinValue(PORTB_ID,PIN2_ID,PIN_HIGH_ID);
	SET_BIT(GICR_REG ,PIN5_ID);
	break;
	}



}

void EXTINT_voidInt0(u8 Copy_u8IntNum,u8 Copy_u8SenseMode)
{



	EXTINT_voidIntIialize(Copy_u8IntNum);

	if (Copy_u8IntNum==0)
	{
		switch(Copy_u8SenseMode)
		{
		case ('R'):                                                      // rasing
				SET_BIT(MCUCR_REG ,PIN0_ID);
		SET_BIT(MCUCR_REG ,PIN1_ID);
		break ;
		case('F'):                                                       //failling
				CLR_BIT(MCUCR_REG ,PIN0_ID);
		SET_BIT(MCUCR_REG ,PIN1_ID);
		break;
		case('L'):                                                        // low level
				CLR_BIT(MCUCR_REG ,PIN0_ID);
		CLR_BIT(MCUCR_REG ,PIN1_ID);
		break;

		}
	}


	else if (Copy_u8IntNum==1)

	{
		switch(Copy_u8SenseMode)
		{
		case ('R'):                                                      // rasing
				SET_BIT(MCUCR_REG ,PIN2_ID);
		SET_BIT(MCUCR_REG ,PIN3_ID);
		break ;
		case('F'):                                                       //failling
				CLR_BIT(MCUCR_REG ,PIN2_ID);
		SET_BIT(MCUCR_REG ,PIN3_ID);
		break;
		case('L'):                                                        // low level
				CLR_BIT(MCUCR_REG ,PIN2_ID);
		CLR_BIT(MCUCR_REG ,PIN3_ID);
		break;

		}
	}



	else if (Copy_u8IntNum==2)
	{
		switch(Copy_u8SenseMode)
		{
		case ('R'):                                                      // rasing
				SET_BIT(MCUCSR_REG ,PIN6_ID);
		break ;
		case('F'):                                                       //failling
				CLR_BIT(MCUCSR_REG ,PIN6_ID);
		break;

		}

	}


}

void __vector_1()__attribute__((signal));
void __vector_1()
{
	DIO_voidSetPinValue(PORTA_ID,PIN0_ID,PIN_HIGH_ID);

}

void __vector_2()__attribute__((signal));
void __vector_2()
{
	DIO_voidSetPinValue(PORTA_ID,PIN0_ID,PIN_HIGH_ID);

}

void __vector_3()__attribute__((signal));
void __vector_3()
{
	DIO_voidSetPinValue(PORTA_ID,PIN0_ID,PIN_HIGH_ID);

}

