// 17:26 ~ 18:13
#include <iostream>
#include <algorithm>
using namespace std;
int stairs[301];
int arr[301][2];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> stairs[i];
    }
    arr[0][1] = stairs[0];
    arr[1][2] = arr[0][1] + stairs[1];
    arr[1][1] = stairs[1];
    for(int i=2;i<n;i++) {
        arr[i][1] = max(arr[i-2][1], arr[i-2][2]) + stairs[i];
        arr[i][2] = arr[i-1][1] + stairs[i];
    }
    cout << max(arr[n-1][1], arr[n-1][2]);
}