// 10:36 ~ 11:55
#include <iostream>
#include <utility>
using namespace std;
char board[2188][2188];   // 3^7 == 2187
void func(int x, int y, int n) {
    if(n == 1) {
        board[x][y] = '*';
        
    }
    else {
        int div = n/3;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(i==1 && j==1) continue;
                func(x + i*div, y + j*div, div);
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        fill(board[i], board[i]+n, ' ');

    func(0,0,n);

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
}