#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define N 1000000

using namespace std;

// Graph representation using adjacency list
vector<ll> v[N];

// Visited array to track nodes
bool visited[N];

// Variable to track if a cycle exists
ll ans = 0;

// Depth-First Search (DFS) function
void dfs(ll ver, ll par) {
    visited[ver] = true; // Mark the current vertex as visited

    // Traverse all neighbors of the current vertex
    for (ll i = 0; i < v[ver].size(); i++) {
        ll child = v[ver][i]; // Neighbor (child) of the current vertex

        // If the child is already visited
        if (visited[child]) {
            // Skip the parent vertex to avoid false cycle detection
            if (child != par) {
                ans = 1; // Cycle detected
                return;
            }
            continue;
        }

        // Recursively perform DFS on the unvisited child
        dfs(child, ver);

        // If a cycle is detected in recursion, stop further exploration
        if (ans == 1) return;
    }
}

int main() {
    ll ve, e; // ve = number of vertices, e = number of edges
    cin >> ve >> e;

    // Input edges and construct the adjacency list
    for (ll i = 0; i < e; i++) {
        ll v1, v2;
        cin >> v1 >> v2;

        // Add edges to the adjacency list (undirected graph)
        v[v1].pb(v2);
        v[v2].pb(v1);
    }

    // Perform DFS starting from vertex 1 (assuming the graph is connected)
    dfs(1, -1);

    // Check if a cycle was detected
    if (ans == 1) {
        cout << "YES" << endl; // Cycle exists
    } else {
        cout << "NO" << endl; // No cycle
    }

    return 0;
}
