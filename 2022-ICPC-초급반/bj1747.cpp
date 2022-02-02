#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int notprime[2000002] = { 1,1,0 };
int N;

void sieve(void) {
	for (int i = 2; i <= 2000000; i++) {
		if (notprime[i] == 0) {
			for (int j = 2 * i; j <= 2000000; j += i) {
				notprime[j] = 1;
			}
		}
	}
}

int check(int n) {
	vector<int> digit;

	while (n != 0) {
		digit.push_back(n % 10);
		n /= 10;
	}

	for (int i = 0; i < digit.size() / 2; i++) {
		if (digit[i] != digit[digit.size() - i - 1]) return 0;
	}

	return 1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	sieve();

	for (int i = N; i <= 1003001; i++) {
		if (check(i) && notprime[i] == 0) {
			cout << i;
			return 0;
		}
	}
}