#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;

ll N, P, Q;
map<ll, ll> mp;

ll func(ll n) {
	if (mp.count(n))
		return mp[n];
	else
		return mp[n] = func(n / P) + func(n / Q);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> P >> Q;

	mp[0] = 1;
	cout << func(N);
	
}