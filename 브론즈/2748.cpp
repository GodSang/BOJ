// 23:05 ~ 23:12
#include <iostream>
using namespace std;

typedef long long ll;

ll arr[91];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    arr[0] = 0;
    arr[1] = 1;
    for(int i=2;i<=n;i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    cout << arr[n];
}