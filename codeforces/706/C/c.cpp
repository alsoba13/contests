#include <bits/stdc++.h>
using namespace std;
 
long double f() {
	int n;
	cin >> n;
	vector<long long> x, y;
	for(int i = 0; i<2*n; i++){
		long long xx, yy;
		cin >> xx >> yy;
		if(xx==0)
			y.push_back(abs(yy));
		else
			x.push_back(abs(xx));
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	long double ans = 0;
	for(int i = 0; i<n; i++){
		ans += sqrt(x[i]*x[i]+y[i]*y[i]);
	}
	return ans;
}
 
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		//slv();
		cout << fixed << setprecision(15) << f() << '\n';
	}
	return 0;
}