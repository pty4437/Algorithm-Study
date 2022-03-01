#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;
string str;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true) {
		getline(cin, str);
		bool flag = true;

		if (str == ".")
			break;

		stack<char> stk;

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(' || str[i] == '[')
				stk.push(str[i]);
			else if (str[i] == ')' || str[i] == ']') {
				if (stk.empty()) {
					flag = false;
					break;
				}
				
				char tmp = stk.top(); stk.pop();

				if (str[i] == ')') {
					if (tmp != '(') {
						flag = false;
						break;
					}
				}
				else if (str[i] == ']') {
					if (tmp != '[') {
						flag = false;
						break;
					}
				}
			}
		}

		if (!stk.empty())
			flag = false;

		if (flag == false)
			cout << "no\n";
		else
			cout << "yes\n";
	}
}