#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define N 100000

using namespace std;

int main() {
    ll n, m;
    cin >> n >> m;

    // Adjacency list to represent the graph
    vector<ll> v[n];

    // Indegree array to track incoming edges for each vertex
    vector<ll> indegree(n, 0);

    // Input the edges and construct the graph
    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        v[a].pb(b);  // Directed edge from `a` to `b`
        indegree[b]++;  // Increment indegree of vertex `b`
    }

    // Queue to store vertices with indegree 0
    queue<ll> q;

    // Push all vertices with indegree 0 into the queue
    for (ll i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // Perform Topological Sorting
    vector<ll> topo_order;  // To store the topological order
    while (!q.empty()) {
        ll cur = q.front();
        q.pop();
        topo_order.pb(cur);  // Add the current vertex to the topological order

        // Reduce indegree of neighbors and check for indegree 0
        for (ll i = 0; i < v[cur].size(); i++) {
            ll neighbor = v[cur][i];
            indegree[neighbor]--;  // Reduce indegree
            if (indegree[neighbor] == 0) {
                q.push(neighbor);  // Add to queue if indegree becomes 0
            }
        }
    }

    // Check for cycles (If topological order size is less than `n`, graph has a cycle)
    if (topo_order.size() != n) {
        cout << "The graph contains a cycle. Topological sort not possible.\n";
    } else {
        // Print the topological order
        for (ll i = 0; i < topo_order.size(); i++) {
            cout << topo_order[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
