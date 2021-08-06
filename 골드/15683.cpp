// 19:33
#include <iostream>

using namespace std;
int n,m;
int board[9][9];
void one(int x, int y, int flag) {
    if(flag == 1) {
        for(int curY=y+1;curY<=m;curY++) {
            if(board[x][curY] == 6) break;
            board[x][curY] = 1;
        }
    }
    else if(flag == 2) {
        for(int curX=x+1;curX<=n;curX++) {
            if(board[curX][y] == 6) break;
            board[curX][y] = 1;
        }
    }
    else if(flag == 3) {
        for(int curY=y-1;curY>=0;curY--) {
            if(board[x][curY] == 6) break;
            board[x][curY] = 1;
        }
    }
    else if(flag == 4) {
        for(int curX=x-1;curX>=0;curX--) {
            if(board[curX][y] == 6) break;
            board[curX][y] = 1;
        }
    }
    else {
        cout << "CCTV 1 ERROR \n";
    }
}
void two(int x, int y, int flag) {
    if(flag == 1) {
        for(int curX=)
    }
}
void three(int x, int y, int flag) {

}
void four(int x, int y, int flag) {

}
void five(iint x, int y, int flag) {

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
}