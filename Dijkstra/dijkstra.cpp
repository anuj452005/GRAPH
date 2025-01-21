#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define ll long long
const int N = 1e5 + 10;
const int INF = 1e9 + 10;

void dijkstra(int source, vector<pair<int, int>> graph[]) {
    vector<int> vis(N, 0);
    vector<int> dist(N, INF);
    set<pair<int, int>> st;  // (weight, node)
    st.insert({0, source});
    dist[source] = 0;

    while (!st.empty()) {
        auto node = *st.begin();
        st.erase(st.begin());
        
        int v = node.second;
        int d = node.first;
        
        if (vis[v]) continue;
        vis[v] = 1;
        
        for (auto child : graph[v]) {
            int child_v = child.first;
            int wt = child.second;
            
            if (dist[v] + wt < dist[child_v]) {
                st.erase({dist[child_v], child_v});
                dist[child_v] = dist[v] + wt;
                st.insert({dist[child_v], child_v});
            }
        }
    }
    // Print the distances for verification
    for (int i = 1; i < N; i++) {
        if (dist[i] < INF) cout << "Distance from " << source << " to " << i << " is " << dist[i] << endl;
        else cout << "Node " << i << " is unreachable from source " << source << endl;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> graph[n + 1];  // (node, weight)
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        // graph[v].push_back({u, w}); // If the graph is undirected
    }

    int source;
    cin >> source;
    dijkstra(source, graph);
}

signed main() {
    fast
    solve();
    return 0;
}
