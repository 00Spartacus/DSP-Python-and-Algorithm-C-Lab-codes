#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define N 1000000

using namespace std;

// Graph representation using adjacency list
vector<ll> v[N];

// Visited array to keep track of visited nodes
bool visited[N];

// Depth-First Search (DFS) function
void dfs(ll ver) {
    visited[ver] = true;  // Mark the current vertex as visited
    cout << "start " << ver << endl;  // Print the start of traversal for this vertex

    // Traverse all neighbors of the current vertex
    for (ll i = 0; i < v[ver].size(); i++) {
        ll child = v[ver][i];  // Get the neighbor (child)
        cout << "child " << child << " " << "parent " << ver << endl;

        // If the neighbor is already visited, skip it
        if (visited[child]) {
            continue;
        }

        // Recursively perform DFS on the unvisited neighbor
        dfs(child);
    }
}

int main() {
    ll ve, e;  // ve = number of vertices, e = number of edges
    cin >> ve >> e;

    // Input edges and construct the adjacency list
    for (ll i = 0; i < e; i++) {
        ll v1, v2;
        cin >> v1 >> v2;

        // Add edges to the graph (undirected)
        v[v1].pb(v2);
        v[v2].pb(v1);
    }

    ll con_comp = 0;  // Variable to count connected components

    // Check all vertices for unvisited nodes
    for (ll i = 1; i <= ve; i++) {
        if (!visited[i]) {
            dfs(i);  // Perform DFS on the unvisited node
            con_comp++;  // Increment connected component count
        }
    }

    // Output the number of connected components
    cout << con_comp << endl;

    return 0;
}
