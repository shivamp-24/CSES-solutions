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
    //dp[i][j] -> number of ways to reach (n-1, n-1) from (i, j)
    dp[n-1][n-1] = 1;
    for(int i=n-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            if(i == n-1 && j == n-1) continue;
            if(str[i][j] == '*'){
                dp[i][j] = 0;
                continue;
            }
            //right
            int right = 0;
            if((j + 1) < n) right = dp[i][j+1];
            //down
            int down = 0;
            if((i + 1) < n) down = dp[i+1][j];
            dp[i][j] = (right + down) % mod;
        }
    }
    cout << dp[0][0] << endl;
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