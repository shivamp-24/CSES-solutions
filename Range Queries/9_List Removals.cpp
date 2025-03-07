#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

#define mxn 200005
int seg[4 * mxn];

void build(int node, int st, int en, vector<int> &arr) {
    if(st == en) {
        seg[node] = 1;
        return;
    }
    int mid = (st + en) / 2;
    build(2 * node, st, mid, arr);
    build(2 * node + 1, mid + 1, en, arr);
    seg[node] = seg[2 * node] + seg[2 * node + 1];
}

void update(int node, int st, int en, int p, int &real_index) {
    if(st == en) {
        seg[node] = 0;
        real_index = st;
        return;
    }
    int mid = (st + en) / 2;
    //p <= seg[2 * node] => move left
    //else move right with p = p - seg[2 * node]
    if(p <= seg[2 * node]) update(2 * node, st, mid, p, real_index);
    else update(2 * node + 1, mid + 1, en, p - seg[2 * node], real_index);
    seg[node] = seg[2 * node] + seg[2 * node + 1];
}

void func() {
    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    //build segment tree with sum of values with 0 and 1 denoting presence and absence of values
    build(1, 0, n-1, arr);

    for(int i=0; i<n; i++) {
        int p; cin >> p;
        //find first index with prefix sum == p
        int real_index;
        update(1, 0, n-1, p, real_index);

        cout << arr[real_index] << " ";
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