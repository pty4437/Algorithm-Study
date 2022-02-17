#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
typedef long long ll;

vector<pair<int, pair<int, double>>> adj;
vector<pair<int, int>> dot;
int par[1001];
int N, M, X, Y, cnt = 0;
double res = 0;

bool compare(pair<int, pair<int, double>> A, pair<int, pair<int, double>> B) {
	return A.second.second < B.second.second;
}

int do_find(int x) {
	if (x == par[x]) return x;
	return par[x] = do_find(par[x]);
}

void do_union(int x, int y) {
	int px = do_find(x);
	int py = do_find(y);

	if (px < py) par[px] = py;
	else if (px > py) par[py] = px;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> X >> Y;

		dot.push_back({ X, Y });
	}

	for (int i = 0; i < N; i++) par[i] = i;

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			double dist = sqrt(pow(dot[i].first - dot[j].first, 2) + pow(dot[i].second - dot[j].second, 2));
			adj.push_back({ i, {j, dist} });
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> X >> Y;
		do_union(X - 1, Y - 1);
	}

	sort(adj.begin(), adj.end(), compare);

	for (int i = 0; i < adj.size(); i++) {
		if (cnt == N - M - 1)
			break;

		int pA = do_find(adj[i].first);
		int pB = do_find(adj[i].second.first);

		if (pA != pB) {
			cnt++;
			res += adj[i].second.second;
			do_union(pA, pB);
		}
	}

	printf("%.2lf\n", res);
}