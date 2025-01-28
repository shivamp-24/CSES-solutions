#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void dfs(int u, vector<int> &vis, vector<int> &dp, vector<int> adj[], vector<int> &next){
    vis[u] = 1;
    for(auto v: adj[u]){
        if(!vis[v]) dfs(v, vis, dp, adj, next);
        //now dp[v] will have been calculated
        //update dp[u]
        //checking dp[v] != -1 is necessary -> why?? --> because what if v can never reach n and hence it's value will remain -1
        if(dp[v] != -1 && (dp[v] + 1) > dp[u]){
            dp[u] = dp[v] + 1;
            next[u] = v;
        }
    }
}

void func(){
    int n, m; cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    //using normal queue to find max distance from 1 to n gives TLE, hence another approach required
    //we will use dp
    vector<int> dp(n+1, -1);
    //dp[i] -> max number of nodes on the path from i to n
    dp[n] = 1;
    //dp[u] = 1 + dp[v] where v is child of u -> can only calculate dp[u] when dp[v] is already calculated
    vector<int> next(n+1); //stores the next child node that current nodes chooses for maximum nodes in path
    vector<int> vis(n+1, 0);
    dfs(1, vis, dp, adj, next);
    //final result in dp[1]
    if(dp[1] == -1){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    cout << dp[1] << endl;
    //print path using next array
    for(int u=1; ; u = next[u]){
        cout << u << " ";
        if(u == n) break;
    }
    cout << endl;
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    while(t--){
        func();
    }
    return 0;
}