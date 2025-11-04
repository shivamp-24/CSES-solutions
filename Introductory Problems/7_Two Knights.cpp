#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func() {
    int n; cin >> n;
    for(int k=1; k<=n; k++) {
        int totalWays = ((k*k) * (k*k - 1)) / 2;
        int attackWays = 4 * (k-2) * (k-1);
        cout << totalWays - attackWays << endl;
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