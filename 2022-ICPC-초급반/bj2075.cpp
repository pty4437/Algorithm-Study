#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

int N;
priority_queue<int, vector<int>, greater<int>> q;

int solve() {
	int num;

	for (int i = 0; i < N * N; i++) {
		cin >> num;

		if (q.size() < N) {
			q.push(num);
		}
		else if (q.top() < num) {
			q.pop();
			q.push(num);
		}
	}



	return q.top();
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	cout << solve();
}