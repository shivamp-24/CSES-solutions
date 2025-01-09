#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define endl "\n"
#define int long long

void printPath(int sx, int sy, int nx, int ny, vector<vector<pair<int, int>>>& par){
    cout << "YES" << endl;
    string path = "";
    while(nx != sx || ny != sy){
        int px = par[nx][ny].first;
        int py = par[nx][ny].second;
        if(px == nx){
            if(py < ny){
                path += 'R';
            }else{
                path += 'L';
            }
        }else{
            if(px < nx){
                path += 'D';
            }else{
                path += 'U';
            }
        }
        nx = px;
        ny = py;
    }
    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    cout << path << endl;
}

void func(){
    int n, m; cin >> n >> m;
    vector<vector<char>> str(n, vector<char>(m));
    queue<pair<int, pair<int, int>>> qm;
    vector<vector<int>> distm(n, vector<int>(m, 1e9));
    int sx, sy;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> str[i][j];
            if(str[i][j] == 'M'){
                qm.push({0, {i, j}});
                distm[i][j] = 0;
            }
            if(str[i][j] == 'A'){
                sx = i;
                sy = j;
            }
        }
    }
    if(sx == 0 || sx == n-1 || sy == 0 || sy == m-1){
        cout << "YES" << endl;
        cout << 0 << endl;
        return;
    }
    //first step is to find shortest distance of each cell from monsters
    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};
    while(!qm.empty()){
        auto it = qm.front();
        qm.pop();
        int cx = it.second.first;
        int cy = it.second.second;
        int cd = it.first;
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && str[nx][ny] != '#' && (cd + 1) < distm[nx][ny]){
                distm[nx][ny] = cd + 1;
                qm.push({cd + 1, {nx, ny}});
            }
        }
    }
    //now we need to find shortest distance of each cell from A and also the path if able to reach boundary at any point
    queue<pair<int, pair<int, int>>> qa;
    vector<vector<int>> dista(n, vector<int>(m, 1e9));
    vector<vector<pair<int, int>> > par(n, vector<pair<int, int>>(m, {-1, -1}));
    qa.push({0, {sx, sy}});
    dista[sx][sy] = 0;
    while(!qa.empty()){
        auto it = qa.front();
        qa.pop();
        int cx = it.second.first;
        int cy = it.second.second;
        int cd = it.first;
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && str[nx][ny] != '#' && (cd + 1) < min(distm[nx][ny], dista[nx][ny])){
                par[nx][ny] = {cx, cy};
                if(nx == 0 || nx == n-1 || ny == 0 || ny == m-1){
                    printPath(sx, sy, nx, ny, par);
                    return;
                }
                dista[nx][ny] = cd + 1;
                qa.push({cd + 1, {nx, ny}});
            }
        }
    }
    cout << "NO" << endl;
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