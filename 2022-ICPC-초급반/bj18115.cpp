#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
typedef long long ll;

ll N;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	vector<int> command(N);
	deque<int> dq;

	for (int i = 0; i < N; i++)
		cin >> command[i];

	int num = 1;

	for (int i = N - 1; i >= 0; i--) {
		if (command[i] == 1) {
			dq.push_front(num);
		}
		else if (command[i] == 2) {
			dq.insert(++dq.begin(), num);
		}
		else if (command[i] == 3) {
			dq.push_back(num);
		}

		num++;
	}

	for (int i = 0; i < N; i++)
		cout << dq[i] << " ";

	cout << "\n";

}