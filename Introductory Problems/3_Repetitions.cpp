#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func() {
    string str; cin >> str;
    int n = str.size();
    int ans = 0;
    char last = str[0];
    int curr = 1;
    for(int i=1; i<n; i++){
        if(str[i] == last) {
            curr++;
        }
        else {
            ans = max(ans, curr);
            curr = 1;
            last = str[i];
        }
    }
    ans = max(ans, curr);
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