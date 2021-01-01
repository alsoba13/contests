#include <bits/stdc++.h>
using namespace std;

int f() {
	int n, m;
	cin >> n;
	vector<int> r(n);
	for(int i = 0; i<n; i++) cin >> r[i];
	cin >> m;
	vector<int> b(m);
	for(int i = 0; i<m; i++) cin >> b[i];
	int sum_n = 0, max_n = 0, sum_m = 0, max_m = 0;
	for(int i = 0; i<n; i++){
		sum_n += r[i];
		if (sum_n > max_n) max_n = sum_n;
	}	
	for(int i = 0; i<m; i++){
		sum_m += b[i];
		if (sum_m > max_m) max_m = sum_m;
	}
	return max_m + max_n;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cout << f() << endl;
	}
	return 0;
}