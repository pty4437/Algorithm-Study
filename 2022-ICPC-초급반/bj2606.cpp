#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <stack>

using namespace std;
typedef long long ll;

int n, m;
vector<int> adj[102];
int visited[102] = { 0 };

void dfs(int cur) {
	if (visited[cur]) return;

	visited[cur] = 1;

	for (int next : adj[cur])
		dfs(next);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> m;

	int a, b;

	while (m--) {
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1);

	ll res = 0;

	for (int i = 1; i <= n; i++) {
		if (visited[i])
			res++;
	}

	cout << res-1;
}