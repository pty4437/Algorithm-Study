#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdlib>

using namespace std;

bool compare(pair<int, int>A, pair<int, int>B) {

	if (A.first == B.first)
		return A.second > B.second;

	return A.first < B.first;
}

int check[30001];

int main(void) {
	int N, tmp;
	vector<pair<int, int>> v;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		v.push_back(pair<int, int>(tmp, 0));
	}

	if (N == 1) {
		printf("권병장님, 중대장님이 찾으십니다");
		return 0;
	}
	else {
		for (int i = 1; i < N; i++) {
			scanf("%d", &tmp);
			v[i - 1].second = tmp;
		}

		int res = v[N - 1].first;

		sort(v.begin(), v.end(), compare);

		for (int i = 0; i < v.size(); i++) {
			for (int j = i + 1; j < v.size(); j++) {
				if (v[j].first - v[i].first <= v[i].second)
					check[j] = 1;
				else
					break;
			}
		}

		for (int i = 1; i < v.size(); i++) {
			if (!check[i]) {
				printf("엄마 나 전역 늦어질 것 같아");
				return 0;
			}
			else if (res <= v[i].first + v[i].second) {
				printf("권병장님, 중대장님이 찾으십니다");
				return 0;
			}
		}

		printf("권병장님, 중대장님이 찾으십니다");
		return 0;
	}
}