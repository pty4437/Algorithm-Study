#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;

ll fail[2002000];
int n;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	string S;

	cin >> S;

	for (int i = 1, j = 0; i < n; i++) {
		while (j > 0 && S[i] != S[j]) j = fail[j - 1];
		if (S[i] == S[j])fail[i] = ++j;
	}

	if (fail[n - 1])
		cout << n - fail[n - 1];
	else
		cout << n;
}