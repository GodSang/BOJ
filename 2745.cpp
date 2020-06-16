#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	
	vector<int> v;
	string s;
	int n;
	int str_size;
	int num;
	long long sum = 0;

	cin >> s >> n;
	str_size = s.size();

	for (int i = 0; i < str_size; i++) {
		if (s[i] >= 'A') {
			v.push_back(s[i] - 55);
		}
		else if(s[i] <= '9') {
			v.push_back(s[i] - '0');
		}
	}

	for (int i = 0; i < str_size; i++) {
		num = v.back();
		v.pop_back();
		sum += num * pow(n, i);
	}
	cout << sum << '\n';

	
	return 0;
}