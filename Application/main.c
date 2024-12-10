
#include "RCC_Config.h"
#include "GPIO_Config.h"
#include "Control_Led.h"

void main (void) {

    configRCC(); 
    configGPIOC(); 

    while(1) {
        //toggleLed
        toggleLed(); 

    }
}
