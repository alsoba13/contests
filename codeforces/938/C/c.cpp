#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long g(vector<long long> &a, long long k) {
	for(int i = 0; i<a.size(); i++) {
		if(a[i]>k) return i;
		k -= a[i];
	}
	return a.size();
}

long long f() {
	long long n, k;
	cin >> n >> k;
	vector<long long> a(n);
	for(int i = 0; i<n; i++) cin >> a[i];
	long long ans = g(a, k/2 + k%2);
	reverse(a.begin(), a.end());
	ans += g(a, k/2);
	return min(ans, n);
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
