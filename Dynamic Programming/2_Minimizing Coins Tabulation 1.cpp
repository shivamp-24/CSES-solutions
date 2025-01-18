#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func(){
    int n, x; cin >> n >> x;
    vector<int> cost(n);
    for(int i=0; i<n; i++) cin >> cost[i];
    //since dp[n][x] gave MLE
    //we need to think of something else
    vector<int> dp(x+1);
    //dp[i] --> minimum number of coins to make sum x
    dp[0] = 0;
    for(int i=1; i<=x; i++){
        //dp[i] = 1 + dp[i - cost[j]] -> take minimum for all such valid cost[j]
        int required = 1e9;
        for(int j=0; j<n; j++){
            if(i >= cost[j]){
                required = min(required, 1 + dp[i - cost[j]]);
            }
        }
        dp[i] = required;
    }
    //if no possible way, then print -1
    if(dp[x] == 1e9) cout << -1 << endl;
    else cout << dp[x] << endl;
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