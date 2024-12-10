
#include "Control_Led.h"

// Hàm toggle LED
void toggleLed(void) {
    GPIOC->ODR ^= (1 << 13);
    for(int i = 0; i < 500; i++);

}


