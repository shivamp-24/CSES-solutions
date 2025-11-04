#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func() {
    int n; cin >> n;
    int sum = (n * (n + 1)) / 2;
    if(sum & 1) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    int curr = sum / 2;
    vector<int> set1, set2;
    for(int i=n; i>=1; i--) {
        if(curr >= i) {
            set1.push_back(i);
            curr -= i;
        } else set2.push_back(i);
    }
    cout << set1.size() << endl;
    for(auto it: set1) cout << it << " ";
    cout << endl;

    cout << set2.size() << endl;
    for(auto it: set2) cout << it << " ";
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