#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	unsigned int T;
	long long N;

	scanf("%d", &T);

	while (T--) {
		scanf("%lld", &N);
		if ((N % 3 == 2) || (N % 9 == 0)) printf("TAK\n");
		else printf("NIE\n");
	}


}