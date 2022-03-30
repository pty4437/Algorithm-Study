#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;
typedef long long ll;

int N, M, cheese = 0, bef_cheese = 0, t = 0;
int map[101][101], visited[101][101];
int dx[4] = { 1, - 1,0,0 };
int dy[4] = { 0,0,1,-1 };

int count_cheese() {
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j]) cnt++;
		}
	}

	return cnt;
}

void melt_cheese() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == -1) map[i][j] = 0;
		}
	}
}

void bfs(int startX, int startY) {
	list<pair<int, int>> q;
	q.push_front({ startX, startY });
	visited[startX][startY] = 1;

	while (!q.empty()) {
		pair<int, int>tmp = q.back(); q.pop_back();
		int x = tmp.first, y = tmp.second;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (visited[nx][ny] || map[nx][ny] == -1) continue;

			if (map[nx][ny] == 1) {
				visited[nx][ny] = 1;
				map[nx][ny] = -1;
				continue;
			}

			visited[nx][ny] = 1;
			q.push_front({ nx,ny });
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for(t = 0;;t++){
		cheese = count_cheese();

		if (cheese == 0) break;
		bef_cheese = cheese;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				visited[i][j] = 0;
			}
		}

		bfs(0, 0);

		melt_cheese();

	}

	cout << t << endl;
	cout << bef_cheese << endl;
}