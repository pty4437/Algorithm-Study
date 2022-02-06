#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <list>

using namespace std;
typedef long long ll;

int n, m, startX, startY;
int map[1001][1001], visited[1001][1001], range[1001][1001];
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

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visited[nx][ny] || !map[nx][ny]) continue;

			range[nx][ny] = range[x][y] + 1;
			visited[nx][ny] = 1;
			q.push_front({ nx,ny });
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];

			if (map[i][j] == 2) {
				startX = i; startY = j;
			}
		}
	}

	bfs(startX, startY);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (range[i][j] == 0 && map[i][j] == 1)
				cout << -1 << " ";
			else
				cout << range[i][j] << " ";
		}

		cout << "\n";
	}
}