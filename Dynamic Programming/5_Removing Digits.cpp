#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func(){
    int n; cin >> n;
    vector<int> dp(n+1, 1e18);
    //dp[i] -> minimum steps to make i starting from n
    dp[n] = 0;
    for(int i=n; i>=0; i--){
        if(dp[i] == 1e18) continue;
        int zz = i;
        while(zz){
            int r = zz % 10;
            dp[i - r] = min(dp[i - r], 1 + dp[i]);
            zz /= 10;
        }
    }
    cout << dp[0] << endl;
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