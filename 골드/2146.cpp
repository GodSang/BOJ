// 15:08 ~ 16:30
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

#define X first
#define Y second
int board[101][101];
int dist[101][101];
int vis[101][101];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

using namespace std;

void printTest(int n) {
    cout << endl;
    for(int a=0;a<n;a++) {
        for(int b=0;b<n;b++) {
            cout << dist[a][b] << " ";
        }
        cout << endl;
    } 
}

int main() {
    int n;
    queue<pair<int,int>> q;
    int min = 300;
    int island=2;
    int isZero=0;
    cin >> n;
    for(int i=0;i<n;i++) {  // 바다 육지 좌표 입력
        for(int j=0;j<n;j++) {
            cin >> board[i][j];
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            queue<pair<int,int>> q2;
            if(board[i][j] == 0 || vis[i][j] != 0) continue;
            q.push({i,j});
            vis[i][j] = 1;
            board[i][j] = island;
            while(!q.empty()) {
                pair<int,int> cur = q.front();
                q.pop();
                for(int dir=0;dir<4;dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
                    if(board[nx][ny] == 0){
                        isZero=1;
                        continue;
                    }
                    if(vis[nx][ny] != 0) continue;
                    q.push({nx,ny});
                    board[nx][ny] = island;
                    vis[nx][ny] = 1;
                }
                if(isZero) {    // 섬의 가장 바까의 좌표 저장
                    q2.push({cur.X, cur.Y});
                    dist[cur.X][cur.Y]=1;
                    isZero = 0;
                }
            }

            while(!q2.empty()) {
                pair<int,int> cur = q2.front();
                q2.pop();
                if(board[cur.X][cur.Y] != 0 && board[cur.X][cur.Y] != island) {
                    min = dist[cur.X][cur.Y] < min ? dist[cur.X][cur.Y] : min;
                    break;
                }
                for(int dir=0;dir<4;dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
                    if(((board[nx][ny] == board[cur.X][cur.Y]) && board[nx][ny] != 0) || dist[nx][ny] != 0) continue;
                    q2.push({nx,ny});
                    dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                }            
            }
            for(int k=0;k<n;k++)    // dist 초기화
                fill(dist[k], dist[k] + n, 0);
            island++;
        }
    }
    cout << min-2;
}
