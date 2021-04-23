#include <iostream>

int main(){
    using namespace std;
    ios::sync_with_stdio(0);
    cin.tie(0);

    int max = -1, max_cnt=0, cnt=0;
    int a;

    for(int i=0 ; i<9 ; i++) {
        cnt++;
        cin >> a;
        if(a > max) {
            max = a;
            max_cnt = cnt;
        }
    }
    cout << max << "\n" << max_cnt;


}