#include <bits/stdc++.h>
using namespace std;

int f() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int> > a(n);
	for(int i = 0; i<n; i++) cin >> a[i].first;
	for(int i = 0; i<n; i++) cin >> a[i].second;
	sort(a.begin(), a.end());
	int i = 0;
	while(a[i].first<=k && i<n) {
		k+=a[i].second;
		i++;
	}
	return k;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		//slv();
		cout << f() << '\n';
		//cout << (f()?"YES":"NO") << '\n';
	}
	return 0;
}
