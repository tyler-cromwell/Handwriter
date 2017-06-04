/**********************************************************************
  Copyright (C) 2017 Tyler Cromwell <tjc6185@gmail.com>

  This file is part of Handwriter.

  Handwriter is free software: you can redistribute it and/or modify
  it under Version 2 of the terms of the GNU General Public License
  as published by the Free Software Foundation.

  Handwriter is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY of FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Ritchie.
  If not, see <http://www.gnu.org/licenses/old-licenses/gpl-2.0.html>
**********************************************************************/
#include <math.h>
#include <Arduino.h>
#include <Servo.h>

#include "arm.h"
#include "trig.h"

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;


void _arm_servo2_write(double l) {
    servo2.write(THETA_INIT2 - (90.0 - _theta2(l)) - _theta2e(l));
}


void _arm_servo3_write(double l) {
    servo3.write(THETA_INIT3 - (_theta3(l) - 90));
}


void _arm_servo4_write(double l) {
    servo4.write(THETA_INIT4 - (_theta4(l) - 90));
}


void arm_setup(byte pin1, byte pin2, byte pin3, byte pin4) {
    servo1.attach(pin1);
    servo2.attach(pin2);
    servo3.attach(pin3);
    servo4.attach(pin4);
}


void arm_reset() {
#if (ARM_DEBUG > 0)
    Serial.println("========================================");
    Serial.println(">>> Arm reseting <<<");
#endif
    servo1.write(THETA_INIT1);  // Align to center stand
    servo2.write(THETA_INIT2);  // Point straight up
    servo3.write(THETA_INIT3);  // Point straight out
    servo4.write(THETA_INIT4);  // Point down
}


void arm_set_extension(double l) {
    double t2 = _theta2(l);
    double t3 = _theta3(l);
    double t4 = _theta4(l);

#if (ARM_DEBUG > 0)
    Serial.println("========================================");
    Serial.print(">>> Setting arm extension to ");  Serial.print(l);    Serial.println(" cm <<<");
#endif

    servo1.write(THETA_INIT1);
    _arm_servo2_write(l);
    _arm_servo3_write(l);
    _arm_servo4_write(l);

#if (ARM_DEBUG > 0)
    Serial.print("Servo 1: ");  Serial.print(servo1.read());    Serial.println(" deg");
    Serial.print("Servo 2: ");  Serial.print(servo2.read());    Serial.println(" deg");
    Serial.print("Servo 3: ");  Serial.print(servo3.read());    Serial.println(" deg");
    Serial.print("Servo 4: ");  Serial.print(servo4.read());    Serial.println(" deg");
    Serial.println();
    Serial.print("Theta 2: ");  Serial.print(t2);               Serial.println(" deg");
    Serial.print("Theta 3: ");  Serial.print(t3);               Serial.println(" deg");
    Serial.print("Theta 4: ");  Serial.print(t4);               Serial.println(" deg");
    Serial.print("Side B:  ");  Serial.print(_sideB(l));        Serial.println(" cm");
    Serial.print("Height:  ");  Serial.print(_height(l));       Serial.println(" cm");
#endif
}
