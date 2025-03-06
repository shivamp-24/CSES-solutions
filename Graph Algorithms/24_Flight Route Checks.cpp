#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

vector<int> vis;

void dfs(int u, vector<int> adj[]) {
    vis[u] = 1;
    for(int v: adj[u]) {
        if(vis[v]) continue;
        dfs(v, adj);
    }
}

void func() {
    //given directed graph
    //need to find if we can reach any node from any node

    //logic
    //suppose from a node u => we can reach all other nodes
    //now another necessary condition => we must be able to reach u from all other nodes

    //let's say u = 1
    //check if all nodes reachable from 1 => if no then print 1 and unreachable node
    //now all nodes are reachable from 1
    //now 1 must be reachable from all other nodes
    //hence, in reverse graph, all nodes are reachable from 1 => if no then print unreachable node and 1

    int n, m; cin >> n >> m;
    vector<int> adj[n+1], adjrev[n+1];
    for(int i=0; i<m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adjrev[v].push_back(u);
    }

    vis.assign(n+1, 0);
    dfs(1, adj);

    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            cout << "NO" << endl;
            cout << 1 << " " << i << endl;
            return;
        }
    }

    vis.assign(n+1, 0);
    dfs(1, adjrev);

    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            cout << "NO" << endl;
            cout << i << " " << 1 << endl;
            return;
        }
    }

    cout << "YES" << endl;
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