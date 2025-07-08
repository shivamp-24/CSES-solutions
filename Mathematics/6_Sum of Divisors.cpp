#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func() {
    int n; cin >> n;
    int sum = 0;
    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n; j+=i) {
            sum += i;
            sum %= mod;
        }
    }
    cout << sum << endl;
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