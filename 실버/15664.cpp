// 15:05 ~15:11
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> num;
int arr[9];
int chk[9];
int n,m;

void func(int cur) {
    if(cur == m) {
        for(int i=0;i<m;i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    int prev = -1;
    for(int i=0;i<n;i++) {
        if(chk[i] == 1) continue;
        if(prev == num[i]) continue;
        if(cur != 0) {
            if(arr[cur-1] > num[i]) continue;
        }
        arr[cur] = num[i];
        prev = arr[cur];
        chk[i] = 1;
        func(cur+1);
        chk[i] = 0;
    }
}

int main() {
    int k;
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> k;
        num.push_back(k);
    }
    sort(num.begin(), num.end());
    func(0);
}
