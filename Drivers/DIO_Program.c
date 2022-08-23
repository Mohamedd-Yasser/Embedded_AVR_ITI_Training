#include "STD-TYPES.h"
#include "BIT_MATH.h"
#include "DIO_PRIVATE.h"
#include "DIO_Interface.h"





void DIO_voidSetPinDirection(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinDir)
{
	
	if (Copy_u8PinDir==1)
	{
		switch(Copy_u8PortID)
	    {
		case PORTA_ID /*portA*/:  SET_BIT(DDRA_REG,Copy_u8PinID);break;
		case PORTB_ID /*portB*/:  SET_BIT(DDRB_REG,Copy_u8PinID);break;
		case PORTC_ID /*portC*/:  SET_BIT(DDRC_REG,Copy_u8PinID);break;
		case PORTD_ID /*portD*/:  SET_BIT(DDRD_REG,Copy_u8PinID);break;
	    }
	
	
	} 
	else if (Copy_u8PinDir==0)
	{
		switch(Copy_u8PortID)
		{
		case PORTA_ID /*portA*/:  CLR_BIT(DDRA_REG,Copy_u8PinID);break;
		case PORTB_ID /*portB*/:  CLR_BIT(DDRB_REG,Copy_u8PinID);break;
		case PORTC_ID /*portC*/:  CLR_BIT(DDRC_REG,Copy_u8PinID);break;
		case PORTD_ID /*portD*/:  CLR_BIT(DDRD_REG,Copy_u8PinID);break;
		}
		
	}
}



void DIO_voidSetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinValue)
{
	if (Copy_u8PinValue==1)
	{
		switch(Copy_u8PortID)
	    {
		case PORTA_ID /*portA*/:  SET_BIT(PORTA_REG,Copy_u8PinID);break;
		case PORTB_ID /*portB*/:  SET_BIT(PORTB_REG,Copy_u8PinID);break;
		case PORTC_ID /*portC*/:  SET_BIT(PORTC_REG,Copy_u8PinID);break;
		case PORTD_ID /*portD*/:  SET_BIT(PORTD_REG,Copy_u8PinID);break;
	    }
	
	
	} 
	else if (Copy_u8PinValue==0)
	{
		switch(Copy_u8PortID)
		{
		case PORTA_ID /*portA*/:  CLR_BIT(PORTA_REG,Copy_u8PinID);break;
		case PORTB_ID /*portB*/:  CLR_BIT(PORTB_REG,Copy_u8PinID);break;
		case PORTC_ID /*portC*/:  CLR_BIT(PORTC_REG,Copy_u8PinID);break;
		case PORTD_ID /*portD*/:  CLR_BIT(PORTD_REG,Copy_u8PinID);break;
		}
		
	}
}




void DIO_voidSetPortDirection(u8 Copy_u8PortID, u8 Copy_u8PortDir)
{
	switch(Copy_u8PortID)
	{
	case PORTA_ID: DDRA_REG= Copy_u8PortDir; break;
	case PORTB_ID: DDRB_REG= Copy_u8PortDir; break;
	case PORTC_ID: DDRC_REG= Copy_u8PortDir; break;
	case PORTD_ID: DDRD_REG= Copy_u8PortDir; break;

	}
}
void DIO_voidSetPortValue(u8 Copy_u8PortID, u8 Copy_u8PortValue)
{
	switch(Copy_u8PortID)
		{
		case PORTA_ID: PORTA_REG= Copy_u8PortValue; break;
		case PORTB_ID: PORTB_REG= Copy_u8PortValue; break;
		case PORTC_ID: PORTC_REG= Copy_u8PortValue; break;
		case PORTD_ID: PORTD_REG= Copy_u8PortValue; break;

		}

}
void DIO_voidTogPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID)
{
	switch(Copy_u8PortID)
		    
	
	{
	        case 0 /*portA*/:  TOG_BIT(PORTA_REG,Copy_u8PinID);break;
			case 1 /*portB*/:  TOG_BIT(PORTB_REG,Copy_u8PinID);break;
			case 2 /*portC*/:  TOG_BIT(PORTC_REG,Copy_u8PinID);break;
			case 3 /*portD*/:  TOG_BIT(PORTD_REG,Copy_u8PinID);break;
			}
	}
u8 DIO_voidGetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID)
{
	u8 Value=0;
	switch(Copy_u8PortID)
		    
	
	{
	        case 0 /*portA*/:  Value= GET_BIT(DDRA_REG,Copy_u8PinID);break;
			case 1 /*portB*/:  Value=GET_BIT(DDRB_REG,Copy_u8PinID);break;
			case 2 /*portC*/:  Value=GET_BIT(DDRC_REG,Copy_u8PinID);break;
			case 3 /*portD*/:  Value=GET_BIT(DDRD_REG,Copy_u8PinID);break;
			}
			return Value;
	}


