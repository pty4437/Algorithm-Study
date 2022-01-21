#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string l, r, res;
bool flag = true;

void dfs(int a, int b, int len) {
	if (flag)
		return;
	if (len == res.size()) {
		flag = true;
		return;
	}
	if (l[a] == res[len])
		dfs(a + 1, b, len+1);
	if (r[b] == res[len])
		dfs(a, b + 1, len+1);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> l >> r >> res;
		int check[27] = { 0 };
		flag = true;

		for (int j = 0; j < l.size(); j++)
			check[l[j] - 'a'] += 1;
		for (int j = 0; j < r.size(); j++)
			check[r[j] - 'a'] += 1;
		for (int j = 0; j < res.size(); j++)
			check[res[j] - 'a'] -= 1;

		for (int j = 0; j < 27; j++) {
			if (check[j] != 0) {
				flag = false;
				break;
			}
		}

		if (flag == false) {
			cout << "Data set " << i + 1 << ": no\n";
		}
		else {
			flag = false;
			dfs(0, 0, 0);
			if (flag)
				cout << "Data set " << i + 1 << ": yes\n";
			else
				cout << "Data set " << i + 1 << ": no\n";
		}
			
	}

	return 0;
}