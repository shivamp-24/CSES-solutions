#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void dfs(int u, vector<int> &vis, vector<int> adj[]){
    vis[u] = 1;
    for(auto &v: adj[u]){
        if(!vis[v]) dfs(v, vis, adj);
    }
}

void func(){
    int n, m; cin >> n >> m;
    vector<int> adj[n+1], adjrev[n+1];
    vector<vector<int>> edges;
    //apply bellman ford algorithm
    //if positive cycle present then very large score possible -> hence negate edges and apply bellman ford to find if cycle present
    for(int i=0; i<m; i++){
        int u, v, wt; cin >> u >> v >> wt;
        edges.push_back({u, v, (-1)*wt});
        adj[u].push_back(v);
        adjrev[v].push_back(u);
    }
    //find all reachable nodes from 1 and n
    //this will help us to cosider only those cycles which are reachable from both 1 and n
    vector<int> vis1(n+1, 0), visn(n+1, 0);
    dfs(1, vis1, adj);
    dfs(n, visn, adjrev);
    vector<int> dist(n+1, 1e14);
    dist[1] = 0;
    //relax edges n-1 times
    for(int i=0; i<n-1; i++){
        for(auto &it: edges){
            int u = it[0], v = it[1], wt = it[2];
            if(dist[u] != 1e14 && (dist[u] + wt) < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }
    //relax nth time and if nodes which are reachable from both side are relaxed, then return -1
    for(auto &it: edges){
        int u = it[0], v = it[1], wt = it[2];
        if(vis1[u] && visn[v] && (dist[u] + wt) < dist[v]){
            cout << -1 << endl;
            return;
        }
    }
    cout << (-1)*dist[n] << endl;
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