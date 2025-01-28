#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func(){
    int n, m; cin >> n >> m;
    vector<int> adj[n+1];
    vector<int> in(n+1, 0);
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        in[v]++;
    }
    vector<int> dp(n+1, 0);
    // dp[i] = number of ways to reach i from 1
    // dp[v] = dp[u] for all u which has an edge to v -> hence need to process in toposort manner
    //we will process nodes in topological manner, so that previous nodes already have an answer for next node to process
    //base case
    dp[1] = 1;
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(!in[i]) q.push(i);
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v: adj[u]){
            dp[v] = (dp[v] + dp[u]) % mod;
            in[v]--;
            if(!in[v]) q.push(v);
        }
    }
    cout << dp[n] << endl;
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