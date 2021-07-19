//14:44 ~ 15:41
#include <iostream>
#include <queue>

using namespace std;
int dist[100001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<int> q;
    int n,k;
    fill(dist, dist+100001, -1);
    cin >> n >> k;
    if(n == k) {
        cout << 0;
         return 0;
    }
    q.push(n);
    while(!q.empty()){
        int cur = q.front(); 
        q.pop();
        for(int nx : {cur-1, cur+1, cur*2}) {
            if(nx < 0 || nx >= 100001) continue;
            if(dist[nx] != -1) continue;
            dist[nx] = dist[cur] + 1;
            if(nx == k) {
                cout << dist[nx]+1;
                return 0;
            }
            q.push(nx);
        }
    }
}