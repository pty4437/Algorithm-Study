#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N, day, cost, res = 0;
int dp[16], t[16], c[16];


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> t[i] >> c[i];
	}

	for (int i = 1; i <= N + 1; i++) {
		for (int j = 1; j < i; j++) {
			dp[i] = max(dp[i], dp[j]);

			if (j + t[j] == i)
				dp[i] = max(dp[i], dp[j] + c[j]);
		}

		res = max(res, dp[i]);
	}

	cout << res;
}