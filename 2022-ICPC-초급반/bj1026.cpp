#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//bool compare(pair<int, int> A, pair<int, int> B) {
	//return A.
//}
bool compare_A(int A, int B) {
	return A < B;
}

bool compare_B(int A, int B) {
	return A > B;
}

int main(void) {
	int N;

	scanf("%d", &N);

	//vector<pair<int, int>> v;
	vector<int> first;
	vector<int> second;

	int tmp;

	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		//v.push_back(pair<int, int>(tmp, 0));
		first.push_back(tmp);
	}

	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		//v[i].second = tmp;
		second.push_back(tmp);;
	}

	// sort(v.begin(), v.end(), compare);
	sort(first.begin(), first.end(), compare_A);
	sort(second.begin(), second.end(), compare_B);

	int res = 0;

	for (int i = 0; i < N; i++) {
		res += first[i] * second[i];
	}

	printf("%d", res);
}