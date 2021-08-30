// 20:52 ~ 21:40
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<char> stk;
    stack<char> stk_ans;
    string str, boom;
    cin >> str;
    int str_size = str.size();
    cin >> boom;
    int boom_size = boom.size();
    
    for(int i=0;i<str_size;i++) {
        stack<char> stk_tmp;
        int boom_flag=1;
        if(str[i] == boom.back()) {
            for(int j=boom_size-2;j>=0;j--) {
                if(!stk.empty() && stk.top() == boom[j]) {
                    stk_tmp.push(stk.top());
                    stk.pop();
                } else {
                    while(!stk_tmp.empty()) {
                        stk.push(stk_tmp.top());
                        stk_tmp.pop();
                    }
                    stk.push(str[i]);
                    break;
                }
            }
        } else {
            stk.push(str[i]);
        }
    }
    if(stk.empty()) {
        cout << "FRULA";
    } else {
        while(!stk.empty()) {
            char c = stk.top();
            stk.pop();
            stk_ans.push(c);
        }
        while(!stk_ans.empty()) {
            cout << stk_ans.top();
            stk_ans.pop();
        }
    }
}