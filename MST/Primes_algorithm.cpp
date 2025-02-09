#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; // (weight, node)

// Function to find the Minimum Spanning Tree using Prim's Algorithm
void primMST(int n, vector<vector<pii>> &adj) {
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-Heap
    vector<bool> inMST(n, false);  // Track included vertices
    vector<int> parent(n, -1);     // Store MST
    vector<int> key(n, INT_MAX);   // Store min edge weight for each vertex

    // Start from node 0
    pq.push({0, 0});
    key[0] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue; // Skip if already in MST

        inMST[u] = true; // Include this vertex in MST

        // Process all adjacent vertices of u
        for (auto &[weight, v] : adj[u]) {
            if (!inMST[v] && weight < key[v]) { // Update if a better edge is found
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    // Print the MST
    cout << "Minimum Spanning Tree Edges:\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " (Weight: " << key[i] << ")\n";
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<pii>> adj(n); // Adjacency list representation

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u}); // Since the graph is undirected
    }

    primMST(n, adj);

    return 0;
}
