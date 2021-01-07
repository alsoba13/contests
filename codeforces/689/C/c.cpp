#include <bits/stdc++.h>
using namespace std;

double f() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), r(m);
	vector<float> p(m);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) cin >> r[i] >> p[i];
	int f = -1;
	for(int i = 0; i<n; i++){
		if (a[i] != i+1) {
			f = i;
		}
	}
	if (f == -1) return 1.0;
	double P = 1;
	for (int i = 0; i<m; i++) {
		if (r[i]<f+1) continue;
		P *= (1-p[i]);
	}
	return 1-P;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		printf("%lf\n", f());
	}
	return 0;
}