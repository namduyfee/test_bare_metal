#include "RCC_Config.h"

void configRCC(void) {

    RCC->CR = 0x03037D83; 
    RCC->CFGR = 0x075DFFFA; 
    RCC->AHBENR = 0x14; 
    RCC->APB2ENR = 0x10;
    RCC->CSR = 0x1C000000;
    
}

