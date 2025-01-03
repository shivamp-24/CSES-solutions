#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define endl "\n"
#define int long long

void dfs(int u, int p, vector<int> adj[], vector<int> &sub){
    sub[u] = 1;
    for(auto &v: adj[u]){
        if(v == p) continue;
        dfs(v, u, adj, sub);
        sub[u] += sub[v];
    }
}

void func(){
    int n; cin >> n;
    vector<int> adj[n+1];
    for(int i=2; i<=n; i++){
        int x; cin >> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    vector<int> sub(n+1, 0);
    dfs(1, -1, adj, sub);
    for(int i=1; i<=n; i++) cout << sub[i]-1 << " ";
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