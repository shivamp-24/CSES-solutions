#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define endl "\n"
#define int long long

void dfs(int u, vector<int> &vis, vector<int> adj[]){
    vis[u] = 1;
    for(auto &v: adj[u]){
        if(vis[v]) continue;
        dfs(v, vis, adj);
    }
}

void func(){
    int n, m; cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n+1, 0);
    vector<int> roads;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i, vis, adj);
            roads.push_back(i);
        }
    }
    cout << roads.size()-1 << endl;
    for(int i=1; i<roads.size(); i++){
        cout << roads[i-1] << " " << roads[i] << endl;
    }
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