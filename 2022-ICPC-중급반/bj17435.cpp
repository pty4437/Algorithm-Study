#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll m, q, n, x;
int f[202020][20];


ll query(ll n, ll x) {
	for (int i = 19; i >= 0; i--) {
		if (n >= (1 << i)) {
			n -= (1 << i);
			x = f[x][i];
		}
	}

	return x;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m;

	for (int i = 1; i <= m; i++) cin >> f[i][0];
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j <= m; j++) f[j][i] = f[f[j][i - 1]][i - 1];
	}

	cin >> q;

	while (q--) {
		cin >> n >> x;
		cout << query(n, x) << "\n";
	}
}