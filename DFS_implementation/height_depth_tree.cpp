#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define ll int long long 

 const int N=1e5+8;
 int depth[N],height[N];

  vector<int>graph2[N];
void dfs(int vertex,int parent){
    // components 1 
    // take the action in the vertex after entering the vertex(  niche jate hue )
    // 
  
   
  for(auto child:graph2[vertex]){
   
    if(child==parent) continue;
    //component 2
    // take the action before entering the child vertex   ( niche jate hue )
    depth[child]=depth[vertex]+1;

    dfs(child,vertex);
    height[vertex]=max(height[vertex],height[child]+1);
    //component 3
    // take the action after entering the child vertex    ( upar jate hue )

  }

  //component 4 
  // take the action before exiting the vertex        ( upar jate hue )


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