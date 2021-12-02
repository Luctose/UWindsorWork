/*
Sample problem 9
Lucas Sarweh
*/

// Include header files
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isEqual(char a[], char b[]){
    int sizea = strlen(a);
    int sizeb = strlen(b);
    printf("%d %d\n", sizea, sizeb);
    if(sizea == sizeb){
        for(int i = 0; i < sizea; i++){
            if(a[i] == b[i]){
                continue;
            }else{
                return 0;
            }
        }
    }else{
        return 0;
    }
    return 1;
}

int main(void){
    char poo[15] = "cyka blyat gg";
    char pee[14] = "cyka blyat gg";
    printf("%d", isEqual(poo, pee));

}