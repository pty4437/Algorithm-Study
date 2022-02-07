#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;

int N, M, T, swordX, swordY, res;
int map[101][101], visited[101][101], dist[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs(int curX, int curY) {
	list<pair<int, int>> q;
	q.push_front({ curX, curY });
	visited[curX][curY] = 1;

	while (!q.empty()) {
		pair<int, int>cur = q.back(); q.pop_back();

		int x = cur.first, y = cur.second;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (visited[nx][ny] || map[nx][ny] == 1) continue;

			q.push_front({ nx, ny });
			visited[nx][ny] = 1;
			dist[nx][ny] = dist[x][y] + 1;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> T;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				swordX = i; swordY = j;
			}
		}
	}

	bfs(0, 0);

	int swordDis = 9999999999;

	if (dist[swordX][swordY] != 0) {
		swordDis = dist[swordX][swordY] + ((N - 1) - swordX) + ((M - 1) - swordY);
	}

	if (dist[N - 1][M - 1] == 0 && swordDis < 9999999999)
		res = swordDis;
	else if (dist[N - 1][M - 1] > 0) {
		res = min(swordDis, dist[N - 1][M - 1]);
	}
	else
		res = -1;

	if (res == -1 || res > T)
		cout << "Fail";
	else
		cout << res;
}