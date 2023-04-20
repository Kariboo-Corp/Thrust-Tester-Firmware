#ifndef MAIN_H
#define MAIN_H

#define LED_MCU 4

#define CLK_1 2
#define CLK_2 6
#define CLK_3 8
#define CLK_4 10

#define DATA_1 3
#define DATA_2 5
#define DATA_3 7
#define DATA_4 9

#define SWITCH  A0
#define POT     A1
#define PWM_OUT 4

const long LOADCELL_OFFSET = 50682624;
const long LOADCELL_DIVIDER = 5895655;


#endif