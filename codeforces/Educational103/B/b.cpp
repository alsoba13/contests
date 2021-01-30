#include <bits/stdc++.h>
using namespace std;

long long f() {
	int n, k;
	cin >> n >> k;
	vector<long long> p(n), sum(n);
	for(int i = 0; i<n; i++){
		cin >> p[i];
	}
	sum[0] = 0;
	for(int i = 1; i<n; i++){
		sum[i] = sum[i-1]+p[i-1];
	}
	long long ans = 0;
	for(int i = 1; i<n; i++){
		if (p[i]*100>sum[i]*k)
		ans = max(ans, p[i]*100/k+(p[i]*100%k!=0)-sum[i]);
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
