#include <iostream>
#include <string>

    using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    string word1, word2;
    cin >> n;
    for(int i=0;i<n;i++) {
        int arr1[26] = {0,};
        int arr2[26] = {0,};
        int flag=0;
        cin >> word1 >> word2;
        for(auto e : word1) {
            arr1[e-97]++;
        }
        for(auto e : word2) {
            arr2[e-97]++;
        }
        for(int j=0 ; j<26 ; j++) {
            if(arr1[j] != arr2[j]) {
                flag++;
                break;
            }
        }
        if(flag == 1) {
            cout << "Impossible" << "\n";
        }else {
            cout << "Possible" << "\n";
        }
    }

    return 0;
}