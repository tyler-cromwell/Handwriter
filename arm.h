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
#ifndef ARM_H
#define ARM_H

// Off <= 0, On > 0
#define ARM_DEBUG 0


/**
 * Raise the arm to stop drawing.
 */
extern void arm_raise();


/**
 * Lower the arm to start drawing.
 */
extern void arm_lower();


/**
 * Set arm to default position.
 */
extern void arm_reset();


/**
 * Set arm to starting position.
 */
extern void arm_prepare();


/**
 * Extend the arm out by the given length.
 * 
 * Parameters:
 *   double l: The length to extend by (centimeters).
 */
extern void arm_extend(double l);


/**
 * Parameters:
 *   double f: Half the length of the line to draw (centimeters).
 *   double l: The length to extend by (centimeters).
 */
extern void arm_draw_side(double f, double l);


/**
 * UNTESTED CODE!
 * CHECK FOR DIRECTION AND IF ANGLE SIGNS ARE CORRECT!
 */
extern void arm_draw_forward(double f, double g, double l);


#endif
