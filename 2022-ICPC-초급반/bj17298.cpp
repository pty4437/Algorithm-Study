#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;
typedef long long ll;

ll N;
stack<int> stk;
stack<int> print;
stack<int> max_stk;

int tmp;
int val;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for(int i = 0; i < N; i++){
		cin >> tmp;
		stk.push(tmp);
	}

	for (int i = 0; i < N; i++) {
		val = stk.top();
		stk.pop();

		if (max_stk.empty()) {
			print.push(-1);
			max_stk.push(val);
		}
		else {
			while (!max_stk.empty()) {
				if (max_stk.top() > val) {
					print.push(max_stk.top());
					max_stk.push(val);
					break;
				}

				max_stk.pop();
			}

			if (max_stk.empty()) {
				print.push(-1);
				max_stk.push(val);
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		cout << print.top() << " ";
		print.pop();
	}
}