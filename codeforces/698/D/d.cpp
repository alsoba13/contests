#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
	if (b == 0) return a;
	return gcd(b, a%b);
}

bool f() {
	long long n, k;
	cin >> n >> k;
	vector<long long> a(n), d;
	for(int i = 0; i<n; i++){ 
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for(int i = 1; i<n; i++){
		d.push_back(a[i]-a[i-1]);
	}
	long long g = d[0];
	for(int i = 1; i<d.size(); i++){
		g = gcd(g, d[i]);
	}
	for(int i = 0; i<n; i++){
		if ((k-a[i])%g == 0) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cout << (f()?"YES":"NO") << '\n';
	}
	return 0;
}
