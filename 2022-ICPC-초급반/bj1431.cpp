#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;

ll N;

bool compare(string A, string B) {
	if (A.size() < B.size())
		return true;
	else if (A.size() > B.size())
		return false;
	
	else {
		int sumA = 0, sumB = 0;

		for (int i = 0; i < A.size(); i++) {
			if (A[i] >= '0' && A[i] <= '9')
				sumA += A[i] - '0';
			if (B[i] >= '0' && B[i] <= '9')
				sumB += B[i] - '0';
		}

		if (sumA > sumB)
			return false;
		else if (sumA < sumB)
			return true;
		else {
			for (int i = 0; i < A.size(); i++) {
				if (A[i] != B[i]) {
					if (A[i] < B[i])
						return true;
					else
						return false;
				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	vector<string> v;

	while (N--) {
		string tmp;

		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end(), compare);

	//sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";
}