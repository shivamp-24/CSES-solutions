#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

int n, m;
vector<vector<int>> dp;
vector<int> arr1, arr2;

// int memo(int i, int j) {
//     if(i == n || j == m) return 0;
//     if(dp[i][j] != -1) return dp[i][j];

//     //pick
//     int pick = 0;
//     if(arr1[i] == arr2[j]) pick = 1 + memo(i+1, j+1);

//     int skip = max(memo(i+1, j), memo(i, j+1));

//     return dp[i][j] = max(pick, skip);
// }

void func(){
    cin >> n >> m;
    arr1.resize(n);
    arr2.resize(m);
    for(int i=0; i<n; i++) cin >> arr1[i];
    for(int i=0; i<m; i++) cin >> arr2[i];
    // dp.assign(n, vector<int>(m, -1));
    // cout << memo(0, 0) << endl;

    dp.assign(n+1, vector<int>(m+1, 0));
    for(int i=n-1; i>=0; i--) {
        for(int j=m-1; j>=0; j--) {
            int pick = 0;
            if(arr1[i] == arr2[j]) pick = 1 + dp[i+1][j+1];
            int skip = max(dp[i+1][j], dp[i][j+1]);

            dp[i][j] = max(pick, skip);
        }
    }
    cout << dp[0][0] << endl;

    //print lcs
    vector<int> lcs;
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(arr1[i] == arr2[j]) {
            lcs.push_back(arr1[i]);
            i++;
            j++;
        } else if(dp[i+1][j] > dp[i][j+1]) i++;
        else j++;
    }
    for(auto it: lcs) cout << it << " ";
    cout << endl;
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