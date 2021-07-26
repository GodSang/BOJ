// 15:07 ~ 18:38
#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#define X first
#define Y second
using namespace std;
vector<pair<int,int>> v[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int vis[101][101];
int light[101][101];
int near[101][101];

int main() {
    int n,m;
    int x,y,a,b;
    int cnt=0;
    queue<pair<int,int>> q;
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        cin >> x >> y >> a >> b;
        v[x][y].push_back({a,b});
    }
    q.push({1,1});
    light[1][1] = 1;
    vis[1][1] = 1;
    while(!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();
        for(auto e : v[cur.X][cur.Y]) {
            light[e.X][e.Y] = 1;
        }
        for(int dir=0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
            near[nx][ny] = 1;
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(vis[i][j] == 0 && light[i][j] == 1 && near[i][j] == 1) {
                    vis[i][j] = 1;
                    q.push({i,j});
                }
            }
        }
    }
    for(int i=1; i<=n;i++) {
        for(int j=1; j<=n; j++) {
            if(light[i][j] == 1)
                cnt++;
        }
    }
    cout << cnt;
}