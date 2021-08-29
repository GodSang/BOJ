// 13:37 ~ 14:05
#include <iostream>
#include <algorithm>
using namespace std;
int num[12];
int a[12];
int cal[4];
int n, sum=0;
int mx = -1000000001;
int mn = 1000000001;
void func(int cur) {
    if(cur == n-1) {    // base case
        int res = num[0];
        for(int i=0;i<n-1;i++) {
            switch (a[i]) {
                case 0: 
                    res += num[i+1];
                    break;     
                case 1:
                    res -= num[i+1];
                    break;
                case 2:
                    res *= num[i+1];
                    break;
                case 3:
                    res /= num[i+1];
                    break;
            }
        }
        mx = max(res, mx);
        mn = min(res, mn);
        return;
    }

    for(int i=0;i<4;i++) {
        if(cal[i] == 0) continue;
        a[cur] = i;
        cal[i]--;
        func(cur+1);
        cal[i]++;
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> num[i];
    }
    for(int i=0;i<4;i++) {
        cin >> cal[i];
    }
    func(0);
    cout << mx << "\n" << mn;
}