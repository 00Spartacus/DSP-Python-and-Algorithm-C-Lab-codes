#include<bits/stdc++.h>
using namespace std;

#define N 1000  // Defining a maximum limit for the grid

// Visited array to track which cells have been visited during BFS
int vis[4][4];

// Distance array to store the shortest distance from the starting point (1, 1)
int dist[4][4];

// Function to check if a cell (i, j) is within bounds and not visited
bool isSafe(int i, int j) {
    // Check if the cell is within bounds and not visited
    if (i >= 4 || j >= 4 || i < 0 || j < 0) return false;
    if (vis[i][j]) return false;  // Already visited
    return true;
}

// BFS function to explore the grid
void bfs(int i, int j) {
    // Queue for BFS, stores pairs of (row, column)
    queue<pair<int, int>> que;
    
    // Start BFS from (i, j)
    que.push(make_pair(i, j));
    vis[i][j] = 1;  // Mark the starting cell as visited
    
    dist[i][j] = 0;  // The distance to the starting cell is 0

    // Process the queue until it's empty
    while (!que.empty()) {
        pair<int, int> cur = que.front();  // Get the front element from the queue
        que.pop();  // Remove the element from the queue

        // Check four possible directions: Up, Down, Left, Right
        
        // Up (i-1, j)
        if (isSafe(cur.first - 1, cur.second)) {
            que.push(make_pair(cur.first - 1, cur.second));  // Enqueue the next cell
            dist[cur.first - 1][cur.second] = dist[cur.first][cur.second] + 1;  // Update the distance
            vis[cur.first - 1][cur.second] = 1;  // Mark the cell as visited
        }

        // Down (i+1, j)
        if (isSafe(cur.first + 1, cur.second)) {
            que.push(make_pair(cur.first + 1, cur.second));
            dist[cur.first + 1][cur.second] = dist[cur.first][cur.second] + 1;
            vis[cur.first + 1][cur.second] = 1;
        }

        // Left (i, j-1)
        if (isSafe(cur.first, cur.second - 1)) {
            que.push(make_pair(cur.first, cur.second - 1));
            dist[cur.first][cur.second - 1] = dist[cur.first][cur.second] + 1;
            vis[cur.first][cur.second - 1] = 1;
        }

        // Right (i, j+1)
        if (isSafe(cur.first, cur.second + 1)) {
            que.push(make_pair(cur.first, cur.second + 1));
            dist[cur.first][cur.second + 1] = dist[cur.first][cur.second] + 1;
            vis[cur.first][cur.second + 1] = 1;
        }
    }
}

int main() {
    // Initialize the visited array and distance array to 0
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            vis[i][j] = 0;
            dist[i][j] = 0;
        }
    }

    // Perform BFS starting from position (1, 1)
    bfs(1, 1);

    // Print the distance array
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;  // New line after each row
    }

    return 0;
}
