// 19:36 ~ 19:50
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    int mn = 2000000001;
    cin >> n >> m;
    vector<int> vec(n);
    for(int i=0;i<n;i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    int en=0;
    for(int st=0;st<n;st++) {
        while(en < n && vec[en]-vec[st] < m) en++;
        if(en == n) break;
        mn = min(mn, vec[en]-vec[st]);
    }
    /*
    int tmp=0;
    for(int st=0;st<n;st++) {
        for(int en=tmp;en<n;en++) {
            if(vec[en] - vec[st] >= m){ // 차이가 m 이상이면
                mn = min(vec[en] - vec[st], mn);
                tmp = en;
                break;
            }  
        }
    }
    */
    cout << mn;

}