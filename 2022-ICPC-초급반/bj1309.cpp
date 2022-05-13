#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N;
ll dp[3];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	dp[0] = 3;
	dp[1] = 7;

	cin >> N;

	if (N == 1) {
		cout << dp[0];
		return 0;
	}
	else if (N == 2) {
		cout << dp[1];
		return 0;
	}
	

	for (int i = 2; i < N; i++) {
		dp[2] = ((dp[1] * 2) + dp[0]) % 9901;
		dp[0] = dp[1];
		dp[1] = dp[2];
	}

	cout << dp[2];
}