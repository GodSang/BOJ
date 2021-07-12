#include <iostream>
#include <list>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i<n ; i++) {
        list<char> password;
        string str;
    
        list<char>::iterator cursor = password.begin();
        cin >> str;

        for(int j = 0; j < str.size() ; j++) {
            if(str.at(j) == '<') {
                if(cursor != password.begin())
                    cursor--;
            }
            else if(str.at(j) == '>') {
                if(cursor != password.end()){
                    cursor++;
                }
            }
            else if(str.at(j) == '-') {
                if(cursor != password.begin()){
                    cursor--;
                    cursor = password.erase(cursor);
                }
            }
            else {
                password.insert(cursor, str.at(j));
            }
        }

        for (list<char>::iterator iter = password.begin() ; iter != password.end() ; iter++) {
            cout << *iter;
        }
        cout << '\n';
    }
    return 0 ;
}