// 20:56
#include <iostream>
#include <queue>
#include <algorithm>
int board[1000001];
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<int> q;
    int f,s,g,u,d;
    int isCorrect=0;
    cin >> f >> s >> g >> u >> d;
    board[s] = 1;
    q.push(s);
    while(!q.empty()) {
        int cur = q.front();
        if(cur == g) {
            isCorrect = 1;
            break;
        }
        q.pop();
        
        int ux = cur + u;
        int dx = cur - d;
        for(int e : {ux, dx}) {
            if(e < 1 || e > f) continue;
            if(board[e] != 0 ) continue; // 1 2 3 4 5
            q.push(e);
            board[e] = board[cur] + 1;
        }
    }
    if(isCorrect) 
        cout << board[g] - 1;
    else
        cout << "use the stairs";
}