// 10:22 ~ 10:47
#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
int board[31][31][31];
int dist[31][31][31];
int dx[6]={1,0,-1,0,0,0};
int dy[6]={0,1,0,-1,0,0};
int dz[6]={0,0,0,0,1,-1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,l;
    int ex,ey,ez;
    char c;
    while(1) {
        int isCorrect=0;
        queue<tuple<int,int,int>> q;
        cin >> l >> n >> m;
    
        if(n==0 && m==0 && l==0 ) break;
        for(int k=0;k<l;k++) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    cin >> c;
                    if(c=='S') {
                        q.push({i,j,k});
                        dist[i][j][k] = 1;
                    }else if(c=='E') {
                        ex = i;
                        ey = j;
                        ez = k;
                    }else if(c=='#') {
                        board[i][j][k] = -1;
                    }
                }
            }
        }
        while(!q.empty()) {
            tuple<int,int,int> cur = q.front();
            q.pop();
            if(get<0>(cur) == ex && get<1>(cur) == ey && get<2>(cur) == ez) {
                isCorrect = 1;
                break;
            }
            for(int dir=0;dir<6;dir++) {
                int nx = get<0>(cur) + dx[dir];
                int ny = get<1>(cur) + dy[dir];
                int nz = get<2>(cur) + dz[dir];
                if(nx<0||ny<0||nz<0||nx>=n||ny>=m||nz>=l) continue;
                if(dist[nx][ny][nz] != 0 || board[nx][ny][nz] == -1) continue;
                q.push({nx,ny,nz});
                dist[nx][ny][nz] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            }
        }
        if(isCorrect) {
            cout << "Escaped in " << dist[ex][ey][ez] - 1 << " minute(s).\n"; 
        } else {
            cout << "Trapped!\n";
        }
        // 사용한 배열 초기화
        for(int k=0;k<l;k++) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    board[i][j][k] = 0;
                    dist[i][j][k] = 0;
                }
            }
        }    
    }

}