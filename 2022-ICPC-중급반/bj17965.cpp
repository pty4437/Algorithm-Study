#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	long long n;
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;

	vector<long long> A(n), B(n);

	for (long long i = 0; i < n; i++) cin >> A[i];
	for (long long i = 0; i < n; i++) cin >> B[i];

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	long long ans = -1e12;
	long long tmp = 1e12;

	for (long long i = 0; i < n; i++) {
		tmp = 1e12;
		for (long long j = 0; j < n; j++)
			tmp = min(tmp, abs(A[i] - B[j]));

		ans = max(tmp, ans);
	}

	cout << ans;

}