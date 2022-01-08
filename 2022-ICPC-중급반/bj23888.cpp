#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

long long GCD(long long x, long long y) {
	if (!y)return x;
	return GCD(y, x % y);
}

int main(void) {
	long long a, d, q, query_num, l, r;;

	//초항 a와 공차 d입력
	scanf("%lld %lld", &a, &d);

	vector<long long>pre(1010101);
	pre[1] = a;

	for (unsigned int i = 2; i < 1010101; i++)pre[i] = pre[i - 1] + a + (i - 1) * d;
	long long gcd = GCD(a, d);

	//쿼리 개수 q입력
	scanf("%lld", &q);

	while(q--){
		//쿼리 입력
		scanf("%lld %lld %lld", &query_num, &l, &r);

		//1번 쿼리
		if (query_num == 1)
			printf("%lld\n", pre[r] - pre[l - 1]);
		//2번 쿼리
		else{
			if (l == r) printf("%lld\n",a + (l - 1) * d);
			else printf("%lld\n", gcd);
		}
	}

}
