// 15:31 ~ 15:52
#include <iostream>
using namespace std;

int arr[20];
int n, s,cnt=0;
void func(int k, int sum) {
    if(k == n){
        if(sum == s) {
            cnt++;
        }
        return;
    }
    func(k+1, sum);
    func(k+1, sum+arr[k]);
}

int main() {
    cin >> n >> s;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    func(0,0);
    if(s==0) {
        cnt--;
    }
    cout << cnt;
}