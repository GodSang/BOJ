#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    int max = 100000001;
    stack<pair<int, int>> stk;
    cin >> n;
    stk.push({max, 0});
    for(int i = 1; i <= n ; i++) {
        cin >> k;
        while(stk.top().first < k) {
            stk.pop();
        }
        cout << stk.top().second << " ";
        stk.push({k, i});
        
    }



    return 0;
}