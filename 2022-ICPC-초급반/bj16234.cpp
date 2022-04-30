#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;
typedef long long ll;

int N, L, R, cnt = 0;
int map[51][51], visited[51][51];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };

int bfs(int iX, int iY, int visited_flag) {
	int road = 1;
	double Psum = 0;
	list<pair<int, int>> q;
	q.push_front({ iX, iY });
	visited[iX][iY] = visited_flag;
	Psum += map[iX][iY];

	while (!q.empty()) {
		pair<int, int> tmp = q.back(); q.pop_back();
		int x = tmp.first, y = tmp.second;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (visited[nx][ny] > 0) continue;

			int people = map[x][y] - map[nx][ny];
			if (people < 0) people *= -1;

			if (people < L || people > R) continue;

			q.push_front({ nx, ny });
			visited[nx][ny] = visited_flag;
			road++;
			Psum += map[nx][ny];
			
		}

	}

	if (road == 1)
		return 0;
	else {
		int new_people = Psum / road;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] == visited_flag) map[i][j] = new_people;
			}
		}

		return road;
	}

}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> L >> R;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	while (true) {
		int visited_flag = 1;
		bool flag = false;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				visited[i][j] = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					if (bfs(i, j, visited_flag) > 0) {
						flag = true;
					}
					visited_flag++;
				}
			}
		}

		if (flag == true)
			cnt++;
		else
			break;

	}

	cout << cnt;

}