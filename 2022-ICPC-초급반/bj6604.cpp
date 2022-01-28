#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;
typedef long long ll;

typedef struct mat {
	char name;
	ll row;
	ll col;
} MAT;

ll T, r, c;
char n;

bool compare(MAT A, MAT B) {
	return A.name < B.name;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	vector<MAT> mat_arr(T);


	for (int i = 0; i < T; i++) {
		cin >> mat_arr[i].name >> mat_arr[i].row >> mat_arr[i].col;
	}

	sort(mat_arr.begin(), mat_arr.end(), compare);

	string input;
	MAT tmp, pu, a, b;

	getline(cin, input);

	while (getline(cin, input)) {
		ll res = 0;
		bool flag = true;
		stack<MAT> stack;

		for (int i = 0; i < input.size(); i++) {
			tmp.name = input[i];
			if (tmp.name == '(' || tmp.name == ')') {
				tmp.row = tmp.col = -1;
			}
			else {
				tmp.row = mat_arr[tmp.name - 'A'].row;
				tmp.col = mat_arr[tmp.name - 'A'].col;
			}

			stack.push(tmp);

			if (input[i] == ')') {
				stack.pop();

				b = stack.top(); stack.pop();
				a = stack.top(); stack.pop();

				if (a.col != b.row) {
					cout << "error" << "\n";
					flag = false;
					break;
				}

				else {
					res += a.row * a.col * b.col;
				}

				stack.pop();
				pu.row = a.row;
				pu.col = b.col;
				stack.push(pu);
			}
		}

		if(flag == true)
			cout << res << "\n";
	}

	return 0;
}