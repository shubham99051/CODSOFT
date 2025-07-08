#include <iostream>
using namespace std;

// Represents the 3x3 game board
char board[3][3];

// Tracks the current player symbol
char currentPlayer = 'X';

// Displays the game title and instructions
void showTitle() {
    cout << "==============================\n";
    cout << "        TIC TAC TOE GAME      \n";
    cout << "==============================\n";
    cout << " Player 1: X\n";
    cout << " Player 2: O\n";
    cout << " Pick a position (1-9) to make your move.\n\n";
}

// Initializes the board with numbers 1-9
void initializeBoard() {
    char cell = '1';
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            board[row][col] = cell++;
        }
    }
}

// Renders the current board state
void displayBoard() {
    cout << "\n";
    for (int row = 0; row < 3; row++) {
        cout << " ";
        for (int col = 0; col < 3; col++) {
            cout << board[row][col];
            if (col < 2) cout << " | ";
        }
        cout << "\n";
        if (row < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

// Prompts the current player to make a valid move
void playerMove() {
    int position;
    while (true) {
        cout << "Player " << currentPlayer << ", choose a position (1-9): ";
        cin >> position;

        if (position < 1 || position > 9) {
            cout << "Invalid! Enter a number between 1 and 9.\n";
            continue;
        }

        int row = (position - 1) / 3;
        int col = (position - 1) % 3;

        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = currentPlayer;
            break;
        } else {
            cout << "Cell already taken. Try again.\n";
        }
    }
}

// Checks if the current player has won
bool checkWin() {
    for (int i = 0; i < 3; i++) {
        // Horizontal and vertical checks
        if ((board[i][0] == currentPlayer &&
             board[i][1] == currentPlayer &&
             board[i][2] == currentPlayer) ||

            (board[0][i] == currentPlayer &&
             board[1][i] == currentPlayer &&
             board[2][i] == currentPlayer)) {
            return true;
        }
    }

    // Diagonal checks
    if ((board[0][0] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][2] == currentPlayer) ||

        (board[0][2] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][0] == currentPlayer)) {
        return true;
    }

    return false;
}

// Checks if the board is full and no one has won
bool checkDraw() {
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (board[row][col] != 'X' && board[row][col] != 'O')
                return false;

    return true;
}

// Switches turns between X and O
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Entry point of the game
int main() {
    showTitle();
    initializeBoard();

    while (true) {
        displayBoard();
        playerMove();

        if (checkWin()) {
            displayBoard();
            cout << " Player " << currentPlayer << " wins the game!\n";
            break;
        }

        if (checkDraw()) {
            displayBoard();
            cout << "It's a draw! Well played both.\n";
            break;
        }

        switchPlayer();
    }

    return 0;
}