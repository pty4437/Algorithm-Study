#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string str;

bool palin(string s) {
	if (s.size() == 1) return true;

	string left, right;
	int half = s.size() / 2;

	for (int i = 0; i < half; i++) {
		left += s[i];
	}

	if (s.size() % 2 == 1)
		half++;

	for (int i = half; i < s.size(); i++) {
		right += s[i];
	}

	if (left != right) return false;
	if (palin(left) && palin(right)) return true;
	
	return false;

}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> str;

	if (palin(str)) cout << "AKARAKA";
	else cout << "IPSELENTI";

	return 0;
}