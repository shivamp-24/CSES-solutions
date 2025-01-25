#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

int findNode(vector<int> &dist, int n){
    int node = -1, maxi = -1;
    for(int i=1; i<=n; i++){
        if(dist[i] > maxi){
            maxi = dist[i];
            node = i;
        }
    }
    return node;
}

void dfs(int u, int p, vector<int> &dist, vector<int> adj[]){
    for(auto v: adj[u]){
        if(v == p) continue;
        dist[v] = 1 + dist[u];
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
    //find two ends of diameter, max distance for any node will be max of distance to these end points
    vector<int> dist(n+1, 0);
    dfs(1, -1, dist, adj);
    int start = findNode(dist, n); //one end of diameter
    vector<int> dist1(n+1, 0); //store distances from one end of diameter
    dfs(start, -1, dist1, adj);
    int end = findNode(dist1, n); //second end of diameter
    vector<int> dist2(n+1, 0); //store distances from second end of diameter
    dfs(end, -1, dist2, adj);
    vector<int> ans(n+1); //stores max distances for each node
    for(int i=1; i<=n; i++){
        ans[i] = max(dist1[i], dist2[i]);
    }
    for(int i=1; i<=n; i++) cout << ans[i] << " ";
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