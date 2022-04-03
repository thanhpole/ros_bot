#if !defined(MAIN_H)
#define MAIN_H

#include <Arduino.h>
#include "AccelStepper.h"
#include "MultiStepper.h"
#include "ros.h"

#define MAX_SPEED 1000

extern MultiStepper stepper;
extern AccelStepper FL_Stepper;
extern AccelStepper FR_Stepper;
extern AccelStepper BL_Stepper;
extern AccelStepper BR_Stepper;

enum positon
{
  go_forward,
  go_backward,
  go_left,
  go_right
};

extern long forward[4];
extern long backward[4];
extern long left[4];
extern long right[4];

void init_stepper();
void stepper_run();

#endif // MAIN_H
