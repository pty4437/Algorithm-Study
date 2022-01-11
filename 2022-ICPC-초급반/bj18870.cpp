#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>


using namespace std;

bool compare(int A, int B) {
	return A < B;
}

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> vec_tmp;
	vector<int> v;

	int tmp;

	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);

		v.push_back(tmp);
		vec_tmp.push_back(tmp);
	}

	sort(vec_tmp.begin(), vec_tmp.end(), compare);
	vec_tmp.erase(unique(vec_tmp.begin(), vec_tmp.end()), vec_tmp.end());

	for (int i = 0; i < N; i++) {
		auto it = lower_bound(vec_tmp.begin(), vec_tmp.end(), v[i]);
		printf("%d ", it - vec_tmp.begin());
	}
	
}