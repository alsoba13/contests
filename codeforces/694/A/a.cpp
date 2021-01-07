#include <bits/stdc++.h>
using namespace std;

void slv() {
	int n, x;
	cin >> n >> x;
	long long sum = 0, max = 0;
	for(int i = 0; i<n; i++) {
		int a; 
		cin >> a;
		max += (a/x + (a%x?1:0));
		sum += a;
	}
	cout << sum/x + (sum%x?1:0) << " " << max << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		slv();
	}
	return 0;
}
