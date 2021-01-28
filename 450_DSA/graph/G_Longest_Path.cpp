#include "bits/stdc++.h"
using namespace std;
vector<int> adj[100005];
vector<int> dp(100005);
bool vis[100005];

void dfs(int curr){
    dp[curr]=0;
    vis[curr]=true;
    for(int i:adj[curr]){
        if(!vis[i]){
            dfs(i);
        }
        dp[curr]= max(dp[curr],1+dp[i]);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        vis[i]=false;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    
    int ans=dp[1];
    for(int i=1;i<=n;i++){
        if(ans<dp[i]) ans= dp[i];
    }
    cout<<ans;
    return 0;

}