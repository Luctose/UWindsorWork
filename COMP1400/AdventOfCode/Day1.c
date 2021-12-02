#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXCHAR 1000

int main(){

    int num[1000];
    FILE *fp;
    char str[MAXCHAR];
    char* filename = "C:\\Users\\lucas\\Desktop\\Assignments COMP1400\\AdventOfCode\\Years.txt";

    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Could not open file %s", filename);
        return 1;
    }

    for(int l = 0; fgets(str, MAXCHAR, fp) != NULL; l++){
        num[l] = atoi(str);
    }

    fclose(fp);

    for(int i = 0; i < 200; i++){
        for(int j = 0; j < 200; j++){
            for(int k = 0; k < 200; k++){
                if((num[i] + num[j] + num[k]) == 2020){
                    printf("%d\t%d\t%d\n", num[i], num[j], num[k]);
                    printf("%d", num[i] * num[j] * num[k]);
                    return 0;
                }
            }
        }
    }

    return 0;
}