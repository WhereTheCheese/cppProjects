#include <iostream>

using namespace std;

//Tic-Tac-Toe game
void playTicTacToe() {
    char board[3][3] = {{' ', ' ', ' '},
                        {' ', ' ', ' '},
                        {' ', ' ', ' '}};
    char currentPlayer = 'X';
    bool gameOver = false;

    //displays the board
    void displayBoard() {
        cout << "   1 2 3\n";
        for (int i = 0; i < 3; i++) {
            cout << i + 1 << "  ";
            for (int j = 0; j < 3; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }

    // check if a move is valid
    bool isValidMove(int row, int col) {
        return board[row - 1][col - 1] == ' ';
    }

    //Check for a win
    bool checkWin(char player) {
        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
                (board[0][i] == player && board[1][i] == player && board[2][i] == player) ||
                (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
                (board[0][2] == player && board[1][1] == player && board[2][0] == player))  
 {
                return true;
            }
        }
        return false;
    }

    //check for a tie
    bool checkTie() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    while (!gameOver) {
        displayBoard();

        int row, col;
        cout << "Player " << currentPlayer << ", enter your move : ";
        cin >> row >> col;

        if (isValidMove(row, col)) {
            board[row - 1][col - 1] = currentPlayer;
            if (checkWin(currentPlayer)) {
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameOver = true;
            } else if (checkTie()) {
                cout << "It's a tie!" << endl;
                gameOver = true;
            }
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move. Please try again." << endl;
        }
    }

    // asks the player if they want to play TikTacToe again
    char playAgain;
    cout << "Do you want to play again? Y/N: ";
    cin >> playAgain;
    if (playAgain  
 == 'y' || playAgain == 'Y') {
        // Reset the board and start a new game
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j]  
 = ' ';
            }
        }
        currentPlayer = 'X';
        gameOver = false;
    }
}

int main() {
    playTicTacToe();
    return 0;
}
