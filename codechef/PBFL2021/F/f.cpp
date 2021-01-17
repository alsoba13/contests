#include <bits/stdc++.h>
using namespace std;

int g(int i, int j, int n) {
	return 1 + max(abs(n-i), abs(n-j));
}

void slv() {
	int n;
	cin >> n;
	for(int i = 1; i<=2*n-1; i++) {
		for(int j = 1; j<=2*n-1; j++){
			cout << g(i, j, n);
		}
		cout << '\n';
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
