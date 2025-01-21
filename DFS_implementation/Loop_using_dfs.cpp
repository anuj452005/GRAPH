#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define ll int long long 
 const int N=1e5+8;
bool visited[N];
  vector<int>graph2[N];
int   dfs(int vertex,int parent){
    // components 1 
    // take the action in the vertex after entering the vertex
  
    visited[vertex]=true;
    bool isLoopExists=false;
  for(auto child:graph2[vertex]){
   
    if(visited[child] && child==parent) continue;
    if(visited[child]) return true;
    //component 2
    // take the action before entering the child vertex

      isLoopExists|=dfs(child,vertex);
    //component 3
    // take the action after entering the child vertex

  }

  //component 4 
  // take the action before exiting the vertex
 return isLoopExists;

}

// O(v+E)

void solve(){
    int n,m;
    // n== number of the vertex and m is the numbr fo the edge 
    cin>>n>>m;
    int graph1[n][n]={0};
  
    for(int i=0;i<m;i++){
        int v1,v2,w;
        cin>>v1>>v2;
        graph2[v1].push_back(v2);
        graph2[v2].push_back(v1);     
    }
    

//     int cnt=0;
//     for(int i=1;i<=n;i++){
//      if(visited[i]) continue;
//      dfs(i,);
//      cnt++;
//     }
//   cout<<cnt<<endl;
           bool falg=false;
        for(int i=1;i<=n;i++){
            if(visited[i]) continue;
            if(dfs(i,0)){
                  falg=true;
                  break;
            }
        }

if(falg) cout<<"yes"<<endl;
else cout<<"NO"<<endl;

}

signed  main(){
    fast
int t;
{
solve();


}
   return 0;
}