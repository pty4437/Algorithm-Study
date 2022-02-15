#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>

using namespace std;
typedef long long ll;

#define inf 1e9

int N, M;
char a[555][555];
int dist[303030], visited[303030];
vector<pair<int, int>> adj[303030];

int id(int i, int j) {
	return i * 555 + j;
}

void addEdge(int s, int e, int x) {
	adj[s].push_back({ e,x });
	adj[e].push_back({ s,x });
}

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

	char tmp;
	
	cin >> N >> M;

	scanf("%c", &tmp);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%c", &a[i][j]);
		}
		scanf("%c", &tmp);
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (a[i][j] == '/') {
				addEdge(id(i - 1, j - 1), id(i, j), 1);
				addEdge(id(i - 1, j), id(i, j - 1), 0);
			}
			else{
				addEdge(id(i - 1, j - 1), id(i, j), 0);
				addEdge(id(i - 1, j), id(i, j - 1), 1);
			}
		}
	}

	cout << dijkstra(id(0, 0), id(N, M));

}