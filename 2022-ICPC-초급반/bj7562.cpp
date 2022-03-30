#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
typedef long long ll;

int T,l, nowX, nowY, desX, desY;
int visited[301][301];

int dx[8] = { -1,-2,-2,-1,1,2,2,1 };
int dy[8] = { -2,-1,1,2,-2,-1,1,2 };

void bfs(int iX, int iY) {
	list<pair<int, int>> q;
	q.push_front({ iX, iY });
	visited[iX][iY] = 1;

	while (!q.empty()) {
		pair<int, int> tmp = q.back(); q.pop_back();
		int x = tmp.first, y = tmp.second;

		if (x == desX && y == desY) break;

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i], ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= l || ny >= l) continue;
			if (visited[nx][ny]) continue;

			q.push_front({ nx,ny });
			visited[nx][ny] = visited[x][y] + 1;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> l;
		cin >> nowX >> nowY;
		cin >> desX >> desY;

		for (int i = 0; i < l; i++)
			for (int j = 0; j < l; j++)
				visited[i][j] = 0;

		bfs(nowX, nowY);

		cout << visited[desX][desY]-1 << "\n";
	}
}