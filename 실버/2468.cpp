// 20:44 ! 21:24
#include <iostream>
#include <queue>
#include <utility>
#define X first
#define Y second
using namespace std;
int board[101][101][101];
int vis[101][101][101];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int>> q;
    int n,h;
    int hMax = -1;
    int ans = -1;
    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> h;
            hMax = h > hMax ? h : hMax;
            for(int k=0;k<h;k++) {
                board[i][j][k] = 1;
            }
        }
    }
    for(int k=0;k < hMax ; k++) {
        int cnt=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j][k] == 0 || vis[i][j][k] == 1) continue;
                q.push({i,j});
                vis[i][j][k] = 1;
                while(!q.empty()) {
                    pair<int,int> cur = q.front();
                    q.pop();
                    for(int dir=0;dir<4;dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx<0 || nx >= n || ny<0 || ny >= n) continue;
                        if(board[nx][ny][k]==0 || vis[nx][ny][k] != 0) continue;
                        q.push({nx,ny});
                        vis[nx][ny][k] = 1;
                    }
                }
                cnt++;
            }
        }
        ans = cnt > ans ? cnt : ans;
    }
    cout << ans;
}