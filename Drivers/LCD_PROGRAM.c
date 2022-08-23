#include <util/delay.h>
#include "STD-TYPES.h"
#include "BIT_MATH.h"
#include "DIO_PRIVATE.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "LCD_CONFIG.h"





void LCD_voidInit(void)
{ 


    /* Set Pin Direction*/ 
    DIO_voidSetPinDirection(LCD_PORT_CONTROL,RS, PIN_OUTPUT_ID);
    DIO_voidSetPinDirection(LCD_PORT_CONTROL,RW, PIN_OUTPUT_ID);
    DIO_voidSetPinDirection(LCD_PORT_CONTROL,RE, PIN_OUTPUT_ID);

    /*Set Port Direction*/
    DIO_voidSetPortDirection(LCD_PORT_DISPLAY,ALL_PORT_OUT);
    /*Delay 30*/ 
	_delay_ms(30);
    /* Send Command Function Set*/
	LCD_voidWriteCommand(0b00111000);
    /*Delay 2*/
	_delay_ms(2);
    /*Send Command Display on/off*/
	LCD_voidWriteCommand(0b00001100);
    /*Delay 2ms*/
	_delay_ms(30);
    /*Send Command Clear Display*/
	LCD_voidWriteCommand(0b00000001);

}



void LCD_voidWriteCommand( u8 Copy_u8Command)
{
	/*RS=1--->pin0*/
    DIO_voidSetPinValue(LCD_PORT_CONTROL, RS,PIN_LOW_ID);
	/*RW=1--->pin1*/
    DIO_voidSetPinValue(LCD_PORT_CONTROL, RW,PIN_LOW_ID);
    /*Send Data*/
   DIO_voidSetPortValue(LCD_PORT_DISPLAY,Copy_u8Command);
   /*Enable Pulse*/
   DIO_voidSetPinValue(PORTB_ID, RE,PIN_HIGH_ID);
	_delay_ms(2); //1 second delay
   DIO_voidSetPinValue(PORTB_ID, RE,PIN_LOW_ID);


	
}
void  LCD_voidWriteDATA( u8 Copy_u8DATA)
{
	/*RS=1--->pin0*/
    DIO_voidSetPinValue(LCD_PORT_CONTROL, RS,PIN_HIGH_ID);
 	/*RW=1--->pin1*/
    DIO_voidSetPinValue(LCD_PORT_CONTROL, RW,PIN_LOW_ID);
    /*Send Data*/
    DIO_voidSetPortValue(LCD_PORT_DISPLAY,Copy_u8DATA);
    /*Enable Pulse*/
    DIO_voidSetPinValue(LCD_PORT_CONTROL, RE,PIN_HIGH_ID);
	_delay_ms(2); //1 second delay
    DIO_voidSetPinValue(LCD_PORT_CONTROL, RE,PIN_LOW_ID);
}

void LCD_GoToXY(u8 Copy_u8X, u8 Copy_u8Y)
{
	u8 LOC_Default=128;
if (Copy_u8X==0)
{
	LOC_Default= LOC_Default+Copy_u8Y;
	LCD_voidWriteCommand(LOC_Default);
}
else
{
	LOC_Default= LOC_Default+Copy_u8Y+0X40;

	LCD_voidWriteCommand(LOC_Default);
}
}
void LCD_WriteString(u8 *Copy_u8String)
{
 u8 i=0;
 while (Copy_u8String[i]!='\0')
 {
	 LCD_GoToXY(0,i);
		LCD_voidWriteDATA (Copy_u8String[i]);
		i++;
 }
}

void LCD_voidDisplayNumber(u32 Copy_u8DATA)
{
	s8 count=0 ,cont=0;
	u32 arr[100];

	while (Copy_u8DATA != 0)
	{
		cont=Copy_u8DATA %10 ;
		Copy_u8DATA=Copy_u8DATA/10 ;
		arr[count]=cont;
		count++ ;
	}

	for (s8 i=count-1;i>=0;i--)
	{
		LCD_voidWriteDATA(arr[i]+48);
	}


}
void LCD_voidWriteSpecialChar(u8 *Copy_u8SPECIAL,u8 Copy_u8Loc,u8 Copy_u8X,u8 Copy_u8Y)
{
	LCD_voidWriteCommand(64+(Copy_u8Loc*8));
for (u8 i=0;i<8;i++){
	LCD_voidWriteDATA(Copy_u8SPECIAL[i]);
}
LCD_GoToXY(Copy_u8X,Copy_u8Y);
LCD_voidWriteDATA(Copy_u8Loc);

}


void LCD_Clear(void)
{
	LCD_voidWriteCommand (1);

}
void LCD_Shift(u8 *Copy_u8String)
{
	u8 i=0,temp;

	while(i<16){
	 while (Copy_u8String[i]!='\0')
	 {
		 LCD_GoToXY(0,i);
			LCD_voidWriteDATA (Copy_u8String[i]);
			i++;
	 }
	// _delay_ms(5);
	 LCD_Clear();
	 temp++;

	}
}





