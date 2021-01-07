#include <bits/stdc++.h>
using namespace std;

long long f() {
	long long n, x;
	cin >> n >> x;
	vector<long long> a(n);
	int i_min, min_steps = 50;
	for(int i = 0; i<n; i++) {
		cin >> a[i];
		int steps = 0, b = a[i];
		while(b%x == 0){
			steps++;
			b/=x;
		}
		if (steps < min_steps) {
			min_steps = steps;
			i_min = i;
		}
	}
	long long ans = 0;
	for(int i = 0; i<n; i++) {
		ans += a[i]*(min_steps+1);
		if (i<i_min) ans += a[i];
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cout << f() << endl;
		//slv();
	}
	return 0;
}
