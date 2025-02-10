#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

#define mxn 200005
int seg[4 * mxn];

vector<int> val, parent, depth, heavy, head, pos;
int cur_pos;

void build(int node, int st, int en, vector<int> &arr){
    if(st == en){
        seg[node] = val[arr[st]];
        return;
    }
    int mid = (st + en) / 2;
    build(2 * node, st, mid, arr);
    build(2 * node + 1, mid + 1, en, arr);

    seg[node] = max(seg[2 * node], seg[2 * node + 1]);
}

void update(int node, int st, int en, int ind, int value, vector<int> &arr){
    if(st == en){
        val[arr[ind]] = value;
        seg[node] = value;
        return;
    }
    int mid = (st + en) / 2;
    if(ind <= mid) update(2 * node, st, mid, ind, value, arr);
    else update(2 * node + 1, mid + 1, en, ind, value, arr);
    
    seg[node] = max(seg[2 * node], seg[2 * node + 1]);
}

int query(int node, int st, int en, int l, int r){
    if(st >= l && en <= r) return seg[node];
    if(en < l || st > r) return 0;
    int mid = (st + en) / 2;
    return max(query(2 * node, st, mid, l, r), query(2 * node + 1, mid + 1, en, l, r));
}

int dfs(int v, vector<int> adj[]){
    int size = 1;
    int max_c_size = 0; //helps find the child which will be part of heavy edge
    for(int c: adj[v]){
        if(c == parent[v]) continue;
        parent[c] = v, depth[c] = depth[v] + 1;
        int c_size = dfs(c, adj);
        size += c_size;
        if(c_size > max_c_size){
            max_c_size = c_size;
            heavy[v] = c;
        }
    }
    return size;
}

void decompose(int v, int h, vector<int> adj[]){
    head[v] = h, pos[v] = cur_pos++;
    if(heavy[v] != -1){
        decompose(heavy[v], h, adj); //call child to continue the heavy path from v
    }
    //only other childs which are not part of heavy edge left
    for(int c: adj[v]){
        if(c != parent[v] && c != heavy[v]){
            decompose(c, c, adj); //new heavy path start from c
        }
    }
}

int query_path(int a, int b, int n){
    int res = 0;
    for(; head[a] != head[b]; b = parent[head[b]]) {
        if(depth[head[a]] > depth[head[b]]) swap(a, b);
        int cur_heavy_path_max = query(1, 0, n-1, pos[head[b]], pos[b]); //query in segment tree to find for current heavy path
        res = max(res, cur_heavy_path_max);
    }
    //now both a and b part of same heavy path
    if(depth[a] > depth[b]) swap(a, b);
    int last_heavy_path_max = query(1, 0, n-1, pos[a], pos[b]);
    res = max(res, last_heavy_path_max);
    return res;
}

void func() {
    int n, q; cin >> n >> q;
    val = vector<int>(n);
    for(int i=0; i<n; i++){
        cin >> val[i];
    }
    vector<int> adj[n];
    for(int i=0; i<n-1; i++){
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //heavy light decomposition
    //heavy edge -> edge from a node downward to the child with the max subtree size
    parent = vector<int>(n); //store parent for dfs and decompose -> useful while finding heavy paths
    depth = vector<int>(n); //depth is required to check which path to consider -> use depth[a] and depth[b] and call whichever lies at more depth
    heavy = vector<int>(n, -1); //stores the child which leads to heavy path
    head = vector<int>(n); //stores the head or top-most node for each node
    pos = vector<int>(n); //used for segment tree -> each heavy path is divided into some intervals -> decided by pos array
    cur_pos = 0; //helps determine the order of visiting from head to down in heavy paths for segment tree

    dfs(0, adj); //root is 0

    decompose(0, 0, adj); //(root, head, adj)

    //now time to build segment tree
    //segment tree will be built on values in pos array
    //seg[node] will store value of that node
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        arr[pos[i]] = i;
    }

    build(1, 0, n-1, arr); //in build we will use value of node present in arr

    while(q--){
        int t; cin >> t;
        if(t == 1){
            int s, x; cin >> s >> x;
            s--;
            //what position needs to be updated??
            //index will be pos[s]
            //update val[s] = x
            //s = arr[pos[s]]
            //val[arr[pos[s]]] = x
            //index is pos[s]
            update(1, 0, n-1, pos[s], x, arr);
        }
        else{
            int a, b; cin >> a >> b;
            a--, b--;
            cout << query_path(a, b, n) << " ";
        }
    }
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