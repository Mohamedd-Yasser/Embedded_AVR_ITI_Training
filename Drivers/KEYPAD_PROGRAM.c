#include "STD-TYPES.h"
#include "BIT_MATH.h"
#include "DIO_PRIVATE.h"
#include "DIO_Interface.h"
#include "KEYPAD_INTERFACE.h"
#include "KYP_CONFIG.h"
#include <util/delay.h>
#include "LCD_INTERFACE.h"


void KYP_Init(void)
{
	    DIO_voidSetPortDirection(KYP_PORT,FourOUT_FourIN);
		DIO_voidSetPortValue(KYP_PORT,All_HIGH);
}



u8 KYP_GetPressedKey(void)
{
	u8 LOC_SwitchValue[1][3]={
			                  {7,8,9},
		                      {4,5,6,'*'},
							  {1,2,3,'-'},
                              {'%',0,'=','+'}};

	u8 LOC_KeyState=No_Key_PRESSED;
	u8 LOC_Cols=0;
	u8 LOC_Rows=0;
	u8 LOC_CheackPressed=1;

	for (LOC_Cols=Col_Start ; LOC_Cols<Col_End ; LOC_Cols++)
	{
		DIO_voidSetPinValue (KYP_PORT,LOC_Cols,PIN_LOW_ID);
			for ( LOC_Rows=Row_Start;LOC_Rows<=Row_End;LOC_Rows++)
			{
				LOC_CheackPressed = DIO_voidGetPinValue(KYP_PORT,LOC_Rows);

				if (LOC_CheackPressed==0)
				{
					LOC_KeyState= LOC_SwitchValue[LOC_Rows-4][LOC_Cols];
					while(LOC_CheackPressed==0)
					{
						LOC_CheackPressed = DIO_voidGetPinValue(KYP_PORT,LOC_Rows);

					}
                    _delay_ms(50); 	
                     return LOC_KeyState;					
				}
			}
			
		DIO_voidSetPinValue (KYP_PORT,LOC_Cols,PIN_HIGH_ID); 

	}
	return LOC_KeyState;
	
}
void KYP_CALC()//does not work i dont know why
{
	u8 arr[4];
		u8 i=0;
	u8 KeyPadPressed=KYP_GetPressedKey();
				if (KeyPadPressed!=0xFF)
				{
					switch (KeyPadPressed)
					{

					case 42:LCD_voidWriteDATA(42);break;
					case 43:LCD_voidWriteDATA(43);break;
					case 45: LCD_voidWriteDATA(45);break;
					case 47:LCD_voidWriteDATA(47);break;
					case 61: LCD_voidWriteDATA(61);
					LCD_voidWriteDATA(KeyPadPressed);

					switch (arr[1])
					{
					LCD_voidWriteDATA(45);
					case 42:LCD_voidDisplayNumber(arr[0]*arr[2]);break;
					case 43:LCD_voidDisplayNumber(arr[0]+arr[2]);break;
			        case 45:LCD_voidDisplayNumber(arr[0]-arr[2]);break;
					case 47:LCD_voidDisplayNumber(arr[0]/arr[2]);break;
	                 }
					break;
					case 37:LCD_Clear();break;

					default: LCD_voidDisplayNumber(KeyPadPressed);break;


					}
					arr[i]=KeyPadPressed;
					LCD_voidWriteDATA(KeyPadPressed);

					i++;

				}
}








