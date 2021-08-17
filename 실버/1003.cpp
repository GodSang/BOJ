// 17:09 ~ 17:32
#include <iostream>
using namespace std;
int arr[41][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    arr[0][0] = 1;
    arr[0][1] = 0;
    arr[1][0] = 0;
    arr[1][1] = 1;
    for(int i=2;i<41;i++) {
        arr[i][0] = arr[i-1][0] + arr[i-2][0];
        arr[i][1] = arr[i-1][1] + arr[i-2][1];        
    }
    while(t--) {
        int n;
        cin >> n;
        cout << arr[n][0] << " " << arr[n][1] << "\n";
    }

}