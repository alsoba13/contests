#include <bits/stdc++.h>
using namespace std;

int c[100000];

int f() {
	int n, p, k, x, y;
	string s;
	cin >> n >> p >> k >> s >> x >> y;
	for (int i = 0; i < p; i++) {
		c[i] = -1;
	}
	c[p-1] = (s[p-1] == '0' ? x : 0);
	for (int i = p; i < n; i++) {
		if (i-k < 0 || c[i-k] == -1) {
			c[i] = (i-p+1)*y;
		} else {
			c[i] = min(c[i-k], (i-p+1)*y);
		}
		c[i] += (s[i] == '0' ? x : 0);
	}
	int sol = c[n-1];
	for (int i = n-k; i < n; i++) {
		if (c[i] == -1) continue;
		sol = min(sol, c[i]);
	}
	return sol;
}

int main() {
	int t; 
	cin >> t;
	while (t--) {
		cout << f() << endl;
	}

	return 0;
}