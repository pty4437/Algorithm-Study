#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
typedef long long ll;

int N, visited[100001], par[100001];
vector<int> adj[100001];

void dfs(int idx) {
	stack<int> st;

	st.push(idx);
	visited[idx] = 1;

	while (!st.empty()) {
		int cur = st.top(); st.pop();

		for (int tmp : adj[cur]) {
			if (visited[tmp]) continue;

			par[tmp] = cur;
			st.push(tmp);
			visited[tmp] = 1;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	int a, b;

	for (int i = 1; i < N; i++) {
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i <= N; i++)
		cout << par[i] << "\n";
}