/* 
x + y + z = k
x + y = k - z
x + y => O(n^2)
k - z에 해당하는 값이 있는지 탐색 => o(logN)
최종 O(n^2logN)
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[1001];
vector<int> two;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            two.push_back(a[i]+a[j]);
        }
    }
    sort(two.begin(), two.end());
    for(int i=n-1;i>0;i--) {
        for(int j=0;j<i;j++) {
            if(binary_search(two.begin(), two.end(), a[i] - a[j])) {
                cout << a[i];
                return 0;
            }
        }
    }
}