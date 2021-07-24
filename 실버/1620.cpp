// 21:22
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    map<string, int> simap;
    map<int, string> ismap;
    string str;
    string test;
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++) {
        cin >> str;
        simap[str] = i;
        ismap[i] = str;
    }
    while(m--) {
        cin >> test;
        if(test[0] - '0' >= 10 || test[0] - '0' < 0) {
            cout << simap[test] << "\n";
        } else {
            cout << ismap[stoi(test)] << "\n";
        }
    }
}