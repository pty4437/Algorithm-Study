#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>

using namespace std;
typedef long long ll;

#define inf 1e9

int T, n, m;
int dist[21], visited[21], pre[21];

ll dijkstra(int start, int goal, vector<pair<int, int>> adj[]) {
	fill(dist, dist + 21, inf);
	fill(visited, visited + 21, 0);
	fill(pre, pre + 21, 0);

	priority_queue<pair<int, int>> pq;
	dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cur = pq.top().second; pq.pop();
		if (visited[cur]) continue;

		visited[cur] = 1;
		for (pair<int, int> u : adj[cur]) {
			int next = u.first, cost = u.second;
			int next_dist = dist[cur] + cost;
			if (dist[next] > next_dist) {
				dist[next] = next_dist;
				pre[next] = cur;
				pq.push({ -next_dist, next });
			}
		}
	}

	return dist[goal];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for(int s = 1; s <= T; s++){
		vector<pair<int, int>> adj[21];

		cin >> n >> m;

		int a, b, c;

		while (n--) {
			cin >> a >> b >> c;
			adj[a].push_back({ b,c });
			adj[b].push_back({ a,c });
		}

		ll res = dijkstra(0, m-1, adj);

		cout << "Case #" << s << ": ";

		if (res == 1e9) {
			cout << -1 << "\n";
			continue;
		}

		vector<int> route;

		route.push_back(m-1);

		int tmp = m-1;

		while (true) {
			tmp = pre[tmp];
			route.push_back(tmp);

			if (tmp == 0)
				break;
		}


		for (int i = route.size() - 1; i >= 0; i--)
			cout << route[i] << " ";

		cout << "\n";
	}
}