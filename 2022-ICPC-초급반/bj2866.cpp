#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

char table[1002][1002];
long long val_table[1002] = { 0 };

long long POW(long long A, long long B) {
	long long res = 1;

	for (int i = 0; i < B; i++)
		res *= A;

	return res;
}

int main(void) {
	int R, C;
	char c;
	int res = 0;

	cin >> R >> C;

	scanf("%c", &c);

	for(int i = 0; i < R; i++){
		for (int j = 0; j < C; j++) {
			scanf("%c", &table[i][j]);
		}
		scanf("%c", &c);
	}

	//printf("%s\n", table[0]);

	for (int i = 0; i < C; i++) {
		for (int j = 1; j < R; j++) {
			val_table[i] += (table[j][i] - 96) * POW(27, R - j - 1);
		}
	}

	for (int i = 1; i < R; i++) {
		for (int j = 0; j < C; j++) {
			for (int k = j + 1; k < C; k++) {
				if (val_table[j] == val_table[k]) {
					printf("%d\n", res);
					return 0;
				}
			}
		}

		res++;

		for (int j = 0; j < C; j++) {
			//printf("sss : %d\n", table[i][j] - 96);
			val_table[j] -= (table[i][j] - 96) * POW(27, R - i - 1);
			//printf("%lld\n", val_table[j]);
		}
	}

	printf("%d\n", res);
	return 0;

}