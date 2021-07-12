#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> stk;
    vector<int> vec;
    vector<char> res;
    int n, k, l=0;
    int flag=0;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> k;
        vec.push_back(k);
    }
    int i=1;
    while(l < n){
        if (i > n+1) {
            flag = 1;
            break;
        }
        if(!stk.empty()){
            if(stk.top() == vec[l]){
                l++;
                res.push_back('-');
                stk.pop();
            }
            else{
            stk.push(i++);
            res.push_back('+');
            }
        }
        else {
            stk.push(i++);
            res.push_back('+');
        }
    }
    if(flag)
        cout << "NO";
    else {
        for(int e=0; e<res.size()-1;e++) {
            cout << res[e] << "\n";
        }
        cout << res.back();
    }
    return 0;
}