#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;

int N, res = 0;
int map[30][30], visited[30][30];
vector<int> v;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs(int curX, int curY) {
	list<pair<int, int>> q;
	int width = 1;

	q.push_front({ curX, curY });
	visited[curX][curY] = 1;

	while (!q.empty()) {
		pair<int, int>cur = q.back(); q.pop_back();

		int x = cur.first, y = cur.second;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (visited[nx][ny] || !map[nx][ny]) continue;

			width++;
			q.push_front({ nx, ny });
			visited[nx][ny] = 1;
		}
	}

	v.push_back(width);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	string str;

	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			
			visited[i][j] = 0;

			if (str[j] == '1')
				map[i][j] = 1;
			else
				map[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && map[i][j]) {
				bfs(i, j);
				res++;
			}
		}
	}

	cout << res << "\n";

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";

	return 0;
}