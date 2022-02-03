#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll N, M;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	vector<ll> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	cin >> M;
	vector<ll> search(M);

	for (int i = 0; i < M; i++) {
		cin >> search[i];
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < M; i++) {
		cout << upper_bound(v.begin(), v.end(), search[i]) - lower_bound(v.begin(), v.end(), search[i]) << " ";
	}

}