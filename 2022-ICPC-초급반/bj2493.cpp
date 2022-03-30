#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
typedef long long ll;

int N, top_idx = 0, high = 0, high_idx = 0;
int top[500001];
stack<pair<int, int>> st;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> top[i];
	}

	for (int i = 1; i <= N; i++) {
		if (st.empty()) {
			cout << st.size() << " ";
			st.push({ top[i], i });
		}
		else if (top[i] >= st.top().first) {
			while (!st.empty() && st.top().first <= top[i]) st.pop();
			if (!st.empty())
				cout << st.top().second << " ";
			else
				cout << "0 ";
			st.push({top[i], i});
		}
		else if (top[i] < st.top().first) {
			cout << st.top().second << " ";
			st.push({ top[i],i });
		}
	}
}