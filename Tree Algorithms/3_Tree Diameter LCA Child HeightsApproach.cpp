#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void fleaf(int u, int p, vector<int> adj[], vector<int> &farthest_leaf){
    for(auto &v: adj[u]){
        if(v == p) continue;
        fleaf(v, u, adj, farthest_leaf);
        farthest_leaf[u] = max(farthest_leaf[u], farthest_leaf[v] + 1);
    }
}

void dfs(int u, int p, vector<int> &ans, vector<int> adj[], vector<int> &farthest_leaf){
    pair<int, int> topChild = {-1, -1}; //{max, s_max}
    for(auto &v: adj[u]){
        if(v == p) continue;
        dfs(v, u, ans, adj, farthest_leaf);
        int curr_val = farthest_leaf[v];
        if(topChild.first == -1){
            topChild.first = curr_val;
        }
        else{
            if(curr_val > topChild.first){
                topChild.second = topChild.first;
                topChild.first = curr_val;
            }
            else if(curr_val > topChild.second){
                topChild.second = curr_val;
            }
        }
    }
    ans[u] = topChild.first + topChild.second + 2;
}

void func(){
    int n; cin >> n;
    vector<int> adj[n+1];
    for(int i=0; i<n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //use formula of diameter = two max heights of childs + 2
    //we will consider each node as lca and calculate longest path through this lca i.e., maximum left + right + 2
    vector<int> farthest_leaf(n+1, 0);
    //find farthest leaf of each node
    fleaf(1, -1, adj, farthest_leaf);
    //considering each node as lca, calculate ans value for each node
    vector<int> ans(n+1);
    dfs(1, -1, ans, adj, farthest_leaf);
    //diameter will be maximum value in ans
    int dia = *max_element(ans.begin(), ans.end());
    cout << dia << endl;
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