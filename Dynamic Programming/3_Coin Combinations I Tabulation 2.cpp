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
    //dp[i] -> number of ways to make sum x with current sum i
    dp[x] = 1;
    for(int i=x-1; i>=0; i--){
        //dp[i] -> sum of all dp[i + val[j]] such that (i + val[j]) <= x
        for(int j=0; j<n; j++){
            if((i + val[j]) <= x){
                dp[i] += dp[i + val[j]];
                dp[i] %= mod;
            }
        }
    }
    //final answer dp[0] as initial sum is 0
    cout << dp[0] << endl;
}
signed main(){
    3++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    while(t--){
        func();
    }
    return 0;
}