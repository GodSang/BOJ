/* bfs�Ǵ� dfs�� ����� �̺� �׷��� �Ǻ��س��� ����
�ڵ� ���� : https://data-make.tistory.com/439
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 20001

int n, m;	// ������ ������ ����
int colorArr[MAX];
int color = 1;

bool bfs() {
	int u, v;

	// �׽�Ʈ ���̽� ���� �ʱ�ȭ ���ֱ� ���� �Լ� �ȿ� ����.
	queue<int> q;
	vector<vector<int>> a(n + 1);
	vector<int> check(n + 1);

	for (int i = 1; i <= m; i++) {	// ���� ���� �ֱ�
		cin >> u >> v;	
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {	// ���� �׷����� �ƴ� ��쵵 �����ֱ� ����.
		if (check[i]) continue;

		q.push(i);
		check[i] = 1;

		while (!q.empty()) {
			int start = q.front();
			q.pop();
			for (int j = 0; j < a[start].size(); j++) {
				if (check[a[start][j]] == 0) {
					// ���� �� ��带 1�� -1�� ���� ����
					if (check[start] == 1) {	
						check[a[start][j]] = -1;
					}
					else {
						check[a[start][j]] = 1;
					}
					q.push(a[start][j]);
				}
				else {
					if (check[start] + check[a[start][j]] != 0) {
						return false;
					}
				}
			}
		}
	}
	return true;
}

int main() {
	int testCase;	

	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		cin >> n >> m;
		if (bfs()) cout << "YES" << '\n';
		else cout << "NO" << "\n";
	}
	return 0;
}