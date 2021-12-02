/*
Sample problem 6
Lucas Sarweh
*/

// Include header files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TRUE 1
#define FALSE 0

void seclarge(int a[15]){

    int first = 0;
    int second = 0;
    int temp = 0;

    for(int i = 0; i < 15; i++){
        if(a[i] > first){
            temp = first;
            first = a[i];
            second = temp;
        }else if(a[i] < first && a[i] > second){
            second = a[i];
        }
    }

    printf("\n%d is the second largest integer in the array.", second);
}

int main(void){

    srand(time(NULL));
    int array[15];
    for(int j = 0; j < 15; j++){
        array[j] = rand() % 10;
    }
    for(int k = 0; k < 15; k++){
        printf("%d ", array[k]);
    }
    seclarge(array);
}