#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
private:
    vector<char> board; // 3x3 Tic-Tac-Toe board
    char currentPlayer;

public:
    TicTacToe() {
        // Initialize the board with empty spots
        board = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        currentPlayer = 'X'; // X starts
    }

    // Display the game board
    void displayBoard() {
        cout << "\n";
        cout << " " << board[0] << " | " << board[1] << " | " << board[2] << "\n";
        cout << "---|---|---\n";
        cout << " " << board[3] << " | " << board[4] << " | " << board[5] << "\n";
        cout << "---|---|---\n";
        cout << " " << board[6] << " | " << board[7] << " | " << board[8] << "\n";
        cout << "\n";
    }

    // Take player's move
    bool playerMove() {
        int move;
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        // Check for valid input
        if (move < 1 || move > 9 || board[move - 1] == 'X' || board[move - 1] == 'O') {
            cout << "Invalid move! Try again.\n";
            return false;
        }

        // Make the move
        board[move - 1] = currentPlayer;
        return true;
    }

    // Switch between players
    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Check if someone has won
    bool checkWinner() {
        // Winning combinations
        int win[8][3] = {
            {0, 1, 2}, {3, 4, 5}, {6, 7, 8},  // rows
            {0, 3, 6}, {1, 4, 7}, {2, 5, 8},  // columns
            {0, 4, 8}, {2, 4, 6}              // diagonals
        };

        for (int i = 0; i < 8; i++) {
            if (board[win[i][0]] == currentPlayer && board[win[i][1]] == currentPlayer && board[win[i][2]] == currentPlayer) {
                return true;
            }
        }

        return false;
    }

    // Check if the board is full (draw)
    bool isDraw() {
        for (int i = 0; i < 9; i++) {
            if (board[i] != 'X' && board[i] != 'O') {
                return false;
            }
        }
        return true;
    }

    // Run the game loop
    void playGame() {
        // int moveCount = 0;
        while (true) {
            displayBoard();
            if (playerMove()) {
                // moveCount++;
                if (checkWinner()) {
                    displayBoard();
                    cout << "Player " << currentPlayer << " wins!\n";
                    break;
                } else if (isDraw()) {
                    displayBoard();
                    cout << "It's a draw!\n";
                    break;
                }
                switchPlayer();
            }
        }
    }
};

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}