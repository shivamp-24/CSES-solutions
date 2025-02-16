#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func() {
    int n; cin >> n;
    map<int, vector<pair<int,int>>> mp;
    set<int> endDays;
    for(int i=0; i<n; i++){
        int a, b, p; cin >> a >> b >> p;
        mp[b].push_back({a, p});
    }
    map<int, int> dp;
    //dp[x] -> maximum reward when last ending day was x
    //base case
    auto it = mp.begin();
    for(auto [start, price]: it->second){
        dp[it->first] = max(dp[it->first], price);
    }
    endDays.insert(it->first);
    it++;
    //fill dp
    while(it != mp.end()){
        int currEnd = it->first;
        //pick
        int pick = 0;
        for(auto [start, price]: it->second){
            auto it1 = endDays.lower_bound(start);
            if(it1 == endDays.begin()){ //no end exists before start
                pick = max(pick, price);
            }
            else{ //end exists before start
                it1--;
                pick = max(pick, price + dp[(*it1)]);
            }
        }
        //skip
        int skip = dp[*(--endDays.end())];
        dp[currEnd] = max(pick, skip);

        endDays.insert(currEnd);
        it++;
    }
    //answer will be max in dp
    int ans = 0;
    for(auto x: dp){
        ans = max(ans, x.second);
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