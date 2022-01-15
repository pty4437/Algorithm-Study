#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(string A, string B) {
	return A < B;
}

int main(void) {
	string str;

	cin >> str;

	vector<string> v;
	int size = str.size();

	for (int i = 0; i < size; i++) {
		v.push_back(str);

		str = str.substr(1, str.size());
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
}