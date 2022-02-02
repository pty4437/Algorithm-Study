#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;

int N, S, arr[25];
int ans = 0, sum = 0;

void dfs(int idx) {
	if (idx == N) return;
	if (sum + arr[idx] == S) ans++;
	dfs(idx + 1);
	sum += arr[idx];
	dfs(idx + 1);
	sum -= arr[idx];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> S;
	
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	dfs(0);

	cout << ans;
}