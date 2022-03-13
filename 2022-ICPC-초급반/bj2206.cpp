#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;
typedef long long ll;

int N, M;
int map[1001][1001];
int visited[1001][1001][2];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
vector<pair<int, int>> cannot;

int bfs(int xIdx, int yIdx) {
	list<pair<pair<int, int>, int>> q;
	visited[xIdx][yIdx][1] = 1;
	q.push_front({ { xIdx, yIdx }, 1 });

	while (!q.empty()) {
		//int count = 0;
		pair<pair<int, int>, int> tmp = q.back(); q.pop_back();
		int x = tmp.first.first, y = tmp.first.second, block = tmp.second;

		if (x == N && y == M) return visited[x][y][block];

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];

			if (nx < 1 || ny < 1 || nx > N || ny > M) {
				continue;
			}

			if (map[nx][ny] == 1 && block) {
				visited[nx][ny][block - 1] = visited[x][y][block] + 1;
				q.push_front({ {nx,ny}, block - 1 });
			}

			if (map[nx][ny] == 0 && visited[nx][ny][block] == 0) {
				visited[nx][ny][block] = visited[x][y][block] + 1;
				q.push_front({ {nx,ny},block });
			}
		}
	}

	return -1;
}

int main(void) {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	cout << bfs(1, 1);

}