#include <bits/stdc++.h>
using namespace std;

long long f() {
	int n;
	cin >> n;
	vector<long long> a(n);
	for(int i = 0; i<n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	return 2*abs(a[0]-a[n-1]);
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
