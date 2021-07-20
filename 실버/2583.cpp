// 16:10 ~ 17:18
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int board[101][101];
int vis[101][101];
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    int lx,ly,rx,ry;
    int area=0, sum=0;
    vector<int> vec;
    queue<pair<int,int>> q;
    cin >> n >> m >> k;
    while(k--) {
        cin >> lx >> ly >> rx >> ry;
        for(int i = ly ; i < ry ; i++) {
            for(int j = lx ; j < rx ; j++) {
                board[i][j] = -1;
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(board[i][j] == -1 || vis[i][j] == 1) continue;
            q.push({i,j});
            vis[i][j] = 1;
            area++;
            while(!q.empty()) {
                pair<int,int> cur = q.front();
                q.pop();
                sum++;
                for(int dir=0;dir<4;dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx<0||nx>=n||ny<0||ny>=m) continue;
                    if(vis[nx][ny] == 1 || board[nx][ny] == -1) continue;
                    q.push({nx,ny});
                    vis[nx][ny] = 1;
                }
            }
            vec.push_back(sum);
            sum=0;
        }
    }
    sort(vec.begin(), vec.end());
    cout << area << "\n";
    for(auto e : vec)
        cout << e << " ";

}