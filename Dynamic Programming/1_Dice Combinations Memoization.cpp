#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

int solve(int n, vector<int> &dp){
    if(n < 0) return 0;
    if(n == 0) return 1;
    if(dp[n] != -1) return dp[n];
    int ans = 0;
    for(int i=1; i<=6; i++){
        ans += solve(n - i, dp);
        ans %= mod;
    }
    return dp[n] = ans;
}

void func(){
    int n; cin >> n;
    vector<int> dp(n+1, -1);
    cout << solve(n, dp) << endl;
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