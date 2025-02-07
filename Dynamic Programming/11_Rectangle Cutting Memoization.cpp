#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

int memo(int a, int b, vector<vector<int>> &dp){
    if(a == b) return 0;
    if(dp[a][b] != -1) return dp[a][b];
    //horizontal cuts
    int hcut = 1e18;
    for(int i=1; i<a; i++){
        //cut at height i from top
        int cut1; //(i, b)
        if(dp[i][b] != -1) cut1 = dp[i][b];
        else cut1 = memo(i, b, dp);
        int cut2; //(a-i, b)
        if(dp[a-i][b] != -1) cut2 = dp[a-i][b];
        else cut2 = memo(a-i, b, dp);
        hcut = min(hcut, 1 + cut1 + cut2);
    }
    //vertical cuts
    int vcut = 1e18;
    for(int j=1; j<b; j++){
        //cut at width j from left
        int cut1; //(a, j)
        if(dp[a][j] != -1) cut1 = dp[a][j];
        else cut1 = memo(a, j, dp);
        int cut2; //(a, b-j)
        if(dp[a][b-j] != -1) cut2 = dp[a][b-j];
        else cut2 = memo(a, b-j, dp);
        vcut = min(vcut, 1 + cut1 + cut2);
    }
    return dp[a][b] = min(hcut, vcut);
}

void func(){
    int a, b; cin >> a >> b;
    vector<vector<int>> dp(a+1, vector<int>(b+1, -1));
    //minimum cuts required to cut (a x b) rectangle into squares
    cout << memo(a, b, dp) << endl;
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