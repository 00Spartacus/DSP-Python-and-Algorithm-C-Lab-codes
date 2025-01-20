#include <bits/stdc++.h>
#define ll long long
#define N ((int)1e5 + 5)  // Maximum number of nodes
#define MOD ((int)1e9 + 7)
#define MAX ((int)1e9 + 7)
#define thr 1e-8
#define pi acos(-1)  // pi = acos(-1)
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)

using namespace std;

// Array to store the shortest distance from the source to each node
int dis[N];

// Adjacency list to store the graph
vector<int> vec[N];

// BFS function to calculate the shortest distance from source node to all other nodes
void bfs(int src) {
    memset(dis, -1, sizeof dis);  // Initialize all distances to -1 (unvisited)
    dis[src] = 0;  // Distance to source is 0
    queue<int> que;  // Queue to perform BFS
    que.push(src);

    // Perform BFS until all reachable nodes are visited
    while (!que.empty()) {
        int a = que.front();  // Current node
        que.pop();

        // Explore all neighbors of node 'a'
        for (int i = 0; i < vec[a].size(); i++) {
            int b = vec[a][i];  // Neighbor node
            if (dis[b] == -1) {  // If the neighbor has not been visited
                dis[b] = dis[a] + 1;  // Update the distance to this neighbor
                que.push(b);  // Push the neighbor to the queue
            }
        }
    }
}

int main() {
    int n, m;  // Number of nodes and edges
    cin >> n >> m;

    // Read the edges and build the graph (undirected graph)
    while (m--) {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    // Call BFS starting from node 1
    bfs(1);

    // Output the distance array (shortest distance from source node 1 to each node)
    for (int i = 1; i <= n; i++) {
        cout << "Distance from 1 to " << i << ": " << dis[i] << endl;
    }

    return 0;
}
