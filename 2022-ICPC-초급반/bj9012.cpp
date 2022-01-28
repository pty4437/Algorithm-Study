#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
typedef long long ll;

ll T;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	while (T--) {
		string str;
		stack<char> stk;
		bool flag = true;

		cin >> str;

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(')
				stk.push(str[i]);
			else {
				if(stk.empty() == false)
					stk.pop();
				else {
					flag = false;
					break;
				}
			}
		}

		if (stk.empty() == false) {
			cout << "NO" << "\n";
		}
		else if(flag == true){
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
		
	}
}