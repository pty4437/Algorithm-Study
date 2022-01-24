#define _CRT_SECURE_NO_WARNING

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N, K;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	vector<int> v(N);
	vector<int> tmp(N+1);
	int idx = 0;

	for (int i = N; i >= 1; i--) {
		tmp[i] = i;
	}

	for (int i = 0; i < N; i++) {
		if (K - (N - i - 1) >= 0) {
			K -= (N - i - 1);
			v[idx] = N - i;
			idx++;
			tmp[N-i] = 0;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (tmp[i] != 0) {
			//printf("aa\n");
			for (int j = 0; j < N; j++) {
				if (v[j] == 0) {
					v[j] = tmp[i];
					break;
				}
			}
		}
	}


	for (int i = 0; i < N; i++) {
			cout << v[i] << " ";
	}
}