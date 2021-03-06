#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e15;

long long f() {
	int n; long long u, v;
	cin >> n >> u >> v;
	vector<int> a(n);
	for(int i = 0; i<n; i++) cin >> a[i];
	vector<long long> dp(n, INF);
	for(int i = 1; i<n; i++){
		if(abs(a[i]-a[i-1])>1) dp[i] = 0;
		else{
			if(a[i]==a[i-1]) dp[i] = min(dp[i-1], min(2*v, u+v));
			else if (abs(a[i]-a[i-1])==1) dp[i] = min(dp[i-1], min(u, v));
		}
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
