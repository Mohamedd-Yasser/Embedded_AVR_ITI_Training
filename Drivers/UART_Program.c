#include "STD-TYPES.h"
#include "BIT_MATH.h"
#include"DIO_Private.h"
#include"DIO_Interface.h"
#include"ADC_Private.h"
#include"ADC_Interface.h"
#include"ADC_Congif.h"
#include "UART_Config.h"
#include "UART_Interface.h"
#include "UART_Private.h"




void UART_voidInialize()
{

	u8 Copy_u8Value;
	//Register Enable
	SET_BIT(Copy_u8Value,7);

	//Enable Tx and Rx 
	SET_BIT(UCSRB,3);
	SET_BIT(UCSRB,4);



	//Asychronus
	CLR_BIT(Copy_u8Value,6);
	//No parity
	CLR_BIT(Copy_u8Value,4);
	CLR_BIT(Copy_u8Value,5);
	//Number of stop bits
	CLR_BIT(Copy_u8Value,3);
	//Character size (the third bit is 0 by default)
	SET_BIT(Copy_u8Value,1);
	SET_BIT(Copy_u8Value,2);
	UCSRC_UBRRH=Copy_u8Value;


	//To set BaudRate
	//CLR_BIT(UCSRC_UBRRH,7);
	UBRRL=51 ; 


}


void UART_SendData(u8 Copy_u8Value)
{


	UDR=Copy_u8Value;
	while (DIO_voidGetPinValue(UCSRA,6)==0);
	SET_BIT(UCSRA,6);


}


u8 UART_ReceiveData()
{

	while (DIO_voidGetPinValue(UCSRA,7)==0);
	//To Reset the value 
	DIO_voidGetPinValue(UCSRA,7);
	return UDR ;
}
void UART_voidSendNumber(u16 Copy_u8Value)
{
	u8 count =0;
	u16 number[16]={0};
	for (u8 i=0;Copy_u8Value!=0;i++){
		number[i]=Copy_u8Value % 10;
		Copy_u8Value=	Copy_u8Value/10;
		count ++;
	}
	for (u8 j=count-1;j>=0;j--)
	{
		UART_SendData(number[j]+48);
	}
}


