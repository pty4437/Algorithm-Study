#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>
#include <queue>

using namespace std;
typedef long long ll;

const int INF = 987654321;

int V, E, K, u, v, w;
int dist[20001], visited[20001];
vector<pair<int, int>> adj[20001];

void dijkstra(int start) {
	fill(dist, dist + 20001, INF);
	priority_queue<pair<int, int>> pq;

	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int cur = pq.top().second; pq.pop();
		for (pair<int, int> tmp : adj[cur]) {
			int next = tmp.first, cost = tmp.second;
			int next_dist = dist[cur] + cost;
			if (dist[next] > next_dist) {
				dist[next] = next_dist;
				pq.push({ -next_dist, next });
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> V >> E;
	cin >> K;

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;

		adj[u].push_back({ v,w });
	}

	dijkstra(K);

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}
}