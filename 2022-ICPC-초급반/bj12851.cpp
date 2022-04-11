#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;
typedef long long ll;

int N, K;
int res_route = 987654321, res = 0;
int visited[100002];

void bfs() {
	list<pair<int, int>> q;
	q.push_front({ N, 0 });
	visited[N] = 1;

	while (!q.empty()) {
		pair<int, int> tmp = q.back(); q.pop_back();

		visited[tmp.first] = 1;

		if (tmp.first == K) {

			if (res_route > tmp.second) {
				res = 1;
				res_route = tmp.second;
			}
			else if (res_route == tmp.second) {
				res++;
			}

			continue;
		}

		int plus = tmp.first + 1, minus = tmp.first - 1, sungan = tmp.first * 2;
		int route = tmp.second;

		if (route < res_route) {
			if (sungan == K || (sungan <= K + 1 && !visited[sungan])) {
				q.push_front({ sungan, route + 1 });
			}
			if (minus == K || (minus >= 0 && !visited[minus])) {
				q.push_front({ minus, route + 1 });
			}
			if (plus == K || (plus <= K && !visited[plus])) {
				q.push_front({ plus, route + 1 });
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	bfs();

	cout << res_route << endl;
	cout << res << endl;
}