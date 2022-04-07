#include <bits/stdc++.h>
using namespace std;

bool f() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i<n; i++ ) {
		cin >> a[i];
	}
	if(n == 1) return a[0] == 1;
	sort(a.begin(), a.end());
	return a[n-1]-a[n-2]<=1;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		//slv();
		cout << (f()?"YES":"NO") << '\n';
	}
	return 0;
}
