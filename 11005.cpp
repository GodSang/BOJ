/*Stack 써서 진법 변환 구현 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>

using namespace std;

int main() {
	long long n;
	int b;
	int q, r;
    int num;
	char c;
	int size;
	stack<int> s;
	
	cin >> n >> b;
	q = n;
	while (true) {
		r = q % b;
		q = q / b;
		s.push(r);
		if (q < b) {
			if(q != 0)
				s.push(q);
			break;
		}
	}
	size = s.size();
	for (int i = 0; i < size; i++) {
		num = s.top();
		s.pop();
		if (num >= 10) {
			c = char(num + 55);
			cout << c;
		}
		else {
			cout << num;
		}
	}



}