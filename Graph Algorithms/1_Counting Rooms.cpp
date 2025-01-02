#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define endl "\n"
#define int long long

int dx[]={-1, 0, 0, 1};
int dy[]={0, -1, 1, 0};

void dfs(int x, int y, vector<vector<char>> &str, vector<vector<int>> &vis, int n, int m){
    vis[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] && str[nx][ny] == '.'){
            dfs(nx, ny, str, vis, n, m);
        }
    }
}

void func(){
    int n, m; cin >> n >> m;
    vector<vector<char>> str(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> str[i][j];
        }
    }
    int ans = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        for(int  j = 0; j < m; j++){
            if(!vis[i][j] && str[i][j] == '.'){
                ans++;
                dfs(i, j, str, vis, n, m);
            }
        }
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t=1;
    // cin>>t;
    while(t--){
        func();
    }
    return 0;
}