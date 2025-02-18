#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func() {
    int n, x; cin >> n >> x;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    vector<int> dp((1 << n), n+1);
    //dp[mask] -> minimum number of rides for mask subset of people

    vector<vector<int>> subsets((1 << n)); //stores all subset mask for each mask values from (1 to (1 << n))
    //O(3^n) complexity total -> hence works only if n <= 15 else TLE. 
    //Here n <= 20. So we will optimize this later...
    for(int mask = 1; mask<(1 << n); mask++) {
        int s = mask;
        while(s > 0) {
            subsets[mask].push_back(s);
            s = (s - 1) & mask;
        }
    }
    
    vector<int> w((1 << n), 0); //stores sum of weights for mask elements chosen
    for(int mask = 1; mask<(1 << n); mask++) {
        for(int j=0; j<n; j++) {
            if((mask >> j) & 1) w[mask] += arr[j];
        }
    }

    //base case
    dp[0] = 0;

    //fill dp
    for(int mask=1; mask<(1 << n); mask++) {
        for(int s: subsets[mask]) {
            if(w[s] <= x) {
                dp[mask] = min(dp[mask], 1 + dp[mask ^ s]);
            }
        }
    }

    cout << dp[(1 << n) - 1] << endl;
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