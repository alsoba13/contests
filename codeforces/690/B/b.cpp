#include <bits/stdc++.h>
using namespace std;

bool f() {
	int n;
	string s, t = "2020";
	cin >> n >> s;
	int b = 0, e = 0;
	for(int i = 0; i<4; i++) {
		if(s[i]==t[i]) b++;
		else break;
	}
	for(int i = n-1, j = 3; i>=n-4; i--, j--) {
		if(s[i]==t[j]) e++;
		else break;
	}
	return e+b>=4;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cout << (f() ? "YES" : "NO") << endl;
	}
	return 0;
}