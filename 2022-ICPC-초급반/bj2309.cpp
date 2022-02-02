#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool compare(int a, int b) {
	return a < b;
}

vector<int> v(9);
vector<int> res(7);
int sum = 0;

void search(int idx) {
	if (idx == 5 && sum + v[idx+1] == 100) {
		res.push_back(v[idx+1]);
		for (int i = 0; i < 7; i++)
			cout << res[i] << "\n";
		exit(-1);
	}

	sum += v[idx];
	res.push_back(v[idx]);
	search(idx + 1);

	res.pop_back();
	sum -= v[idx];
	search(idx + 1);
}

int main(void) {

	for (int i = 0; i < 9; i++)
		cin >> v[i];

	sort(v.begin(), v.end(), compare);

	search(0);
}