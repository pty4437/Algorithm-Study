#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long POW(long long A, long long B) {
	/*
	long long res = 1;

	for (int i = 0; i < B; i++)
		res *= A;

	return res;*/

	long long res = 1;
	while (B) {
		if (B & 1)
			res *= A;
		B >>= 1;
		A *= A;
	}

	return res;
}

int main(void) {
	string S, P;
	long long str_val = 0, pat_val = 0;

	cin >> S;
	cin >> P;

	long long Psize = P.size();

	for (int i = 0; i < Psize; i++) {
		pat_val += (P[i] - 96) * POW(27, Psize - i - 1);
		str_val += (S[i] - 96) * POW(27, Psize - i - 1);
	}

	for (int i = Psize - 1; i < S.size(); i++) {
		if (pat_val == str_val) {
			printf("1\n");
			return 0;
		}

		long long tmp = (S[i - Psize + 1] - 96) * POW(27, Psize - 1);
		str_val = (str_val - tmp) * 27 + (S[i + 1] - 96);
	}

	printf("0\n");
	return 0;
}