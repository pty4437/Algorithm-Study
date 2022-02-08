#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;

vector<int> v[1010];
int b_chk[1010], checked[1010];
int n, m, a, b, ans;

bool dfs(int x) {
	if (checked[x]) return false;
	checked[x] = true;
	for (auto nxt : v[x]) {
		if (!b_chk[nxt] || dfs(b_chk[nxt])) {
				b_chk[nxt] = x;
				return true;
		}
	}

	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> b;
			v[i].push_back(b);
		}
	}

	for (int i = 1; i <= n; i++) {
		memset(checked, 0, sizeof(checked));
		if (dfs(i)) ans++;
	}

	cout << ans;
}