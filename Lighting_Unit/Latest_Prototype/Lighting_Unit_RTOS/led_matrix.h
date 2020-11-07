/*
 * led_matrix.h
 *
 *  Created on: Feb 11, 2019
 *      Author: rohan
 */

#ifndef LED_MATRIX_H_
#define LED_MATRIX_H_
#include <stdbool.h>
#include <stdint.h>
#include "pin_assignments.h"
#include "driverlib/ssi.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"


#define intensity_value 0x00

struct{
    bool left;
    bool right;
}status;

// Control Registers
typedef enum {
    NOOP        =    0,
    DECODE      =    9,
    INTENSITY   =   10,
    SCANLIMIT   =   11,
    SHUTDOWN    =   12,
    DISPTEST    =   15,
}control_register;


// Decode Modes
enum {
    NODECODE    =   0,
    CB0         =   1,
    CB30        =   15,
    CBALL       =  255,
} decode_mode;



void initialize_matrix(uint8_t);
void set_control_register(control_register control_reg_temp , uint8_t value);
void clear_display(void);
void left(void);
void right(void);
void flash(void);
#endif /* LED_MATRIX_H_ */
