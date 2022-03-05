#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N;
int dp[2][100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	dp[0][0] = dp[1][0] = 0;
	dp[0][1] = dp[1][1] = 1;

	for (int i = 2; i <= N; i++) {
		dp[0][i] += (dp[0][i - 1] + dp[0][i - 2]);
		dp[1][i] += (dp[1][i - 1] + dp[1][i - 2]);
	}

	cout << dp[0][N];
}