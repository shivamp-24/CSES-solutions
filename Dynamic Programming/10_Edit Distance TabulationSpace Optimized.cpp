#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func(){
    string str1, str2; cin >> str1 >> str2;
    int n = str1.size(), m = str2.size();
    //dp[i][j] -> minimum operations to transform str1[1...i] to str2[1...j]
    //space optimization
    vector<int> prev(m+1);
    //base case
    //from empty str1 to str2(1...j)
    for(int j=0; j<=m; j++) prev[j] = j;
    //tabulation
    for(int i=1; i<=n; i++){
        vector<int> curr(m+1, 0);
        curr[0] = i;
        for(int j=1; j<=m; j++){
            if(str1[i-1] == str2[j-1]){
                curr[j] = prev[j-1];
            }
            else{
                curr[j] = 1 + min({prev[j-1], prev[j], curr[j-1]});
            }
        }
        prev = curr;
    }
    cout << prev[m] << endl;
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