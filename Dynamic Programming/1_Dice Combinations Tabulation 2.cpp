#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define endl "\n"
#define int long long

void func(){
    int n; cin >> n;
    vector<int> dp(n+1);
    //dp[i] --> number of ways to make sum n starting from i
    dp[n] = 1;
    for(int i=n-1; i>=0; i--){
        for(int j=1; j<=6; j++){
            if((i + j) > n) continue;
            dp[i] += dp[i+j];
            dp[i] %= mod;
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