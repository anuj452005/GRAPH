#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define ll int long long 
void solve(){
    int n;
    cin>>n;
    vector<int>graph[n+1];
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);        
    }
     vector<int>indegree(n,0);
        vector<int>res;
        queue<int>q;
        //1
        for(int u=0;u<n;u++){
            for(int &v:graph[u]){
                indegree[v]++;
            }
        }
        //2
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int u=q.front();
            q.pop();
            res.push_back(u);
            for(auto v:graph[u]){
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
            }
        }
         

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