// 15:29 ~ 15:50
#include <iostream>
using namespace std;
int arr[13];
int num[13];
bool chk[13];
int k;
void func (int cur) {
    if(cur==6) {
        for(int i=0;i<6;i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=0;i<k;i++) {
        if(chk[i] == 1) continue;
        if(cur != 0) {
            if(arr[cur-1] > num[i]) continue;
        }
        arr[cur] = num[i];
        chk[i] = 1;
        func(cur+1);
        chk[i] = 0;
    }
}

int main () {
    while(1){
        cin >> k;
        if(k==0) break;
        for(int i=0;i<k;i++) {
            cin >> num[i];
        }
        func(0);
        cout << "\n";
    }
}