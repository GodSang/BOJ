// 17:18 ~ 19:29
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define X first
#define Y second
int n,m;
int board[9][9];
int tmpBoard[9][9];
int arr[5] = {0,0,0,0,1};
int ans = 81;
vector<pair<int,int>> v;
vector<pair<int,int>> cctv;
void watchLeft(int x, int y) {
    for(int curY=y-1;curY>=0;curY--) {
        if(tmpBoard[x][curY] == 6) break;
        else if(tmpBoard[x][curY] == 0)
            tmpBoard[x][curY] = 1;
        else continue;
    }
}
void watchRight(int x, int y) {
    for(int curY=y+1;curY<=m;curY++) {
        if(tmpBoard[x][curY] == 6) break;
        else if(tmpBoard[x][curY] == 0)
            tmpBoard[x][curY] = 1;
        else continue;
    }    
}
void watchTop(int x, int y) {
    for(int curX=x-1;curX>=0;curX--) {
        if(tmpBoard[curX][y] == 6) break;
        else if(tmpBoard[curX][y] == 0)
            tmpBoard[curX][y] = 1;
        else continue;
    }    
}
void watchBottom(int x, int y) {
    for(int curX=x+1;curX<=n;curX++) {
        if(tmpBoard[curX][y] == 6) break;
        else if(tmpBoard[curX][y] == 0)
            tmpBoard[curX][y] = 1;
        else continue;
    }    
}
void one(int x, int y, int flag) {
    if(flag == 1) {
        watchTop(x,y);
    }
    else if(flag == 2) {
        watchBottom(x,y);
    }
    else if(flag == 3) {
        watchLeft(x,y);
    }
    else if(flag == 4) {
        watchRight(x,y);
    }
    else {
        cout << "CCTV 1 ERROR \n";
    }
}
void two(int x, int y, int flag) {
    if(flag == 1) {
        watchLeft(x,y);
        watchRight(x,y);
    }
    else if(flag == 2) {
        watchTop(x,y);
        watchBottom(x,y);
    }
    else {
        cout << "CCTV 2 ERROR \n";
    }
}
void three(int x, int y, int flag) {
    if(flag == 1) {
        watchTop(x,y);
        watchRight(x,y);
    }
    else if(flag == 2) {
        watchRight(x,y);
        watchBottom(x,y);
    }
    else if(flag == 3) {
        watchBottom(x,y);
        watchLeft(x,y);
    }
    else if(flag == 4) {
        watchTop(x,y);
        watchLeft(x,y);
    }
    else {
        cout << "CCTV 3 ERROR \n";
    }
}
void four(int x, int y, int flag) {
    if(flag == 1) {
        watchLeft(x,y);
        watchTop(x,y);
        watchRight(x,y);
    }
    else if(flag == 2) {
        watchTop(x,y);
        watchRight(x,y);
        watchBottom(x,y);
    }
    else if(flag == 3) {
        watchRight(x,y);
        watchBottom(x,y);
        watchLeft(x,y);
    }
    else if(flag == 4) {
        watchBottom(x,y);
        watchLeft(x,y);
        watchTop(x,y);
    }
    else {
        cout << "CCTV 4 ERROR \n";
    }
}
void five(int x, int y, int flag) {
    if(flag == 1) {
        watchTop(x,y);
        watchRight(x,y);
        watchBottom(x,y);
        watchLeft(x,y);
    }
    else {
        cout << "CCTV 5 ERROR \n";
    }
}

void copyArr() {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            tmpBoard[i][j] = board[i][j];
        }
    }
}

void func(int cur) {
    if(cur == v.size()) {
        // cctv 탐색
        copyArr();
        int num=0;
        for(auto e : v) {
            if(cctv[num].X == 1)  {
                one(e.X, e.Y, cctv[num].Y);
            }
            else if(cctv[num].X == 2) {
                two(e.X, e.Y, cctv[num].Y);
            }
            else if(cctv[num].X == 3) {
                three(e.X, e.Y, cctv[num].Y);
            }
            else if(cctv[num].X == 4) {
                four(e.X, e.Y, cctv[num].Y);
            }
            else if(cctv[num].X == 5) {
                five(e.X, e.Y, cctv[num].Y);
            }
            num++;
        }
        int cnt = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(tmpBoard[i][j] == 0) cnt++;
            }
        }
        ans = cnt < ans ? cnt : ans;
        return;
    }
    for(int i=1;i<=4;i++) {
        if(cctv[cur].X == 2) {
            if(i>2) {
                return;
            }
        }
        else if(cctv[cur].X == 5) {
            if(i>1) {
                return;
            }
        }
        cctv[cur].second = i;
        func(cur+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> board[i][j];
            if(board[i][j] != 0 && board[i][j] != 6) {
                v.push_back({i,j});
                cctv.push_back({board[i][j], 0});
            }
        }
    }
    func(0);
    cout << ans;
}