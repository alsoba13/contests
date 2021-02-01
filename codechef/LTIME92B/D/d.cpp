#include <bits/stdc++.h>
using namespace std;

bool p2(long long a){
	while(a%2 == 0) a/=2;
	return a == 1;
}
long long gcd(long long a, long long b){
	return b==0?a:gcd(b,a%b);
}
bool f() {
	long long n, k;
	cin >> n >> k;
	vector<long long> a(n);
	for(int i = 0; i<n; i++){
		cin >> a[i];
	}
	if(p2(k)) return true;
	for(int i = 0; i<n; i++) {
		if(a[i]%k == 0) continue;
		if(p2(k/gcd(a[i], k))) continue;
		return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		//slv();
		cout << (f()?"YES":"NO") << '\n';
	}
	return 0;
}
