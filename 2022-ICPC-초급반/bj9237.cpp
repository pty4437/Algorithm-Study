#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(int A, int B) {
	return A > B;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	int val = 0;

	cin >> N;
	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		v[i] += i;

		val = max(val, v[i]);
	}

	cout << val + 2;
}