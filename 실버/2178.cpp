//14:10 ~ 14:58
#include <iostream>
#include <queue>
#include <utility>
#include <string>

using namespace std;
#define X first
#define Y second
int board[101][101];
bool vis[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main() {
    int dist=1;
    queue<pair<int,int>> q;
    string line;
    int n,m;
    int nx,ny;
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> line;
        for(int j=0; j<m;j++) {
            board[i][j] = line[j]-'0';
        }
    }
    vis[0][0] = 1;
    board[0][0] = 1;
    q.push({0,0});
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for(int dir=0;dir<4;dir++) {
            nx = cur.X + dx[dir];
            ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] || board[nx][ny] != 1) continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
            board[nx][ny] = board[cur.X][cur.Y]+1;
        }
        if(nx == n-1 && ny == m-1) break;
    }
    cout << board[n-1][m-1];
    return 0;
}