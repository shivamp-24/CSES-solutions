#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define endl "\n"
#define int long long

void func(){
    int n, m; cin >> n >> m;
    vector<int> adjrev[n+1];
    vector<int> in(n+1, 0);
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        adjrev[v].push_back(u);
        in[u]++;
    }
    vector<int> dp(n+1, -1);
    //dp[i] -> max number of nodes on the path from i to n
    //dp[u] = 1 + dp[v] where v is child of u -> can only calculate dp[u] when dp[v] is already calculated
    //since dp[u] depends on child, hence we will make reverse adjaceny
    //so that childs are processed first and then parent in topological sort manner
    vector<int> next(n+1); //stores the next child node that current nodes chooses for maximum nodes in path
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(!in[i]) q.push(i);
    }
    //base case
    dp[n] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v: adjrev[u]){
            in[v]--;
            if(!in[v]) q.push(v);
            if(dp[u] != -1 && (dp[u] + 1) > dp[v]){
                dp[v] = dp[u] + 1;
                next[v] = u;
            }
        }
    }
    //final result in dp[1]
    if(dp[1] == -1){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    cout << dp[1] << endl;
    //print path using next array
    for(int u=1; ; u = next[u]){
        cout << u << " ";
        if(u == n) break;
    }
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