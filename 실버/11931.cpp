// 20:53 ~ 20:59
#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000001];
bool comp(int a, int b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n, comp);
    for(int i=0;i<n;i++) {
        cout << arr[i] << "\n";
    }
}