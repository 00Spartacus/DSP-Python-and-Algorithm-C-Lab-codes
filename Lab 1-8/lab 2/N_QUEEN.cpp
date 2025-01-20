#include <iostream>
#include <vector>
using namespace std;

// Function to check if it's safe to place a queen at board[i][j]
bool isSafe(vector<vector<int>>& board, int i, int j) {
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

// Recursive function to find all solutions
int rec(vector<vector<int>>& board, int i) {
    int n = board.size();

    // Base case: if all queens are placed
    if (i == n) {
        return 1;
    } else {
        int nb_solutions = 0;

        // Try placing a queen in all columns of the current row
        for (int j = 0; j < n; j++) {
            if (isSafe(board, i, j)) {
                // Place the queen
                board[i][j] = 1;

                // Recur to place the rest of the queens
                nb_solutions += rec(board, i + 1);

                // Backtrack and remove the queen
                board[i][j] = 0;
            }
        }
        return nb_solutions;
    }
}

int main() {
    int n;
    cout << "Enter the size of the board: ";
    cin >> n;

    // Initialize the chessboard
    vector<vector<int>> board(n, vector<int>(n, 0));

    // Find and print the number of solutions
    int solutions = rec(board, 0);
    cout << "Number of solutions: " << solutions << endl;

    return 0;
}

