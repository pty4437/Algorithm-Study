#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool palin(string str) {
	int size = str.size() / 2;

	for (int i = 0; i < size; i++) {
		if (str[i] != str[str.size() - i - 1])
			return false;
	}

	return true;
}

int main(void) {
	int T, k;
	string tmp;

	cin >> T;

	while (T--) {
		vector<string> v;
		bool flag = false;
		cin >> k;

		while (k--) {
			cin >> tmp;
			v.push_back(tmp);
		}

		for (int i = 0; i < v.size(); i++) {
			for (int j = i+1; j < v.size(); j++) {
				if (palin(v[i] + v[j]) == true) {
					cout << v[i] + v[j] << "\n";
					flag = true;
					break;
				}

				if (palin(v[j] + v[i]) == true) {
					cout << v[j] + v[i] << "\n";
					flag = true;
					break;
				}
			}

			if (flag == true)
				break;
		}

		if (flag == false)
			printf("0\n");
	}
}