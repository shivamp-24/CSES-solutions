#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

#define mxn 200005
int seg[4 * mxn];

void update(int node, int st, int en, int pos, int val, vector<int> &sum) {
    if(st == en) {
        sum[st] += val;
        seg[node] = sum[st];
        return;
    }
    int mid = (st + en) / 2;
    if(pos <= mid) update(2 * node, st, mid, pos, val, sum);
    else update(2 * node + 1, mid + 1, en, pos, val, sum);
    seg[node] = seg[2 * node] + seg[2 * node + 1];
}

int query(int node, int st, int en, int l, int r) {
    if(st >= l && en <= r) return seg[node];
    if(en < l || st > r) return 0;
    int mid = (st + en) / 2;
    return (query(2 * node, st, mid, l, r) + query(2 * node + 1, mid + 1, en, l, r));
}

void func() {
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    //array to maintain updates -> use prefix difference logic => sum[l]++ and sum[r+1]-- => similar logic used here
    vector<int> sum(n, 0);

    // build(1, 0, n-1, sum);
    //we do not need to build segment tree as we are just storing 0 in nodes which is already there as global declaration

    while(q--) {
        int t; cin >> t;
        if(t == 1) {
            int a, b, u; cin >> a >> b >> u;
            a--, b--;
            //increase sum[a] by u and decrease sum[b+1] by u
            update(1, 0, n-1, a, u, sum);
            if((b + 1) < n) update(1, 0, n-1, b+1, -1 * u, sum);
        }
        else {
            int k; cin >> k;
            k--;
            //find the updates till k-th index using segment tree in sum array
            int updates = query(1, 0, n-1, 0, k);
            cout << updates + arr[k] << endl;
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