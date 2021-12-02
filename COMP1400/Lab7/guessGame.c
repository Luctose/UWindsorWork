/*
Lab 7 Part B
Guessing Game
This game will generate a random number
from 0 to 50 and the user must guess
the number until they guess correctly
or has made 10 wrong guesses
Developed by: Lucas Sarweh
Version 1
Date: 9 Nov 2020
*/

// Include standard input/output
#include <stdio.h>
// Include standard general utilities
#include <stdlib.h>
// Include time
#include <time.h>

// Main function starts execution
int main(void){

    // Give user an explaination of the game
    puts("Welcome to my guessing game!\n"
    "In this game you will guess a number\n"
    "from 0 - 50 good luck!\n"
    "------------------------------------");

    // Set the seed for the random function using the current time
    srand(time(NULL));

    // Variable needed outside the loop to handle playing again
    int done = 1;

    // While loop for users to be able to play again
    while(done){

        // Generate a random number from 0 - 50
        int goal = rand() % 50 + 1;
        // Variable for the users guess (initialize to outside of guessing range)
        int guess = -1;
        // Variable that tracks how many guesses the user has made
        int tries = 0;

        // Loop until the user guesses correctly
        while(goal != guess){

            // Loop incase user enters an invalid option
            do{

                // Prompt the user for a guess
                printf("Enter your guess (between 0 and 50): ");
                // Store guess into memory
                scanf("%d", &guess);

                // If guess is out of range
                if(guess > 50 || guess < 0){

                    // Tell the user the guess is not acceptable
                    puts("This guess is not in range. Please try again.");
                }

            }while((guess > 50) || (guess < 0));

            // Add one to the number of tries the user has used
            tries += 1;

            // Logic to tell user if number is higher or lower
            // If the goal is lower than the guess
            if(guess > goal){

                // Output too high
                puts("Too high...");

                // Make sure the user still has attempts
                if(tries >= 10){

                    // If they don't tell them they lose and exit the loop
                    printf("Sorry, you have exceeded the number of attempts. The number was %d\n", goal);
                    break;
                }
            }
            // If the goal is higher than the guess
            else if(guess < goal){

                // Output too low
                puts("Too low...");

                // Make sure the user still has attempts
                if(tries >= 10){
                    
                    // If they don't tell them they lose and exit the loop
                    printf("Sorry, you have exceeded the number of attempts. The number was %d\n", goal);
                    break;
                }
            }
            // Guess correctly
            else{

                // Tell the user they were correct
                printf("Correct, the number was %d\n", goal);
            }
        }

        // Do while to loop if user inputs invalid guess
        do{

            // Prompt if they would like to play again
            printf("Would you like to play again (1 = yes, 0 = no): ");
            // Store user input
            scanf("%d", &done);

            // User wants to exit
            if (done == 0){

                // Thank the user for playing
                puts("Thanks for playing! Goodbye.");
                break;
            }
            // User wants to play again
            else if(done == 1){

                // Message for playing again
                puts("Awesome! Lets play again!");
                break;
            }
            // Incase the user puts anything other than 1 or 0
            else{
                
                // Say it is not valid
                puts("That is not a valid option!");
            }

        }while(1);
    }
}