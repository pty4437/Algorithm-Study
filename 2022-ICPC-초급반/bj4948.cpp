#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int n;
int sieve[250000];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 2; i <= 250000; i++) {
		if (sieve[i]) continue;
		for (int j = i + i; j <= 250000; j += i) sieve[j] = 1;
	}


	while (true) {
		int cnt = 0;
		cin >> n;

		if (n == 0)
			break;

		for (int i = n+1; i <= 2 * n; i++) {
			if (!sieve[i]) cnt++;
		}

		cout << cnt << "\n";
	}
}