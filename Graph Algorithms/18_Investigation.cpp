#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> adj[n+1];
    for(int i=0; i<m; i++){
        int u, v, wt; cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
    vector<int> dist(n+1, 1e18); //stores the minimum distance to a node
    vector<int> no_of_routes(n+1, 0); //number of routes with minimum distance
    vector<int> min_steps(n+1, 1e18); //minimum flights in min path
    vector<int> max_steps(n+1, 0); //maximum flights in min path

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    no_of_routes[1] = 1;
    min_steps[1] = 0;
    max_steps[1] = 0;

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int cd = it.first;
        int u = it.second;
        if(cd > dist[u]) continue;
        for(auto [v, wt]: adj[u]){
            if((dist[u] + wt) < dist[v]){
                //new min found, hence reset all values
                dist[v] = dist[u] + wt;
                no_of_routes[v] = no_of_routes[u];
                min_steps[v] = (min_steps[u] + 1) % mod;
                max_steps[v] = max_steps[u] + 1;
                pq.push({dist[v], v});
            }
            else if((dist[u] + wt) == dist[v]){
                //this min already exists hence update all values
                no_of_routes[v] = (no_of_routes[v] + no_of_routes[u]) % mod;
                min_steps[v] = min(min_steps[v], min_steps[u] + 1);
                max_steps[v] = max(max_steps[v], max_steps[u] + 1);
            }
        }
    }
    cout << dist[n] << " " << no_of_routes[n] << " " << min_steps[n] << " " << max_steps[n] << endl;
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