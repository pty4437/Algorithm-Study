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
	vector<int> v(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	cin >> M;

	int mok = (N / M);

	for (int i = 0; i < M; i++) {
		sort(v.begin() + mok * i, v.begin() + mok * (i + 1));

		for (int j = (N / M) * i; j < (N / M) * (i + 1); j++)
			cout << v[j] << " ";
	}

}