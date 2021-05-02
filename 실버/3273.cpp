// 21-05-02 16:33 ~ 17:11 try : 3
#include <iostream>

using namespace std;

int arr[1000001] = {0,};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    int num;
    int cnt=0;

    cin >> n;
    for (int i = 0;i<n;i++) {
        cin >> num;
        arr[num]++;
    }

    cin >> x;
    
    for(int i = 1; i <= 1000000 ; i++) {
        if(i>=x)
            break;
        if(x-i > 1000000 || x-i == i)
            continue;
        if(arr[i] != 0) {
            if(arr[x-i] != 0){
                arr[x-i] = 0;
                // cout << "cnt++ : " << i << " : " << arr[x-i] << endl;
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}