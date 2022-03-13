#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N, L;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> L;

	for (int i = L; i <= 100; i++) {
		int num = N - i * (i + 1) / 2;

		if (num % i == 0) {
			int start = num / i + 1;

			if (start >= 0) {
				for (int j = 0; j < i; j++) {
					cout << j + start << " ";
				}

				return 0;
			}
		}
	}

	cout << -1;
}