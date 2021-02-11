#include <bits/stdc++.h>
using namespace std;

long long f() {
	long long k;
	cin >> k;
	return (k/2+1)*(k-k/2+1);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		//slv();
		cout << f() << '\n';
	}
	return 0;
}
