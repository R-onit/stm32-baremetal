#include "stm32f103xb.h"

#define PIN5      (1U << 5)
#define PIN5_NUM  5
#define SystemCoreClock 72000000

void SysTick_Init(void);
void delay_ms(uint32_t ms);

int main(void) {
    SysTick_Init();
    /*(USING RCC registors->to enable clock access to APB2 bus)
     	 	 the RCC registers have have 32-bits ,enabling the bit 2 of IOPAEN*/
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

    /*(LETS SET PIN5->using GPIO registors)
     * now we need to configure the port -> what do we want__output led,working at 2MHz
     * [CNF1 CNF2 MODE1 MODE2]->[0010]
     * MODE->sets output speed and input mode
     * CNF ->sets functionality type*/
    GPIOA->CRL &= ~(0xF << (PIN5_NUM * 4)); // clear CNF+MODE for pin 5
    GPIOA->CRL |=  (0x2 << (PIN5_NUM * 4)); // output mode, 2 MHz, push-pull


    /*lets loop the logic to toggle led*/
    while (1) {
        GPIOA->BSRR = PIN5;  // Set PA5 high
        delay_ms(500);
        GPIOA->BRR  = PIN5;  // Set PA5 low
        delay_ms(500);
    }
}
/*some more control registers of GPIO
 IDR-->reads the input state of the pin -(uint8_t state = (GPIOA->IDR & (1 << 0)) ? 1 : 0;)
 ODR-->set/reset pin output manually [read/write]
 BSRR-->Atomic (single write sets/resets without affecting others)set and reset of output pins[write only]*/













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
