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
#ifndef TRIG_H
#define TRIG_H

// Starting angles (Degrees)
#define THETA_INIT1 102   // Servo 1
#define THETA_INIT2 124   // Servo 2
#define THETA_INIT3  56   // Servo 3
#define THETA_INIT4 104   // Servo 4

// Side lengths (Centimeters)
#define A  9.80   // Length between Servo 3 and 4
#define C 10.40   // Length between Servo 2 and 3
#define D 13.50   // Length between Servo 4 and tip
#define H  7.30   // Height of Servo 2 from the writing surface
#define L 16.00   // Length between Servo 2 and tip at rest

// Convert Radians to Degrees
#define DEGREES(rad) ((rad) * (180.0 / M_PI))


/**
 * Calculates the length of the trapezoid base given an extension amount.
 */
extern double _sideB(double l);


/**
 * Calculates the extension length given the length of the trapezoid base.
 */
extern double _length(double b);


/**
 * Calculates the trapezoid height from the given extension length.
 */
extern double _height(double l);


/**
 * Calculate the angle for rotating Servo 1.
 * ONLY USE WITH SERVO 1!
 * 
 * Parameters:
 *   double f: The side extension length (centimeters).
 *   double b: The forward extension length (centimeters).
 */
extern double _theta1(double f, double b);


/**
 * Calculate the angle for rotating Servo 2.
 * ONLY USE WITH SERVO 2!
 * 
 * Parameters:
 *   double l: The extension length (centimeters).
 */
extern double _theta2(double l);


/**
 *
 */
extern double _theta2h(double l);


/**
 * Calulate the angle for rotating Servo 3.
 * ONLY USE WITH SERVO 3!
 * 
 * Parameters:
 *   double l: The extension length (centimeters).
 */
extern double _theta3(double l);


/**
 * Calulate the angle for rotating Servo 4.
 * ONLY USE WITH SERVO 4!
 * 
 * Parameters:
 *   double l: The extension length (centimeters).
 */
extern double _theta4(double l);


#endif
