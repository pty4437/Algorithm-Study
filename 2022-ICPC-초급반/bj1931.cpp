#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N;
vector<pair<int, int>> v;

bool compare(pair<int, int> A, pair<int, int> B) {
	if (A.second == B.second)
		return A.first < B.first;

	return A.second < B.second;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	int a, b;

	for (int i = 0; i < N; i++) {
		cin >> a >> b;

		v.push_back(pair<int, int>(a, b));
	}

	sort(v.begin(), v.end(), compare);

	int count = 0, end_time = 0;

	for (int i = 0; i < N; i++) {
		if (end_time <= v[i].first) {
			end_time = v[i].second;
			count++;
		}
	}

	cout << count;
}