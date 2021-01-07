#include <bits/stdc++.h>
using namespace std;
string f() {
	int n; string s;
	cin >> n >> s;
	sort(s.begin(), s.end());
	return s;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cout << f() << endl;
	}
	return 0;
}