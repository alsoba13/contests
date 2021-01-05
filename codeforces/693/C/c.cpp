#include <bits/stdc++.h>
using namespace std;

long long f() {
	int n;
	cin >> n;
	vector<long long> a(n), p(n,0);
	for(int i = 0; i<n; i++) cin >> a[i];
	for(int i = n-1; i>=0; i--){
		if(a[i]+i<n) 
			p[i] = p[i+a[i]]+a[i];
		else
			p[i] = a[i];
	}
	long long M = 0;
	for(int i =0; i<n; i++) {
		M = max(M, p[i]);
	}
	return M;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cout << f() << endl;
		//slv();
	}
	return 0;
}