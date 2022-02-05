#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll N, M;

ll res = 0;
ll sum = 0;
vector<int> v;

void func(int idx) {

	if (sum > M)
		return;

	if (sum == M) {
		res++;
		return;
	}

	if (idx == N - 1)
		return;

	sum += v[idx];
	func(idx + 1);
	sum -= v[idx];
	func(idx + 1);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	

	for (int i = 0; i < N; i++) {
		int tmp;

		cin >> tmp;
		v.push_back(tmp);

		//cin >> v[i];
	}

	sort(v.begin(), v.end());

	func(0);

	cout << res;

}