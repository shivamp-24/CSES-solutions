#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

const int maxn = 1e6;
int dp1[maxn + 1]; //number of towers which end with 1 width on last block
int dp2[maxn + 1]; //number of towers which end with 2 width on last block

void preProcess() {
    //base case
    dp1[1] = 1;
    dp2[1] = 1;
    for(int i=2; i<=maxn; i++){
        //1 widths
        dp1[i] = (dp2[i-1] + 4 * dp1[i-1]) % mod; //new 1-width block over 2 width block + 4-ways of extending or not extending 1-width block
        //2 widths
        dp2[i] = (dp1[i-1] + 2 * dp2[i-1]) % mod; //new 2 width block over 1 width blocks + 2-wasys of extending or not extending new 2-width blocks
    }
}

void func(){
    int n; cin >> n;
    cout << (dp1[n] + dp2[n]) % mod << endl;
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    preProcess();
    while(t--){
        func();
    }
    return 0;
}