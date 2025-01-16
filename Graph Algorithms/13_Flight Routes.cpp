#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func(){
    int n, m, k; cin >> n >> m >> k;
    vector<pair<int, int>> adj[n+1];
    for(int i=0; i<m; i++){
        int u, v, wt; cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    //we will maintain k best distances for each node in priority queue and it accordingly to keep k minimum distances
    vector<priority_queue<int>> dist(n+1);
    dist[1].push(0);
    pq.push({0, 1});
    while(!pq.empty()){
        auto [cd, u] = pq.top();
        pq.pop();
        if(cd > dist[u].top()) continue; //this step is necessary to avoid tle
        for(auto [v, wt]: adj[u]){
            if(dist[v].size() < k){
                dist[v].push(cd + wt);
                pq.push({cd + wt, v});
            }
            else{
                int nd = cd + wt;
                if(nd < dist[v].top()){
                    dist[v].pop();
                    dist[v].push(nd);
                    pq.push({nd, v});
                }
            }
        }
    }
    vector<int> res;
    while(!dist[n].empty()){
        res.push_back(dist[n].top());
        dist[n].pop();
    }
    reverse(res.begin(), res.end());
    for(auto &it: res) cout << it << " ";
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