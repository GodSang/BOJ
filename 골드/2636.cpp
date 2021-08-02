// 20:46 ~ 21:09
#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second
int board[101][101];
int vis[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int>> q;
    int n,m;
    int day=0;
    int ans=0;
    int sum=0;
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> board[i][j];
            ans += board[i][j];
        }
    }


    while(1) {
        q.push({0,0});
        vis[0][0] = 1;
        while(!q.empty()) {
            pair<int,int> cur = q.front();
            q.pop();
            for(int dir=0;dir<4;dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(vis[nx][ny] == 1) continue; 
                if(board[nx][ny] == 1) {
                    board[nx][ny] = 0;
                    vis[nx][ny] = 1;
                    continue;
                }
                q.push({nx,ny});
                vis[nx][ny] = 1;
            }
        }
        // cout << endl;
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<m;j++) {
        //         cout << board[i][j] << " ";
        //     }
        //     cout << endl;
        // }        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j] == 1)
                    sum++;
            }
        }
        day++;
        if(sum == 0) break;
        ans = sum;
        sum = 0;
        for(int i=0;i<n;i++) {
            fill(vis[i],vis[i]+m,0);
        }
    }
    cout << day << "\n" << ans;
}