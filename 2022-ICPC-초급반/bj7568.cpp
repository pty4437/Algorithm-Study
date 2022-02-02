#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N;
int arr[52];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	vector<pair<int, int>> info(N);

	for (int i = 0; i < N; i++) {
		cin >> info[i].first >> info[i].second;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)
				continue;
			else {
				if (info[i].first < info[j].first && info[i].second < info[j].second)
					arr[i]++;
			}
		}
	}

	for (int i = 0; i < N; i++)
		cout << arr[i]+1 << " ";
}