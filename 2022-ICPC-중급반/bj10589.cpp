#define _CRT_SECURE_NO_WARNING

#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;

	cin >> n >> m;

	vector<vector<int>> v;

	for (int i = 2; i <= n; i += 2) v.push_back({ i, 1, i, m });
	for (int j = 2; j <= m; j += 2) v.push_back({ 1, j, n, j });

	cout << v.size() << endl;

	for (auto nxt : v) {
		for (auto nxt2 : nxt) cout << nxt2 << ' ';
		cout << "\n";
	}
}