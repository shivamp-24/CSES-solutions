#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func(){
    int n, m; cin >> n >> m;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<vector<int>> dp(n, vector<int>(m+1));
    //dp[i][last] -> number of arrays till i-th index when last is used as arr[i]
    //base case -> arr[0] = 0 -> then dp[0][1...m] = 1, if(arr[0] != 0) -> then dp[0][arr[0]] = 1, other dp[0][y] = 0
    for(int j=1; j<=m; j++){
        if(arr[0] == 0 || arr[0] == j){
            dp[0][j] = 1;
        }
        else {
            dp[0][j] = 0;
        }
    }
    //normal tabulation
    for(int i=1; i<n; i++){
        for(int j=1; j<=m; j++){
            if(arr[i] == 0 || arr[i] == j){
                //we can make it j
                for(int k=j-1; k<=(j+1); k++){
                    if(k < 1 || k > m) continue;
                    dp[i][j] = (dp[i][j] + dp[i-1][k]) % mod;
                }
            }
            else{
                //arr[i] != 0 && arr[i] != j
                dp[i][j] = 0;
            }
        }
    }
    //now dp[n-1][...] will contain result
    //if arr[n-1] != 0, then dp[n-1][arr[n-1]] will be result
    //else sum of dp[n-1][...] will be result
    if(arr[n-1]) cout << dp[n-1][arr[n-1]] << endl;
    else{
        int ans = 0;
        for(int j=1; j<=m; j++) ans = (ans + dp[n-1][j]) % mod;
        cout << ans << endl;
    }
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