#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;

ll N, M, res = 0;
vector<int> v[1001];
int visited[1002];

void dfs(int idx) {
	stack<int> st;
	st.push(idx);
	visited[idx] = 1;

	while (!st.empty()) {
		int cur = st.top(); st.pop();
		for (int next : v[cur]) {
			if (visited[next])continue;

			st.push(next);
			visited[next] = 1;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	int a, b;

	while (M--) {
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			dfs(i);
			res++;
		}
	}

	cout << res;
}