#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1010

using namespace std;
typedef long long ll;

typedef struct node {
	int x;
	int y;
	ll cost;
} Node;

vector<Node> v;
vector<int> bal;
int par[MAX];
int n, m, k, x, y, z, edge = 0;
ll res = 0, total = 0;

bool compare(Node A, Node B) {
	return A.cost < B.cost;
}

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

	cin >> m >> n >> k;

	for (int i = 0; i < k; i++) {
		int tmp;
		cin >> tmp; bal.push_back(tmp);
	}

	for (int i = 0; i < MAX; i++) {
		par[i] = i;
	}

	for (int i = 0; i < n; i++) {
		Node tmp;
		cin >> tmp.x >> tmp.y >> tmp.cost;
		v.push_back(tmp);
	}

	for (int i = 0; i < k; i++)
		do_union(0, bal[i]);

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++) {
		if (edge == m - 1)
			break;

		int a = do_find(v[i].x), b = do_find(v[i].y);

		if (a != b) {
			res += v[i].cost;
			edge++;
			do_union(v[i].x, v[i].y);
		}
	}

	cout << res << "\n";

	return 0;
}