#include <bits/stdc++.h>
using namespace std;

bool f() {
	int a, b, c;
	cin >> a >> b >> c;
	if ((a + b + c) % 9 != 0) return false;
	int k = (a + b + c)/9;
	if ( a < k || b < k || c < k) return false;
	return true;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cout << (f()? "YES":"NO") << endl;
	}
	return 0;
}