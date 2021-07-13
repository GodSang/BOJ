#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> vec;
    string str;
    int n, k;
    int front=0,end=0;
    cin >> n;
 
    while(n--){
        cin >> str;
    if(str == "push") {
        cin >> k;
        vec.push_back(k);
        end++;
        continue;
    }else if(str == "pop") {
        if(front == end) {
            cout << -1;
        }else{
            cout << vec[front];
            front++;
        }
    }else if(str == "size") {
        cout << end-front;
    }else if(str == "empty") {
        if(front == end) {
            cout << 1;
        }else
            cout << 0;
    }else if(str == "front") {
        if(front == end) {
            cout << -1;
        }else {
            cout << vec[front];
        }
    }else if(str == "back") {
        if(front == end) {
            cout << -1;
        }else {
            cout << vec[end-1];
        }
    }
    cout << '\n';
    }
    return 0;
}