
#include "GPIO_Config.h"

void configGPIOC(void) {

    GPIOC->CRH &= ~(0xF << 20); 
    GPIOC->CRH |= (0x3 << 20); 
}

