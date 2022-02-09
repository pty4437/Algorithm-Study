#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int T;
ll arr[51];

void fibo(int idx) {
	if (idx == 51)
		return;

	arr[idx] = arr[idx - 1] + arr[idx - 2];
	fibo(idx + 1);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	arr[1] = arr[2] = 1;

	fibo(3);

	
	cin >> T;

	while (T--) {
		ll n;
		vector<ll> v;

		cin >> n;

		for (int i = 50; i >= 1; i--) {
			if (arr[i] <= n) {
				n -= arr[i];
				v.push_back(arr[i]);
			}
		}

		sort(v.begin(), v.end());

		for (auto x : v)
			cout << x << " ";
		cout << "\n";
	}
	
}