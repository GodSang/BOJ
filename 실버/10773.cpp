#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k, n, sum=0;
    stack<int> stk;
    cin >> k;
    while(k--){
        cin >> n;
        if(n != 0) {
            stk.push(n);
        }
        if(n == 0)
            stk.pop();     
    }
    while(!stk.empty()) {
        sum += stk.top();
        stk.pop();
    }
    cout << sum;
    return 0;
}