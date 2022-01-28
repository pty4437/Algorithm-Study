#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;
typedef long long ll;

int N, P;
int num_str, prat;
stack<int> stk[7];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> P;
	ll res = 0;

	while (N--) {
		cin >> num_str >> prat;

		if (stk[num_str].empty() || stk[num_str].top() < prat) {
			stk[num_str].push(prat);
			res++;
		}
		else if (stk[num_str].top() == prat)
			continue;
		else if (stk[num_str].top() > prat) {
			while (!stk[num_str].empty()) {
				if (stk[num_str].top() <= prat)
					break;

				stk[num_str].pop();
				res++;
			}

			if (stk[num_str].empty() || stk[num_str].top() != prat) {
				stk[num_str].push(prat);
				res++;
			}
		}
	}

	cout << res;
}