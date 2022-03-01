#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N, M, r, c, d;
int Map[51][51];

int solve() {
	int res = 0, cnt = 0;

	while (true) {
		if (cnt == 4) {
			if (d == 0) r++;
			else if (d == 1) c--;
			else if (d == 2) r--;
			else if (d == 3) c++;

			if (Map[r][c] == 1) break;

			cnt = 0;
		}
		else {
			if (Map[r][c] == 0) {
				res++; Map[r][c] = 2; cnt = 0;
			}

			if (d == 0) d = 3;
			else d--;

			if (d == 0) {
				r--;
				if (Map[r][c] == 1 || Map[r][c] == 2) {
					r++;
					cnt++;
				}
			}
			else if (d == 1) {
				c++;
				if (Map[r][c] == 1 || Map[r][c] == 2) {
					c--;
					cnt++;
				}
			}
			else if (d == 2) {
				r++;
				if (Map[r][c] == 1 || Map[r][c] == 2) {
					r--;
					cnt++;
				}
			}
			else if (d == 3) {
				c--;
				if (Map[r][c] == 1 || Map[r][c] == 2) {
					c++;
					cnt++;
				}
			}
		}
	}

	return res;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	cin >> r >> c >> d;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
		}
	}

	cout << solve();
}