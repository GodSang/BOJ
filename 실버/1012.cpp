// 10:07~10:47
#include <iostream>
#include <queue>
#include <utility>

using namespace std;
#define X first
#define Y second
int board[51][51];
int vis[51][51];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main() {
    queue<pair<int,int>> q;
    int t,n,m,k;
    int tx, ty;
    int cnt=0;
    cin >> t;
    while(t--) {
        cin >> m >> n >> k; // n: 행, m: 열
        for(int i=0;i<n;i++) {
            fill(board[i], board[i]+m, 0);
            fill(vis[i], vis[i]+m, 0);
        }
        for(int i=0;i<k;i++){
            cin >> ty >> tx;
            board[tx][ty] = 1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 1 && vis[i][j] == 0){
                    q.push({i,j});
                    vis[i][j] = 1;
                    while(!q.empty()) {
                        pair<int,int> cur = q.front();
                        q.pop();
                        for(int dir=0;dir<4;dir++) {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                            if(vis[nx][ny] == 1 || board[nx][ny] == 0) continue;
                            q.push({nx,ny});
                            vis[nx][ny] = 1;
                        }
                    }
                    cnt++;  
                }
            }
        }
    cout << cnt << "\n";
    cnt = 0;    
    }
}