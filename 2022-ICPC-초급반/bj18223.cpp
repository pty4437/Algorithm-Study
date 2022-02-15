#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>

using namespace std;
typedef long long ll;

#define inf 1e9

int V, E, P;
int dist[5001], visited[5001];
vector<pair<int, int>> adj[5001];

int dijkstra(int start, int goal) {
	fill(dist, dist + 5001, inf);
	fill(visited, visited + 5001, 0);

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

	cin >> V >> E >> P;

	int a, b, c;

	while (E--) {
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}

	int res = dijkstra(1, V);
	int res2 = dijkstra(1, P) + dijkstra(P, V);

	if (res < res2)
		cout << "GOOD BYE";
	else
		cout << "SAVE HIM";
	
}