/*
This program will take an integer from 1-7
and output a day of the week
COMP-1400 Lab 6
Exercise 5
Developed by: Lucas Sarweh
Version: 1
Date: 2 Nov 2020
*/

// Include standard input/output
#include <stdio.h>

// Program execution starts at main
int main(void){

    //Define any variables needed
    int day;

    // Weclome message
    puts("Welcome! This program asks for a day number\n"
    "and will tell you what day of the week it is.");

    // Prompt message
    printf("Please input an integer: ");

    // Store input into memory
    scanf("%d", &day);

    // Switch statement will decide what day the user has chosen
    switch(day){

        case 1: // Monday
            
            // Display it is monday
            puts("Monday");
            break;
        
        case 2: // Tuesday

            // Display it is tuesday
            puts("Tuesday");
            break;
        
        case 3: // Wednesday

            // Display it is wednesday
            puts("Wednesday");
            break;
        
        case 4: // Thursday

            // Display it is thursday
            puts("Thursday");
            break;
        
        case 5: // Friday

            // Display it is friday
            puts("Friday");
            break;
        
        case 6: // Saturday

            // Display it is saturday
            puts("Saturday");
            break;
        
        case 7: // Sunday

            // Display it is sunday
            puts("Sunday");
            break;
        
        default: // Anything invalid

            // Display invalid day of the week
            puts("This number is beyond the number of days in a week.");

    }
}