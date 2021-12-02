/*
Sample problem 5
Lucas Sarweh
*/

// Include header files
#include <stdio.h>
#define TRUE 1
#define FALSE 0
int sumdigits(int n){
    int sum = 0;
    while(n > 0){
        sum = sum + (n % 10);
        n = n / 10;
    }
    return sum;
}

int main(void){
    int done = TRUE;
    int num;
    while(done){
        printf("%s", "Enter a number: ");
        scanf("%d", &num);
        if(num == 0){
            done = FALSE;
            return 0;
        }
        printf("%d\n", sumdigits(num));
    }
}