

#ifndef __STM32F103C8T6__

#define __STM32F103C8T6__

#include <stdio.h> 
#include <stdlib.h>

#define RCC_BASE_ADDR 0x40021000
#define GPIOC_BASE_ADDR 0x40011000




#define RCC ((RCC_Typedef*) RCC_BASE_ADDR)

/* khong can phai khai bao cu the de co the truy cap CRL CRH..
 * mà chỉ địa chỉ để ép kiểu về con trỏ GPIO_Typedef 
 * thì nó sẽ hiểu là trong đấy sẽ có cấu trúc CRL, CRH...
*/
#define GPIOC ((GPIO_Typedef*) GPIOC_BASE_ADDR)

typedef struct {
    volatile uint32_t CR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR; 
    volatile uint32_t APB2RSTR;
    volatile uint32_t APB1RSTR;
    volatile uint32_t AHBENR;
    volatile uint32_t APB2ENR;
    volatile uint32_t APB1ENR;
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
} RCC_Typedef; 


/* typedef ở đây không dùng để tạo một đối tương GPIO_Typedef cụ thể 
 * mà nó đang dùng để phân chia vùng nhớ theo đúng với vị trí 
 * thanh ghi trong con chip
*/ 
typedef struct {
    volatile uint32_t CRL;
    volatile uint32_t CRH;
    volatile uint32_t IDR; 
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t BRR;
    volatile uint32_t LCKR;
} GPIO_Typedef;


#endif

