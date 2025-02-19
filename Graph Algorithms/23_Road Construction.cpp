#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

int findPar(int u, vector<int> &par) {
    if(par[u] == u) return u;
    return par[u] = findPar(par[u], par);
}

bool unionBySize(int u, int v, vector<int> &par, vector<int> &size, int &max_size) {
    int pu = findPar(u, par);
    int pv = findPar(v, par);

    if(pu == pv) return false;

    if(size[pu] > size[pv]) swap(pu, pv);
    size[pv] += size[pu];
    par[pu] = pv;
    max_size = max(max_size, size[pv]);
    return true;
}

void func() {
    int n, m; cin >> n >> m;

    //use union-find algorithm
    vector<int> par(n+1), size(n+1);
    for(int i=1; i<=n; i++) {
        par[i] = i;
        size[i] = 1;
    }
    int comp = n, max_size = 1;
    for(int i=0; i<m; i++) {
        int u, v; cin >> u >> v;

        //if u and v on different components, then components decrease after doing union of them
        if(unionBySize(u, v, par, size, max_size)) {
            comp--;
        }

        cout << comp << " " << max_size << endl;
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