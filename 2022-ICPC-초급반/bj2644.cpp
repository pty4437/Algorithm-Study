#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>

using namespace std;
typedef long long ll;

int n, m, a, b, x, y, cnt = 0, sum = 0;
int par[101];
vector<int> a_v, b_v;

int do_find(int x, bool flag, int a_b) {
	if (flag == true) {
		if (a_b == 1)
			a_v.push_back(x);
		else if (a_b == 2)
			b_v.push_back(x);
	}
	if (x == par[x]) return x;
	return x = do_find(par[x], flag, a_b);
}

void do_union(int x, int y) {
	par[y] = x;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 1; i <= 100; i++)
		par[i] = i;

	cin >> n;
	cin >> a >> b;
	cin >> m;

	while (m--) {
		cin >> x >> y;
		do_union(x, y);
	}

	if (do_find(a, false, 1) != do_find(b, false, 1)) cout << -1;
	else {
		do_find(a, true, 1); do_find(b, true, 2);

		reverse(a_v.begin(), a_v.end());
		reverse(b_v.begin(), b_v.end());

		for (int i = 0; i < min(a_v.size(), b_v.size()); i++) {
			if (a_v[i] == b_v[i]) cnt += 2;
		}

		cout << a_v.size() + b_v.size() - cnt;
	}
}