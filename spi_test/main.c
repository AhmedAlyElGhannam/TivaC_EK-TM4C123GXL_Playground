#include "tm4c123gh6pm.h"

#define RED_LED         (1U << 1)
#define BLUE_LED        (1U << 2)
#define GREEN_LED       (1U << 3)

/**
RGB LED:
Red LED: Connected to PF1 (Port F, Pin 1)
Blue LED: Connected to PF2 (Port F, Pin 2)
Green LED: Connected to PF3 (Port F, Pin 3)
User Switches:
SW1 (Left Switch): Connected to PF4 (Port F, Pin 4)
SW2 (Right Switch): Connected to PF0 (Port F, Pin 0)
*/

/**
 * will use SSI0 & SSI1
 * SSI0Clk -> PA2 (SCK)
 * SSI0Fss -> PA3 (CS)
 * SSI0Rx  -> PA4 (MISO)
 * SSI0Tx  -> PA5 (MOSI)
 *
 * SSI1Clk -> PF2 (SCK)
 * SSI1Fss -> PF3 (CS)
 * SSI1Rx  -> PF0 (MISO)
 * SSI1Tx  -> PF1 (MOSI)
 *
 * */

void main(void)
{
    /** SPI */
    // enable chosen chosen modules by writing 1 in corresponding bit (bit0->bit3 for 4 modules) RCGCSSI
    SYSCTL_RCGCSSI_R |= ((1U << 0) | (1U << 1)); // SSI0 && SSI1
    // enable clock for chosen SPI modules via GPIO port clock RCGCGPIO
    SYSCTL_RCGCGPIO_R |= ((1U << 0) | (1U << 5)); // port A && port F
    // enable advanced high-performance bus for port A && F cuz why not
    SYSCTL_GPIOHBCTL_R |= ((1U << 0) | (1U << 5));
    // enable AFSEL for GPIO pins corresponding to chosen SPI modules
    GPIO_PORTA_AHB_AFSEL_R |= ((1U << 2) | (1U << 3) | (1U << 4) | (1U << 5));
    GPIO_PORTF_AHB_AFSEL_R |= ((1U << 2) | (1U << 3) | (1U << 0) | (1U << 1));
    //enable MUX for GPIO pins GPIOPCTL
    GPIO_PORTA_AHB_PCTL_R |= ((0x02 << 8) | (0x02 << 12) | (0x02 << 16) | (0x02 << 24));
    GPIO_PORTF_AHB_PCTL_R |= ((0x02 << 0) | (0x02 << 4) | (0x02 << 8) | (0x02 << 12));
    // digital enable for SPI pins
    GPIO_PORTA_AHB_DEN_R |= ((1U << 2) | (1U << 3) | (1U << 4) | (1U << 5));
    GPIO_PORTF_AHB_DEN_R |= ((1U << 2) | (1U << 3) | (1U << 0) | (1U << 1));
    // drive current select for SPI pins (8mA)
    GPIO_PORTA_AHB_DR8R_R |= ((1U << 2) | (1U << 3) | (1U << 4) | (1U << 5));
    GPIO_PORTF_AHB_DR8R_R |= ((1U << 2) | (1U << 3) | (1U << 0) | (1U << 1));
    // drain select for SPI pins (pull-up res)
    GPIO_PORTA_AHB_PUR_R |= ((1U << 2) | (1U << 3) | (1U << 4) | (1U << 5));
    GPIO_PORTF_AHB_PUR_R |= ((1U << 2) | (1U << 3) | (1U << 0) | (1U << 1));
    // clear SSE bit in the SSICR1 register before configuration
    SSI0_CR1_R &= ~(1U << 1);
    SSI1_CR1_R &= ~(1U << 1);
    // make SPI module master or slave
    SSI0_CR1_R = (0x00000000); // SSI0 configured as master
    // SSI1_CR1_R |= (0x0000000C); // SSI1 configured as slave with disabled output
    SSI1_CR1_R = (0x00000004); // SSI1 configured as slave with enabled output
    // configure SPI clock source  SSICC
    SSI0_CC_R = (0x0); // system clock
    SSI1_CC_R = (0x0); // system clock
    // configure clock prescaler divisor SSICPSR
    SSI0_CPSR_R = (0x0A); // divide clock by 10 -> 16/10 = 1.6MHz
    SSI1_CPSR_R = (0x0A); // divide clock by 10 -> 16/10 = 1.6MHz
    // set SSICR0 according to desired config
    /**
     * data is captured on first clock edge transition (clk phase)
     * clk steady state value is low (clk polarity)
     * Freescale SPI (SPI mode)
     * 8-bit data size
     * */
    SSI0_CR0_R |= (0x7);
    SSI1_CR0_R |= (0x7);
    // OPTIONAL: configure DMA usage (I will ignore it)
    // enable SPI module(s)
    SSI0_CR1_R |= (1U << 1); // master (will send data)
    SSI1_CR1_R |= (1U << 1); // slave (will receive data)

    while(1)
    {
            // wait until master is ready to transmit
            while ((SSI0_SR_R & (1U << 1)) == 0);

            // write data to master
            SSI0_DR_R = 0xFE;

            // wait until slave has received data
            while ((SSI1_SR_R & (1U << 2)) == 0);

            // Read received data
            unsigned char hehe = 0;
            hehe = SSI1_DR_R;

            if (hehe)
            {

            }
    }
}
