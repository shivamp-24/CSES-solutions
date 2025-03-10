#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func() {
    int n, q; cin >> n >> q;
    vector<vector<int>> pre(n+1, vector<int>(n+1));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            char ch; cin >> ch;
            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + (ch == '*');
        }
    }

    while(q--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        cout << pre[x2][y2] - pre[x2][y1-1] - pre[x1-1][y2] + pre[x1-1][y1-1] << endl;
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