#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func(){
    int a, b; cin >> a >> b;
    vector<vector<int>> dp(a+1, vector<int>(b+1));
    //minimum cuts required to cut (a x b) rectangle into squares
    //tabulation
    for(int i=1; i<=a; i++){
        for(int j=1; j<=b; j++){
            if(i == j){
                dp[i][j] = 0;
                continue;
            }
            //horizontal cuts
            int hcut = 1e18;
            for(int k=1; k<i; k++){
                int cut1 = dp[k][j];
                int cut2 = dp[i-k][j];
                hcut = min(hcut, 1 + cut1 + cut2);
            }
            //vertical cuts
            int vcut = 1e18;
            for(int k=1; k<j; k++){
                int cut1 = dp[i][k];
                int cut2 = dp[i][j-k];
                vcut = min(vcut, 1 + cut1 + cut2);
            }
            dp[i][j] = min(hcut, vcut);
        }
    }
    cout << dp[a][b] << endl;
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