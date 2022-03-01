#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
typedef long long ll;

int T;
int x, y;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> x >> y;
		int len = y - x;
		int root = sqrt(len);
		int res = 0;

		if (pow(root, 2) == len)
			res = 2 * root - 1;
		else
			res = 2 * root;

		if (len > root * (root + 1)) res++;

		cout << res << "\n";

	}
}