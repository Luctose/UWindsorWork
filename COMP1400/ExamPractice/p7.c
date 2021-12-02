/*
Sample problem 7
Lucas Sarweh
*/

// Include header files
#include <stdio.h>

int isOdd(int n){
    if(n % 2 == 0){
        return 0;
    }else{
        return 1;
    }
}

int main(void){
    int done = 1;
    int num;
    while(done){
        printf("%s", "Enter num: ");
        scanf("%d", &num);
        if(num == 0){
            done = 0;
        }
        printf("%d\n", isOdd(num));
    }
}