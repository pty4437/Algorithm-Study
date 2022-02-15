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
string S;
int K;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> S >> K;

	for (int i = 1, j = 0; i < S.size(); i++) {
		while (j > 0 && S[i] != S[j]) j = fail[j - 1];
		if (S[i] == S[j])fail[i] = ++j;
	}

	cout << (S.size() - fail[S.size() - 1]) * (K - 1) + S.size();
}