#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func(){
    int n, m; cin >> n >> m;
    vector<vector<int>> edges;
    for(int i=0; i<m; i++){
        int u, v, wt; cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }
    vector<int> dist(n+1, 1e14);
    dist[1] = 0;
    //applying bellman ford to detect negative cycle
    vector<int> parent(n+1); //store parents to find path
    int node = -1; //keeps track of the last node relaxed
    bool check;
    for(int i=0; i<n; i++){
        check = false;
        for(int i=0; i<m; i++){
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
            if((dist[u] + wt) < dist[v]){
                check = true;
                dist[v] = dist[u] + wt;
                parent[v] = u;
                node = v;
            }
        }
    }
    //check is false --> no negative cycle present
    if(!check){
        cout << "NO" << endl;
        return;
    }
    for(int i=1; i<=n; i++) node = parent[node]; //this step is done to ensure that node finally lies inside the cycle if it is an extension of cycle and distance was updated beacuse node was attached to cycle
    //now node definitely lies in a cycle, print the path using parent
    vector<int> path;
    for(int curr = node; ; curr = parent[curr]){
        path.push_back(curr);
        if(curr == node && path.size() > 1) break; //path size should be greater than 1 as initially curr is start node
    }
    reverse(path.begin(), path.end());
    cout << "YES" << endl;
    for(auto &it: path) cout << it << " ";
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