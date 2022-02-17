#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 200010

using namespace std;
typedef long long ll;

typedef struct node {
	int x;
	int y;
	ll cost;
} Node;

int par[MAX];
int n, m, x, y, z, edge = 0;
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

	//par[y] = x;

	if (px > py) par[px] = py;
	else if (px < py) par[py] = px;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true) {
		vector<Node> v;
		cin >> m >> n;
		res = 0;
		edge = 0;
		total = 0;

		if (m == 0 && n == 0)
			break;

		for (int i = 0; i < MAX; i++) {
			par[i] = i;
		}

		for (int i = 0; i < n; i++) {
			Node tmp;
			cin >> tmp.x >> tmp.y >> tmp.cost;

			total += tmp.cost;

			v.push_back(tmp);
		}

		sort(v.begin(), v.end(), compare);

		for (int i = 0; i < n; i++) {
			if (edge == m-1)
				break;

			int a = do_find(v[i].x), b = do_find(v[i].y);

			if (a != b) {
				res += v[i].cost;
				edge++;
				do_union(v[i].x, v[i].y);
			}
		}

		cout << total - res << "\n";
	}


	return 0;
}