#include "RCC_Config.h"

volatile unsigned int* CR      = (volatile unsigned int*)(RCC_BASE_ADDR + 0x00); 
volatile unsigned int* CFGR    = (volatile unsigned int*)(RCC_BASE_ADDR + 0x04); 
volatile unsigned int* CIR     = (volatile unsigned int*)(RCC_BASE_ADDR + 0x08); 
volatile unsigned int* APB2RSTR = (volatile unsigned int*)(RCC_BASE_ADDR + 0x0C); 
volatile unsigned int* APB1RSTR = (volatile unsigned int*)(RCC_BASE_ADDR + 0x10); 
volatile unsigned int* AHBENR  = (volatile unsigned int*)(RCC_BASE_ADDR + 0x14); 
volatile unsigned int* APB2ENR = (volatile unsigned int*)(RCC_BASE_ADDR + 0x18); 
volatile unsigned int* APB1ENR = (volatile unsigned int*)(RCC_BASE_ADDR + 0x1C); 
volatile unsigned int* BDCR    = (volatile unsigned int*)(RCC_BASE_ADDR + 0x20); 
volatile unsigned int* CSR     = (volatile unsigned int*)(RCC_BASE_ADDR + 0x24); 

void configRCC(void) {

    *CR = 0x03037D83; 
    *CFGR = 0x075DFFFA; 
    *AHBENR = 0x14; 
    *APB2ENR = 0x10;
    *CSR = 0x1C000000;
    
}

