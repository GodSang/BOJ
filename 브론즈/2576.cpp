#include <iostream>

int main(){
    using namespace std;
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, lop = 7;
    int sum=0, min=100;
    while(lop--) {
        cin >> a;
        if(a%2) {
            sum += a;
            if(a<min) min = a;
        } 
    }
    if(sum) cout << sum << "\n" << min;
    else cout << "-1";
}