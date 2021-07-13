#include <iostream>
#include <stack>
#include <utility>

using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k,max=1000000001;
    long long sum=0;
    stack<int> tmp;
    stack<pair<int,int>> stk;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> k;
        tmp.push(k);
    }
    stk.push({max,0});
    while(!tmp.empty()){
        int tmpsum=0;
        while(tmp.top() > stk.top().first) {
            tmpsum += 1+stk.top().second;
            stk.pop();
        }
        stk.push({tmp.top(), tmpsum});
        tmp.pop();
        sum += tmpsum;
    }
    cout << sum;
    return 0;
}