#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

#define mxn 200005
int seg[4 * mxn];

void build(int node, int st, int en, vector<int> &arr) {
    if(st == en) {
        seg[node] = arr[st];
        return;
    }
    int mid = (st + en) / 2;
    build(2 * node, st, mid, arr);
    build(2 * node + 1, mid + 1, en, arr);
    seg[node] = min(seg[2 * node], seg[2 * node + 1]);
}

int query(int node, int st, int en, int l, int r) {
    if(st >= l && en <= r) return seg[node];
    if(en < l || st > r) return 1e9;
    int mid = (st + en) / 2;
    return min(query(2 * node, st, mid, l, r), query(2 * node + 1, mid + 1, en, l, r));
}

void func() {
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    //use static segment tree without updates
    build(1, 0, n-1, arr);
    while(q--) {
        int a, b; cin >> a >> b;
        a--, b--;
        cout << query(1, 0, n-1, a, b) << endl;
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