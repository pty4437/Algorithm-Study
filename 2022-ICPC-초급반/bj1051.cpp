#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>

using namespace std;
typedef long long ll;

int N, M;
int res = 1;
int arr[51][51];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	string tmp;

	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		for (int j = 1; j <= M; j++) {
			arr[i][j] = tmp[j - 1] - 48;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			for (int num = 1; num <= min(N, M); num++) {
				int x = i + num, y = j + num;

				if (x <= N && y <= M) {
					if (arr[i][j] == arr[x][j] && arr[i][j] == arr[x][y] && arr[i][j] == arr[i][y]) {
						res = max(res, (num + 1) * (num + 1));
					}
				}
			}
		}
	}

	cout << res;
}