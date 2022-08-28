#include "STD-TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "SPI_INTERFACE.h"
#include "SPI_PRIVATE.h"




void SPI_voidMasterInit()
{
	//SPCR=0b1101
	/*Excute SPI*/ 
	CLR_BIT(SPCR,PIN7_ID);

	/*Enable SPI*/ 
	SET_BIT(SPCR,PIN6_ID);
	SET_BIT(SPCR,PIN5_ID);

	/*Enable Master*/ 
	SET_BIT(SPCR,PIN4_ID);
	/*Clock Rate*/ 
	SET_BIT(SPCR,PIN0_ID);
	CLR_BIT(SPCR,PIN1_ID);


	SET_BIT(SPCR,PIN2_ID);
	CLR_BIT(SPCR,PIN3_ID);

	SET_BIT(SPSR,0);
	DIO_voidSetPinDirection(PORTD_ID,PIN5_ID,1);
	DIO_voidSetPinDirection(PORTD_ID,PIN6_ID,0);
	DIO_voidSetPinDirection(PORTD_ID,PIN7_ID,1);
	DIO_voidSetPinDirection(PORTD_ID,PIN4_ID,0);




}
void SPI_voidSlaveInit()
{
	/*Excute SPI*/ 
	CLR_BIT(SPCR,PIN7_ID);

	/*Enable SPI*/ 
	SET_BIT(SPCR,PIN6_ID);
	SET_BIT(SPCR,PIN5_ID);

	/*Enable Slave*/ 
	CLR_BIT(SPCR,PIN4_ID);
	/*Clock Rate*/ 
	SET_BIT(SPCR,PIN0_ID);
	CLR_BIT(SPCR,PIN1_ID);


	SET_BIT(SPCR,PIN2_ID);
	CLR_BIT(SPCR,PIN3_ID);

	SET_BIT(SPSR,0);

	DIO_voidSetPinDirection(PORTD_ID,PIN5_ID,0);
	DIO_voidSetPinDirection(PORTD_ID,PIN6_ID,1);
	DIO_voidSetPinDirection(PORTD_ID,PIN7_ID,0);
	DIO_voidSetPinDirection(PORTD_ID,PIN4_ID,0);

}

u8   SPI_u8Transceiver(u8 Copy_u8Data)
{
	SPDR=Copy_u8Data;
	while (GET_BIT(SPCR,PIN7_ID)==0);
	return SPCR;
}
