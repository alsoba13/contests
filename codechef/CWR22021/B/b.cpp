#include <bits/stdc++.h>
using namespace std;
#define INF 1e8
int f() {
	int n; 
	cin >> n;
	vector<int> a(n), dp(n, INF);
	for(int i = 0; i<n; i++) cin >> a[i];
	dp[0] = 0;
	for(int i = 0; i<n-1; i++){
		for(int j = min(n-1, i+a[i]); j>i && dp[i]+1<dp[j]; j--){
			dp[j] = dp[i]+1;
		}
	}
	if(dp[n-1]==INF) return -1;
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
