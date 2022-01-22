#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T;
	cin >> T;
	
	while (T--) {
		int N;
		cin >> N;

		if (N % 2 == 0) cout << "cubelover" << "\n";
		else cout << "koosaga" << "\n";
	}

	return 0;
}