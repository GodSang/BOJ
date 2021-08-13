// 19:53 ~ 20:01
#include <iostream>
#include <stack>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long int s;

    cin >> s;
    long long int cur=1;
    long long int sum=0;
    long long int ans=0;
    while(1) {
        if(sum + cur > s) {
            sum -= cur-1;
            ans--;
            continue;
        }
        sum += cur;
        ans++;
        if(sum == s) break;
        else if(sum > s) {
            sum -= cur;
            ans--;
        }
        cur++;
    }
    cout << ans;
}