/*
Sample problem 8
Lucas Sarweh
*/

// Include header files
#include <stdio.h>
#include <ctype.h>

int main(void){
    char letter;
    printf("%s", "Enter a lowercase letter: ");
    scanf("%c", &letter);

    letter = toupper(letter);
    printf("%c", letter);
}
