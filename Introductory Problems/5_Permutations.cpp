#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func() {
    int n; cin >> n;
    if(n > 1 && n <= 3) {
        cout << "NO SOLUTION" << endl;
        return;
    }
    for(int i=2; i<=n; i+=2) cout << i << " ";
    for(int i=1; i<=n; i+=2) cout << i << " ";
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