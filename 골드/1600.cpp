// 19 : 49 ~ 21 : 48
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int board[201][201];
int dist[201][201][31];
int dx[12]={1,0,-1,0,-2,-2,-1,-1,1,1,2,2};
int dy[12]={0,1,0,-1,1,-1,2,-2,2,-2,1,-1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<tuple<int,int,int>> q;
    int n, m, k;
    int min=100000;
    cin >> k >> m >> n;
    int ex = n-1;
    int ey = m-1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> board[i][j];
        }
    }
    q.push({0,0,0});
    dist[0][0][0] = 1;
    while(!q.empty()) {
        int jumpFlag = 0;
        tuple<int,int,int> cur = q.front();
        q.pop();
        if(get<2>(cur) >= k) {
            jumpFlag=1;
        }
        for(int dir=0;dir<12;dir++) {
            int nx = get<0>(cur) + dx[dir];
            int ny = get<1>(cur) + dy[dir];
            int nz = get<2>(cur);
            if(dir>3) { // 말 움직임
                if(jumpFlag)
                    continue;
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(board[nx][ny] == 1 || dist[nx][ny][nz+1] != 0) continue;
                q.push({nx,ny,nz+1});
                dist[nx][ny][nz+1] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            }else { // 상하좌우
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(board[nx][ny] == 1 || dist[nx][ny][nz] != 0) continue;
                q.push({nx,ny,nz});
                dist[nx][ny][nz] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            }
        }
    }
    for(int i=0;i<=k;i++) {
        if(dist[n-1][m-1][i] == 0) continue;
        min = dist[n-1][m-1][i] < min ? dist[n-1][m-1][i] : min;
    }
    if(min == 100000)
        cout << -1;
    else
        cout << min - 1;
}