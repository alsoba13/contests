#include <bits/stdc++.h>
using namespace std;

long long ceil(long long a, long long b) {
	return a/b + (a%b>0?1:0);
}

bool f() {
	long long hc, dc, hM, dM;
	cin >> hc >> dc >> hM >> dM;
	long long k, w, a;
	cin >> k >> w >> a;
	for(int kw = 0; kw<=k; kw++) {
		long long ka = k-kw;
		if(ceil(hM, dc+kw*w) <= ceil(hc+ka*a, dM)) return true;
	}
	return false;
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
