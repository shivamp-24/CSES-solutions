#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func() {
    int n, q; cin >> n >> q;
    vector<int> arr(n), pre(n);
    //normal prefix sum logic
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        pre[i] = arr[i];
        if(i > 0) pre[i] += pre[i-1];
    }
    while(q--) {
        int a, b; cin >> a >> b;
        a--, b--;
        if(a == 0) cout << pre[b] << endl;
        else cout << pre[b] - pre[a-1] << endl;
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