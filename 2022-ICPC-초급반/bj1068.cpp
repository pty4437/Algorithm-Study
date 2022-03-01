#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
typedef long long ll;

int N, parent, del, root, res = 0;
vector<int> v[51];
int visited[51];

void dfs(int start) {
	stack<int> st;
	st.push(start);
	visited[start] = 1;

	while (!st.empty()) {
		int cur = st.top(); st.pop();

		if (cur == del)
			continue;

		if (v[cur].size() == 0) {
			res++; continue;
		}
		else if (v[cur].size() == 1) {
			if (v[cur][0] == del) {
				res++; continue;
			}
		}
		
		for (int next : v[cur]) {
			if (visited[next]) continue;
			st.push(next);
			visited[next]++;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> parent;
		if (parent == -1)
			root = i;
		else
			v[parent].push_back(i);

	}

	cin >> del;

	dfs(root);

	cout << res;

}