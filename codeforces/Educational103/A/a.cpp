#include <bits/stdc++.h>
using namespace std;

int f() {
	int n, k;
	cin >> n >> k;
	if(n%k == 0) return 1;
	return 1 + (k-(n%k))/n + ((k-(n%k))%n != 0);
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
