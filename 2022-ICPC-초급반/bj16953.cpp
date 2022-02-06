#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <list>

using namespace std;
typedef long long ll;

ll A, B;
bool flag = false;

int visited[1001][1001], dist[1001][1001];
//int dx[4] = { 1, -1, 0, 0 };
//int dy[4] = { 0, 0, 1, -1 };
ll map[1001][1001];

void bfs(ll num) {
	list<pair<ll, int>> q;
	q.push_front({ num, 1 });
	//visited[curX][curY] = 1;

	while (!q.empty()) {
		pair<ll, int> cur = q.back(); q.pop_back();

		if (cur.first == B) {
			cout << cur.second;
			flag = true;
		}

		if (cur.first * 2 <= B)
			q.push_front({ cur.first * 2, cur.second + 1 });
		if (cur.first * 10 + 1 <= B)
			q.push_front({ cur.first * 10 + 1, cur.second + 1 });

	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> A >> B;

	//map[0][0] = A;

	bfs(A);

	if (flag == false)
		cout << -1;
	
	return 0;
}