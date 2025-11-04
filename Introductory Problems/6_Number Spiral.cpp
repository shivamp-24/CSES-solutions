#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func() {
    int x, y; cin >> x >> y;
    int z = max(x, y);
    int prev = (z - 1) * (z - 1);

    if(z & 1) {
        //odd -> start from left
        if(x > y) cout << prev + y << endl;
        else cout << prev + y + y - x << endl;
    } else {
        //even -> start from top
        if(y > x) cout << prev + x << endl;
        else cout << prev + x + x - y << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while(t--){
        func();
    }
    return 0;
}