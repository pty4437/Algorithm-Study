#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
typedef long long ll;

int N, M;
int arr[10][10];

bool isSquare(int n) {
	int root = (int)sqrt(n);
	if (root * root == n) return true;
	else return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	string tmp;

	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		for (int j = 1; j <= M; j++) {
			arr[i][j] = (int)tmp[j - 1] - 48;
		}
	}

	int res = -1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			for (int x = -N; x < N; x++) {
				for (int y = -M; y < M; y++) {
					if (x == 0 && y == 0)continue;
					int a = i, b = j;
					int now = 0;
					while (a > 0 && a <= N && b > 0 && b <= M) {
						now *= 10;
						now += arr[a][b];
						if (isSquare(now)) res = max(res, now);
						a += x;
						b += y;
					}

					if (isSquare(now)) res = max(res, now);
				}
			}
		}
	}

	cout << res << endl;
}