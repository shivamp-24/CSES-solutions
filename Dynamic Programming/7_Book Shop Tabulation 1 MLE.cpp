#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func(){
    int n, x; cin >> n >> x;
    vector<int> price(n), page(n);
    for(int i=0; i<n; i++) cin >> price[i];
    for(int i=0; i<n; i++) cin >> page[i];
    //memoization gives MLE -> since O(n*x) ~ O(1e8)
    //hence try tabulation
    vector<vector<int>> dp(n, vector<int>(x+1, -1));
    //dp[i][money] -> maximum pages till index i by using at most "money" amount
    //base case
    for(int j=0; j<=x; j++){
        if(j < price[0]) dp[0][j] = 0;
        else dp[0][j] = page[0];
    }
    //tabulation
    for(int i=1; i<n; i++){
        for(int j=0; j<=x; j++){
            //pick
            int pick = INT_MIN;
            if(price[i] <= j) pick = page[i] + dp[i-1][j - price[i]];
            //skip
            int skip = dp[i-1][j];
            dp[i][j] = max(pick, skip);
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