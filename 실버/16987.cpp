// 17:16 ~ 18:08
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
#define X first
#define Y second

vector<pair<int,int>> egg;
int isBroken[9];
int n;
int broken = -1;

 
void func(int cur) {
    int cnt=0;
    for(int i=0;i<n;i++) {
        if(egg[i].X <= 0) cnt++;
    }
    if(cur == n || cnt == n-1) {  // 가장 오른쪽 계란이면
        broken = cnt > broken ? cnt : broken;
        return;
    }
    if(egg[cur].X <= 0) {   // 이미 깨진 계란이면
        func(cur+1);
    }
    else{   
        for(int i=0;i<n;i++) {
            if(i == cur) continue;
            if(egg[i].X <= 0) continue;
            egg[cur].X -= egg[i].Y;
            egg[i].X -= egg[cur].Y;
            func(cur+1);
            egg[cur].X += egg[i].Y;
            egg[i].X += egg[cur].Y;
        }
    }
}

int main() {
    int s, w;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> s >> w;
        egg.push_back({s,w});
    }
    func(0);
    cout << broken;
}
