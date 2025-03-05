#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

#define mxn 1000000
int cnt[mxn + 1];

void pre() {
    for(int i=1; i<=mxn; i++) {
        for(int j=i; j<=mxn; j+=i) {
            cnt[j]++;
        }
    }
}

void func() {
    int n; cin >> n;
    pre();
    while(n--) {
        int x; cin >> x;
        cout << cnt[x] << endl;
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