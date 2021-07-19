//10:47~12:13
#include <iostream>
#include <queue>
#include <utility>

using namespace std;
#define X first
#define Y second
char board[1001][1001];
int dist1[1001][1001];
int dist2[1001][1001];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    int nx, ny;
    char k;
    queue<pair<int,int>> q1;
    queue<pair<int,int>> q2;
    pair<int,int> cur;
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        fill(dist1[i], dist1[i]+m, -1);
        fill(dist2[i], dist2[i]+m, -1);
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> k;
            board[i][j] = k;
            if(k=='F') {
                dist1[i][j] = 0;
                q1.push({i,j});
            }
            if(k=='J') {
                dist2[i][j] = 0;
                q2.push({i,j});
            }
        }
    }
    while(!q1.empty()) {    // 불 BFS
        cur = q1.front();
        q1.pop();
        for(int dir=0;dir<4;dir++){
            nx = cur.X + dx[dir];
            ny = cur.Y + dy[dir];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(dist1[nx][ny] != -1 || board[nx][ny] == '#') continue;
            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            q1.push({nx,ny});
        }
    }
    while(!q2.empty()) {    // 지훈 BFS
        cur = q2.front();
        q2.pop();
        for(int dir=0;dir<4;dir++) {
            nx = cur.X + dx[dir];
            ny = cur.Y + dy[dir];    
            if(nx<0 || nx>=n || ny<0 || ny>=m) {  // 탈출 조건
                cout << dist2[cur.X][cur.Y] + 1;
                return 0;
            }
            if(dist2[nx][ny] != -1 || board[nx][ny] == '#') continue;
            if(dist2[cur.X][cur.Y] + 1 >= dist1[nx][ny] && dist1[nx][ny] != -1) continue;
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            q2.push({nx,ny});
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
