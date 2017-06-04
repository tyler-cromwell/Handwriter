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
#include "arm.h"
#include "trig.h"

// Off <= 0, On > 0
#define MAIN_DEBUG 1


/**
 * Arduino startup function.
 */
void setup() {
    Serial.begin(9600);
    arm_setup(3, 5, 6, 9);
    arm_reset();
    delay(1500);
}


/**
 * Arduino loop function.
 */
void loop() {
#if (MAIN_DEBUG > 0)
    if (Serial.available()) {
        char ch = Serial.read();

        switch (ch) {
            case 'r': arm_reset();          break;
            case 'p': arm_set_extension(0); break;
            case 'e': arm_set_extension(6); break;
        }
    }
#else
    if (ch >= 'a' && ch <= 'z') {
        ch -= 32;
        Serial.print(ch);
    }

    switch (ch) {
        case 'A': drawA(); break;
        case 'B': drawB(); break;
        case 'C': drawC(); break;
        case 'D': drawD(); break;
        case 'E': drawE(); break;
        case 'F': drawF(); break;
        case 'G': drawG(); break;
        case 'H': drawH(); break;
        case 'I': drawI(); break;
        case 'J': drawJ(); break;
        case 'K': drawK(); break;
        case 'L': drawL(); break;
        case 'M': drawM(); break;
        case 'N': drawN(); break;
        case 'O': drawO(); break;
        case 'P': drawP(); break;
        case 'Q': drawQ(); break;
        case 'R': drawR(); break;
        case 'S': drawS(); break;
        case 'T': drawT(); break;
        case 'U': drawU(); break;
        case 'V': drawV(); break;
        case 'W': drawW(); break;
        case 'X': drawX(); break;
        case 'Y': drawY(); break;
        case 'Z': drawZ(); break;
    }
#endif
}
