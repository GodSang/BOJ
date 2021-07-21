// 10:04 ~ 10:36
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
#define X first
#define Y second
int board[301][301];
int dx[8]={-2,-2,-1,-1,1,1,2,2};
int dy[8]={1,-1,2,-2,2,-2,1,-1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v;
    int n, t;
    int lx, ly, rx, ry;
    cin >> t;
    while(t--) {
        queue<pair<int,int>> q;
        cin >> n;
        cin >> lx >> ly >> rx >> ry;
        q.push({lx,ly});
        board[lx][ly] = 1;
        while(!q.empty()){
            pair<int,int> cur = q.front();
            q.pop();
            if(cur.X == rx && cur.Y == ry) {
                v.push_back(board[rx][ry] - 1);
                break;
            }
            for(int dir=0;dir<8;dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx<0||nx>=n||ny<0||ny>=n) continue;
                if(board[nx][ny] != 0) continue;
                q.push({nx,ny});
                board[nx][ny] = board[cur.X][cur.Y] + 1;
            }
        }
        for(int i=0;i<n;i++) {
            fill(board[i], board[i] + n, 0);
        }
    }
    for (auto e : v)
        cout << e << "\n";
}