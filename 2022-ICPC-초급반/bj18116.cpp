#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;

char command, enter;
int N, a, b;
int par[1000001], cnt[1000001];

int do_find(int x) {
	if (x == par[x]) return x;
	return par[x] = do_find(par[x]);
}

void do_union(int x, int y) {
	int px = do_find(x);
	int py = do_find(y);

	if (px < py) {
		par[px] = py;
		cnt[py] += cnt[px];
	}
	else if(px > py) {
		par[py] = px;
		cnt[px] += cnt[py];
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	fill_n(cnt, 1000001, 1);

	for (int i = 0; i < 1000001; i++) {
		par[i] = i;
	}

	while (N--) {
		cin >> command >> a;

		if (command == 'I') {
			cin >> b;
			do_union(a, b);
		}
		else {
			cout << cnt[do_find(a)] << "\n";
		}

	}
}