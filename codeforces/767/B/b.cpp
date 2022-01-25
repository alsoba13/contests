#include <bits/stdc++.h>
using namespace std;

bool f() {
	int l, r, k;
	cin >> l >> r >> k;
	if (l==r) return l!=1;
	int length = r-l+1;
	int num_odds = length%2==0 ? length/2 : length/2+l%2;
	return k>=num_odds;
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
