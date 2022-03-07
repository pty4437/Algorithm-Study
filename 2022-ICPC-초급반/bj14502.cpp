#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;
typedef long long ll;

int N, M, whole = 0, cnt = 0, res = 0;
int map[8][8], visited[8][8];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

vector<pair<int, int>> virus;
vector<pair<int, int>> road;

void bfs(int xIdx, int yIdx) {
	list<pair<int, int>> q;
	q.push_front({ xIdx, yIdx });
	visited[xIdx][yIdx] = 1;

	while (!q.empty()) {
		pair<int, int> tmp = q.back(); q.pop_back();
		int x = tmp.first, y = tmp.second;
		cnt++;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (map[nx][ny] == 1 || visited[nx][ny] == 1 || map[nx][ny] == 2) continue;

			q.push_front({ nx, ny });
			visited[nx][ny] = 1;
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

			if (map[i][j] == 2) {
				virus.push_back({ i,j });
				whole++;
			}
			if (map[i][j] == 0) {
				whole++;
				road.push_back({ i,j });
			}
		}
	}

	whole -= 3;

		for (int i = 0; i < road.size(); i++) {
			for (int j = i + 1; j < road.size(); j++) {
				for (int k = j + 1; k < road.size(); k++) {
					int x1 = road[i].first, x2 = road[j].first, x3 = road[k].first;
					int y1 = road[i].second, y2 = road[j].second, y3 = road[k].second;

					map[x1][y1] = 1; map[x2][y2] = 1; map[x3][y3] = 1;

					for (int x = 0; x < N; x++)
						for (int y = 0; y < M; y++)
								visited[x][y] = 0;

					for (int vIdx = 0; vIdx < virus.size(); vIdx++) {
						bfs(virus[vIdx].first, virus[vIdx].second);
					}

					res = max(res, whole - cnt);
					cnt = 0;

					map[x1][y1] = 0; map[x2][y2] = 0; map[x3][y3] = 0;
				}
			}
		}

	cout << res;
}
