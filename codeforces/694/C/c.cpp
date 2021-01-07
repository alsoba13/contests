#include <bits/stdc++.h>
using namespace std;

long long f() {
	int n, m;
	cin >> n >> m;
	vector<long long> c(m), k(n);
	for(int i = 0; i<n; i++) {
		cin >> k[i];
		k[i]--;
	}
	for(int i = 0; i<m; i++) cin >> c[i];
	int present = 0;
	long long ans = 0;
	sort(k.rbegin(), k.rend());
	for(int i = 0; i<n; i++) {
		if (present <= k[i] && c[present]<c[k[i]]) {
			ans += c[present];
			present++;
		} else {
			ans += c[k[i]];
		}
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cout << f() << endl;
	}
	return 0;
}
