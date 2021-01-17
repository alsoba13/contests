#include <bits/stdc++.h>
using namespace std;

int f() {
	int n, k;
	cin >> k >> n;
	int m = n, M = -1;
	for(int i = 1; i<=n; i++){
		int a;
		cin >> a;
		if (a == k){
			m = min(i, m);
			M = max(i, M);
		}
	}
	if (M == -1) return 0;
	return M-m;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cout << f() << '\n';
	}
	return 0;
}
