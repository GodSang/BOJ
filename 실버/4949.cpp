// 10:34 ~ 11:08 / try: 1
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    while(1){
        int isWrong=0;
        stack<char> stk;
        getline(cin, str);
        if(str[0] == '.'){
            break;
        }
        
        for(char e : str) {
        // for(int i=0;i<str.size();i++) {
            if(e == '.'){
                if(!stk.empty())
                    isWrong = 1;
            } else if(e == '(' || e == '[') {
                stk.push(e);
            } else if(e == ')') {
                if(!stk.empty() && stk.top() == '('){
                    stk.pop();
                } else {
                    isWrong = 1;
                    break;
                }
            } else if(e == ']') {
                if(!stk.empty() && stk.top() == '['){
                    stk.pop();
                } else {
                    isWrong = 1;
                    break;
                }
            } else {
                continue;
            }      
        }
        if(isWrong)
            cout << "no" << "\n";
        else   
            cout << "yes" << "\n";
    }
    return 0;
}