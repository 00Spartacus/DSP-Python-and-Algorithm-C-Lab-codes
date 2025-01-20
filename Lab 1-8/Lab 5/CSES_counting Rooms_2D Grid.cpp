#include <bits/stdc++.h>
using namespace std;

#define N 1005

vector<vector<char>> vec;      // Grid for storing the map (walls and spaces)
vector<vector<bool>> vis;      // Visited grid to keep track of visited cells
int n, m;

int dx[] = {-1, 0, 1, 0};  // Directions for up, right, down, left
int dy[] = {0, 1, 0, -1};

bool isValid(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return false;  // Out of bounds
    if (vis[x][y] || vec[x][y] == '#') return false;        // Already visited or a wall
    return true;
}

void dfs(int x, int y) {
    vis[x][y] = true;  // Mark the current cell as visited
    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];  // Calculate new coordinates
        int newY = y + dy[i];
        if (isValid(newX, newY)) {
            dfs(newX, newY);  // Recursively explore the neighboring cell
        }
    }
}

int main() {
    cin >> n >> m;  // Read grid dimensions

    vec.resize(n, vector<char>(m));  // Resize the grid to fit input
    vis.resize(n, vector<bool>(m, false));  // Initialize the visited grid

    // Read the grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> vec[i][j];
        }
    }

    int cnt = 0;  // To count the number of rooms

    // Traverse the grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vec[i][j] == '.' && !vis[i][j]) {  // Found an unvisited empty space
                dfs(i, j);  // Perform DFS to mark all connected spaces as visited
                cnt++;  // Increment the room count
            }
        }
    }

    cout << cnt << endl;  // Output the number of rooms
}
