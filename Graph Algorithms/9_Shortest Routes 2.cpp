#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func(){
    int n, m, q; cin >> n >> m >> q;
    vector<vector<int>> dist(n+1, vector<int>(n+1, 1e18));
    for(int i=0; i<m; i++){
        int u, v, wt; cin >> u >> v >> wt;
        //u->v can appear multiple times in input with different weights, hence take minimum
        dist[u][v] = min(dist[u][v], wt);
        dist[v][u] = min(dist[v][u], wt);
    }
    //floyd warshall algorithm
    for(int i=1; i<=n; i++) dist[i][i] = 0;
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int a, b;
    while(q--){
        cin >> a >> b;
        if(dist[a][b] == 1e18) cout << -1 << endl;
        else cout << dist[a][b] << endl;
    }
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