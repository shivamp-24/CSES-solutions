#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func(){
    int n; cin >> n;
    vector<int> arr(n);
    int sum = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    vector<vector<int>> dp(n, vector<int>(sum + 1));
    //dp[i][j] -> whether sum j is possible by using the array (0...i)
    //base case
    //dp[0][j]
    for(int j=0; j<=sum; j++){
        if(j == arr[0] || j == 0) dp[0][j] = 1;
        else dp[0][j] = 0;
    }
    //fill table
    for(int i=1; i<n; i++){
        for(int j=0; j<=sum; j++){
            //pick
            int pick = 0;
            if(arr[i] <= j) pick = dp[i-1][j - arr[i]];
            //skip
            int skip = dp[i-1][j];
            dp[i][j] = (pick | skip);
        }
    }
    vector<int> res;
    for(int j=1; j<=sum; j++){
        if(dp[n-1][j]) res.push_back(j);
    }
    cout << res.size() << endl;
    for(auto &it: res) cout << it << " ";
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