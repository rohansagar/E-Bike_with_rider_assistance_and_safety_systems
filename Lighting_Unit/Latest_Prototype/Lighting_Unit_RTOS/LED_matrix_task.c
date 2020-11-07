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


#define LEDMARTIXTASKSTACKSIZE 128
/*
 * @brief: This function initializes the LED matrix display and creates the task
 */

static void LED_matrix_task(void *pvParameters){

    // this task is responsible for updating the led matrix
    while (1)
    {
        flash();
      }


}
void LED_martix_task_init(void){

    // Initialize the LED matrix display
    initialize_matrix(0xff);
    clear_display();

    // create the LED matrix task
    xTaskCreate(LED_matrix_task, (const portCHAR *)"LED_matrix_task",
                       LEDMARTIXTASKSTACKSIZE, NULL, tskIDLE_PRIORITY +
                       PRIORITY_LED_MATRIX_TASK, NULL) != pdTRUE;

}
