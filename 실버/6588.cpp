/*	골드바흐의 추측 증명 프로그램
	참고 링크
	시간단축 : https://www.acmicpc.net/board/view/44906
	제곱근 까지인 이유와 설명 : https://redcoder.tistory.com/48
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

#define MAX 1000000
int num[MAX + 1] = { 0, };

int main() {
	int cnt = 0;
	int n;
	int a = 0;
	int one=0, two=0;
	int stop = 0;

	// 100만 까지의 소수가 아닌 것들을 "1"로 바꿈.
	// 100만 까지라서 100만번이 아닌 제곱근 까지만 확인해줘도 됨
	for (int i = 2; i <= 1000; i++) {
		if (num[i] == 0) {
			for (int j = i * i; j <= MAX; j += i) {
				num[j] = 1;
			}
		}
	}
	while (true) {
		scanf("%d", &n);

		if (n == 0)
			break;

		for (int i = 2; i < n; i++) {
			if (num[i] == 0) {
				for (int j = 2; j < n; j++) {
					if (num[j] == 0) {
						if (num[n - j] == 0) {
							stop = 1;
							printf("%d = %d + %d\n", n, j, n-j );
							break;
						}
					}
				}
			}
			if (stop) {
				stop = 0;
				break;
			}
		}

	}

	return 0;
}