#ifndef  _ADC_INTERFACE_
#define  _ADC_INTERFACE_


void ADC_voidInit();          // default i choose ADC0  // prescaler /64

u16 ADC_u16GetResult();

void ADC_voidSingleRead();


void ADC_voidSelectChannel(u8 Copy_u8ChannelNUM);

void ADC_voidSelectPreScaler(u8 Copy_u8ClkDiv);


#endif
