#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

int V, E, A, B, C, cnt = 0;
int par[10001];
ll res = 0;
vector<pair<int, pair<int, int>>> adj;

bool compare(pair<int, pair<int, int>> A, pair<int, pair<int, int>> B) {
	return A.second.second < B.second.second;
}

int do_find(int x) {
	if (x == par[x]) return x;
	return par[x] = do_find(par[x]);
}

void do_union(int x, int y) {
	int px = do_find(x);
	int py = do_find(y);

	if (px < py) par[px] = py;
	else if (px > py) par[py] = px;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> V >> E;

	for(int i = 0; i < E; i++) {
		cin >> A >> B >> C;

		adj.push_back({ A,{ B,C } });
	}

	sort(adj.begin(), adj.end(), compare);

	for (int i = 1; i <= V; i++)
		par[i] = i;

	for (int i = 0; i < E; i++) {
		if (cnt == V - 1)
			break;

		int pA = do_find(adj[i].first);
		int pB = do_find(adj[i].second.first);

		if (pA != pB) {
			do_union(pA, pB);
			res += adj[i].second.second;
			cnt++;
		}
	}

	cout << res;
}