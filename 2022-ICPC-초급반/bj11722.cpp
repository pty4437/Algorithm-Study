#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N, tmp;
vector<int> sqe;
int dp[1001], maxVal = -987654321;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for(int i = 0; i < N; i++) {
		cin >> tmp;
		sqe.push_back(tmp);
	}

	for (int i = 0; i < N; i++) {
		dp[i] = 1;

		for (int j = 0; j <= i; j++) {
			if (sqe[i] < sqe[j] && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
		}

		maxVal = max(dp[i], maxVal);
	}

	cout << maxVal;
}