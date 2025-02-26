#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func() {
    int n; cin >> n;
    int maxi = 0, ans = 0;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        if(x > maxi) maxi = x;
        else ans += (maxi - x);
    }
    cout << ans << endl;
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