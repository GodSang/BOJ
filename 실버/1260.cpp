/*	DFS�� BFS, DFS�� ����,��� ���/ BFS�� ť ���
	���� ��ũ
	DFS, BFS���� ���� : https://mygumi.tistory.com/102
	queue �Լ� ���� : https://blockdmask.tistory.com/101
	���� �ڵ� ���� : https://yongku.tistory.com/entry/%EB%B0%B1%EC%A4%80-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98BOJ-1260%EB%B2%88-DFS%EC%99%80-BFSC
*/
#include <iostream>
#include <queue>

using namespace std;

#define MAX 1001

int n, m;	// n�� ������ ����, m�� ������ ����
int a[MAX][MAX];	// ���� ���
int check[MAX];		// �湮�� �������� ����ϴ� �迭

void dfs(int start) {
	check[start] = 1;	// ���� ������ �湮 �ߴٴ� ������ 1 ����
	cout << start << " ";
	for (int i = 1; i <= n; i++) {
		if (check[i] == 1 || a[start][i] == 0) continue;	// �̹� �湮�߰ų�, ������ ������� Skip
		dfs(i);
	}
}

void bfs(int start) {
	queue<int> q;
	check[start] = 0;	// dfs���� ����� �迭�� �ݴ�� ���.
	q.push(start);

	while (!q.empty()) {
		start = q.front();
		cout << start << " ";
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (check[i] == 0 || a[start][i] == 0) continue;
			q.push(i);
			check[i] = 0;
		}
	}
}

int main() {

	int start;
	int x, y;
	cin >> n >> m >> start;

	for (int i = 0; i < m; i++) {	// ���� �Է� �޾Ƽ� ������� 1�� �ٲٱ�
		cin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}
	dfs(start);
	cout << '\n';
	bfs(start);

	return 0;
}