#include <iostream>

int main(){
    using namespace std;
    ios::sync_with_stdio(0);
    cin.tie(0);

    string word;
    int alpha[26]={0, };
    cin >> word;
    
    for(int i=0 ; i<word.size() ; i++) {
        alpha[word[i]-97]++;
    }

    for(int e : alpha)
        cout << e << ' ';

    return 0;
}