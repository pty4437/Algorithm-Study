#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N, M;
int arr[100001];

void solve(int cur, int idx) {
	if (idx == M + 1) {
		for (int i = 1; i <= M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";

		return;
	}

	if (cur == N + 1) return;
	arr[idx] = cur;
	solve(cur + 1, idx + 1);
	solve(cur + 1, idx);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	solve(1, 1);
}