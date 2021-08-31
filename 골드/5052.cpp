// 19:10 ~ 19:37
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n;
    string str;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<string> vec;
        for(int i=0;i<n;i++) {
            cin >> str;
            vec.push_back(str);
        }
        sort(vec.begin(), vec.end());
        set<string> s;
        int flag = 0;
        for(int i=0;i<n;i++) {
            string tmp_str = "";
            for(int j=0; j<vec[i].size()-1 ;j++) {
                
                tmp_str += vec[i][j];
                if(s.find(tmp_str) != s.end()) {
                    flag = 1;
                    cout << "NO\n";
                    break;
                }
            }
            if(flag) break;
            s.insert(vec[i]);
        }
        if(!flag) cout << "YES\n";
    }
}