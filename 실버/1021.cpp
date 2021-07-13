#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n, k, num, sum=0;
    int cnt =0;
    int flag;
    deque<int> deq;
    deque<int>::iterator iter;
    cin >> n >> k;
    for(int i=1;i<=n;i++)
        deq.push_back(i);

    while(k--) {
        cin >> num;
        cnt = 0;
        iter = deq.begin();
        while(*iter != num) {
            iter++;
            cnt++;
        }
        if( cnt*2 < deq.size() ? 1 : 0) {
            while(deq.front() != num) {
                deq.push_back(deq.front());
                deq.pop_front();
                sum++;
            }
            deq.pop_front();
        }else {
            while(deq.back() != num) {
                deq.push_front(deq.back());
                deq.pop_back();
                sum++;
            }
            deq.pop_back();
            sum++;
        }
    }
    cout << sum;
    return 0;
}