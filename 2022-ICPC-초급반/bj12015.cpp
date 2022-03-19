#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N;
vector<int> seq, res;

void binary_search(int num) {
	int low = 0, high = res.size() - 1, mid;
	int ret = 987654321;

	while (low <= high) {
		mid = (low + high) / 2;
		
		if (res[mid] >= num) {
			if (ret > mid)
				ret = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}

	res[ret] = num;
}

void find() {
	res.push_back(seq[0]);

	for (int i = 1; i < seq.size(); i++) {
		if (res.back() < seq[i])
			res.push_back(seq[i]);
		else
			binary_search(seq[i]);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	int tmp;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		seq.push_back(tmp);
	}

	find();

	cout << res.size();
}