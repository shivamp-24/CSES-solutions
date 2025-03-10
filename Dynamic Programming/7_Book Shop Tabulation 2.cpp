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

    // vector<vector<int>> dp(n, vector<int>(x+1, -1));
    //dp[i][money] -> maximum pages till index i by using at most "money" amount
    
    // dp[n][x] gives MLE
    //hence need to space optimize
    //dp[i] -> depends only on dp[i-1] -> hence two vectors -> prev and curr can do the job
    vector<int> prev(x+1);
    //base case -> for index 0
    for(int j=0; j<=x; j++){
        if(j < price[0]) prev[j] = 0;
        else prev[j] = page[0];
    }
    //normal tabulation
    for(int i=1; i<n; i++){
        vector<int> curr(x+1);
        for(int j=0; j<=x; j++){
            //pick
            int pick = INT_MIN;
            if(price[i] <= j) pick = page[i] + prev[j - price[i]];
            //skip
            int skip = prev[j];
            curr[j] = max(pick, skip);
        }
        prev = curr;
    }
    cout << prev[x] << endl;
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