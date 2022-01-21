#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mat[502][2], dp[502][502];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, r, c;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> r >> c;
		mat[i][0] = r;
		mat[i][1] = c;
	}

	for (int i = 1; i < N; i++) {
		for (int j = 1; i + j <= N; j++) {
			dp[j][i + j] = 1000000000;
			for (int k = j; k <= i + j; k++)
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + mat[j][0] * mat[k][1] * mat[i + j][1]);
		}
	}

	cout << dp[1][N];
}