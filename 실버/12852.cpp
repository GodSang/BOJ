#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001];
int way[1000001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    arr[1] = 0;
    for(int i=2;i<=n;i++) {
        arr[i] = arr[i-1] + 1;
        way[i] = i-1;
        if(i%3 == 0) {
            if(arr[i] > arr[i/3] + 1) {
                arr[i] = arr[i/3] + 1;
                way[i] = i/3;
            }
        }
        if(i%2 == 0) {
            if(arr[i] > arr[i/2] + 1) {
                arr[i] = arr[i/2] + 1;
                way[i] = i/2;
            }
        }
    }
    cout << arr[n] << "\n";
    cout << n << " ";
    while(n!=1) {
        cout << way[n] << " ";
        n = way[n];
    }

}