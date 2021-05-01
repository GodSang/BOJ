#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr_0[7]={0,};
    int arr_1[7]={0,};

    int k,n, s, y;
    int sum=0;
    cin >> n >> k;
    for(int i=0; i<n;i++) {
        cin >> s >> y;
        if(s==0) 
            arr_0[y]++;
        else
            arr_1[y]++;
    }

    for(int i=1;i<7;i++) {
    
        if(arr_0[i]%k != 0) {    // 나머지 있음
            sum+=arr_0[i]/k + 1;
        }
        else if(arr_0[i]%k == 0) {              // 나머지 없음
            sum+=arr_0[i]/k;
        }

        if(arr_1[i]%k != 0) {    // 나머지 있음
            sum+=arr_1[i]/k + 1;
        }
        else if(arr_1[i]%k == 0) {              // 나머지 없음
            sum+=arr_1[i]/k;
        }
    }
    cout << sum;
    return 0;
}