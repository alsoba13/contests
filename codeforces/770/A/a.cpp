#include <bits/stdc++.h>
using namespace std;

int f() {
	int n, k; string s, s_rev;
	cin >> n >> k >> s;
	s_rev = string(s);
	reverse(s_rev.begin(), s_rev.end());
	if (s_rev == s || 0 == k) return 1;
	return 2;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		//slv();
		cout << f() << '\n';
	}
	return 0;
}
