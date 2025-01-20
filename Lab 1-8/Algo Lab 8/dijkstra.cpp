#include<bits/stdc++.h>
#define ll long long
#define N ((int)1e5 + 5)
#define MOD ((int)1e9 + 7)
#define MAX ((int)1e9 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)

using namespace std;

int dis[N];  // Array to store the shortest distances from the source node
bool vis[N]; // Array to keep track of visited nodes
vector<pair<int, int>> vec[N]; // Adjacency list to store the graph (node, weight)

// Function to implement Dijkstra's Algorithm
void dijkstra(int src, int n) {
    // Initialize all distances as infinity and visited array as false
    for (int i = 1; i <= n; i++) {
        dis[i] = MAX;  // Distance set to infinity initially
        vis[i] = 0;    // Mark all nodes as unvisited
    }

    dis[src] = 0;  // Distance to the source node is 0
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> prq; // Min-heap priority queue

    prq.push({0, src});  // Push the source node with distance 0

    while (!prq.empty()) {
        pair<int, int> p = prq.top();  // Get the node with the smallest distance
        prq.pop();
        int a = p.second;  // The node we're currently processing

        if (vis[a] == 1) continue;  // If the node is already visited, skip it

        vis[a] = 1;  // Mark the node as visited

        // Process all adjacent nodes (neighbors)
        for (int i = 0; i < vec[a].size(); i++) {
            int b = vec[a][i].first, c = vec[a][i].second;  // b is the neighbor, c is the weight of the edge
            int val = dis[a] + c;  // Calculate the distance to the neighbor

            // If we found a shorter path to the neighbor, update its distance
            if (dis[b] > val) {
                dis[b] = val;  // Update the distance
                prq.push({dis[b], b});  // Push the neighbor with the new distance to the priority queue
            }
        }
    }
}

int main() {
    int n, m;  // n: number of nodes, m: number of edges
    cin >> n >> m;  // Input the number of nodes and edges

    // Input the edges
    while (m--) {
        int a, b, c;  // a: start node, b: end node, c: weight of the edge
        cin >> a >> b >> c;

        // Since it's an undirected graph, add the edge in both directions
        vec[a].push_back({b, c});
        vec[b].push_back({a, c});
    }

    // Call Dijkstra's algorithm starting from node 1
    dijkstra(1, n);

    // Output the shortest distances from node 1 to all other nodes
    for (int i = 1; i <= n; i++) {
        if (dis[i] == MAX)
            cout << "INF ";  // If the node is unreachable, output "INF"
        else
            cout << dis[i] << " ";  // Output the shortest distance
    }
    cout << endl;

    return 0;
}
