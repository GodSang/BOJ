/*에라토스테네스의 체를 이용한 소수 찾는 프로그램
	참고 링크
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
	// 10만 까지의 소수가 아닌 것들을 "1"로 바꿈.
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