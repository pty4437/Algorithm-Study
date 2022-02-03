#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
typedef long long ll;

int n;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	vector<pair<int, int>> v(n);
	vector<int> xlist;

	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
		xlist.push_back(v[i].first);
		xlist.push_back(v[i].second);
	}

	sort(xlist.begin(), xlist.end());
	xlist.erase(unique(xlist.begin(), xlist.end()), xlist.end());

	for (int i = 0; i < n; i++) {
		v[i].first = (lower_bound(xlist.begin(), xlist.end(), v[i].first) - xlist.begin());
		v[i].second = (lower_bound(xlist.begin(), xlist.end(), v[i].second) - xlist.begin());
	}

	int arr[20005] = { -1 };
	int cnt = 1;

	for (int i = 0; i < n; i++) {
		for (int j = v[i].first; j <= v[i].second; j++) {
			arr[j] = cnt;
		}

		cnt++;
	}

	int res = 0;
	bool check[20005] = { false };


	for (int i = 0; i < 20005; i++) {
		if (arr[i] != 0 && !check[arr[i]]) {
			check[arr[i]] = true;
			res++;
		}
	}

	cout << res;
}