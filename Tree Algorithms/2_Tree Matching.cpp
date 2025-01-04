#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define endl "\n"
#define int long long

void dfs(int u, int p, vector<int> adj[], vector<vector<int>> &dp){
    for(auto &v: adj[u]){
        if(v == p) continue;
        dfs(v, u, adj, dp);
        dp[u][0] += max(dp[v][0], dp[v][1]);
    }
    for(auto &v: adj[u]){
        if(v == p) continue;
        dp[u][1] = max(dp[u][1], 1 + dp[u][0] - max(dp[v][0], dp[v][1]) + dp[v][0]);
    }
}

void func(){
    int n;  cin >> n;
    vector<int> adj[n+1];
    for(int i=0; i<n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> dp(n+1, vector<int>(2, 0));
    //dp[u][0] = maximum number of edges in a matching in the subtree rooted at u, if u is not included in the matching
    //dp[u][1] = maximum number of edges in a matching in the subtree rooted at u, if u is included in the matching
    //dp[u][0] = sum of max(dp[v][0], dp[v][1]) for all v in adj[u]
    //dp[u][1] => we will pick one v from adj[u] for pairing with u, and for all other v in adj[u], we will pick max(dp[v][0], dp[v][1])
    //dp[u][1] = 1 + sum of max(dp[v][0], dp[v][1]) for all v in adj[u] except the one picked for pairing with u
    //dp[u][1] = 1 + sum of max(dp[v][0], dp[v][1]) for all v in adj[u] - max(dp[v1][0], dp[v1][1]) + dp[v1][0] where v1 is the one picked for pairing with u
    //dp[u][1] = 1 + dp[u][0] - max(dp[v1][0], dp[v1][1]) + dp[v1][0]
    //we will consider picking each v from adj[u] as the one to be paired with u, and take the maximum of all these values
    dfs(1, -1, adj, dp);
    int ans = max(dp[1][0], dp[1][1]);
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t=1;
    // cin>>t;
    while(t--){
        func();
    }
    return 0;
}