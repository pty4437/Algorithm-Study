#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;


long long POW(long long A, long long B) {

	long long res = 1;

	for (long long i = 0; i < B; i++) {
		res *= A;
	}

	return res;
}

int main(void) {
	long long N, M;

	scanf("%lld", &N);
	scanf("%lld", &M);

	string str, pat;

	cin >> str;

	if (str.size() != M) {
		printf("0\n");
		return 0;
	}

	pat = "I";

	for (long long i = 0; i < N; i++) {
		pat += "OI";
	}

	long long pat_val = 0;


	for (long long i = pat.size() - 1; i >= 0; i--) {
		pat_val += (pat[i] - 64) * POW(27, i);
	}

	long long str_val = 0;

	for (long long i = pat.size()-1; i >= 0; i--) {

		str_val += (str[pat.size() - 1 - i] - 64) * POW(27, i);
	}

	long long res = 0;

	if (pat.size() > str.size()) {
		printf("0\n");
		return 0;
	}

	for (long long i = pat.size() - 1; i < str.size(); i++) {
		if (str_val == pat_val)
			res++;

		long long tmp = (str[i - pat.size() + 1] - 64) * POW(27, pat.size() - 1);

		str_val = (str_val - tmp) * 27 + (str[i + 1] - 64);

	}

	cout << res;
}