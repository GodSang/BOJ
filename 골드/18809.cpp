// 15:38 ~ 18:04
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
#define X first
#define Y second
int board[51][51];
int Rdist[51][51];
int Gdist[51][51];
int a[11];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n, m, r, g;
vector<pair<int,int>> v;



int BFS(queue<pair<int,int>> rQ, queue<pair<int,int>> gQ) {
    int cnt = 0;
    while(!rQ.empty() || !gQ.empty()) {
        int rsize = rQ.size();
        int gsize = gQ.size();
        // 붉은 배양액 BFS
        while(rsize--) {
            pair<int,int> cur = rQ.front();
            rQ.pop();
            if(Rdist[cur.X][cur.Y] != 0 && Gdist[cur.X][cur.Y] == Rdist[cur.X][cur.Y]) continue;
            for(int dir=0;dir<4;dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(Rdist[nx][ny] != 0 || board[nx][ny] == -1) continue;
                Rdist[nx][ny] = Rdist[cur.X][cur.Y] + 1;
                rQ.push({nx,ny});
            }
        }
        // 녹색 배양액 BFS
        while(gsize--) {
            pair<int,int> cur = gQ.front();
            gQ.pop();
            if(Gdist[cur.X][cur.Y] != 0 && Gdist[cur.X][cur.Y] == Rdist[cur.X][cur.Y]) {
                cnt++;
                continue;
            }
            for(int dir=0;dir<4;dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(Gdist[nx][ny] != 0 || board[nx][ny] == -1) continue;
                Gdist[nx][ny] = Gdist[cur.X][cur.Y] + 1;
                gQ.push({nx,ny});
            }
        }
    }
    return cnt;
}


int main() {
    int k;
    int res;
    int max = -1;
    cin >> n >> m >> g >> r;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> k;
            if(k == 0) {
                board[i][j] = -1;
            }
            else if(k == 2){
                v.push_back({i,j});
                board[i][j] = 0;
            }
            else {
                board[i][j] = 0;
            }

        }
    }
    fill(a, a+v.size(), 2);
    for(int i=0;i<g;i++) {
        a[i] = 0;
    }
    for(int i=g;i<r+g;i++) {
        a[i] = 1;
    }
    do {
        queue<pair<int,int>> rQ;
        queue<pair<int,int>> gQ;
        for(int i=0;i<v.size();i++) {
            auto cur = v[i];
            if(a[i] == 0) {
                Gdist[cur.X][cur.Y] = 1;
                gQ.push({cur.X, cur.Y});
            }
            else if(a[i] == 1){
                Rdist[cur.X][cur.Y] = 1;
                rQ.push({cur.X, cur.Y});
            }
        }
        res = BFS(rQ, gQ);
        max = res > max ? res : max;
        for(int i=0;i<n;i++) {
            fill(Rdist[i], Rdist[i] + m, 0);
            fill(Gdist[i], Gdist[i] + m, 0);
        }
    }while(next_permutation(a, a+v.size()));
    cout << max;
}