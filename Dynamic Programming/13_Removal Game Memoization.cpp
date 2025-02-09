#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

int memo(int l, int r, vector<int> &arr, vector<vector<int>> &dp){
    if(l > r) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    //pick left
    int left_pick = arr[l] + min(memo(l + 1, r - 1, arr, dp), memo(l + 2, r, arr, dp));
    //pick right
    int right_pick = arr[r] + min(memo(l, r - 2, arr, dp), memo(l + 1, r - 1, arr, dp));
    return dp[l][r] = max(left_pick, right_pick);
}

void func(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, -1));
    //dp[i][j] -> maximum score possible in array (i...j)
    //second player will try minimising in remaining array by two options -> transition states
    cout << memo(0, n-1, arr, dp) << endl;
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