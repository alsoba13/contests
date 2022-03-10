#include <bits/stdc++.h>
using namespace std;

int g(int x, int a) {
	return x/a + x%a;
}

int f() {
	int l, r, a;
	cin >> l >> r >> a;
	int sol = g(r, a);
	int x = r-(r+1)%a;
	if(x >= l)
		sol = g(x, a);
	return sol;
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
