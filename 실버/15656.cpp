// 13:31 ~ 13:40
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;
int arr[8];
vector<int> num;

void func(int cur) {
    if(cur == m) {
        for(int i=0;i<m;i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=0;i<n;i++) {
        arr[cur] = num[i];
        func(cur+1);
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