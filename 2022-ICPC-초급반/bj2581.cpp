#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N, M, sum = 0, minVal = 987654321;
int arr[10001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cin >> M;

	arr[1] = 1;

	for (int i = 2; i <= 10000; i++) {
		for (int j = i + i; j <= 10000; j += i) {
			arr[j] = 1;
		}
	}

	for (int i = N; i <= M; i++) {
		if (!arr[i]) {
			minVal = min(minVal, i);
			sum += i;
		}
	}

	if (sum != 0) {
		cout << sum << endl;
		cout << minVal << endl;
	}
	else
		cout << -1;
}