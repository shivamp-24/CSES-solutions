#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> adj[n+1];
    for(int i=0; i<m; i++) {
        int u, v, wt; cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    //minimum spanning tree finding approach
    //prim's algorithm
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; //stores {edge weight, node}
    vector<int> vis(n + 1, 0);
    pq.push({0, 1});

    int mst = 0;
    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int cwt = it.first;
        int u = it.second;

        if(vis[u]) continue;
        vis[u] = 1;
        mst += cwt;

        for(auto [v, wt]: adj[u]) {
            if(!vis[v]) {
                pq.push({wt, v});
            }
        }
    }

    //check if disconnected graph
    //then mst not possible
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    cout << mst << endl;
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