// 17:40 ~ 18:13
#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int colorCost[1001][3];
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<3;j++) {
            cin >> colorCost[i][j];
        }
    }
    arr[0][0] = colorCost[0][0];
    arr[0][1] = colorCost[0][1];
    arr[0][2] = colorCost[0][2];
    for(int i=1;i<n;i++) {
        for(int j=0;j<3;j++) {
            if(j==0)
                arr[i][0] = min(arr[i-1][1], arr[i-1][2]) + colorCost[i][0];
            else if(j==1)
                arr[i][1] = min(arr[i-1][0], arr[i-1][2]) + colorCost[i][1];
            else if(j==2)
                arr[i][2] = min(arr[i-1][0], arr[i-1][1]) + colorCost[i][2];
        }
    }
    cout << min({arr[n-1][0], arr[n-1][1], arr[n-1][2]});
}