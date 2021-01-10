/*
 * LED_matrix_task.c
 *
 *  Created on: Nov 1, 2020
 *      Author: rohan
 */
#include <stdint.h>
#include "pin_assignments.h"
#include "LED_matrix_task.h"
#include "FreeRTOS.h"
#include "task.h"
#include "priorities.h"
#include "led_matrix.h"
#include "signal_interupts.h"


#define LEDMARTIXTASKSTACKSIZE 128
/*
 * @brief: This function initializes the LED matrix display and creates the task
 */

/*
 type definition for state
 */
typedef enum{

    idle,
    left_flash,
    right_flash,

}state_t;

state_t state= idle; //Initializing state to idle


static void LED_matrix_task(void *pvParameters){

    // this task is responsible for updating the led matrix
    while (1){

        switch(state){

           case idle:{

               if(status.right == 1){
                   state = right_flash;
                        }
               else if(status.left == 1){
                    state = left_flash;
                        }
               else{
                    flash(2);
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


    }

}
void LED_martix_task_init(void){


    // Initialize the LED matrix display
    initialize_matrix(0xff);
    clear_display();

    // Enable turn signal buttons
    initialize_signals();

    // create the LED matrix task
    xTaskCreate(LED_matrix_task, (const portCHAR *)"LED_matrix_task",
                       LEDMARTIXTASKSTACKSIZE, NULL, tskIDLE_PRIORITY +
                       PRIORITY_LED_MATRIX_TASK, NULL) != pdTRUE;

}
