#include <bits/stdc++.h>
using namespace std;

int f() {
	int a, b, c;
	cin >> a >> b >> c;
	if ((a+b-2*c)%3 == 0) return 0;
	return 1;
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
