#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int par[1000001];
int n, m, command, a, b;

int do_find(int x) {
	if (x == par[x]) return x;
	return par[x] = do_find(par[x]);
}

void do_union(int x, int y) {
	int px = do_find(x);
	int py = do_find(y);

	if (px > py) par[px] = py;
	else if (px < py) par[py] = px;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i <= n; i++) par[i] = i;

	while (m--) {
		cin >> command >> a >> b;

		if (command == 0) {
			do_union(a, b);
		}
		else if (command == 1) {
			if (do_find(a) == do_find(b)) {
				cout << "YES\n";
			}
			else
				cout << "NO\n";
		}
		else
			exit(0);
	}
}