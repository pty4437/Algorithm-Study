#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int par[1001];
int n, m, d, w;
vector<pair<int, int>> v;
int res[1001];

bool compare(pair<int, int> A, pair<int, int> B) {
	if (A.second == B.second)
		return A.first < B.first;
	return A.second > B.second;
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

	cin >> n;

	for (int i = 0; i < 1001; i++) {
		par[i] = i;
		res[i] = 0;
	}

	for(int i = 0; i < n; i++){
		cin >> d >> w;

		v.push_back({ d,w });
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++) {
		int idx = do_find(v[i].first);

		if (res[idx] == 0) {
			res[idx] = v[i].second;
			do_union(idx - 1, idx);
		}

	}
	
	ll sum = 0;

	for (int i = 1; i <= 1000; i++)
		sum += res[i];

	cout << sum;
}