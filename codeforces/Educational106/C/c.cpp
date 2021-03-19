#include <bits/stdc++.h>
using namespace std;

long long g(int i, int n, vector<long long> &sums, vector<long long> &mins){
	return sums[i]+mins[i]*(n-(i/2)-1);
}

long long f() {
	int n;
	cin >> n;
	vector<long long> c(n), sums(n), mins(n);
	for(int i = 0; i<n; i++) cin >> c[i];
	sums[0] = c[0];
	sums[1] = c[1];
	mins[0] = c[0];
	mins[1] = c[1];
	for(int i = 2; i<n; i++){
		sums[i] = sums[i-2]+c[i];
		mins[i] = min(mins[i-2], c[i]);
	}
	long long ans = n*(c[0]+c[1]);
	for(int i = 2; i<n; i++) {
		ans = min(ans, g(i, n, sums, mins)+g(i-1, n, sums, mins));
	}
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
