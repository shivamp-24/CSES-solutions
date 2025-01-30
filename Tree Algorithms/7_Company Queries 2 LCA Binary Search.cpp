#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void dfs(int u, int p, vector<int> &level, vector<int> adj[]){
    for(auto v: adj[u]){
        if(v == p) continue;
        level[v] = 1 + level[u];
        dfs(v, u, level, adj);
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
    //binary search
    int low = 1, high = min(level[u], level[v]), lca = -1, mid;
    while(low <= high){
        mid = (low + high) >> 1;
        int parentU = findKthParent(u, mid, parents, maxi);
        int parentV = findKthParent(v, mid, parents, maxi);
        if(parentU == parentV){
            lca = parentU;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return lca;
}

void func(){
    int n, q; cin >> n >> q;
    int maxi = log2(n) + 1;
    vector<vector<int>> parents(maxi, vector<int>(n+1, -1));
    vector<int> adj[n+1];
    for(int i=2; i<=n; i++){
        int p; cin >> p;
        adj[i].push_back(p);
        adj[p].push_back(i);
        parents[0][i] = p;
    }
    for(int i=1; i<maxi; i++){
        for(int node=1; node<=n; node++){
            int intermediate = parents[i-1][node];
            if(intermediate != -1){
                parents[i][node] = parents[i-1][intermediate];
            }
        }
    }
    vector<int> level(n+1);
    level[1] = 0;
    dfs(1, -1, level, adj);
    while(q--){
        int u, v; cin >> u >> v;
        //finding lca using binary search
        //T.C. -> O(logn) * O(logn) = O(log^2n)
        int lca = findLCA(u, v, parents, maxi, level);
        cout << lca << endl;
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