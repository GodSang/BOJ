#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num[10]={0,};
    string n;
    int cnt=0;
    int index=0;
    int max = -1;

    cin >> n;

    for(int i=0; i<n.size();i++) {
        if(n[i] == '9') {
            num[6]++;
        }
        else {
            num[n[i]-'0']++;
        }
    }
    num[6] = num[6]/2 + num[6]%2;
    for(int i=0;i<9;i++){
        if(num[i]>max){
            max = num[i];
        }
    }
    cout << max;
    return 0;
}