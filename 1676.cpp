/*	���丮�� 0�� ����
	���� ��ũ
	https://private-space.tistory.com/6
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
	long long sum = 1;
	int n, tmp;
	int cnt = 0;

	cin >> n;

	if (n == 0) {
		cout << 0 << '\n';
		return 0;
	}


	for (int i = 1; i <= n;i++) {
		tmp = i;
		while (tmp%5 == 0) {	// 25�� 5*5, 125�� 5*5*5�̱� ����.
			cnt++;
			tmp /= 5;
		}
	}

	cout << cnt << "\n";
	return 0;
}