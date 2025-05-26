#include <stdio.h>
#include "stm32f103xb.h"
#include <stdint.h>

#define PIN5      (1U << 5)
#define PIN13      (1U << 13)
#define APB1         		SysCLK
#define sysCLK	 16000000
#define bd     	115200

void uart2_tx_init(void);
static void set_baudRate(uint32_t SystemCoreClock, uint32_t BaudRate) ;
void USART2_write(char ch);
//char USART2_read(void) ;

int main(void) {
	uart2_tx_init();

    while (1) {

//    		char c ;//= USART2_read();  // Receive char
    	    USART2_write('a');         // Echo back
            for (volatile int i = 0; i < 100000; i++); // crude delay

//    	    USART2_write(c);         // Echo back
    }
}

void uart2_tx_init(void){
	//1.Enable Clocks
	    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;     // Enable GPIOA clock
	    RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;     // Enable AFIO for alternate functions
	    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;   // Enable USART2 clock

	//2. Configure GPIOA Pins (PA2 = TX, PA3 = RX)
	    // PA2 = TX (AF Push-Pull)
	    GPIOA->CRL &= ~((0xF << (4*2)));        // Clear MODE2[1:0] + CNF2[1:0]
	    GPIOA->CRL |=  ((0xB << (4*2)));        // MODE2 = 11 (50 MHz), CNF2 = 10 (AF PP)

	    // PA3 = RX (input floating)
	    GPIOA->CRL &= ~(0xF << (4*3));	// Clear MODE2[1:0] + CNF2[1:0]
	    GPIOA->CRL |=  (0x4 << (4*3));    // Input floating

	//3. Configure USART2
	    set_baudRate(sysCLK,bd);

	//4.  Enable USART2, TX, RX
	    USART2->CR1 |= USART_CR1_TE  | USART_CR1_UE;
}
static void set_baudRate(uint32_t SystemCoreClock, uint32_t BaudRate) {
    USART2->BRR = ((SystemCoreClock + BaudRate / 2) / BaudRate);
}
void USART2_write(char ch) {
    while (!(USART2->SR & USART_SR_TXE)); // Wait until TXE (Transmit Data Register Empty)
    USART2->DR = ch;

}
//char USART2_read(void) {
//    while (!(USART2->SR & USART_SR_RXNE)); // Wait until RXNE (Read Data Register Not Empty)
//    return USART2->DR;
//}












