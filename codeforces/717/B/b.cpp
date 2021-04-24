#include <bits/stdc++.h>
using namespace std;
bool f() {
	int n;
	cin >> n;
	vector<long long> a(n);
	for(int i = 0; i<n; i++) cin >> a[i];
	long long ans = 0;
	for(int i = 0; i<n; i++) ans ^= a[i];
	if(ans == 0) return true;
	long long xr = 0;
	int cnt = 0;
	for(int i = 0; i<n; i++) {
		xr ^= a[i];
		if(xr == ans) {
			cnt++;
			xr = 0;
		}
	}
	return cnt > 1;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		//slv();
		cout << (f()?"YES":"NO") << '\n';
	}
	return 0;
}
