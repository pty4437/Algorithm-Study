#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;

	cin >> T;

	while (T--) {
		int a, b;
		int tmp = 1;

		cin >> a >> b;

		for (int i = 1; i <= b; i++) {
			tmp *= a;
			
			tmp = tmp % 10;
		}

		if (tmp == 0)
			tmp = 10;
		cout << tmp << "\n";
	}
}