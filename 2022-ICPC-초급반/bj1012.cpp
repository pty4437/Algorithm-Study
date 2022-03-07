#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
typedef long long ll;

int T, M, N, K, a, b;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int arr[51][51];

void bfs(int row, int col) {
	list<pair<int, int>> q;
	q.push_front({ row, col });

	while (!q.empty()) {
		pair<int, int> tmp = q.back(); q.pop_back();
		int x = tmp.first, y = tmp.second;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];

			if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
			if (arr[nx][ny] == 0) continue;

			q.push_front({ nx, ny });
			//visited[nx][ny] = 1;
			arr[nx][ny] = 0;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	while (T--) {
		int cnt = 0;
		cin >> M >> N >> K;

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				arr[i][j] = 0;
			}
		}

		for (int i = 0; i < K; i++) {
			cin >> a >> b;
			arr[a][b] = 1;
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == 1) {
					bfs(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << "\n";
	}
}