#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long
 
void func(){
    int n, m; cin >> n >> m;
    vector<pair<int,int>> adj[n+1];
    for(int i=0; i<m; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n+1, 1e18), vis(n+1, 0);
    pq.push({0, 1});
    dist[1] = 0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int cd = it.first;
        int u = it.second;
        if(vis[u] == 1) continue;
        vis[u] = 1;
        for(auto &it: adj[u]){
            int v = it.first, wt = it.second;
            if((cd + wt) < dist[v]){
                dist[v] = cd + wt;
                pq.push({dist[v], v});
            }
        }
    }
    for(int i=1; i<=n; i++) cout << dist[i] << " ";
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