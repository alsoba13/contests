#include <bits/stdc++.h>
using namespace std;

int f() {
	string s;
	cin >> s;
	int odd = 0;
	for(int i = 0; i<s.size(); i++) {
		if((s[i]-'0')%2 == 1) odd++;
	}
	if (odd < 2) return -1;
	return odd%2;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cout << f() << '\n';
	}
	return 0;
}
