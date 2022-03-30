#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;

int N;
string str, tmp;
vector<string> v;

bool compare(string A, string B) {
	if (A.size() == B.size())
		return A < B;

	return A.size() < B.size();
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	while (N--) {
		cin >> str;
		v.push_back(str);
	}

	sort(v.begin(), v.end(), compare);
	v.erase(unique(v.begin(), v.end()), v.end());

	for (string x : v) {
		//if (x == tmp) continue;

		cout << x << "\n";
		//tmp = x;
	}
}