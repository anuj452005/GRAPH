#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define ll long long

int bfs(int start, int n, vector<int> graph[]) {
    vector<int> depth(n + 1, -1);  
    vector<int> parent(n + 1, -1);
    queue<int> q;
    
    q.push(start);
    depth[start] = 0;

    int ans = INT_MAX;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (depth[neighbor] == -1) {
              
                depth[neighbor] = depth[node] + 1;
                parent[neighbor] = node;
                q.push(neighbor);
            } else if (parent[node] != neighbor) {
               
                ans = min(ans, depth[node] + depth[neighbor] + 1);
            }
        }
    }
    
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> graph[n + 1];

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); 
    }

    int ans = INT_MAX;

    for (int i = 1; i <= n; i++) {
        int cycle_length = bfs(i, n, graph);
        ans = min(ans, cycle_length);
    }

    if (ans == INT_MAX) {
        cout << -1 << endl; 
    } else {
        cout << ans << endl; 
    }
}

int main() {
    fast
    solve();
    return 0;
}
