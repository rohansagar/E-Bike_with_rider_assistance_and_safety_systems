/*
 * main.c
 *
 *  Created on: Jun 30, 2019
 *      Author: rohan
 */



#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

#include "inc/hw_memmap.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_types.h"
#include "inc/hw_i2c.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "driverlib/debug.h"
#include "driverlib/interrupt.h"
#include "driverlib/i2c.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"

#include"pin_assignments.h"
#include "led_matrix.h"
#include"signal_interupts.h"


typedef enum{

    idle,
    left_flash,
    right_flash,

}state_t;


void main(void)
{
    // set system clock to 80 mhz
    SysCtlClockSet(SYSCTL_SYSDIV_2_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);
    // wait for like half a second
    SysCtlDelay(SysCtlClockGet()/3/2);
    // initialize the LED Matrix
    initialize_matrix(0xff);
    clear_display();
    initialize_signals();

    state_t state = idle;
    while(1){

        switch(state){

            case idle:{
                if(status.right == 1){
                    state = right_flash;
                }

                else if(status.left == 1){
                    state = left_flash;
                }

                else{
                    flash();
                    state = idle;
                }

            }

            case left_flash:{
                if(status.left == 0){
                    state = idle;
                }

                else{
                    left();
                    state = left_flash;
                }
            }
            case right_flash:{

                if(status.right == 0){
                    state = idle;
                }

                else{
                    right();
                    state = right_flash;
                }


            }

        }


//
//        if(status.left){
//            left();
//        }
//
//        if( status.right){
//            right();
//        }
//
//        flash();
    }

}




