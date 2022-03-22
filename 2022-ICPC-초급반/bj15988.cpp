#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int T, n;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	while (T--) {
		ll dp[1000001];

		cin >> n;

		dp[1] = 1; dp[2] = 2; dp[3] = 4;

		for (int i = 4; i <= n; i++) {
			dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
		}

		cout << dp[n] << "\n";
	}
}