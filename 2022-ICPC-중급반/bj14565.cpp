#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

long long plu, mul, y;

long long GCD(long long x, long long y) {
	if (!y)return x;
	return GCD(y, x % y);
}

long long EX_GCD(long long a, long long b, long long& x, long long& y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}
	long long ret = EX_GCD(b, a % b, x, y);
	long long temp = y;

	y = x - (a / b) * y;
	x = temp;

	if (x <= 0) {
		x += b;
		y -= a;
	}

	return ret;
}

int main(void) {
	long long N, A;

	//N°ú AÀÔ·Â
	scanf("%lld %lld", &N, &A);

	plu = N - A;
	mul = 0;

	if (GCD(N, A) != 1)mul = -1;
	else EX_GCD(A, N, mul, y);
	
	printf("%lld %lld\n", plu, mul);


}