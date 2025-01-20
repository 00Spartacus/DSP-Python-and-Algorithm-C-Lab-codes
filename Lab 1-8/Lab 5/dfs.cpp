#include <bits/stdc++.h>
using namespace std;
#define N (int)2e6 + 5 // Maximum number of nodes

vector<int> vec[N];  // Adjacency list to represent the graph
bool vis[N];         // Array to track visited nodes

// Depth-First Search (DFS) function
void dfs(int n) {
    vis[n] = true; // Mark the current node as visited
    cout << n << "   Start:\n" << endl;

    // Traverse all neighbors of the current node
    for (int i = 0; i < vec[n].size(); i++) {
        int neighbor = vec[n][i];

        // If the neighbor is not visited, perform DFS on it
        if (!vis[neighbor]) {
            dfs(neighbor);
            cout << n << " again\n";
        }
    }

    // Finish processing the current node
    cout << n << "   Finished\n";
}

int main() {
    int n, m; // `n` is the number of nodes, `m` is the number of edges
    cin >> n >> m;

    // Initialize the visited array
    for (int i = 0; i <= n; i++) vis[i] = false;

    // Input the edges of the graph
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        // Add edges to the adjacency list (undirected graph)
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    // Perform DFS starting from node 0
    dfs(0);

    return 0;
}
