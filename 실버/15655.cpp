// 20:19 ~ 20:28
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> num;
int arr[9];
bool chk[9];
int n,m;

void func(int cur) {
    if(cur==m) {
        for(int i=0;i<m;i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    for(int i=0;i<n;i++) {
        if(chk[i] == 1) continue;
        if(cur==0) {
            chk[i] = 1;
            arr[cur] = num[i];            
        }
        else {
            if(num[i] < arr[cur-1]) continue;
            chk[i] = 1;
            arr[cur] = num[i];
        }
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