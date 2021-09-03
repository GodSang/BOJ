
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, s;
    int mn=100001;
    cin >> n >> s;
    vector<int> vec(n);
    for(int i=0;i<n;i++) {
        cin >> vec[i];
    }
    int en=0;
    int tot=vec[0];
    for(int st=0;st<n;st++) {
        while(en < n && tot < s) {
            en++;
            if(en == n) break;
            tot += vec[en];
            
        }
        if(en == n) break;
        mn = min(mn, en-st+1);
        tot -= vec[st];
    }
    if(mn == 100001) mn = 0;
    cout << mn;
}