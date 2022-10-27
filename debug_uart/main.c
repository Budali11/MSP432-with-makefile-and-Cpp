/**
 * Copyright 2022 Budali11
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "user_core.h"
<<<<<<< HEAD
=======
#include "user_uart.h"
#include "user_dma.h"
>>>>>>> c3d1c48bb06eae38256c6d1954229bce8d1ad196
#include "iic_bus.h"
#include "flash.h"
#include "pcm.h"
#include "gpio.h"
#include "cs.h"

void Clock_Configuration(void);
void Clock_Information(void);
void Delay(uint32_t us)
{
    for(uint32_t i = 0; i < 48*us; i++);
}


int main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
	GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);
    GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0);
	Clock_Configuration();
<<<<<<< HEAD
    Delay(20);
    Peripheral_PreInit();

=======
    DMA_PreInit();
    UART_PreInit();
>>>>>>> c3d1c48bb06eae38256c6d1954229bce8d1ad196
    Printf("Yuki.\r\n");
    D_Printf("DMA_Yuki.\r\n");
    Delay(500);
    D_Printf("1234567890This is a test text.\r\n");
    while (1)
    {
        /* code */
    }
    

    return 0;
}

void Clock_Configuration(void)
{
    GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_PJ,
        GPIO_PIN2 | GPIO_PIN3, GPIO_PRIMARY_MODULE_FUNCTION);
    CS_setExternalClockSourceFrequency(32000, 48000000);

    PCM_setCoreVoltageLevel(PCM_VCORE1);
    FlashCtl_setWaitState(FLASH_BANK0, 2);
    FlashCtl_setWaitState(FLASH_BANK1, 2);
    CS_startHFXT(false);
    CS_initClockSignal(CS_ACLK, CS_LFXTCLK_SELECT, CS_CLOCK_DIVIDER_1); //ACLK == 32.768kHz
    CS_initClockSignal(CS_MCLK, CS_HFXTCLK_SELECT, CS_CLOCK_DIVIDER_1); //MCLK == 48MHz
    CS_initClockSignal(CS_HSMCLK, CS_MODOSC_SELECT, CS_CLOCK_DIVIDER_1); //HSMCLK == 24MHz
    CS_initClockSignal(CS_SMCLK, CS_MODOSC_SELECT, CS_CLOCK_DIVIDER_2); //SMCLK == 12MHz
    CS_initClockSignal(CS_BCLK, CS_LFXTCLK_SELECT, CS_CLOCK_DIVIDER_1); //BCLK == 32.768MHz

}

void Clock_Information(void)
{
    uint32_t ACLK, MCLK, HSMCLK, SMCLK, BCLK;

    ACLK = CS_getACLK();
    MCLK = CS_getMCLK();
    HSMCLK = CS_getHSMCLK();
    SMCLK = CS_getSMCLK();
    BCLK = CS_getBCLK();

    (void)ACLK;
    (void)MCLK;
    (void)HSMCLK;
    (void)SMCLK;
    (void)BCLK;
}