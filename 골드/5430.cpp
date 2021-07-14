#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, tmp=0, size;
    int errFlag=0, revFlag=0;
    string func, arr;
    cin >> n;
    while(n--) {
        deque<int> dq;
        cin >> func;
        cin >> k;
        cin >> arr;
        for(int i=1;i<arr.size()-1;i++) {
            if(arr[i] == ',') {
                dq.push_back(tmp);
                tmp = 0;
            }else {
                tmp = 10*tmp + (arr[i] - '0');
            }
        }
        if(tmp != 0) {
            dq.push_back(tmp);
        }

        for(int i=0;i<func.size();i++) {
            if(func[i] == 'R') {
                revFlag = 1-revFlag;
            }
            if(func[i] == 'D') {
                if(dq.empty()) {
                    errFlag = 1;
                    break;
                }else {
                    if(revFlag) {
                        dq.pop_back();
                    }else {
                        dq.pop_front();
                    }
                }
            }
        }
        if(errFlag) {
            cout << "error" << '\n';
        } else {
            size = dq.size();
            if(revFlag) {
                reverse(dq.begin(), dq.end());
            }
            cout << "[";
            for(int i=1;i<size;i++) {
                cout << dq.front() << ",";
                dq.pop_front();
            }
            if(!dq.empty()) {
                cout << dq.back();
            }
            cout << "]" << '\n';
        }
        errFlag = 0;
        revFlag = 0;
        tmp = 0;
    }
    return 0;
}