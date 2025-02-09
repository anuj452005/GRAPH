#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define ll int long long 
const int n=1e5+6;
int subtree_N[n];
vector<int>graph[n];
void dfs(int vertex,int parent){
    // components 1 
    // take the action in the vertex after entering the vertex(  niche jate hue )
    // 
  
    subtree_N[vertex] = 1;
  for(auto child:graph[vertex]){
   
    if(child==parent) continue;
    //component 2
    // take the action before entering the child vertex   ( niche jate hue )

    dfs(child,vertex);
   
    //component 3
    // take the action after entering the child vertex    ( upar jate hue )
    subtree_N[vertex]+=subtree_N[child];


  }

  //component 4 
  // take the action before exiting the vertex        ( upar jate hue )
  //  subtree_N[vertex]+=vertex;

}
void solve(){
    
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