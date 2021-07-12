#include <iostream>
#include <list>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k, n;
    list<int> l;
    list<int>::iterator iter;
    cin >> n >> k;
    for(int i=1;i<=n;i++)
        l.push_back(i);
    iter = l.end();
    cout << "<";
    for(int i=0;i<n-1;i++){
        for(int j=0;j<k;j++){
            if(iter == --l.end()){
                iter = l.begin();
            }
            else{
                iter++;
            }
        }
        cout << *iter << ", ";
        iter = l.erase(iter);
        iter--;
    }

    cout << l.back() << ">";
    return 0;
}