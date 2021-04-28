/* -2진법 구현
	참고 링크 
	https://m.blog.naver.com/pjh980918/221802545735
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> vec;
	long long num, q = 0;
	int res;

	cin >> num;
	q = num;
	if (num == 0) {
		cout << '0' << '\n';
		return 0;
	}
	else if (num == 1) {
		cout << '1' << '\n';
		return 0;
	}
	else {
		while (q != 1) {
			res = q % (-2);
			q = q / (-2);

			if (res == -1) {
				q += 1;
				vec.push_back(1);
				if (q == 1)
					vec.push_back(1);
			}
			else if (res == 0) {
				vec.push_back(0);
				if (q == 1)
					vec.push_back(1);

			}
			else {	// res == 1
				vec.push_back(1);
				if (q == 1)
					vec.push_back(1);
			}
		}
		while (vec.size()) {
			cout << vec.back();
			vec.pop_back();
		}
	}
	

	return 0;
}