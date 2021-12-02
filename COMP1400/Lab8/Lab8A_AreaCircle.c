/*
Lab 8 Part A - Area of a circle
COMP-1400
This program defines a function to
calculate the area of a circle.
Developed by: Lucas Sarweh
Version: 1
Date: 16 Nov 2020
*/

// Include the math header
#include <math.h>

// This function will calculate the area of a circle
double areaOfCircle(double radius){

    // This will calculate and return the area of a circle (pi(radius^2))
    return M_PI * (radius * radius);
}