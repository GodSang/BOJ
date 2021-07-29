// 14:10 ~ 14:20
#include <iostream>
using namespace std;

int n,m;
int arr[10];
bool choice[10];

void pick(int k) {
    if(k==m) {
        for(int i=0;i<m;i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=1;i<=n;i++) {
        if(choice[i]) continue;
        arr[k] = i;
        choice[i] = 1;
        pick(k+1);
        choice[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    pick(0);
    
}