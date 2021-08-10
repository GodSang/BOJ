// 15:13 ~ 15:36
#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=2;i<=n;i++) {
        arr[i] = arr[i-1] + 1;
        if(i%3 == 0) {
            arr[i] = min(arr[i], arr[i/3] + 1);
        }
        if(i%2 == 0) {
            arr[i] = min(arr[i], arr[i/2] + 1);
        }
    }
    cout << arr[n];
}