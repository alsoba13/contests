#include <bits/stdc++.h>
using namespace std;

bool f() {
	int n, k1, k2;
	cin >> n >> k1 >> k2;
	int w, b;
	cin >> w >> b;
	if(k1+k2>=2*w && 2*n-k1-k2>=2*b) return true;
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
