#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;
typedef long long ll;

int N, K;
int visited[101010], route[101010];
vector<int> res;

void bfs(int start) {
	list<int> q;
	q.push_front(start);
	visited[start] = 1;

	while (!q.empty()) {
		int cur = q.back(); q.pop_back();

		if (cur == K) break;

		if (!visited[cur + 1]) {
			q.push_front(cur + 1); visited[cur + 1] = 1; route[cur + 1] = cur;
		}
		if (cur-1 >= 0 && !visited[cur - 1]) {
			q.push_front(cur - 1); visited[cur - 1] = 1; route[cur - 1] = cur;
		}
		if (cur * 2 < 101010 && !visited[cur * 2] && cur != 0) {
			q.push_front(cur * 2); visited[cur * 2] = 1; route[cur*2] = cur;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	if (N > K) {
		cout << N - K << "\n";
		for (int i = N; i >= K; i--)
			cout << i << " ";
		return 0;
	}

	bfs(N);

	int idx = K;

	while (idx != 0) {
		res.push_back(idx);
		idx = route[idx];
	}

	if (N == 0)
		res.push_back(N);

	cout << res.size()-1 << "\n";

	for (int i = res.size() - 1; i >= 0; i--)
		cout << res[i] << " ";
}