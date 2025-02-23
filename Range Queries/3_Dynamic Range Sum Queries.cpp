#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

#define mxn 200005
int seg[4 * mxn];
 
void build(int node, int st, int en, vector<int> &arr){
    if(st == en){
        seg[node] = arr[st];
        return;
    }
    int mid = (st + en) / 2;
    build(2 * node, st, mid, arr);
    build(2 * node + 1, mid + 1, en, arr);
    seg[node] = seg[2 * node] + seg[2 * node + 1];
}
 
void update(int node, int st, int en, int pos, int val, vector<int> &arr){
    if(st == en){
        seg[node] = arr[pos] = val;
        return;
    }
    int mid = (st + en) / 2;
    if(pos <= mid) update(2 * node, st, mid, pos, val, arr);
    else update(2 * node + 1, mid + 1, en, pos, val, arr);
    seg[node] = seg[2 * node] + seg[2 * node + 1];
}
 
int query(int node, int st, int en, int l, int r){
    if(st >= l && en <= r) return seg[node];
    if(en < l || st > r) return 0;
    int mid = (st + en) / 2;
    return query(2 * node, st,mid, l, r) + query(2 * node + 1, mid + 1, en, l, r);
}


void func() {
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    //use segment tree with updates
    build(1, 0, n-1, arr);
    while(q--) {
        int t; cin >> t;
        if(t == 1) {
            int pos, val; cin >> pos >> val;
            pos--;
            update(1, 0, n-1, pos, val, arr);
        }
        else {
            int a, b; cin >> a >> b;
            a--, b--;
            cout << query(1, 0, n-1, a, b) << endl;
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