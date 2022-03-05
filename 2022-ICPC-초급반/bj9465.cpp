#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int T, col;
int arr[2][100001];
int dp[2][100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> col;

		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= col; j++) {
				cin >> arr[i][j];
			}
		}

		dp[0][0] = dp[1][0] = 0;
		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];

		for (int i = 2; i <= col; i++) {
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + arr[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + arr[1][i];
		}

		cout << max(dp[0][col], dp[1][col]) << "\n";
	}

}