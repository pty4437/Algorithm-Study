#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N, M, k, a, b;
ll A[10001];
int par[10001];

int do_find(int x) {
	if (x == par[x]) return x;
	return par[x] = do_find(par[x]);
}

void do_union(int x, int y) {
	int px = do_find(x);
	int py = do_find(y);

	if (px < py) {
		par[px] = py; 
		A[py] = min(A[px], A[py]);
		A[px] = 0;
	}
	else if (px > py) { 
		par[py] = px; 
		A[px] = min(A[px], A[py]);
		A[py] = 0; 
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> k;

	for (int i = 1; i <= N; i++) par[i] = i;

	for (int i = 1; i <= N; i++)
		cin >> A[i];

	while (M--) {
		cin >> a >> b;

		do_union(a, b);
	}

	ll sum = 0;

	for (int i = 1; i <= N; i++)
		sum += A[i];

	if (sum > k)
		cout << "Oh no";
	else
		cout << sum;
}