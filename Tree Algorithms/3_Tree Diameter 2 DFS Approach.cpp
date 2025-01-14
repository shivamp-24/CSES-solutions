#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

int findNode(vector<int> &dist, int n){
    int node, maxi = 0;
    for(int i=1; i<=n; i++){
        if(dist[i] >= maxi){
            maxi = dist[i];
            node = i;
        }
    }
    return node;
}

void dfs(int u, int p, vector<int> &dist, vector<int> adj[]){
    for(auto &v: adj[u]){
        if(v == p) continue;
        dist[v] = dist[u] + 1;
        dfs(v, u, dist, adj);
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
    //find the farthest node from any node
    vector<int> dist(n+1, 0);
    dfs(1, -1, dist, adj);
    int node = findNode(dist, n);
    //now find the farthest node from this node
    dist[node] = 0;
    dfs(node, -1, dist, adj);
    int dia = *max_element(dist.begin(), dist.end());
    cout << dia << endl;
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