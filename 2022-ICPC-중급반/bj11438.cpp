#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

const int _n = 100000 + 2;
vector<int> v[_n];

int N, M, parent[_n][21], d[_n];

void dfs(int x, int par) {
	d[x] = d[par] + 1;
	for (int nxt : v[x]) {
		if (nxt == par)continue;
		parent[nxt][0] = x;
		dfs(nxt, x);
	}
}

int lca(int x, int y) {
	if (d[x] > d[y]) swap(x, y); 
	for(int i = 20; i >= 0; i--) {
		if (d[y] - d[x] >= (1 << i))
			y = parent[y][i];
	}
	if (x == y) return x;
	for (int i = 20; i >= 0; i--) {
		if (parent[x][i] != parent[y][i]) {
			x = parent[x][i];
			y = parent[y][i];
		}
	}

	return parent[x][0];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b;

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1, 0);

	for (int i = 1; i < 21; i++) {
		for (int j = 1; j <= N; j++) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
		}
	}

	cin >> M;

	while (M--) {
		cin >> a >> b;
		cout << lca(a, b) << "\n";
	}
}