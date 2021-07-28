// 14:28 ~ 15:10
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int,int>> v;

void hanoi(int a, int b, int n) {
    if(n==1) {
        v.push_back({a,b});
        return;
    }
    hanoi(a,6-a-b,n-1);
    v.push_back({a,b});
    hanoi(6-a-b,b,n-1);

}

int main() {
    int n;
    cin >> n;
    hanoi(1,3,n);
    cout << v.size() << "\n";
    for(auto e : v) {
        cout << e.first << " " << e.second << "\n";
    }
}