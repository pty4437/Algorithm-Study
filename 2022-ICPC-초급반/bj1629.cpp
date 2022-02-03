#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll _pow(int a, int b, int c) {
	if (b == 0)
		return 1;
	if (b % 2 == 1)
		return (_pow(a, b - 1, c) * a) % c;

	ll half = _pow(a, b / 2, c);
	return (half * half) % c;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int A, B, C;

	cin >> A >> B >> C;

	cout << _pow(A, B, C);
}