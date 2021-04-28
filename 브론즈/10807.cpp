#include <iostream>

int main(){
    using namespace std;
    ios::sync_with_stdio(0);
    cin.tie(0);

    int number[201]={0, };
    int n, v;
    int a;

    cin >> n;

    for (int i = 0 ; i < n ; i++) {
        cin >> a;
        number[a+100]++;
    }
    cin >> v;

    cout << number[v+100];

    return 0;
}