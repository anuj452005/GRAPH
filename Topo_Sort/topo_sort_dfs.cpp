#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define ll int long long 

void toposort(vector<vector<int>>&graph,stack<int>st,vector<int>&vis,int node){
    vis[node]=true;
    for(auto child:graph[node]){
        if(!vis[child]){
            toposort(graph,st,vis,child);
        }
    }
    st.push(node);
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