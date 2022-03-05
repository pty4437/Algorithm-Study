#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N, a, b;
int dp[105];
vector<pair<int, int>> v;

bool compare(pair<int, int> A, pair<int, int> B) {
	return A.first < B.first;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	while (N--) {
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end(), compare);

	int res = 0;

	for (int i = 0; i < v.size(); i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (v[i].second > v[j].second)
				dp[i] = max(dp[i], dp[j] + 1);
		}

		res = max(res, dp[i]);
	}

	cout << v.size() - res;
}