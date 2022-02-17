#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 99999999

using namespace std;
typedef long long ll;

int par[501];
int cycle[501];
int n, m, command, a, b, res;

int do_find(int x) {
	if (x == par[x]) return x;
	return par[x] = do_find(par[x]);
}

void do_union(int x, int y) {
	int px = do_find(x);
	int py = do_find(y);

	if (px != py) {
		if (cycle[px] || cycle[py])
			cycle[px] = cycle[py] = -INF;
		par[px] = py;
	}
	else
		cycle[px] = -INF;

}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for(int i = 1;;i++){

		cin >> n >> m;

		if (n == 0 && m == 0)
			break;

		for (int i = 0; i <= n; i++) { par[i] = i; cycle[i] = 0; }
		res = 0;

		while (m--) {
			cin >> a >> b;

			do_union(a, b);
		}

		for (int j = 1; j <= n; j++) cycle[do_find(j)]++;

		for (int j = 1; j <= n; j++)
			if (cycle[j] > 0) res++;

		cout << "Case " << i << ": ";

		if (res <= 0)
			cout << "No trees.\n";
		else if (res == 1)
			cout << "There is one tree.\n";
		else
			cout << "A forest of " << res << " trees.\n";
	}

	return 0;
}