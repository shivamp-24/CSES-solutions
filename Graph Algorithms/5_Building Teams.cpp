#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define endl "\n"
#define int long long

bool checkBipartite(int u, int color, vector<int> &col, vector<int> adj[]){
    col[u] = color;
    for(auto &v: adj[u]){
        if(col[v] == -1){
            if(!checkBipartite(v, color ^ 1, col, adj)) return false;
        }
        else{
            if(col[v] == col[u]) return false;
        }
    }
    return true;
}

void func(){
    int n, m; cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> col(n+1, -1);
    for(int i=1; i<=n; i++){
        if(col[i] == -1){
            if(!checkBipartite(i, 1, col, adj)){
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
    }
    for(int i=1; i<=n; i++) cout << col[i] + 1 << " ";
    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t=1;
    // cin>>t;
    while(t--){
        func();
    }
    return 0;
}