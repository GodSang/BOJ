// 00:25 ~ 00:46
#include <iostream>
#include <algorithm>
using namespace std;

int a[500001];

int lower_idx(int target, int len) {
    int st = 0;
    int en = len;
    int mid;
    while(st != en) {
        mid = (st+en)/2;
        if(a[mid] >= target) {
            en = mid;
        } else if(a[mid] < target) {
            st = mid+1;
        }
    }
    return st;
}

int upper_idx(int target, int len) {
    int st = 0;
    int en = len;
    int mid;
    while(st != en) {
        mid = (st+en)/2;
        if(a[mid] > target) {
            en = mid;
        } else if(a[mid] <= target) {
            st = mid+1;
        }
    }
    return st;    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    sort(a, a+n);

    cin >> m;
    for(int i=0;i<m;i++) {
        cin >> k;
        // cout << upper_idx(k, n) - lower_idx(k, n)  << " ";
        cout << upper_bound(a, a+n, k) - lower_bound(a, a+n, k) << " ";
    }
}