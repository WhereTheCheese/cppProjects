#include <iostream>
using namespace std;

void displayBoard(const char board[3][3]) {
    // prints out the board with the right labels this time
    cout << "  1 2 3" << endl;  //Column labels
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " ";  //Row labels
        for (int j = 0; j < 3; j++) {
            cout << board[j][i] << " ";
        }
        cout << endl;
    }
}

void resetBoard(char board[3][3]) {
    //sets all positions to empty
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

bool checkWin(const char board[3][3], char player) {
    //check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    //Check diagonals
    return (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
           (board[0][2] == player && board[1][1] == player && board[2][0] == player);
}

bool checkTie(const char board[3][3]) {
    //checks for a tied game
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

bool isValidMove(int row, int col, const char board[3][3]) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

void clearInputBuffer() {
    cin.clear();
    char c;
    while (cin.get(c) && c != '\n');
}

int main() {
    char board[3][3];
    char playAgain = 'y';
    //lets you play again
    while (playAgain == 'y' || playAgain == 'Y') {
        resetBoard(board);
        char currentPlayer = 'X';
        bool gameOver = false;
        
        cout << "\nWelcome to Tic-tac-toe!" << endl;
        cout << "Take turns entering row and column numbers (1-3)." << endl;

        while (!gameOver) {
            displayBoard(board);
            
            int row, col;
            bool validInput = false;
            
            while (!validInput) {
                cout << "Player " << currentPlayer << ", enter your move (row col): ";
                if (cin >> row >> col) {
                    row--; col--; 
                    if (isValidMove(row, col, board)) {
                        validInput = true;
                    } else {
                        cout << "Invalid move! Position either out of bounds or already taken." << endl;
                    }
                } else {
                    cout << "Invalid input! Please enter numbers only." << endl;
                    clearInputBuffer();
                }
            }
            
            board[col][row] = currentPlayer;

            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameOver = true;
            } else if (checkTie(board)) {
                displayBoard(board);
                cout << "It's a tie!" << endl;
                gameOver = true;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }
        
        cout << "\nWould you like to play again? (y/n): ";
        cin >> playAgain;
        clearInputBuffer();
    }
    
    cout << "Thanks for playing!" << endl;
    return 0;
}
