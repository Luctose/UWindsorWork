/*
Sample problem 3
Lucas Sarweh
*/

// Include header files
#include <stdio.h>

char iToString(int n){
    char c = n + '0';
    return c;
}

int main(void){
    int n;
    scanf("%d", &n);
    iToString(n);
    printf("%c", iToString(n));
}