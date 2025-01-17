#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long
 
void printPath(pair<int, int> &cycle, vector<int> &parent){
    int start = cycle.first, end = cycle.second;
    vector<int> path = {start};
    int curr = end;
    while(curr != start){
        path.push_back(curr);
        curr = parent[curr];
    }
    path.push_back(start);
    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    for(auto &it: path) cout << it << " ";
    cout << endl;
}
 
bool dfs(int u, vector<int> &vis, vector<int> adj[], pair<int, int> &cycle, vector<int> &parent){
    vis[u] = 1;
    for(auto v: adj[u]){
        if(vis[v] == 0){
            parent[v] = u;
            if(dfs(v, vis, adj, cycle, parent)) return true;
        }
        else{
            if(vis[v] == 1) {
                cycle = {v, u};
                return true;
            }
        }
    }
    vis[u] = 2;
    return false;
}
 
void func(){
    int n, m; cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    //in round trip graph was undirected, here it is directed
    //we need to find a cycle in a directed graph
    //we will use path visited concept of detecting cycle in graph
    vector<int> vis(n+1, 0), parent(n+1);
    pair<int, int> cycle;
    for(int i=1; i<=n; i++){
        if(vis[i] == 0){
            if(dfs(i, vis, adj, cycle, parent)){
                printPath(cycle, parent);
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
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