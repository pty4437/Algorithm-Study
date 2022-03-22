#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N, M, r = 0, l = 0;
//vector<int> gui;
int gui[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> gui[i];
		r += gui[i];
		l = max(l, gui[i]);
	}

	while (l <= r) {
		int mid = (l + r) / 2;

		int sum = 0, cnt = 0;
		for (int i = 0; i < N; i++) {
			if (sum + gui[i] > mid) {
				sum = 0; cnt++;
			}
			sum += gui[i];
		}

		if (sum != 0) cnt++;

		if (cnt > M)
			l = mid + 1;
		else
			r = mid - 1;
	}

	cout << l;
}