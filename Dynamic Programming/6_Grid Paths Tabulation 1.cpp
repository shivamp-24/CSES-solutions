#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func(){
    int n; cin >> n;
    vector<vector<char>> str(n, vector<char>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin >> str[i][j];
    }
    if(str[0][0] == '*' || str[n-1][n-1] == '*'){
        cout << 0 << endl;
        return;
    }
    vector<vector<int>> dp(n, vector<int> (n));
    //dp[i][j] -> number of ways to reach (i, j) from (0, 0)
    dp[0][0] = 1;
    //dp[i][j] -> dp[i - 1][j] + dp[i][j - 1]
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == 0 && j == 0) continue;
            if(str[i][j] == '*'){
                dp[i][j] = 0;
                continue;
            }
            //up
            int up = 0;
            if(i > 0 && str[i-1][j] == '.') up = dp[i-1][j];
            //left
            int left = 0;
            if(j > 0 && str[i][j-1] == '.') left = dp[i][j-1];
            dp[i][j] = (up + left) % mod;
        }
    }
    cout << dp[n-1][n-1] << endl;
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