// 16:46 ~ 16:59
#include <iostream>
#include <queue>
#include <utility>

int dist[200001];

using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<int> q;
    int n,k;
    cin >> n >> k;
    q.push(n);
    dist[n] = 1;
    while(!q.empty()) {
        int flag=0;
        int cur = q.front();
        q.pop();
        if(cur == k) {
            break;
        }
        for(int e : {cur*2, cur-1, cur+1}){
            flag++;
            if(e < 0 || e > 200000) continue;
            if(dist[e] != 0) continue;
            q.push(e);
            if(flag == 1) {
                dist[e] = dist[cur];
            } else {
                dist[e] = dist[cur] + 1;
            }
        }
    }
    cout << dist[k] - 1;
}
