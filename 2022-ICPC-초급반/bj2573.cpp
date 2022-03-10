#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>

using namespace std;
typedef long long ll;

int N, M, res = 0, cnt = 0, tmp = 0;
int arr[301][301];
int visited[301][301];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool flag;

void bfs(int xIdx, int yIdx) {
	list<pair<int, int>> q;
	q.push_front({ xIdx, yIdx });
	visited[xIdx][yIdx] = 1;

	while (!q.empty()) {
		pair<int, int> t = q.back(); q.pop_back();
		int x = t.first, y = t.second;

		for (int k = 0; k < 4; k++) {
			int cx = x + dx[k], cy = y + dy[k];

			if (cx < 0 || cy < 0 || cx >= N || cy >= M) continue;
			if (visited[cx][cy] || !arr[cx][cy]) continue;

			visited[cx][cy] = 1;
			q.push_front({ cx, cy });
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 0;
			cin >> arr[i][j];
		}
	}

	while (true) {
		flag = true;
		vector<pair<pair<int, int>, int>> v;
		cnt = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] > 0 && visited[i][j] == 0) {
					flag = false;
					bfs(i, j);
					cnt++;
				}
			}
		}

		if (flag == false && cnt > 1) {
			cout << res;
			break;
		}
		else if (flag == true) {
			cout << 0;
			break;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				visited[i][j] = 0;

				if (arr[i][j]) {
					tmp = 0;
					for (int k = 0; k < 4; k++) {
						int tmpI = i + dx[k], tmpJ = j + dy[k];

						if (tmpI < 0 || tmpJ < 0 || tmpI >= N || tmpJ >= M) continue;
						if (!arr[tmpI][tmpJ]) tmp++;
					}

					v.push_back({ { i, j }, tmp });
				}
			}
		}

		for (int i = 0; i < v.size(); i++) {
			pair<int, int> dot = v[i].first;
			arr[dot.first][dot.second] -= v[i].second;

			if (arr[dot.first][dot.second] < 0)
				arr[dot.first][dot.second] = 0;
		}

		res++;
	}

	return 0;
}