#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool dp[1002];

int main(void) {
	int N;

	cin >> N;

	//true = 상근, false = 창영
	dp[1] = dp[3] = true;
	dp[2] = false;
	
	for (int i = 4; i <= N; i++) {
		if (dp[i - 1] == true || dp[i - 3] == true) dp[i] = false;
		else dp[i] = true;
	}

	if (dp[N] == true)
		cout << "SK";
	else
		cout << "CY";
}