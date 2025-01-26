#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void dfs(int u, int p, vector<int> &dp, vector<int> &sub, vector<int> adj[]){
    sub[u] = 1;
    dp[u] = 0;
    for(auto v: adj[u]){
        if(v == p) continue;
        dfs(v, u, dp, sub, adj);
        sub[u] += sub[v];
        dp[u] += (sub[v] + dp[v]);
    }
}

void changeRoot(int u, int v, vector<int> &dp, vector<int> &sub){
    //remove contribution of v from u
    dp[u] -= (sub[v] + dp[v]);
    sub[u] -= sub[v];
    //add contribution of u in v
    dp[v] += (sub[u] + dp[u]);
    sub[v] += sub[u];
}

void reroot(int u, int p, vector<int> &dp, vector<int> &sub, vector<int> &ans, vector<int> adj[]){
    ans[u] = dp[u];
    for(auto v: adj[u]){
        if(v == p) continue;
        changeRoot(u, v, dp, sub); //change root from u to v
        reroot(v, u, dp, sub, ans, adj);
        changeRoot(v, u, dp, sub); //change root from v to u
    }
}

void func(){
    int n; cin >> n;
    vector<int> adj[n+1];
    for(int i=0; i<n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dp(n+1); //store initial sum of distances when rooted at 1
    vector<int> sub(n+1, 0); //store subtree size of each node
    dfs(1, -1, dp, sub, adj); //calculate initial values when rooted at 1
    vector<int> ans(n+1); //store sum of distances from node i to all other nodes
    reroot(1, -1, dp, sub, ans, adj); //dfs to make each node as root and recalculate dp
    for(int i=1; i<=n; i++) cout << ans[i] << " ";
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