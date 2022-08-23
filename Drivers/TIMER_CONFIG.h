#ifndef  _TIMER_PRIVATE
#define  _TIMER_PRIVATE




#define  TCCRO          *((volatile u8*) 0x53)
#define  TCNTO          *((volatile u8*) 0x52)
#define  TIMSK          *((volatile u8*) 0x59)
#define  OCRO           *((volatile u8*) 0x5C)
#define TCCR1A          *((volatile u16*) 0x4F)
#define TCCR1B          *((volatile u16*) 0x4E)
#define OCR1A           *((volatile u16*) 0x4A)
#define ICR1            *((volatile u16*) 0x46)




#endif
