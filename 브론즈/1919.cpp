// 21-05-02 16:23 ~ 16:31 1 try
#include <iostream>
#include <string>
#include <stdlib.h>     // 절대값 abs 사용
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int alphaA[26]={0,};
    int alphaB[26]={0,};
    string a,  b;
    int cnt=0;
    cin >> a >> b;
    for(auto e : a) {
        alphaA[e-'a']++;
    }
    for(auto e : b) {
        alphaB[e-'a']++;
    }
    for (int i=0;i<26;i++) {
        if(alphaA[i] == alphaB[i])
            continue;
        cnt += abs(alphaA[i]-alphaB[i]);
    }
    cout << cnt;
    return 0;
}