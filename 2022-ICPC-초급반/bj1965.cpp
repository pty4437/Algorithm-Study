#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int n, res = 0;
int box[1001], dp[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> box[i];

	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (box[i] > box[j] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
		res = max(res, dp[i]);
	}

	cout << res;
}