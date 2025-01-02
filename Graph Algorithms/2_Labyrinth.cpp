#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define endl "\n"
#define int long long

void findPath(int nx, int ny, int sx, int sy, vector<vector<pair<int, int>>> &path){
    string res;
    int fx = nx, fy = ny;
    while(fx != sx || fy != sy){
        int ix = path[fx][fy].first, iy = path[fx][fy].second;
        if(fx == (ix + 1)) res.push_back('D');
        else if(fx == (ix - 1)) res.push_back('U');
        else if(fy == (iy + 1)) res.push_back('R');
        else res.push_back('L');
        fx = ix;
        fy = iy;
    }
    reverse(res.begin(), res.end());
    cout << res.size() << endl;
    cout << res <<endl;
}

void func(){
    int n, m; cin >> n >> m;
    vector<vector<char>> str(n, vector<char>(m));
    int sx, sy;
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < m; j++){
            cin >> str[i][j];
            if(str[i][j] == 'A'){
                sx = i;
                sy = j;
            }
        }
    }
    queue<pair<int, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    q.push({sx, sy});
    vis[sx][sy] = 1;
    vector<vector<pair<int, int>>> path(n, vector<pair<int, int>>(m));
    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int cx = it.first;
        int cy = it.second;
        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] && str[nx][ny] != '#'){
                path[nx][ny] = {cx, cy};
                if(str[nx][ny] == 'B') {
                    cout << "YES" << endl;
                    findPath(nx, ny, sx, sy, path);
                    return;
                }
                q.push({nx, ny});
                vis[nx][ny] = 1;
            }
        }
    }
    cout << "NO" << endl;
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