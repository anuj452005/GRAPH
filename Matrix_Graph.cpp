#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define ll int long long 
const int N=1e5+1;
vector<int>graph[N];
vector<bool>visited[N];
void dfs(int vetex){
// c1
  visited[vetex]=true;
  for(auto child:graph[vetex]){
   // c2 
    if(visited[child]==false) dfs(child);
    // c3 
  }

// c4 
}
void solve(){
    int n,m;
    // n=vetex,m=edges
    cin>>n>>m;
   
    for(int i=0;i<m;i++){
        int v1,v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    int 
}

signed  main(){
    fast
int t;
cin>>t;
while(t--){
solve();


}
   return 0;
}