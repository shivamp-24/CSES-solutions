#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func(){
    int n, m; cin >> n >> m;
    vector<int> adj[n+1];
    vector<int> in(n+1, 0);
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        in[v]++;
    }
    queue<int> q;
    vector<int> res;
    for(int i=1; i<=n; i++){
        if(in[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        res.push_back(u);
        for(auto v: adj[u]){
            in[v]--;
            if(in[v] == 0) q.push(v);
        }
    }
    if(res.size() != n) cout << "IMPOSSIBLE" << endl;
    else{
        for(auto &it: res) cout << it << " ";
        cout << endl;
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