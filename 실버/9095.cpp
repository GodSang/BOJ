// 15:43 ~ 15:52
#include <iostream>
using namespace std;
int arr[12] = {0,1,2,4,0,0,0,0,0,0,0,0};

int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        if(n<=3) {
            cout << arr[n] << "\n";
            continue;
        }
        for(int i=4;i<=n;i++) {
            arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
        }
        cout << arr[n] << "\n";
    }
}