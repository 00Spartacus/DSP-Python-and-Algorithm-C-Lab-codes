#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define MAXN 1005

// Structure to represent an edge with weight, starting node, and destination node
struct Edge {
    int u, v, weight;
    
    bool operator>(const Edge& other) const {
        return weight > other.weight;  // Used for min-heap (priority queue)
    }
};

int n, m;
vector<pair<int, int>> adj[MAXN];  // Adjacency list: node -> {neighbor, weight}
vector<bool> visited(MAXN, false);  // To track visited nodes

// Prim's Algorithm to find the MST weight
int prim(int start) {
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;  // Min-heap to get the smallest edge
    int mstWeight = 0;  // Total weight of the MST

    // Start with the given starting node (arbitrary choice)
    visited[start] = true;

    // Push all edges of the starting node into the priority queue
    for (auto& neighbor : adj[start]) {
        int v = neighbor.first;
        int weight = neighbor.second;
        pq.push({start, v, weight});
    }

    // Loop while there are edges to process
    while (!pq.empty()) {
        Edge currentEdge = pq.top();
        pq.pop();

        int u = currentEdge.u;
        int v = currentEdge.v;
        int weight = currentEdge.weight;

        // If the destination node is already visited, ignore this edge
        if (visited[v]) continue;

        // Add the edge weight to the MST
        mstWeight += weight;
        visited[v] = true;

        // Push all edges of the newly visited node into the priority queue
        for (auto& neighbor : adj[v]) {
            int nextNode = neighbor.first;
            int nextWeight = neighbor.second;

            if (!visited[nextNode]) {
                pq.push({v, nextNode, nextWeight});
            }
        }
    }

    return mstWeight;  // Return the total weight of the MST
}

int main() {
    // Input the number of nodes and edges
    cin >> n >> m;

    // Input the edges
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});  // Since the graph is undirected
    }

    // Choose an arbitrary start node, here we take node 1
    int startNode = 1;

    // Call Prim's algorithm to find the MST and its weight
    int mstWeight = prim(startNode);

    cout << "Weight of the Minimum Spanning Tree: " << mstWeight << endl;

    return 0;
}
