#include <iostream>
#include <queue>

#define MAX 1001
int a[MAX][MAX] = { 0 , };
int check[MAX] = { 0, };
int n, m;

using namespace std;

void bfs(int start) {

	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		start = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (check[i] == 1 || a[start][i] == 0)
				continue;
			q.push(i);
			check[i] = 1;
		}
	}
}

int main() {

	int u, v;	// 간선의 양 끝점
	int cnt = 0;
	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		cin >> u >> v;
		a[u][v] = a[v][u] = 1;
	}

	for (int i = 1; i <= n; i++) {
		if (check[i] == 0) {
			bfs(i);
			cnt++;
		}
	}
	cout << cnt << '\n';

	return 0;
}