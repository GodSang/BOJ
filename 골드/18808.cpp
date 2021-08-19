// 생각 : 13:59 ~ 14:46 코딩 : 14:47 ~ 16:14
#include <iostream>
#include <utility>
using namespace std;
int note[41][41];
int s[11][11];
int n, m, r, c;

void rotate() {
    int tmpS[11][11];
    for(int i=0;i<c;i++) {
        for(int j=0;j<r;j++) {
            tmpS[i][j] = s[r-1-j][i];
        }
    }
    for(int i=0;i<c;i++) {
        for(int j=0;j<r;j++) {
            s[i][j] = tmpS[i][j];
        }
    }
    swap(r, c);
}

bool chk(int x, int y) {
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(s[i][j] == 1 && note[i + x][j + y] == 1)
                return false;
        }
    }
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(s[i][j] == 1)
                note[i + x][j + y] = 1;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> n >> m >> k;

    while(k--) {
        bool breakPoint = false;
        cin >> r >> c;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                cin >> s[i][j];
            }
        }
        for(int rot=0;rot<4;rot++) {
            for(int i=0;i<=n-r;i++) {
                if(breakPoint) break;
                for(int j=0;j<=m-c;j++) {
                    breakPoint = chk(i,j);
                    if(breakPoint) break;
                }
            }
            if(breakPoint) break;
            rotate();
        }
        for(int i=0;i<11;i++)
            fill(s[i],s[i]+11,0);
    }

    int ans=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            ans += note[i][j];
        }
    }
    cout << ans;
}