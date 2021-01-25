#include <bits/stdc++.h>
using namespace std;

bool f() {
	long long n;
	cin >> n;
	while((n&1) == 0) {
		n/=2;
	}
	return n!=1;
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
