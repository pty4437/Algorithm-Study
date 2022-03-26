#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;
typedef long long ll;

int M, N;
int arr[1001][1001];
int visited[1001][1001];

int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };

void bfs(int xIdx, int yIdx) {
	list<pair<int, int>> q;
	q.push_front({ xIdx, yIdx });
	visited[xIdx][yIdx] = 1;

	while (!q.empty()) {
		pair<int, int> tmp = q.back(); q.pop_back();
		int x = tmp.first, y = tmp.second;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (visited[nx][ny] || arr[nx][ny]) continue;

			q.push_front({ nx, ny });
			visited[nx][ny] = 1;
		}
	}
}

int main(void) {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	for (int i = 0; i < M; i++) {
		if (!visited[0][i] && !arr[0][i])
			bfs(0, i);
	}

	for (int i = 0; i < M; i++) {
		if (visited[N - 1][i] && !arr[N - 1][i]) {
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";
	return 0;
}