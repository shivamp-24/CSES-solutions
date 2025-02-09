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
    // vector<vector<int>> dp(n + 1, vector<int>(req + 1));
    //dp[i][j] -> number of ways to get sum (req - j) from elements (1...i)

    //space optimization
    vector<int> prev(req + 1);
    //base case
    for(int j=0; j<=req; j++){
        if(j <= 1) prev[j] = 1;
        else prev[j] = 0;
    }

    //fill table
    for(int i=2; i<=n; i++){
        vector<int> curr(req + 1);
        for(int j=0; j<=req; j++){
            int pick = 0;
            if(i <= j) pick = prev[j - i];
            int skip = prev[j];
            curr[j] = (pick + skip) % mod;
        }
        prev = curr;
    }
    int ans = prev[req];
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