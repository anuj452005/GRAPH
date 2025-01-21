#include <bits/stdc++.h>
using namespace std;
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl "\n"
#define ll int long long
// bfs me level wise  traverasla hota h
// it use the quene
    const  int N=1e5;
    vector<int>graph[N];
    int vis[N];
    int level[N];  // gives the shortest path from the  source vertex


void bfs(int source){
    queue<int>q;
    q.push( source);
     vis[source]=1;

   while(!q.empty()){
        int cur_v=q.front();
         q.pop();
          for(int child:graph[cur_v]){
            if(!vis[child]){
            q.push(child);
            vis[child]=1;
            level[child]=level[cur_v]+1;
           }
          }

 }
}

// v-node n-edges
// O(V+E)


void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

}

signed main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}