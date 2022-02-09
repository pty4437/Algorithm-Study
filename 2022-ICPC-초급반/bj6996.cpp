#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;

	cin >> T;

	while (T--) {
		string a, b;
		int A[27] = { 0 }, B[27] = { 0 };
		bool flag = true;

		cin >> a >> b;
		
		for (int i = 0; i < a.size(); i++)
			A[a[i] - 'a']++;
		for (int i = 0; i < b.size(); i++)
			B[b[i] - 'a']++;

		for (int i = 0; i < 27; i++) {
			if (A[i] != B[i]) {
				flag = false;
				break;
			}
		}

		if (flag == true)
			cout << a << " & " << b << " are anagrams.\n";
		else
			cout << a << " & " << b << " are NOT anagrams.\n";
	}
}