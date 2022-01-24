#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N;

bool compare(int A, int B) {
	return A < B;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	vector<int> v(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	sort(v.begin(), v.end(), compare);

	ll res = 0, tmp = 0;

	for (int i = 0; i < N; i++) {
		res += v[i] * (N - i);
	}

	cout << res;
}