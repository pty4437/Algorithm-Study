#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <sstream>

using namespace std;
typedef long long ll;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll N;
	cin >> N;

	vector<string> str_vec(N);
	stack<string> stk[100];
	stack<string> sol_stk;

	string sol, tmp;
	getline(cin, tmp);

	for (int i = 0; i < N; i++) {
		getline(cin, str_vec[i]);
	}

	//cin >> sol;
	//getline(cin, tmp);
	getline(cin, sol);

	stringstream ss(sol);
	ss.str(sol);

	string word;
	while (ss >> word) {
		sol_stk.push(word);
	}

	for (int i = 0; i < N; i++) {
		stringstream ss(str_vec[i]);
		ss.str(str_vec[i]);

		while (ss >> word) {
			stk[i].push(word);
		}
	}

	while (!sol_stk.empty()) {
		bool flag = false;

		for (int i = 0; i < N; i++) {
			if (stk[i].empty())
				continue;

			if (sol_stk.top().compare(stk[i].top()) == 0) {
				sol_stk.pop(); stk[i].pop();

				flag = true;
				break;
			}
		}

		if (flag == false) {
			cout << "Impossible";
			return 0;
		}
	}


	cout << "Possible";
}