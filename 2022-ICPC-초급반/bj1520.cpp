#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
typedef long long ll;

int N, M;
int Map[501][501], dp[501][501];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0, 0, 1, -1 };

//int visited[501][501];

int dfs(int x, int y) {
	if (x == N - 1 && y == M - 1) return 1;
	if (dp[x][y] != -1) return dp[x][y];
	
	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
			if (Map[nx][ny] < Map[x][y])
				dp[x][y] += dfs(nx, ny);
		}
	}

	return dp[x][y];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
			dp[i][j] = -1;
		}

	cout << dfs(0, 0);
}