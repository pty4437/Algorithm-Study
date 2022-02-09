#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int K, a;
stack<int> st;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> K;

	while (K--) {
		cin >> a;

		if (a == 0)
			st.pop();
		else
			st.push(a);
	}

	int sum = 0;

	while (!st.empty()) {
		sum += st.top();
		st.pop();
	}

	cout << sum;
}