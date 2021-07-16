// 15:07 ~ 15:39
#include <iostream>
#include <queue>
#include <utility>

using namespace std;
#define X first
#define Y second
int board[1001][1001];
bool vis[1001][1001];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int>> q;
    int n, m, k;
    int max=0;
    cin >> m >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> k;
            board[i][j] = k;
            if(k == 1) {
                q.push({i,j});
                vis[i][j] = 1;
            }
        }
    }
    while(!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();
        for(int dir=0;dir<4;dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] || board[nx][ny] != 0) continue;
            vis[nx][ny] = 1;
            q.push({nx,ny});
            board[nx][ny] = board[cur.X][cur.Y] + 1;
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(board[i][j] == 0) {
                cout << -1;
                return 0;
            }
            max = board[i][j] > max ? board[i][j] : max;
        }
    }
    cout << max - 1;
    return 0;
}
