#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

int findKthParent(int x, int k, vector<vector<int>> &parents, int maxi){
    for(int i=0; i<=maxi; i++){
        if((k >> i) & 1){
            x = parents[i][x];
            if(x == -1) return x;
        }
    }
    return x;
}

void func() {
    int n, q; cin >> n >> q;
    //use binary lifting approach similar to trees
    //maxi is log2(1e9) = 30 as k can be upto 1e9
    int maxi = 30;
    vector<vector<int>> parents(maxi + 1, vector<int>(n+1, -1));
    for(int i=1; i<=n; i++){
        int x; cin >> x;
        parents[0][i] = x;
    }

    //fill parent array
    for(int i=1; i<=maxi; i++){
        for(int node=1; node<=n; node++){
            int intermediate = parents[i-1][node];
            if(intermediate != -1){
                parents[i][node] = parents[i-1][intermediate];
            }
        }
    }

    //process queries
    while(q--){
        int x, k; cin >> x >> k;
        cout << findKthParent(x, k, parents, maxi) << endl;
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