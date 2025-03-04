#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

int power(int x, int y) {
    int ans = 1;
    while(y) {
        if(y & 1) {
            ans = (ans * x) % mod;
        }
        x = (x * x) % mod;
        y = y >> 1;
    }
    return ans;
}

void func() {
    int n; cin >> n;
    while(n--) {
        int a, b; cin >> a >> b;
        cout << power(a, b) << endl;
    }
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