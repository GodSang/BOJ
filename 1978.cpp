/*�����佺�׳׽��� ü�� �̿��� �Ҽ� ã�� ���α׷�
	���� ��ũ
	https://marobiana.tistory.com/91
	*/

#include <iostream>

using namespace std;

#define MAX 100000
int num[MAX + 1] = { 0, };

int main() {
	int cnt = 0;
	int n;
	int tmp;
	
	num[1] = 1;
	// 10�� ������ �Ҽ��� �ƴ� �͵��� "1"�� �ٲ�.
	for (int i = 2; i <= MAX; i++) {
		for (int j = 2; j <= MAX/2; j++) {
			if (i * j <= MAX) {
				num[i * j] = 1;
			}
			else
				break;
		}
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (num[tmp] != 1)
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}