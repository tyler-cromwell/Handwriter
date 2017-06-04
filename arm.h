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
#define ARM_DEBUG 1


/**
 * Initializes the servo controllers.
 */
extern void arm_setup(byte pin1, byte pin2, byte pin3, byte pin4);


/**
 * Set arm to default position.
 */
extern void arm_reset();


/**
 * Set arm to certain length outward.
 */
extern void arm_set_extension(double l);


#endif
