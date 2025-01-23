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
    // vector<vector<int>> dp(n, vector<int>(x+1));
    //dp[i][j] -> number of ways to make sum j using coins till index i --> also MLE

    //final approach
    vector<int> dp(x+1, 0);
    //dp[x] -> number of ways to make sum x
    //base case --> dp[0]
    dp[0] = 1;
    //update dp[x] by considering sum till a particular index only i.e., opposite to Coin Combinations I
    for(int i=0; i<n; i++){
        //consider coins till i index only
        for(int j = c[i]; j <= x; j++){
            dp[j] += dp[j - c[i]];
            dp[j] %= mod;
        }
    }
    cout << dp[x] << endl;
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