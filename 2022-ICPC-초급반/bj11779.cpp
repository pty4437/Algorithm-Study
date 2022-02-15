#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>

using namespace std;
typedef long long ll;

#define inf 1e9

int n, m, startP, endP;
vector<pair<int, int>> adj[1001];
int dist[1001], visited[1001], pre[1001];

int dijkstra(int start, int goal) {
	fill(dist, dist + 1001, inf);
	fill(visited, visited + 1001, 0);

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

	cin >> n;
	cin >> m;

	int a, b, c;

	while (m--) {
		cin >> a >> b >> c;

		adj[a].push_back({ b,c });
	}

	cin >> startP >> endP;

	cout << dijkstra(startP, endP) << endl;

	vector<int> route;

	route.push_back(endP);

	int tmp = endP;

	while (true) {
		tmp = pre[tmp];

		if (tmp == 0)
			break;

		route.push_back(tmp);
	}

	cout << route.size() << endl;

	for (int i = route.size() - 1; i >= 0; i--)
		cout << route[i] << " ";
}