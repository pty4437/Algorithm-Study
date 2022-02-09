#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str;
	int flag = 0;

	getline(cin, str);

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'U' && flag == 0)
			flag++;
		if (str[i] == 'C' && flag == 1)
			flag++;
		if (str[i] == 'P' && flag == 2)
			flag++;
		if (str[i] == 'C' && flag == 3)
			flag++;
	}

	if (flag == 4)
		cout << "I love UCPC";
	else
		cout << "I hate UCPC";
}