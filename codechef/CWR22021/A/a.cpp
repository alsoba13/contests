#include <bits/stdc++.h>
using namespace std;

int f() {
	int n, m;
	cin >> n >> m;
	return n*m/2;
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
