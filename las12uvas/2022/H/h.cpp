#include <bits/stdc++.h>
using namespace std;

long long f() {
	int n, k;
	cin >> n >> k;
	vector<long long> c(n);
	for(int i = 0; i<n; i++) cin >> c[i];
	vector<long long> dp(n);
	dp[0] = c[0];
	for(int i = 1; i<n; i++) {
		long long back = 0;
		if (i>=k+1) back = dp[i-k-1];
		dp[i] = max(c[i]+back, dp[i-1]);
	}
	return dp[n-1];
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
