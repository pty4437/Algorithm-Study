#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N;
vector<int> P;
int dp[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	
	int tmp;

	P.push_back(0);

	for(int i = 1; i <= N; i++) {
		cin >> tmp;
		P.push_back(tmp);
	}

	dp[1] = P[1];

	for (int i = 2; i <= N; i++) {
		dp[i] = P[i];
		for (int j = 1; j < i; j++) {
			for (int k = 1; k < i; k++) {
				if(j + k == i)
					dp[i] = max(dp[i], dp[j] + P[k]);
			}
		}
	}

	cout << dp[N];
}