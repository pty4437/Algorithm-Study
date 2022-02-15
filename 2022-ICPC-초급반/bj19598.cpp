#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

int N, a, b;
priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int, int>> v;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for(int i = 0; i < N; i++){
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end());
	
	pq.push(v[0].second);

	int res = 1;

	for (int i = 1; i < N; i++) {
		while (!pq.empty() && pq.top() <= v[i].first)
			pq.pop();

		pq.push(v[i].second);
		res = max(res, (int)pq.size());
	}

	cout << res;
}