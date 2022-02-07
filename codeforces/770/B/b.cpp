#include <bits/stdc++.h>
using namespace std;

bool f() {
	long long n, x, y;
	cin >> n >> x >> y;
	vector<long long> a(n);
	for(int i = 0; i<n; i++) cin >> a[i];
	for(int i = 0; i<n; i++) x ^= a[i];
	return x%2 == y%2;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		//slv();
		cout << (f()?"Alice":"Bob") << '\n';
	}
	return 0;
}
