#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll N, M;
ll sum = 0, maxVal = 0;
vector<ll> v;

int bin_search() {
	ll start = 0, end = v[N-1];
	ll res, sum;

	while (start <= end) {
		sum = 0;
		ll mid = (start + end) / 2;
		for (int i = 0; i < N; i++)
			sum += min(v[i], mid);

		if (M >= sum) {
			res = mid;
			start = mid + 1;
		}
		else
			end = mid - 1;
	}

	return res;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	ll tmp;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		sum += tmp;
		maxVal = max(maxVal, tmp);
		v.push_back(tmp);
	}

	cin >> M;

	if (M >= sum) {
		cout << maxVal;
	}
	else {
		sort(v.begin(), v.end());

		cout << bin_search();
	}

}