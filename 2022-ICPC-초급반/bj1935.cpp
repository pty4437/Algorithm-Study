#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;
typedef long long ll;

int N;
string str;
double arr[27];
stack<double> stk;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cin >> str;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < str.size(); i++) {
		double a, b;

		if (str[i] >= 'A' && str[i] <= 'Z') {
			stk.push(arr[str[i] - 'A']);
		}
		else {
			a = stk.top(); stk.pop();
			b = stk.top(); stk.pop();

			if (str[i] == '*') {
				stk.push(a * b);
			}
			else if (str[i] == '+') {
				stk.push(a + b);
			}
			else if (str[i] == '-') {
				stk.push(b - a);
			}
			else if (str[i] == '/') {
				stk.push(b / a);
			}
		}
	}

	printf("%.2lf\n", stk.top());

}