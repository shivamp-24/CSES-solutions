#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

int memo(int i, int j, int n, int m, string &str1, string &str2, vector<vector<int>> &dp){
    if(i == n){
        //if j < m -> then need to add in str1
        return (m - j);
    }
    if(j == m){
        //some characters in str1 left -> need to delete them all
        return (n - i);
    }
    if(dp[i][j] != -1) return dp[i][j];
    int ans = INT_MAX;
    if(str1[i] == str2[j]){
        //pick them
        ans = memo(i+1, j+1, n, m, str1, str2, dp);
    }
    else{
        //replace operation
        ans = 1 + memo(i+1, j+1, n, m, str1, str2, dp);
        //delete operation
        ans = min(ans, 1 + memo(i+1, j, n, m, str1, str2, dp));
        //add operation
        ans = min(ans, 1 + memo(i, j+1, n, m, str1, str2, dp));
    }
    return dp[i][j] = ans;
}

void func(){
    string str1, str2; cin >> str1 >> str2;
    int n = str1.size(), m = str2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    //dp[i][j] -> minimum operations to transform str1[0...i] to str2[0...j]
    cout << memo(0, 0, n, m, str1, str2, dp) << endl;
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