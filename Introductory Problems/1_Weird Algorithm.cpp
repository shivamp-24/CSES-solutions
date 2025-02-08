#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func(){
    int n; cin >> n;
    while(n != 1){
        cout << n << " ";
        if(n & 1) n = n * 3 + 1;
        else n /= 2;
    }
    cout << 1 << endl;
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