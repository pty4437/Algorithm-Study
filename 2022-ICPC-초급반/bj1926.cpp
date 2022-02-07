#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;

int map[501][501], visited[501][501];
int n, m, res = 0;
vector<int> width;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs(int curX, int curY) {
	list<pair<int, int>> q;
	q.push_front({ curX, curY });
	visited[curX][curY] = 1;
	int tmp = 0;

	while (!q.empty()) {
		pair<int, int> cur = q.back(); q.pop_back();
		tmp++;

		int x = cur.first, y = cur.second;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visited[nx][ny] || !map[nx][ny]) continue;

			q.push_front({ nx,ny }); visited[nx][ny] = 1;
		}
	}

	width.push_back(tmp);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] && !visited[i][j]) {
				bfs(i, j); res++;
			}
		}
	}

	cout << res << endl;

	sort(width.begin(), width.end());

	if (!width.empty())
		cout << width[width.size() - 1] << endl;
	else
		cout << 0;
}