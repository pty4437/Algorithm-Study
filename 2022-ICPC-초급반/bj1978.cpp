#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N, res = 0;
vector<int> v;
int arr[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	int tmp;

	arr[1] = 1;

	for (int i = 2; i <= 1000; i++) {
		for (int j = i*2; j <= 1000; j += i) {
			arr[j] = 1;
		}
	}

	while (N--) {
		cin >> tmp;
		v.push_back(tmp);
	}

	for (int x : v) {
		if (!arr[x]) res++;
	}

	cout << res;
}