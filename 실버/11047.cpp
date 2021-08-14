// 23:07 ~ 23:13
#include <iostream>
using namespace std;
int coin[11];
int main() {
    int n, k;
    int ans = 0;
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        cin >> coin[i];
    }
    for(int i=n-1;i>=0;i--) {
        if(k / coin[i] == 0) continue;
        ans += k / coin[i];
        k %= coin[i];
    }
    cout << ans;
}