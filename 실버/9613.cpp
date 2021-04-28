#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	while (true) {
		int c = a % b;
		if (c != 0) {
			a = b;
			b = c;
		}
		else {
			return b;
		}
	}
}

int main() {
	int t, n, num, c;
	long long sum = 0;
	vector<int> vec;
	
	cin >> t;
	for (int i = 0; i < t; i++) {	// 테스트케이스 만큼 반복
		cin >> n;
		for (int j = 0; j < n; j++) {	// n 만큼의 숫자 vector에 입력
			cin >> num;
			vec.push_back(num);
		}
		
		for (int k = 0; k < n; k++) {
			for (int l = k + 1; l < n; l++) {
				sum += gcd(vec[k], vec[l]);
			}
		}
		cout << sum << '\n';
		sum = 0;
		vec.clear();
	}
	return 0;
}