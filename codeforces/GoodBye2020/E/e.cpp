#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

void slv() {
	int n;
	cin >> n;
	vector<long long> x(n);
	int q[60];
	long long p2[60], mp2[60];
	for(int i = 0; i<60; i++) q[i] = 0;
	for(int i = 0; i<n; i++) {
		cin >> x[i];
		for(int j = 0; j<60; j++) {
			p2[j] = (1LL << j);
			mp2[j] = p2[j] % MOD;
			q[j] += ((x[i] & (1LL << j)) > 0) ? 1 : 0;
		}
	}
	long long sum = 0;
	for(int i = 0; i<n; i++) {
		long long sum1 = 0, sum2 = 0;
		for(int j = 0; j<60; j++) {
			if ( (x[i] & p2[j]) > 0) {
				sum1 = (sum1 + (mp2[j]*q[j])%MOD)%MOD;
				sum2 = (sum2 + (mp2[j]*n)%MOD)%MOD;
			} else {
				sum2 = (sum2 + (mp2[j]*q[j])%MOD);
			}
		}
		sum = (sum + ((sum1%MOD)*(sum2%MOD)%MOD))%MOD;
	}
	cout << sum << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		slv();
	}
	return 0;
}