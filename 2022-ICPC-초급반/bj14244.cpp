#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int n, m;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n - m; i++)
		printf("%d %d\n", i, i + 1);

	int num = n - m;

	for(int i = n-m; i < n-1; i++)
		printf("%d %d\n", num, i + 1);
}