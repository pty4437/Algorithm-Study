#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;
const int MAX = 1000002;
int N;
double dp[MAX];

double func(int n) {
	if(n <= 0) return 0.0;
	double &res = dp[n];
	if (res >= 0.0) return res;
	res = 0.0;

	for (int i = 1; i <= 6; i++)
		res += (func(n - i) + 1) / 6.0;

	return res;
}

int main(void) {
	memset(dp, -1, sizeof(dp));
	cin >> N;
	cout << fixed;
	cout.precision(13);
	cout << func(N);
}