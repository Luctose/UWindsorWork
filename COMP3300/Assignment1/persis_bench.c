#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>


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
    int num_list[125] = {0};
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
    
    // Find the persistence of each number in the list
    int persis_min[] = {-1, INT_MAX};
    int persis_max[] = {-1, INT_MIN};
    int persis_cur;
    int current_num;
    int temp;
    // Loop each item in the list
    for(i = 0; i < 125; ++i){
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
        if(persis_cur < persis_min[1]){
            persis_min[0] = i;
            persis_min[1] = persis_cur;
        }
        if(persis_cur > persis_max[1]){
            persis_max[0] = i;
            persis_max[1] = persis_cur;
        }

    }

    // Print smallest and largest persistent numbers
    printf("Largest persistence number: %d Has persistence: %d\n", num_list[persis_max[0]], persis_max[1]);
    printf("Smallest persistence number: %d Has persistence: %d\n", num_list[persis_min[0]], persis_min[1]);
    // End execution timer
    clock_t end = clock();

    // calculate elapsed time by finding difference (end - begin) and
    // divide by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time elpased is %.8f seconds", time_spent);
    return 0;
}