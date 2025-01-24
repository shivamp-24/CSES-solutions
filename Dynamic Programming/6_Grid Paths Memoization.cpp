#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

int memo(int cx, int cy, vector<vector<char>> &str, int n, vector<vector<int>> &dp){
    if(cx == n-1 && cy == n-1) return 1;
    if(dp[cx][cy] != -1) return dp[cx][cy];
    int right = 0, down = 0;
    //right
    if(cy + 1 < n && str[cx][cy + 1] == '.'){
        right = memo(cx, cy + 1, str, n, dp);
    }
    //down
    if(cx + 1 < n && str[cx + 1][cy] == '.'){
        down = memo(cx + 1, cy, str, n, dp);
    }
    return dp[cx][cy] = (right + down) % mod;
}

void func(){
    int n; cin >> n;
    vector<vector<char>> str(n, vector<char>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin >> str[i][j];
    }
    if(str[0][0] == '*'){
        cout << 0 << endl;
        return;
    }
    vector<vector<int>> dp(n, vector<int> (n, -1));
    cout << memo(0, 0, str, n, dp) << endl;
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