/* 조합 0의 개수
	참고 링크
	순열과 조합 설명 : https://suhak.tistory.com/2
	개수 카운팅 설명 : https://www.geeksforgeeks.org/count-trailing-zeroes-factorial-number/
	삼항 연산자 : https://dojang.io/mod/page/view.php?id=145

	반례 : 5C1 등 2의 개수가 5의 개수보다 적은 것들 (나눠주기 때문에 발생. 
			일반적으로 0 개수 세는 문제는 5만 카운팅해도 문제 없음 ex. 1676.cpp
	*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

	// 5 개수 카운팅
int fiveCount(int tmp) {
	int cnt = 0;
	for (long long i = 5; tmp / i >= 1; i *= 5)
		cnt += tmp / i;
	return cnt;
}
	// 2 개수 카운팅
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

	if (n == m || m == 0) {	// 예외처리
		cout << 0;
		return 0;
	}

	fcnt = fiveCount(n) - fiveCount(n - m) - fiveCount(m);
	tcnt = twoCount(n) - twoCount(n - m) - twoCount(m);
	cnt = fcnt > tcnt ? tcnt : fcnt;	// 5의 개수와 2의 개수 중 작은 것을 고른다(5*2 = 10)
	cout << cnt << "\n";
	
	return 0;
}