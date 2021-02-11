#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, diff = 0, sol = 0;
	cin >> n;
	vector<long long> a(n), b(n), x(n);
	for(int i = 0; i<n; i++) {
		cin >> a[i] >> b[i];
		diff += a[i];
		x[i] = a[i]*2+b[i];
	}
	sort(x.rbegin(), x.rend());
	for(int i = 0; i<n && diff >= 0; i++) {
		diff -= x[i];
		sol++;
	}
	cout << sol << endl;
	return 0;
}