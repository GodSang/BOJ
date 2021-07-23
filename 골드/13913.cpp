// 17:20 ~ 17:53
#include <iostream>
#include <queue>
#include <stack>

using namespace std;
int dist[200001];
int trace[200001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<int> q;
    int n,k,tmpK;
    cin >> n >> k;
    q.push(n);
    trace[n] = n;
    dist[n] = 1;
    while(!q.empty()){
        int cur = q.front(); 
        q.pop();
        if(cur == k) {
            break;
        }
        for(int nx : {cur-1, cur+1, cur*2}) {
            if(nx < 0 || nx > 200000) continue;
            if(dist[nx] != 0) continue;
            dist[nx] = dist[cur] + 1;
            q.push(nx);
            trace[nx] = cur;
        }
    }
    cout << dist[k] - 1 << "\n";
    stack<int> s;

    tmpK = k;
    while(n != tmpK){
        s.push(trace[tmpK]);
        tmpK = trace[tmpK];
    }
    
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << k;

}