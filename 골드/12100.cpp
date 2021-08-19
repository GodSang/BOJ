// 16:55 ~ 19:15
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
int n;
int board[21][21];
int tmpBoard[21][21];
int ansBoard[21][21];
int ans = -1;
int arr[5];

void top() {
    for(int y=0;y<n;y++) {
        int cur=0;
        int arr[21] = {0, };
        bool chk[21];
        fill(chk, chk+21, 1);
        for(int x=0;x<n;x++) {
            if(tmpBoard[x][y] == 0) continue;
            if(cur != 0 && tmpBoard[x][y] == arr[cur-1] && chk[cur-1]) {
                arr[cur-1] *= 2;
                chk[cur-1] = 0;
                continue;
            }
            arr[cur] = tmpBoard[x][y];
            cur++;
        }
        for(int i=0;i<n;i++) {
            tmpBoard[i][y] = arr[i];
        }
    }
}

void bottom() {
    for(int y=0;y<n;y++) {
        int cur=0;
        int arr[21] = {0, };
        bool chk[21];
        fill(chk, chk+21, 1);
        for(int x=n-1;x>=0;x--) {
            if(tmpBoard[x][y] == 0) continue;
            if(cur != 0 && tmpBoard[x][y] == arr[cur-1] && chk[cur-1]) {
                arr[cur-1] *= 2;
                chk[cur-1] = 0;
                continue;
            }
            arr[cur] = tmpBoard[x][y];
            cur++;
        }
        for(int i=0;i<n;i++) {
            tmpBoard[n-1-i][y] = arr[i];
        }
    }
}

void left() {
     for(int x=0;x<n;x++) {
        int cur=0;
        int arr[21] = {0, };
        bool chk[21];
        fill(chk, chk+21, 1);
        for(int y=0;y<n;y++) {
            if(tmpBoard[x][y] == 0) continue;
            if(cur != 0 && tmpBoard[x][y] == arr[cur-1] && chk[cur-1]) {
                arr[cur-1] *= 2;
                chk[cur-1] = 0;
                continue;
            }
            arr[cur] = tmpBoard[x][y];
            cur++;
        }
        for(int i=0;i<n;i++) {
            tmpBoard[x][i] = arr[i];
        }
    }
}

void right() {
        for(int x=0;x<n;x++) {
        int cur=0;
        int arr[21] = {0, };
        bool chk[21];
        fill(chk, chk+21, 1);
        for(int y=n-1;y>=0;y--) {
            if(tmpBoard[x][y] == 0) continue;
            if(cur != 0 && tmpBoard[x][y] == arr[cur-1] && chk[cur-1]) {
                arr[cur-1] *= 2;
                chk[cur-1] = 0;
                continue;
            }
            arr[cur] = tmpBoard[x][y];
            cur++;
        }
        for(int i=0;i<n;i++) {
            tmpBoard[x][n-1-i] = arr[i];
        }
    }
}

void blockGame() {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++){
            tmpBoard[i][j] = board[i][j];
        }    
    }
    for(int i=0;i<5;i++) {
        switch(arr[i])
        {
            case 0:
                top();
                break;
            case 1:
                bottom();
                break;
            case 2:
                left();
                break;
            case 3:
                right();
                break;
        }
    }
}

void func(int index) {
    if(index == 5) {
        blockGame();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                ans = max(ans, tmpBoard[i][j]);
            }
        }
        return;
    }
    for(int i=0;i<4;i++) {
        arr[index] = i;
        func(index+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> board[i][j];
        }
    }
    func(0);
    cout << ans;
}