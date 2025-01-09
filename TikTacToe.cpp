#include <iostream>
using namespace std;

void displayBoard(const char board[3][3]) {
//prints out the board
cout << " 1  2  3" << endl;
cout << "1 " << board[0][0] << " " << board[1][0] << " "  << board[2][0] << endl;
cout << "1 " << board[0][1] << " " << board[1][1] << " "  << board[2][1] << endl;
cout << "2 " << board[0][2]<< " "  << board[1][2] << " " <<board[2][2] << endl;
}

bool checkWin(const char board[3][3], char player) {
    //check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    //Check diagnals
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
    //board array
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    char currentPlayer = 'X';
    bool gameOver = false;

    cout << "Welcome to Tic-tac-toe!" << endl;
    cout << "take turns entering row and column numbers (1-3)." << endl;
//Loop to keep the game going
    while (!gameOver) {
        displayBoard(board);
        
        int row, col;
        bool validInput = false;
        //checks validy of the move
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

        board[row][col] = currentPlayer;
//check the win condishions
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

    return 0;
}
