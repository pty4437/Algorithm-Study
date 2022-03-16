#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
typedef long long ll;

int n, num;
vector<int> seq;
vector<char> oper;
stack<int> st;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> num;
		seq.push_back(num);
	}

	num = 1;

	for (int i = 0; i < seq.size(); i++) {
		if (st.empty() || st.top() < seq[i]) {
			if (st.empty()) {
				oper.push_back('+');
				st.push(num);
				num += 1;
			}

			while (st.top() != seq[i]) {
				if (num > seq[i]) {
					cout << "NO";
					return 0;
				}
				oper.push_back('+');
				st.push(num);
				num += 1;
			}
			oper.push_back('-');
			st.pop();
		}
		else if (st.top() == seq[i]) {
			oper.push_back('-');
			st.pop();
		}
		else if(st.top() > seq[i]){
			while (st.top() != seq[i]) {
				oper.push_back('-');
				st.pop();
			}
			oper.push_back('-');
			st.pop();
		}
	}

	for (int i = 0; i < oper.size(); i++) {
		cout << oper[i] << "\n";
	}
}