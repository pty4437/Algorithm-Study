#define CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N, M;
int arr[100001];
int sol[100001];

int bin_search(int num) {
	int start = 0, end = N-1;
	int mid;

	while (start <= end) {
		mid = (start + end) / 2;

		if (arr[mid] == num)
			return 1;

		if (arr[mid] > num) {
			end = mid - 1;
		}
		else
			start = mid + 1;
	}

	return 0;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	int tmp;
	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}
		
	sort(arr, arr + N);
	cin >> M;

	for (int i = 1; i <= M; i++) {
		cin >> sol[i];
	}

	for (int i = 1; i <= M; i++) {
		cout << bin_search(sol[i]) << "\n";
	}

	return 0;
}