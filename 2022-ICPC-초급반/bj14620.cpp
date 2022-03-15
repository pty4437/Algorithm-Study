#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <stdlib.h>

using namespace std;
typedef long long ll;

int N, cnt = 0, tmp = 0, res = 987654321;
int map[12][12];
vector<pair<pair<int, int>, int>> v;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != 1 && j != 1 && i != N && j != N)
				v.push_back({ { i, j }, map[i][j] + map[i + 1][j] + map[i - 1][j] + map[i][j + 1] + map[i][j - 1] });
		}
	}

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			for (int k = 0; k < v.size(); k++) {
				if (i == j || j == k || i == k) continue;

				int dist1 = abs(v[i].first.first - v[j].first.first) + abs(v[i].first.second - v[j].first.second);
				int dist2 = abs(v[i].first.first - v[k].first.first) + abs(v[i].first.second - v[k].first.second);
				int dist3 = abs(v[k].first.first - v[j].first.first) + abs(v[k].first.second - v[j].first.second);

				if (dist1 <= 2 || dist2 <= 2 || dist3 <= 2) continue;
				else {
					tmp = v[i].second + v[j].second + v[k].second;
					res = min(res, tmp);
				}
			}
		}
	}

	cout << res;
}