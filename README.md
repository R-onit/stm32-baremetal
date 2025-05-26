# STM32 Bare-Metal Project Collection

A curated collection of STM32F103C8T6 bare-metal projects developed without HAL or LL libraries, using STM32CubeIDE.  
Demonstrates direct register-level programming showcasing fundamental embedded concepts.

---

## Projects Overview

| Project Name                     | Description                                      |
|---------------------------------|------------------------------------------------|
| [UART](UART)                    | Basic UART communication: send "Hello World" via USART2 at 9600 baud. |
| [Button_LED](Button_LED)        | Control the on-board LED using a push button, implemented bare-metal. |
| [Blinky](Blinky)                | Simple bare-metal LED toggling on the built-in board LED. |

---

## CMSIS Headers

The `cmsis/` folder contains minimal CMSIS core and device headers required for STM32F103C8T6 development.

---

## Usage

1. Clone the repo:
   ```bash
   git clone https://github.com/R-onit/stm32-baremetal.git


## Setup
- IDE: STM32CubeIDE
- MCU: STM32F103C8T6
- Programmer: ST-Link V2

## Build Steps
1. Open STM32CubeIDE
2. Import project: File > Import > Existing Projects into Workspace
3. Flash to board
