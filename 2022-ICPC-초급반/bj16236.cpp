#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>

using namespace std;
typedef long long ll;

int N;
int map[21][21];
int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };

struct fish {
	int y, x, dist;
	bool operator<(const fish& b) const {
		if (dist == b.dist) {
			if (y == b.y)
				return x > b.x;
			return y > b.y;
		}
		return dist > b.dist;
	}
};

queue<fish> shark;

int bfs() {
	int t = 0, eat = 0, sharkSize = 2;

	while (true) {
		priority_queue<fish> feed;
		vector<vector<bool>> visited(N, vector<bool>(N));
		//int visited[21][21];

		while (!shark.empty()) {
			fish tmp = shark.front();
			shark.pop();

			for (int i = 0; i < 4; i++) {
				int nx = tmp.x + dx[i], ny = tmp.y + dy[i];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				if (visited[ny][nx] || map[ny][nx] > sharkSize) continue;

				visited[ny][nx] = true;
				shark.push({ ny, nx, tmp.dist + 1 });
				if (map[ny][nx] < sharkSize && map[ny][nx] != 0)
					feed.push({ ny, nx, tmp.dist + 1 });
			}
		}

		if (feed.empty()) break;

		fish selected = feed.top();
		int feedX = selected.x, feedY = selected.y, feedSize = map[feedY][feedX];

		if (++eat == sharkSize) {
			eat = 0;
			sharkSize++;
		}

		map[feedY][feedX] = 0;
		shark.push({ feedY, feedX, 0 });

		t += selected.dist;
	}

	return t;

}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				map[i][j] = 0;
				shark.push({ i,j,0 });
			}
		}
	}

	cout << bfs() << endl;
	return 0;
}