#include<bits/stdc++.h>
using namespace std;

struct edge {
    int a, b, w;
};

int par[10005];         // Parent array
int nodeRank[10005];    // Rank array (renamed to avoid ambiguity)
edge ar[100005];        // Array to store all edges

// Comparison function to sort edges by weight in ascending order
bool cmp(edge a, edge b) {
    return a.w < b.w;  // Sort edges by their weights
}

// Find the representative of the set containing 'a' (with path compression)
int find(int a) {
    if (par[a] == -1) return a;
    else {
        par[a] = find(par[a]);  // Path compression step
        return par[a];
    }
}

// Union function to merge two sets
void union_sets(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    if (rootA != rootB) {
        // Union by rank: attach the smaller tree to the root of the larger tree
        if (nodeRank[rootA] > nodeRank[rootB]) {
            par[rootB] = rootA;  // Attach rootB's tree to rootA
            nodeRank[rootA] += nodeRank[rootB];  // Update rank of rootA
        } else {
            par[rootA] = rootB;  // Attach rootA's tree to rootB
            nodeRank[rootB] += nodeRank[rootA];  // Update rank of rootB
        }
    }
}

int main() {
    int n, m; // n: number of vertices, m: number of edges
    cin >> n >> m;
    
    // Initialize Union-Find structures
    for (int i = 1; i <= n; i++) {
        par[i] = -1;  // Initially, each node is its own parent
        nodeRank[i] = 1;  // Initially, the rank of each node is 1
    }

    // Input the edges
    for (int i = 0; i < m; i++) {
        cin >> ar[i].a >> ar[i].b >> ar[i].w;
    }

    // Sort edges by weight (non-decreasing order)
    sort(ar, ar + m, cmp);

    int sum = 0;  // Variable to store the total weight of the MST

    // Apply Kruskal's algorithm
    for (int i = 0; i < m; i++) {
        int a = find(ar[i].a);
        int b = find(ar[i].b);
        
        // If the vertices are in different sets, include this edge in the MST
        if (a != b) {
            sum += ar[i].w;  // Add the weight of the edge to the MST
            union_sets(a, b);  // Merge the two sets
        }
    }

    // Output the total weight of the MST
    cout << sum << endl;
    
    return 0;
}
