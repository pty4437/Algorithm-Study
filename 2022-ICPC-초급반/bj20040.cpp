#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

int n, m, a, b;
int par[500001];

int do_find(int x) {
	if (x == par[x]) return x;
	return par[x] = do_find(par[x]);
}

void do_union(int x, int y) {
	int px = do_find(x);
	int py = do_find(y);

	if (px < py) par[px] = py;
	else par[py] = px;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) par[i] = i;

	for(int i = 1; i <= m; i++){
		cin >> a >> b;

		if (do_find(a) == do_find(b)) {
			cout << i;
			return 0;
		}

		do_union(a, b);
	}

	cout << 0;

	return 0;
}