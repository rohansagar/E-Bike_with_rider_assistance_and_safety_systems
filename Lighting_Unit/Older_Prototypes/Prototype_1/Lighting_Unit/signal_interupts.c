/*
 * signal_interupts.c
 *
 *  Created on: Feb 20, 2019
 *      Author: rohan
 */

#include "signal_interupts.h"

// This functions sets up the signal interrupts
void initialize_signals()
{

    // Enable the Switch ports.
    SysCtlPeripheralEnable(SYS_TURN_PORT);
    while(!SysCtlPeripheralReady(SYS_TURN_PORT));

    //Unlocking Port F
    GPIO_PORTF_LOCK_R = 0x4C4F434B;
    GPIO_PORTF_CR_R |= 0x01; 

    //Configuring Pins as inputs
    GPIOPinTypeGPIOInput(TURN_PORT_BASE, LEFT_TURN_PIN|RIGHT_TURN_PIN);
    GPIOPadConfigSet(TURN_PORT_BASE, LEFT_TURN_PIN|RIGHT_TURN_PIN, GPIO_STRENGTH_8MA, GPIO_PIN_TYPE_STD_WPU);

    // Configuring Interrupts
    GPIOIntRegister(TURN_PORT_BASE, buttons_ISR);
    GPIOIntTypeSet(TURN_PORT_BASE, LEFT_TURN_PIN|RIGHT_TURN_PIN , GPIO_FALLING_EDGE);
    GPIOIntEnable(TURN_PORT_BASE, LEFT_TURN_PIN|RIGHT_TURN_PIN);

}


// this function is for turn switches

void buttons_ISR()
{
    // storing the interrupt status register
    uint32_t int_status = GPIOIntStatus(TURN_PORT_BASE, true);

    if  ( (int_status & LEFT_TURN_PIN) == LEFT_TURN_PIN){
        status.right = 0;
        status.left = !(status.left);
    }

    if((int_status & RIGHT_TURN_PIN) == RIGHT_TURN_PIN){
        status.left = 0;
        status.right = !(status.right);
    }
    SysCtlDelay(SysCtlClockGet()/3/10); // for de-bouncing a delay of 1/8th second
    GPIOIntClear(TURN_PORT_BASE, LEFT_TURN_PIN| RIGHT_TURN_PIN );
}
