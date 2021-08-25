// 23:08 ~ 23:43
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int x[1000001];
vector<int> v;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> x[i];
        v.push_back(x[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i=0;i<n;i++) {
        cout << lower_bound(v.begin(), v.end(), x[i]) - v.begin() << ' ';
    }
}