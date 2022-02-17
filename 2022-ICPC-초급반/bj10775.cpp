#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int G, P, g, res = 0;
int par[100001];

int do_find(int x) {
	if (x == par[x]) return x;
	return par[x] = do_find(par[x]);
}

void do_union(int x, int y) {
	int px = do_find(x);
	int py = do_find(y);

	if (px < py) par[py] = px;
	else if (px > py) par[px] = py;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> G;
	cin >> P;

	for (int i = 1; i <= G; i++) par[i] = i;

	while (P--) {
		cin >> g;

		int parent = do_find(g);

		if (parent) {
			res++;
			do_union(parent - 1, parent);
		}
		else
			break;
	}

	cout << res;
}