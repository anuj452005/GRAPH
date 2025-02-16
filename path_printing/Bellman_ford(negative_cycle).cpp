#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define ll long long

struct edge {
    int u, v, w;
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<edge> graph;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.push_back({ u, v, w });
    }

    vector<ll> dis(n + 1, 1e18);
    vector<int> parent(n + 1, -1);

    int start = -1;
    dis[1] = 0;


    for (int i = 1; i <= n - 1; i++) {
        for (auto& it : graph) {
            int u = it.u, v = it.v, w = it.w;
            if (dis[u] != 1e18 && dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                parent[v] = u;
            }
        }
    }


    for (auto& it : graph) {
        int u = it.u, v = it.v, w = it.w;
        if (dis[u] != 1e18 && dis[u] + w < dis[v]) {
            start = v;
            break;
        }
    }

    if (start == -1) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;


    for (int i = 0; i < n; i++) {
        start = parent[start];
    }

    vector<int> cycle;
    int x = start;
    while (true) {
        cycle.push_back(x);
        if (x == start && cycle.size() > 1) break;
        x = parent[x];
    }

    reverse(cycle.begin(), cycle.end());

    for (int node : cycle) {
        cout << node << " ";
    }
    cout << endl;
    //     The reason we move exactly n times along the parent array is based on graph theory and the Bellman-Ford algorithm. Let's break it down step by step.
    // 1. Understanding Bellman-Ford and Negative Cycles

    //     Bellman-Ford detects a negative cycle when we can still relax an edge after n-1 iterations.
    //     This means there's a path where distances keep decreasing infinitely, meaning a cycle exists.

    // 2. What Happens When We Detect a Negative Cycle?

    //     The node start that we find after the n-th iteration might not be inside the cycle yet.
    //     It could just be influenced by the cycle (i.e., it was updated due to a cycle but isn't part of it).
    //     If start is not inside the cycle, tracing its parent directly might not lead to a correct cycle.

    // 3. Why Moving n Times Works

    //     In a graph with n nodes, the longest simple path has at most n-1 edges.
    //     If you keep moving along the parent array for more than n-1 times, you must visit some node twice.
    //     That means you are inside a cycle! (because a cycle means a node repeats).

    // Thus, moving n times guarantees that we reach a node inside the cycle.
}

signed main() {
    fast
        solve();
    return 0;
}
