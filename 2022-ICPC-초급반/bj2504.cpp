#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
typedef long long ll;

string str;
stack<char> st;
int value = 1, res = 0, tmp_res = 0;
bool flag = true;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> str;

	//st.push(str[0]);

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			st.push(str[i]);
			value *= 2;
		}
		else if (str[i] == '[') {
			st.push(str[i]);
			value *= 3;
		}
		else if (str[i] == ')') {
			if (st.empty() || st.top() != '(') {
				cout << 0; return 0;
			}
			if (str[i - 1] == '(') {
				res += value;
				value /= 2;
				st.pop();
			}
			else {
				value /= 2;
				st.pop();
			}
		}
		else if (str[i] == ']') {
			if (st.empty() || st.top() != '[') {
				cout << 0; return 0;
			}
			if (str[i - 1] == '[') {
				res += value;
				value /= 3;
				st.pop();
			}
			else {
				value /= 3;
				st.pop();
			}
		}
	}

	if (!st.empty()) {
		cout << 0;
		return 0;
	}

	cout << res;
}