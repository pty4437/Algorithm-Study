#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

int N, K;

double func() {
	double pr = N;
	int A;

	for (int i = 0; i < K; i++) {
		scanf("%d", &A);
		double temp = 0.000;

		temp += pr * (1.00 - (double)A / N);
		temp += (N - pr) * ((double)A / N);

		pr = temp;
	}

	return pr;
}

int main(void) {
	scanf("%d", &N); scanf("%d", &K);
	cout << fixed;
	cout.precision(13);
	cout << func();
}