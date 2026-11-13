COMP-3300 Page 4
/* A Sample program to see how to find execution (CPU) time for execution in C.
/* **************************************************************************
* exec_time.c
* *********************************************************************** */
#include <stdio.h>
#include <time.h> // for clock_t, clock()
#include <unistd.h> // for sleep()
int main(void)
{
    double time_spent = 0.0; // to store execution time of code
    clock_t begin = clock();
    sleep(20); // do some stuff here
    clock_t end = clock();
    // calculate elapsed time by finding difference (end - begin) and
    // divide by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time elpased is %f seconds", time_spent);
    return 0;
}