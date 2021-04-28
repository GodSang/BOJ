#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define MAX 10000000

using namespace std;

int num[MAX + 1] = { 0, };

int main() {
	
	int n;
	int q = 2;

	cin >> n;

	num[1] = 1;
	for (int i = 2; i*i <= n; i++) {
		if (num[i] == 0) {
			for (int j = i*i; j <= n; j += i) {
				num[j] = 1;
			}
		}
	}
	for (int i = 2; i <= n ; i++) {
		if (num[i] == 0) {
			if (n % i == 0) {
				printf("%d\n", i);
				n = n / i;
				i--;
			}
		}
	}

	return 0;
}