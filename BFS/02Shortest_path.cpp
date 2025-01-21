#include <bits/stdc++.h>
using namespace std;
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl "\n"
#define ll int long long
const int N=1e5+9;
vector<int>graph[N];
const int INF=1e9+10;
 int vis[8][8];
 int level[8][8];

int getX(string s) {return s[0] -'a';}
int getY(string s) {return s[1] - '1';}


bool isvalid(int x,int y){
    return x>=0 && y>=0 && x<8 && y<8;
}

vector<pair<int,int>>mov={
    {-1,2},{1,2},
    {-1,-2},{1,-2},
    {2,-1},{2,1},
    {-2,-1},{-2,1}
};

int bfs(string source ,string dest){
    int sourceX=getX(source);
    int sourceY=getY(source);
    int destX=getX(source);
    int destY=getY(source);

    queue<pair<int,int>>q;
    q.push({sourceX,sourceY});
    vis[sourceX][sourceY]=1;

    while(!q.empty()){
       int x=q.front().first;
       int y=q.front().second;
       q.pop();

       for(auto movement:mov){
         int childX=movement.first+x;
         int childY=movement.first+y;
         if(!isvalid(childX,childY)) continue;
         if(!vis[childX][childY]){
            q.push({childX,childY});
            level[childX][childY]=level[x][y]+1;
            vis[childX][childY]=1;
         }
       }
       if(level[destX][destY]!=INF) break;
    }
    return level[destX][destY];
}

void resert(){
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
        vis[i][j]=INF;
    }
  }
}

void solve()
{
   string s1,s2;
   cin>>s1>>s2;

}

signed main()
{
    fast int t;
   
    { resert();
        solve();
    }
    return 0;
}