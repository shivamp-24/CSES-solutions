#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func(){
    string str1, str2; cin >> str1 >> str2;
    int n = str1.size(), m = str2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    //dp[i][j] -> minimum operations to transform str1[1...i] to str2[1...j]
    //tabulation
    //base case
    //str1 from empty to str2
    for(int j=0; j<=m; j++) dp[0][j] = j;
    //str1 from i to empty str2
    for(int i=0; i<=n; i++) dp[i][0] = i;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                int ans = INT_MAX;
                //replace operation
                ans = min(ans, 1 + dp[i-1][j-1]);
                //delete operation
                ans = min(ans, 1 + dp[i-1][j]);
                //add operation
                ans = min(ans, 1 + dp[i][j-1]);
                dp[i][j] = ans;
            }
        }
    }
    cout << dp[n][m] << endl;
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