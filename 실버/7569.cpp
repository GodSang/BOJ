//11:00
#include <iostream>
#include <tuple>
#include <queue>

using namespace std;
int board[101][101][101];
int dx[6]={1,0,-1,0,0,0};
int dy[6]={0,1,0,-1,0,0};
int dz[6]={0,0,0,0,1,-1};
int main() {
    int n,m,h,status,max=1;
    queue<tuple<int,int,int>> q;
    cin >> m >> n >> h;
    for(int k=0;k<h;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin >> status;
                board[i][j][k] = status;
                if(status == 1) {
                    q.push({i,j,k});
                }
            }
        }
    }
    while(!q.empty()) {
        tuple<int,int,int> cur = q.front();
        q.pop();
        for(int dir=0;dir<6;dir++) {
            int nx = get<0>(cur) + dx[dir];
            int ny = get<1>(cur) + dy[dir];
            int nz = get<2>(cur) + dz[dir];
            if(nx<0||ny<0||nz<0) continue;
            if(nx>=n||ny>=m||nz>=h) continue;
            if(board[nx][ny][nz] != 0) continue;
            q.push({nx,ny,nz});
            board[nx][ny][nz] = board[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
        }
    }
    for(int k=0;k<h;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j][k] == 0){
                    cout << -1;
                    return 0;
                }
                max = board[i][j][k] > max ? board[i][j][k] : max;
            }
        }
    }
    cout << max -1;
}
