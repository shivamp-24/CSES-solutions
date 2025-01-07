#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define endl "\n"
#define int long long

bool checkCycle(int u, int p, vector<int> &vis, vector<int> adj[], vector<int> &parent, pair<int, int> &cycle){
    vis[u] = 1;
    parent[u] = p;
    for(auto &v: adj[u]){
        if(vis[v]){
            if(v != p) {
                cycle = {v, u};
                return true;
            }
        }
        else{
            if(checkCycle(v, u, vis, adj, parent, cycle)) return true;
        }
    }
    return false;
}

void printPath(pair<int,int> &cycle, vector<int> &parent){
    int end = cycle.second;
    int og = end;
    int start = cycle.first;
    vector<int> path = {end};
    while(end != start){
        end = parent[end];
        path.push_back(end);
    }
    path.push_back(og);
    cout << path.size() << endl;
    for(auto &it: path) cout << it << " ";
    cout << endl;
}

void func(){
    int n, m; cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n+1, 0);
    vector<int> parent(n+1);
    for(int i=1; i<=n; i++){
        if(vis[i] == 0){
            pair<int, int> cycle;
            //{start, end} of cycle where we find vis[child] already visited but it is not the parent of node
            bool res = checkCycle(i, -1, vis, adj, parent, cycle);
            if(res == true){
                printPath(cycle, parent);
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
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