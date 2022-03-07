#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N, M, a, b;
vector<int> package, one;

bool compare(int A, int B) {
	return A < B;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
	
		package.push_back(a);
		one.push_back(b);
	}

	sort(package.begin(), package.end(), compare);
	sort(one.begin(), one.end(), compare);

	int mok = N / 6;
	int na = N % 6;

	cout << min(mok * package[0] + na * one[0], min(N * one[0], (mok+1) * package[0]));
}