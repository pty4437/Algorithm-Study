#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <list>

using namespace std;
typedef long long ll;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int n, ans = 0, ans2 = 0;
char arr[107][107], enter;
int visited[107][107] = { 0 };

void bfs(int startX, int startY) {
	list<pair<int, int>> q;
	q.push_front({ startX, startY });
	visited[startX][startY] = 1;

	while (!q.empty()) {
		pair<int, int> cur = q.back(); q.pop_back();
		int x = cur.first, y = cur.second;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if (visited[nx][ny]) continue;
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (arr[nx][ny] != arr[x][y]) continue;

			visited[nx][ny] = 1;
			q.push_front({ nx,ny });
			
	
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	scanf("%c", &enter);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%c", &arr[i][j]);
		}

		scanf("%c", &enter);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				bfs(i, j);
				ans++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 'G')
				arr[i][j] = 'R';
		}
	}

	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				bfs(i, j);
				ans2++;
			}
		}
	}

	cout << ans << " " << ans2 << "\n";

	return 0;
}