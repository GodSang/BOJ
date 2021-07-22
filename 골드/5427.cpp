// 16:16 ~ : 17:56
#include <iostream>
#include <queue>
#include <utility>
#include <string>

using namespace std;
#define X first
#define Y second
int board[1001][1001];
int dist1[1001][1001];
int dist2[1001][1001];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, t;
    char c;
    cin >> t;
    while(t--) {
        queue<pair<int,int>> q1;
        queue<pair<int,int>> q2;
        int exit=0;
        int ans;
        cin >> m >> n;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin >> c;
                if(c == '#') {
                    board[i][j] = -1;
                }
                else if(c == '*') {
                    q1.push({i,j});
                    dist1[i][j] = 1;
                }else if(c == '@') {
                    q2.push({i,j});
                    dist2[i][j] = 1;
                }
            }
        }
        while(!q1.empty()) {
            pair<int,int> cur = q1.front();
            q1.pop();
            for(int dir=0;dir<4;dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx<0||nx>=n||ny<0||ny>=m) continue;
                if(dist1[nx][ny] != 0 || board[nx][ny] == -1) continue;
                q1.push({nx,ny});
                dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            }
        }
        while(!q2.empty() && exit != 1) {
            pair<int,int> cur = q2.front();
            q2.pop();
            for(int dir=0;dir<4;dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx<0||nx>=n||ny<0||ny>=m) {
                    exit = 1;
                    ans = dist2[cur.X][cur.Y];
                    break;
                }
                if(dist2[nx][ny] != 0 || board[nx][ny] == -1) continue;
                if(dist1[nx][ny] != 0 && dist2[cur.X][cur.Y] + 1 >= dist1[nx][ny]) continue;
                dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
                q2.push({nx,ny});
                
            }
        }
        for(int i=0;i<n;i++) {
            fill(board[i],board[i] + m, 0);
            fill(dist1[i],dist1[i] + m, 0);
            fill(dist2[i],dist2[i] + m, 0);
        }
        if(exit) cout << ans << "\n";
        else    cout << "IMPOSSIBLE\n";
    }
}

