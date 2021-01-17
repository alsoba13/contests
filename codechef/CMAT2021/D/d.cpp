#include <bits/stdc++.h>
using namespace std;

void slv() {
	long long a, b, x;
	cin >> a >> b >> x; 
	long long ansa = a/x, ansb = b/x, ansr = (a%x+b%x)/x;
	cout << ansa + ansb + ansr << " ";
	if (ansr) {
		cout << x-max(a%x, b%x) << '\n';
	} else {
		cout << 0 << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		slv();
	}
	return 0;
}
