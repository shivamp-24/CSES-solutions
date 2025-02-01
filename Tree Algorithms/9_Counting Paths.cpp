#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void dfs(int u, int p, vector<int> &level, vector<int> adj[], vector<vector<int>> &parents){
    parents[0][u] = p;
    for(auto v: adj[u]){
        if(v == p) continue;
        level[v] = 1 + level[u];
        dfs(v, u, level, adj, parents);
    }
}

int findKthParent(int node, int k, vector<vector<int>> &parents, int maxi){
    for(int i=0; i<maxi; i++){
        if((k >> i) & 1){
            node = parents[i][node];
            if(node == -1) return -1;
        }
    }
    return node;
}

int findLCA(int u, int v, vector<vector<int>> &parents, int maxi, vector<int> &level){
    if(level[u] < level[v]){
        v = findKthParent(v, level[v] - level[u], parents, maxi);
    }
    else if(level[u] > level[v]){
        u = findKthParent(u, level[u] - level[v], parents, maxi);
    }
    if(u == v) return u;
    //optimized approach to find LCA
    for(int i=maxi - 1; i>=0; i--){
        if(parents[i][u] != parents[i][v]){
            u = parents[i][u];
            v = parents[i][v];
        }
    }
    return parents[0][u];
}

void dfsSum(int u, int p, vector<int> &ans, vector<int> adj[]){
    for(auto v: adj[u]){
        if(v == p) continue;
        dfsSum(v, u, ans, adj);
        ans[u] += ans[v];
    }
}

void func(){
    int n, m; cin >> n >> m;
    int maxi = log2(n) + 1;
    vector<vector<int>> parents(maxi, vector<int>(n+1, -1));
    vector<int> adj[n+1];
    for(int i=0; i<n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> level(n+1);
    level[1] = 0;
    dfs(1, -1, level, adj, parents);
    for(int i=1; i<maxi; i++){
        for(int node=1; node<=n; node++){
            int intermediate = parents[i-1][node];
            if(intermediate != -1){
                parents[i][node] = parents[i-1][intermediate];
            }
        }
    }
    vector<int> ans(n+1, 0);
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        //path from u to v
        //increase ans[u] and ans[v] by 1
        //now lca will get plus 2 from u and v combined
        //hence decrease 1 from ans[lca(u, v)]
        //parent of lca should not get any increment
        //hence decrease 1 from ans[parent[lca]]
        //call normal dfs and accumulate sum of ans array
        ans[u]++;
        ans[v]++;
        int lca = findLCA(u, v, parents, maxi, level);
        ans[lca]--;
        if(parents[0][lca] != -1) ans[parents[0][lca]]--;
    }
    dfsSum(1, -1, ans, adj);
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