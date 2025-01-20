#include <bits/stdc++.h> 
using namespace std;

// Function to check if it's safe to place a queen at position (row, col)
bool isSafe(vector<vector<int>>& chessBoard, int row, int col) {
    int boardSize = chessBoard.size();
    int leftDiagonal = col, rightDiagonal = col;

    // Check the current column and the two diagonals
    while (row >= 0) {
        if ((leftDiagonal >= 0 && chessBoard[row][leftDiagonal] == 1) || // Check left diagonal
            (chessBoard[row][col] == 1) || // Check column
            (rightDiagonal < boardSize && chessBoard[row][rightDiagonal] == 1)) { // Check right diagonal
            return false;
        }
        row--;
        leftDiagonal--;
        rightDiagonal++;
    }

    return true; // Position is safe to place the queen
}

// Recursive function to solve the N-Queens problem
bool solveNQueens(vector<vector<int>>& chessBoard, int row) {
    int boardSize = chessBoard.size();

    // Base case: If all queens are placed
    if (row == boardSize) {
        return true; // Solution found
    }

    // Try placing a queen in each column of the current row
    for (int col = 0; col < boardSize; col++) {
        if (isSafe(chessBoard, row, col)) {
            // Place the queen
            chessBoard[row][col] = 1;

            // Recur to place queens in the next row
            if (solveNQueens(chessBoard, row + 1)) {
                return true; // If solution is found, stop
            }

            // Backtrack: Remove the queen
            chessBoard[row][col] = 0;
        }
    }
    return false; // No valid placement found
}

int main() {
    int n;
    cout << "Enter the size of the board: ";
    cin >> n;

    // Initialize the chessboard (0 represents empty, 1 represents queen)
    vector<vector<int>> chessBoard(n, vector<int>(n, 0));

    // Find one solution to the N-Queens problem
    if (solveNQueens(chessBoard, 0)) {
        cout << "One solution found:\n";
        // Print the board with queens represented by 'Q'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << (chessBoard[i][j] == 1 ? "Q " : ". ");
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}
