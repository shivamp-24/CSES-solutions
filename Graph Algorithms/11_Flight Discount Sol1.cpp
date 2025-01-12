#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void dijkstra(int src, vector<pair<int, int>> adj[], vector<int> &dist){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dist[src] = 0;
    vector<int> vis(dist.size(), 0);
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int u = it.second;
        int cd = it.first;
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto i: adj[u]){
            int v = i.first;
            int wt = i.second;
            if(dist[v] > cd + wt){
                dist[v] = cd + wt;
                pq.push({dist[v], v});
            }
        }
    }
}

void func(){
    int n, m; cin >> n >> m;
    vector<pair<int, int>> adj[n+1], adjrev[n+1];
    for(int i=0; i<m; i++){
        int u, v, wt; cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adjrev[v].push_back({u, wt});
    }
    //find distance of each node from 1 and n
    //adj for finding path from 1 and adjrev for finding path from n
    vector<int> dist1(n+1, 1e18), distn(n+1, 1e18);
    dijkstra(1, adj, dist1);
    dijkstra(n, adjrev, distn);
    //for path 1 -> A -> B -> n, if we take discount at A -> B, then cost = dist1[A] + distn[B] + wt/2
    //do this for all edges
    int ans = 1e18;
    for(int u=1; u<=n; u++){
        for(auto &[v, wt]: adj[u]){
            ans = min(ans, dist1[u] + distn[v] + wt / 2);
        }
    }
    cout << ans << endl;
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