#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func(){
    int n, x; cin >> n >> x;
    vector<int> c(n);
    for(int i=0; i<n; i++) cin >> c[i];
    //since memoization will give MLE due to O(n*x) space, hence we need to think of tabulation only
    vector<vector<int>> dp(n, vector<int>(x+1));
    //dp[i][j] -> number of ways to make sum j using coins till index i
    //base case -> dp[i][0]
    for(int i=0; i<n; i++) dp[i][0] = 1;
    //dp[0][j]
    for(int j=0; j<=x; j++){
        dp[0][j] = 0;
        if(j % c[0] == 0) dp[0][j] = 1;
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<=x; j++){
            int skip = dp[i-1][j];
            int pick = 0;
            if(j >= c[i]) pick = dp[i][j - c[i]];
            dp[i][j] = (pick + skip) % mod;
        }
    }
    cout << dp[n-1][x] << endl;
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