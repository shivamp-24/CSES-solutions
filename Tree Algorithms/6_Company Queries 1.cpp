#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

int findKthParent(int node, int k, vector<vector<int>> &parents, int maxi){
    for(int i=0; i<maxi; i++){
        if((k >> i) & 1){
            node = parents[i][node];
            if(node == -1) return node;
        }
    }
    return node;
}

void func(){
    int n, q; cin >> n >> q;
    //binary lifting approach
    //finding k-th parent in log(k) time
    //logic : 2^(i-th) parent of u = 2^((i-1)-th) parent of (2^((i-1)-th) parent of u)
    //base case -> find 2^(0-th) parent of each node using dfs
    int maxi = log2(n) + 1; //maxi is msb of n, beacuse maximum 2^maxi-th parent will exist
    vector<vector<int>> parents(maxi, vector<int>(n+1, -1));
    for(int i=2; i<=n; i++){
        int p; cin >> p;
        //base case -> 2^0-th parent
        parents[0][i] = p;
    }
    //now populate parents array
    for(int i=1; i<maxi; i++){
        for(int node=1; node<=n; node++){
            int intermediate = parents[i-1][node];
            if(intermediate != -1){
                parents[i][node] = parents[i-1][intermediate];
            }
        }
    }
    while(q--){
        int node, k; cin >> node >> k;
        int res = findKthParent(node, k, parents, maxi);
        cout << res << endl;
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