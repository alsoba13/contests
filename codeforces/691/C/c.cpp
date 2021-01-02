#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<long long> a(n), b(m);
	for(int i = 0; i<n; i++) cin >> a[i];
	for(int i = 0; i<m; i++) cin >> b[i];
	sort(a.begin(), a.end());
	long long gd = 0;
	for(int i = 1; i<n; i++){
		gd = gcd(gd, a[i]-a[i-1]);
	}
	for(int i = 0; i<m; i++) {
		cout << gcd(a[0]+b[i], gd) << " ";
	}
	cout << endl;
	return 0;
}