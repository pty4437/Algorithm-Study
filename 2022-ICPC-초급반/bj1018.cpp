#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N, M;
char map[51][51], whiteCase[8][8], blackCase[8][8];
int blackCnt[51][51], whiteCnt[51][51];
int res = 987654321;
char enter;
bool flag = false;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0) {
			whiteCase[i][0] = 'W';
			blackCase[i][0] = 'B';
		}
		else {
			whiteCase[i][0] = 'B';
			blackCase[i][0] = 'W';
		}

		for (int j = 1; j < 8; j++) {
			if (whiteCase[i][j - 1] == 'W') whiteCase[i][j] = 'B';
			else whiteCase[i][j] = 'W';
		
			if (blackCase[i][j - 1] == 'W') blackCase[i][j] = 'B';
			else blackCase[i][j] = 'W';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}	
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i + 7 >= N || j + 7 >= M) continue;


			for (int x = i; x < i + 8; x++) {
				for (int y = j; y < j + 8; y++) {
					if (map[x][y] != whiteCase[x - i][y - j]) whiteCnt[i][j]++;		
					if (map[x][y] != blackCase[x - i][y - j]) blackCnt[i][j]++;
				}
			}

			res = min(res, min(blackCnt[i][j],whiteCnt[i][j]));
		}
	}

	cout << res;
}