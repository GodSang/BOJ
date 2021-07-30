//13:48 ~ 14:39
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[9];
bool chk[9];
vector<int> num;
int n,m;

void func(int cur) {
    if(cur==m) {
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
        arr[cur] = num[i];
        prev = num[i];
        chk[i] = 1;
        func(cur+1);
        chk[i] = 0;
    }
}


int main () {
    int k;
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> k;
        num.push_back(k);
    }
    sort(num.begin(), num.end());
    func(0);
}
 