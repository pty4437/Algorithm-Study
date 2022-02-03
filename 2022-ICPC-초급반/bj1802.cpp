#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;

bool func(string str, int start, int end) {
	if (start >= end)
		return true;

	int l = start;
	int r = end;

	while (l < r) {
		if (str[l++] == str[r--])
			return false;
	}

	return func(str, start, r - 1);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;

	cin >> T;

	while (T--) {
		string str;
		cin >> str;

		if (str.length() % 2 == 0) {
			cout << "NO" << "\n";
			continue;
		}

		if (func(str, 0, str.length() - 1))
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
}