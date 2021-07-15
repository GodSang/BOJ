// 15:08~16:31
#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<int> stk;

int nextSum(char next) {
    int sum=0;
    int pos = next == ')' ? -1 : -2;
    int impos = next == ')' ? -2 : -1;
    while(!stk.empty()) {
        if(stk.top() == impos) {
            return -1; 
        } else if(stk.top() == pos) {
            stk.pop();
            if(next == ')') {
                if(sum == 0)
                    return 2;
                else
                    return sum*2;
            }
            if(sum == 0)
                return 3;
            else
                return sum*3;
        } else {
            sum += stk.top();
            stk.pop();
        }
    }
    return -1;
}

int main() {
    string str;
    int isWrong=0, ans=0;
    int result=0;
    int tmp;
    cin >> str;
    for(int i=0;i<str.size();i++) {
        if(str[i] == '(' || str[i] == '[') {
            tmp = str[i] == '(' ? -1 : -2;
            stk.push(tmp);
        }else if(str[i] == ')' || str[i] == ']') {
            ans = nextSum(str[i]);
            if(ans == -1) {
                isWrong = 1;
                break;
            }
            stk.push(ans);
        }
    }
    if(isWrong || str.size() == 1)
        cout << "0";
    else{
        while(!stk.empty()){
            if(stk.top() == -2 || stk.top() == -1){
                cout << "0";
                return 0;
            }
            result += stk.top();
            stk.pop();
        }
        cout << result;
    }
    return 0;
}