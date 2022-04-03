#include "main.h"

void setup()
{
  Serial.begin(115200);
  init_stepper();
  // put your setup code here, to run once:
}

void loop()
{
  stepper_run();
  // put your main code here, to run repeatedly:
}