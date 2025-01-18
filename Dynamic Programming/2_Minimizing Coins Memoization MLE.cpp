#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

int func(int ind, int left_sum, vector<int> &cost, int n, vector<vector<int>> &dp){
    if(ind == n){
        if(left_sum == 0) return 0;
        return 1e9;
    }
    if(dp[ind][left_sum] != -1) return dp[ind][left_sum];
    //pick
    int pick = 1e9;
    if(cost[ind] <= left_sum){
        pick = 1 + func(ind, left_sum - cost[ind], cost, n, dp);
    }
    int skip = func(ind + 1, left_sum, cost, n, dp);
    return dp[ind][left_sum] = min(pick, skip);
}

void func(){
    int n, x; cin >> n >> x;
    vector<int> cost(n);
    for(int i=0; i<n; i++) cin >> cost[i];
    sort(cost.begin(), cost.end());
    vector<vector<int>> dp(n, vector<int>(x+1, -1));
    int ans = func(0, x, cost, n, dp);
    if(ans == 1e9) cout << -1 << endl;
    else cout << ans << endl;
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