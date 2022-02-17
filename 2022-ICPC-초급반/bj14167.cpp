#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N, a, b, cnt = 0, res;
int par[1001];
vector<pair<int, int>> dot;
vector < pair<int, pair<int, int>> > adj;

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

bool compare(pair<int, pair<int, int>> A, pair<int, pair<int, int>> B) {
	return A.second.second < B.second.second;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for(int i = 0; i < N; i++){
		cin >> a >> b;
		dot.push_back({ a, b });
	}

	for (int i = 0; i < N; i++) par[i] = i;

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int dist = (dot[i].first - dot[j].first) * (dot[i].first - dot[j].first) + (dot[i].second - dot[j].second) * (dot[i].second - dot[j].second);

			adj.push_back({ i, {j, dist} });
		}
	}

	sort(adj.begin(), adj.end(), compare);

	for (int i = 0; i < adj.size(); i++) {
		if (cnt == N - 1)
			break;

		int pA = do_find(adj[i].first);
		int pB = do_find(adj[i].second.first);

		if (pA != pB) {
			do_union(pA, pB);
			cnt++;
			res = adj[i].second.second;
		}
	}

	cout << res;
}