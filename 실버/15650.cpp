// 19:13 ~ 19:27
#include <iostream>
using namespace std;

int n,m;
int arr[9];
bool chk[9];

void func(int k) {
    if(k==m) {
        for(int i=0;i<m;i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=1;i<=n;i++) {
        if(chk[i] == 1) continue;
        if(k==0) {
            arr[k] = i;
        }else {
            if(i<arr[k-1]) continue;
        }
        arr[k] = i;
        chk[i] = 1;
        func(k+1);
        chk[i] = 0;
    }
}

int main() {
    cin >> n >> m;
    func(0);
}