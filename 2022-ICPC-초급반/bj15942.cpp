#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

int N, k, p, upCnt, downCnt;
int h[200001];
bool check[200001] = { false };
vector<int> up;

void getup() {
	int t = p;
	while (t >>= 1)
		up.push_back(t);
	reverse(up.begin(), up.end());
	if (up.size() >= k) {
		cout << -1;
		exit(0);
	}
	for (auto i : up)h[i] = ++upCnt;
}

void dfs(int v) {
	h[v] = downCnt--;
	if (v * 2 <= N) dfs(v * 2);
	if (v * 2 + 1 <= N) dfs(v * 2 + 1);
}

void getdown() {
	downCnt = N;
	if (p * 2 <= N) dfs(p * 2);
	if (p * 2 + 1 <= N) dfs(p * 2 + 1);
	if (downCnt < k) {
		cout << -1;
		exit(0);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cin >> k >> p;

	h[p] = k;

	getup();
	getdown();

	queue<int> q;
	for (int i = upCnt + 1; i <= downCnt; i++) {
		if (i == k) continue;
		q.push(i);
	}
	for (int i = 1; i <= N; i++) {
		if (h[i]) continue;
		h[i] = q.front(); q.pop();
	}

	for (int i = 1; i <= N; i++)
		cout << h[i] << "\n";
}