#ifndef _LCD_INTERFACE_H
#define _LCD_INTERFACE_H



void LCD_voidInit(void);
void LCD_Clear(void);
void LCD_voidWriteCommand(u8 Copy_u8Command);
void LCD_voidWriteDATA(u8 Copy_u8DATA);
void LCD_GoToXY(u8 X, u8 Y);
void LCD_WriteString(u8 *Copy_u8String);
void LCD_voidDisplayNumber(u32 Copy_u8DATA);
void LCD_voidWriteSpecialChar(u8 *Copy_u8SPECIAL,u8 Copy_u8Loc,u8 Copy_u8X,u8 Copy_u8Y);
void LCD_Shift(u8 *Copy_u8String);

#endif
