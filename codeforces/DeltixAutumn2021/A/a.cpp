#include <bits/stdc++.h>
using namespace std;

long long f() {
	int n;
	cin >> n;
	vector<long long> a(n);
	int cnt = 0;
	for(int i = 0; i<n; i++) {
		cin >> a[i];
		while(a[i]%2 == 0){
			cnt++;
			a[i]/=2;
		}
	}
	sort(a.rbegin(), a.rend());
	a[0] <<= cnt;
	long long ans = 0;
	for(int i = 0; i<n; i++) ans += a[i];
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		//slv();
		cout << f() << '\n';
	}
	return 0;
}
