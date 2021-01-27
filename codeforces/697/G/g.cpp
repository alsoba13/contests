#include <bits/stdc++.h>
using namespace std;

#define N 200001
vector<int> cnt(N, 0), dp(N, 0);

int f() {
	int n; 
	cin >> n;
	fill(cnt.begin(), cnt.end(), 0);
	fill(dp.begin(), dp.end(), 0);
	for(int i = 0; i<n; i++) {
		int a;
		cin >> a;
		cnt[a]++;
	}
	for(int i = 1; i<N; i++){
		dp[i] += cnt[i];
		for(int j = 2*i; j<N; j += i){
			dp[j] = max(dp[i], dp[j]);
		}
	}
	int ans = 0;
	for(int i = 1; i<N; i++){
		ans = max(ans, dp[i]);
	}
	return n-ans;
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
