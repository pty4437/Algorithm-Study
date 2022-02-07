#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;

int N, M;
int visited[10001];
vector<int> adj[10001];
vector < pair<int, int>> pc;

void dfs(int idx) {
	stack<int> st;
	st.push(idx);
	visited[idx] = 1;
	int count = 0;

	while (!st.empty()) {
		int cur = st.top(); st.pop();
		count++;

		for (int next : adj[cur]) {
			if (visited[next]) continue;

			st.push(next);
			visited[next] = 1;
		}
	}

	pc.push_back({ idx, count });
}

bool compare(pair<int, int> A, pair<int, int> B) {

	if (A.second == B.second)
		return A.first < B.first;

	return A.second > B.second;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	int a, b;

	while (M--) {
		cin >> a >> b;

		//adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		//if (!visited[i])
		memset(visited, 0, sizeof(visited));
		dfs(i);
	}

	sort(pc.begin(), pc.end(), compare);

	//cout << pc.size() << endl;

	for (int i = 0; i < pc.size(); i++) {
		cout << pc[i].first << " ";

		if (i == pc.size()-1 || pc[i].second != pc[i + 1].second)
			break;
	}
}