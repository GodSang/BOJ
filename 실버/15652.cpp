// 19:43 ~ 19:49
#include <iostream>
using namespace std;

int n,m;
int arr[9];

void func(int cur){
    if(cur==m) {
        for(int i=0;i<m;i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=1;i<=n;i++) {
        if(cur==0) {
            arr[cur] = i;
        }
        else {
            if(i < arr[cur-1]) continue;
            arr[cur] = i;
        }
        func(cur+1);
    }
}

int main() {
    cin >> n >> m;
    func(0);
}