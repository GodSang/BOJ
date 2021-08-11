//19:20
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    int num[100001];
    int arr[100001];
    cin >> n >> m;

    cin >> num[0];
    arr[0] = num[0];
    for(int i=1;i<n;i++) {
        cin >> num[i];
        arr[i] = arr[i-1] + num[i];
    }
    int start, end;
    while(m--) {
        cin >> start >> end;
        if(start == 1) {
            cout << arr[end-1] << "\n";
        }
        else {
            cout << arr[end-1] - arr[start-2] << "\n";
        }
    }
}