#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
typedef long long ll;

int N, tmp;
int v[101];
vector<int> res;
int flag[101], visited[101];

void dfs(int idx) {
	vector<int> tmp_v;
	stack<int> st;
	int last = 0;

	st.push(idx);
	visited[idx] = 1;

	while (!st.empty()) {
		last = st.top(); st.pop();
		tmp_v.push_back(last);
		if (visited[v[last]]) {
			continue;
		}

		st.push(v[last]);
		visited[v[last]] = 1;
	}

	if (v[last] == idx) {
		for (int i = 0; i < tmp_v.size(); i++) {
			res.push_back(tmp_v[i]);
			//cout << tmp_v[i] << endl;
			flag[tmp_v[i]] = 1;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> v[i];
		visited[i] = 0;
	}

	for (int i = 1; i <= N; i++) {
		if (!flag[i]) {
			for (int j = 1; j <= N; j++)
				visited[j] = 0;
			dfs(i);
		}
	}

	sort(res.begin(), res.end());
	cout << res.size() << endl;

	for (int i = 0; i < res.size(); i++) cout << res[i] << "\n";
}