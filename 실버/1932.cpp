//17:35 ~ 18:32
#include <iostream>
#include <algorithm>
using namespace std;
int tri[501][501];
int arr[501][501];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            cin >> tri[i][j];
        }
    }
    arr[1][1] = tri[1][1];
    for(int i=2;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            arr[i][j] = max(arr[i-1][j-1], arr[i-1][j]) + tri[i][j];
        }
    }
    int ans = -1;
    for(int j=1;j<=n;j++) {
        ans = max(ans, arr[n][j]);
    }
    cout << ans;
}