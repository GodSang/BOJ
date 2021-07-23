// 15:34 ~ 18:03
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <tuple>
#define X first
#define Y second
using namespace std;
int board[1001][1001];
int dist[1001][1001][2];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<tuple<int,int,int>> q;
    int n,m;
    int ans;
    string str;
    cin >> n >> m;
    for (int i=0;i<n;i++) {
        cin >> str;
        for (int j=0;j<m;j++) {
            board[i][j] = str[j] - '0';
        }
    }

    q.push({0,0,0});
    dist[0][0][0]=1;
    while(!q.empty()) {
        tuple<int,int,int> cur = q.front();
        q.pop();
        if(get<0>(cur) == n-1 && get<1>(cur) == m-1) {
            break;
        }
        for(int dir=0;dir<4;dir++) {
            int nx = get<0>(cur) + dx[dir];
            int ny = get<1>(cur) + dy[dir];
            int nz = get<2>(cur);
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(dist[nx][ny][nz] != 0) continue;
            if(board[nx][ny] == 1 && nz == 0) {
                q.push({nx,ny,1});
                dist[nx][ny][1] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
            }
            if(board[nx][ny] == 0) {
                dist[nx][ny][nz] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
                q.push({nx,ny,nz});
            }
        }
    }
    
    int a = dist[n-1][m-1][0];
    int b = dist[n-1][m-1][1];
    if(a==0 && b==0) {
        cout << -1;
        return 0;
    }
    if(a*b) ans = a > b ? b : a;
    else    ans = a > b ? a : b;
    cout << ans;
}