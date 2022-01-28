#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <deque>

using namespace std;
typedef long long ll;

ll N, K;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	vector<char> num_vec;
	deque<char> dq;
	char tmp, tmp2;

	cin >> tmp;
	dq.push_back(tmp);
	int idx = 0;

	for (int i = 1; i < N; i++) {
		//cin >> num_vec[i];
		cin >> tmp;

		if (dq[idx] < tmp) {
			if (K > 0) {
				while (idx >= 0 && tmp > dq[idx] && K > 0) {
					//printf("%d\n", idx);
					dq.erase(dq.begin() + idx);
					K--;
					idx--;
				}
				
			}
			dq.push_back(tmp);
			idx++;
			//K--;
		}
		else {
			dq.push_back(tmp);
			idx++;
		}
	}


	while (K--) {
		dq.pop_back();
	}
	/*
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < num_vec.size() - 1; j++) {
			if (num_vec[j] < num_vec[j + 1]) {
				num_vec.erase(num_vec.begin() + j);
				break;
			}
		}
	}*/

	for (int i = 0; i < dq.size(); i++)
		cout << dq[i];
}