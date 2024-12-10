
#ifndef __GPIO__

#define __GPIO__

#include <stdio.h> 


#define GPIOC_BASE_ADDR 0x40011000

void configGPIOC(void); 
void toggleLed(void); 

#endif

