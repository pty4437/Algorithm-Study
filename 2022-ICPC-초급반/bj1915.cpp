#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
typedef long long ll;

int N, M;
int map[1010][1010];
//int map[1010][1010];

int solve() {
	int maximum = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j]) {
				map[i][j] = min(map[i - 1][j - 1], min(map[i - 1][j], map[i][j - 1])) + 1;

				maximum = max(maximum, map[i][j]);
			}
		}
	}

	return maximum;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		string str; cin >> str;
		for (int j = 1; j <= M; j++)
			map[i][j] = str[j - 1] - '0';
	}

	int res = solve();

	cout << res * res;
}