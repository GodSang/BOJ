#include <iostream>
#include <string>

    using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c;
    int result=0;
    int arr[10] = {0,};

    string str;
    
    cin >> a >> b >> c;
    result = a*b*c;
    str = to_string(result);
    for(auto e : str) {
        arr[e-48]++;
    }

    for(auto e : arr) {
        cout << e << "\n";
    }

    return 0;
}