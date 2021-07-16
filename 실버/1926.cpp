//11:08 ~ 11:45
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define X first
#define Y second
int board[501][501];
bool vis[501][501];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int>> q;
    int n, m, k;
    int count=0, sum=0;;
    int max=0;
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> k;
            board[i][j] = k;
        }
    }       
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(vis[i][j] || board[i][j] != 1) continue;
            vis[i][j] = 1;
            q.push({i,j});
            while(!q.empty()) {
                pair<int,int> cur = q.front();
                q.pop();
                count++;
                for(int dir = 0; dir<4;dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                    if(vis[nx][ny] || board[nx][ny] != 1) continue;
                    vis[nx][ny] = 1;
                    q.push({nx,ny}); 
                }
            }
            max = count > max ? count : max;
            sum++;
            count = 0;
        }
    }
    cout << sum << "\n" << max;
    return 0;
}