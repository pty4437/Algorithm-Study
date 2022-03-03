#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N, tmp;
vector<int> v;

bool compare(int A, int B) {
	return A < B;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end(), compare);

	int weight = 1;

	for (int i = 0; i < N; i++) {
		
		if (v[i] > weight) {
			break;
		}

		weight += v[i];
	}

	cout << weight;
}