//10:15 ~ 11:30
#include <iostream>
#include <queue>
#include <utility>
#define X first
#define Y second
using namespace std;
int board[301][301];
int vis[301][301];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int>> q;
    int n,m,k;
    int flag=0;
    int sum=0;
    int year=0;
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> k;
            board[i][j] = k;
        }
    }
    while(1) {
        year++;
        flag = 0;
        for(int i=1;i<n-1;i++) {
            for(int j=1;j<m-1;j++) {
                if(vis[i][j] == 1 || board[i][j] == 0) continue;
                q.push({i,j});
                vis[i][j] = 1;
                while(!q.empty()) {
                    pair<int,int> cur = q.front();
                    q.pop();
                    for(int dir=0;dir<4;dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(vis[nx][ny] == 1) continue;
                        if(board[nx][ny] == 0) {
                            if(board[cur.X][cur.Y] != 0) {
                                board[cur.X][cur.Y] -= 1;
                            }
                            continue;
                        }
                        q.push({nx,ny});
                        vis[nx][ny] = 1;    
                    }
                }
                flag++;
            }
        }
        if(flag >= 2) break;

        for(int i=0;i<n;i++)
            fill(vis[i], vis[i]+m,0);
        for(int i=1;i<n-1;i++) {
            for(int j=1;j<m-1;j++) {
                sum += board[i][j];
            }
        }
        if(sum == 0) {
            cout << 0;
            return 0;
        }
        sum = 0;
    }
    cout << year-1;
}