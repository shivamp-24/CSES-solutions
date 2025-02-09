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
    vector<vector<int>> dp(n, vector<int>(n));
    //dp[i][j] -> maximum score possible in array (i...j)
    //second player will try minimising in remaining array by two options -> transition states

    //tabulation
    //base case -> since dp[i] depends on dp[i+1] and dp[i+2], hence calculate dp[n-1][j] and dp[n-2][j] first
    //dp[n-1]
    dp[n-1][n-1] = arr[n-1];
    //dp[n-2]
    if(n > 1){
        dp[n-2][n-2] = arr[n-2];
        dp[n-2][n-1] = max(arr[n-2], arr[n-1]);
    }
    //fill table
    for(int i=n-3; i>=0; i--){ //i from n because dp[i][j] depends on dp[i+1][j]
        for(int j=i; j<n; j++){ //j from 0 because dp[i][j] depends on dp[i][j-1]
            //pick left
            // int pick_left = arr[i] + min(dp[i+1][j-1], dp[i+2][j]);
            int tp1 = dp[i+2][j];
            if(j > 0) tp1 = min(tp1, dp[i+1][j-1]);
            int pick_left = arr[i] + tp1;
            //pick right
            // int pick_right = arr[j] + min(dp[i][j-2], dp[i+1][j-1]);
            int tp2 = 0;
            if(j > 1) tp2 = min(dp[i][j-2], dp[i+1][j-1]);
            else if(j > 0) tp2 = dp[i+1][j-1];
            int pick_right = arr[j] + tp2;

            dp[i][j] = max(pick_left, pick_right);
        }
    }
    cout << dp[0][n-1] << endl;
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