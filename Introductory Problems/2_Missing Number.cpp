#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func() {
    int n; cin >> n;
    int sum = 0;
    for(int i=0; i<n-1; i++){
        int x; cin >> x;
        sum += x;
    }
    int tot = (n * (n + 1)) / 2;
    cout << tot - sum << endl;
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