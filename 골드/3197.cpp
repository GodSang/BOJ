// 17:30 ~ 19:10
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define X first
#define Y second
using namespace std;

char board[1501][1501];
int swanVis[1501][1501];
int waterVis[1501][1501];
queue<pair<int,int>> swanQ;
queue<pair<int,int>> waterQ;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void input(int n, int m) {
    int firstSwan=1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> board[i][j];
            if(board[i][j] == 'L' && firstSwan) {   // 처음 만난 백조일 경우 시작점으로 지정
                swanVis[i][j] = 1;
                swanQ.push({i,j});
                firstSwan = 0;
            } else if(board[i][j] == 'L' && !firstSwan) {
                waterQ.push({i,j});
            } else if(board[i][j] == '.') { // 빙판은 따로 저장
                waterQ.push({i,j});
                waterVis[i][j] = 1;
            }
        }
    }
}

void printTest(int n, int m) {
    cout << endl;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout << swanVis[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    int cnt=0;
    int isSearch=1;
    vector<pair<int,int>> v;
    cin >> n >> m;
    input(n, m);
    while(1 && isSearch){
        // 백조가 빙판에 닿을 때 까지 BFS
        while(!swanQ.empty() && isSearch) {
            pair<int,int> cur = swanQ.front();
            swanQ.pop();
            for(int dir=0;dir<4;dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(swanVis[nx][ny] != 0 ) continue;
                if(board[nx][ny] == 'X') {
                    swanVis[nx][ny] = 1;
                    v.push_back({nx,ny});
                    continue;
                }
                if(board[nx][ny] == 'L') {
                    isSearch = 0; 
                    break;
                }
                swanVis[nx][ny] = 1;
                swanQ.push({nx,ny});
            }
        }
        for(auto e : v) {
            swanQ.push(e);
        }
        v.clear();
        // 저장해둔 물 주변에 빙하가 있을 경우 빙하를 녹임
        while(!waterQ.empty() && isSearch) {
            pair<int,int> cur = waterQ.front();
            waterQ.pop();
            for(int dir=0;dir<4;dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(waterVis[nx][ny] != 0) continue;
                if(board[nx][ny] == 'X') {
                    board[nx][ny] = '.';
                    waterVis[nx][ny] = 1;
                    v.push_back({nx,ny});
                    continue;
                }
                waterVis[nx][ny] = 1;
                waterQ.push({nx,ny});
            }
        }
        for(auto e : v) {
            waterQ.push(e);
        }
        v.clear();
        cnt++;
    }
    cout << cnt-1;
}


