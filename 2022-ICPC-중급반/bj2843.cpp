#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;
typedef long long ll;

const int n_ = 300000 + 200;
vector<int> v[n_];
int a, b, c, d, n, m, x, y;
int A[n_], B[n_], par[n_];
stack<pair<int, int>> query;
bool checked[n_];

int find(int x) {
	if (!par[x]) return x;
	return par[x] = find(par[x]);
}

void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	par[x] = y;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) cin >> B[i];

	cin >> m;

	while (m--) {
		cin >> a >> b;
		if (a == 2) checked[b] = true;
		query.push({ a,b });
	}

	for (int i = 1; i <= n; i++) {
		if (checked[i] || !B[i]) continue;
		if (find(i) == find(B[i])) A[find(i)] = 1;
		else merge(i, B[i]);
	}

	stack<int> ans, real_ans;
	while (query.size()) {
		a = query.top().first, b = query.top().second;
		query.pop();
		if (a == 1) {
			if (A[find(b)]) ans.push(-1);
			else ans.push(find(b));
		}
		else {
			if (find(b) == find(B[b]))A[find(b)] = 1;
			else merge(b, B[b]);
		}

	}

	while (ans.size()) {
		if (ans.top() < 0) cout << "CIKLUS";
		else cout << ans.top();
		cout << "\n";
		ans.pop();
	}
}