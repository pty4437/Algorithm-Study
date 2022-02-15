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

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string S, T;

	getline(cin, S); getline(cin, T);

	for (int i = 1, j = 0; i < T.size(); i++) {
		while (j > 0 && T[i] != T[j]) j = fail[j - 1];
		if (T[i] == T[j])fail[i] = ++j;
	}

	vector<ll> ans;
	for (int i = 0, j = 0; i < S.size(); i++) {
		while (j > 0 && S[i] != T[j]) j = fail[j - 1];
		if (S[i] == T[j]) {
			if (j == T.size() - 1) {
				ans.push_back(i - T.size() + 2);
				j = fail[j];
			}
			else j++;
		}
	}

	cout << ans.size() << "\n";
	for (ll nxt : ans) cout << nxt << " ";
}