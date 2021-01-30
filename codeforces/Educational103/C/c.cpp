#include <bits/stdc++.h>
using namespace std;

long long f() {
	int n;
	cin >> n;
	vector<long long> c(n), a(n), b(n);
	for(int i = 0; i<n; i++) cin >> c[i];
	for(int i = 0; i<n; i++) cin >> a[i];
	for(int i = 0; i<n; i++) cin >> b[i];
	for(int i = 0; i<n; i++){
		int a_=a[i], b_=b[i];
		a[i] = min(a_, b_);
		b[i] = max(a_, b_);
	}
	vector<long long> dp(n, 0);
	for(int i = 1; i<n; i++){
		if(a[i] == b[i]){
			dp[i] = c[i]+1;
		}else{
			dp[i] = max(dp[i-1]-(b[i]-a[i]-1)+c[i], c[i]+b[i]-a[i]+1);
		}
	}
	long long ans = 0;
	for(int i = 0; i<n; i++){
		ans = max(ans, dp[i]);
	}
	return ans;
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
