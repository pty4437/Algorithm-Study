#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N, X;
vector<pair<int, int>> v;

bool compare(pair<int, int> A, pair<int, int> B) {
	int tmp1 = A.first - A.second;
	int tmp2 = B.first - B.second;

	if (tmp1 == tmp2)
		return A.first > B.first;
	return tmp1 > tmp2;

	//return (A.first - A.second) > (B.first - B.second);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> X;

	int a, b;

	for (int i = 0; i < N; i++) {
		cin >> a >> b;

		v.push_back(pair<int, int>(a, b));
	}

	sort(v.begin(), v.end(), compare);


	int possible = 0;
	int tmp_N = N, tmp_X = X;

	
	//if (N * 5000 <= X)
		//possible = N;
	//else
		//possible = (X - 1000 * N) / 5000;

	for (int i = 0; i < N; i++) {
		if (tmp_X - 5000 - ((tmp_N - 1) * 1000) >= 0) {
			possible++;
			tmp_X -= 5000;
			tmp_N--;
		}
	}

	//cout << possible << endl;

	ll res = 0;

	for (int i = 0; i < N; i++) {
		if (v[i].first - v[i].second < 0 || possible == 0) {
			res += v[i].second;
		}
		else {
			res += v[i].first;
			possible--;
		}
	}

	cout << res << "\n";

	return 0;
}