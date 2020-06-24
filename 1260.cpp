/*	DFS와 BFS, DFS는 스택,재귀 사용/ BFS는 큐 사용
	참고 링크
	DFS, BFS개념 설명 : https://mygumi.tistory.com/102
	queue 함수 설명 : https://blockdmask.tistory.com/101
	구현 코드 참고 : https://yongku.tistory.com/entry/%EB%B0%B1%EC%A4%80-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98BOJ-1260%EB%B2%88-DFS%EC%99%80-BFSC
*/
#include <iostream>
#include <queue>

using namespace std;

#define MAX 1001

int n, m;	// n은 정점의 개수, m은 간선의 개수
int a[MAX][MAX];	// 인접 행렬
int check[MAX];		// 방문한 정점인지 기록하는 배열

void dfs(int start) {
	check[start] = 1;	// 현재 정점을 방문 했다는 뜻으로 1 대입
	cout << start << " ";
	for (int i = 1; i <= n; i++) {
		if (check[i] == 1 || a[start][i] == 0) continue;	// 이미 방문했거나, 간선이 없을경우 Skip
		dfs(i);
	}
}

void bfs(int start) {
	queue<int> q;
	check[start] = 0;	// dfs에서 사용한 배열을 반대로 사용.
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

	for (int i = 0; i < m; i++) {	// 간선 입력 받아서 인접행렬 1로 바꾸기
		cin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}
	dfs(start);
	cout << '\n';
	bfs(start);

	return 0;
}