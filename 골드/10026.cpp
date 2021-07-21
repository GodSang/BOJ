// 14:46 ~ 15:15
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <utility>

using namespace std;
#define X first
#define Y second
char board[101][101];
int vis[101][101];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
queue<pair<int,int>> q;
int bfs(int n) {
    int area=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(vis[i][j] != 0) continue;
            q.push({i,j});
            vis[i][j] = 1;
            while(!q.empty()) {
                pair<int,int> cur = q.front();
                q.pop();
                for(int dir=0;dir<4;dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx<0||nx>=n||ny<0||ny>=n) continue;
                    if(vis[nx][ny] != 0) continue;
                    if(board[cur.X][cur.Y] != board[nx][ny]) continue;
                    q.push({nx,ny});
                    vis[nx][ny] = 1;
                }
            }
            area++;
        }
    }
    return area;   
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string str;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> str;
        for(int j=0;j<n;j++) {
            board[i][j] = str[j];
        }
    }
    cout << bfs(n) << " ";
    for(int i=0;i<n;i++) {
        fill(vis[i], vis[i] + n, 0);
        for(int j=0;j<n;j++) {
            if(board[i][j] == 'G') board[i][j] = 'R';
        }
    }
    cout << bfs(n);

}