/*
Sample problem 11
Lucas Sarweh
*/

// Include header files
#include <stdio.h>
#include <math.h>
// Define macros

// This function calculates distance between two points
double distance(double x1, double y1, double x2, double y2){
    // Return the distance
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main(void){
    double pee = 3.33;
    double peee = 45.2;
    double poo = 32.1;
    double pooo = 2.11;

    printf("%lf", distance(pee, poo, peee, pooo));
}