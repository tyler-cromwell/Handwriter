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

#include "trig.h"


double _sideB(double l) {
    return sqrt(pow(H, 2.0) + pow(L + l, 2.0));
}


double _length(double b) {
    return sqrt(pow(b, 2.0) - pow(H, 2.0)) - L;
}


double _height(double l) {
    double b = _sideB(l);
    double p1 = (-1.0 * A + b + C + D);
    double p2 = (A - b + C + D);
    double p3 = (A - b + C - D);
    double p4 = (A - b - C + D);
    return sqrt(p1 * p2 * p3 * p4) / (2.0 * abs(b - A));
}


double _theta1(double f, double b) {
    return DEGREES(atan(f / b));
}


double _theta2(double l) {
    double h = _height(l);
    if (h >= C) {
        // Need this if statement
        return 90.0;
    } else {
        return DEGREES(asin(h / C));
    }
}


double _theta2h(double l) {
    return 90.0 - DEGREES(acos(H / _sideB(l)));
}


double _theta3(double l) {
    return 180.0 - _theta2(l);
}


double _theta4(double l) {
    return DEGREES(acos(_height(l) / D)) + 90.0;
}
