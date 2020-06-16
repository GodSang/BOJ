#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	int str_size, stk_size;
	string str;
	stack<int> s;
	int r, q;
	int temp;

	cin >> str;
	if (str == "0") {
		cout << '0';
		return 0;
	}
	str_size = str.size();

	for (int i = 0; i < str_size; i++) {
		q = str[i] - '0';
		while (true) {
			r = q % 2;
			q = q / 2;
			s.push(r);
			if (q == 0)
				break;
			else if (q < 2) {
			s.push(q);
			break;
			}
		}
		stk_size = s.size();
		
		if (stk_size == 2 && i != 0)
			cout << '0';
		else if (stk_size == 1 && i != 0) {
			cout << '0';
			cout << '0';
		}

		for (int j = 0; j < stk_size; j++) {
			cout << s.top();
			s.pop();
		}
	}
	return 0;
}