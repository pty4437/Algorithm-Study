#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
	int N;
	vector<string> v;
	string tmp;

	cin >> N;
	getline(cin, tmp);

	for (int i = 0; i < N; i++) {
		getline(cin, tmp);
		v.push_back(tmp);
	}

	for (int i = 0; i < N; i++) {
		bool table[26] = { false };
		bool flag = false;

		for (int j = 0; j < v[i].size(); j++) {
			if (v[i][j] >= 65 && v[i][j] <= 90)
				table[v[i][j] - 65] = true;
			else if (v[i][j] >= 97 && v[i][j] <= 122)
				table[v[i][j] - 97] = true;
		}

		for (int j = 0; j < 26; j++) {
			if (table[j] == false) {
				if (flag == false) {
					printf("missing ");
					flag = true;
				}

				printf("%c", j + 97);
			}
		}

		if (flag == false) {
			printf("pangram");
		}
		printf("\n");
	}
}