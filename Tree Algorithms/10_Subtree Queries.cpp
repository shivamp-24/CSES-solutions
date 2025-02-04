#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

#define mxn 200005
int seg[4 * mxn];

void build(int node, int st, int en, vector<int> &arr, vector<int> &val){
    if(st == en){
        seg[node] = val[arr[st]];
        return;
    }
    int mid = (st + en) / 2;
    build(2 * node, st, mid, arr, val);
    build(2 * node + 1, mid + 1, en, arr, val);
    seg[node] = seg[2 * node] + seg[2 * node + 1];
}

void update(int node, int st, int en, int pos, int value, vector<int> &val, vector<int> &arr){
    if(st == en){
        seg[node] = val[arr[pos]] = value;
        return;
    }
    int mid = (st + en) / 2;
    if(pos <= mid) update(2 * node, st, mid, pos, value, val, arr);
    else update(2 * node + 1, mid + 1, en, pos, value, val, arr);
    seg[node] = seg[2 * node] + seg[2 * node + 1];
}

int query(int node, int st, int en, int l, int r){
    if(st >= l && en <= r) return seg[node];
    if(en < l || st > r) return 0;
    int mid = (st + en) / 2;
    return query(2 * node, st, mid, l, r) + query(2 * node + 1, mid + 1, en, l, r);
}

void dfs(int u, int p, int &timer, vector<int> &in, vector<int> &out, vector<int> &arr, vector<int> &val, vector<int> adj[]){
    in[u] = timer++;
    arr.push_back(u);
    for(auto v: adj[u]){
        if(v == p) continue;
        dfs(v, u, timer, in, out, arr, val, adj);
    }
    out[u] = timer++;
}

void func(){
    int n, q; cin >> n >> q;
    vector<int> val(n+1);
    for(int i=1; i<=n; i++) cin >> val[i];
    vector<int> adj[n+1];
    for(int i=0; i<n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //logic -> use segment tree with point updates
    //we will make array in the order in which nodes are visited
    //array will contain node
    //use in time and out time to find out the range of indices till which a subtree of current node is valid
    //then call normal segment tree for range sum of values in each query for arr array

    vector<int> arr; //store the order in which nodes are visited in dfs
    vector<int> in(n+1, 0), out(n+1, 0);
    int timer = 0;
    dfs(1, -1, timer, in, out, arr, val, adj);

    vector<int> ind(n+1); //to find a particular node is at what index in arr
    // used when we need to reach the node at which "update" is to be done or find the range of indices for which it contains its subtree nodes...
    for(int i=0; i<n; i++){
        ind[arr[i]] = i;
    }

    //now we can build segment tree to contain sum of values in particular range
    build(1, 0, n-1, arr, val);

    while(q--){
        int type; cin >> type;
        if(type == 1){
            int s, x; cin >> s >> x;
            //updating needs to be done
            //ind[s] -> index in arr where s is present
            //arr[ind[s]] = s
            //val[arr[ind[s]]] = val[s] = x
            update(1, 0, n-1, ind[s], x, val, arr);
        }
        else{
            int s; cin >> s;
            //find the range of indices which contains subtree of s
            int l = ind[s];
            int r = l + (out[s] - in[s]) / 2;
            cout << query(1, 0, n-1, l, r) << endl;
        }
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
