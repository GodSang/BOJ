// 17:52
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int board[1001][1001];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
long long s[10];
int ans[10];
queue<tuple<int,int,int>> q[10];
int n,m;

void bfs(int player) {
    queue<tuple<int,int,int>> tmpQ;
    while(!q[player].empty()) {
        tuple<int,int,int> cur = q[player].front();
        q[player].pop();
        if(get<2>(cur) >= s[player]) {
            tmpQ.push({get<0>(cur), get<1>(cur), 0});
            continue;
        }
        for(int dir=0;dir<4;dir++){
            int nx = get<0>(cur) + dx[dir];
            int ny = get<1>(cur) + dy[dir];
            int lim = get<2>(cur);
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] != 0) continue;
            board[nx][ny] = player;
            q[player].push({nx,ny,lim+1});
        }
    }
    q[player] = tmpQ;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int p;
    char c;

    cin >> n >> m >> p;
    for(int i=1;i<=p;i++) {
        cin >> s[i];
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> c;
            if(c == '.') {
                board[i][j] = 0;
            }else if(c == '#') {
                board[i][j] = -1;
            }else {
                board[i][j] = c - '0';
                q[c-'0'].push({i,j,0});
            }
        }
    }
 
    while(1) {
        int sum1=0, sum2=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                sum1 += board[i][j];
            }
        }
        for(int i=1;i<=p;i++) {
            bfs(i);
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                sum2 += board[i][j];
            }
        }
        if(sum1 == sum2) break;
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(board[i][j] == -1 || board[i][j] == 0) continue;
            ans[board[i][j]]++;
        }
    }
    for(int i=1;i<=p;i++) {
        cout << ans[i] << " ";
    }
}