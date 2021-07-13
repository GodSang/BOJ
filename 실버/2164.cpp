#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, flag = 1;
    int num;
    queue<int> q;
    cin >> n;
    if(n==1) {
        cout << 1;
        return 0;
    }
    for(int i=1;i<=n;i++)
        q.push(i);
    while(!q.empty()) {
        if(flag) {
            q.pop();
            flag--;
        }else {
            num = q.front();
            q.push(num);
            q.pop();
            flag++;
        }
    }
    cout << num;
    return 0;
}