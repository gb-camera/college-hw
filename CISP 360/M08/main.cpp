#include <iostream>
#include <string>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

//declare function prototypes
void fillBoard(char board[][COLS]);
void showBoard(char board[][COLS]);
void getChoice(char b[][COLS], bool playerToggle);
bool gameOver(char b[][COLS]);

int main() {
    ///main is complete, nothing to do here
    char board[ROWS][COLS];
    bool playerToggle = false;

    fillBoard(board);
    showBoard(board);

    while (!gameOver(board))
    {
        getChoice(board, playerToggle);
        showBoard(board);
        playerToggle = !playerToggle;
    }

    return 0;
}

///TODO (0)
   void fillBoard(char board[][COLS]) {
       for(int i = 0; i < ROWS; i++) {
           for(int j = 0; j < COLS; j++) {
               board[i][j] = '*';
           }
       }
   }
   ///Use a nested for loop to Fill the 2D array with '*'s


///TODO (1)
   void showBoard(char board[][COLS]) {
       cout << "  1 2 3" << endl;
       for(int i = 0; i < ROWS; i++) {
           cout << i + 1 << " ";
           for(int j = 0; j < COLS; j++) {
               if(j < COLS - 1) {
                    cout << board[i][j] << " ";
               }
               else {
                   cout << board[i][j];
               }
           }
        cout << endl;
       }
   }
   ///Use a nested for loop to print the board
   ///For each row, print the row number, then use an inner for loop to print each cell, separated by a space
   ///print a newline when the inner for loop is complete to move on to the next row


void getChoice(char b[][COLS], bool playerToggle) {
    string player;
    char c;
    int row, col;
    
    ///TODO (2)
      ///if playerToggle is false, then set the player string and c to correspond to player 1
      ///otherwise player 2
    if(!playerToggle) {
        player = "Player 1";
        c = 'X';
    }  
    else {
        player = "Player 2";
        c = 'O';
    }
      
    ///TODO (3)
      ///implement validation loop
    do {
        do {
        ///prompt the current player to enter the row
        cout << player << ", Row: ";
        cin  >> row;
        row -= 1;
        } while(row > 2 || row < 0);  ///range for row is invalid?

        do {
        ///prompt the current player to enter the column
        cout << player << ", Column: ";
        cin  >> col;
        col -= 1;
        } while(col > 2 || col < 0);  ///range for col is invalid?
    } while(b[row][col] == 'X' || b[row][col] == 'O');  ///the chosen cell is an X or an O?
    ///assign the player's char to the chosen cell
    b[row][col] = c;
    ///NOTE:  row 1, col 1 to the user is actually row 0, col 0 in the array
}

///TODO (4)
   ///implement gameOver
   
bool gameOver(char b[][COLS]) {
    bool gameOver = false;
    bool xWin = false, oWin = false;
    int tieCounter = 0;
    //Check for tie
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(b[i][j] != '*') {
                tieCounter += 1;
            }
            else {
                continue;
            }
        }
    }
    ///For loop to test row/column conditions
    for(int i = 0; i < 3; i++) {
        if(b[i][0] == b[i][1] && b[i][0] == b[i][2]) {
            if(b[i][0] == 'X') {
                xWin = true;
            }
            else if(b[i][0] == 'O') {
                oWin = true;
            }
        }
        else if(b[0][i] == b[1][i] && b[0][i] == b[2][i]) {
            if(b[0][i] == 'X') {
                xWin = true;
            }
            else if(b[0][i] == 'O') {
                oWin = true;
            }
        }
    }
    //If statements to check diagonal conditions
    if(b[0][0] == b[1][1] && b[0][0] == b[2][2]) {
        if(b[1][1] == 'X') {
            xWin = true;
        }
        else if(b[1][1] == 'O') {
            oWin = true;
        }
    }
    else if(b[0][2] == b[1][1] && b[0][2] == b[2][0]) {
        if(b[1][1] == 'X') {
            xWin = true;
        }
        else if(b[1][1] == 'O') {
            oWin = true;
        }
    }
    /// X Wins
    if(xWin) {
        cout << "Player 1 wins!";
        gameOver = true;
    }
    ///O Wins
    else if(oWin) {
        cout << "Player 2 wins!";
        gameOver = true;
    }
    ///Tie
    else if(tieCounter >= 9) {
        cout << "Tie!";
        gameOver = true;
    }
    return gameOver;
}

