#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
typedef long long ll;

int N, INF = 9999;
int map[15625], dist[15625], visited[15625];

int dijkstra(int start, int goal) {
	fill(dist, dist + 15625, INF);
	fill(visited, visited + 15625, 0);

	priority_queue<pair<int, int>> pq;
	dist[start] = map[0];
	pq.push({ map[0], start });

	while (!pq.empty()) {
		int cur = pq.top().second; pq.pop();
		if (visited[cur]) continue;

		visited[cur] = 1;
		
		if (cur + 1 < cur + N) {
			int next = cur + 1, cost = map[cur + 1];
			int next_dist = dist[cur] + cost;
			if (dist[next] > next_dist) {
				dist[next] = next_dist;
				pq.push({-dist[next], next });
			}
		}

		if (cur + N < N * N) {
			int next = cur + N, cost = map[cur + N];
			int next_dist = dist[cur] + cost;
			if (dist[next] > next_dist) {
				dist[next] = next_dist;
				pq.push({ -dist[next], next });
			}
		}

		if (cur - 1 >= (int)(cur / N) * N) {
			int next = cur - 1, cost = map[cur - 1];
			int next_dist = dist[cur] + cost;
			if (dist[next] > next_dist) {
				dist[next] = next_dist;
				pq.push({ -dist[next], next });
			}
		}

		if (cur - N >= 0) {
			int next = cur - N, cost = map[cur - N];
			int next_dist = dist[cur] + cost;
			if (dist[next] > next_dist) {
				dist[next] = next_dist;
				pq.push({ -dist[next], next });
			}
		}
	}

	return dist[goal];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for(int i = 1;;i++){
		cin >> N;

		if (N == 0)
			break;
		else {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					cin >> map[i*N + j];
				}
			}
		}

		cout << "Problem " << i << ": " << dijkstra(0, N * N - 1) << "\n";
	}

	return 0;
}