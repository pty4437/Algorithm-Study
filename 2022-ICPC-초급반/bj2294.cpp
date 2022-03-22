#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N, K;
bool flag = false;
vector<int> coin;
int dp[100001];

int solve() {
	for (int i = 0; i < coin.size(); i++) {
		dp[coin[i]] = 1;
	}

	for (int i = 2; i <= K; i++) {
		if (dp[i] != 1) {
			dp[i] = 987654321;

			for (int j = 1; j < i; j++) {
				if(dp[j] > 0 && dp[i-j] > 0)
					dp[i] = min(dp[i], dp[j] + dp[i - j]);
			}

		}
	}

	return dp[K];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	int tmp;

	while (N--) {
		cin >> tmp;
		coin.push_back(tmp);
	}

	sort(coin.begin(), coin.end());

	int res = solve();

	if (res == 0 || res >= 987654321)
		cout << -1;
	else
		cout << res;

	return 0;
}