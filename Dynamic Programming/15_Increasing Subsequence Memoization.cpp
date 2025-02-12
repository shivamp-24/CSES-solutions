#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

int memo(int ind, int last, vector<vector<int>> &dp, vector<int> &arr, int n){
    if(ind == n) return 0;
    if(dp[ind][last] != -1) dp[ind][last];
    //pick
    int pick = 0;
    if(arr[ind] > arr[last]) pick = 1 + memo(ind + 1, ind, dp, arr, n);
    //skip
    int skip = memo(ind + 1, last, dp, arr, n);
    return dp[ind][last] = max(pick, skip);
}

void func() {
    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, -1));
    //dp[i][j] -> longest increasing subsequence till index i with last element at index j
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, 1 + memo(i+1, i, dp, arr, n));
    }
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