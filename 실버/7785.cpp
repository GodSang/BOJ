// 20:32
#include <iostream>
#include <map>
#include <string>
using namespace std;

bool comp(string a, string b) {
    return a < b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    map<string, string, greater<string>> m;
    int n;
    string name;
    string str;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> name >> str;
        m[name] = str;
    }
    for(pair<string,string> e : m){
        if(e.second == "enter") {
            cout << e.first << "\n";
        }
    }
}