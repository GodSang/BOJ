// 16:08 ~ 20:01
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
#define X first
#define Y second
char board[5][5];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int a[25];
int vis[5][5];
int chkSelect[5][5];
vector<pair<int,int>> v;

bool func() {
    int cntS=0;
    int cnt=0;
    queue<pair<int,int>> q;
    // 다솜파 4명 이상인지 체크
    for(int i=0;i<v.size();i++) {
        pair<int,int> cur = v[i];
        if(board[cur.X][cur.Y] == 'S') cntS++;
    }
    if(cntS < 4) return false;

    q.push({v[0].X, v[0].Y});
    vis[v[0].X][v[0].Y] = 1;
    while(!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();
        cnt++;
        for(int dir=0;dir<4;dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
            if(vis[nx][ny] || !chkSelect[nx][ny]) continue;
            q.push({nx,ny});
            vis[nx][ny] = 1;
        }
    }
    if(cnt == 7) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans=0;
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            cin >> board[i][j];
        }
    }
    fill(a, a+25, 1);
    for(int i=0;i<7;i++) {  // 25개 중에 7개를 뽑는 조합
        a[i] = 0;
    }
    do {
        int index=0;
        for(int i=0;i<25;i++) {
            if(a[i] == 0) {
                v.push_back({i/5, i%5});
                chkSelect[i/5][i%5] = 1;
            }
        }
        if(func()) 
            ans++;
        for(int i=0;i<5;i++) {
            fill(chkSelect[i], chkSelect[i] + 5, 0);
            fill(vis[i], vis[i]+5, 0);
        }
        while(!v.empty()) {
            v.pop_back();
        }
    }while(next_permutation(a, a+25));

    cout << ans;

}