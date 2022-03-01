#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, i, j; 
int tmp, arr[10001];

bool compare(short A, short B) {
	return A < B;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	while (N--) {
		cin >> tmp;
		arr[tmp]++;
	}

	for (i = 1; i <= 10000; i++) {
		for (j = 0; j < arr[i]; j++)
			cout << i << "\n";
	}
}