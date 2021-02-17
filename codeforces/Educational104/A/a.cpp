#include <bits/stdc++.h>
using namespace std;

int f() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i<n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	for(int i = 1; i<n; i++){
		if(a[i]!=a[i-1]) return n-i;
	}
	return 0;
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
