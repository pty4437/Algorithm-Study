#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;

int M, N, K;
int visited[101][101] = { 0 };
vector<int> adj[10002];
vector<int> v;
int arr[101][101] = { 1 };
ll res = 0;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs(int curX, int curY) {
	list<pair<int, int>> q;
	q.push_back({ curX, curY });
	visited[curX][curY] = 1;

	int temp = 0;

	while (!q.empty()) {
		pair<int, int> cur = q.back(); q.pop_back();
		int x = cur.first, y = cur.second;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];

			if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
			if (visited[nx][ny] || !arr[nx][ny]) continue;

			visited[nx][ny] = 1;
			q.push_front({ nx, ny });

			temp++;
		}
	}

	v.push_back(temp);
	
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> M >> N >> K;


	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = 1;
		}
	}


	int a, b, c, d;



	while (K--) {
		cin >> a >> b >> c >> d;

		for (int i = b; i < d; i++) {
			for (int j = a; j < c; j++) {
				arr[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && arr[i][j]) {
				bfs(i, j);
				res++;
			}
		}
	}

	cout << res << "\n";

	sort(v.begin(), v.end());

	for (int tmp : v)
		cout << tmp+1 << " ";
}