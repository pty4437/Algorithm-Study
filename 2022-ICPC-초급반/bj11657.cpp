#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>	
#include <list>	
#include <algorithm>

using namespace std;
typedef long long ll;
#define INF 99999999

int N, M, A, B, C;
vector<pair<int, int>> adj[501];
ll dist[6001];
int negative_cycle = 0;

void bellman_ford(int start) {
	for (int i = 1; i <= N; i++)
		dist[i] = INF;

	dist[start] = 0;

	for (int iter = 1; iter <= N; iter++) {
		for (int cur = 1; cur <= N; cur++) {
			for (pair<int, int> E : adj[cur]) {
				ll next = E.first, cost = E.second;
				if (dist[cur] != INF && dist[next] > dist[cur] + cost) {
					dist[next] = dist[cur] + cost;
					if (iter == N) { negative_cycle = 1; }
				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	while (M--) {
		cin >> A >> B >> C;

		adj[A].push_back({ B,C });
	}

	bellman_ford(1);

	if (negative_cycle)
		cout << -1;
	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == INF)
				cout << -1 << "\n";
			else
				cout << dist[i] << "\n";
		}
	}
}