#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n;
	int tmp;

	scanf("%d", &n);
	vector<int> arr(2020202);
	vector<bool> checked(2020202);

	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		arr[tmp]++;
	}
	if (!arr[0]) {
		printf("0\n");
		return 0;
	}
	if (!arr[1]) {
		printf("1\n");
		return 0;
	}
	for (int i = 1; i < 2020202; i++) {
		if (!arr[i]) continue;
		for (int j = 1; j < 2020202; j++) {
			if (i * j > 2020202) break;
			if (!arr[j]) continue;
			checked[i * j] = true;
		}
	}

	for (int i = 2; i < 2020202; i++) {
		if (checked[i]) continue;
		printf("%d\n", i);
		return 0;
	}

}