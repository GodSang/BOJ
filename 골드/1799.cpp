// 14:40 ~ 16:00
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n;
int ans = -1;
int board[2][11][11];
int chkL[21];   // 왼쪽 대각선
int chkR[21];   // 오른쪽 대각선

void func(int x, int y,int cnt, int flag) {
    if( y >= n ) {
        x++;
        y=0;
    }
    if(x >= n) {
        ans = cnt > ans ? cnt : ans;
        return;
    }

    if(board[flag][x][y] && !chkR[x-y+n-1] && !chkL[x+y]){
        chkR[x-y+n-1] = 1;
        chkL[x+y] = 1;
        func(x, y + 1,cnt + 1, flag);
        chkR[x-y+n-1] = 0;
        chkL[x+y] = 0;    
    }
    func(x, y + 1,cnt, flag);
}

int main() {
    int res=0;
    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if((i%2 == 0 && j%2 == 0) || (i%2 == 1 && j%2 == 1)) {  // 흰색 발판
                cin >> board[0][i][j];
            }  
            else    // 검은색 발판
                cin >> board[1][i][j];
        }
    }

    func(0, 0, 0, 0);  // 흰색
    res = ans;
    ans = -1;
    fill(chkL, chkL+21, 0);
    fill(chkR, chkR+21, 0);
    
    func(0, 0, 0, 1);  // 검은색
    res += ans;
    cout << res;
}