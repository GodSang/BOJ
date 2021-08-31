// 21:34 ~ 21:41
#include <iostream>
#include <queue>
using namespace std;

struct comp{
    bool operator()(int a, int b) {
        if(abs(a) == abs(b)) {
            return a > b;
        }
        return abs(a) > abs(b);
        
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int, vector<int>, comp> pq;
    int n, x;
    cin >> n;
    while(n--) {
        cin >> x;
        if(x == 0) {
            if(pq.empty()) {
                cout << "0" << "\n";
            }else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        } else {
            pq.push(x);
        }

    }
}