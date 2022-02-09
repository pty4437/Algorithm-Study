#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str;


	while (true) {
		string tmp = "";
		bool flag = true;

		cin >> str;

		if (str == "#")
			break;

		for (int i = str.size() - 1; i >= 0; i--) {
			if (str[i] == 'b')
				tmp += 'd';
			else if (str[i] == 'd')
				tmp += 'b';
			else if (str[i] == 'p')
				tmp += 'q';
			else if (str[i] == 'q')
				tmp += 'p';
			else if (str[i] == 'i' || str[i] == 'o' || str[i] == 'v' || str[i] == 'w' || str[i] == 'x')
				tmp += str[i];
			else {
				flag = false;
				break;
			}
		}

		if (flag == false)
			cout << "INVALID\n";
		else
			cout << tmp << "\n";
	}

	return 0;
}