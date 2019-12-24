/*
 *This file consists of all the pin assignment macros
  */
#include "stdint.h"
#include "stdbool.h"
#include "inc/hw_memmap.h"
#include "inc/hw_timer.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"
#include "driverlib/pin_map.h"





// Pin assignments for Turn and Brake switches
#define SYS_TURN_PORT          SYSCTL_PERIPH_GPIOF
#define TURN_PORT_BASE         GPIO_PORTF_BASE
#define LEFT_TURN_PIN               GPIO_PIN_4
#define RIGHT_TURN_PIN              GPIO_PIN_0
// Note: Both the turn switches are on one port

#define SYS_STOP_SWITCH_PORT        SYSCTL_PERIPH_GPIOE
#define STOP_SWITCH_PORT_BASE       GPIO_PORTE_BASE
#define STOP_SWITCH_PIN             GPIO_PIN_1

// Pin assignments for light flashing Timer
#define SYS_TIMER_PORT      SYSCTL_PERIPH_TIMER0
#define TIMER_PORT_BASE     TIMER0_BASE




