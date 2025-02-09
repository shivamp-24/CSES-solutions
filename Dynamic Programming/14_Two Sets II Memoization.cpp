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

int memo(int ind, int sum_left, vector<vector<int>> &dp, int n){
    if(ind > n){
        if(sum_left == 0) return 1;
        return 0;
    }
    if(dp[ind][sum_left] != -1) return dp[ind][sum_left];
    //pick
    int pick = 0;
    if(ind <= sum_left) pick = memo(ind + 1, sum_left - ind, dp, n);
    //skip
    int skip = memo(ind + 1, sum_left, dp, n);
    return dp[ind][sum_left] = (pick + skip) % mod;
}

void func() {
    int n; cin >> n;
    int sum = (n * (n + 1)) / 2;
    if(sum & 1){
        cout << 0 << endl;
        return;
    }
    int req = sum / 2;
    vector<vector<int>> dp(n+1, vector<int>(req + 1, -1));
    //dp[i][j] -> number of ways to get sum (req - j) from array elements (1...i)
    int ans = memo(1, req, dp, n);
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