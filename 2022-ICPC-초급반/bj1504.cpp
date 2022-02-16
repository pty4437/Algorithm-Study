#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
typedef long long ll;

int N, E, a, b, c, v1, v2, INF = 999999999;
vector<pair<int, int>> adj[801];
int dist[801], visited[801];

int dijkstra(int start, int goal) {
	fill(dist, dist + 801, INF);
	fill(visited, visited + 801, 0);
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
				pq.push({ -next_dist, next });
			}
		}
	}

	return dist[goal];
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;

		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}

	cin >> v1 >> v2;

	int res1, res2, res3, res4, res5, res6;

	res1 = dijkstra(1, v1); res4 = dist[v2];
	res2 = dijkstra(v1, v2); res6 = dist[N];
	res3 = dijkstra(v2, N); res5 = dist[v1];

	if (res1 == INF || res2 == INF || res3 == INF) {
		if(res4 == INF || res5 == INF || res6 == INF)
			cout << -1;
	}
	else
		cout << min(res1 + res2 + res3, res4 + res5 + res6);
}