#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func() {
    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    //we need to find the max number which divides >=2 elements in array
    //we can find divisors all numbers and increase the divisor count
    //then choose the max divisor with count >= 2

    //how to do this efficiently??

    int maxi = *max_element(arr.begin(), arr.end());
    vector<int> vis(maxi+1, 0);
    for(auto it: arr) vis[it]++;
    for(int i=maxi; i>=1; i--) {
        int cnt = 0;
        for(int j=i; j<=maxi; j+=i) {
            cnt += vis[j];
        }
        if(cnt >= 2) {
            cout << i << endl;
            return;
        }
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