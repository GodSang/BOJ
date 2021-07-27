#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#define LMT 500000
#define X first
#define Y second
using namespace std;
int vis[LMT+1][2];

int main() {
    queue<pair<int,int>>q;
    int n,k;
    cin >> n >> k;
    if(n == k) {
        cout << 0;
        return 0;
    }
    for(int i=0;i<LMT+1;i++) {
        fill(vis[i], vis[i] +2, -1);
    }
    
    vis[n][0] = 1;
    q.push({n, 0});
    while(!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();
        cur.Y += 1;
        for(int nx : {cur.X-1, cur.X+1, cur.X*2}) {
            if(nx<0 || nx > LMT) continue;
            if(vis[nx][cur.Y % 2] != -1) continue;
            vis[nx][cur.Y%2] = cur.Y;
            q.push({nx, cur.Y});
        }
    }
    for(int i=0;i<LMT;i++) {
        k += i;
        if(k > LMT) break;
        if(vis[k][i%2] <= i) {
            cout << i;
            return 0;
        }
    }
    cout << -1;

}