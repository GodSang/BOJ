// 19:00 ~19:57
#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

int same[1002][1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;
    int lenA = a.size();
    int lenB = b.size();
    for(int curA=1;curA<=lenA;curA++) {
        for(int curB=1;curB<=lenB;curB++) {
            if(a[curA-1] == b[curB-1]) {
                same[curA][curB] = same[curA-1][curB-1] + 1; 
            }else if(a[curA-1] != b[curB-1]) {
                same[curA][curB] = max(same[curA-1][curB], same[curA][curB-1]);
            }
        }
    }
    cout << same[lenA][lenB];
}