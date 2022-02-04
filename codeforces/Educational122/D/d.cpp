#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000;
vector<int> best(1001, inf);

void compute_best() {
	best[1] = 0;
	for(int i = 1; i<=1000; i++) {
		for(int j = 1; j<=i; j++) {
			if (i+i/j > 1000) continue;
			best[i+i/j] = min(best[i+i/j], best[i]+1);
		}
	}
}

int f() {
	int n, k;
	cin >> n >> k;
	vector<int> b(n), c(n);
	int sum = 0; 
	for(int i = 0; i<n; i++) {
		cin >> b[i];
		b[i] = best[b[i]];
		sum += b[i];
	}
	for(int i = 0; i<n; i++) cin >> c[i];
	k = min(k, sum);
	vector<int> dp(k+1, 0);
	//knapsack problem
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<=k-b[i]; j++) {
			dp[k-j] = max(dp[k-j], dp[k-j-b[i]]+c[i]);
		}
	}
	return dp[k];
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	compute_best();
	int t;
	cin >> t;
	while (t--) {
		//slv();
		cout << f() << '\n';
	}
	return 0;
}
