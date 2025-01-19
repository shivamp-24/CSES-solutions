#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func(){
    int n, x; cin >> n >> x;
    vector<int> val(n);
    for(int i=0; i<n; i++) cin >> val[i];
    //memoization does not work as we total ways considers all permutations of coins
    vector<int> dp(x + 1, 0);
    //dp[i] -> number of ways to make sum i
    dp[0] = 1;
    for(int i=1; i<=x; i++){
        //dp[i] will be sum of all dp[i - val[j]] to consider all permutations, such that i >= val[j]
        for(int j=0; j<n; j++){
            if(i >= val[j]){
                dp[i] += dp[i - val[j]];
                dp[i] %= mod;
            }
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