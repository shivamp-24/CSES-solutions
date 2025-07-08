#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

class Bit {
public:
    int n;
    vector<int> bit;

    Bit(int n) {
        this->n = n;
        bit.resize(n+1, 0);
    }

    void update(int id, int val) {
        while(id <= n) {
            bit[id] += val;
            id += (id & -id);
        }
    }

    int query(int id) {
        int res = 0;
        while(id > 0) {
            res += bit[id];
            id -= (id & -id);
        }
        return res;
    }
};


void func() {
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    //use fenwick tree with updates
    Bit bit(n);
    for(int i=0; i<n; i++) {
        bit.update(i + 1, arr[i]);
    }
    while(q--) {
        int t; cin >> t;
        if(t == 1) {
            int pos, val; cin >> pos >> val;
            bit.update(pos, -arr[pos - 1]);
            arr[pos - 1] = val;
            bit.update(pos, arr[pos - 1]);
        }
        else {
            int a, b; cin >> a >> b;
            cout << bit.query(b) - bit.query(a - 1) << endl;
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