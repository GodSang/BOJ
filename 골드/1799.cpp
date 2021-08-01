// 17:02
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n;
int board[2][11][11];

void func(int x, int y, int cnt, int flag) {
    
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if((i%2 == 0 && j%2 == 0) || (i%2 == 1 && j%2 == 1)) {
                cin >> board[0][i][j];
            }
            else
                cin >> board[1][i][j];
        }
    }
    func(0, 0, 0, 0);
}