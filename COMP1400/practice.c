#include <stdio.h> 
int main(int argc, char **argv) {
    double inputInteger;
    printf("Please provide some input.\n");
    if(scanf("%lf", &inputInteger) == 1) {
        printf("You inputted an integer\n");
    } else {
        printf("You did not enter an integer\n");
    }
    return 0;
}