//23:40 ~ 23:57
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v;
    int n, m;
    int num;
    cin >> n;
    while(n--) {
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    cin >> m;
    while(m--) {
        cin >> num;
        int st = 0;
        int en = v.size() - 1;
        int mid;
        while(1){
            mid = (st+en) / 2;
            if(num > v[mid]) {
                st = mid + 1;
            } else if(num < v[mid]) {
                en = mid - 1;
            } else if(num == v[mid]) {
                cout << "1" << "\n";
                break;
            }
            
            if(st > en) {
                cout << "0" << "\n";
                break;
            }
        }
    }
}