#include "stm32f103xb.h"

#define PIN5      (1U << 5)
#define PIN13      (1U << 13)
#define SystemCoreClock 72000000

void SysTick_Init(void);
void delay_ms(uint32_t ms);

int main(void) {
    SysTick_Init();
//clock access to APB2, ENABLING GPIOA,GPIOC
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;//for led
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;//for push button


    //GPIOA register setting for funcctionality and speed
    GPIOA->CRL &= ~(0xF << (5 * 4)); // clear CNF+MODE for pin 5
    GPIOA->CRL |=  (0x2 << (5 * 4)); // output mode, 2 MHz, push-pull
    //GPIOC register setting for functionality and speed
    GPIOC->CRL &= ~(0xF << (5 * 4)); // clear CNF+MODE for pin 5
    GPIOC->CRL |=  (0x2 << (5 * 4)); // output mode, 2 MHz, push-pull

    GPIOC->ODR |=  ~(1U << 13);//enables the internal pull down resistor to pin 13

    while (1) {
    	if(!(GPIOC->IDR & (1U << 13))==0){
    		GPIOA->BRR  =(1U<<5);
    	}else{
			GPIOA->BSRR =(1U<<5);
    	}
    }
}













void SysTick_Init(void) {
    SysTick->LOAD = (SystemCoreClock / 1000) - 1; // 1ms tick
    SysTick->VAL = 0;
    SysTick->CTRL = 5; // Enable | No interrupt | Processor clock
}

void delay_ms(uint32_t ms) {
    for (uint32_t i = 0; i < ms; i++) {
        while ((SysTick->CTRL & (1 << 16)) == 0);
    }
}
