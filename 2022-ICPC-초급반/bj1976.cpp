#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N, M, tmp;
int par[201];

int do_find(int x) {
	if (x == par[x]) return x;
	return par[x] = do_find(par[x]);
}

void do_union(int x, int y) {
	int px = do_find(x);
	int py = do_find(y);

	if (x == y) return;
	par[px] = py;

	//if (px < py) par[px] = py;
	//else if (px > py) par[py] = px;
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cin >> M;

	for (int i = 0; i <= 200; i++) par[i] = i;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> tmp;
			if (tmp == 1)
				do_union(i, j);
		}
	}

	cin >> tmp;
	int head = do_find(tmp);
	
	for (int i = 1; i < M; i++) {
		cin >> tmp;

		if (head != do_find(tmp)) {
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";
	return 0;
}