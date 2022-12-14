#ifndef _DIO_INTERFACE_H
#define _DIO_INTERFACE_H

#define PORTA_ID (0X00)
#define PORTB_ID (0X01)
#define PORTC_ID (0X02)
#define PORTD_ID (0X03)

/*Pin ID Macros*/


#define PIN0_ID  (0X00)
#define PIN1_ID  (0X01)
#define PIN2_ID  (0X02)
#define PIN3_ID  (0X03)
#define PIN4_ID  (0X04)
#define PIN5_ID  (0X05)
#define PIN6_ID  (0X06)
#define PIN7_ID  (0X07)


/*Direction Macros*/
#define PIN_OUTPUT_ID (0X01)
#define PIN_INPUT_ID  (0X00)
#define ALL_PORT_OUT  (0XFF)
#define ALL_PORT_IN   (0X00)



#define PIN_HIGH_ID   (0X01)
#define PIN_LOW_ID    (0X00)
#define ALL_PORT_HIGH (0XFF)
#define ALL_PORT_LOW  (0X00)







    /* Prototypes*/ 

void DIO_voidSetPinDirection(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinDir);
void DIO_voidSetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinValue);
void DIO_voidSetPortDirection(u8 Copy_u8PortID, u8 Copy_u8PortDir);
void DIO_voidSetPortValue(u8 Copy_u8PortID, u8 Copy_u8PortValue);
void DIO_voidTogPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID);
u8 DIO_voidGetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID);

 

#endif 
