#include <bits/stdc++.h>
using namespace std;

int f() {
	int a, b;
	cin >> a >> b;
	if(a == 0) return 1;
	return a+2*b+1;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		//slv();
		cout << f() << '\n';
		//cout << (f()?"YES":"NO") << '\n';
	}
	return 0;
}
