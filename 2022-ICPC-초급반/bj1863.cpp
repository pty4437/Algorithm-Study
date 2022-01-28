#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;
typedef long long ll;

ll n;
ll x, y;
stack<ll> s;
vector<ll> v;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll res = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back(y);
	}

	for (int i = 0; i < n; i++) {
		y = v[i];

		while (true) {
			if (s.empty() || s.top() <= y)
				break;

			if (y < s.top()) {
				if (s.top() != 0) res++;
				s.pop();
			}
		}

		if (s.empty() == false && s.top() == y) continue;

		s.push(y);
	}

	while (true) {
		if (s.empty())
			break;
		if (s.top() != 0) res++;
		s.pop();

	}

	cout << res;

	return 0;
}