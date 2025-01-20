#include <iostream>
#include <vector>
using namespace std;

// Function to check if it's safe to place a queen at board[i][j]
bool isSafe(vector<vector<int> >& board, int i, int j) {
    int n = board.size();
    int j_left = j, j_right = j;

    // Check upper diagonals and columns
    while (i >= 0) {
        if ((j_left >= 0 && board[i][j_left] == 1) || // Check left diagonal
            (board[i][j] == 1) || // Check column
            (j_right < n && board[i][j_right] == 1)) { // Check right diagonal
            return false;
        }
        i--;
        j_left--;
        j_right++;
    }

    return true;
}

// Recursive function to find one solution
bool rec(vector<vector<int> >& board, int i) {
    int n = board.size();

    // Base case: if all queens are placed
    if (i == n) {
        return true;
    }

    // Try placing a queen in all columns of the current row
    for (int j = 0; j < n; j++) {
        if (isSafe(board, i, j)) {
            // Place the queen
            board[i][j] = 1;

            // Recur to place the rest of the queens
            if (rec(board, i + 1)) {
                return true; // If a solution is found, stop
            }

            // Backtrack and remove the queen
            board[i][j] = 0;
        }
    }
    return false; // No solution found for this configuration
}

int main() {
    int n;
    cout << "Enter the size of the board: ";
    cin >> n;

    // Initialize the chessboard
    vector<vector<int> > board(n, vector<int>(n, 0));

    // Find one solution
    if (rec(board, 0)) {
        cout << "One solution found:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << (board[i][j] == 1 ? "Q " : ". ");
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}

