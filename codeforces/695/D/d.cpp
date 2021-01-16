#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main() {
	int n, k, q;
	cin >> n >> k >> q;
	vector<long long> a(n);
	for(int i = 0; i<n; i++) {
		cin >> a[i];
	}
	long long dp[n][k+1];
	vector<long long> cnt(n);
	for(int i = 0; i<n; i++) dp[i][0] = 1;
	for(int j = 1; j<=k; j++) {
		dp[0][j] = dp[1][j-1];
		for(int i = 1; i<n-1; i++){
			dp[i][j] = (dp[i+1][j-1]+dp[i-1][j-1])%MOD;
		}
		dp[n-1][j] = dp[n-2][j-1];
	}
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= k; j++) {
            cnt[i] += (dp[i][j] * dp[i][k - j])%MOD;
			cnt[i] %= MOD;
		}
	long long ans = 0;
	for(int i = 0; i<n; i++) {
		ans += (cnt[i]*a[i])%MOD;
		ans %= MOD; 
	}
	for(int i = 0; i<q; i++) {
		long long j, v;
		cin >> j >> v;
		j--;
		ans -= (cnt[j]*a[j])%MOD;
		ans = (ans + MOD)%MOD;
		a[j] = v;
		ans += (cnt[j]*a[j])%MOD;
		ans %= MOD;
		cout << ans << endl;
	}
}
