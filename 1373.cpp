#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {

	vector<int> v;
	string s;
	int str_size;
	int r;
	long long sum = 0;

	cin >> s;
	str_size = s.size();
	r = str_size % 3;

	if (r == 1) {
		v.push_back(0);
		v.push_back(0);
	}
	else if (r == 2) {
		v.push_back(0);
	}

	for (int i = 0; i < str_size; i++) {
		v.push_back(s[i] - '0');
	}

	for (int i = 0; i < str_size; i+=3) {
		cout << v[i] * 4 + v[i + 1] * 2 + v[i + 2];
	}
	
	cout << '\n';



	return 0;
}