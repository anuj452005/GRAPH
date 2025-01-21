#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define ll int long long 
 const int N=1e5+8;
bool visited[N];
  vector<int>graph2[N];


  vector<int>ans;
void dfs(int vertex,int& a){
    // components 1 
    // take the action in the vertex after entering the vertex
     cout<<"after entring the vertex new dfs"<<vertex<<" "<<++a<<endl;
    
    visited[vertex]=true;
  for(auto child:graph2[vertex]){
   
    if(visited[child]) continue;
    //component 2
    // take the action before entering the child vertex
    cout<<"before entering the child vertex "<<child<<" "<<++a<<endl;
   
 
    dfs(child,a);
    //component 3
    // take the action after entering the child vertex
    cout<<"after entering the ((child)) vertex "<<child<<" "<<++a<<endl;
   
   
  }

  //component 4 
  // take the action before exiting the vertex  (note ==> ye jo vertex h ye akhri child hoga )
  cout<<"before exiting the vertex "<<vertex<<" "<<++a<<endl;


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
    int cnt=0;
    for(int i=1;i<=n;i++){
     if(visited[i]) continue;
     int a=0;
     dfs(i,a);
     cnt++;
    }
    for(auto it:ans) cout<<it<<" ";


  cout<<cnt<<endl;


}

signed  main(){
    fast
int t;
{
solve();


}
   return 0;
}