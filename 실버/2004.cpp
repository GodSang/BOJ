/* ���� 0�� ����
	���� ��ũ
	������ ���� ���� : https://suhak.tistory.com/2
	���� ī���� ���� : https://www.geeksforgeeks.org/count-trailing-zeroes-factorial-number/
	���� ������ : https://dojang.io/mod/page/view.php?id=145

	�ݷ� : 5C1 �� 2�� ������ 5�� �������� ���� �͵� (�����ֱ� ������ �߻�. 
			�Ϲ������� 0 ���� ���� ������ 5�� ī�����ص� ���� ���� ex. 1676.cpp
	*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

	// 5 ���� ī����
int fiveCount(int tmp) {
	int cnt = 0;
	for (long long i = 5; tmp / i >= 1; i *= 5)
		cnt += tmp / i;
	return cnt;
}
	// 2 ���� ī����
int twoCount(int tmp) {
	int cnt = 0;
	for (long long i = 2; tmp / i >= 1; i *= 2)
		cnt += tmp / i;
	return cnt;
}

// nCm = n! / m!*(n-m)!
int main() {
	int n, m;
	int fcnt, tcnt;
	int cnt;

	cin >> n >> m;

	if (n == m || m == 0) {	// ����ó��
		cout << 0;
		return 0;
	}

	fcnt = fiveCount(n) - fiveCount(n - m) - fiveCount(m);
	tcnt = twoCount(n) - twoCount(n - m) - twoCount(m);
	cnt = fcnt > tcnt ? tcnt : fcnt;	// 5�� ������ 2�� ���� �� ���� ���� ����(5*2 = 10)
	cout << cnt << "\n";
	
	return 0;
}