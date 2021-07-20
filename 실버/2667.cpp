// 21:05 ~ 21:33
#include <iostream>
#include <stdio.h>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define X first
#define Y second
int board[25][25];
int vis[25][25];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int>> q;
    vector<int> v;
    int n, k, area=0, cnt=0;
    string str;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> str;
        for(int j=0;j<n;j++) {
            board[i][j] = str[j] - '0';
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(vis[i][j] != 0 || board[i][j] == 0) continue;
            q.push({i,j});
            vis[i][j] = 1;
            while(!q.empty()) {
                pair<int,int> cur = q.front();
                q.pop();
                cnt++;
                for(int dir=0;dir<4;dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx<0||nx>=n||ny<0||ny>=n) continue;
                    if(vis[nx][ny] != 0 || board[nx][ny] == 0) continue;
                    q.push({nx,ny});
                    vis[nx][ny]=1;
                }
            }
            area++;
            v.push_back(cnt);
            cnt=0;
        }
    }
    sort(v.begin(), v.end());
    cout << area << "\n";
    for (auto e : v)
        cout << e << "\n";
}
