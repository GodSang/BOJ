// 13:30 ~ 14:12
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    int sum=0;
    char tmp;
    stack<char> stk;

    cin >> str;
    for(int i=0;i<str.size();i++) {
        tmp = str[i];
        if(tmp == '(') {
            stk.push(tmp);
        }else if(tmp == ')'){
            if(str[i-1] == '(') {
                stk.pop();
                sum += stk.size();
            } else if(str[i-1] == ')') {
                stk.pop();
                sum++;
            }
        }
    }
    cout << sum;
    return 0;
}