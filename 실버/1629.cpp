// 13:45 ~ 14:14
#include <iostream>

#define ll long long
using namespace std;

ll func(ll a, ll b, ll c) {
    ll res;
    if(b==1) {
        return a%c;
    }
    res = func(a, b/2, c);
    res = res * res % c;
    if(b%2 == 0)
        return res;
    else
        return res * a % c;
}

int main() {
    ll a,b,c;
    cin >> a >> b >> c;
    cout << func(a,b,c);
}