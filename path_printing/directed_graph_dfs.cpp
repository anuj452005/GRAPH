#include <iostream>
#include <vector>

using namespace std;

const int N = 1005;  // Maximum number of nodes
vector<int> adj[N];  // Adjacency list
vector<bool> visited(N, false);
vector<bool> recStack(N, false);
vector<int> parent(N, -1);
vector<int> cycle;


bool dfs(int node) {
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            parent[neighbor] = node;
            if (dfs(neighbor)) return true;
        } else if (recStack[neighbor]) {  
            int cur = node;
            cycle.push_back(neighbor);  

            while (cur != neighbor) {
                cycle.push_back(cur);
                cur = parent[cur];
            }
            cycle.push_back(neighbor);  
            return true;
        }
    }

    recStack[node] = false;  
    return false;
}

// Function to find a cycle in a directed graph
void findCycle(int n) {
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i)) {
                cout << "Cycle detected: ";
                for (int v : cycle) cout << v << " ";
                cout << endl;
                return;  // Print only one cycle
            }
        }
    }
    cout << "No cycle found" << endl;
}

// Driver Code
int main() {
    int n = 4;
    adj[1].push_back(3);
    adj[2].push_back(1);
    adj[2].push_back(4);
    adj[3].push_back(2); 
    adj[3].push_back(4); 

    findCycle(n);

    return 0;
}
