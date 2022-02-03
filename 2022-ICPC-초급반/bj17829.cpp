#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll N;
int arr[1025][1025];

int dnc(int r, int c) {
	vector<int> v;
	for (int i = r; i < r + 2; i++)
		for (int j = c; j < c + 2; j++)
			v.push_back(arr[i][j]);
	sort(v.begin(), v.end());
	return v[2];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}


	while (N > 1) {
		for (int i = 0; i < N; i += 2) {
			for (int j = 0; j < N; j += 2) {
				arr[i / 2][j / 2] = dnc(i, j);
			}
		}
		N /= 2;
	}

	cout << arr[0][0];
}
