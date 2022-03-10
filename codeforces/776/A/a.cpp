#include <bits/stdc++.h>
using namespace std;

bool f() {
	string s; char c;
	cin >> s >> c;
	for(int i = 0; i<s.size(); i+=2)
		if(s[i] == c) return true;
	return false;
}


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		//slv();
		//cout << f() << '\n';
		cout << (f()?"YES":"NO") << '\n';
	}
	return 0;
}
