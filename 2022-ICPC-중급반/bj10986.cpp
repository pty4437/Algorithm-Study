#define _CRT_SECURE_NO_WARNING

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll N, M;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	vector<ll> v(M);
	v[0]++;

	ll pre_sum = 0, A, res = 0;

	for (int i = 0; i < N; i++) {
		cin >> A;
		pre_sum += A;
		pre_sum %= M;

		res += v[pre_sum];
		v[pre_sum]++;
	}

	cout << res;
}