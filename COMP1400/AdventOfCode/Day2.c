#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXCHAR 1000

int main(){

    int num[1000];
    FILE *fp;
    char str[MAXCHAR];
    char* filename = "C:\\Users\\lucas\\Desktop\\Assignments COMP1400\\AdventOfCode\\Passwords.txt";

    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Could not open file %s", filename);
        return 1;
    }

    fgets(str, MAXCHAR, fp);