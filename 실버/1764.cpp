//17:50 ~ 17:56
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,cnt=0;
    string s;
    set<string> a;
    set<string> b;
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> s;
        a.insert(s);
    }
    for(int i=0;i<m;i++) {
        cin >> s;
        if(a.find(s) != a.end()) {
            cnt++;
            b.insert(s);
        }
    }
    cout << cnt << "\n";
    for(string str : b)
        cout << str << "\n";
}