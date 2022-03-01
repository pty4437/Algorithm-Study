#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int n, arr[100001], idx = 1, tmp;
stack<int> stk;


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> tmp;

		if (idx <= tmp) {
			for (int i = idx; i <= tmp; i++) {
				stk.push(i); cout << "+\n";
			}
			idx = tmp;
		}
		else if(idx > tmp){
			if (stk.top() != tmp) {
				cout << "NO\n";
				return 0;
			}
		}

		stk.pop();
		cout << "-\n";
	}
}