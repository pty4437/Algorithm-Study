#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

int n, m, a, b, c, inf = 999999999, negative_cycle = 0;
vector<pair<int, int>> adj[101];
vector<int> rev[101];
int dist[101], pre[101], tmp;
bool visit[101] = { false, };

void bellman_ford(int start, int goal) {
	for (int i = 1; i <= n; i++) {
		dist[i] = inf;
	}

	dist[start] = 0;

	for (int iter = 1; iter <= n; iter++) {
		for (int cur = 1; cur <= n; cur++) {
			for (pair<int, int> E : adj[cur]) {
				int next = E.first, cost = E.second;
				if (dist[cur] != inf && dist[next] > dist[cur] + cost) {
					dist[next] = dist[cur] + cost;
					pre[next] = cur;

					if (iter == n && visit[next]) { negative_cycle = 1; }
				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;

		adj[a].push_back({ b,-c });
		rev[b].push_back(a);
	}

	queue<int> q;
	visit[n] = true;
	q.push(n);

	while (!q.empty()) {
		int cidx = q.front();
		q.pop();
		for (int i = 0; i < rev[cidx].size(); i++) {
			int next = rev[cidx][i];
			if (!visit[next]) {
				visit[next] = true;
				q.push(next);
			}
		}
	}

	bellman_ford(1, n);

	if (negative_cycle) {
		cout << -1;
		return 0;
	}

	vector<int> road;

	int idx = n;
	road.push_back(n);

	while (true) {
		if (pre[idx] == 0)
			break;

		road.push_back(pre[idx]);
		idx = pre[idx];
	}

	for (int i = road.size() - 1; i >= 0; i--)
		cout << road[i] << " ";
}