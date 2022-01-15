#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int A, int B) {
	return A > B;
}

int main(void) {
	int N, tmp;
	vector<int> v;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		v.push_back(tmp);
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size() - 2; i++) {
		if (v[i] < v[i + 1] + v[i + 2]) {
			printf("%d\n", v[i] + v[i + 1] + v[i + 2]);
			return 0;
		}
	}

	printf("-1\n");
}