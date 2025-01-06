#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define endl "\n"
#define int long long

void printPath(vector<int> &path, int n){
    vector<int> res = {n};
    int curr = n;
    while(curr != 1){
        curr = path[curr];
        res.push_back(curr);
    }
    reverse(res.begin(), res.end());
    cout << res.size() << endl;
    for(auto &it: res) cout << it << " ";
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
    vector<int> dist(n+1, 1e9);
    queue<pair<int, int>> q;
    q.push({0, 1});
    //{dist, node}
    dist[1] = 0;
    vector<int> path(n+1);
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int cur_dist = it.first;
        int cur_node = it.second;
        for(auto &child: adj[cur_node]){
            if((cur_dist + 1) < dist[child]){
                dist[child] = cur_dist + 1;
                q.push({dist[child], child});
                path[child] = cur_node;
                if(child == n) {
                    printPath(path, n);
                    return;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
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