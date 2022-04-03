#include "main.h"

MultiStepper stepper;
AccelStepper FL_Stepper(1, 22, 24);
AccelStepper FR_Stepper(1, 23, 25);
AccelStepper BL_Stepper(1, 28, 30);
AccelStepper BR_Stepper(1, 29, 31);

long forward[4] = {200, -200, 200, -200};
long backward[4] = {-200, 200, -200, 200};
long left[4] = {-200, -200, 200, 200};
long right[4] = {200, 200, -200, -200};

String buf;
positon pos;

void init_stepper()
{
  FL_Stepper.setMaxSpeed(MAX_SPEED);
  FR_Stepper.setMaxSpeed(MAX_SPEED);
  BL_Stepper.setMaxSpeed(MAX_SPEED);
  BR_Stepper.setMaxSpeed(MAX_SPEED);

  stepper.addStepper(FL_Stepper);
  stepper.addStepper(FR_Stepper);
  stepper.addStepper(BL_Stepper);
  stepper.addStepper(BR_Stepper);
}

void stepper_run()
{
  if (Serial.available())
  {
    buf = Serial.readStringUntil('\n');
    if (buf == "w" || buf == "W")
    {
      pos = go_forward;
    }
    if (buf == "s" || buf == "S")
    {
      pos = go_backward;
    }
    if (buf == "a" || buf == "A")
    {
      pos = go_left;
    }
    if (buf == "d" || buf == "D")
    {
      pos = go_right;
    }
  }
  switch (pos)
  {
  case go_forward:
    stepper.moveTo(forward);
    stepper.runSpeedToPosition();
    break;

  case go_backward:
    stepper.moveTo(backward);
    stepper.runSpeedToPosition();
    break;

  case go_left:
    stepper.moveTo(left);
    stepper.runSpeedToPosition();
    break;

  case go_right:
    stepper.moveTo(right);
    stepper.runSpeedToPosition();
    break;

  default:
    FL_Stepper.setCurrentPosition(0);
    FR_Stepper.setCurrentPosition(0);
    BL_Stepper.setCurrentPosition(0);
    BR_Stepper.setCurrentPosition(0);
    break;
  }
}
