#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int N = 1005;  // Max number of nodes
vector<int> adj[N];  // Adjacency list
vector<int> parent(N, -1);
vector<bool> visited(N, false);
vector<int> cycle;   // Stores cycle nodes

bool dfs(int node, int par) {
    visited[node] = true;
    parent[node] = par;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node)) return true;
        } else if (neighbor != par) {  // Cycle detected
            int cur = node;
            cycle.push_back(neighbor);  // Start of cycle

            while (cur != neighbor) {
                cycle.push_back(cur);
                cur = parent[cur];
            }
            cycle.push_back(neighbor);  // Complete the cycle
            return true;
        }
    }
    return false;
}

void findCycle(int n) {
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                cout << "Cycle detected: ";
                for (int v : cycle) cout << v << " ";
                cout << endl;
                return;  // Print only one cycle
            }
        }
    }
    cout << "No cycle found" << endl;
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    cout << "Enter the edges:\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // Undirected graph
    }

    findCycle(n);

    return 0;
}
