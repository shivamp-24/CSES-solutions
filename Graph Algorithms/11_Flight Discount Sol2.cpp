#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func(){
    int n, m; cin >> n >> m;
    vector<pair<int, int>> adj[n+1], adjrev[n+1];
    for(int i=0; i<m; i++){
        int u, v, wt; cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
    vector<vector<int>> dist(n+1, vector<int>(2, 1e18));
    //dist[i][0] -> shortest distance till i without using discount
    //dist[i][1] -> shortest distance till i after using discount
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;
    pq.push({{0, 0}, 1});
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int cd = it.first.first;
        int discount_used = it.first.second;
        int u = it.second;
        if(cd > dist[u][discount_used]) continue; //this acts as visited array
        for(auto &[v, wt]: adj[u]){
            //use discount
            if(!discount_used){
                if(dist[v][1] > cd + wt/2){
                    dist[v][1] = cd + wt/2;
                    pq.push({{dist[v][1], 1}, v});
                }
            }
            //don't use discount
            if(dist[v][discount_used] > cd + wt){
                dist[v][discount_used] = cd + wt;
                pq.push({{dist[v][discount_used], discount_used}, v});
            }
        }
    }
    cout << dist[n][1] << endl;
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