/* ===========================================================================
COMP-1410 Assignment 2
==============================================================================
Student name: Lucas Sarweh

Replace the error with statement citing any sources of outside help:
ERROR_NO_INTEGRITY_STATEMENT

=========================================================================== */

#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

// print_board is a helper function that prints the specified
//   connect four board
void print_board(char board[6][7]);

// make_move(board, column, player) updates the board following a move
//   by the given player in the given column; returns false if the move
//   was illegal because the column was full
// requires: 0 <= column < 7
//           player is either 'X' or 'O'
bool make_move(char board[6][7], int column, char player);

// check_win(board) returns true if the given player has 4 connected
//   pieces on the board
bool check_win(char board[6][7], char player);

// This function initializes connect 4
void init_connect4(char board[6][7]);

// first_capital(str, n) returns the first capital letter in str;
//   returns 0 if str contains no capital letters
// requires: str is a string of length n
//           str contains only lower-case and upper-case letters
//           all lower-case letters appear before upper-case letters
char first_capital(const char str[], int n);

// deepest_substring(str, out) updates out to be the deepest substring of
//   str; the first is used if multiple possibilities exist
// requires:
//   str is a string with balanced parenthesis
//   out points to enough memory to store the deepest substring of str
void deepest_substring(const char str[], char out[]);

// print_board() implementation
void print_board(char board[6][7]){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            printf("%c ", board[i][j]);
        }
        puts("");
    }
}

// make_move() implementation
bool make_move(char board[6][7], int column, char player){
    // If the number is too high
    if(column > 6 || column < 0){
        // Don't make a move and return false
        return false;
    }
    // Evaluate the state of the board
    for(int i = 0; i < 6; i++){
        // Check if there is a spot open here
        if(board[i][column] == 'X' || board[i][column] == 'O'){
            // Check if the board is full
            if(i == 0){
                // If so return false
                return false;
            }else{
                // If not full place a piece for the player in the last column that was empty
                board[i - 1][column] = player;
                return true;
            }
        }
    }
    // When the column is empty nothing is returned so set that as the move and return true
    board[5][column] = player;
    return true;
}

// check_win() implementation
bool check_win(char board[6][7], char player){
    // Variables/arrays to keep track of each type of win condition
    int hor = 0;
    int ver[7] = {0};
    int dia[6][7] = {0}; // This one is going to be kinda scuffed

    // Evaluate the state of the game
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            // When there is the desired player piece here
            if(board[i][j] == player){
                // Add to the horizontal, vertical, and diagnal win conditions
                hor += 1;
                ver[j] += 1;
                dia[i][j] += 1;

                // If the last 4 diagnal spaces to the left all are true
                if(i >= 3 && j >= 3){
                    if(dia[i - 1][j - 1] && dia[i - 2][j - 2] && dia[i - 3][j - 3]){
                        // They win
                        return true;
                    }
                // If the last 4 diagnal spaces to the right all are true
                }else if(i >= 3 && j <= 3){
                    if(dia[i - 1][j + 1] && dia[i - 2][j + 2] && dia[i - 3][j + 3]){
                        // they win
                        return true;
                    }
                }
            // No desired player piece here
            }else{
                // Reset the horizontal and verticle counts
                hor = 0;
                ver[j] = 0;
            }
            
            // If we count four in a row for verticle or horizontal
            if(hor >= 4 || ver[j] >= 4){
                // They win
                return true;
            }
        }
    }
    // When there is no win
    return false;
}

// Implementation of init_connect4()
void init_connect4(char board[6][7]){
    // Initialize vairable to store players choice
    int choice = 0;
    // This variable checks how many moves have been made
    int moves = 0;
    
    puts("Welcome to connect 4! 'X' will go first followed by 'O'.\n"
    "The board is 6 * 7 meaning you will specify your move by giving\n"
    "the column number from 1 - 7. Begin!\n");

    // Print board for visiualization
    print_board(board);

    // While we are still playing the game
    while(true){
        // Player 1's turn
        while(true){
            // Prompt player 1 for choice
            printf("%s", "Player 1 enter your column: ");
            // Make sure scanf gets correct input
            if(scanf("%d", &choice)){
                // Make the move for the player
                if(make_move(board, choice - 1, 'X')){
                    // Add to the number of moves made
                    moves += 1;
                    // Exit current while loop
                    break;
                }else{
                    // When a player tries to overflow a column
                    puts("That column is full try another.");
                }
            }else{
                // If they input a non integer try again
                puts("Incorrect input, try again.");
            }
        }
        // Print the current board
        print_board(board);

        // Check if player 1 has won after that turn
        if(check_win(board, 'X')){
            printf("%s", "Congrats player 1 you have won!\n");
            break;
        }

        // Player 2's turn
        while(true){
            // Prompt player 2 for choice
            printf("%s", "Player 2 enter your column: ");
            // Make sure scanf gets correct input
            if(scanf("%d", &choice)){
                // Make the move for the player
                if(make_move(board, choice - 1, 'O')){
                    moves += 1;
                    // Exit current while loop
                    break;
                }else{
                    // When the player tries to overflow a column
                    puts("That column is full try another.");
                }
            }else{
                // If they input a non integer try again
                puts("Incorrect input, try again.");
            }
        }
        // Print the current board
        print_board(board);

        // Check if player 1 has won after that turn
        if(check_win(board, 'O')){
            printf("%s", "Congrats player 2 you have won!\n");
            break;
        }
        // Check if it is a draw when the board is full (6 * 7 moves)
        if(moves >= 42){
            printf("%s", "The match has resulted in a draw.\n");
            // Exit the game
            break;
        }
    }
}

// first_captial() implementation
char first_capital(const char str[], int n){
    // Use binary search for O(logn)
    // Define lower, upper, and middle bound
    int lower = 0;
    int upper = n - 1;
    int mid = lower + (upper - lower) / 2;
    while(true){
        // See if the current midpoint is uppercase
        if(isupper(str[mid])){
            // If it is change the upper to mid
            upper = mid;
        }else{
            // If it isn't change the lower to mid plus one
            lower = mid + 1;
        }
        // Calc a new mid
        mid = lower + (upper - lower) / 2;
        // Check if there is only one left
        if(upper == lower){
            // exit loop
            break;
        }
    }
    // Check the last letter
    if(isupper(str[upper])){
        // Return the first uppercase
        return str[upper];
    }else{
        // There was no uppercase
        return 0;
    }
}

// deepest_substring()
void deepest_substring(const char str[], char out[]){
    // Var for deepness
    int deepness = 0;
    // Keep track of deepest number ever gotten to
    int highest = 0;
    int index = 0;
    /*
    for(int i = 0; i < strlen(str); i++){
        if(strcmp(str[i], '('){
            deepness += 1;
            if(highest < deepness){
                highest = deepness;
                index = i;
            }
        }else if(strcmp(str[i], ')')){
            deepness -= 1;
        }
    }
    for(int j = index; j < strlen(str); j++){
        if(strcmp(str[j], ')')){
            for(int k = index; k < j; k++){
                strcat(out, str[index]);
            }
        }
    }*/
}

int main(void) {
    char my_game[6][7] = {".......",
                          ".......",
                          ".......",
                          ".......",
                          ".......",
                          "......."};
    
    //init_connect4(my_game);
    // Some given tests for check_win()
    char test1[6][7] = {".......",
                        ".......",
                        "X......",
                        "X.....O",
                        "X.....O",
                        "X.....O"};
    assert(check_win(test1, 'X'));

    char test2[6][7] = {".......",
                        ".......",
                        ".......",
                        "X.XXXXO",
                        "X.....O",
                        "X.....O"};
    assert(check_win(test2, 'X'));

    char test3[6][7] = {".......",
                        ".......",
                        ".......",
                        "X......",
                        "X......",
                        "X......"};
    assert(check_win(test3, 'X') == false);

    char test4[6][7] = {".......",
                        ".......",
                        ".......",
                        "X.XXX.O",
                        "X.....O",
                        "X.....O"};
    assert(check_win(test4, 'X') == false);

    char test5[6][7] = {".....X.",
                        "....X..",
                        "...O...",
                        "X.XX..O",
                        "X.....O",
                        "X.....O"};
    assert(check_win(test5, 'X') == false);

    char test6[6][7] = {".......",
                        "...X...",
                        "..X....",
                        "XX.XXXO",
                        "X.....O",
                        "X.....O"};
    assert(check_win(test6, 'X'));

    char test7[6][7] = {".....O.",
                        "....X..",
                        "...X...",
                        "..XXXO.",
                        ".......",
                        "......."};
    assert(check_win(test7, 'X') == false);

    char test8[6][7] = {".......",
                        ".......",
                        ".......",
                        ".......",
                        ".......",
                        "......."};
    assert(check_win(test8, 'X') == false);

    char test9[6][7] = {".......",
                        ".......",
                        ".XOOOO.",
                        "....O..",
                        "....X..",
                        "......."};
    assert(check_win(test9, 'O'));

    char test10[6][7] = {".......",
                        ".....O.",
                        "....O..",
                        "...O...",
                        "..O....",
                        "......."};
    assert(check_win(test10, 'O'));

    char test11[6][7] = {".......",
                        ".......",
                        "...O...",
                        "....O..",
                        ".....O.",
                        "......O"};
    assert(check_win(test11, 'O'));

    char test12[6][7] = {"X......",
                        ".O..O..",
                        "..O.O..",
                        "...OO..",
                        "..OOOO.",
                        "......X"};
    assert(check_win(test12, 'O'));

    // Testing first_capital()
    assert(first_capital("abcABC", 6) == 'A'); // Given test

    assert(first_capital("adffG", 5) == 'G'); // Last letter captial

    assert(first_capital("FJRNE", 5) == 'F'); // No lowercase

    assert(first_capital("tUPLKJ", 6) == 'U'); // First letter lowercase

    assert(first_capital("yghne", 5) == 0); // No uppercase

    assert(first_capital("rhGHTD", 6) == 'G'); // Even length capital in middle

    assert(first_capital("leWDF", 5) == 'W'); // Odd length capital in middle

    // Testing deepest_substring() still brokey
    char hi[10];
    deepest_substring("(hh)", hi);
    assert(strcmp("(fg)(g(hh))", hi));

    char he[10];
    deepest_substring("(fg)(g(h(h)))", he);
    assert(strcmp("(h)", he));

    char ho[10];
    deepest_substring("(fg(fg))(g(hh))", ho);
    assert(strcmp("(fg)", ho));

    char hy[10];
    deepest_substring("(((seven)))", hy);
    assert(strcmp("(seven)", hy));

    char bo[10];
    deepest_substring("(g(d(s)ss)(d(d(df(g))))", bo);
    assert(strcmp("(g)", bo));
}