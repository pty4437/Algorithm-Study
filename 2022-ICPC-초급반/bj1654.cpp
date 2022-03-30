#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N, K, tmp;
vector<int> lan;

int bin_search() {
	ll start = 0, end = 2147483647;
	ll mid;

	while (start <= end) {
		mid = (start + end) / 2;
		int cnt = 0;

		for (int x : lan) {
			cnt += x / mid;
		}

		if (cnt < N)
			end = mid - 1;
		else
			start = mid + 1;
	}

	return end;
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> K >> N;

	while (K--) {
		cin >> tmp;
		lan.push_back(tmp);
	}

	cout << bin_search();
}