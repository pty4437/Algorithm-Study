#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;

int M, N;
int visited[1001][1001], map[1001][1001], dist[1001][1001];
//int map[1001][1001], dist[1001][1001];
list<pair<int, int>> q;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs() {
	while (!q.empty()) {
		pair<int, int> cur = q.back(); q.pop_back();

		int x = cur.first, y = cur.second;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (visited[nx][ny] || map[nx][ny] == -1) continue;

			dist[nx][ny] = dist[x][y] + 1;

			q.push_front({ nx, ny });
			visited[nx][ny] = 1;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];

			if (map[i][j] == 1) {
				q.push_back({ i,j });
				visited[i][j] = 1;
			}
		}
	}

	bfs();

	int res = 0;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == -1)
				continue;

			if (map[i][j] == 0 && dist[i][j] == 0) {
				cout << -1;
				return 0;
			}

			res = max(res, dist[i][j]);
		}
	}

	cout << res;
}