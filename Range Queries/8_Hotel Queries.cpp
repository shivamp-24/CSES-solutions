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
    seg[node] = max(seg[2 * node], seg[2 * node + 1]);
}

int update(int node, int st, int en, int val, vector<int> &arr) {
    if(st == en) {
        if(val <= arr[st]) {
            arr[st] -= val;
            seg[node] = arr[st];
            return (st + 1);
        }
        return 0;
    }
    int mid = (st + en) / 2;
    int ans;
    if(val <= seg[2 * node]) ans = update(2 * node, st, mid, val, arr);
    else ans = update(2 * node + 1, mid + 1, en, val, arr);
    seg[node] = max(seg[2 * node], seg[2 * node + 1]);
    return ans;
}

void func() {
    int n, m; cin >> n >> m;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    build(1, 0, n-1, arr);
    while(m--) {
        int r; cin >> r;
        //first index with arr[index] >= r
        cout << update(1, 0, n-1, r, arr) << " ";
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