#include <bits/stdc++.h>
using namespace std;

int sign(int a) {
	if (a == 0) return 0;
	if (a > 0) return 1;
	return -1;
}

int f() {
	int n;
	cin >> n;
	vector<long long> t(n), x(n);
	for(int i = 0; i<n; i++) cin >> t[i] >> x[i];
	t.push_back(3*1e9);
	x.push_back(0);
	long long pos = 0, dir = 0, time_left = 0, ans = 0;
	for(int i = 0; i<n; i++) {
		if (!time_left) {
			time_left = abs(x[i]-pos);
			dir = sign(x[i]-pos);
		}
		long long tmp = min(time_left, t[i+1]-t[i]);
		long long xf = pos + dir*tmp;
		if (min(xf,pos) <= x[i] && x[i] <= max(xf,pos)) ans++;
		pos = xf;
		time_left -= tmp;
	}	
	return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cout << f() << endl;
	}
	return 0;
}