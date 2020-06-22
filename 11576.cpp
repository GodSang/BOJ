/*
a진법 b진법으로 변환하기
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {

	vector<int> vec1;
	int a, b;
	int n, q = 0;
	int res, num;
	int temp;
	int sq = 0;
	int sum = 0;
	int size = 0;

	cin >> a >> b >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		vec1.push_back(num);
	}

	size = vec1.size();

	for (int i = 0; i < size; i++) {
		temp = vec1.back();
		vec1.pop_back();
		sum += temp * pow(a, sq++);
	}
	q = sum;
	while (true) {
		res = q % b;
		q = q / b;
		vec1.push_back(res);
		if (q < b) {
			if (q != 0)
				vec1.push_back(q);
			break;
		}
	}
	size = vec1.size();
	for (int i = 0; i < size; i++) {
		cout << vec1.back() << " ";
		vec1.pop_back();
	}

	return 0;
}