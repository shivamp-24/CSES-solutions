#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

//(x^y) % mod
int power(int x, int y){
    int res = 1;

    x %= mod;
    if(x == 0) return 0;

    while(y){
        if(y & 1){
            res = (res * x) % mod;
        }
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

void func() {
    int n; cin >> n;
    int sum = (n * (n + 1)) / 2;
    if(sum & 1){
        cout << 0 << endl;
        return;
    }
    int req = sum / 2;
    vector<vector<int>> dp(n + 1, vector<int>(req + 1));
    //dp[i][j] -> number of ways to get sum (req - j) from elements (1...i)

    //tabulation
    //base case
    for(int j=0; j<=req; j++){
        if(j <= 1) dp[1][j] = 1;
        else dp[1][j] = 0;
    }
    
    //fill table
    for(int i=2; i<=n; i++){
        for(int j=0; j<=req; j++){
            int pick = 0;
            if(i <= j) pick = dp[i-1][j - i];
            int skip = dp[i-1][j];
            dp[i][j] = (pick + skip) % mod;
        }
    }
    int ans = dp[n][req];
    //final result for unique pairs -> ans / 2
    ans = (ans * power(2, mod - 2)) % mod;
    cout << ans << endl;
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