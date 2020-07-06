/* bfs또는 dfs를 사용해 이분 그래프 판별해내는 문제
코드 참고 : https://data-make.tistory.com/439
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 20001

int n, m;	// 정점과 간선의 개수
int colorArr[MAX];
int color = 1;

bool bfs() {
	int u, v;

	// 테스트 케이스 마다 초기화 해주기 위해 함수 안에 선언.
	queue<int> q;
	vector<vector<int>> a(n + 1);
	vector<int> check(n + 1);

	for (int i = 1; i <= m; i++) {	// 연결 정보 넣기
		cin >> u >> v;	
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {	// 연결 그래프가 아닐 경우도 따져주기 위함.
		if (check[i]) continue;

		q.push(i);
		check[i] = 1;

		while (!q.empty()) {
			int start = q.front();
			q.pop();
			for (int j = 0; j < a[start].size(); j++) {
				if (check[a[start][j]] == 0) {
					// 연결 된 노드를 1과 -1로 색깔 구분
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