#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func() {
    int n; cin >> n;
    vector<vector<int>> arr(n);
    for(int i=0; i<n; i++) {
        int x, y, p; cin >> x >> y >> p;
        arr[i] = {x, y, p};
    }
    sort(arr.begin(), arr.end());
    vector<int> next(n);
    for(int i=0; i<n; i++) {
        //find the next non-overlapping slot for arr[i]
        int low = i + 1, high = n - 1, mid, ind = n;
        while(low <= high) {
            mid = (low + high) >> 1;
            if(arr[mid][0] > arr[i][1]) {
                ind = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        next[i] = ind;
    }
    vector<int> dp(n+1);
    dp[n] = 0;
    for(int ind=n-1; ind>=0; ind--) {
        //pick
        int pick = arr[ind][2] + dp[next[ind]];
        int skip = dp[ind+1];

        dp[ind] = max(pick, skip);
    }
    cout << dp[0] << endl;
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