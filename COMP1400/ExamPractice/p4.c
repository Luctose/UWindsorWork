/*
Sample problem 4
Lucas Sarweh
*/

// Include header files
#include <stdio.h>
#include <ctype.h>

// Define macros
#define SIZE 30

// Function
int isCLD(char a[], int size){
    if(islower(a[0])){
        return 0;
    }else{
        return 1;
    }
}

int main(void){
    char c[SIZE] = "45ello";
    printf("%d", isCLD(c, SIZE));
}