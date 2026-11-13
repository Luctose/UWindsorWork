/*
Name: Lucas Sarweh
ID: 110042658
Assignment 1
COMP-3300
Due: 01/30/2024
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

void start_fork(pid_t *child, int *num_list, int k, int *pmin, int *pmax){
    // Child pid
    pid_t pid;

    // Child job
    if((pid = fork()) == 0){
        sleep(3);
        // Each child will process 25 numbers

        // Find the persistence of each number in the list
        // Lists to store the min and max
        
        pmin[0] = -1;
        pmin[1] = INT_MAX;
        pmax[0] = -1;
        pmax[1] = INT_MIN;
        
        int persis_cur;
        int current_num;
        int temp;
        int i;
        // Loop each item in the list
        for(i = k * 25; i < (k + 1) * 25; ++i){
            if(i >= 125){
                break;
            }
            persis_cur = 0;
            current_num = num_list[i];
            
            // While multi digit number
            while(current_num >= 10){
                // While current number still has digits to multiply
                temp = 1;
                while(current_num != 0){
                    temp *= current_num % 10;
                    current_num = current_num / 10;
                }
                // Assign new current number and increase persistence count
                current_num = temp;
                persis_cur++;
            }
            // Check if current item in list has beaten min or max persistence
            if(persis_cur < pmin[1]){
                pmin[0] = i;
                pmin[1] = persis_cur;
            }
            if(persis_cur > pmax[1]){
                pmax[0] = i;
                pmax[1] = persis_cur;
            }

        }
        // Display what the child has found
        printf("Max persistence number: %d Has persistence: %d\n", num_list[pmax[0]], pmax[1]);
        printf("Min persistence number: %d Has persistence: %d\n", num_list[pmin[0]], pmin[1]);
        printf("I am kid #: %d and my id is: %d\n", k, getpid());
        // Kill child
        exit(1);
    }else{
        // Assign child PID to parent array
        *child = pid;
    }

}

int main(int argc, char *argv[]){
    // To keep track of execution time
    double time_spent = 0.0; // to store execution time of code
    clock_t begin = clock();

    if(argc <= 1){
        printf("Please provide an input file as an argument\nEx: ./executable_name file_name.txt");
        return 0;
    }

    // Open file
    FILE * fp = fopen(argv[1], "r");
    if(fp == NULL){
        printf("Error opening file");
        return 0;
    }

    // Initialize c to take file input and a list to store the numbers
    char c;
    int *num_list = (int*) malloc(125 * sizeof(int));
    // Initialize to 0
    for(int l = 0; l < 125; ++l){
        num_list[l] = 0;
    }

    size_t i = 0;
    // Retrieve numbers from file and add to list
    while((c = fgetc(fp)) != EOF){
        if(c == '\n'){
            ++i;
        }
        else{
            num_list[i] = (num_list[i] * 10) + atoi(&c);
        }
    }
    // Close the file
    fclose(fp);

    // Sort the list (Insertion sort)
    int key, j;
    for(i = 1; i < 125; ++i){
        key = num_list[i];
        j = i - 1;

        while(j >= 0 && num_list[j] > key){
            num_list[j + 1] = num_list[j];
            j = j - 1;
        }
        num_list[j + 1] = key;
    }

    int *persis_max = (int*) malloc(2 * sizeof(int));
    int *persis_min = (int*) malloc(2 * sizeof(int));

    // Fork 5 children
    pid_t child_pid[5];
    for(i = 0; i < 5; ++i){
        start_fork(&child_pid[i], num_list, i, persis_min, persis_max);
    }

    printf("I am the father of the following: %d, %d, %d, %d, and %d\n", child_pid[0], child_pid[1], child_pid[2], child_pid[3], child_pid[4]);

    int count = 5;
    pid_t statuspid;
    int status;
    while(count > 0){
        statuspid = wait(&status);
        printf("From the main: child, id = %d ended with status %d\n", statuspid, status);
        --count;
    }
    
    // End execution timer
    clock_t end = clock();

    // calculate elapsed time by finding difference (end - begin) and
    // divide by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time elpased is %.8f seconds\n", time_spent);

    free(num_list);
    free(persis_max);
    free(persis_min);

    printf("Good bye!\n");
    return 0;
}