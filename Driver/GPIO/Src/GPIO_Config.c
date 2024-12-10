
#include "GPIO_Config.h"

volatile unsigned int* CRL = (volatile unsigned int*)(GPIOC_BASE_ADDR); 
volatile unsigned int* CRH = (volatile unsigned int*)(GPIOC_BASE_ADDR + 0x04); 
volatile unsigned int* IDR = (volatile unsigned int*)(GPIOC_BASE_ADDR + 0x08); 
volatile unsigned int* ODR = (volatile unsigned int*)(GPIOC_BASE_ADDR + 0x0C); 
volatile unsigned int* BSRR = (volatile unsigned int*)(GPIOC_BASE_ADDR + 0x10); 
volatile unsigned int* BRR = (volatile unsigned int*)(GPIOC_BASE_ADDR + 0x14); 
volatile unsigned int* LCKR = (volatile unsigned int*)(GPIOC_BASE_ADDR + 0x18); 

void configGPIOC(void) {

    *CRH &= ~(0xF << 20); 
    *CRH |= (0x3 << 20); 
}

// Hàm toggle LED
void toggleLed(void) {
    *ODR ^= (1 << 13);
    for(int i = 0; i < 500; i++);

}


