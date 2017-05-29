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


void arm_setup(byte pin1, byte pin2, byte pin3, byte pin4) {
    servo1.attach(pin1);
    servo2.attach(pin2);
    servo3.attach(pin3);
    servo4.attach(pin4);
}


void arm_raise() {
    servo2.write(servo2.read() + 15.0);
}


void arm_lower() {
    servo2.write(servo2.read() - 15.0);
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


void arm_prepare() {
    double t2 = _theta2(0.0);
    double t2h = _theta2h(0.0);
    double t3 = _theta3(0.0);
    double t4 = _theta4(0.0);

#if (ARM_DEBUG > 0)
    Serial.println("========================================");
    Serial.println(">>> Arm preparing <<<");
#endif
    servo1.write(THETA_INIT1);                    // Align to center stand
    servo2.write(THETA_INIT2 - 90.0 + t2 - t2h);  // Point straight up
    servo3.write(THETA_INIT3 + 90.0 - t3);        // Point straight out
    servo4.write(THETA_INIT4 + 90.0 - t4);        // Point down
#if (ARM_DEBUG > 0)
    Serial.print("Side B:\t\t");  Serial.print(_sideB(0.0));  Serial.println(" cm");
    Serial.print("Height:\t\t");  Serial.print(_height(0.0)); Serial.println(" cm");
    Serial.print("Theta1:\t\t");  Serial.print(0.0);          Serial.println(" deg");
    Serial.print("Theta2:\t\t");  Serial.print(t2);           Serial.println(" deg");
    Serial.print("Theta2h:\t");   Serial.print(t2h);          Serial.println(" deg");
    Serial.print("Theta3:\t\t");  Serial.print(t3);           Serial.println(" deg");
    Serial.print("Theta4:\t\t");  Serial.print(t4);           Serial.println(" deg");
#endif
}


void arm_extend(double l) {
    double t1 = servo1.read() - THETA_INIT1;
    double t2 = _theta2(l);
    double t2h = _theta2h(l);
    double t3 = _theta3(l);
    double t4 = _theta4(l);

#if (ARM_DEBUG > 0)
    Serial.println("========================================");
    Serial.print(">>> Extending tip by ");
    Serial.print(l);  Serial.println(" cm <<<");
#endif
    servo2.write(THETA_INIT2 - 90.0 + t2 - t2h);
    servo3.write(THETA_INIT3 + 90.0 - t3);
    servo4.write(THETA_INIT4 + 90.0 - t4);
#if (ARM_DEBUG > 0)
    Serial.print("Side B:\t\t");  Serial.print(_sideB(l));  Serial.println(" cm");
    Serial.print("Height:\t\t");  Serial.print(_height(l)); Serial.println(" cm");
    Serial.print("Theta1:\t\t");  Serial.print(t1);         Serial.println(" deg");
    Serial.print("Theta2:\t\t");  Serial.print(t2);         Serial.println(" deg");
    Serial.print("Theta2h:\t");   Serial.print(t2h);        Serial.println(" deg");
    Serial.print("Theta3:\t\t");  Serial.print(t3);         Serial.println(" deg");
    Serial.print("Theta4:\t\t");  Serial.print(t4);         Serial.println(" deg");
#endif
}


void arm_draw_side(double f, double l) {
    double b = L + l;
    double b1 = sqrt(pow(f, 2.0) + pow(b, 2.0));
    double t1 = _theta1(f, b);

    // Move to one side & extend to new length
    servo1.write(THETA_INIT1 + t1);
    arm_extend(b1 - L);
    delay(1500);

    // Draw to center
    //servo1.write(THETA_INIT1);
    //arm_extend(b - L);
    //delay(1500);

    // Draw to other side
    servo1.write(THETA_INIT1 - t1);
    arm_extend(b1 - L);
    delay(1500);
}


/**
 * UNTESTED CODE!
 * CHECK FOR DIRECTION AND IF ANGLE SIGNS ARE CORRECT!
 */
void arm_draw_forward(double f, double g, double l) {
    double b = _sideB(l);
    double b1 = sqrt(pow(f, 2.0) + pow(b, 2.0));
    double b2 = sqrt(pow(f, 2.0) + pow(b + g, 2.0));
    double theta1 = _theta1(f, b);
    double theta1a = _theta1(f, b + g);

    // Center
    arm_extend(l);
    arm_raise();
    delay(500);

    // Move to one side & extend to new length
    servo1.write(THETA_INIT1 + theta1);
    arm_extend(_length(b1));
    arm_raise();
    delay(500);

    // Prepare to write
    arm_lower();
    delay(500);

    // Draw to extension
    servo1.write(THETA_INIT1 + theta1a);
    arm_extend(_length(b2));
    delay(500);
}
