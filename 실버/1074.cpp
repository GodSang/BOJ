// 15:13 ~ 16:01
#include <iostream>
#include <cmath>
using namespace std;

int search(int n, int x, int y) {
    int half = pow(2,n-1);
    if(n == 0) return 0;
    if(x<half && y<half)    // 1번 영역
        return search(n-1,x,y);   
    else if(x<half && y>=half)  // 2번 영역
        return half*half + search(n-1, x, y-half);
    else if(x>=half && y<half)  // 3번 블록
        return 2*half*half + search(n-1, x-half,y);
    else if(x>=half && y>=half)   // 4번 블록
        return 3*half*half + search(n-1, x-half, y-half);    
}

int main() {
    int n,x,y;
    cin >> n >> x >> y;
    cout << search(n,x,y);
}