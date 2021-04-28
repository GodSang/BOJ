/* 유클리드 호제법 사용
   참고 링크
   http://blog.naver.com/PostView.nhn?blogId=kmc7468&logNo=221017936040&categoryNo=413&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=postView
   */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <list>
#include <vector>

using namespace std;


int main() {

	long long gcd = 0;
	long long a, b, c;

	cin >> a >> b;

	while (true) {
		c = a % b;
		if (c != 0) {
			a = b;
			b = c;
		}
		else {
			gcd = b;
			for (int i = 0; i < b; i++) {
				printf("1");
			}
			printf("\n");
			break;
		}
	}

	return 0;
}