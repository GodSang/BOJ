// 15:56 ~ 16:35
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l,c;
char arr[16];
bool chk[16];
vector<char> alp;

void func(int cur) {
    if(cur == l) {
        int za = 0;
        int mo = 0;
        for(int i=0;i<l;i++){
            if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u' )
                mo++;
            else   
                za++;
        }
        if(mo < 1 || za < 2) return;
        for(int i=0;i<l;i++) {
            cout << arr[i];
        }
        cout << "\n";
        return;
    }
    for(int i=0;i<c;i++) {
        if(chk[i] == 1) continue;
        if(cur != 0) {
            if(arr[cur-1] > alp[i]) continue;
        }
        chk[i] = 1;
        arr[cur] = alp[i];
        func(cur+1);
        chk[i] = 0;
    }
}

int main() {
    char n;
    cin >> l >> c;
    for(int i=0;i<c;i++) {
        cin >> n;
        alp.push_back(n);
    }
    sort(alp.begin(), alp.end());
    func(0);
}