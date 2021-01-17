#include <bits/stdc++.h>
using namespace std;

int f() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i<n; i++) cin >> a[i];
	int dp[n+1];
	dp[0] = max(0, a[0]);
	for(int i = 1; i<n; i++){
		dp[i] = max(dp[i-1]+a[i], a[i]);
	}
	int ans = dp[0];
	for(int i = 1; i<n; i++) ans = max(ans, dp[i]);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cout << f() << '\n';
	}
	return 0;
}
